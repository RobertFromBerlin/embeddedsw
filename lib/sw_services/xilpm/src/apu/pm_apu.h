/******************************************************************************
*
* Copyright (C) 2015 Xilinx, Inc.  All rights reserved.
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

#ifndef PM_APU_H
#define PM_APU_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * APU Base Address
 */
#define APU_BASEADDR      0XFD5C0000U

/**
 * Register: APU_ERR_CTRL
 */
#define APU_ERR_CTRL    ( ( APU_BASEADDR ) + 0X00000000U )

#define APU_ERR_CTRL_PSLVERR_SHIFT   0U
#define APU_ERR_CTRL_PSLVERR_WIDTH   1U
#define APU_ERR_CTRL_PSLVERR_MASK    0X00000001U

/**
 * Register: APU_ISR
 */
#define APU_ISR    ( ( APU_BASEADDR ) + 0X00000010U )

#define APU_ISR_INV_APB_SHIFT   0U
#define APU_ISR_INV_APB_WIDTH   1U
#define APU_ISR_INV_APB_MASK    0X00000001U

/**
 * Register: APU_IMR
 */
#define APU_IMR    ( ( APU_BASEADDR ) + 0X00000014U )

#define APU_IMR_INV_APB_SHIFT   0U
#define APU_IMR_INV_APB_WIDTH   1U
#define APU_IMR_INV_APB_MASK    0X00000001U

/**
 * Register: APU_IEN
 */
#define APU_IEN    ( ( APU_BASEADDR ) + 0X00000018U )

#define APU_IEN_INV_APB_SHIFT   0U
#define APU_IEN_INV_APB_WIDTH   1U
#define APU_IEN_INV_APB_MASK    0X00000001U

/**
 * Register: APU_IDS
 */
#define APU_IDS    ( ( APU_BASEADDR ) + 0X0000001CU )

#define APU_IDS_INV_APB_SHIFT   0U
#define APU_IDS_INV_APB_WIDTH   1U
#define APU_IDS_INV_APB_MASK    0X00000001U

/**
 * Register: APU_CONFIG_0
 */
#define APU_CONFIG_0    ( ( APU_BASEADDR ) + 0X00000020U )

#define APU_CONFIG_0_CFGTE_SHIFT   24U
#define APU_CONFIG_0_CFGTE_WIDTH   4U
#define APU_CONFIG_0_CFGTE_MASK    0X0F000000U

#define APU_CONFIG_0_CFGEND_SHIFT   16U
#define APU_CONFIG_0_CFGEND_WIDTH   4U
#define APU_CONFIG_0_CFGEND_MASK    0X000F0000U

#define APU_CONFIG_0_VINITHI_SHIFT   8U
#define APU_CONFIG_0_VINITHI_WIDTH   4U
#define APU_CONFIG_0_VINITHI_MASK    0X00000F00U

#define APU_CONFIG_0_AA64NAA32_SHIFT   0U
#define APU_CONFIG_0_AA64NAA32_WIDTH   4U
#define APU_CONFIG_0_AA64NAA32_MASK    0X0000000FU

/**
 * Register: APU_CONFIG_1
 */
#define APU_CONFIG_1    ( ( APU_BASEADDR ) + 0X00000024U )

#define APU_CONFIG_1_L2RSTDISABLE_SHIFT   29U
#define APU_CONFIG_1_L2RSTDISABLE_WIDTH   1U
#define APU_CONFIG_1_L2RSTDISABLE_MASK    0X20000000U

#define APU_CONFIG_1_L1RSTDISABLE_SHIFT   28U
#define APU_CONFIG_1_L1RSTDISABLE_WIDTH   1U
#define APU_CONFIG_1_L1RSTDISABLE_MASK    0X10000000U

#define APU_CONFIG_1_CP15DISABLE_SHIFT   0U
#define APU_CONFIG_1_CP15DISABLE_WIDTH   4U
#define APU_CONFIG_1_CP15DISABLE_MASK    0X0000000FU

