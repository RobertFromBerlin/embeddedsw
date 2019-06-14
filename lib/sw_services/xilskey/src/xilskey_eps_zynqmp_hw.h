/******************************************************************************
*
* Copyright (C) 2015 - 2019 Xilinx, Inc.  All rights reserved.
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
* @file xilskey_eps_zynqmp_hw.h
* This header file contains identifiers and register-level driver functions (or
* macros) that can be used to access the Xilinx ZynqMp eFuse controller.
*
* <pre>
* MODIFICATION HISTORY:
*
* Ver   Who     Date     Changes
* ----- ------  -------- ------------------------------------------------------
* 4.0   vns     10/01/15 First release
* 6.0   vns     07/18/16 Modified RSA enable bit mask
* 6.2   vns     03/10/17 Added support for LBIST, LPD and FPD sc enable,
*                        PBR_BOOT_ERROR.
* 6.7   arc     01/05/19 Fixed MISRA-C violations.
* </pre>
*
******************************************************************************/

#ifndef __XSK_EPS_ZYNQMP_HW_H__
#define __XSK_EPS_ZYNQMP_HW_H__


#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/

#include "xil_io.h"

/************************** Constant Definitions *****************************/

/** @name eFuse PS Base Address
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_BASEADDR	0xFFCC0000U/**< Efuse PS base address */
/*@}*/

/** @name Write lock register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_WR_LOCK_OFFSET	0x00000000U
#define XSK_ZYNQMP_EFUSEPS_WR_LOCK_RSTVAL	0x00000001U

#define XSK_ZYNQMP_EFUSEPS_WR_LOCK_SHIFT		0U
#define XSK_ZYNQMP_EFUSEPS_WR_LOCK_WIDTH		16U
#define XSK_ZYNQMP_EFUSEPS_WR_LOCK_MASK		0x0000ffffU
#define XSK_ZYNQMP_EFUSEPS_WR_LOCK_DEFVAL	0x1U
#define XSK_ZYNQMO_EFUSEP_WR_UNLOCK_VALUE	0xDF0D
/*@}*/

/** @name Cfg register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_CFG_OFFSET		0x00000004U
#define XSK_ZYNQMP_EFUSEPS_CFG_RSTVAL		0x00000000U

#define XSK_ZYNQMP_EFUSEPS_CFG_SLVERR_EN_SHIFT	5U
#define XSK_ZYNQMP_EFUSEPS_CFG_SLVERR_EN_WIDTH	1U
#define XSK_ZYNQMP_EFUSEPS_CFG_SLVERR_EN_MASK	0x00000020U
#define XSK_ZYNQMP_EFUSEPS_CFG_SLVERR_EN_DEFVAL	0x0U

#define XSK_ZYNQMP_EFUSEPS_CFG_MARGIN_RD_SHIFT	2U
#define XSK_ZYNQMP_EFUSEPS_CFG_MARGIN_RD_WIDTH	2U
#define XSK_ZYNQMP_EFUSEPS_CFG_MARGIN_RD_MASK	0x0000000cU
#define XSK_ZYNQMP_EFUSEPS_CFG_MARGIN_RD_DEFVAL	0x0U
#define XSK_ZYNQMP_EFUSEPS_CFG_MARGIN_1_RD	0x01
#define XSK_ZYNQMP_EFUSEPS_CFG_MARGIN_2_RD	0x02U
#define XSK_ZYNQMP_EFUSEPS_CFG_NORMAL_RD	0x00U

#define XSK_ZYNQMP_EFUSEPS_CFG_PGM_EN_SHIFT	1U
#define XSK_ZYNQMP_EFUSEPS_CFG_PGM_EN_WIDTH	1U
#define XSK_ZYNQMP_EFUSEPS_CFG_PGM_EN_MASK	0x00000002U
#define XSK_ZYNQMP_EFUSEPS_CFG_PGM_EN_DEFVAL	0x0U

#define XSK_ZYNQMP_EFUSEPS_CFG_CLK_SEL_SHIFT	0U
#define XSK_ZYNQMP_EFUSEPS_CFG_CLK_SEL_WIDTH	1U
#define XSK_ZYNQMP_EFUSEPS_CFG_CLK_SEL_MASK	0x00000001U
#define XSK_ZYNQMP_EFUSEPS_CFG_CLK_SEL_DEFVAL	0x0U
/*@}*/

/** @name Status register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_STS_OFFSET		0x00000008U
#define XSK_ZYNQMP_EFUSEPS_STS_RSTVAL		0x00000000U

#define XSK_ZYNQMP_EFUSEPS_STS_AES_CRC_PASS_SHIFT	7U
#define XSK_ZYNQMP_EFUSEPS_STS_AES_CRC_PASS_WIDTH	1U
#define XSK_ZYNQMP_EFUSEPS_STS_AES_CRC_PASS_MASK	0x00000080U
#define XSK_ZYNQMP_EFUSEPS_STS_AES_CRC_PASS_DEFVAL	0x0U

#define XSK_ZYNQMP_EFUSEPS_STS_AES_CRC_DONE_SHIFT	6U
#define XSK_ZYNQMP_EFUSEPS_STS_AES_CRC_DONE_WIDTH	1U
#define XSK_ZYNQMP_EFUSEPS_STS_AES_CRC_DONE_MASK	0x00000040U
#define XSK_ZYNQMP_EFUSEPS_STS_AES_CRC_DONE_DEFVAL	0x0U

#define XSK_ZYNQMP_EFUSEPS_STS_CACHE_DONE_SHIFT		5U
#define XSK_ZYNQMP_EFUSEPS_STS_CACHE_DONE_WIDTH		1U
#define XSK_ZYNQMP_EFUSEPS_STS_CACHE_DONE_MASK		0x00000020U
#define XSK_ZYNQMP_EFUSEPS_STS_CACHE_DONE_DEFVAL	0x0U

#define XSK_ZYNQMP_EFUSEPS_STS_CACHE_LOAD_SHIFT		4U
#define XSK_ZYNQMP_EFUSEPS_STS_CACHE_LOAD_WIDTH		1U
#define XSK_ZYNQMP_EFUSEPS_STS_CACHE_LOAD_MASK		0x00000010U
#define XSK_ZYNQMP_EFUSEPS_STS_CACHE_LOAD_DEFVAL	0x0U

#define XSK_ZYNQMP_EFUSEPS_STS_3_TBIT_SHIFT		2U
#define XSK_ZYNQMP_EFUSEPS_STS_3_TBIT_WIDTH		1U
#define XSK_ZYNQMP_EFUSEPS_STS_3_TBIT_MASK		0x00000004U
#define XSK_ZYNQMP_EFUSEPS_STS_3_TBIT_DEFVAL		0x0U

#define XSK_ZYNQMP_EFUSEPS_STS_2_TBIT_SHIFT		1U
#define XSK_ZYNQMP_EFUSEPS_STS_2_TBIT_WIDTH		1U
#define XSK_ZYNQMP_EFUSEPS_STS_2_TBIT_MASK		0x00000002U
#define XSK_ZYNQMP_EFUSEPS_STS_2_TBIT_DEFVAL		0x0U

#define XSK_ZYNQMP_EFUSEPS_STS_0_TBIT_SHIFT		0U
#define XSK_ZYNQMP_EFUSEPS_STS_0_TBIT_WIDTH		1U
#define XSK_ZYNQMP_EFUSEPS_STS_0_TBIT_MASK		0x00000001U
#define XSK_ZYNQMP_EFUSEPS_STS_0_TBIT_DEFVAL		0x0U
/*@}*/

