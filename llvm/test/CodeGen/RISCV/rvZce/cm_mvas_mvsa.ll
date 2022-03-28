; RUN: llc -mtriple=riscv32 -mattr=+experimental-zcmp -verify-machineinstrs < %s \
; RUN: | FileCheck %s -check-prefixes=VALID,VALID32
; RUN: llc -mtriple=riscv64 -mattr=+experimental-zcmp -verify-machineinstrs < %s \
; RUN: | FileCheck %s -check-prefixes=VALID


; Function Attrs: nounwind
define dso_local i32 @cmva(i32 %num, i32 %f, i32 %d, i32 %dx) local_unnamed_addr #0 {
;  VALID-LABEL: cmva:
;  VALID: cm.mva01s {{s[0-7]}}, {{s[0-7]}}
;  VALID-NOT: cm.mva01s {{a.}}, {{a.}}
entry:
  %mul = mul nsw i32 %dx, %d
  %sub = sub nsw i32 %mul, %dx
  %add = add nsw i32 %mul, %d
  %mul2 = mul nsw i32 %sub, %dx
  %add3 = add nsw i32 %add, %mul2
  %mul4 = mul nsw i32 %add3, %d
  %add6 = add nsw i32 %add3, %num
  %add5 = add i32 %sub, %f
  %add7 = add i32 %add5, %mul4
  ret i32 %add7
}

declare i64 @llvm.cttz.i64(i64, i1 immarg)

define i64 @cmvs32(i64 %a) nounwind {
;  VALID32-LABEL: cmvs32:
;  VALID32: cm.mvsa01 {{s[0-7]}}, {{s[0-7]}}
;  VALID32-NOT: cm.mvsa01 {{a.}}, {{a.}}
  %tmp = call i64 @llvm.cttz.i64(i64 %a, i1 false)
  ret i64 %tmp
}

declare void @hoge()
define void @cmvs64(i32 signext %arg, i32 signext %arg1) nounwind {
;  VALID64-LABEL: cmvs:
;  VALID64: cm.mvsa01 {{s[0-7]}}, {{s[0-7]}}
;  VALID64-NOT: cm.mvsa01 {{a.}}, {{a.}}
bb:
  %tmp = icmp eq i32 %arg, %arg1
  br i1 %tmp, label %bb6, label %bb2

bb2:                                              ; preds = %bb2, %bb
  %tmp3 = phi i32 [ %tmp4, %bb2 ], [ %arg, %bb ]
  tail call void @hoge()
  %tmp4 = add nsw i32 %tmp3, 1
  %tmp5 = icmp eq i32 %tmp4, %arg1
  br i1 %tmp5, label %bb6, label %bb2

bb6:                                              ; preds = %bb2, %bb
  ret void
}

%struct.trie = type { [26 x %struct.trie*], i8 }

@word = external global i8*

declare i32 @trie_new(%struct.trie*)
declare i32 @trie_search(i8*, i32, %struct.trie**)
declare i64 @strnlen(i8*, i64)

; Function Attrs: nounwind optnone
define i32 @mvas_2() {
  ;  VALID64-LABEL: mvas_2:
  ;  VALID64-NOT: cm.mva01s {{a.}}, {{s.}}
  ;  VALID64-NOT: cm.mva01s {{s.}}, {{a.}}
entry:
  %trie = alloca %struct.trie*
  %0 = bitcast %struct.trie** %trie to i8*
  store %struct.trie* null, %struct.trie** %trie
  %call = tail call i32 @trie_new(%struct.trie* null)
  %1 = load i8*, i8** @word
  %call1 = tail call i64 @strnlen(i8* %1, i64 100)
  %conv = trunc i64 %call1 to i32
  %call2 = call i32 @trie_search(i8* %1, i32 %conv, %struct.trie** %trie)
  ret i32 %call2
}

declare i32 @foo(i32, i32)

; Function Attrs: nounwind optnone
define dso_local i32 @cm_mvas_same_src(i32 %0, i32 %1, i32 %2, i32 %3) {
 ;  VALID32-LABEL: cm_mvas_same_src:
 ;  VALID32: cm.mva01s	s0, s0
 ;
 ;  VALID64-LABEL: cm_mvas_same_src:
 ;  VALID64: cm.mva01s	s0, s0
entry:
  %4 = call i32 @foo(i32 %3, i32 %2)
  %5 = add i32 %4, %2
  %6 = call i32 @foo(i32 %3, i32 %3)
  %add = add i32 %5, %6
  ret i32 %add
}

