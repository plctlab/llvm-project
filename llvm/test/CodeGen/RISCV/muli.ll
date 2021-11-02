define signext i32 @square(i32 %e) nounwind {
  %1 = mul i32 %e, 89
  ret i32 %1
}