/**
 * Register: APU_RVBARADDR0L
 */
#define APU_RVBARADDR0L    ( ( APU_BASEADDR ) + 0X00000040U )

#define APU_RVBARADDR0L_ADDR_SHIFT   2U
#define APU_RVBARADDR0L_ADDR_WIDTH   30U
#define APU_RVBARADDR0L_ADDR_MASK    0XFFFFFFFCU

/**
 * Register: APU_RVBARADDR0H
 */
#define APU_RVBARADDR0H    ( ( APU_BASEADDR ) + 0X00000044U )

#define APU_RVBARADDR0H_ADDR_SHIFT   0U
#define APU_RVBARADDR0H_ADDR_WIDTH   8U
#define APU_RVBARADDR0H_ADDR_MASK    0X000000FFU

/**
 * Register: APU_RVBARADDR1L
 */
#define APU_RVBARADDR1L    ( ( APU_BASEADDR ) + 0X00000048U )

#define APU_RVBARADDR1L_ADDR_SHIFT   2U
#define APU_RVBARADDR1L_ADDR_WIDTH   30U
#define APU_RVBARADDR1L_ADDR_MASK    0XFFFFFFFCU

/**
 * Register: APU_RVBARADDR1H
 */
#define APU_RVBARADDR1H    ( ( APU_BASEADDR ) + 0X0000004CU )

#define APU_RVBARADDR1H_ADDR_SHIFT   0U
#define APU_RVBARADDR1H_ADDR_WIDTH   8U
#define APU_RVBARADDR1H_ADDR_MASK    0X000000FFU

/**
 * Register: APU_RVBARADDR2L
 */
#define APU_RVBARADDR2L    ( ( APU_BASEADDR ) + 0X00000050U )

#define APU_RVBARADDR2L_ADDR_SHIFT   2U
#define APU_RVBARADDR2L_ADDR_WIDTH   30U
#define APU_RVBARADDR2L_ADDR_MASK    0XFFFFFFFCU

/**
 * Register: APU_RVBARADDR2H
 */
#define APU_RVBARADDR2H    ( ( APU_BASEADDR ) + 0X00000054U )

#define APU_RVBARADDR2H_ADDR_SHIFT   0U
#define APU_RVBARADDR2H_ADDR_WIDTH   8U
#define APU_RVBARADDR2H_ADDR_MASK    0X000000FFU

/**
 * Register: APU_RVBARADDR3L
 */
#define APU_RVBARADDR3L    ( ( APU_BASEADDR ) + 0X00000058U )

#define APU_RVBARADDR3L_ADDR_SHIFT   2U
#define APU_RVBARADDR3L_ADDR_WIDTH   30U
#define APU_RVBARADDR3L_ADDR_MASK    0XFFFFFFFCU

/**
 * Register: APU_RVBARADDR3H
 */
#define APU_RVBARADDR3H    ( ( APU_BASEADDR ) + 0X0000005CU )

#define APU_RVBARADDR3H_ADDR_SHIFT   0U
#define APU_RVBARADDR3H_ADDR_WIDTH   8U
#define APU_RVBARADDR3H_ADDR_MASK    0X000000FFU

/**
 * Register: APU_ACE_CTRL
 */
#define APU_ACE_CTRL    ( ( APU_BASEADDR ) + 0X00000060U )

#define APU_ACE_CTRL_AWQOS_SHIFT   16U
#define APU_ACE_CTRL_AWQOS_WIDTH   4U
#define APU_ACE_CTRL_AWQOS_MASK    0X000F0000U

#define APU_ACE_CTRL_ARQOS_SHIFT   0U
#define APU_ACE_CTRL_ARQOS_WIDTH   4U
#define APU_ACE_CTRL_ARQOS_MASK    0X0000000FU

/**
 * Register: APU_SNOOP_CTRL
 */
#define APU_SNOOP_CTRL    ( ( APU_BASEADDR ) + 0X00000080U )

