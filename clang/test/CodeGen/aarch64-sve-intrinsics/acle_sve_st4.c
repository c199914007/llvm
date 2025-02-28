// REQUIRES: aarch64-registered-target
// RUN: %clang_cc1 -triple aarch64-none-linux-gnu -target-feature +sve -fallow-half-arguments-and-returns -S -O1 -Werror -Wall -emit-llvm -o - %s | FileCheck %s
// RUN: %clang_cc1 -DSVE_OVERLOADED_FORMS -triple aarch64-none-linux-gnu -target-feature +sve -fallow-half-arguments-and-returns -S -O1 -Werror -Wall -emit-llvm -o - %s | FileCheck %s
// RUN: %clang_cc1 -triple aarch64-none-linux-gnu -target-feature +sve -fallow-half-arguments-and-returns -S -O1 -Werror -Wall -o - %s >/dev/null
#include <arm_sve.h>

#ifdef SVE_OVERLOADED_FORMS
// A simple used,unused... macro, long enough to represent any SVE builtin.
#define SVE_ACLE_FUNC(A1,A2_UNUSED,A3,A4_UNUSED) A1##A3
#else
#define SVE_ACLE_FUNC(A1,A2,A3,A4) A1##A2##A3##A4
#endif

void test_svst4_s8(svbool_t pg, int8_t *base, svint8x4_t data)
{
  // CHECK-LABEL: test_svst4_s8
  // CHECK-DAG: %[[V0:.*]] = call <vscale x 16 x i8> @llvm.aarch64.sve.tuple.get.nxv16i8.nxv64i8(<vscale x 64 x i8> %data, i32 0)
  // CHECK-DAG: %[[V1:.*]] = call <vscale x 16 x i8> @llvm.aarch64.sve.tuple.get.nxv16i8.nxv64i8(<vscale x 64 x i8> %data, i32 1)
  // CHECK-DAG: %[[V2:.*]] = call <vscale x 16 x i8> @llvm.aarch64.sve.tuple.get.nxv16i8.nxv64i8(<vscale x 64 x i8> %data, i32 2)
  // CHECK-DAG: %[[V3:.*]] = call <vscale x 16 x i8> @llvm.aarch64.sve.tuple.get.nxv16i8.nxv64i8(<vscale x 64 x i8> %data, i32 3)
  // CHECK: call void @llvm.aarch64.sve.st4.nxv16i8(<vscale x 16 x i8> %[[V0]], <vscale x 16 x i8> %[[V1]], <vscale x 16 x i8> %[[V2]], <vscale x 16 x i8> %[[V3]], <vscale x 16 x i1> %pg, i8* %base)
  // CHECK-NEXT: ret
  return SVE_ACLE_FUNC(svst4,_s8,,)(pg, base, data);
}

void test_svst4_s16(svbool_t pg, int16_t *base, svint16x4_t data)
{
  // CHECK-LABEL: test_svst4_s16
  // CHECK-DAG: %[[V0:.*]] = call <vscale x 8 x i16> @llvm.aarch64.sve.tuple.get.nxv8i16.nxv32i16(<vscale x 32 x i16> %data, i32 0)
  // CHECK-DAG: %[[V1:.*]] = call <vscale x 8 x i16> @llvm.aarch64.sve.tuple.get.nxv8i16.nxv32i16(<vscale x 32 x i16> %data, i32 1)
  // CHECK-DAG: %[[V2:.*]] = call <vscale x 8 x i16> @llvm.aarch64.sve.tuple.get.nxv8i16.nxv32i16(<vscale x 32 x i16> %data, i32 2)
  // CHECK-DAG: %[[V3:.*]] = call <vscale x 8 x i16> @llvm.aarch64.sve.tuple.get.nxv8i16.nxv32i16(<vscale x 32 x i16> %data, i32 3)
  // CHECK-DAG: %[[PG:.*]] = call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> %pg)
  // CHECK: call void @llvm.aarch64.sve.st4.nxv8i16(<vscale x 8 x i16> %[[V0]], <vscale x 8 x i16> %[[V1]], <vscale x 8 x i16> %[[V2]], <vscale x 8 x i16> %[[V3]], <vscale x 8 x i1> %[[PG]], i16* %base)
  // CHECK-NEXT: ret
  return SVE_ACLE_FUNC(svst4,_s16,,)(pg, base, data);
}

