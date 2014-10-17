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

#ifndef _NVTOOLSEXT_H_
#define _NVTOOLSEXT_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifdef _WIN32
	#ifdef NVTX_EXPORTS
		#define NVTX_DECLSPEC
	#else
		#define NVTX_DECLSPEC __declspec(dllimport)
	#endif /* NVTX_EXPORTS */
	#define NVTX_API __stdcall
#else	/* Linux and Mac */
	#define NVTX_DECLSPEC
	#define NVTX_API
#endif	/* Platform */

/*
 * #define NVTX_STDINT_TYPES_ALREADY_DEFINED if you are using your own header file.
 */
#ifndef NVTX_STDINT_TYPES_ALREADY_DEFINED
#include <stdint.h>
#endif

#define NVTX_VERSION 1

#define NVTX_EVENT_ATTRIB_STRUCT_SIZE	( (uint16_t)( sizeof(nvtxEventAttributes_v1) ) )

/** ===========================================================================
 * \section Tools Extension Event Attributes
 * ========================================================================= */

typedef uint64_t nvtxRangeId_t;

typedef enum nvtxColorType_t
{
	NVTX_COLOR_UNKNOWN	= 0,
	NVTX_COLOR_ARGB		= 1
} nvtxColorType_t;

typedef enum nvtxPayloadType_t
{
	NVTX_PAYLOAD_UNKNOWN				= 0,
	NVTX_PAYLOAD_TYPE_UNSIGNED_INT64	= 1,
	NVTX_PAYLOAD_TYPE_INT64				= 2,
	NVTX_PAYLOAD_TYPE_DOUBLE			= 3
} nvtxPayloadType_t;

typedef enum nvtxMessageType_t
{
	NVTX_MESSAGE_UNKNOWN		= 0,
	NVTX_MESSAGE_TYPE_ASCII		= 1,
	NVTX_MESSAGE_TYPE_UNICODE	= 2
} nvtxMessageType_t;

/**
 * \brief Event attribute structure.
 * \remarks This structure is used to store optional attributes that can 
 * be used to describe a tools extension event. These attributes may be reflected
 * in its visual representation in an analysis session.
 */
typedef struct nvtxEventAttributes_v1
{
	/**
	* \brief Tools extension API version.
	* \remarks Needs to be set to NVTX_VERSION to indicate the version of
	* nvtx APIs supported in this header file. This can optionally be
	* overriden to another version of the tools extension library.
	*/
	uint16_t version;
	/**
	* \brief Tools extension event attribute structure.
	* \remarks Need to be set to NVTX_VERSION to indicate the version of
	* nvtx APIs supported in this header file. This can optionally be
	* overriden to another version of the tools extension library.
	*/
	uint16_t size;

	/**
	 * \brief Event category.
	 */
	uint32_t category;

	/**
	 * \brief Event color.
	 */
	int32_t colorType;				/* nvtxColorType_t */
	uint32_t color;

	/**
	 * \brief Event payload.
	 */
	int32_t payloadType;			/* nvtxPayloadType_t */
	union payload_t
	{
		uint64_t ullValue;
		int64_t llValue;
		double dValue;
	} payload;

	/**
	 * \brief Event message.
	 */
	int32_t messageType;			/* nvtxMessageType_t */
	union message_t
	{
		const char* ascii;
		const wchar_t* unicode;
	} message;

} nvtxEventAttributes_v1;

typedef struct nvtxEventAttributes_v1 nvtxEventAttributes_t;


/** ===========================================================================
 * \section Markers/Ranges Events
 * The tools extension API provides methods for annotating instantaneous
 * events, ranges of code, or ranges of time in order to enhance the usability
 * of the Nvidia tools.
 * ========================================================================= */

/** ---------------------------------------------------------------------------
 * \brief Marks an instantaneous event in the application.
 * ------------------------------------------------------------------------- */
NVTX_DECLSPEC void NVTX_API nvtxMarkEx(const nvtxEventAttributes_t* eventAttrib);
NVTX_DECLSPEC void NVTX_API nvtxMarkA(const char* message);
NVTX_DECLSPEC void NVTX_API nvtxMarkW(const wchar_t* message);