#define APU_SNOOP_CTRL_ACE_INACT_SHIFT   4U
#define APU_SNOOP_CTRL_ACE_INACT_WIDTH   1U
#define APU_SNOOP_CTRL_ACE_INACT_MASK    0X00000010U

#define APU_SNOOP_CTRL_ACP_INACT_SHIFT   0U
#define APU_SNOOP_CTRL_ACP_INACT_WIDTH   1U
#define APU_SNOOP_CTRL_ACP_INACT_MASK    0X00000001U

/**
 * Register: APU_PWRCTL
 */
#define APU_PWRCTL    ( ( APU_BASEADDR ) + 0X00000090U )

#define APU_PWRCTL_CLREXMONREQ_SHIFT   17U
#define APU_PWRCTL_CLREXMONREQ_WIDTH   1U
#define APU_PWRCTL_CLREXMONREQ_MASK    0X00020000U

#define APU_PWRCTL_L2FLUSHREQ_SHIFT   16U
#define APU_PWRCTL_L2FLUSHREQ_WIDTH   1U
#define APU_PWRCTL_L2FLUSHREQ_MASK    0X00010000U

#define APU_PWRCTL_CPUPWRDWNREQ_SHIFT   0U
#define APU_PWRCTL_CPUPWRDWNREQ_WIDTH   4U
#define APU_PWRCTL_CPUPWRDWNREQ_MASK    0X0000000FU

/**
 * Register: APU_PWRSTAT
 */
#define APU_PWRSTAT    ( ( APU_BASEADDR ) + 0X00000094U )

#define APU_PWRSTAT_CLREXMONACK_SHIFT   17U
#define APU_PWRSTAT_CLREXMONACK_WIDTH   1U
#define APU_PWRSTAT_CLREXMONACK_MASK    0X00020000U

#define APU_PWRSTAT_L2FLUSHDONE_SHIFT   16U
#define APU_PWRSTAT_L2FLUSHDONE_WIDTH   1U
#define APU_PWRSTAT_L2FLUSHDONE_MASK    0X00010000U

#define APU_PWRSTAT_DBGNOPWRDWN_SHIFT   0U
#define APU_PWRSTAT_DBGNOPWRDWN_WIDTH   4U
#define APU_PWRSTAT_DBGNOPWRDWN_MASK    0X0000000FU

/**
 * Register: APU_ECO
 */
#define APU_ECO    ( ( APU_BASEADDR ) + 0X000000ECU )

#define APU_ECO_SPARE_SHIFT   0U
#define APU_ECO_SPARE_WIDTH   32U
#define APU_ECO_SPARE_MASK    0XFFFFFFFFU

/**
 * Register: APU_RAM_ADJ_0
 */
#define APU_RAM_ADJ_0    ( ( APU_BASEADDR ) + 0X000000F0U )

#define APU_RAM_ADJ_0_L1_ITAG_EMAS_SHIFT   29U
#define APU_RAM_ADJ_0_L1_ITAG_EMAS_WIDTH   1U
#define APU_RAM_ADJ_0_L1_ITAG_EMAS_MASK    0X20000000U

#define APU_RAM_ADJ_0_L1_ITAG_EMAW_SHIFT   27U
#define APU_RAM_ADJ_0_L1_ITAG_EMAW_WIDTH   2U
#define APU_RAM_ADJ_0_L1_ITAG_EMAW_MASK    0X18000000U

#define APU_RAM_ADJ_0_L1_ITAG_EMA_SHIFT   24U
#define APU_RAM_ADJ_0_L1_ITAG_EMA_WIDTH   3U
#define APU_RAM_ADJ_0_L1_ITAG_EMA_MASK    0X07000000U

#define APU_RAM_ADJ_0_L1_IDATA_EMAS_SHIFT   21U
#define APU_RAM_ADJ_0_L1_IDATA_EMAS_WIDTH   1U
#define APU_RAM_ADJ_0_L1_IDATA_EMAS_MASK    0X00200000U