void test_svst4_s32(svbool_t pg, int32_t *base, svint32x4_t data)
{
  // CHECK-LABEL: test_svst4_s32
  // CHECK-DAG: %[[V0:.*]] = call <vscale x 4 x i32> @llvm.aarch64.sve.tuple.get.nxv4i32.nxv16i32(<vscale x 16 x i32> %data, i32 0)
  // CHECK-DAG: %[[V1:.*]] = call <vscale x 4 x i32> @llvm.aarch64.sve.tuple.get.nxv4i32.nxv16i32(<vscale x 16 x i32> %data, i32 1)
  // CHECK-DAG: %[[V2:.*]] = call <vscale x 4 x i32> @llvm.aarch64.sve.tuple.get.nxv4i32.nxv16i32(<vscale x 16 x i32> %data, i32 2)
  // CHECK-DAG: %[[V3:.*]] = call <vscale x 4 x i32> @llvm.aarch64.sve.tuple.get.nxv4i32.nxv16i32(<vscale x 16 x i32> %data, i32 3)
  // CHECK-DAG: %[[PG:.*]] = call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> %pg)
  // CHECK: call void @llvm.aarch64.sve.st4.nxv4i32(<vscale x 4 x i32> %[[V0]], <vscale x 4 x i32> %[[V1]], <vscale x 4 x i32> %[[V2]], <vscale x 4 x i32> %[[V3]], <vscale x 4 x i1> %[[PG]], i32* %base)
  // CHECK-NEXT: ret
  return SVE_ACLE_FUNC(svst4,_s32,,)(pg, base, data);
}

void test_svst4_s64(svbool_t pg, int64_t *base, svint64x4_t data)
{
  // CHECK-LABEL: test_svst4_s64
  // CHECK-DAG: %[[V0:.*]] = call <vscale x 2 x i64> @llvm.aarch64.sve.tuple.get.nxv2i64.nxv8i64(<vscale x 8 x i64> %data, i32 0)
  // CHECK-DAG: %[[V1:.*]] = call <vscale x 2 x i64> @llvm.aarch64.sve.tuple.get.nxv2i64.nxv8i64(<vscale x 8 x i64> %data, i32 1)
  // CHECK-DAG: %[[V2:.*]] = call <vscale x 2 x i64> @llvm.aarch64.sve.tuple.get.nxv2i64.nxv8i64(<vscale x 8 x i64> %data, i32 2)
  // CHECK-DAG: %[[V3:.*]] = call <vscale x 2 x i64> @llvm.aarch64.sve.tuple.get.nxv2i64.nxv8i64(<vscale x 8 x i64> %data, i32 3)
  // CHECK-DAG: %[[PG:.*]] = call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> %pg)
  // CHECK: call void @llvm.aarch64.sve.st4.nxv2i64(<vscale x 2 x i64> %[[V0]], <vscale x 2 x i64> %[[V1]], <vscale x 2 x i64> %[[V2]], <vscale x 2 x i64> %[[V3]], <vscale x 2 x i1> %[[PG]], i64* %base)
  // CHECK-NEXT: ret
  return SVE_ACLE_FUNC(svst4,_s64,,)(pg, base, data);
}

void test_svst4_u8(svbool_t pg, uint8_t *base, svuint8x4_t data)
{
  // CHECK-LABEL: test_svst4_u8
  // CHECK-DAG: %[[V0:.*]] = call <vscale x 16 x i8> @llvm.aarch64.sve.tuple.get.nxv16i8.nxv64i8(<vscale x 64 x i8> %data, i32 0)
  // CHECK-DAG: %[[V1:.*]] = call <vscale x 16 x i8> @llvm.aarch64.sve.tuple.get.nxv16i8.nxv64i8(<vscale x 64 x i8> %data, i32 1)
  // CHECK-DAG: %[[V2:.*]] = call <vscale x 16 x i8> @llvm.aarch64.sve.tuple.get.nxv16i8.nxv64i8(<vscale x 64 x i8> %data, i32 2)
  // CHECK-DAG: %[[V3:.*]] = call <vscale x 16 x i8> @llvm.aarch64.sve.tuple.get.nxv16i8.nxv64i8(<vscale x 64 x i8> %data, i32 3)
  // CHECK: call void @llvm.aarch64.sve.st4.nxv16i8(<vscale x 16 x i8> %[[V0]], <vscale x 16 x i8> %[[V1]], <vscale x 16 x i8> %[[V2]], <vscale x 16 x i8> %[[V3]], <vscale x 16 x i1> %pg, i8* %base)
  // CHECK-NEXT: ret
  return SVE_ACLE_FUNC(svst4,_u8,,)(pg, base, data);
}

void test_svst4_u16(svbool_t pg, uint16_t *base, svuint16x4_t data)
{
  // CHECK-LABEL: test_svst4_u16
  // CHECK-DAG: %[[V0:.*]] = call <vscale x 8 x i16> @llvm.aarch64.sve.tuple.get.nxv8i16.nxv32i16(<vscale x 32 x i16> %data, i32 0)
  // CHECK-DAG: %[[V1:.*]] = call <vscale x 8 x i16> @llvm.aarch64.sve.tuple.get.nxv8i16.nxv32i16(<vscale x 32 x i16> %data, i32 1)
  // CHECK-DAG: %[[V2:.*]] = call <vscale x 8 x i16> @llvm.aarch64.sve.tuple.get.nxv8i16.nxv32i16(<vscale x 32 x i16> %data, i32 2)
  // CHECK-DAG: %[[V3:.*]] = call <vscale x 8 x i16> @llvm.aarch64.sve.tuple.get.nxv8i16.nxv32i16(<vscale x 32 x i16> %data, i32 3)
  // CHECK-DAG: %[[PG:.*]] = call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> %pg)
  // CHECK: call void @llvm.aarch64.sve.st4.nxv8i16(<vscale x 8 x i16> %[[V0]], <vscale x 8 x i16> %[[V1]], <vscale x 8 x i16> %[[V2]], <vscale x 8 x i16> %[[V3]], <vscale x 8 x i1> %[[PG]], i16* %base)
  // CHECK-NEXT: ret
  return SVE_ACLE_FUNC(svst4,_u16,,)(pg, base, data);
}

