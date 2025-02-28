// REQUIRES: aarch64-registered-target
// RUN: %clang_cc1 -triple aarch64-none-linux-gnu -target-feature +sve -fallow-half-arguments-and-returns -S -O1 -Werror -Wall -emit-llvm -o - %s | FileCheck %s
// RUN: %clang_cc1 -triple aarch64-none-linux-gnu -target-feature +sve -fallow-half-arguments-and-returns -S -O1 -Werror -o - %s >/dev/null
#include <arm_sve.h>

svint32_t test_svldnf1uh_s32(svbool_t pg, const uint16_t *base)
{
  // CHECK-LABEL: test_svldnf1uh_s32
  // CHECK: %[[PG:.*]] = call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> %pg)
  // CHECK: %[[LOAD:.*]] = call <vscale x 4 x i16> @llvm.aarch64.sve.ldnf1.nxv4i16(<vscale x 4 x i1> %[[PG]], i16* %base)
  // CHECK: %[[ZEXT:.*]] = zext <vscale x 4 x i16> %[[LOAD]] to <vscale x 4 x i32>
  // CHECK: ret <vscale x 4 x i32> %[[ZEXT]]
  return svldnf1uh_s32(pg, base);
}

svint64_t test_svldnf1uh_s64(svbool_t pg, const uint16_t *base)
{
  // CHECK-LABEL: test_svldnf1uh_s64
  // CHECK: %[[PG:.*]] = call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> %pg)
  // CHECK: %[[LOAD:.*]] = call <vscale x 2 x i16> @llvm.aarch64.sve.ldnf1.nxv2i16(<vscale x 2 x i1> %[[PG]], i16* %base)
  // CHECK: %[[ZEXT:.*]] = zext <vscale x 2 x i16> %[[LOAD]] to <vscale x 2 x i64>
  // CHECK: ret <vscale x 2 x i64> %[[ZEXT]]
  return svldnf1uh_s64(pg, base);
}

svuint32_t test_svldnf1uh_u32(svbool_t pg, const uint16_t *base)
{
  // CHECK-LABEL: test_svldnf1uh_u32
  // CHECK: %[[PG:.*]] = call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> %pg)
  // CHECK: %[[LOAD:.*]] = call <vscale x 4 x i16> @llvm.aarch64.sve.ldnf1.nxv4i16(<vscale x 4 x i1> %[[PG]], i16* %base)
  // CHECK: %[[ZEXT:.*]] = zext <vscale x 4 x i16> %[[LOAD]] to <vscale x 4 x i32>
  // CHECK: ret <vscale x 4 x i32> %[[ZEXT]]
  return svldnf1uh_u32(pg, base);
}

svuint64_t test_svldnf1uh_u64(svbool_t pg, const uint16_t *base)
{
  // CHECK-LABEL: test_svldnf1uh_u64
  // CHECK: %[[PG:.*]] = call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> %pg)
  // CHECK: %[[LOAD:.*]] = call <vscale x 2 x i16> @llvm.aarch64.sve.ldnf1.nxv2i16(<vscale x 2 x i1> %[[PG]], i16* %base)
  // CHECK: %[[ZEXT:.*]] = zext <vscale x 2 x i16> %[[LOAD]] to <vscale x 2 x i64>
  // CHECK: ret <vscale x 2 x i64> %[[ZEXT]]
  return svldnf1uh_u64(pg, base);
}