#define APU_RAM_ADJ_0_L1_IDATA_EMAW_SHIFT   19U
#define APU_RAM_ADJ_0_L1_IDATA_EMAW_WIDTH   2U
#define APU_RAM_ADJ_0_L1_IDATA_EMAW_MASK    0X00180000U

#define APU_RAM_ADJ_0_L1_IDATA_EMA_SHIFT   16U
#define APU_RAM_ADJ_0_L1_IDATA_EMA_WIDTH   3U
#define APU_RAM_ADJ_0_L1_IDATA_EMA_MASK    0X00070000U

#define APU_RAM_ADJ_0_L1_DTAG_EMAS_SHIFT   13U
#define APU_RAM_ADJ_0_L1_DTAG_EMAS_WIDTH   1U
#define APU_RAM_ADJ_0_L1_DTAG_EMAS_MASK    0X00002000U

#define APU_RAM_ADJ_0_L1_DTAG_EMAW_SHIFT   11U
#define APU_RAM_ADJ_0_L1_DTAG_EMAW_WIDTH   2U
#define APU_RAM_ADJ_0_L1_DTAG_EMAW_MASK    0X00001800U

#define APU_RAM_ADJ_0_L1_DTAG_EMA_SHIFT   8U
#define APU_RAM_ADJ_0_L1_DTAG_EMA_WIDTH   3U
#define APU_RAM_ADJ_0_L1_DTAG_EMA_MASK    0X00000700U

#define APU_RAM_ADJ_0_L1_DDATA_EMAS_SHIFT   5U
#define APU_RAM_ADJ_0_L1_DDATA_EMAS_WIDTH   1U
#define APU_RAM_ADJ_0_L1_DDATA_EMAS_MASK    0X00000020U

#define APU_RAM_ADJ_0_L1_DDATA_EMAW_SHIFT   3U
#define APU_RAM_ADJ_0_L1_DDATA_EMAW_WIDTH   2U
#define APU_RAM_ADJ_0_L1_DDATA_EMAW_MASK    0X00000018U

#define APU_RAM_ADJ_0_L1_DDATA_EMA_SHIFT   0U
#define APU_RAM_ADJ_0_L1_DDATA_EMA_WIDTH   3U
#define APU_RAM_ADJ_0_L1_DDATA_EMA_MASK    0X00000007U

/**
 * Register: APU_RAM_ADJ_1
 */
#define APU_RAM_ADJ_1    ( ( APU_BASEADDR ) + 0X000000F4U )

#define APU_RAM_ADJ_1_TLB_EMAS_SHIFT   29U
#define APU_RAM_ADJ_1_TLB_EMAS_WIDTH   1U
#define APU_RAM_ADJ_1_TLB_EMAS_MASK    0X20000000U

#define APU_RAM_ADJ_1_TLB_EMAW_SHIFT   27U
#define APU_RAM_ADJ_1_TLB_EMAW_WIDTH   2U
#define APU_RAM_ADJ_1_TLB_EMAW_MASK    0X18000000U

#define APU_RAM_ADJ_1_TLB_EMA_SHIFT   24U
#define APU_RAM_ADJ_1_TLB_EMA_WIDTH   3U
#define APU_RAM_ADJ_1_TLB_EMA_MASK    0X07000000U

#define APU_RAM_ADJ_1_DIRTY_EMAS_SHIFT   21U
#define APU_RAM_ADJ_1_DIRTY_EMAS_WIDTH   1U
#define APU_RAM_ADJ_1_DIRTY_EMAS_MASK    0X00200000U

#define APU_RAM_ADJ_1_DIRTY_EMAW_SHIFT   19U
#define APU_RAM_ADJ_1_DIRTY_EMAW_WIDTH   2U
#define APU_RAM_ADJ_1_DIRTY_EMAW_MASK    0X00180000U

#define APU_RAM_ADJ_1_DIRTY_EMA_SHIFT   16U
#define APU_RAM_ADJ_1_DIRTY_EMA_WIDTH   3U
#define APU_RAM_ADJ_1_DIRTY_EMA_MASK    0X00070000U