/** @name program address register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_PGM_ADDR_OFFSET	0x0000000CU
#define XSK_ZYNQMP_EFUSEPS_PGM_ADDR_RSTVAL	0x00000000U

#define XSK_ZYNQMP_EFUSEPS_PGM_ADDR_SHIFT	11U
#define XSK_ZYNQMP_EFUSEPS_PGM_ADDR_WIDTH	2U
#define XSK_ZYNQMP_EFUSEPS_PGM_ADDR_MASK	0x00001800U
#define XSK_ZYNQMP_EFUSEPS_PGM_ADDR_DEFVAL	0x0U

#define XSK_ZYNQMP_EFUSEPS_PGM_ADDR_ROW_SHIFT	5U
#define XSK_ZYNQMP_EFUSEPS_PGM_ADDR_ROW_WIDTH	6U
#define XSK_ZYNQMP_EFUSEPS_PGM_ADDR_ROW_MASK	0x000007e0U
#define XSK_ZYNQMP_EFUSEPS_PGM_ADDR_ROW_DEFVAL	0x0U

#define XSK_ZYNQMP_EFUSEPS_PGM_ADDR_COL_SHIFT	0U
#define XSK_ZYNQMP_EFUSEPS_PGM_ADDR_COL_WIDTH	5U
#define XSK_ZYNQMP_EFUSEPS_PGM_ADDR_COL_MASK	0x0000001fU
#define XSK_ZYNQMP_EFUSEPS_PGM_ADDR_COL_DEFVAL	0x0U
/*@}*/

/** @name read address register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_RD_ADDR_OFFSET	0x00000010U
#define XSK_ZYNQMP_EFUSEPS_RD_ADDR_RSTVAL	0x00000000U

#define XSK_ZYNQMP_EFUSEPS_RD_ADDR_SHIFT	11U
#define XSK_ZYNQMP_EFUSEPS_RD_ADDR_WIDTH	2U
#define XSK_ZYNQMP_EFUSEPS_RD_ADDR_MASK		0x00001800U
#define XSK_ZYNQMP_EFUSEPS_RD_ADDR_DEFVAL	0x0U

#define XSK_ZYNQMP_EFUSEPS_RD_ADDR_ROW_SHIFT	5U
#define XSK_ZYNQMP_EFUSEPS_RD_ADDR_ROW_WIDTH	6U
#define XSK_ZYNQMP_EFUSEPS_RD_ADDR_ROW_MASK	0x000007e0U
#define XSK_ZYNQMP_EFUSEPS_RD_ADDR_ROW_DEFVAL	0x0U
/*@}*/

/** @name read data register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_RD_DATA_OFFSET	0x00000014U
#define XSK_ZYNQMP_EFUSEPS_RD_DATA_RSTVAL	0x00000000U

#define XSK_ZYNQMP_EFUSEPS_RD_DATA_SHIFT	0U
#define XSK_ZYNQMP_EFUSEPS_RD_DATA_WIDTH	32U
#define XSK_ZYNQMP_EFUSEPS_RD_DATA_MASK		0xffffffffU
#define XSK_ZYNQMP_EFUSEPS_RD_DATA_DEFVAL	0x0U
/*@}*/

/** @name TPGM register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_TPGM_OFFSET		0x00000018U
#define XSK_ZYNQMP_EFUSEPS_TPGM_RSTVAL		0x00000000U

#define XSK_ZYNQMP_EFUSEPS_TPGM_VAL_SHIFT	0U
#define XSK_ZYNQMP_EFUSEPS_TPGM_VAL_WIDTH	16U
#define XSK_ZYNQMP_EFUSEPS_TPGM_VAL_MASK	0x0000ffffU
#define XSK_ZYNQMP_EFUSEPS_TPGM_VAL_DEFVAL	0x0U
/*@}*/

/** @name TRD register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_TRD_OFFSET		0x0000001CU
#define XSK_ZYNQMP_EFUSEPS_TRD_RSTVAL		0x00000022U

#define XSK_ZYNQMP_EFUSEPS_TRD_VAL_SHIFT	0U
#define XSK_ZYNQMP_EFUSEPS_TRD_VAL_WIDTH	8U
#define XSK_ZYNQMP_EFUSEPS_TRD_VAL_MASK		0x000000ffU
#define XSK_ZYNQMP_EFUSEPS_TRD_VAL_DEFVAL	0x22U
/*@}*/

/** @name TSU_H_PS register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_TSU_H_PS_OFFSET	0x00000020U
#define XSK_ZYNQMP_EFUSEPS_TSU_H_PS_RSTVAL	0x000000ffU

#define XSK_ZYNQMP_EFUSEPS_TSU_H_PS_VAL_SHIFT	0U
#define XSK_ZYNQMP_EFUSEPS_TSU_H_PS_VAL_WIDTH	8U
#define XSK_ZYNQMP_EFUSEPS_TSU_H_PS_VAL_MASK	0x000000ffU
#define XSK_ZYNQMP_EFUSEPS_TSU_H_PS_VAL_DEFVAL	0xffU
/*@}*/

/** @name TSU H PS register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_TSU_H_PS_CS_OFFSET	0x00000024U
#define XSK_ZYNQMP_EFUSEPS_TSU_H_PS_CS_RSTVAL	0x0000000bU

#define XSK_ZYNQMP_EFUSEPS_TSU_H_PS_CS_VAL_SHIFT	0U
#define XSK_ZYNQMP_EFUSEPS_TSU_H_PS_CS_VAL_WIDTH	8U
#define XSK_ZYNQMP_EFUSEPS_TSU_H_PS_CS_VAL_MASK	0x000000ffU
#define XSK_ZYNQMP_EFUSEPS_TSU_H_PS_CS_VAL_DEFVAL	0xbU
/*@}*/

/** @name TSU H CS register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_TSU_H_CS_OFFSET	0x0000002CU
#define XSK_ZYNQMP_EFUSEPS_TSU_H_CS_RSTVAL	0x00000007U

#define XSK_ZYNQMP_EFUSEPS_TSU_H_CS_VAL_SHIFT	0U
#define XSK_ZYNQMP_EFUSEPS_TSU_H_CS_VAL_WIDTH	4U
#define XSK_ZYNQMP_EFUSEPS_TSU_H_CS_VAL_MASK	0x0000000fU
#define XSK_ZYNQMP_EFUSEPS_TSU_H_CS_VAL_DEFVAL	0x7U
/*@}*/

/** @name ISR register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_ISR_OFFSET		0x00000030U
#define XSK_ZYNQMP_EFUSEPS_ISR_RSTVAL		0x00000000U

#define XSK_ZYNQMP_EFUSEPS_ISR_APB_SLVERR_SHIFT		31U
#define XSK_ZYNQMP_EFUSEPS_ISR_APB_SLVERR_WIDTH		1U
#define XSK_ZYNQMP_EFUSEPS_ISR_APB_SLVERR_MASK	0x80000000U
#define XSK_ZYNQMP_EFUSEPS_ISR_APB_SLVERR_DEFVAL	0x0U

#define XSK_ZYNQMP_EFUSEPS_ISR_CACHE_ERR_SHIFT		4U
#define XSK_ZYNQMP_EFUSEPS_ISR_CACHE_ERR_WIDTH		1U
#define XSK_ZYNQMP_EFUSEPS_ISR_CACHE_ERR_MASK	0x00000010U
#define XSK_ZYNQMP_EFUSEPS_ISR_CACHE_ERR_DEFVAL		0x0U

#define XSK_ZYNQMP_EFUSEPS_ISR_RD_ERR_SHIFT		3U
#define XSK_ZYNQMP_EFUSEPS_ISR_RD_ERR_WIDTH		1U
#define XSK_ZYNQMP_EFUSEPS_ISR_RD_ERR_MASK	0x00000008U
#define XSK_ZYNQMP_EFUSEPS_ISR_RD_ERR_DEFVAL		0x0U

#define XSK_ZYNQMP_EFUSEPS_ISR_RD_DONE_SHIFT		2U
#define XSK_ZYNQMP_EFUSEPS_ISR_RD_DONE_WIDTH		1U
#define XSK_ZYNQMP_EFUSEPS_ISR_RD_DONE_MASK	0x00000004U
#define XSK_ZYNQMP_EFUSEPS_ISR_RD_DONE_DEFVAL		0x0U

#define XSK_ZYNQMP_EFUSEPS_ISR_PGM_ERR_SHIFT		1U
#define XSK_ZYNQMP_EFUSEPS_ISR_PGM_ERR_WIDTH		1U
#define XSK_ZYNQMP_EFUSEPS_ISR_PGM_ERR_MASK	0x00000002U
#define XSK_ZYNQMP_EFUSEPS_ISR_PGM_ERR_DEFVAL		0x0U

#define XSK_ZYNQMP_EFUSEPS_ISR_PGM_DONE_SHIFT		0U
#define XSK_ZYNQMP_EFUSEPS_ISR_PGM_DONE_WIDTH		1U
#define XSK_ZYNQMP_EFUSEPS_ISR_PGM_DONE_MASK	0x00000001U
#define XSK_ZYNQMP_EFUSEPS_ISR_PGM_DONE_DEFVAL		0U
/*@}*/

