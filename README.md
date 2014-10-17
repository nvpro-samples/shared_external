These tools do not belong to the samples.
They have been put together in this location to make sample building easiers. But one could avoid using them and specify instead
they location either from environment variables or directly within cmake settings:

## AntTweakBar
rebuilding it will generate lib and dll in shared_external\AntTweakBar\lib. cmake will look for them here
a compiled version is already available locally in lib
- http://anttweakbar.sourceforge.net/doc/tools:anttweakbar:download
- if located somewhere else, specify its base directory with ANTTWEAKBAR_LOCATION

## SvcMFCUI
- https://github.com/tlorach/SvcMFCUI
- if located somewhere else, specify its base directory with SVCMFCUI_LOCATION

## zlib
this folder contains only the compiled version of zlib. Originally used https://github.com/madler/zlib
this is the result of INSTALL build of this project:
  - bin : the dll/so
  - include : zlib includes
  - lib : library to link with (static or dynamic)

## NSight
NVIDIA NSight package: includes, libraries and dlls
- TODO: if located somewhere else, specify its base directory with NSIGHT_LOCATION

````
    Copyright (c) 2013, NVIDIA CORPORATION. All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions
    are met:
     * Redistributions of source code must retain the above copyright
       notice, this list of conditions and the following disclaimer.
     * Neither the name of NVIDIA CORPORATION nor the names of its
       contributors may be used to endorse or promote products derived
       from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ``AS IS'' AND ANY
    EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
    PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
    CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
    EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
    PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
    PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
    OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
    OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

````