#define APU_RAM_ADJ_1_BTAC1_EMAS_SHIFT   13U
#define APU_RAM_ADJ_1_BTAC1_EMAS_WIDTH   1U
#define APU_RAM_ADJ_1_BTAC1_EMAS_MASK    0X00002000U

#define APU_RAM_ADJ_1_BTAC1_EMAW_SHIFT   11U
#define APU_RAM_ADJ_1_BTAC1_EMAW_WIDTH   2U
#define APU_RAM_ADJ_1_BTAC1_EMAW_MASK    0X00001800U

#define APU_RAM_ADJ_1_BTAC1_EMA_SHIFT   8U
#define APU_RAM_ADJ_1_BTAC1_EMA_WIDTH   3U
#define APU_RAM_ADJ_1_BTAC1_EMA_MASK    0X00000700U

#define APU_RAM_ADJ_1_BTAC0_EMAS_SHIFT   5U
#define APU_RAM_ADJ_1_BTAC0_EMAS_WIDTH   1U
#define APU_RAM_ADJ_1_BTAC0_EMAS_MASK    0X00000020U

#define APU_RAM_ADJ_1_BTAC0_EMAW_SHIFT   3U
#define APU_RAM_ADJ_1_BTAC0_EMAW_WIDTH   2U
#define APU_RAM_ADJ_1_BTAC0_EMAW_MASK    0X00000018U

#define APU_RAM_ADJ_1_BTAC0_EMA_SHIFT   0U
#define APU_RAM_ADJ_1_BTAC0_EMA_WIDTH   3U
#define APU_RAM_ADJ_1_BTAC0_EMA_MASK    0X00000007U

/**
 * Register: APU_RAM_ADJ_2
 */
#define APU_RAM_ADJ_2    ( ( APU_BASEADDR ) + 0X000000F8U )

#define APU_RAM_ADJ_2_ETF_EMAS_SHIFT   29U
#define APU_RAM_ADJ_2_ETF_EMAS_WIDTH   1U
#define APU_RAM_ADJ_2_ETF_EMAS_MASK    0X20000000U

#define APU_RAM_ADJ_2_ETF_EMAW_SHIFT   27U
#define APU_RAM_ADJ_2_ETF_EMAW_WIDTH   2U
#define APU_RAM_ADJ_2_ETF_EMAW_MASK    0X18000000U

#define APU_RAM_ADJ_2_ETF_EMA_SHIFT   24U
#define APU_RAM_ADJ_2_ETF_EMA_WIDTH   3U
#define APU_RAM_ADJ_2_ETF_EMA_MASK    0X07000000U

#define APU_RAM_ADJ_2_SCU_TAG_EMAS_SHIFT   13U
#define APU_RAM_ADJ_2_SCU_TAG_EMAS_WIDTH   1U
#define APU_RAM_ADJ_2_SCU_TAG_EMAS_MASK    0X00002000U

#define APU_RAM_ADJ_2_SCU_TAG_EMAW_SHIFT   11U
#define APU_RAM_ADJ_2_SCU_TAG_EMAW_WIDTH   2U
#define APU_RAM_ADJ_2_SCU_TAG_EMAW_MASK    0X00001800U

#define APU_RAM_ADJ_2_SCU_TAG_EMA_SHIFT   8U
#define APU_RAM_ADJ_2_SCU_TAG_EMA_WIDTH   3U
#define APU_RAM_ADJ_2_SCU_TAG_EMA_MASK    0X00000700U

#define APU_RAM_ADJ_2_L2_VICTIM_EMAS_SHIFT   5U
#define APU_RAM_ADJ_2_L2_VICTIM_EMAS_WIDTH   1U
#define APU_RAM_ADJ_2_L2_VICTIM_EMAS_MASK    0X00000020U

#define APU_RAM_ADJ_2_L2_VICTIM_EMAW_SHIFT   3U
#define APU_RAM_ADJ_2_L2_VICTIM_EMAW_WIDTH   2U
#define APU_RAM_ADJ_2_L2_VICTIM_EMAW_MASK    0X00000018U

