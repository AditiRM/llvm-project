// RUN: mlir-translate -no-implicit-module -test-spirv-roundtrip -split-input-file %s | FileCheck %s

spirv.module Logical GLSL450 requires #spirv.vce<v1.0, [Shader], []> {
  spirv.func @bit_cast(%arg0 : f32) "None" {
    // CHECK: {{%.*}} = spirv.Bitcast {{%.*}} : f32 to i32
    %0 = spirv.Bitcast %arg0 : f32 to i32
    // CHECK: {{%.*}} = spirv.Bitcast {{%.*}} : i32 to si32
    %1 = spirv.Bitcast %0 : i32 to si32
    // CHECK: {{%.*}} = spirv.Bitcast {{%.*}} : si32 to i32
    %2 = spirv.Bitcast %1 : si32 to ui32
    spirv.Return
  }
}

// -----

spirv.module Logical GLSL450 requires #spirv.vce<v1.0, [Shader], []> {
  spirv.func @convert_f_to_s(%arg0 : f32) -> i32 "None" {
    // CHECK: {{%.*}} = spirv.ConvertFToS {{%.*}} : f32 to i32
    %0 = spirv.ConvertFToS %arg0 : f32 to i32
    spirv.ReturnValue %0 : i32
  }
  spirv.func @convert_f64_to_s32(%arg0 : f64) -> i32 "None" {
    // CHECK: {{%.*}} = spirv.ConvertFToS {{%.*}} : f64 to i32
    %0 = spirv.ConvertFToS %arg0 : f64 to i32
    spirv.ReturnValue %0 : i32
  }
  spirv.func @convert_bf16_to_s32(%arg0 : bf16) -> i32 "None" {
    // CHECK: {{%.*}} = spirv.ConvertFToS {{%.*}} : bf16 to i32
    %0 = spirv.ConvertFToS %arg0 : bf16 to i32
    spirv.ReturnValue %0 : i32
  }
  spirv.func @convert_f_to_u(%arg0 : f32) -> i32 "None" {
    // CHECK: {{%.*}} = spirv.ConvertFToU {{%.*}} : f32 to i32
    %0 = spirv.ConvertFToU %arg0 : f32 to i32
    spirv.ReturnValue %0 : i32
  }
  spirv.func @convert_f64_to_u32(%arg0 : f64) -> i32 "None" {
    // CHECK: {{%.*}} = spirv.ConvertFToU {{%.*}} : f64 to i32
    %0 = spirv.ConvertFToU %arg0 : f64 to i32
    spirv.ReturnValue %0 : i32
  }
  spirv.func @convert_bf16_to_u32(%arg0 : bf16) -> i32 "None" {
    // CHECK: {{%.*}} = spirv.ConvertFToU {{%.*}} : bf16 to i32
    %0 = spirv.ConvertFToU %arg0 : bf16 to i32
    spirv.ReturnValue %0 : i32
  }
  spirv.func @convert_s_to_f(%arg0 : i32) -> f32 "None" {
    // CHECK: {{%.*}} = spirv.ConvertSToF {{%.*}} : i32 to f32
    %0 = spirv.ConvertSToF %arg0 : i32 to f32
    spirv.ReturnValue %0 : f32
  }
  spirv.func @convert_s64_to_f32(%arg0 : i64) -> f32 "None" {
    // CHECK: {{%.*}} = spirv.ConvertSToF {{%.*}} : i64 to f32
    %0 = spirv.ConvertSToF %arg0 : i64 to f32
    spirv.ReturnValue %0 : f32
  }
  spirv.func @convert_s64_to_bf16(%arg0 : i64) -> bf16 "None" {
    // CHECK: {{%.*}} = spirv.ConvertSToF {{%.*}} : i64 to bf16
    %0 = spirv.ConvertSToF %arg0 : i64 to bf16
    spirv.ReturnValue %0 : bf16
  }
  spirv.func @convert_u_to_f(%arg0 : i32) -> f32 "None" {
    // CHECK: {{%.*}} = spirv.ConvertUToF {{%.*}} : i32 to f32
    %0 = spirv.ConvertUToF %arg0 : i32 to f32
    spirv.ReturnValue %0 : f32
  }
  spirv.func @convert_u64_to_f32(%arg0 : i64) -> f32 "None" {
    // CHECK: {{%.*}} = spirv.ConvertUToF {{%.*}} : i64 to f32
    %0 = spirv.ConvertUToF %arg0 : i64 to f32
    spirv.ReturnValue %0 : f32
  }
  spirv.func @convert_u64_to_bf16(%arg0 : i64) -> bf16 "None" {
    // CHECK: {{%.*}} = spirv.ConvertUToF {{%.*}} : i64 to bf16
    %0 = spirv.ConvertUToF %arg0 : i64 to bf16
    spirv.ReturnValue %0 : bf16
  }
  spirv.func @convert_f32_to_f64(%arg0 : f32) -> f64 "None" {
    // CHECK: {{%.*}} = spirv.FConvert {{%.*}} : f32 to f64
    %0 = spirv.FConvert %arg0 : f32 to f64
    spirv.ReturnValue %0 : f64
  }
  spirv.func @convert_f32_to_bf16(%arg0 : f32) -> bf16 "None" {
    // CHECK: {{%.*}} = spirv.FConvert {{%.*}} : f32 to bf16
    %0 = spirv.FConvert %arg0 : f32 to bf16
    spirv.ReturnValue %0 : bf16
  }
  spirv.func @convert_bf16_to_f32(%arg0 : bf16) -> f32 "None" {
    // CHECK: {{%.*}} = spirv.FConvert {{%.*}} : bf16 to f32
    %0 = spirv.FConvert %arg0 : bf16 to f32
    spirv.ReturnValue %0 : f32
  }
  spirv.func @s_convert(%arg0 : i32) -> i64 "None" {
    // CHECK: {{%.*}} = spirv.SConvert {{%.*}} : i32 to i64
    %0 = spirv.SConvert %arg0 : i32 to i64
    spirv.ReturnValue %0 : i64
  }
  spirv.func @u_convert(%arg0 : i32) -> i64 "None" {
    // CHECK: {{%.*}} = spirv.UConvert {{%.*}} : i32 to i64
    %0 = spirv.UConvert %arg0 : i32 to i64
    spirv.ReturnValue %0 : i64
  }
}