void test_svst4_u32(svbool_t pg, uint32_t *base, svuint32x4_t data)
{
  // CHECK-LABEL: test_svst4_u32
  // CHECK-DAG: %[[V0:.*]] = call <vscale x 4 x i32> @llvm.aarch64.sve.tuple.get.nxv4i32.nxv16i32(<vscale x 16 x i32> %data, i32 0)
  // CHECK-DAG: %[[V1:.*]] = call <vscale x 4 x i32> @llvm.aarch64.sve.tuple.get.nxv4i32.nxv16i32(<vscale x 16 x i32> %data, i32 1)
  // CHECK-DAG: %[[V2:.*]] = call <vscale x 4 x i32> @llvm.aarch64.sve.tuple.get.nxv4i32.nxv16i32(<vscale x 16 x i32> %data, i32 2)
  // CHECK-DAG: %[[V3:.*]] = call <vscale x 4 x i32> @llvm.aarch64.sve.tuple.get.nxv4i32.nxv16i32(<vscale x 16 x i32> %data, i32 3)
  // CHECK-DAG: %[[PG:.*]] = call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> %pg)
  // CHECK: call void @llvm.aarch64.sve.st4.nxv4i32(<vscale x 4 x i32> %[[V0]], <vscale x 4 x i32> %[[V1]], <vscale x 4 x i32> %[[V2]], <vscale x 4 x i32> %[[V3]], <vscale x 4 x i1> %[[PG]], i32* %base)
  // CHECK-NEXT: ret
  return SVE_ACLE_FUNC(svst4,_u32,,)(pg, base, data);
}

void test_svst4_u64(svbool_t pg, uint64_t *base, svuint64x4_t data)
{
  // CHECK-LABEL: test_svst4_u64
  // CHECK-DAG: %[[V0:.*]] = call <vscale x 2 x i64> @llvm.aarch64.sve.tuple.get.nxv2i64.nxv8i64(<vscale x 8 x i64> %data, i32 0)
  // CHECK-DAG: %[[V1:.*]] = call <vscale x 2 x i64> @llvm.aarch64.sve.tuple.get.nxv2i64.nxv8i64(<vscale x 8 x i64> %data, i32 1)
  // CHECK-DAG: %[[V2:.*]] = call <vscale x 2 x i64> @llvm.aarch64.sve.tuple.get.nxv2i64.nxv8i64(<vscale x 8 x i64> %data, i32 2)
  // CHECK-DAG: %[[V3:.*]] = call <vscale x 2 x i64> @llvm.aarch64.sve.tuple.get.nxv2i64.nxv8i64(<vscale x 8 x i64> %data, i32 3)
  // CHECK-DAG: %[[PG:.*]] = call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> %pg)
  // CHECK: call void @llvm.aarch64.sve.st4.nxv2i64(<vscale x 2 x i64> %[[V0]], <vscale x 2 x i64> %[[V1]], <vscale x 2 x i64> %[[V2]], <vscale x 2 x i64> %[[V3]], <vscale x 2 x i1> %[[PG]], i64* %base)
  // CHECK-NEXT: ret
  return SVE_ACLE_FUNC(svst4,_u64,,)(pg, base, data);
}

void test_svst4_f16(svbool_t pg, float16_t *base, svfloat16x4_t data)
{
  // CHECK-LABEL: test_svst4_f16
  // CHECK-DAG: %[[PG:.*]] = call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> %pg)
  // CHECK-DAG: %[[V0:.*]] = call <vscale x 8 x half> @llvm.aarch64.sve.tuple.get.nxv8f16.nxv32f16(<vscale x 32 x half> %data, i32 0)
  // CHECK-DAG: %[[V1:.*]] = call <vscale x 8 x half> @llvm.aarch64.sve.tuple.get.nxv8f16.nxv32f16(<vscale x 32 x half> %data, i32 1)
  // CHECK-DAG: %[[V2:.*]] = call <vscale x 8 x half> @llvm.aarch64.sve.tuple.get.nxv8f16.nxv32f16(<vscale x 32 x half> %data, i32 2)
  // CHECK-DAG: %[[V3:.*]] = call <vscale x 8 x half> @llvm.aarch64.sve.tuple.get.nxv8f16.nxv32f16(<vscale x 32 x half> %data, i32 3)
  // CHECK: call void @llvm.aarch64.sve.st4.nxv8f16(<vscale x 8 x half> %[[V0]], <vscale x 8 x half> %[[V1]], <vscale x 8 x half> %[[V2]], <vscale x 8 x half> %[[V3]], <vscale x 8 x i1> %[[PG]], half* %base)
  // CHECK-NEXT: ret
  return SVE_ACLE_FUNC(svst4,_f16,,)(pg, base, data);
}