#define APU_RAM_ADJ_2_L2_VICTIM_EMA_SHIFT   0U
#define APU_RAM_ADJ_2_L2_VICTIM_EMA_WIDTH   3U
#define APU_RAM_ADJ_2_L2_VICTIM_EMA_MASK    0X00000007U

/**
 * Register: APU_RAM_ADJ_3
 */
#define APU_RAM_ADJ_3    ( ( APU_BASEADDR ) + 0X000000FCU )

#define APU_RAM_ADJ_3_L2_TAGECC_EMAS_SHIFT   29U
#define APU_RAM_ADJ_3_L2_TAGECC_EMAS_WIDTH   1U
#define APU_RAM_ADJ_3_L2_TAGECC_EMAS_MASK    0X20000000U

#define APU_RAM_ADJ_3_L2_TAGECC_EMAW_SHIFT   27U
#define APU_RAM_ADJ_3_L2_TAGECC_EMAW_WIDTH   2U
#define APU_RAM_ADJ_3_L2_TAGECC_EMAW_MASK    0X18000000U

#define APU_RAM_ADJ_3_L2_TAGECC_EMA_SHIFT   24U
#define APU_RAM_ADJ_3_L2_TAGECC_EMA_WIDTH   3U
#define APU_RAM_ADJ_3_L2_TAGECC_EMA_MASK    0X07000000U

#define APU_RAM_ADJ_3_L2_TAG_EMAS_SHIFT   21U
#define APU_RAM_ADJ_3_L2_TAG_EMAS_WIDTH   1U
#define APU_RAM_ADJ_3_L2_TAG_EMAS_MASK    0X00200000U

#define APU_RAM_ADJ_3_L2_TAG_EMAW_SHIFT   19U
#define APU_RAM_ADJ_3_L2_TAG_EMAW_WIDTH   2U
#define APU_RAM_ADJ_3_L2_TAG_EMAW_MASK    0X00180000U

#define APU_RAM_ADJ_3_L2_TAG_EMA_SHIFT   16U
#define APU_RAM_ADJ_3_L2_TAG_EMA_WIDTH   3U
#define APU_RAM_ADJ_3_L2_TAG_EMA_MASK    0X00070000U

#define APU_RAM_ADJ_3_L2_DATAECC_EMAS_SHIFT   13U
#define APU_RAM_ADJ_3_L2_DATAECC_EMAS_WIDTH   1U
#define APU_RAM_ADJ_3_L2_DATAECC_EMAS_MASK    0X00002000U

#define APU_RAM_ADJ_3_L2_DATAECC_EMAW_SHIFT   11U
#define APU_RAM_ADJ_3_L2_DATAECC_EMAW_WIDTH   2U
#define APU_RAM_ADJ_3_L2_DATAECC_EMAW_MASK    0X00001800U

#define APU_RAM_ADJ_3_L2_DATAECC_EMA_SHIFT   8U
#define APU_RAM_ADJ_3_L2_DATAECC_EMA_WIDTH   3U
#define APU_RAM_ADJ_3_L2_DATAECC_EMA_MASK    0X00000700U

#define APU_RAM_ADJ_3_L2_DATA_EMAS_SHIFT   5U
#define APU_RAM_ADJ_3_L2_DATA_EMAS_WIDTH   1U
#define APU_RAM_ADJ_3_L2_DATA_EMAS_MASK    0X00000020U

#define APU_RAM_ADJ_3_L2_DATA_EMAW_SHIFT   3U
#define APU_RAM_ADJ_3_L2_DATA_EMAW_WIDTH   2U
#define APU_RAM_ADJ_3_L2_DATA_EMAW_MASK    0X00000018U

#define APU_RAM_ADJ_3_L2_DATA_EMA_SHIFT   0U
#define APU_RAM_ADJ_3_L2_DATA_EMA_WIDTH   3U
#define APU_RAM_ADJ_3_L2_DATA_EMA_MASK    0X00000007U

