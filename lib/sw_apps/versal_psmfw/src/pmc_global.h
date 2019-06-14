/******************************************************************************
*
* Copyright (C) 2018 - 2019 Xilinx, Inc.  All rights reserved.
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
* @file psm_global.h
*
* This file contains PSM Global definitions used by PSM Firmware
*
* <pre>
* MODIFICATION HISTORY:
*
* Ver	Who		Date		Changes
* ---- ---- -------- ------------------------------
* 1.00  rp   04/09/2018 Initial release
*
* </pre>
*
* @note
*
******************************************************************************/

#ifndef _PMC_GLOBAL_H_
#define _PMC_GLOBAL_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * PMC_GLOBAL Base Address
 */
#define PMC_GLOBAL_BASEADDR      0XF1110000

/**
 * Register: PMC_GLOBAL_PWR_SUPPLY_STATUS
 */
#define PMC_GLOBAL_PWR_SUPPLY_STATUS    ( ( PMC_GLOBAL_BASEADDR ) + 0X0000010C )

#define PMC_GLOBAL_PWR_SUPPLY_STATUS_VCCINT_RAM_SHIFT   7
#define PMC_GLOBAL_PWR_SUPPLY_STATUS_VCCINT_RAM_WIDTH   1
#define PMC_GLOBAL_PWR_SUPPLY_STATUS_VCCINT_RAM_MASK    0X00000080

#define PMC_GLOBAL_PWR_SUPPLY_STATUS_VCCINT_PL_SHIFT   6
#define PMC_GLOBAL_PWR_SUPPLY_STATUS_VCCINT_PL_WIDTH   1
#define PMC_GLOBAL_PWR_SUPPLY_STATUS_VCCINT_PL_MASK    0X00000040

#define PMC_GLOBAL_PWR_SUPPLY_STATUS_VCCAUX_SHIFT   5
#define PMC_GLOBAL_PWR_SUPPLY_STATUS_VCCAUX_WIDTH   1
#define PMC_GLOBAL_PWR_SUPPLY_STATUS_VCCAUX_MASK    0X00000020

#define PMC_GLOBAL_PWR_SUPPLY_STATUS_VCCINT_SOC_SHIFT   4
#define PMC_GLOBAL_PWR_SUPPLY_STATUS_VCCINT_SOC_WIDTH   1
#define PMC_GLOBAL_PWR_SUPPLY_STATUS_VCCINT_SOC_MASK    0X00000010

#define PMC_GLOBAL_PWR_SUPPLY_STATUS_VCCINT_LPD_SHIFT   3
#define PMC_GLOBAL_PWR_SUPPLY_STATUS_VCCINT_LPD_WIDTH   1
#define PMC_GLOBAL_PWR_SUPPLY_STATUS_VCCINT_LPD_MASK    0X00000008

#define PMC_GLOBAL_PWR_SUPPLY_STATUS_VCCINT_FPD_SHIFT   2
#define PMC_GLOBAL_PWR_SUPPLY_STATUS_VCCINT_FPD_WIDTH   1
#define PMC_GLOBAL_PWR_SUPPLY_STATUS_VCCINT_FPD_MASK    0X00000004

#define PMC_GLOBAL_PWR_SUPPLY_STATUS_VCCINT_PMC_SHIFT   1
#define PMC_GLOBAL_PWR_SUPPLY_STATUS_VCCINT_PMC_WIDTH   1
#define PMC_GLOBAL_PWR_SUPPLY_STATUS_VCCINT_PMC_MASK    0X00000002

#define PMC_GLOBAL_PWR_SUPPLY_STATUS_VCCAUX_PMC_SHIFT   0
#define PMC_GLOBAL_PWR_SUPPLY_STATUS_VCCAUX_PMC_WIDTH   1
#define PMC_GLOBAL_PWR_SUPPLY_STATUS_VCCAUX_PMC_MASK    0X00000001

/**
 * Register: PMC_GLOBAL_DOMAIN_ISO_CNTRL
 */
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL    ( ( PMC_GLOBAL_BASEADDR ) + 0X00010000 )

#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_VCCAUX_VCCRAM_SHIFT   18
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_VCCAUX_VCCRAM_WIDTH   1
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_VCCAUX_VCCRAM_MASK    0X00040000

#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_VCCRAM_SOC_SHIFT   17
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_VCCRAM_SOC_WIDTH   1
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_VCCRAM_SOC_MASK    0X00020000

#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_VCCAUX_SOC_SHIFT   16
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_VCCAUX_SOC_WIDTH   1
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_VCCAUX_SOC_MASK    0X00010000

#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_PL_SOC_SHIFT   15
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_PL_SOC_WIDTH   1
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_PL_SOC_MASK    0X00008000

#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_PMC_SOC_SHIFT   14
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_PMC_SOC_WIDTH   1
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_PMC_SOC_MASK    0X00004000

#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_PMC_SOC_NPI_SHIFT   13
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_PMC_SOC_NPI_WIDTH   1
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_PMC_SOC_NPI_MASK    0X00002000

#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_PMC_PL_SHIFT   12
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_PMC_PL_WIDTH   1
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_PMC_PL_MASK    0X00001000

#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_PMC_PL_TEST_SHIFT   11
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_PMC_PL_TEST_WIDTH   1
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_PMC_PL_TEST_MASK    0X00000800

#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_PMC_PL_CFRAME_SHIFT   10
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_PMC_PL_CFRAME_WIDTH   1
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_PMC_PL_CFRAME_MASK    0X00000400

#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_PMC_LPD_SHIFT   9
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_PMC_LPD_WIDTH   1
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_PMC_LPD_MASK    0X00000200

#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_PMC_LPD_DFX_SHIFT   8
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_PMC_LPD_DFX_WIDTH   1
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_PMC_LPD_DFX_MASK    0X00000100

#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_LPD_SOC_SHIFT   7
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_LPD_SOC_WIDTH   1
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_LPD_SOC_MASK    0X00000080

#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_LPD_PL_SHIFT   6
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_LPD_PL_WIDTH   1
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_LPD_PL_MASK    0X00000040

#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_LPD_PL_TEST_SHIFT   5
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_LPD_PL_TEST_WIDTH   1
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_LPD_PL_TEST_MASK    0X00000020

#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_LPD_CPM_SHIFT   4
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_LPD_CPM_WIDTH   1
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_LPD_CPM_MASK    0X00000010

#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_LPD_CPM_DFX_SHIFT   3
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_LPD_CPM_DFX_WIDTH   1
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_LPD_CPM_DFX_MASK    0X00000008

#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_FPD_SOC_SHIFT   2
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_FPD_SOC_WIDTH   1
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_FPD_SOC_MASK    0X00000004

#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_FPD_PL_SHIFT   1
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_FPD_PL_WIDTH   1
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_FPD_PL_MASK    0X00000002

#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_FPD_PL_TEST_SHIFT   0
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_FPD_PL_TEST_WIDTH   1
#define PMC_GLOBAL_DOMAIN_ISO_CNTRL_FPD_PL_TEST_MASK    0X00000001

#ifdef __cplusplus
}
#endif

#endif /* _PMC_GLOBAL_H_ */