/** @name IMR register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_IMR_OFFSET		0x00000034U
#define XSK_ZYNQMP_EFUSEPS_IMR_RSTVAL		0x8000001fU

#define XSK_ZYNQMP_EFUSEPS_IMR_APB_SLVERR_SHIFT		31U
#define XSK_ZYNQMP_EFUSEPS_IMR_APB_SLVERR_WIDTH		1U
#define XSK_ZYNQMP_EFUSEPS_IMR_APB_SLVERR_MASK	0x80000000U
#define XSK_ZYNQMP_EFUSEPS_IMR_APB_SLVERR_DEFVAL	0x1U

#define XSK_ZYNQMP_EFUSEPS_IMR_CACHE_ERR_SHIFT		4U
#define XSK_ZYNQMP_EFUSEPS_IMR_CACHE_ERR_WIDTH		1U
#define XSK_ZYNQMP_EFUSEPS_IMR_CACHE_ERR_MASK	0x00000010U
#define XSK_ZYNQMP_EFUSEPS_IMR_CACHE_ERR_DEFVAL		0x1U

#define XSK_ZYNQMP_EFUSEPS_IMR_RD_ERR_SHIFT		3U
#define XSK_ZYNQMP_EFUSEPS_IMR_RD_ERR_WIDTH		1U
#define XSK_ZYNQMP_EFUSEPS_IMR_RD_ERR_MASK	0x00000008U
#define XSK_ZYNQMP_EFUSEPS_IMR_RD_ERR_DEFVAL		0x1U

#define XSK_ZYNQMP_EFUSEPS_IMR_RD_DONE_SHIFT		2U
#define XSK_ZYNQMP_EFUSEPS_IMR_RD_DONE_WIDTH		1U
#define XSK_ZYNQMP_EFUSEPS_IMR_RD_DONE_MASK	0x00000004U
#define XSK_ZYNQMP_EFUSEPS_IMR_RD_DONE_DEFVAL		0x1U

#define XSK_ZYNQMP_EFUSEPS_IMR_PGM_ERR_SHIFT		1U
#define XSK_ZYNQMP_EFUSEPS_IMR_PGM_ERR_WIDTH		1U
#define XSK_ZYNQMP_EFUSEPS_IMR_PGM_ERR_MASK	0x00000002U
#define XSK_ZYNQMP_EFUSEPS_IMR_PGM_ERR_DEFVAL		0x1U

#define XSK_ZYNQMP_EFUSEPS_IMR_PGM_DONE_SHIFT		0U
#define XSK_ZYNQMP_EFUSEPS_IMR_PGM_DONE_WIDTH		1U
#define XSK_ZYNQMP_EFUSEPS_IMR_PGM_DONE_MASK	0x00000001U
#define XSK_ZYNQMP_EFUSEPS_IMR_PGM_DONE_DEFVAL		0x1U
/*@}*/

/** @name IER register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_IER_OFFSET		0x00000038U
#define XSK_ZYNQMP_EFUSEPS_IER_RSTVAL		0x00000000U

#define XSK_ZYNQMP_EFUSEPS_IER_APB_SLVERR_SHIFT	31U
#define XSK_ZYNQMP_EFUSEPS_IER_APB_SLVERR_WIDTH	1U
#define XSK_ZYNQMP_EFUSEPS_IER_APB_SLVERR_MASK	0x80000000U
#define XSK_ZYNQMP_EFUSEPS_IER_APB_SLVERR_DEFVAL	0x0U

#define XSK_ZYNQMP_EFUSEPS_IER_CACHE_ERR_SHIFT	4U
#define XSK_ZYNQMP_EFUSEPS_IER_CACHE_ERR_WIDTH	1U
#define XSK_ZYNQMP_EFUSEPS_IER_CACHE_ERR_MASK	0x00000010U
#define XSK_ZYNQMP_EFUSEPS_IER_CACHE_ERR_DEFVAL	0x0U

#define XSK_ZYNQMP_EFUSEPS_IER_RD_ERR_SHIFT	3U
#define XSK_ZYNQMP_EFUSEPS_IER_RD_ERR_WIDTH	1U
#define XSK_ZYNQMP_EFUSEPS_IER_RD_ERR_MASK	0x00000008U
#define XSK_ZYNQMP_EFUSEPS_IER_RD_ERR_DEFVAL	0x0U

#define XSK_ZYNQMP_EFUSEPS_IER_RD_DONE_SHIFT	2U
#define XSK_ZYNQMP_EFUSEPS_IER_RD_DONE_WIDTH	1U
#define XSK_ZYNQMP_EFUSEPS_IER_RD_DONE_MASK	0x00000004U
#define XSK_ZYNQMP_EFUSEPS_IER_RD_DONE_DEFVAL	0x0U

#define XSK_ZYNQMP_EFUSEPS_IER_PGM_ERR_SHIFT	1U
#define XSK_ZYNQMP_EFUSEPS_IER_PGM_ERR_WIDTH	1U
#define XSK_ZYNQMP_EFUSEPS_IER_PGM_ERR_MASK	0x00000002U
#define XSK_ZYNQMP_EFUSEPS_IER_PGM_ERR_DEFVAL	0x0U

#define XSK_ZYNQMP_EFUSEPS_IER_PGM_DONE_SHIFT	0U
#define XSK_ZYNQMP_EFUSEPS_IER_PGM_DONE_WIDTH	1U
#define XSK_ZYNQMP_EFUSEPS_IER_PGM_DONE_MASK	0x00000001U
#define XSK_ZYNQMP_EFUSEPS_IER_PGM_DONE_DEFVAL	0x0U
/*@}*/

/** @name IDR register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_IDR_OFFSET		0x0000003CU
#define XSK_ZYNQMP_EFUSEPS_IDR_RSTVAL		0x00000000U

#define XSK_ZYNQMP_EFUSEPS_IDR_APB_SLVERR_SHIFT		31U
#define XSK_ZYNQMP_EFUSEPS_IDR_APB_SLVERR_WIDTH		1U
#define XSK_ZYNQMP_EFUSEPS_IDR_APB_SLVERR_MASK	0x80000000U
#define XSK_ZYNQMP_EFUSEPS_IDR_APB_SLVERR_DEFVAL	0x0U

#define XSK_ZYNQMP_EFUSEPS_IDR_CACHE_ERR_SHIFT		4U
#define XSK_ZYNQMP_EFUSEPS_IDR_CACHE_ERR_WIDTH		1U
#define XSK_ZYNQMP_EFUSEPS_IDR_CACHE_ERR_MASK	0x00000010U
#define XSK_ZYNQMP_EFUSEPS_IDR_CACHE_ERR_DEFVAL		0x0U

#define XSK_ZYNQMP_EFUSEPS_IDR_RD_ERR_SHIFT		3U
#define XSK_ZYNQMP_EFUSEPS_IDR_RD_ERR_WIDTH		1U
#define XSK_ZYNQMP_EFUSEPS_IDR_RD_ERR_MASK	0x00000008U
#define XSK_ZYNQMP_EFUSEPS_IDR_RD_ERR_DEFVAL		0x0U

#define XSK_ZYNQMP_EFUSEPS_IDR_RD_DONE_SHIFT		2U
#define XSK_ZYNQMP_EFUSEPS_IDR_RD_DONE_WIDTH		1U
#define XSK_ZYNQMP_EFUSEPS_IDR_RD_DONE_MASK	0x00000004U
#define XSK_ZYNQMP_EFUSEPS_IDR_RD_DONE_DEFVAL		0x0U

#define XSK_ZYNQMP_EFUSEPS_IDR_PGM_ERR_SHIFT		1U
#define XSK_ZYNQMP_EFUSEPS_IDR_PGM_ERR_WIDTH		1U
#define XSK_ZYNQMP_EFUSEPS_IDR_PGM_ERR_MASK	0x00000002U
#define XSK_ZYNQMP_EFUSEPS_IDR_PGM_ERR_DEFVAL		0x0U

#define XSK_ZYNQMP_EFUSEPS_IDR_PGM_DONE_SHIFT		0U
#define XSK_ZYNQMP_EFUSEPS_IDR_PGM_DONE_WIDTH		1U
#define XSK_ZYNQMP_EFUSEPS_IDR_PGM_DONE_MASK	0x00000001U
#define XSK_ZYNQMP_EFUSEPS_IDR_PGM_DONE_DEFVAL		0x0U
/*@}*/

