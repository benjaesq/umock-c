
// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include <stdio.h>
#include <stdarg.h>

#include "umock_log.h"
#include "umock_c_internal.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wformat-nonliteral"
#endif
void UMOCK_LOG(const char* format, ...)
{
    va_list params;
    va_start(params, format);
    (void)vprintf(format, params); 
    va_end(params);
    printf("\r\n");
    umock_c_indicate_error(UMOCK_C_ERROR);
}
