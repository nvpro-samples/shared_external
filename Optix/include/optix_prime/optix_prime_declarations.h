
/*
 * Copyright (c) 2013 NVIDIA Corporation.  All rights reserved.
 *
 * NVIDIA Corporation and its licensors retain all intellectual property and proprietary
 * rights in and to this software, related documentation and any modifications thereto.
 * Any use, reproduction, disclosure or distribution of this software and related
 * documentation without an express license agreement from NVIDIA Corporation is strictly
 * prohibited.
 *
 * TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THIS SOFTWARE IS PROVIDED *AS IS*
 * AND NVIDIA AND ITS SUPPLIERS DISCLAIM ALL WARRANTIES, EITHER EXPRESS OR IMPLIED,
 * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE.  IN NO EVENT SHALL NVIDIA OR ITS SUPPLIERS BE LIABLE FOR ANY
 * SPECIAL, INCIDENTAL, INDIRECT, OR CONSEQUENTIAL DAMAGES WHATSOEVER (INCLUDING, WITHOUT
 * LIMITATION, DAMAGES FOR LOSS OF BUSINESS PROFITS, BUSINESS INTERRUPTION, LOSS OF
 * BUSINESS INFORMATION, OR ANY OTHER PECUNIARY LOSS) ARISING OUT OF THE USE OF OR
 * INABILITY TO USE THIS SOFTWARE, EVEN IF NVIDIA HAS BEEN ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGES
 */

/**
 * @file   optix_prime_declarations.h
 * @author NVIDIA Corporation
 * @brief  OptiX Prime public API declarations
 *
 * OptiX Prime public API declarations
 */

#ifndef __optix_optix_prime_declarations_h__
#define __optix_optix_prime_declarations_h__

/*! Return value for OptiX Prime APIs */
enum RTPresult
{
  RTP_SUCCESS                         =   0,  /*!< Success */
  RTP_ERROR_INVALID_VALUE             =   1,  /*!< An invalid value was provided */
  RTP_ERROR_OUT_OF_MEMORY             =   2,  /*!< Out of memory */
  RTP_ERROR_INVALID_HANDLE            =   3,  /*!< An invalid handle was supplied */
  RTP_ERROR_NOT_SUPPORTED             =   4,  /*!< An unsupported function was requested */
  RTP_ERROR_OBJECT_CREATION_FAILED    =   5,  /*!< Object creation failed */
  RTP_ERROR_MEMORY_ALLOCATION_FAILED  =   6,  /*!< Memory allocation failed */
  RTP_ERROR_INVALID_CONTEXT           =   7,  /*!< An invalid context was provided */
  RTP_ERROR_VALIDATION_ERROR          =   8,  /*!< A validation error occurred */
  RTP_ERROR_INVALID_OPERATION         =   9,  /*!< An invalid operation was performed */
  RTP_ERROR_UNKNOWN                   = 999   /*!< Unknown error */
};

/*! Context types */
enum RTPcontexttype 
{
  RTP_CONTEXT_TYPE_CPU  = 0x100,  /*!< CPU context */
  RTP_CONTEXT_TYPE_CUDA = 0x101,  /*!< CUDA context */
};

/*! Buffer types */
enum RTPbuffertype 
{
  RTP_BUFFER_TYPE_HOST        = 0x200,  /*!< Buffer in host memory */
  RTP_BUFFER_TYPE_CUDA_LINEAR = 0x201   /*!< Linear buffer in device memory on a cuda device */
};

/*! Buffer formats */
enum RTPbufferformat
{
  /* INDICES */
  RTP_BUFFER_FORMAT_INDICES_INT3                   = 0x400, /*!< Index buffer with 3 integer vertex indices per triangle */

  /* VERTICES */
  RTP_BUFFER_FORMAT_VERTEX_FLOAT3                  = 0x420, /*!< Vertex buffer with 3 floats per vertex position */
  RTP_BUFFER_FORMAT_VERTEX_FLOAT4                  = 0x421, /*!< Vertex buffer with 4 floats per vertex position */

  /* RAYS */
  RTP_BUFFER_FORMAT_RAY_ORIGIN_DIRECTION           = 0x440, /*!< float3:origin float3:direction */
  RTP_BUFFER_FORMAT_RAY_ORIGIN_TMIN_DIRECTION_TMAX = 0x441, /*!< float3:origin, float:tmin, float3:direction, float:tmax */

  /* HITS */
  RTP_BUFFER_FORMAT_HIT_BITMASK                    = 0x460, /*!< one bit per ray 0=miss, 1=hit */
  RTP_BUFFER_FORMAT_HIT_T                          = 0x461, /*!< float:ray distance (t < 0 for miss) */
  RTP_BUFFER_FORMAT_HIT_T_TRIID                    = 0x462, /*!< float:ray distance (t < 0 for miss), int:triangle id */
  RTP_BUFFER_FORMAT_HIT_T_TRIID_U_V                = 0x463  /*!< float:ray distance (t < 0 for miss), int:triangle id, float2:barycentric coordinates u,v (w=1-u-v) */
};

/*! Query types */
enum RTPquerytype 
{
  RTP_QUERY_TYPE_ANY     = 0x1000,  /*!< Return any hit along a ray */
  RTP_QUERY_TYPE_CLOSEST = 0x1001   /*!< Return only the closest hit along a ray */
};

/*! Model hints */
enum RTPmodelhint
{
  RTP_MODEL_HINT_NONE    = 0x0000,  /*!< No hints.  Use default settings. */
  RTP_MODEL_HINT_ASYNC   = 0x2001   /*!< Asynchronous model updating */
};

/*! Query hints */
enum RTPqueryhint 
{
  RTP_QUERY_HINT_NONE    = 0x0000,  /*!< No hints.  Use default settings. */
  RTP_QUERY_HINT_ASYNC   = 0x4001   /*!< Asynchronous query execution */
};

/* Builder parameters */
typedef enum
{
  RTP_BUILDER_PARAM_CHUNK_SIZE            = 0x800, /*!< Number of bytes used for a chunk of the acceleration structure build */
  RTP_BUILDER_PARAM_USE_CALLER_TRIANGLES  = 0x801  /*!< A hint to specify which data should be used for the intersection test */
} RTPbuilderparam;

#endif /* #ifndef __optix_optix_prime_declarations_h__ */