/** @name Cache load register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_CACHE_LOAD_OFFSET	0x00000040U
#define XSK_ZYNQMP_EFUSEPS_CACHE_LOAD_RSTVAL	0x00000000U

#define XSK_ZYNQMP_EFUSEPS_CACHE_LOAD_SHIFT	0U
#define XSK_ZYNQMP_EFUSEPS_CACHE_LOAD_WIDTH	1U
#define XSK_ZYNQMP_EFUSEPS_CACHE_LOAD_MASK	0x00000001U
#define XSK_ZYNQMP_EFUSEPS_CACHE_LOAD_DEFVAL	0x0U
/*@}*/

/** @name Program lock register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_PGM_LOCK_OFFSET	0x00000044U
#define XSK_ZYNQMP_EFUSEPS_PGM_LOCK_RSTVAL	0x00000000U

#define XSK_ZYNQMP_EFUSEPS_PGM_LOCK_SPK_ID_SHIFT	0U
#define XSK_ZYNQMP_EFUSEPS_PGM_LOCK_SPK_ID_WIDTH	1U
#define XSK_ZYNQMP_EFUSEPS_PGM_LOCK_SPK_ID_MASK	0x00000001U
#define XSK_ZYNQMP_EFUSEPS_PGM_LOCK_SPK_ID_DEFVAL	0x0U
/*@}*/

/** @name AES CRC register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_AES_CRC_OFFSET	0x00000048U
#define XSK_ZYNQMP_EFUSEPS_AES_CRC_RSTVAL	0x00000000U

#define XSK_ZYNQMP_EFUSEPS_AES_CRC_VAL_SHIFT		0U
#define XSK_ZYNQMP_EFUSEPS_AES_CRC_VAL_WIDTH		32U
#define XSK_ZYNQMP_EFUSEPS_AES_CRC_VAL_MASK	0xffffffffU
#define XSK_ZYNQMP_EFUSEPS_AES_CRC_VAL_DEFVAL		0x0U
/*@}*/

/** @name Tbits programming enable register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_TBITS_PRGRMG_EN_OFFSET	0x00000100U
#define XSK_ZYNQMP_EFUSEPS_TBITS_PRGRMG_EN_MASK		0x00000008U
/*@}*/

/** @name DNA 0 register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_DNA_0_OFFSET		0x0000100CU
#define XSK_ZYNQMP_EFUSEPS_DNA_0_RSTVAL		0x00000000U

#define XSK_ZYNQMP_EFUSEPS_DNA_0_SHIFT		0U
#define XSK_ZYNQMP_EFUSEPS_DNA_0_WIDTH		32U
#define XSK_ZYNQMP_EFUSEPS_DNA_0_MASK		0xffffffffU
#define XSK_ZYNQMP_EFUSEPS_DNA_0_DEFVAL		0x0U
/*@}*/

/** @name DNA 1 register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_DNA_1_OFFSET		0x00001010U
#define XSK_ZYNQMP_EFUSEPS_DNA_1_RSTVAL		0x00000000U

#define XSK_ZYNQMP_EFUSEPS_DNA_1_SHIFT		0U
#define XSK_ZYNQMP_EFUSEPS_DNA_1_WIDTH		32U
#define XSK_ZYNQMP_EFUSEPS_DNA_1_MASK		0xffffffffU
#define XSK_ZYNQMP_EFUSEPS_DNA_1_DEFVAL		0x0U
/*@}*/

/** @name DNA 2 register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_DNA_2_OFFSET		0x00001014U
#define XSK_ZYNQMP_EFUSEPS_DNA_2_RSTVAL		0x00000000U

#define XSK_ZYNQMP_EFUSEPS_DNA_2_SHIFT		0U
#define XSK_ZYNQMP_EFUSEPS_DNA_2_WIDTH		32U
#define XSK_ZYNQMP_EFUSEPS_DNA_2_MASK		0xffffffffU
#define XSK_ZYNQMP_EFUSEPS_DNA_2_DEFVAL		0x0U
/*@}*/

/** @name User_0 register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_USER_0_OFFSET	0x00001020U
#define XSK_ZYNQMP_EFUSEPS_USER_0_RSTVAL	0x00000000U

#define XSK_ZYNQMP_EFUSEPS_USER_0_SHIFT		0U
#define XSK_ZYNQMP_EFUSEPS_USER_0_WIDTH		32U
#define XSK_ZYNQMP_EFUSEPS_USER_0_MASK		0xffffffffU
#define XSK_ZYNQMP_EFUSEPS_USER_0_DEFVAL	0x0U
/*@}*/

/** @name User_1 register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_USER_1_OFFSET	0x00001024U
#define XSK_ZYNQMP_EFUSEPS_USER_1_RSTVAL	0x00000000U

#define XSK_ZYNQMP_EFUSEPS_USER_1_SHIFT		0U
#define XSK_ZYNQMP_EFUSEPS_USER_1_WIDTH		32U
#define XSK_ZYNQMP_EFUSEPS_USER_1_MASK		0xffffffffU
#define XSK_ZYNQMP_EFUSEPS_USER_1_DEFVAL	0x0U
/*@}*/

/** @name User_2 register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_USER_2_OFFSET	0x00001028U
#define XSK_ZYNQMP_EFUSEPS_USER_2_RSTVAL	0x00000000U

#define XSK_ZYNQMP_EFUSEPS_USER_2_SHIFT		0U
#define XSK_ZYNQMP_EFUSEPS_USER_2_WIDTH		32U
#define XSK_ZYNQMP_EFUSEPS_USER_2_MASK		0xffffffffU
#define XSK_ZYNQMP_EFUSEPS_USER_2_DEFVAL	0x0U
/*@}*/

/** @name User_3 register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_USER_3_OFFSET	0x0000102CU
#define XSK_ZYNQMP_EFUSEPS_USER_3_RSTVAL	0x00000000U

#define XSK_ZYNQMP_EFUSEPS_USER_3_SHIFT		0U
#define XSK_ZYNQMP_EFUSEPS_USER_3_WIDTH		32U
#define XSK_ZYNQMP_EFUSEPS_USER_3_MASK		0xffffffffU
#define XSK_ZYNQMP_EFUSEPS_USER_3_DEFVAL	0x0U
/*@}*/

/** @name User_4 register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_USER_4_OFFSET	0x00001030U
#define XSK_ZYNQMP_EFUSEPS_USER_4_RSTVAL	0x00000000U

#define XSK_ZYNQMP_EFUSEPS_USER_4_SHIFT		0U
#define XSK_ZYNQMP_EFUSEPS_USER_4_WIDTH		32U
#define XSK_ZYNQMP_EFUSEPS_USER_4_MASK		0xffffffffU
#define XSK_ZYNQMP_EFUSEPS_USER_4_DEFVAL	0x0U
/*@}*/

/** @name User_5 register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_USER_5_OFFSET	0x00001034U
#define XSK_ZYNQMP_EFUSEPS_USER_5_RSTVAL	0x00000000U

#define XSK_ZYNQMP_EFUSEPS_USER_5_SHIFT		0U
#define XSK_ZYNQMP_EFUSEPS_USER_5_WIDTH		32U
#define XSK_ZYNQMP_EFUSEPS_USER_5_MASK		0xffffffffU
#define XSK_ZYNQMP_EFUSEPS_USER_5_DEFVAL	0x0U
/*@}*/

