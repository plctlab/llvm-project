//===--- llvm/unittest/IR/VectorTypesTest.cpp - vector types unit tests ---===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/LLVMContext.h"
#include "gtest/gtest.h"
using namespace llvm;

namespace {
TEST(VectorTypesTest, FixedLength) {
  LLVMContext Ctx;

  Type *Int16Ty = Type::getInt16Ty(Ctx);
  Type *Int32Ty = Type::getInt32Ty(Ctx);
  Type *Int64Ty = Type::getInt64Ty(Ctx);
  Type *Float64Ty = Type::getDoubleTy(Ctx);

  VectorType *V8Int32Ty = VectorType::get(Int32Ty, 8);
  ASSERT_FALSE(V8Int32Ty->isScalable());
  VectorType *V8Int16Ty = VectorType::get(Int16Ty, {8, false});
  ASSERT_FALSE(V8Int16Ty->isScalable());

  VectorType::ElementCount EltCnt(4, false);
  VectorType *V4Int64Ty = VectorType::get(Int64Ty, EltCnt);
  ASSERT_FALSE(V4Int64Ty->isScalable());
  VectorType *V2Int64Ty = VectorType::get(Int64Ty, EltCnt/2);
  ASSERT_FALSE(V2Int64Ty->isScalable());
  VectorType *V8Int64Ty = VectorType::get(Int64Ty, EltCnt*2);
  ASSERT_FALSE(V8Int64Ty->isScalable());
  VectorType *V4Float64Ty = VectorType::get(Float64Ty, EltCnt);
  ASSERT_FALSE(V4Float64Ty->isScalable());

  EXPECT_EQ(VectorType::getExtendedElementVectorType(V8Int16Ty), V8Int32Ty);
  EXPECT_EQ(VectorType::getTruncatedElementVectorType(V8Int32Ty), V8Int16Ty);

  EXPECT_EQ(VectorType::getHalfElementsVectorType(V4Int64Ty), V2Int64Ty);
  EXPECT_EQ(VectorType::getDoubleElementsVectorType(V4Int64Ty), V8Int64Ty);

  EXPECT_EQ(VectorType::getInteger(V4Float64Ty), V4Int64Ty);

  EltCnt = V8Int64Ty->getElementCount();
  EXPECT_EQ(EltCnt.Min, 8U);
  ASSERT_FALSE(EltCnt.Scalable);
}

TEST(VectorTypesTest, Scalable) {
  LLVMContext Ctx;

  Type *Int16Ty = Type::getInt16Ty(Ctx);
  Type *Int32Ty = Type::getInt32Ty(Ctx);
  Type *Int64Ty = Type::getInt64Ty(Ctx);
  Type *Float64Ty = Type::getDoubleTy(Ctx);

  VectorType *ScV8Int32Ty = VectorType::get(Int32Ty, 8, true);
  ASSERT_TRUE(ScV8Int32Ty->isScalable());
  VectorType *ScV8Int16Ty = VectorType::get(Int16Ty, {8, true});
  ASSERT_TRUE(ScV8Int16Ty->isScalable());

  VectorType::ElementCount EltCnt(4, true);
  VectorType *ScV4Int64Ty = VectorType::get(Int64Ty, EltCnt);
  ASSERT_TRUE(ScV4Int64Ty->isScalable());
  VectorType *ScV2Int64Ty = VectorType::get(Int64Ty, EltCnt/2);
  ASSERT_TRUE(ScV2Int64Ty->isScalable());
  VectorType *ScV8Int64Ty = VectorType::get(Int64Ty, EltCnt*2);
  ASSERT_TRUE(ScV8Int64Ty->isScalable());
  VectorType *ScV4Float64Ty = VectorType::get(Float64Ty, EltCnt);
  ASSERT_TRUE(ScV4Float64Ty->isScalable());


  EXPECT_EQ(VectorType::getExtendedElementVectorType(ScV8Int16Ty), ScV8Int32Ty);
  EXPECT_EQ(VectorType::getTruncatedElementVectorType(ScV8Int32Ty),
            ScV8Int16Ty);

  EXPECT_EQ(VectorType::getHalfElementsVectorType(ScV4Int64Ty), ScV2Int64Ty);
  EXPECT_EQ(VectorType::getDoubleElementsVectorType(ScV4Int64Ty), ScV8Int64Ty);

  EXPECT_EQ(VectorType::getInteger(ScV4Float64Ty), ScV4Int64Ty);

  EltCnt = ScV8Int64Ty->getElementCount();
  EXPECT_EQ(EltCnt.Min, 8U);
  ASSERT_TRUE(EltCnt.Scalable);
}

}