/**
 * Register: APU_XPD_REG0
 */
#define APU_XPD_REG0    ( ( APU_BASEADDR ) + 0X00000600U )

#define APU_XPD_REG0_PRE_LOAD_SHIFT   0U
#define APU_XPD_REG0_PRE_LOAD_WIDTH   32U
#define APU_XPD_REG0_PRE_LOAD_MASK    0XFFFFFFFFU

/**
 * Register: APU_XPD_REG1
 */
#define APU_XPD_REG1    ( ( APU_BASEADDR ) + 0X00000604U )

#define APU_XPD_REG1_EXPECTED_SHIFT   0U
#define APU_XPD_REG1_EXPECTED_WIDTH   32U
#define APU_XPD_REG1_EXPECTED_MASK    0XFFFFFFFFU

/**
 * Register: APU_XPD_CTRL0
 */
#define APU_XPD_CTRL0    ( ( APU_BASEADDR ) + 0X00000608U )

#define APU_XPD_CTRL0_DELAY_SPARE_SHIFT   25U
#define APU_XPD_CTRL0_DELAY_SPARE_WIDTH   5U
#define APU_XPD_CTRL0_DELAY_SPARE_MASK    0X3E000000U

#define APU_XPD_CTRL0_CMP_SEL_SHIFT   24U
#define APU_XPD_CTRL0_CMP_SEL_WIDTH   1U
#define APU_XPD_CTRL0_CMP_SEL_MASK    0X01000000U

#define APU_XPD_CTRL0_DELAY_CELL_TYPE_SHIFT   19U
#define APU_XPD_CTRL0_DELAY_CELL_TYPE_WIDTH   5U
#define APU_XPD_CTRL0_DELAY_CELL_TYPE_MASK    0X00F80000U

#define APU_XPD_CTRL0_DELAY_VT_TYPE_SHIFT   17U
#define APU_XPD_CTRL0_DELAY_VT_TYPE_WIDTH   2U
#define APU_XPD_CTRL0_DELAY_VT_TYPE_MASK    0X00060000U

#define APU_XPD_CTRL0_DELAY_VALUE_SHIFT   6U
#define APU_XPD_CTRL0_DELAY_VALUE_WIDTH   11U
#define APU_XPD_CTRL0_DELAY_VALUE_MASK    0X0001FFC0U

#define APU_XPD_CTRL0_PATH_SEL_SHIFT   0U
#define APU_XPD_CTRL0_PATH_SEL_WIDTH   6U
#define APU_XPD_CTRL0_PATH_SEL_MASK    0X0000003FU

/**
 * Register: APU_XPD_CTRL1
 */
#define APU_XPD_CTRL1    ( ( APU_BASEADDR ) + 0X0000060CU )

#define APU_XPD_CTRL1_CLK_SPARE_SHIFT   12U
#define APU_XPD_CTRL1_CLK_SPARE_WIDTH   4U
#define APU_XPD_CTRL1_CLK_SPARE_MASK    0X0000F000U

#define APU_XPD_CTRL1_CLK_PHASE_SEL_SHIFT   10U
#define APU_XPD_CTRL1_CLK_PHASE_SEL_WIDTH   2U
#define APU_XPD_CTRL1_CLK_PHASE_SEL_MASK    0X00000C00U

#define APU_XPD_CTRL1_CLK_VT_TYPE_SHIFT   8U
#define APU_XPD_CTRL1_CLK_VT_TYPE_WIDTH   2U
#define APU_XPD_CTRL1_CLK_VT_TYPE_MASK    0X00000300U

#define APU_XPD_CTRL1_CLK_CELL_TYPE_SHIFT   6U
#define APU_XPD_CTRL1_CLK_CELL_TYPE_WIDTH   2U
#define APU_XPD_CTRL1_CLK_CELL_TYPE_MASK    0X000000C0U