svint32_t test_svldnf1uh_vnum_s32(svbool_t pg, const uint16_t *base, int64_t vnum)
{
  // CHECK-LABEL: test_svldnf1uh_vnum_s32
  // CHECK-DAG: %[[PG:.*]] = call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> %pg)
  // CHECK-DAG: %[[BITCAST:.*]] = bitcast i16* %base to <vscale x 4 x i16>*
  // CHECK-DAG: %[[GEP:.*]] = getelementptr <vscale x 4 x i16>, <vscale x 4 x i16>* %[[BITCAST]], i64 %vnum, i64 0
  // CHECK: %[[LOAD:.*]] = call <vscale x 4 x i16> @llvm.aarch64.sve.ldnf1.nxv4i16(<vscale x 4 x i1> %[[PG]], i16* %[[GEP]])
  // CHECK: %[[ZEXT:.*]] = zext <vscale x 4 x i16> %[[LOAD]] to <vscale x 4 x i32>
  // CHECK: ret <vscale x 4 x i32> %[[ZEXT]]
  return svldnf1uh_vnum_s32(pg, base, vnum);
}

svint64_t test_svldnf1uh_vnum_s64(svbool_t pg, const uint16_t *base, int64_t vnum)
{
  // CHECK-LABEL: test_svldnf1uh_vnum_s64
  // CHECK-DAG: %[[PG:.*]] = call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> %pg)
  // CHECK-DAG: %[[BITCAST:.*]] = bitcast i16* %base to <vscale x 2 x i16>*
  // CHECK-DAG: %[[GEP:.*]] = getelementptr <vscale x 2 x i16>, <vscale x 2 x i16>* %[[BITCAST]], i64 %vnum, i64 0
  // CHECK: %[[LOAD:.*]] = call <vscale x 2 x i16> @llvm.aarch64.sve.ldnf1.nxv2i16(<vscale x 2 x i1> %[[PG]], i16* %[[GEP]])
  // CHECK: %[[ZEXT:.*]] = zext <vscale x 2 x i16> %[[LOAD]] to <vscale x 2 x i64>
  // CHECK: ret <vscale x 2 x i64> %[[ZEXT]]
  return svldnf1uh_vnum_s64(pg, base, vnum);
}

svuint32_t test_svldnf1uh_vnum_u32(svbool_t pg, const uint16_t *base, int64_t vnum)
{
  // CHECK-LABEL: test_svldnf1uh_vnum_u32
  // CHECK-DAG: %[[PG:.*]] = call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> %pg)
  // CHECK-DAG: %[[BITCAST:.*]] = bitcast i16* %base to <vscale x 4 x i16>*
  // CHECK-DAG: %[[GEP:.*]] = getelementptr <vscale x 4 x i16>, <vscale x 4 x i16>* %[[BITCAST]], i64 %vnum, i64 0
  // CHECK: %[[LOAD:.*]] = call <vscale x 4 x i16> @llvm.aarch64.sve.ldnf1.nxv4i16(<vscale x 4 x i1> %[[PG]], i16* %[[GEP]])
  // CHECK: %[[ZEXT:.*]] = zext <vscale x 4 x i16> %[[LOAD]] to <vscale x 4 x i32>
  // CHECK: ret <vscale x 4 x i32> %[[ZEXT]]
  return svldnf1uh_vnum_u32(pg, base, vnum);
}

svuint64_t test_svldnf1uh_vnum_u64(svbool_t pg, const uint16_t *base, int64_t vnum)
{
  // CHECK-LABEL: test_svldnf1uh_vnum_u64
  // CHECK-DAG: %[[PG:.*]] = call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> %pg)
  // CHECK-DAG: %[[BITCAST:.*]] = bitcast i16* %base to <vscale x 2 x i16>*
  // CHECK-DAG: %[[GEP:.*]] = getelementptr <vscale x 2 x i16>, <vscale x 2 x i16>* %[[BITCAST]], i64 %vnum, i64 0
  // CHECK: %[[LOAD:.*]] = call <vscale x 2 x i16> @llvm.aarch64.sve.ldnf1.nxv2i16(<vscale x 2 x i1> %[[PG]], i16* %[[GEP]])
  // CHECK: %[[ZEXT:.*]] = zext <vscale x 2 x i16> %[[LOAD]] to <vscale x 2 x i64>
  // CHECK: ret <vscale x 2 x i64> %[[ZEXT]]
  return svldnf1uh_vnum_u64(pg, base, vnum);
}