/** @name User_6 register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_USER_6_OFFSET	0x00001038U
#define XSK_ZYNQMP_EFUSEPS_USER_6_RSTVAL	0x00000000U

#define XSK_ZYNQMP_EFUSEPS_USER_6_SHIFT		0U
#define XSK_ZYNQMP_EFUSEPS_USER_6_WIDTH		32U
#define XSK_ZYNQMP_EFUSEPS_USER_6_MASK		0xffffffffU
#define XSK_ZYNQMP_EFUSEPS_USER_6_DEFVAL	0x0U
/*@}*/

/** @name User_7 register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_USER_7_OFFSET	0x0000103CU
#define XSK_ZYNQMP_EFUSEPS_USER_7_RSTVAL	0x00000000U

#define XSK_ZYNQMP_EFUSEPS_USER_7_SHIFT		0U
#define XSK_ZYNQMP_EFUSEPS_USER_7_WIDTH		32U
#define XSK_ZYNQMP_EFUSEPS_USER_7_MASK		0xffffffffU
#define XSK_ZYNQMP_EFUSEPS_USER_7_DEFVAL	0x0U
/*@}*/

/** @name Misc user control register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_MISC_USER_CTRL_OFFSET	0x00001040U
#define XSK_ZYNQMP_EFUSEPS_MISC_USER_CTRL_RSTVAL	0x00000000U

#define XSK_ZYNQMP_EFUSEPS_MISC_USER_CTRL_RESERVED_MASK		0xFFFE0300U

#define XSK_ZYNQMP_EFUSEPS_MISC_USER_CTRL_LPD_SC_EN_MASK	0x00003800U
#define XSK_ZYNQMP_EFUSEPS_MISC_USER_CTRL_LPD_SC_EN_SHIFT	11U

#define XSK_ZYNQMP_EFUSEPS_MISC_USER_CTRL_FPD_SC_EN_MASK	0x00001C000U
#define XSK_ZYNQMP_EFUSEPS_MISC_USER_CTRL_FPD_SC_EN_SHIFT	14U

#define XSK_ZYNQMP_EFUSEPS_MISC_USER_CTRL_LBIST_EN_SHIFT	10U
#define XSK_ZYNQMP_EFUSEPS_MISC_USER_CTRL_LBIST_EN_MASK		0x00000400U

#define XSK_ZYNQMP_EFUSEPS_MISC_USER_CTRL_USR_WRLK_7_SHIFT	7U
#define XSK_ZYNQMP_EFUSEPS_MISC_USER_CTRL_USR_WRLK_7_WIDTH	1U
#define XSK_ZYNQMP_EFUSEPS_MISC_USER_CTRL_USR_WRLK_7_MASK	0x00000080U
#define XSK_ZYNQMP_EFUSEPS_MISC_USER_CTRL_USR_WRLK_7_DEFVAL	0x0U

#define XSK_ZYNQMP_EFUSEPS_MISC_USER_CTRL_USR_WRLK_6_SHIFT	6U
#define XSK_ZYNQMP_EFUSEPS_MISC_USER_CTRL_USR_WRLK_6_WIDTH	1U
#define XSK_ZYNQMP_EFUSEPS_MISC_USER_CTRL_USR_WRLK_6_MASK	0x00000040U
#define XSK_ZYNQMP_EFUSEPS_MISC_USER_CTRL_USR_WRLK_6_DEFVAL	0x0U

#define XSK_ZYNQMP_EFUSEPS_MISC_USER_CTRL_USR_WRLK_5_SHIFT	5U
#define XSK_ZYNQMP_EFUSEPS_MISC_USER_CTRL_USR_WRLK_5_WIDTH	1U
#define XSK_ZYNQMP_EFUSEPS_MISC_USER_CTRL_USR_WRLK_5_MASK	0x00000020U
#define XSK_ZYNQMP_EFUSEPS_MISC_USER_CTRL_USR_WRLK_5_DEFVAL	0x0U

#define XSK_ZYNQMP_EFUSEPS_MISC_USER_CTRL_USR_WRLK_4_SHIFT	4U
#define XSK_ZYNQMP_EFUSEPS_MISC_USER_CTRL_USR_WRLK_4_WIDTH	1U
#define XSK_ZYNQMP_EFUSEPS_MISC_USER_CTRL_USR_WRLK_4_MASK	0x00000010U
#define XSK_ZYNQMP_EFUSEPS_MISC_USER_CTRL_USR_WRLK_4_DEFVAL	0x0U

#define XSK_ZYNQMP_EFUSEPS_MISC_USER_CTRL_USR_WRLK_3_SHIFT	3U
#define XSK_ZYNQMP_EFUSEPS_MISC_USER_CTRL_USR_WRLK_3_WIDTH	1U
#define XSK_ZYNQMP_EFUSEPS_MISC_USER_CTRL_USR_WRLK_3_MASK	0x00000008U
#define XSK_ZYNQMP_EFUSEPS_MISC_USER_CTRL_USR_WRLK_3_DEFVAL	0x0U

#define XSK_ZYNQMP_EFUSEPS_MISC_USER_CTRL_USR_WRLK_2_SHIFT	2U
#define XSK_ZYNQMP_EFUSEPS_MISC_USER_CTRL_USR_WRLK_2_WIDTH	1U
#define XSK_ZYNQMP_EFUSEPS_MISC_USER_CTRL_USR_WRLK_2_MASK	0x00000004U
#define XSK_ZYNQMP_EFUSEPS_MISC_USER_CTRL_USR_WRLK_2_DEFVAL	0x0U

#define XSK_ZYNQMP_EFUSEPS_MISC_USER_CTRL_USR_WRLK_1_SHIFT	1U
#define XSK_ZYNQMP_EFUSEPS_MISC_USER_CTRL_USR_WRLK_1_WIDTH	1U
#define XSK_ZYNQMP_EFUSEPS_MISC_USER_CTRL_USR_WRLK_1_MASK	0x00000002U
#define XSK_ZYNQMP_EFUSEPS_MISC_USER_CTRL_USR_WRLK_1_DEFVAL	0x0U

#define XSK_ZYNQMP_EFUSEPS_MISC_USER_CTRL_USR_WRLK_0_SHIFT	0U
#define XSK_ZYNQMP_EFUSEPS_MISC_USER_CTRL_USR_WRLK_0_WIDTH	1U
#define XSK_ZYNQMP_EFUSEPS_MISC_USER_CTRL_USR_WRLK_0_MASK	0x00000001U
#define XSK_ZYNQMP_EFUSEPS_MISC_USER_CTRL_USR_WRLK_0_DEFVAL	0x0U
/*@}*/

/** @name PBR Boot error register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_PBR_BOOT_ERR_OFFSET		0x00001044U
#define XSK_ZYNQMP_EFUSEPS_PBR_BOOT_ERR_MASK		0x00000007U
#define XSK_ZYNQMP_EFUSEPS_PBR_BOOT_ERR_SHIFT		0U
/*@}*/

/** @name Xilinx specific register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_RESERVED_OFFSET			0x0000104CU
#define XSK_ZYNQMP_EFUSEPS_RESERVED1_MASK			0x0000FFFFU
#define XSK_ZYNQMP_EFUSEPS_RESERVED2_MASK			0xFFFF0000U
#define XSK_ZYNQMP_EFUSEPS_RESERVED_SHIFT			16U
/*@}*/

/** @name Puf CHASH register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_PUF_CHASH_OFFSET	0x00001050U
#define XSK_ZYNQMP_EFUSEPS_PUF_CHASH_RSTVAL	0x00000000U

#define XSK_ZYNQMP_EFUSEPS_PUF_CHASH_SHIFT	0U
#define XSK_ZYNQMP_EFUSEPS_PUF_CHASH_WIDTH	32U
#define XSK_ZYNQMP_EFUSEPS_PUF_CHASH_MASK	0xffffffffU
#define XSK_ZYNQMP_EFUSEPS_PUF_CHASH_DEFVAL	0x0U
/*@}*/