#define APU_XPD_CTRL1_CLK_INSERT_DLY_SHIFT   2U
#define APU_XPD_CTRL1_CLK_INSERT_DLY_WIDTH   4U
#define APU_XPD_CTRL1_CLK_INSERT_DLY_MASK    0X0000003CU

#define APU_XPD_CTRL1_CLK_SEL_SHIFT   0U
#define APU_XPD_CTRL1_CLK_SEL_WIDTH   2U
#define APU_XPD_CTRL1_CLK_SEL_MASK    0X00000003U

/**
 * Register: APU_XPD_CTRL2
 */
#define APU_XPD_CTRL2    ( ( APU_BASEADDR ) + 0X00000614U )

#define APU_XPD_CTRL2_CTRL_SPARE_SHIFT   1U
#define APU_XPD_CTRL2_CTRL_SPARE_WIDTH   2U
#define APU_XPD_CTRL2_CTRL_SPARE_MASK    0X00000006U

#define APU_XPD_CTRL2_ENABLE_SHIFT   0U
#define APU_XPD_CTRL2_ENABLE_WIDTH   1U
#define APU_XPD_CTRL2_ENABLE_MASK    0X00000001U

/**
 * Register: APU_XPD_CTRL3
 */
#define APU_XPD_CTRL3    ( ( APU_BASEADDR ) + 0X00000618U )

#define APU_XPD_CTRL3_DCYCLE_CNT_VALUE_SHIFT   3U
#define APU_XPD_CTRL3_DCYCLE_CNT_VALUE_WIDTH   12U
#define APU_XPD_CTRL3_DCYCLE_CNT_VALUE_MASK    0X00007FF8U

#define APU_XPD_CTRL3_DCYCLE_HIGH_LOW_SHIFT   2U
#define APU_XPD_CTRL3_DCYCLE_HIGH_LOW_WIDTH   1U
#define APU_XPD_CTRL3_DCYCLE_HIGH_LOW_MASK    0X00000004U

#define APU_XPD_CTRL3_DCYCLE_CNT_CLR_SHIFT   1U
#define APU_XPD_CTRL3_DCYCLE_CNT_CLR_WIDTH   1U
#define APU_XPD_CTRL3_DCYCLE_CNT_CLR_MASK    0X00000002U

#define APU_XPD_CTRL3_DCYCLE_START_SHIFT   0U
#define APU_XPD_CTRL3_DCYCLE_START_WIDTH   1U
#define APU_XPD_CTRL3_DCYCLE_START_MASK    0X00000001U

/**
 * Register: APU_XPD_SOFT_RST
 */
#define APU_XPD_SOFT_RST    ( ( APU_BASEADDR ) + 0X0000061CU )

#define APU_XPD_SOFT_RST_CLK2_SHIFT   2U
#define APU_XPD_SOFT_RST_CLK2_WIDTH   1U
#define APU_XPD_SOFT_RST_CLK2_MASK    0X00000004U

#define APU_XPD_SOFT_RST_CLK1_SHIFT   1U
#define APU_XPD_SOFT_RST_CLK1_WIDTH   1U
#define APU_XPD_SOFT_RST_CLK1_MASK    0X00000002U

#define APU_XPD_SOFT_RST_CLK0_SHIFT   0U
#define APU_XPD_SOFT_RST_CLK0_WIDTH   1U
#define APU_XPD_SOFT_RST_CLK0_MASK    0X00000001U

/**
 * Register: APU_XPD_STAT
 */
#define APU_XPD_STAT    ( ( APU_BASEADDR ) + 0X00000620U )

#define APU_XPD_STAT_CMP_RESULT_SHIFT   1U
#define APU_XPD_STAT_CMP_RESULT_WIDTH   1U
#define APU_XPD_STAT_CMP_RESULT_MASK    0X00000002U

#define APU_XPD_STAT_CMP_DONE_SHIFT   0U
#define APU_XPD_STAT_CMP_DONE_WIDTH   1U
#define APU_XPD_STAT_CMP_DONE_MASK    0X00000001U

#ifdef __cplusplus
}
#endif


#endif /* PM_APU_H */
