/*
BSD 2-Clause License

Copyright (c) 2022, Mikhail Morozov
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "../include/interlocked_ptr.h"

#include <Windows.h>

uintptr_t InterlockedAddPtr(uintptr_t volatile *addend, uintptr_t value)
{
#if defined(_M_AMD64) || defined(_M_ARM64) 
	return InterlockedAdd64(addend, value);
#elif defined(_M_IX86) || defined(_M_ARM)
	return InterlockedAdd(addend, value);
#else
#error Define specific interlocked operation here
	return 0;
#endif
}

uintptr_t InterlockedExchangePtr(uintptr_t volatile *target, uintptr_t value)
{
#if defined(_M_AMD64) || defined(_M_ARM64) 
	return InterlockedExchange64(target, value);
#elif defined(_M_IX86) || defined(_M_ARM)
	return InterlockedExchange(target, value);
#else
#error Define specific interlocked operation here
	return 0;
#endif
}