/** @name Puf MISC register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_PUF_MISC_OFFSET		0x00001054U
#define XSK_ZYNQMP_EFUSEPS_PUF_MISC_RSTVAL		0x00000000U

#define XSK_ZYNQMP_EFUSEPS_PUF_MISC_REG_DIS_SHIFT	31U
#define XSK_ZYNQMP_EFUSEPS_PUF_MISC_REG_DIS_WIDTH	1U
#define XSK_ZYNQMP_EFUSEPS_PUF_MISC_REG_DIS_MASK	0x80000000U
#define XSK_ZYNQMP_EFUSEPS_PUF_MISC_REG_DIS_DEFVAL	0x0U

#define XSK_ZYNQMP_EFUSEPS_PUF_MISC_SYN_WRLK_SHIFT	30U
#define XSK_ZYNQMP_EFUSEPS_PUF_MISC_SYN_WRLK_WIDTH	1U
#define XSK_ZYNQMP_EFUSEPS_PUF_MISC_SYN_WRLK_MASK	0x40000000U
#define XSK_ZYNQMP_EFUSEPS_PUF_MISC_SYN_WRLK_DEFVAL	0x0U

#define XSK_ZYNQMP_EFUSEPS_PUF_MISC_SYN_INVLD_SHIFT	29U
#define XSK_ZYNQMP_EFUSEPS_PUF_MISC_SYN_INVLD_WIDTH	1U
#define XSK_ZYNQMP_EFUSEPS_PUF_MISC_SYN_INVLD_MASK	0x20000000U
#define XSK_ZYNQMP_EFUSEPS_PUF_MISC_SYN_INVLD_DEFVAL	0x0U

#define XSK_ZYNQMP_EFUSEPS_PUF_MISC_RESERVED_SHIFT	28U
#define XSK_ZYNQMP_EFUSEPS_PUF_MISC_RESERVED_WIDTH	1U
#define XSK_ZYNQMP_EFUSEPS_PUF_MISC_RESERVED_MASK	0x10000000U
#define XSK_ZYNQMP_EFUSEPS_PUF_MISC_RESERVED_DEFVAL	0x0U

#define XSK_ZYNQMP_EFUSEPS_PUF_MISC_AUX_SHIFT		0U
#define XSK_ZYNQMP_EFUSEPS_PUF_MISC_AUX_WIDTH		24U
#define XSK_ZYNQMP_EFUSEPS_PUF_MISC_AUX_MASK		0x00ffffffU
#define XSK_ZYNQMP_EFUSEPS_PUF_MISC_AUX_DEFVAL		0x0U
/*@}*/

/** @name Secure control register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_OFFSET			0x00001058U
#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_RSTVAL			0x00000000U

#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_PPK1_INVLD_SHIFT		30U
#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_PPK1_INVLD_WIDTH		2U
#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_PPK1_INVLD_MASK		0xc0000000U
#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_PPK1_INVLD_DEFVAL		0x0U

#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_PPK1_WRLK_SHIFT		29U
#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_PPK1_WRLK_WIDTH		1U
#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_PPK1_WRLK_MASK		0x20000000U
#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_PPK1_WRLK_DEFVAL		0x0U

#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_PPK0_INVLD_SHIFT		27U
#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_PPK0_INVLD_WIDTH		2U
#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_PPK0_INVLD_MASK		0x18000000U
#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_PPK0_INVLD_DEFVAL		0x0U

#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_PPK0_WRLK_SHIFT		26U
#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_PPK0_WRLK_WIDTH		1U
#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_PPK0_WRLK_MASK		0x04000000U
#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_PPK0_WRLK_DEFVAL		0x0U

#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_RSA_EN_SHIFT		11U
#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_RSA_EN_WIDTH		15U
#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_RSA_EN_MASK			0x03FFF800U
#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_RSA_EN_DEFVAL		0x0U

#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_LOCK_SHIFT			10U
#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_LOCK_WIDTH			1U
#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_LOCK_MASK			0x00000400U
#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_LOCK_DEFVAL			0x0U

#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_PROG_GATE_2_SHIFT		9U
#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_PROG_GATE_2_WIDTH		1U
#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_PROG_GATE_2_MASK		0x00000200U
#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_PROG_GATE_2_DEFVAL		0x0U

#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_PROG_GATE_1_SHIFT		8U
#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_PROG_GATE_1_WIDTH		1U
#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_PROG_GATE_1_MASK		0x00000100U
#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_PROG_GATE_1_DEFVAL		0x0U

#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_PROG_GATE_0_SHIFT		7U
#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_PROG_GATE_0_WIDTH		1U
#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_PROG_GATE_0_MASK		0x00000080U
#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_PROG_GATE_0_DEFVAL		0x0U

#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_PROG_GATE_MASK			( \
				(u32)XSK_ZYNQMP_EFUSEPS_SEC_CTRL_PROG_GATE_0_MASK | \
				(u32)XSK_ZYNQMP_EFUSEPS_SEC_CTRL_PROG_GATE_1_MASK | \
				(u32)XSK_ZYNQMP_EFUSEPS_SEC_CTRL_PROG_GATE_2_MASK)

#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_DFT_DIS_SHIFT		6U
#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_DFT_DIS_WIDTH		1U
#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_DFT_DIS_MASK		0x00000040U
#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_DFT_DIS_DEFVAL		0x0U

#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_JTAG_DIS_SHIFT		5U
#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_JTAG_DIS_WIDTH		1U
#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_JTAG_DIS_MASK		0x00000020U
#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_JTAG_DIS_DEFVAL		0x0U

#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_ERR_DIS_SHIFT		4U
#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_ERR_DIS_WIDTH		1U
#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_ERR_DIS_MASK		0x00000010U
#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_ERR_DIS_DEFVAL		0x0U

#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_BBRAM_DIS_SHIFT		3U
#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_BBRAM_DIS_WIDTH		1U
#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_BBRAM_DIS_MASK		0x00000008U
#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_BBRAM_DIS_DEFVAL		0x0U

#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_ENC_ONLY_SHIFT		2U
#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_ENC_ONLY_WIDTH		1U
#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_ENC_ONLY_MASK		0x00000004U
#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_ENC_ONLY_DEFVAL		0x0U

#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_AES_WRLK_SHIFT		1U
#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_AES_WRLK_WIDTH		1U
#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_AES_WRLK_MASK		0x00000002U
#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_AES_WRLK_DEFVAL		0x0U

#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_AES_RDLK_SHIFT		0U
#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_AES_RDLK_WIDTH		1U
#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_AES_RDLK_MASK		0x00000001U
#define XSK_ZYNQMP_EFUSEPS_SEC_CTRL_AES_RDLK_DEFVAL		0x0U
/*@}*/

/** @name SPK ID register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_SPK_ID_OFFSET	0x0000105CU
#define XSK_ZYNQMP_EFUSEPS_SPK_ID_RSTVAL	0x00000000U

#define XSK_ZYNQMP_EFUSEPS_SPK_ID_SHIFT		0U
#define XSK_ZYNQMP_EFUSEPS_SPK_ID_WIDTH		32U
#define XSK_ZYNQMP_EFUSEPS_SPK_ID_MASK		0xffffffffU
#define XSK_ZYNQMP_EFUSEPS_SPK_ID_DEFVAL	0x0U
/*@}*/

/** @name PPK0_0 register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_PPK0_0_OFFSET	0x000010A0U
#define XSK_ZYNQMP_EFUSEPS_PPK0_0_RSTVAL	0x00000000U

#define XSK_ZYNQMP_EFUSEPS_PPK0_0_SHIFT		0U
#define XSK_ZYNQMP_EFUSEPS_PPK0_0_WIDTH		32U
#define XSK_ZYNQMP_EFUSEPS_PPK0_0_MASK		0xffffffffU
#define XSK_ZYNQMP_EFUSEPS_PPK0_0_DEFVAL	0x0U
/*@}*/

/** @name PPK0_1 register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_PPK0_1_OFFSET	0x000010A4U
#define XSK_ZYNQMP_EFUSEPS_PPK0_1_RSTVAL	0x00000000U

#define XSK_ZYNQMP_EFUSEPS_PPK0_1_SHIFT		0U
#define XSK_ZYNQMP_EFUSEPS_PPK0_1_WIDTH		32U
#define XSK_ZYNQMP_EFUSEPS_PPK0_1_MASK		0xffffffffU
#define XSK_ZYNQMP_EFUSEPS_PPK0_1_DEFVAL	0x0U
/*@}*/