// -----

spirv.module Logical GLSL450 requires #spirv.vce<v1.0, [Kernel], []> {
  spirv.func @ptr_cast_to_generic(%arg0 : !spirv.ptr<f32, CrossWorkgroup>) "None" {
    // CHECK: {{%.*}} = spirv.PtrCastToGeneric {{%.*}} : !spirv.ptr<f32, CrossWorkgroup> to !spirv.ptr<f32, Generic>
    %0 = spirv.PtrCastToGeneric %arg0 : !spirv.ptr<f32, CrossWorkgroup> to !spirv.ptr<f32, Generic>
    spirv.Return
  }
  spirv.func @generic_cast_to_ptr(%arg0 : !spirv.ptr<vector<2xi32>, Generic>) "None" {
    // CHECK: {{%.*}} = spirv.GenericCastToPtr {{%.*}} : !spirv.ptr<vector<2xi32>, Generic> to !spirv.ptr<vector<2xi32>, CrossWorkgroup>
    %0 = spirv.GenericCastToPtr %arg0 : !spirv.ptr<vector<2xi32>, Generic> to !spirv.ptr<vector<2xi32>, CrossWorkgroup>
    spirv.Return
  }
  spirv.func @generic_cast_to_ptr_explicit(%arg0 : !spirv.ptr<vector<2xi32>, Generic>) "None" {
    // CHECK: {{%.*}} = spirv.GenericCastToPtrExplicit {{%.*}} : !spirv.ptr<vector<2xi32>, Generic> to !spirv.ptr<vector<2xi32>, CrossWorkgroup>
    %0 = spirv.GenericCastToPtrExplicit %arg0 : !spirv.ptr<vector<2xi32>, Generic> to !spirv.ptr<vector<2xi32>, CrossWorkgroup>
    spirv.Return
  }
}