void test_svst4_f32(svbool_t pg, float32_t *base, svfloat32x4_t data)
{
  // CHECK-LABEL: test_svst4_f32
  // CHECK-DAG: %[[V0:.*]] = call <vscale x 4 x float> @llvm.aarch64.sve.tuple.get.nxv4f32.nxv16f32(<vscale x 16 x float> %data, i32 0)
  // CHECK-DAG: %[[V1:.*]] = call <vscale x 4 x float> @llvm.aarch64.sve.tuple.get.nxv4f32.nxv16f32(<vscale x 16 x float> %data, i32 1)
  // CHECK-DAG: %[[V2:.*]] = call <vscale x 4 x float> @llvm.aarch64.sve.tuple.get.nxv4f32.nxv16f32(<vscale x 16 x float> %data, i32 2)
  // CHECK-DAG: %[[V3:.*]] = call <vscale x 4 x float> @llvm.aarch64.sve.tuple.get.nxv4f32.nxv16f32(<vscale x 16 x float> %data, i32 3)
  // CHECK-DAG: %[[PG:.*]] = call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> %pg)
  // CHECK: call void @llvm.aarch64.sve.st4.nxv4f32(<vscale x 4 x float> %[[V0]], <vscale x 4 x float> %[[V1]], <vscale x 4 x float> %[[V2]], <vscale x 4 x float> %[[V3]], <vscale x 4 x i1> %[[PG]], float* %base)
  // CHECK-NEXT: ret
  return SVE_ACLE_FUNC(svst4,_f32,,)(pg, base, data);
}

void test_svst4_f64(svbool_t pg, float64_t *base, svfloat64x4_t data)
{
  // CHECK-LABEL: test_svst4_f64
  // CHECK-DAG: %[[V0:.*]] = call <vscale x 2 x double> @llvm.aarch64.sve.tuple.get.nxv2f64.nxv8f64(<vscale x 8 x double> %data, i32 0)
  // CHECK-DAG: %[[V1:.*]] = call <vscale x 2 x double> @llvm.aarch64.sve.tuple.get.nxv2f64.nxv8f64(<vscale x 8 x double> %data, i32 1)
  // CHECK-DAG: %[[V2:.*]] = call <vscale x 2 x double> @llvm.aarch64.sve.tuple.get.nxv2f64.nxv8f64(<vscale x 8 x double> %data, i32 2)
  // CHECK-DAG: %[[V3:.*]] = call <vscale x 2 x double> @llvm.aarch64.sve.tuple.get.nxv2f64.nxv8f64(<vscale x 8 x double> %data, i32 3)
  // CHECK-DAG: %[[PG:.*]] = call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> %pg)
  // CHECK: call void @llvm.aarch64.sve.st4.nxv2f64(<vscale x 2 x double> %[[V0]], <vscale x 2 x double> %[[V1]], <vscale x 2 x double> %[[V2]], <vscale x 2 x double> %[[V3]], <vscale x 2 x i1> %[[PG]], double* %base)
  // CHECK-NEXT: ret
  return SVE_ACLE_FUNC(svst4,_f64,,)(pg, base, data);
}

void test_svst4_vnum_s8(svbool_t pg, int8_t *base, int64_t vnum, svint8x4_t data)
{
  // CHECK-LABEL: test_svst4_vnum_s8
  // CHECK-DAG: %[[BITCAST:.*]] = bitcast i8* %base to <vscale x 16 x i8>*
  // CHECK-DAG: %[[GEP:.*]] = getelementptr <vscale x 16 x i8>, <vscale x 16 x i8>* %[[BITCAST]], i64 %vnum, i64 0
  // CHECK-DAG: %[[V0:.*]] = call <vscale x 16 x i8> @llvm.aarch64.sve.tuple.get.nxv16i8.nxv64i8(<vscale x 64 x i8> %data, i32 0)
  // CHECK-DAG: %[[V1:.*]] = call <vscale x 16 x i8> @llvm.aarch64.sve.tuple.get.nxv16i8.nxv64i8(<vscale x 64 x i8> %data, i32 1)
  // CHECK-DAG: %[[V2:.*]] = call <vscale x 16 x i8> @llvm.aarch64.sve.tuple.get.nxv16i8.nxv64i8(<vscale x 64 x i8> %data, i32 2)
  // CHECK-DAG: %[[V3:.*]] = call <vscale x 16 x i8> @llvm.aarch64.sve.tuple.get.nxv16i8.nxv64i8(<vscale x 64 x i8> %data, i32 3)
  // CHECK: call void @llvm.aarch64.sve.st4.nxv16i8(<vscale x 16 x i8> %[[V0]], <vscale x 16 x i8> %[[V1]], <vscale x 16 x i8> %[[V2]], <vscale x 16 x i8> %[[V3]], <vscale x 16 x i1> %pg, i8* %[[GEP]])
  // CHECK-NEXT: ret
  return SVE_ACLE_FUNC(svst4_vnum,_s8,,)(pg, base, vnum, data);
}

