/*
* Copyright 2009-2010  NVIDIA Corporation.  All rights reserved.
*
* NOTICE TO USER:   
*
* This source code is subject to NVIDIA ownership rights under U.S. and
* international Copyright laws.
*
* This software and the information contained herein is PROPRIETARY and
* CONFIDENTIAL to NVIDIA and is being provided under the terms and conditions
* of a form of NVIDIA software license agreement.
*
* NVIDIA MAKES NO REPRESENTATION ABOUT THE SUITABILITY OF THIS SOURCE
* CODE FOR ANY PURPOSE.  IT IS PROVIDED "AS IS" WITHOUT EXPRESS OR
* IMPLIED WARRANTY OF ANY KIND.  NVIDIA DISCLAIMS ALL WARRANTIES WITH
* REGARD TO THIS SOURCE CODE, INCLUDING ALL IMPLIED WARRANTIES OF
* MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE.
* IN NO EVENT SHALL NVIDIA BE LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL,
* OR CONSEQUENTIAL DAMAGES, OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS
* OF USE, DATA OR PROFITS,  WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE
* OR OTHER TORTIOUS ACTION,  ARISING OUT OF OR IN CONNECTION WITH THE USE
* OR PERFORMANCE OF THIS SOURCE CODE.  
*
* U.S. Government End Users.   This source code is a "commercial item" as
* that term is defined at  48 C.F.R. 2.101 (OCT 1995), consisting  of
* "commercial computer  software"  and "commercial computer software
* documentation" as such terms are  used in 48 C.F.R. 12.212 (SEPT 1995)
* and is provided to the U.S. Government only as a commercial end item.
* Consistent with 48 C.F.R.12.212 and 48 C.F.R. 227.7202-1 through
* 227.7202-4 (JUNE 1995), all U.S. Government End Users acquire the
* source code with only those rights set forth herein.
*
* Any use of this source code in individual and commercial software must
* include, in the user documentation and internal comments to the code,
* the above Disclaimer and U.S. Government End Users Notice.
*/

#ifndef _NVTOOLSEXT_OPENCL_H_
#define _NVTOOLSEXT_OPENCL_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <CL/cl.h>

#include "nvToolsExt.h"

/** ===========================================================================
 * \section OpenCL Resource Naming
 * The tools extension API provides methods for annotating objects in order to
 * enhance the usability of the Nvidia tools.
 * ========================================================================= */

/** ---------------------------------------------------------------------------
 * \brief Annotates an OpenCL device.
 * ------------------------------------------------------------------------- */
NVTX_DECLSPEC void NVTX_API nvtxNameClDeviceA(cl_device_id device, const char* name);
NVTX_DECLSPEC void NVTX_API nvtxNameClDeviceW(cl_device_id device, const wchar_t* name);

/** ---------------------------------------------------------------------------
 * \brief Annotates an OpenCL context.
 * ------------------------------------------------------------------------- */
NVTX_DECLSPEC void NVTX_API nvtxNameClContextA(cl_context context, const char* name);
NVTX_DECLSPEC void NVTX_API nvtxNameClContextW(cl_context context, const wchar_t* name);

/** ---------------------------------------------------------------------------
 * \brief Annotates an OpenCL command queue.
 * ------------------------------------------------------------------------- */
NVTX_DECLSPEC void NVTX_API nvtxNameClCommandQueueA(cl_command_queue command_queue, const char* name);
NVTX_DECLSPEC void NVTX_API nvtxNameClCommandQueueW(cl_command_queue command_queue, const wchar_t* name);

/** ---------------------------------------------------------------------------
 * \brief Annotates an OpenCL memory object.
 * ------------------------------------------------------------------------- */
NVTX_DECLSPEC void NVTX_API nvtxNameClMemObjectA(cl_mem memobj, const char* name);
NVTX_DECLSPEC void NVTX_API nvtxNameClMemObjectW(cl_mem memobj, const wchar_t* name);

/** ---------------------------------------------------------------------------
 * \brief Annotates an OpenCL sampler.
 * ------------------------------------------------------------------------- */
NVTX_DECLSPEC void NVTX_API nvtxNameClSamplerA(cl_sampler sampler, const char* name);
NVTX_DECLSPEC void NVTX_API nvtxNameClSamplerW(cl_sampler sampler, const wchar_t* name);

/** ---------------------------------------------------------------------------
 * \brief Annotates an OpenCL program.
 * ------------------------------------------------------------------------- */
NVTX_DECLSPEC void NVTX_API nvtxNameClProgramA(cl_program program, const char* name);
NVTX_DECLSPEC void NVTX_API nvtxNameClProgramW(cl_program program, const wchar_t* name);

/** ---------------------------------------------------------------------------
 * \brief Annotates an OpenCL event.
 * ------------------------------------------------------------------------- */
NVTX_DECLSPEC void NVTX_API nvtxNameClEventA(cl_event evnt, const char* name);
NVTX_DECLSPEC void NVTX_API nvtxNameClEventW(cl_event evnt, const wchar_t* name);


/** ===========================================================================
 * \section Unicode Helpers
 * ========================================================================= */
 
#ifdef UNICODE
  #define nvtxNameClDevice        nvtxNameClDeviceW
  #define nvtxNameClContext       nvtxNameClContextW
  #define nvtxNameClCommandQueue  nvtxNameClCommandQueueW
  #define nvtxNameClMemObject     nvtxNameClMemObjectW
  #define nvtxNameClSampler       nvtxNameClSamplerW
  #define nvtxNameClProgram       nvtxNameClProgramW
  #define nvtxNameClEvent         nvtxNameClEventW
#else
  #define nvtxNameClDevice        nvtxNameClDeviceA
  #define nvtxNameClContext       nvtxNameClContextA
  #define nvtxNameClCommandQueue  nvtxNameClCommandQueueA
  #define nvtxNameClMemObject     nvtxNameClMemObjectA
  #define nvtxNameClSampler       nvtxNameClSamplerA
  #define nvtxNameClProgram       nvtxNameClProgramA
  #define nvtxNameClEvent         nvtxNameClEventA
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _NVTOOLSEXT_OPENCL_H_ */