// -----

spirv.module Physical64 OpenCL requires #spirv.vce<v1.0, [Kernel, Addresses], []> {
  spirv.func @covert_ptr_to_u(%arg0 : !spirv.ptr<i32, Generic>) "None" {
    // CHECK: {{%.*}} = spirv.ConvertPtrToU {{%.*}} : !spirv.ptr<i32, Generic> to i32
    %0 = spirv.ConvertPtrToU %arg0 : !spirv.ptr<i32, Generic> to i32
    spirv.Return
  }
  spirv.func @covert_ptr_to_u_truncate(%arg0 : !spirv.ptr<i64, Generic>) "None" {
    // CHECK: {{%.*}} = spirv.ConvertPtrToU {{%.*}} : !spirv.ptr<i64, Generic> to i32
    %0 = spirv.ConvertPtrToU %arg0 : !spirv.ptr<i64, Generic> to i32
    spirv.Return
  }
  spirv.func @covert_ptr_to_u_extend(%arg0 : !spirv.ptr<i32, Generic>) "None" {
    // CHECK: {{%.*}} = spirv.ConvertPtrToU {{%.*}} : !spirv.ptr<i32, Generic> to i64
    %0 = spirv.ConvertPtrToU %arg0 : !spirv.ptr<i32, Generic> to i64
    spirv.Return
  }
}

// -----

spirv.module PhysicalStorageBuffer64 OpenCL requires #spirv.vce<v1.0, [Kernel, Addresses, PhysicalStorageBufferAddresses], []> {  
  spirv.func @covert_ptr_to_u_PhysicalStorageBuffer(%arg0 : !spirv.ptr<i32, PhysicalStorageBuffer> { spirv.decoration = #spirv.decoration<Aliased>} ) "None" {
    // CHECK: {{%.*}} = spirv.ConvertPtrToU {{%.*}} : !spirv.ptr<i32, PhysicalStorageBuffer> to i32
    %0 = spirv.ConvertPtrToU %arg0 : !spirv.ptr<i32, PhysicalStorageBuffer> to i32
    spirv.Return
  }
}

// -----

spirv.module Physical64 OpenCL requires #spirv.vce<v1.0, [Kernel, Addresses], []> {
  spirv.func @covert_u_to_ptr(%arg0 : i32) "None" {
    // CHECK: {{%.*}} = spirv.ConvertUToPtr {{%.*}} : i32 to !spirv.ptr<i32, Generic> 
    %0 = spirv.ConvertUToPtr %arg0 : i32 to !spirv.ptr<i32, Generic>
    spirv.Return
  }
  spirv.func @covert_u_to_ptr_truncate(%arg0 : i64) "None" {
    // CHECK: {{%.*}} = spirv.ConvertUToPtr {{%.*}} : i64 to !spirv.ptr<i32, Generic> 
    %0 = spirv.ConvertUToPtr %arg0 : i64 to !spirv.ptr<i32, Generic>
    spirv.Return
  }
  spirv.func @covert_u_to_ptr_extend(%arg0 : i32) "None" {
    // CHECK: {{%.*}} = spirv.ConvertUToPtr {{%.*}} : i32 to !spirv.ptr<i64, Generic> 
    %0 = spirv.ConvertUToPtr %arg0 : i32 to !spirv.ptr<i64, Generic>
    spirv.Return
  }
}

// -----

spirv.module PhysicalStorageBuffer64 OpenCL requires #spirv.vce<v1.0, [Kernel, Addresses, PhysicalStorageBufferAddresses], []> {
  spirv.func @covert_u_to_ptr_PhysicalStorageBuffer(%arg0 : i32) "None" {
    // CHECK: {{%.*}} = spirv.ConvertUToPtr {{%.*}} : i32 to !spirv.ptr<i32, PhysicalStorageBuffer>
    %0 = spirv.ConvertUToPtr %arg0 : i32 to !spirv.ptr<i32, PhysicalStorageBuffer>
    spirv.Return
  }
}