/** ---------------------------------------------------------------------------
 * \brief Marks the start of a range.
 * \return nvtxRangeId_t unique ID used to correlated Start and End events
 *
 * \remarks Each nvtxRangeStart call should be followed by a nvtxRangeEnd
 * call.  The start and end events are matched by passing the return value of
 * the nvtxRangeStart call into the nvtxRangeEnd call.  The function calls
 * for start and end can be made on different threads.
 * \remarks Ranges defined by Start/End can overlap.
 * ------------------------------------------------------------------------- */
NVTX_DECLSPEC nvtxRangeId_t NVTX_API nvtxRangeStartEx(const nvtxEventAttributes_t* eventAttrib);
NVTX_DECLSPEC nvtxRangeId_t NVTX_API nvtxRangeStartA(const char* message);
NVTX_DECLSPEC nvtxRangeId_t NVTX_API nvtxRangeStartW(const wchar_t* message);

/** ---------------------------------------------------------------------------
 * \brief Marks the end of a range.
 * \param[in] id nvtxRangeId returned from a nvtxRangeStart call
 *
 * \remarks Ranges defined by Start/End can overlap.
 * ------------------------------------------------------------------------- */
NVTX_DECLSPEC void NVTX_API nvtxRangeEnd(nvtxRangeId_t id);

/** ---------------------------------------------------------------------------
 * \brief Marks the start of a nested range
 * \return the 0 based level of range being started.  If an error occurs a
 * negative value is returned.
 *
 * \remarks nvtxRangePush and nvtxRangePop are used to define nested ranges.
 * A range stack is maintained per thread.
 * ------------------------------------------------------------------------- */
NVTX_DECLSPEC int NVTX_API nvtxRangePushEx(const nvtxEventAttributes_t* eventAttrib);
NVTX_DECLSPEC int NVTX_API nvtxRangePushA(const char* message);
NVTX_DECLSPEC int NVTX_API nvtxRangePushW(const wchar_t* message);

/** ---------------------------------------------------------------------------
 * \brief Marks the end of a nested range
 * \return the level of the range being ended.  If an error occurs a negative
 * value is returned on the current thread.
 *
 * \remarks nvtxRangePush and nvtxRangePop are used to defined nested ranges.
 * A range stack is maintained on each thread.
 * ------------------------------------------------------------------------- */
NVTX_DECLSPEC int NVTX_API nvtxRangePop();



/** ===========================================================================
 * \section Resource Naming
 * The tools extension API provides methods for annotating objects in order to
 * enhance the usability of the Nvidia tools.
 * ========================================================================= */

/** ---------------------------------------------------------------------------
 * \brief Annotates a NVTX category.
 * \remarks The category names are tracked per process.
 * ------------------------------------------------------------------------- */
NVTX_DECLSPEC void NVTX_API nvtxNameCategoryA(uint32_t category, const char* message);
NVTX_DECLSPEC void NVTX_API nvtxNameCategoryW(uint32_t category, const wchar_t* message);

/** ---------------------------------------------------------------------------
 * \brief Annotates an OS thread.
 * \remarks Naming a thread that is not a child of the calling process is
 * not supported.
 * ------------------------------------------------------------------------- */
NVTX_DECLSPEC void NVTX_API nvtxNameOsThreadA(uint32_t threadId, const char* message);
NVTX_DECLSPEC void NVTX_API nvtxNameOsThreadW(uint32_t threadId, const wchar_t* message);

/** ===========================================================================
 * \section Unicode Helpers
 * ========================================================================= */

#ifdef UNICODE
	#define nvtxMark			nvtxMarkW
	#define nvtxRangeStart		nvtxRangeStartW
	#define nvtxRangePush		nvtxRangePushW
	#define nvtxNameCategory	nvtxNameCategoryW
	#define nvtxNameOsThread	nvtxNameOsThreadW
#else
	#define nvtxMark			nvtxMarkA
	#define nvtxRangeStart		nvtxRangeStartA
	#define nvtxRangePush		nvtxRangePushA
	#define nvtxNameCategory	nvtxNameCategoryA
	#define nvtxNameOsThread	nvtxNameOsThreadA
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _NVTOOLSEXT_H_ */