void test_svst4_vnum_s16(svbool_t pg, int16_t *base, int64_t vnum, svint16x4_t data)
{
  // CHECK-LABEL: test_svst4_vnum_s16
  // CHECK-DAG: %[[BITCAST:.*]] = bitcast i16* %base to <vscale x 8 x i16>*
  // CHECK-DAG: %[[GEP:.*]] = getelementptr <vscale x 8 x i16>, <vscale x 8 x i16>* %[[BITCAST]], i64 %vnum, i64 0
  // CHECK-DAG: %[[V0:.*]] = call <vscale x 8 x i16> @llvm.aarch64.sve.tuple.get.nxv8i16.nxv32i16(<vscale x 32 x i16> %data, i32 0)
  // CHECK-DAG: %[[V1:.*]] = call <vscale x 8 x i16> @llvm.aarch64.sve.tuple.get.nxv8i16.nxv32i16(<vscale x 32 x i16> %data, i32 1)
  // CHECK-DAG: %[[V2:.*]] = call <vscale x 8 x i16> @llvm.aarch64.sve.tuple.get.nxv8i16.nxv32i16(<vscale x 32 x i16> %data, i32 2)
  // CHECK-DAG: %[[V3:.*]] = call <vscale x 8 x i16> @llvm.aarch64.sve.tuple.get.nxv8i16.nxv32i16(<vscale x 32 x i16> %data, i32 3)
  // CHECK-DAG: %[[PG:.*]] = call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> %pg)
  // CHECK: call void @llvm.aarch64.sve.st4.nxv8i16(<vscale x 8 x i16> %[[V0]], <vscale x 8 x i16> %[[V1]], <vscale x 8 x i16> %[[V2]], <vscale x 8 x i16> %[[V3]], <vscale x 8 x i1> %[[PG]], i16* %[[GEP]])
  // CHECK-NEXT: ret
  return SVE_ACLE_FUNC(svst4_vnum,_s16,,)(pg, base, vnum, data);
}

void test_svst4_vnum_s32(svbool_t pg, int32_t *base, int64_t vnum, svint32x4_t data)
{
  // CHECK-LABEL: test_svst4_vnum_s32
  // CHECK-DAG: %[[BITCAST:.*]] = bitcast i32* %base to <vscale x 4 x i32>*
  // CHECK-DAG: %[[GEP:.*]] = getelementptr <vscale x 4 x i32>, <vscale x 4 x i32>* %[[BITCAST]], i64 %vnum, i64 0
  // CHECK-DAG: %[[V0:.*]] = call <vscale x 4 x i32> @llvm.aarch64.sve.tuple.get.nxv4i32.nxv16i32(<vscale x 16 x i32> %data, i32 0)
  // CHECK-DAG: %[[V1:.*]] = call <vscale x 4 x i32> @llvm.aarch64.sve.tuple.get.nxv4i32.nxv16i32(<vscale x 16 x i32> %data, i32 1)
  // CHECK-DAG: %[[V2:.*]] = call <vscale x 4 x i32> @llvm.aarch64.sve.tuple.get.nxv4i32.nxv16i32(<vscale x 16 x i32> %data, i32 2)
  // CHECK-DAG: %[[V3:.*]] = call <vscale x 4 x i32> @llvm.aarch64.sve.tuple.get.nxv4i32.nxv16i32(<vscale x 16 x i32> %data, i32 3)
  // CHECK-DAG: %[[PG:.*]] = call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> %pg)
  // CHECK: call void @llvm.aarch64.sve.st4.nxv4i32(<vscale x 4 x i32> %[[V0]], <vscale x 4 x i32> %[[V1]], <vscale x 4 x i32> %[[V2]], <vscale x 4 x i32> %[[V3]], <vscale x 4 x i1> %[[PG]], i32* %[[GEP]])
  // CHECK-NEXT: ret
  return SVE_ACLE_FUNC(svst4_vnum,_s32,,)(pg, base, vnum, data);
}

