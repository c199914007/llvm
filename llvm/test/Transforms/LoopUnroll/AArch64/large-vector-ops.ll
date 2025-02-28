; NOTE: Assertions have been autogenerated by utils/update_test_checks.py
; RUN: opt -loop-unroll -S %s | FileCheck %s

target datalayout = "e-m:o-i64:64-i128:128-n32:64-S128"
target triple = "arm64-apple-ios5.0.0"

; The loop in the function only contains a few instructions, but they will get
; lowered to a very large amount of target instructions.
; FIXME: Currently the cost-model assigns a cost of 1 to those large vector ops.
define void @loop_with_large_vector_ops(i32 %i, <225 x double>* %A, <225 x double>* %B) {
; CHECK-LABEL: @loop_with_large_vector_ops(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    br label [[LOOP:%.*]]
; CHECK:       loop:
; CHECK-NEXT:    [[LV_1:%.*]] = load <225 x double>, <225 x double>* [[A:%.*]], align 8
; CHECK-NEXT:    [[LV_2:%.*]] = load <225 x double>, <225 x double>* [[A]], align 8
; CHECK-NEXT:    [[MUL:%.*]] = fmul <225 x double> [[LV_1]], [[LV_2]]
; CHECK-NEXT:    store <225 x double> [[MUL]], <225 x double>* [[A]], align 8
; CHECK-NEXT:    [[A_GEP_1:%.*]] = getelementptr <225 x double>, <225 x double>* [[A]], i32 1
; CHECK-NEXT:    [[LV_1_1:%.*]] = load <225 x double>, <225 x double>* [[A_GEP_1]], align 8
; CHECK-NEXT:    [[B_GEP_1:%.*]] = getelementptr <225 x double>, <225 x double>* [[A]], i32 1
; CHECK-NEXT:    [[LV_2_1:%.*]] = load <225 x double>, <225 x double>* [[B_GEP_1]], align 8
; CHECK-NEXT:    [[MUL_1:%.*]] = fmul <225 x double> [[LV_1_1]], [[LV_2_1]]
; CHECK-NEXT:    store <225 x double> [[MUL_1]], <225 x double>* [[B_GEP_1]], align 8
; CHECK-NEXT:    [[A_GEP_2:%.*]] = getelementptr <225 x double>, <225 x double>* [[A]], i32 2
; CHECK-NEXT:    [[LV_1_2:%.*]] = load <225 x double>, <225 x double>* [[A_GEP_2]], align 8
; CHECK-NEXT:    [[B_GEP_2:%.*]] = getelementptr <225 x double>, <225 x double>* [[A]], i32 2
; CHECK-NEXT:    [[LV_2_2:%.*]] = load <225 x double>, <225 x double>* [[B_GEP_2]], align 8
; CHECK-NEXT:    [[MUL_2:%.*]] = fmul <225 x double> [[LV_1_2]], [[LV_2_2]]
; CHECK-NEXT:    store <225 x double> [[MUL_2]], <225 x double>* [[B_GEP_2]], align 8
; CHECK-NEXT:    [[A_GEP_3:%.*]] = getelementptr <225 x double>, <225 x double>* [[A]], i32 3
; CHECK-NEXT:    [[LV_1_3:%.*]] = load <225 x double>, <225 x double>* [[A_GEP_3]], align 8
; CHECK-NEXT:    [[B_GEP_3:%.*]] = getelementptr <225 x double>, <225 x double>* [[A]], i32 3
; CHECK-NEXT:    [[LV_2_3:%.*]] = load <225 x double>, <225 x double>* [[B_GEP_3]], align 8
; CHECK-NEXT:    [[MUL_3:%.*]] = fmul <225 x double> [[LV_1_3]], [[LV_2_3]]
; CHECK-NEXT:    store <225 x double> [[MUL_3]], <225 x double>* [[B_GEP_3]], align 8
; CHECK-NEXT:    [[A_GEP_4:%.*]] = getelementptr <225 x double>, <225 x double>* [[A]], i32 4
; CHECK-NEXT:    [[LV_1_4:%.*]] = load <225 x double>, <225 x double>* [[A_GEP_4]], align 8
; CHECK-NEXT:    [[B_GEP_4:%.*]] = getelementptr <225 x double>, <225 x double>* [[A]], i32 4
; CHECK-NEXT:    [[LV_2_4:%.*]] = load <225 x double>, <225 x double>* [[B_GEP_4]], align 8
; CHECK-NEXT:    [[MUL_4:%.*]] = fmul <225 x double> [[LV_1_4]], [[LV_2_4]]
; CHECK-NEXT:    store <225 x double> [[MUL_4]], <225 x double>* [[B_GEP_4]], align 8
; CHECK-NEXT:    [[A_GEP_5:%.*]] = getelementptr <225 x double>, <225 x double>* [[A]], i32 5
; CHECK-NEXT:    [[LV_1_5:%.*]] = load <225 x double>, <225 x double>* [[A_GEP_5]], align 8
; CHECK-NEXT:    [[B_GEP_5:%.*]] = getelementptr <225 x double>, <225 x double>* [[A]], i32 5
; CHECK-NEXT:    [[LV_2_5:%.*]] = load <225 x double>, <225 x double>* [[B_GEP_5]], align 8
; CHECK-NEXT:    [[MUL_5:%.*]] = fmul <225 x double> [[LV_1_5]], [[LV_2_5]]
; CHECK-NEXT:    store <225 x double> [[MUL_5]], <225 x double>* [[B_GEP_5]], align 8
; CHECK-NEXT:    [[A_GEP_6:%.*]] = getelementptr <225 x double>, <225 x double>* [[A]], i32 6
; CHECK-NEXT:    [[LV_1_6:%.*]] = load <225 x double>, <225 x double>* [[A_GEP_6]], align 8
; CHECK-NEXT:    [[B_GEP_6:%.*]] = getelementptr <225 x double>, <225 x double>* [[A]], i32 6
; CHECK-NEXT:    [[LV_2_6:%.*]] = load <225 x double>, <225 x double>* [[B_GEP_6]], align 8
; CHECK-NEXT:    [[MUL_6:%.*]] = fmul <225 x double> [[LV_1_6]], [[LV_2_6]]
; CHECK-NEXT:    store <225 x double> [[MUL_6]], <225 x double>* [[B_GEP_6]], align 8
; CHECK-NEXT:    [[A_GEP_7:%.*]] = getelementptr <225 x double>, <225 x double>* [[A]], i32 7
; CHECK-NEXT:    [[LV_1_7:%.*]] = load <225 x double>, <225 x double>* [[A_GEP_7]], align 8
; CHECK-NEXT:    [[B_GEP_7:%.*]] = getelementptr <225 x double>, <225 x double>* [[A]], i32 7
; CHECK-NEXT:    [[LV_2_7:%.*]] = load <225 x double>, <225 x double>* [[B_GEP_7]], align 8
; CHECK-NEXT:    [[MUL_7:%.*]] = fmul <225 x double> [[LV_1_7]], [[LV_2_7]]
; CHECK-NEXT:    store <225 x double> [[MUL_7]], <225 x double>* [[B_GEP_7]], align 8
; CHECK-NEXT:    [[A_GEP_8:%.*]] = getelementptr <225 x double>, <225 x double>* [[A]], i32 8
; CHECK-NEXT:    [[LV_1_8:%.*]] = load <225 x double>, <225 x double>* [[A_GEP_8]], align 8
; CHECK-NEXT:    [[B_GEP_8:%.*]] = getelementptr <225 x double>, <225 x double>* [[A]], i32 8
; CHECK-NEXT:    [[LV_2_8:%.*]] = load <225 x double>, <225 x double>* [[B_GEP_8]], align 8
; CHECK-NEXT:    [[MUL_8:%.*]] = fmul <225 x double> [[LV_1_8]], [[LV_2_8]]
; CHECK-NEXT:    store <225 x double> [[MUL_8]], <225 x double>* [[B_GEP_8]], align 8
; CHECK-NEXT:    [[A_GEP_9:%.*]] = getelementptr <225 x double>, <225 x double>* [[A]], i32 9
; CHECK-NEXT:    [[LV_1_9:%.*]] = load <225 x double>, <225 x double>* [[A_GEP_9]], align 8
; CHECK-NEXT:    [[B_GEP_9:%.*]] = getelementptr <225 x double>, <225 x double>* [[A]], i32 9
; CHECK-NEXT:    [[LV_2_9:%.*]] = load <225 x double>, <225 x double>* [[B_GEP_9]], align 8
; CHECK-NEXT:    [[MUL_9:%.*]] = fmul <225 x double> [[LV_1_9]], [[LV_2_9]]
; CHECK-NEXT:    store <225 x double> [[MUL_9]], <225 x double>* [[B_GEP_9]], align 8
; CHECK-NEXT:    ret void
;
entry:
  br label %loop

loop:
  %iv = phi i32 [ 0, %entry ], [ %iv.next, %loop ]
  %A.gep = getelementptr <225 x  double>, <225 x  double>* %A, i32 %iv
  %lv.1 = load <225 x double>, <225 x double>* %A.gep, align 8
  %B.gep = getelementptr <225 x  double>, <225 x  double>* %A, i32 %iv
  %lv.2 = load <225 x double>, <225 x double>* %B.gep, align 8
  %mul = fmul <225 x double> %lv.1, %lv.2
  store <225 x double> %mul, <225 x double>* %B.gep, align 8
  %iv.next = add nuw i32 %iv, 1
  %cmp = icmp ult i32 %iv.next, 10
  br i1 %cmp, label %loop, label %exit

exit:
  ret void
}
