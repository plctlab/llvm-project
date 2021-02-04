def riscv_extract_vector_elt
  : SDNode<"ISD::EXTRACT_VECTOR_ELT",
            SDTypeProfile<1, 2, [SDTCisVT<0, i64>, SDTCisPtrTy<2>]>, []>;

multiclass VPatInsertExtractElt_XI_Idx<bit IsFloat> {
  defvar vtilist = !if(IsFloat, AllFloatVectors, AllIntegerVectors);
  // defvar insertelt_node = !if(IsFloat, insertelt, riscv_insert_vector_elt);
  defvar extractelt_node = !if(IsFloat, extractelt, riscv_extract_vector_elt);
  foreach vti = vtilist in {
    defvar MX = RoundFMToM1<vti.LMULstr>.Result;
    defvar vmv_xf_s_inst = !cast<Instruction>(!if(IsFloat, "PseudoVFMV_F_S_",
                                                           "PseudoVMV_X_S_")#"M"#MX);
    defvar vmv_s_xf_inst = !cast<Instruction>(!if(IsFloat, "PseudoVFMV_S_F_",
                                                           "PseudoVMV_S_X_")#"M"#MX);
    // Only pattern-match insert/extract-element operations where the index is
    // 0. Any other index will have been custom-lowered to slide the vector
    // correctly into place (and, in the case of insert, slide it back again
    // afterwards).
    def : Pat<(extractelt_node (vti.Type vti.RegClass:$rs1), 0),
                       (vmv_xf_s_inst (i64 zero_reg), vti.RegClass:$rs1, vti.SEW)>;

    // def : Pat<(vti.Vector (insertelt_node (vti.Vector vti.RegClass:$merge),
    //                                       vti.ScalarRegClass:$rs1, 0)),
    //           (vmv_s_xf_inst vti.RegClass:$merge,
    //                   ToFPR32<vti.Scalar, vti.ScalarRegClass, "rs1">.ret,
    //                   vti.AVL, vti.SEW)>;
  }
}

let Predicates = [HasStdExtV] in
defm "" : VPatInsertExtractElt_XI_Idx</*IsFloat*/0>;

def SDTRVVSlide : SDTypeProfile<1, 3, [
  SDTCisVec<0>, SDTCisSameAs<1, 0>, SDTCisSameAs<2, 0>, SDTCisVT<3, XLenVT>
]>;

def riscv_slideup : SDNode<"RISCVISD::VSLIDEUP", SDTRVVSlide, []>;
def riscv_slidedown : SDNode<"RISCVISD::VSLIDEDOWN", SDTRVVSlide, []>;

let Predicates = [HasStdExtV] in {

// foreach vti = AllIntegerVectors in 
//   def : Pat<(vti.Vector riscv_vid),
//             (!cast<Instruction>("PseudoVID_V_"#vti.LMul.MX) vti.AVL, vti.SEW)>;

foreach vti = AllIntegerVectors in {
    // def : Pat<(vti.Vector (riscv_slideup (vti.Vector vti.RegClass:$rs3),
    //                                      (vti.Vector vti.RegClass:$rs1),
    //                                      uimm5:$rs2)),
    //           (!cast<Instruction>("PseudoVSLIDEUP_VI_"#vti.LMul.MX)
    //               vti.RegClass:$rs3, vti.RegClass:$rs1, uimm5:$rs2,
    //               vti.AVL, vti.SEW)>;
    defvar MX = RoundFMToM1<vti.LMULstr>.Result;

    def : Pat<(vti.Type (riscv_slideup (vti.Type vti.RegClass:$merge),
                                         (vti.Type vti.RegClass:$rs1),
                                         GPR:$rs2)),
              (!cast<Instruction>("PseudoVSLIDEUP_VX_"#"M"#MX)
                  vti.RegClass:$merge, vti.RegClass:$rs1, GPR:$rs2, (vti.Mask zero_reg), vti.SEW)>;

    // def : Pat<(vti.Vector (riscv_slidedown (vti.Vector vti.RegClass:$rs3),
    //                                        (vti.Vector vti.RegClass:$rs1),
    //                                        uimm5:$rs2)),
    //           (!cast<Instruction>("PseudoVSLIDEDOWN_VI_"#vti.LMul.MX)
    //               vti.RegClass:$rs3, vti.RegClass:$rs1, uimm5:$rs2,
    //               vti.AVL, vti.SEW)>;

    def : Pat<(vti.Type (riscv_slidedown (vti.Type vti.RegClass:$merge),
                                           (vti.Type vti.RegClass:$rs1),
                                           GPR:$rs2)),
              (!cast<Instruction>("PseudoVSLIDEDOWN_VX_"#"M"#MX)
                  vti.RegClass:$merge, vti.RegClass:$rs1, GPR:$rs2, (vti.Mask zero_reg), vti.SEW)>;
}
} // Predicates = [HasStdExtV]