void test_svst4_vnum_s64(svbool_t pg, int64_t *base, int64_t vnum, svint64x4_t data)
{
  // CHECK-LABEL: test_svst4_vnum_s64
  // CHECK-DAG: %[[BITCAST:.*]] = bitcast i64* %base to <vscale x 2 x i64>*
  // CHECK-DAG: %[[GEP:.*]] = getelementptr <vscale x 2 x i64>, <vscale x 2 x i64>* %[[BITCAST]], i64 %vnum, i64 0
  // CHECK-DAG: %[[V0:.*]] = call <vscale x 2 x i64> @llvm.aarch64.sve.tuple.get.nxv2i64.nxv8i64(<vscale x 8 x i64> %data, i32 0)
  // CHECK-DAG: %[[V1:.*]] = call <vscale x 2 x i64> @llvm.aarch64.sve.tuple.get.nxv2i64.nxv8i64(<vscale x 8 x i64> %data, i32 1)
  // CHECK-DAG: %[[V2:.*]] = call <vscale x 2 x i64> @llvm.aarch64.sve.tuple.get.nxv2i64.nxv8i64(<vscale x 8 x i64> %data, i32 2)
  // CHECK-DAG: %[[V3:.*]] = call <vscale x 2 x i64> @llvm.aarch64.sve.tuple.get.nxv2i64.nxv8i64(<vscale x 8 x i64> %data, i32 3)
  // CHECK-DAG: %[[PG:.*]] = call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> %pg)
  // CHECK: call void @llvm.aarch64.sve.st4.nxv2i64(<vscale x 2 x i64> %[[V0]], <vscale x 2 x i64> %[[V1]], <vscale x 2 x i64> %[[V2]], <vscale x 2 x i64> %[[V3]], <vscale x 2 x i1> %[[PG]], i64* %[[GEP]])
  // CHECK-NEXT: ret
  return SVE_ACLE_FUNC(svst4_vnum,_s64,,)(pg, base, vnum, data);
}

void test_svst4_vnum_u8(svbool_t pg, uint8_t *base, int64_t vnum, svuint8x4_t data)
{
  // CHECK-LABEL: test_svst4_vnum_u8
  // CHECK-DAG: %[[BITCAST:.*]] = bitcast i8* %base to <vscale x 16 x i8>*
  // CHECK-DAG: %[[GEP:.*]] = getelementptr <vscale x 16 x i8>, <vscale x 16 x i8>* %[[BITCAST]], i64 %vnum, i64 0
  // CHECK-DAG: %[[V0:.*]] = call <vscale x 16 x i8> @llvm.aarch64.sve.tuple.get.nxv16i8.nxv64i8(<vscale x 64 x i8> %data, i32 0)
  // CHECK-DAG: %[[V1:.*]] = call <vscale x 16 x i8> @llvm.aarch64.sve.tuple.get.nxv16i8.nxv64i8(<vscale x 64 x i8> %data, i32 1)
  // CHECK-DAG: %[[V2:.*]] = call <vscale x 16 x i8> @llvm.aarch64.sve.tuple.get.nxv16i8.nxv64i8(<vscale x 64 x i8> %data, i32 2)
  // CHECK-DAG: %[[V3:.*]] = call <vscale x 16 x i8> @llvm.aarch64.sve.tuple.get.nxv16i8.nxv64i8(<vscale x 64 x i8> %data, i32 3)
  // CHECK: call void @llvm.aarch64.sve.st4.nxv16i8(<vscale x 16 x i8> %[[V0]], <vscale x 16 x i8> %[[V1]], <vscale x 16 x i8> %[[V2]], <vscale x 16 x i8> %[[V3]], <vscale x 16 x i1> %pg, i8* %[[GEP]])
  // CHECK-NEXT: ret
  return SVE_ACLE_FUNC(svst4_vnum,_u8,,)(pg, base, vnum, data);
}

void test_svst4_vnum_u16(svbool_t pg, uint16_t *base, int64_t vnum, svuint16x4_t data)
{
  // CHECK-LABEL: test_svst4_vnum_u16
  // CHECK-DAG: %[[BITCAST:.*]] = bitcast i16* %base to <vscale x 8 x i16>*
  // CHECK-DAG: %[[GEP:.*]] = getelementptr <vscale x 8 x i16>, <vscale x 8 x i16>* %[[BITCAST]], i64 %vnum, i64 0
  // CHECK-DAG: %[[V0:.*]] = call <vscale x 8 x i16> @llvm.aarch64.sve.tuple.get.nxv8i16.nxv32i16(<vscale x 32 x i16> %data, i32 0)
  // CHECK-DAG: %[[V1:.*]] = call <vscale x 8 x i16> @llvm.aarch64.sve.tuple.get.nxv8i16.nxv32i16(<vscale x 32 x i16> %data, i32 1)
  // CHECK-DAG: %[[V2:.*]] = call <vscale x 8 x i16> @llvm.aarch64.sve.tuple.get.nxv8i16.nxv32i16(<vscale x 32 x i16> %data, i32 2)
  // CHECK-DAG: %[[V3:.*]] = call <vscale x 8 x i16> @llvm.aarch64.sve.tuple.get.nxv8i16.nxv32i16(<vscale x 32 x i16> %data, i32 3)
  // CHECK-DAG: %[[PG:.*]] = call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> %pg)
  // CHECK: call void @llvm.aarch64.sve.st4.nxv8i16(<vscale x 8 x i16> %[[V0]], <vscale x 8 x i16> %[[V1]], <vscale x 8 x i16> %[[V2]], <vscale x 8 x i16> %[[V3]], <vscale x 8 x i1> %[[PG]], i16* %[[GEP]])
  // CHECK-NEXT: ret
  return SVE_ACLE_FUNC(svst4_vnum,_u16,,)(pg, base, vnum, data);
}