/** @name PPK0_2 register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_PPK0_2_OFFSET	0x000010A8U
#define XSK_ZYNQMP_EFUSEPS_PPK0_2_RSTVAL	0x00000000U

#define XSK_ZYNQMP_EFUSEPS_PPK0_2_SHIFT		0U
#define XSK_ZYNQMP_EFUSEPS_PPK0_2_WIDTH		32U
#define XSK_ZYNQMP_EFUSEPS_PPK0_2_MASK		0xffffffffU
#define XSK_ZYNQMP_EFUSEPS_PPK0_2_DEFVAL	0x0U
/*@}*/

/** @name PPK0_3 register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_PPK0_3_OFFSET	0x000010ACU
#define XSK_ZYNQMP_EFUSEPS_PPK0_3_RSTVAL	0x00000000U

#define XSK_ZYNQMP_EFUSEPS_PPK0_3_SHIFT		0U
#define XSK_ZYNQMP_EFUSEPS_PPK0_3_WIDTH		32U
#define XSK_ZYNQMP_EFUSEPS_PPK0_3_MASK		0xffffffffU
#define XSK_ZYNQMP_EFUSEPS_PPK0_3_DEFVAL	0x0U
/*@}*/

/** @name PPK0_4 register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_PPK0_4_OFFSET	0x000010B0U
#define XSK_ZYNQMP_EFUSEPS_PPK0_4_RSTVAL	0x00000000U

#define XSK_ZYNQMP_EFUSEPS_PPK0_4_SHIFT		0U
#define XSK_ZYNQMP_EFUSEPS_PPK0_4_WIDTH		32U
#define XSK_ZYNQMP_EFUSEPS_PPK0_4_MASK		0xffffffffU
#define XSK_ZYNQMP_EFUSEPS_PPK0_4_DEFVAL	0x0U
/*@}*/

/** @name PPK0_5 register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_PPK0_5_OFFSET	0x000010B4U
#define XSK_ZYNQMP_EFUSEPS_PPK0_5_RSTVAL	0x00000000U

#define XSK_ZYNQMP_EFUSEPS_PPK0_5_SHIFT		0U
#define XSK_ZYNQMP_EFUSEPS_PPK0_5_WIDTH		32U
#define XSK_ZYNQMP_EFUSEPS_PPK0_5_MASK		0xffffffffU
#define XSK_ZYNQMP_EFUSEPS_PPK0_5_DEFVAL	0x0U
/*@}*/

/** @name PPK0_6 register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_PPK0_6_OFFSET	0x000010B8U
#define XSK_ZYNQMP_EFUSEPS_PPK0_6_RSTVAL	0x00000000U

#define XSK_ZYNQMP_EFUSEPS_PPK0_6_SHIFT		0U
#define XSK_ZYNQMP_EFUSEPS_PPK0_6_WIDTH		32U
#define XSK_ZYNQMP_EFUSEPS_PPK0_6_MASK		0xffffffffU
#define XSK_ZYNQMP_EFUSEPS_PPK0_6_DEFVAL	0x0U
/*@}*/

/** @name PPK0_7 register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_PPK0_7_OFFSET	0x000010BCU
#define XSK_ZYNQMP_EFUSEPS_PPK0_7_RSTVAL	0x00000000U

#define XSK_ZYNQMP_EFUSEPS_PPK0_7_SHIFT		0U
#define XSK_ZYNQMP_EFUSEPS_PPK0_7_WIDTH		32U
#define XSK_ZYNQMP_EFUSEPS_PPK0_7_MASK		0xffffffffU
#define XSK_ZYNQMP_EFUSEPS_PPK0_7_DEFVAL	0x0U
/*@}*/

/** @name PPK0_8 register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_PPK0_8_OFFSET	0x000010C0U
#define XSK_ZYNQMP_EFUSEPS_PPK0_8_RSTVAL	0x00000000U

#define XSK_ZYNQMP_EFUSEPS_PPK0_8_SHIFT		0U
#define XSK_ZYNQMP_EFUSEPS_PPK0_8_WIDTH		32U
#define XSK_ZYNQMP_EFUSEPS_PPK0_8_MASK		0xffffffffU
#define XSK_ZYNQMP_EFUSEPS_PPK0_8_DEFVAL	0x0U
/*@}*/

/** @name PPK0_9 register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_PPK0_9_OFFSET	0x000010C4U
#define XSK_ZYNQMP_EFUSEPS_PPK0_9_RSTVAL	0x00000000U

#define XSK_ZYNQMP_EFUSEPS_PPK0_9_SHIFT		0U
#define XSK_ZYNQMP_EFUSEPS_PPK0_9_WIDTH		32U
#define XSK_ZYNQMP_EFUSEPS_PPK0_9_MASK		0xffffffffU
#define XSK_ZYNQMP_EFUSEPS_PPK0_9_DEFVAL	0x0U
/*@}*/

/** @name PPK0_10 register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_PPK0_10_OFFSET	0x000010C8U
#define XSK_ZYNQMP_EFUSEPS_PPK0_10_RSTVAL	0x00000000U

#define XSK_ZYNQMP_EFUSEPS_PPK0_10_SHIFT	0U
#define XSK_ZYNQMP_EFUSEPS_PPK0_10_WIDTH	32U
#define XSK_ZYNQMP_EFUSEPS_PPK0_10_MASK		0xffffffffU
#define XSK_ZYNQMP_EFUSEPS_PPK0_10_DEFVAL	0x0U
/*@}*/

/** @name PPK0_11 register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_PPK0_11_OFFSET	0x000010CCU
#define XSK_ZYNQMP_EFUSEPS_PPK0_11_RSTVAL	0x00000000U

#define XSK_ZYNQMP_EFUSEPS_PPK0_11_SHIFT	0U
#define XSK_ZYNQMP_EFUSEPS_PPK0_11_WIDTH	32U
#define XSK_ZYNQMP_EFUSEPS_PPK0_11_MASK		0xffffffffU
#define XSK_ZYNQMP_EFUSEPS_PPK0_11_DEFVAL	0x0U
/*@}*/

/** @name PPK1_0 register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_PPK1_0_OFFSET	0x000010D0U
#define XSK_ZYNQMP_EFUSEPS_PPK1_0_RSTVAL	0x00000000U

#define XSK_ZYNQMP_EFUSEPS_PPK1_0_SHIFT		0U
#define XSK_ZYNQMP_EFUSEPS_PPK1_0_WIDTH		32U
#define XSK_ZYNQMP_EFUSEPS_PPK1_0_MASK		0xffffffffU
#define XSK_ZYNQMP_EFUSEPS_PPK1_0_DEFVAL	0x0U
/*@}*/

/** @name PPK1_1 register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_PPK1_1_OFFSET	0x000010D4U
#define XSK_ZYNQMP_EFUSEPS_PPK1_1_RSTVAL	0x00000000U

#define XSK_ZYNQMP_EFUSEPS_PPK1_1_SHIFT		0U
#define XSK_ZYNQMP_EFUSEPS_PPK1_1_WIDTH		32U
#define XSK_ZYNQMP_EFUSEPS_PPK1_1_MASK		0xffffffffU
#define XSK_ZYNQMP_EFUSEPS_PPK1_1_DEFVAL	0x0U
/*@}*/

/** @name PPK1_2 register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_PPK1_2_OFFSET	0x000010D8U
#define XSK_ZYNQMP_EFUSEPS_PPK1_2_RSTVAL	0x00000000U

#define XSK_ZYNQMP_EFUSEPS_PPK1_2_SHIFT		0U
#define XSK_ZYNQMP_EFUSEPS_PPK1_2_WIDTH		32U
#define XSK_ZYNQMP_EFUSEPS_PPK1_2_MASK		0xffffffffU
#define XSK_ZYNQMP_EFUSEPS_PPK1_2_DEFVAL	0x0U
/*@}*/

