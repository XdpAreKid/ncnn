// Tencent is pleased to support the open source community by making ncnn available.
//
// Copyright (C) 2022 THL A29 Limited, a Tencent company. All rights reserved.
//
// Licensed under the BSD 3-Clause License (the "License"); you may not use this file except
// in compliance with the License. You may obtain a copy of the License at
//
// https://opensource.org/licenses/BSD-3-Clause
//
// Unless required by applicable law or agreed to in writing, software distributed
// under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied. See the License for the
// specific language governing permissions and limitations under the License.

#include "cpu.h"
#include "mat.h"
#include "x86_usability.h"

namespace ncnn {

#include "convolution_packed_int8.h"
#include "convolution_im2col_gemm_int8.h"
#include "convolution_3x3_winograd_int8.h"

// packed
void convolution_transform_kernel_packed_int8_avx2(const Mat& kernel, Mat& kernel_tm, int inch, int outch, int kernel_w, int kernel_h)
{
    convolution_transform_kernel_packed_int8(kernel, kernel_tm, inch, outch, kernel_w, kernel_h);
}

void convolution_packed_int8_avx2(const Mat& bottom_blob, Mat& top_blob, const Mat& weight_data_tm, int kernel_w, int kernel_h, int dilation_w, int dilation_h, int stride_w, int stride_h, const Option& opt)
{
    convolution_packed_int8(bottom_blob, top_blob, weight_data_tm, kernel_w, kernel_h, dilation_w, dilation_h, stride_w, stride_h, opt);
}

// gemm
void convolution_im2col_input_tile_int8_avx2(const Mat& bottom_blob, Mat& B, int j, int max_jj, int k, int max_kk, int kernel_w, int kernel_h, int dilation_w, int dilation_h, int stride_w, int stride_h)
{
    convolution_im2col_input_tile_int8(bottom_blob, B, j, max_jj, k, max_kk, kernel_w, kernel_h, dilation_w, dilation_h, stride_w, stride_h);
}

void unpack_output_tile_int32_avx2(const Mat& topT, Mat& top_blob, int i, int max_ii, int j, int max_jj)
{
    unpack_output_tile_int32(topT, top_blob, i, max_ii, j, max_jj);
}

// winograd
void conv3x3s1_winograd23_transform_kernel_int8_avx2(const Mat& kernel, Mat& AT, int inch, int outch, const Option& opt)
{
    conv3x3s1_winograd23_transform_kernel_int8(kernel, AT, inch, outch, opt);
}

int conv3x3s1_winograd23_int8_avx2(const Mat& bottom_blob, Mat& top_blob, const Mat& AT, int nT, const Option& opt)
{
    return conv3x3s1_winograd23_int8(bottom_blob, top_blob, AT, nT, opt);
}

void conv3x3s1_winograd43_transform_kernel_int8_avx2(const Mat& kernel, Mat& AT, int inch, int outch, const Option& opt)
{
    conv3x3s1_winograd43_transform_kernel_int8(kernel, AT, inch, outch, opt);
}

int conv3x3s1_winograd43_int8_avx2(const Mat& bottom_blob, Mat& top_blob, const Mat& AT, int nT, const Option& opt)
{
    return conv3x3s1_winograd43_int8(bottom_blob, top_blob, AT, nT, opt);
}

} // namespace ncnn
