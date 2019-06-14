/******************************************************************************
*
* Copyright (C) 2012 - 2014 Xilinx, Inc.  All rights reserved.
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal 
* in the Software without restriction, including without limitation the rights 
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  
* copies of the Software, and to permit persons to whom the Software is 
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in 
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMANGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*
* 
*
******************************************************************************/
/*****************************************************************************/
/**
*
* @file fsbl_debug.h
*
* This file contains the debug verbose information for FSBL print functionality
*
* <pre>
* MODIFICATION HISTORY:
*
* Ver	Who	Date		Changes
* ----- ---- -------- -------------------------------------------------------
* 3.00a mb	01/09/12 Initial release
*
* </pre>
*
* @note
*
******************************************************************************/

#ifndef _FSBL_DEBUG_H
#define _FSBL_DEBUG_H

#ifdef __cplusplus
extern "C" {
#endif


#define DEBUG_GENERAL	0x00000001    /* general debug  messages */
#define DEBUG_INFO	0x00000002    /* More debug information */

#if defined (FSBL_DEBUG_INFO)
#define fsbl_dbg_current_types ((DEBUG_INFO) | (DEBUG_GENERAL))
#elif defined (FSBL_DEBUG)
#define fsbl_dbg_current_types (DEBUG_GENERAL)
#else
#define fsbl_dbg_current_types 0
#endif

#ifdef STDOUT_BASEADDRESS
#define fsbl_printf(type,...) \
		if (((type) & fsbl_dbg_current_types))  {xil_printf (__VA_ARGS__); }
#else
#define fsbl_printf(type, ...)
#endif

#ifdef __cplusplus
}
#endif

#endif /* _FSBL_DEBUG_H */