%struct._IO_FILE = type { i32, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, %struct._IO_marker*, %struct._IO_FILE*, i32, i32, i64, i16, i8, [1 x i8], i8*, i64, i8*, i8*, i8*, i8*, i64, i32, [20 x i8] }
%struct._IO_marker = type { %struct._IO_marker*, %struct._IO_FILE*, i32 }
%struct.Node = type { i8*, i64, %struct.Node*, %struct.Node* }

declare i8* @malloc(i64)

declare i32 @fgetc(%struct._IO_FILE*nocapture)

declare %struct.Node* @addWordToTree(i8*, %struct.Node*)

; Function Attrs: nounwind optsize
define %struct.Node* @cmmv_a1_come_first(%struct._IO_FILE*nocapture %file, %struct.Node* %root) {
 ;  VALID32-LABEL: cmmv_a1_come_first:
 ;  VALID32: cm.push	{ra, s0-s5}, -32
 ;  VALID32-NEXT: .cfi_offset ra, -4
 ;  VALID32-NEXT: .cfi_offset s0, -8
 ;  VALID32-NEXT: .cfi_offset s1, -12
 ;  VALID32-NEXT: .cfi_offset s2, -16
 ;  VALID32-NEXT: .cfi_offset s3, -20
 ;  VALID32-NEXT: .cfi_offset s4, -24
 ;  VALID32-NEXT: .cfi_offset s5, -28
 ;  VALID32-NEXT: cm.mvsa01	s2, s0

 ;  VALID64-LABEL: cmmv_a1_come_first:
 ;  VALID64: cm.push	{ra, s0-s5}, -64
 ;  VALID64-NEXT: .cfi_offset ra, -8
 ;  VALID64-NEXT: .cfi_offset s0, -16
 ;  VALID64-NEXT: .cfi_offset s1, -24
 ;  VALID64-NEXT: .cfi_offset s2, -32
 ;  VALID64-NEXT: .cfi_offset s3, -40
 ;  VALID64-NEXT: .cfi_offset s4, -48
 ;  VALID64-NEXT: .cfi_offset s5, -56
 ;  VALID64-NEXT: cm.mvsa01	s2, s0
entry:
  %call = tail call dereferenceable_or_null(46) i8* @malloc(i64 46)
  %arrayidx = getelementptr inbounds i8, i8* %call, i64 -1
  %call117 = tail call i32 @fgetc(%struct._IO_FILE* %file)
  %sext.mask18 = and i32 %call117, 255
  %cmp.not19 = icmp eq i32 %sext.mask18, 255
  br i1 %cmp.not19, label %while.end, label %land.lhs.true.preheader

land.lhs.true.preheader:
  %arrayidx921 = getelementptr inbounds i8, i8* %call, i64 255
  store i8 0, i8* %arrayidx921
  %call1022 = tail call %struct.Node* @addWordToTree(i8* %call, %struct.Node* %root)
  %call123 = tail call i32 @fgetc(%struct._IO_FILE* %file)
  %sext.mask24 = and i32 %call123, 255
  %cmp.not25 = icmp eq i32 %sext.mask24, 255
  br i1 %cmp.not25, label %while.end, label %land.lhs.true.land.lhs.true_crit_edge

land.lhs.true.land.lhs.true_crit_edge:
  %call1026 = phi %struct.Node* [ %call10, %land.lhs.true.land.lhs.true_crit_edge ], [ %call1022, %land.lhs.true.preheader ]
  %.pre = load i8, i8* %arrayidx
  %cmp6.not = icmp eq i8 %.pre, 39
  %spec.select = select i1 %cmp6.not, i64 0, i64 255
  %arrayidx9 = getelementptr inbounds i8, i8* %call, i64 %spec.select
  store i8 0, i8* %arrayidx9
  %call10 = tail call %struct.Node* @addWordToTree(i8* %call, %struct.Node* %call1026)
  %call1 = tail call i32 @fgetc(%struct._IO_FILE* %file)
  %sext.mask = and i32 %call1, 255
  %cmp.not = icmp eq i32 %sext.mask, 255
  br i1 %cmp.not, label %while.end, label %land.lhs.true.land.lhs.true_crit_edge

while.end:
  %root.addr.0.lcssa = phi %struct.Node* [ %root, %entry ], [ %call1022, %land.lhs.true.preheader ], [ %call10, %land.lhs.true.land.lhs.true_crit_edge ]
  ret %struct.Node* %root.addr.0.lcssa
}