void test_svst4_vnum_u32(svbool_t pg, uint32_t *base, int64_t vnum, svuint32x4_t data)
{
  // CHECK-LABEL: test_svst4_vnum_u32
  // CHECK-DAG: %[[BITCAST:.*]] = bitcast i32* %base to <vscale x 4 x i32>*
  // CHECK-DAG: %[[GEP:.*]] = getelementptr <vscale x 4 x i32>, <vscale x 4 x i32>* %[[BITCAST]], i64 %vnum, i64 0
  // CHECK-DAG: %[[V0:.*]] = call <vscale x 4 x i32> @llvm.aarch64.sve.tuple.get.nxv4i32.nxv16i32(<vscale x 16 x i32> %data, i32 0)
  // CHECK-DAG: %[[V1:.*]] = call <vscale x 4 x i32> @llvm.aarch64.sve.tuple.get.nxv4i32.nxv16i32(<vscale x 16 x i32> %data, i32 1)
  // CHECK-DAG: %[[V2:.*]] = call <vscale x 4 x i32> @llvm.aarch64.sve.tuple.get.nxv4i32.nxv16i32(<vscale x 16 x i32> %data, i32 2)
  // CHECK-DAG: %[[V3:.*]] = call <vscale x 4 x i32> @llvm.aarch64.sve.tuple.get.nxv4i32.nxv16i32(<vscale x 16 x i32> %data, i32 3)
  // CHECK-DAG: %[[PG:.*]] = call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> %pg)
  // CHECK: call void @llvm.aarch64.sve.st4.nxv4i32(<vscale x 4 x i32> %[[V0]], <vscale x 4 x i32> %[[V1]], <vscale x 4 x i32> %[[V2]], <vscale x 4 x i32> %[[V3]], <vscale x 4 x i1> %[[PG]], i32* %[[GEP]])
  // CHECK-NEXT: ret
  return SVE_ACLE_FUNC(svst4_vnum,_u32,,)(pg, base, vnum, data);
}

void test_svst4_vnum_u64(svbool_t pg, uint64_t *base, int64_t vnum, svuint64x4_t data)
{
  // CHECK-LABEL: test_svst4_vnum_u64
  // CHECK-DAG: %[[BITCAST:.*]] = bitcast i64* %base to <vscale x 2 x i64>*
  // CHECK-DAG: %[[GEP:.*]] = getelementptr <vscale x 2 x i64>, <vscale x 2 x i64>* %[[BITCAST]], i64 %vnum, i64 0
  // CHECK-DAG: %[[V0:.*]] = call <vscale x 2 x i64> @llvm.aarch64.sve.tuple.get.nxv2i64.nxv8i64(<vscale x 8 x i64> %data, i32 0)
  // CHECK-DAG: %[[V1:.*]] = call <vscale x 2 x i64> @llvm.aarch64.sve.tuple.get.nxv2i64.nxv8i64(<vscale x 8 x i64> %data, i32 1)
  // CHECK-DAG: %[[V2:.*]] = call <vscale x 2 x i64> @llvm.aarch64.sve.tuple.get.nxv2i64.nxv8i64(<vscale x 8 x i64> %data, i32 2)
  // CHECK-DAG: %[[V3:.*]] = call <vscale x 2 x i64> @llvm.aarch64.sve.tuple.get.nxv2i64.nxv8i64(<vscale x 8 x i64> %data, i32 3)
  // CHECK-DAG: %[[PG:.*]] = call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> %pg)
  // CHECK: call void @llvm.aarch64.sve.st4.nxv2i64(<vscale x 2 x i64> %[[V0]], <vscale x 2 x i64> %[[V1]], <vscale x 2 x i64> %[[V2]], <vscale x 2 x i64> %[[V3]], <vscale x 2 x i1> %[[PG]], i64* %[[GEP]])
  // CHECK-NEXT: ret
  return SVE_ACLE_FUNC(svst4_vnum,_u64,,)(pg, base, vnum, data);
}

