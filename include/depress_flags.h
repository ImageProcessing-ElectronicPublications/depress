/*
BSD 2-Clause License

Copyright (c) 2021-2023, Mikhail Morozov
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

#ifndef DEPRESS_FLAGS_H
#define DEPRESS_FLAGS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdint.h>

enum {
	DEPRESS_PAGE_TYPE_COLOR,
	DEPRESS_PAGE_TYPE_BW
};

enum {
	DEPRESS_PAGE_TYPE_BW_PARAM1_SIMPLE,
	DEPRESS_PAGE_TYPE_BW_PARAM1_ERRDIFF,
	DEPRESS_PAGE_TYPE_BW_PARAM1_ADAPTIVE
};

typedef struct {
	unsigned int x;
	unsigned int y;
	unsigned int width;
	unsigned int height;
} depress_illustration_rect_type;

typedef struct {
	depress_illustration_rect_type *illrects;
	size_t nof_illrects;
	int type;
	int param1;
	int quality; // 0..100
	int dpi;
} depress_flags_type;

#ifdef __cplusplus
}
#endif

#endif
