/******************************************************************************
*
* Copyright (C) 2010 - 2019 Xilinx, Inc.  All rights reserved.
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
* @file xemacps_sinit.c
* @addtogroup emacps_v3_10
* @{
*
* This file contains lookup method by device ID when success, it returns
* pointer to config table to be used to initialize the device.
*
* <pre>
* MODIFICATION HISTORY:
*
* Ver   Who  Date     Changes
* ----- ---- -------- -------------------------------------------------------
* 1.00a wsy  01/10/10 New
* 3.00  kvn  02/13/15 Modified code for MISRA-C:2012 compliance.
* </pre>
*
******************************************************************************/

/***************************** Include Files *********************************/

#include "xemacps.h"
#include "xparameters.h"

/************************** Constant Definitions *****************************/


/**************************** Type Definitions *******************************/

/*************************** Variable Definitions *****************************/
extern XEmacPs_Config XEmacPs_ConfigTable[XPAR_XEMACPS_NUM_INSTANCES];

/***************** Macros (Inline Functions) Definitions *********************/


/************************** Function Prototypes ******************************/

/*****************************************************************************/
/**
* Lookup the device configuration based on the unique device ID.  The table
* contains the configuration info for each device in the system.
*
* @param DeviceId is the unique device ID of the device being looked up.
*
* @return
* A pointer to the configuration table entry corresponding to the given
* device ID, or NULL if no match is found.
*
******************************************************************************/
XEmacPs_Config *XEmacPs_LookupConfig(u16 DeviceId)
{
	XEmacPs_Config *CfgPtr = NULL;
	u32 i;

	for (i = 0U; i < (u32)XPAR_XEMACPS_NUM_INSTANCES; i++) {
		if (XEmacPs_ConfigTable[i].DeviceId == DeviceId) {
			CfgPtr = &XEmacPs_ConfigTable[i];
			break;
		}
	}

	return (XEmacPs_Config *)(CfgPtr);
}
/** @} */