/** @name PPK1_3 register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_PPK1_3_OFFSET	0x000010DCU
#define XSK_ZYNQMP_EFUSEPS_PPK1_3_RSTVAL	0x00000000U

#define XSK_ZYNQMP_EFUSEPS_PPK1_3_SHIFT		0U
#define XSK_ZYNQMP_EFUSEPS_PPK1_3_WIDTH		32U
#define XSK_ZYNQMP_EFUSEPS_PPK1_3_MASK		0xffffffffU
#define XSK_ZYNQMP_EFUSEPS_PPK1_3_DEFVAL	0x0U
/*@}*/

/** @name PPK1_4 register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_PPK1_4_OFFSET	0x000010E0U
#define XSK_ZYNQMP_EFUSEPS_PPK1_4_RSTVAL	0x00000000U

#define XSK_ZYNQMP_EFUSEPS_PPK1_4_SHIFT		0U
#define XSK_ZYNQMP_EFUSEPS_PPK1_4_WIDTH		32U
#define XSK_ZYNQMP_EFUSEPS_PPK1_4_MASK		0xffffffffU
#define XSK_ZYNQMP_EFUSEPS_PPK1_4_DEFVAL	0x0U
/*@}*/

/** @name PPK1_5 register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_PPK1_5_OFFSET	0x000010E4U
#define XSK_ZYNQMP_EFUSEPS_PPK1_5_RSTVAL	0x00000000U

#define XSK_ZYNQMP_EFUSEPS_PPK1_5_SHIFT		0U
#define XSK_ZYNQMP_EFUSEPS_PPK1_5_WIDTH		32U
#define XSK_ZYNQMP_EFUSEPS_PPK1_5_MASK		0xffffffffU
#define XSK_ZYNQMP_EFUSEPS_PPK1_5_DEFVAL	0x0U
/*@}*/

/** @name PPK1_6 register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_PPK1_6_OFFSET	0x000010E8U
#define XSK_ZYNQMP_EFUSEPS_PPK1_6_RSTVAL	0x00000000U

#define XSK_ZYNQMP_EFUSEPS_PPK1_6_SHIFT		0U
#define XSK_ZYNQMP_EFUSEPS_PPK1_6_WIDTH		32U
#define XSK_ZYNQMP_EFUSEPS_PPK1_6_MASK		0xffffffffU
#define XSK_ZYNQMP_EFUSEPS_PPK1_6_DEFVAL	0x0U
/*@}*/

/** @name PPK1_7 register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_PPK1_7_OFFSET	0x000010ECU
#define XSK_ZYNQMP_EFUSEPS_PPK1_7_RSTVAL	0x00000000U

#define XSK_ZYNQMP_EFUSEPS_PPK1_7_SHIFT		0U
#define XSK_ZYNQMP_EFUSEPS_PPK1_7_WIDTH		32U
#define XSK_ZYNQMP_EFUSEPS_PPK1_7_MASK		0xffffffffU
#define XSK_ZYNQMP_EFUSEPS_PPK1_7_DEFVAL	0x0U
/*@}*/

/** @name PPK1_8 register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_PPK1_8_OFFSET	0x000010F0U
#define XSK_ZYNQMP_EFUSEPS_PPK1_8_RSTVAL	0x00000000U

#define XSK_ZYNQMP_EFUSEPS_PPK1_8_SHIFT		0U
#define XSK_ZYNQMP_EFUSEPS_PPK1_8_WIDTH		32U
#define XSK_ZYNQMP_EFUSEPS_PPK1_8_MASK		0xffffffffU
#define XSK_ZYNQMP_EFUSEPS_PPK1_8_DEFVAL	0x0U
/*@}*/

/** @name PPK1_8 register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_PPK1_9_OFFSET	0x000010F4U
#define XSK_ZYNQMP_EFUSEPS_PPK1_9_RSTVAL	0x00000000U

#define XSK_ZYNQMP_EFUSEPS_PPK1_9_SHIFT		0U
#define XSK_ZYNQMP_EFUSEPS_PPK1_9_WIDTH		32U
#define XSK_ZYNQMP_EFUSEPS_PPK1_9_MASK		0xffffffffU
#define XSK_ZYNQMP_EFUSEPS_PPK1_9_DEFVAL	0x0U
/*@}*/

/** @name PPK1_10 register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_PPK1_10_OFFSET	0x000010F8U
#define XSK_ZYNQMP_EFUSEPS_PPK1_10_RSTVAL	0x00000000U

#define XSK_ZYNQMP_EFUSEPS_PPK1_10_SHIFT	0U
#define XSK_ZYNQMP_EFUSEPS_PPK1_10_WIDTH	32U
#define XSK_ZYNQMP_EFUSEPS_PPK1_10_MASK		0xffffffffU
#define XSK_ZYNQMP_EFUSEPS_PPK1_10_DEFVAL	0x0U
/*@}*/

/** @name PPK1_11 register
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_PPK1_11_OFFSET	0x000010FCU
#define XSK_ZYNQMP_EFUSEPS_PPK1_11_RSTVAL	0x00000000U

#define XSK_ZYNQMP_EFUSEPS_PPK1_11_SHIFT	0U
#define XSK_ZYNQMP_EFUSEPS_PPK1_11_WIDTH	32U
#define XSK_ZYNQMP_EFUSEPS_PPK1_11_MASK		0xffffffffU
#define XSK_ZYNQMP_EFUSEPS_PPK1_11_DEFVAL	0x0U
/*@}*/

/** @name PUF masks and shifts
 * @{
 */
#define XSK_ZYNQMP_EFUSEPS_PUF_ROW_UPPER_MASK		0xFFFF0000U
#define XSK_ZYNQMP_EFUSEPS_PUF_ROW_LOWER_MASK		0x0000FFFFU
#define XSK_ZYNQMP_EFUSEPS_PUF_ROW_HALF_WORD_SHIFT	16U
/*@}*/

/** @name CSU module register offset and base address
 * @{
 */
#define XSK_ZYNQMP_CSU_BASEADDR			(0XFFCA0000U)

#define XSK_ZYNQMP_CSU_PUF_CMD			(0X4000U)
#define XSK_ZYNQMP_CSU_PUF_CFG0			(0X4004U)
#define XSK_ZYNQMP_CSU_PUF_CFG1			(0X4008U)
#define XSK_ZYNQMP_CSU_PUF_SHUT			(0X400CU)
#define XSK_ZYNQMP_CSU_PUF_STATUS		(0X4010U)
#define XSK_ZYNQMP_CSU_ISR				(0x0020U)

#define XSK_ZYNQMP_CSU_PUF_STATUS_OVERFLOW_MASK		(0X30000000U)
#define XSK_ZYNQMP_CSU_PUF_STATUS_AUX_MASK		(0X0FFFFFF0U)
#define XSK_ZYNQMP_CSU_PUF_STATUS_KEY_RDY_MASK		(0X00000008U)
#define XSK_ZYNQMP_CSU_PUF_STATUS_SYN_WRD_RDY_MASK	(0X00000001U)

#define XSK_ZYNQMP_CSU_PUF_WORD			(0X4018U)

/**
 * Register: CSU_PUF_TM_STATUS
 */
#define XSK_ZYNQMP_CSU_PUF_TM_STATUS		(0X4804U)
#define XSK_ZYNQMP_CSU_PUF_TM_STATUS_DN_MASK	(0X00000001U)

/**
 * Register: CSU_PUF_TM_UL
 */
#define XSK_ZYNQMP_CSU_PUF_TM_UL		(0X00004808U)

/**
 * Register: CSU_PUF_TM_LL
 */
#define XSK_ZYNQMP_CSU_PUF_TM_LL		(0X0000480CU)

/**
 * Register: CSU_PUF_TM_SW
 */
#define XSK_ZYNQMP_CSU_PUF_TM_SW		(0X00004810U)
/**
 * Register: CSU_PUF_TM_TR
 */
#define XSK_ZYNQMP_CSU_PUF_TM_TR		(0X00004814U)
#define XSK_ZYNQMP_CSU_PUF_TM_TR_US_MASK	(0X03000000U)
#define XSK_ZYNQMP_CSU_PUF_TM_TR_ER_MASK	(0X00FF0000U)
#define XSK_ZYNQMP_CSU_PUF_TM_TR_FRR_MASK	(0X00000001U)

#ifdef __cplusplus
}
#endif

#endif /* __XSK_EPS_ZYNQMP_HW_H__ */
