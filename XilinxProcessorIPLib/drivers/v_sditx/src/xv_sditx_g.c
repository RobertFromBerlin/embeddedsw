/*******************************************************************
*
* Copyright (C) 2010-2017 Xilinx, Inc. All rights reserved.
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
#include "xv_sditx.h"

/*
* The configuration table for devices
*/

XV_SdiTx_Config XV_SdiTx_ConfigTable[XPAR_XV_SDITX_NUM_INSTANCES] =
{
	{
		XPAR_V_SMPTE_UHDSDI_TX_SS_V_SMPTE_UHDSDI_TX_DEVICE_ID,
		XPAR_V_SMPTE_UHDSDI_TX_SS_V_SMPTE_UHDSDI_TX_AXI_CTRL_BASEADDR,
		XPAR_V_SMPTE_UHDSDI_TX_SS_V_SMPTE_UHDSDI_TX_INCLUDE_EDH,
		XPAR_V_SMPTE_UHDSDI_TX_SS_V_SMPTE_UHDSDI_TX_LINE_RATE,
		XPAR_V_SMPTE_UHDSDI_TX_SS_V_SMPTE_UHDSDI_TX_TX_INSERT_C_STR_ST352
	}
};
