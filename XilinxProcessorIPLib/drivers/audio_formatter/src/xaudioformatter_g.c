/*******************************************************************
* Copyright (C) 2018 Xilinx, Inc. All rights reserved.
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

*******************************************************************************/

#include "xparameters.h"
#include "xaudioformatter.h"

/*
* The configuration table for devices
*/

XAudioFormatter_Config XAudioFormatter_ConfigTable
	[XPAR_XAUDIOFORMATTER_NUM_INSTANCES] = {
	{
		XPAR_AUDIO_SS_0_AUDIO_FORMATTER_0_DEVICE_ID,
		XPAR_AUDIO_SS_0_AUDIO_FORMATTER_0_BASEADDR,
		XPAR_AUDIO_FORMATTER_0_INCLUDE_MM2S,
		XPAR_AUDIO_FORMATTER_0_INCLUDE_S2MM,
		XPAR_AUDIO_FORMATTER_0_MAX_NUM_CHANNELS_MM2S,
		XPAR_AUDIO_FORMATTER_0_MAX_NUM_CHANNELS_S2MM,
		XPAR_AUDIO_FORMATTER_0_MM2S_ADDR_WIDTH,
		XPAR_AUDIO_FORMATTER_0_MM2S_DATAFORMAT,
		XPAR_AUDIO_FORMATTER_0_PACKING_MODE_MM2S,
		XPAR_AUDIO_FORMATTER_0_PACKING_MODE_S2MM,
		XPAR_AUDIO_FORMATTER_0_S2MM_ADDR_WIDTH,
		XPAR_AUDIO_FORMATTER_0_S2MM_DATAFORMAT
	}
};