void test_svst4_vnum_f16(svbool_t pg, float16_t *base, int64_t vnum, svfloat16x4_t data)
{
  // CHECK-LABEL: test_svst4_vnum_f16
  // CHECK-DAG: %[[BITCAST:.*]] = bitcast half* %base to <vscale x 8 x half>*
  // CHECK-DAG: %[[GEP:.*]] = getelementptr <vscale x 8 x half>, <vscale x 8 x half>* %[[BITCAST]], i64 %vnum, i64 0
  // CHECK-DAG: %[[V0:.*]] = call <vscale x 8 x half> @llvm.aarch64.sve.tuple.get.nxv8f16.nxv32f16(<vscale x 32 x half> %data, i32 0)
  // CHECK-DAG: %[[V1:.*]] = call <vscale x 8 x half> @llvm.aarch64.sve.tuple.get.nxv8f16.nxv32f16(<vscale x 32 x half> %data, i32 1)
  // CHECK-DAG: %[[V2:.*]] = call <vscale x 8 x half> @llvm.aarch64.sve.tuple.get.nxv8f16.nxv32f16(<vscale x 32 x half> %data, i32 2)
  // CHECK-DAG: %[[V3:.*]] = call <vscale x 8 x half> @llvm.aarch64.sve.tuple.get.nxv8f16.nxv32f16(<vscale x 32 x half> %data, i32 3)
  // CHECK-DAG: %[[PG:.*]] = call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> %pg)
  // CHECK: call void @llvm.aarch64.sve.st4.nxv8f16(<vscale x 8 x half> %[[V0]], <vscale x 8 x half> %[[V1]], <vscale x 8 x half> %[[V2]], <vscale x 8 x half> %[[V3]], <vscale x 8 x i1> %[[PG]], half* %[[GEP]])
  // CHECK-NEXT: ret
  return SVE_ACLE_FUNC(svst4_vnum,_f16,,)(pg, base, vnum, data);
}

void test_svst4_vnum_f32(svbool_t pg, float32_t *base, int64_t vnum, svfloat32x4_t data)
{
  // CHECK-LABEL: test_svst4_vnum_f32
  // CHECK-DAG: %[[BITCAST:.*]] = bitcast float* %base to <vscale x 4 x float>*
  // CHECK-DAG: %[[GEP:.*]] = getelementptr <vscale x 4 x float>, <vscale x 4 x float>* %[[BITCAST]], i64 %vnum, i64 0
  // CHECK-DAG: %[[V0:.*]] = call <vscale x 4 x float> @llvm.aarch64.sve.tuple.get.nxv4f32.nxv16f32(<vscale x 16 x float> %data, i32 0)
  // CHECK-DAG: %[[V1:.*]] = call <vscale x 4 x float> @llvm.aarch64.sve.tuple.get.nxv4f32.nxv16f32(<vscale x 16 x float> %data, i32 1)
  // CHECK-DAG: %[[V2:.*]] = call <vscale x 4 x float> @llvm.aarch64.sve.tuple.get.nxv4f32.nxv16f32(<vscale x 16 x float> %data, i32 2)
  // CHECK-DAG: %[[V3:.*]] = call <vscale x 4 x float> @llvm.aarch64.sve.tuple.get.nxv4f32.nxv16f32(<vscale x 16 x float> %data, i32 3)
  // CHECK-DAG: %[[PG:.*]] = call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> %pg)
  // CHECK: call void @llvm.aarch64.sve.st4.nxv4f32(<vscale x 4 x float> %[[V0]], <vscale x 4 x float> %[[V1]], <vscale x 4 x float> %[[V2]], <vscale x 4 x float> %[[V3]], <vscale x 4 x i1> %[[PG]], float* %[[GEP]])
  // CHECK-NEXT: ret
  return SVE_ACLE_FUNC(svst4_vnum,_f32,,)(pg, base, vnum, data);
}

void test_svst4_vnum_f64(svbool_t pg, float64_t *base, int64_t vnum, svfloat64x4_t data)
{
  // CHECK-LABEL: test_svst4_vnum_f64
  // CHECK-DAG: %[[BITCAST:.*]] = bitcast double* %base to <vscale x 2 x double>*
  // CHECK-DAG: %[[GEP:.*]] = getelementptr <vscale x 2 x double>, <vscale x 2 x double>* %[[BITCAST]], i64 %vnum, i64 0
  // CHECK-DAG: %[[V0:.*]] = call <vscale x 2 x double> @llvm.aarch64.sve.tuple.get.nxv2f64.nxv8f64(<vscale x 8 x double> %data, i32 0)
  // CHECK-DAG: %[[V1:.*]] = call <vscale x 2 x double> @llvm.aarch64.sve.tuple.get.nxv2f64.nxv8f64(<vscale x 8 x double> %data, i32 1)
  // CHECK-DAG: %[[V2:.*]] = call <vscale x 2 x double> @llvm.aarch64.sve.tuple.get.nxv2f64.nxv8f64(<vscale x 8 x double> %data, i32 2)
  // CHECK-DAG: %[[V3:.*]] = call <vscale x 2 x double> @llvm.aarch64.sve.tuple.get.nxv2f64.nxv8f64(<vscale x 8 x double> %data, i32 3)
  // CHECK-DAG: %[[PG:.*]] = call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> %pg)
  // CHECK: call void @llvm.aarch64.sve.st4.nxv2f64(<vscale x 2 x double> %[[V0]], <vscale x 2 x double> %[[V1]], <vscale x 2 x double> %[[V2]], <vscale x 2 x double> %[[V3]], <vscale x 2 x i1> %[[PG]], double* %[[GEP]])
  // CHECK-NEXT: ret
  return SVE_ACLE_FUNC(svst4_vnum,_f64,,)(pg, base, vnum, data);
}
