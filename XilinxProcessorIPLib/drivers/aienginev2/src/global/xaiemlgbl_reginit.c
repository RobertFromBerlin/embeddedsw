/******************************************************************************
*
* Copyright (C) 2005 - 2019 Xilinx, Inc.  All rights reserved.
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
******************************************************************************/

/*****************************************************************************/
/**
* @file xaie2gbl_reginit.c
* @{
*
* This file contains the instances of the register bit field definitions for the
* Core, Memory, NoC and PL module registers.
*
* <pre>
* MODIFICATION HISTORY:
*
* Ver   Who     Date     Changes
* ----- ------  -------- -----------------------------------------------------
* 1.0   Tejus   07/30/2019  Initial creation
* 1.1   Tejus   10/21/2019  Optimize stream switch data structures
* 1.2   Tejus   10/28/2019  Add pl interface register properties
* 1.3   Tejus   12/09/2019  Include correct header file to avoid cyclic
*			    dependancy
* 1.4   Tejus   03/16/2020  Seperate PlIf Module for SHIMPL and SHIMNOC Tiles
* 1.5   Tejus   03/16/2020  Add register properties for Mux/Demux registers
* 1.6   Tejus   03/17/2020  Add lock module properties
* 1.7   Tejus   03/21/2020  Add structure fields to stream switch module
*			    definition
* 1.8   Tejus   03/21/2020  Add register properties for stream switch slot
*			    registers
* 1.9   Tejus   03/23/2020  Organize header files in alphabetical order
* 2.0   Tejus   03/23/2020  Re-organize dma data structures
* </pre>
*
******************************************************************************/

/***************************** Include Files *********************************/
#include "xaie_dma_aieml.h"
#include "xaie_locks_aieml.h"
#include "xaiegbl_regdef.h"
#include "xaiemlgbl_params.h"

/************************** Constant Definitions *****************************/

/**************************** Type Definitions *******************************/

/**************************** Macro Definitions ******************************/

/************************** Variable Definitions *****************************/
/*
 * Global instance for Core module Core_Control register.
 */
const static XAie_RegCoreCtrl Aie2CoreCtrlReg =
{
	XAIE2GBL_CORE_MODULE_CORE_CONTROL,
	{XAIE2GBL_CORE_MODULE_CORE_CONTROL_ENABLE_LSB, XAIE2GBL_CORE_MODULE_CORE_CONTROL_ENABLE_MASK},
	{XAIE2GBL_CORE_MODULE_CORE_CONTROL_RESET_LSB, XAIE2GBL_CORE_MODULE_CORE_CONTROL_RESET_MASK}
};

/*
 * Global instance for Core module Core_Status register.
 */
const static XAie_RegCoreSts Aie2CoreStsReg =
{
	XAIE2GBL_CORE_MODULE_CORE_STATUS,
	{XAIE2GBL_CORE_MODULE_CORE_STATUS_CORE_DONE_LSB, XAIE2GBL_CORE_MODULE_CORE_STATUS_CORE_DONE_MASK},
	{XAIE2GBL_CORE_MODULE_CORE_STATUS_RESET_LSB, XAIE2GBL_CORE_MODULE_CORE_STATUS_RESET_MASK},
	{XAIE2GBL_CORE_MODULE_CORE_STATUS_ENABLE_LSB, XAIE2GBL_CORE_MODULE_CORE_STATUS_ENABLE_MASK}
};


const static XAie_DmaBdEnProp Aie2MemTileDmaBdEnProp =
{
	.NxtBd.Idx = 1U,
	.NxtBd.Lsb = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_1_NEXT_BD_LSB,
	.NxtBd.Mask = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_1_NEXT_BD_MASK,
	.UseNxtBd.Idx = 1U,
	.UseNxtBd.Lsb = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_1_USE_NEXT_BD_LSB,
	.UseNxtBd.Mask = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_1_USE_NEXT_BD_MASK,
	.ValidBd.Idx = 7U,
	.ValidBd.Lsb = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_7_VALID_BD_LSB,
	.ValidBd.Mask = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_7_VALID_BD_MASK,
	.OutofOrderBdId.Idx = 0U,
	.OutofOrderBdId.Lsb = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_0_OUT_OF_ORDER_BD_ID_LSB,
	.OutofOrderBdId.Mask = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_0_OUT_OF_ORDER_BD_ID_MASK,
};

const static XAie_DmaBdPkt Aie2MemTileDmaBdPktProp =
{
	.EnPkt.Idx = 0U,
	.EnPkt.Lsb = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_0_ENABLE_PACKET_LSB,
	.EnPkt.Mask = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_0_ENABLE_PACKET_MASK,
	.PktId.Idx = 0U,
	.PktId.Lsb = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_0_PACKET_ID_LSB,
	.PktId.Mask = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_0_PACKET_ID_MASK,
	.PktType.Idx = 0U,
	.PktType.Lsb = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_0_PACKET_TYPE_LSB,
	.PktType.Mask = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_0_PACKET_TYPE_MASK,
};

const static XAie_DmaBdLock Aie2MemTileDmaLockProp =
{
	.Aie2DmaLock.LckRelVal.Idx = 7U,
	.Aie2DmaLock.LckRelVal.Lsb = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_7_LOCK_REL_VALUE_LSB,
	.Aie2DmaLock.LckRelVal.Mask = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_7_LOCK_REL_VALUE_MASK,
	.Aie2DmaLock.LckRelId.Idx = 7U,
	.Aie2DmaLock.LckRelId.Lsb = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_7_LOCK_REL_ID_LSB,
	.Aie2DmaLock.LckRelId.Mask = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_7_LOCK_REL_ID_MASK,
	.Aie2DmaLock.LckAcqEn.Idx = 7U,
	.Aie2DmaLock.LckAcqEn.Lsb = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_7_LOCK_ACQ_ENABLE_LSB,
	.Aie2DmaLock.LckAcqEn.Mask = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_7_LOCK_ACQ_ENABLE_MASK,
	.Aie2DmaLock.LckAcqVal.Idx = 7U,
	.Aie2DmaLock.LckAcqVal.Lsb = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_7_LOCK_ACQ_VALUE_LSB,
	.Aie2DmaLock.LckAcqVal.Mask = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_7_LOCK_ACQ_VALUE_MASK,
	.Aie2DmaLock.LckAcqId.Idx = 7U,
	.Aie2DmaLock.LckAcqId.Lsb = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_7_LOCK_ACQ_ID_LSB,
	.Aie2DmaLock.LckAcqId.Mask = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_7_LOCK_ACQ_ID_MASK,
};

const static XAie_DmaBdBuffer Aie2MemTileBufferProp =
{
	.TileDmaBuff.BaseAddr.Idx = 1U,
	.TileDmaBuff.BaseAddr.Lsb = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_1_BASE_ADDRESS_LSB,
	.TileDmaBuff.BaseAddr.Mask = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_1_BASE_ADDRESS_MASK,
	.TileDmaBuff.BufferLen.Idx = 0U,
	.TileDmaBuff.BufferLen.Lsb = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_0_BUFFER_LENGTH_LSB,
	.TileDmaBuff.BufferLen.Mask = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_0_BUFFER_LENGTH_MASK,
};

const static XAie_DmaBdDoubleBuffer Aie2MemTileDoubleBufferProp = {0U};

const static XAie_DmaBdMultiDimAddr Aie2MemTileMultiDimProp =
{
	.Aie2MultiDimAddr.DmaDimProp[1U].StepSize.Idx = 3U,
	.Aie2MultiDimAddr.DmaDimProp[1U].StepSize.Lsb = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_3_D1_STEPSIZE_LSB,
	.Aie2MultiDimAddr.DmaDimProp[1U].StepSize.Mask = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_3_D1_STEPSIZE_MASK,
	.Aie2MultiDimAddr.DmaDimProp[0U].StepSize.Idx = 2U,
	.Aie2MultiDimAddr.DmaDimProp[0U].StepSize.Lsb = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_2_D0_STEPSIZE_LSB,
	.Aie2MultiDimAddr.DmaDimProp[0U].StepSize.Mask = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_2_D0_STEPSIZE_MASK,
	.Aie2MultiDimAddr.DmaDimProp[1U].Wrap.Idx = 3U,
	.Aie2MultiDimAddr.DmaDimProp[1U].Wrap.Lsb = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_3_D1_WRAP_LSB,
	.Aie2MultiDimAddr.DmaDimProp[1U].Wrap.Mask = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_3_D1_WRAP_MASK,
	.Aie2MultiDimAddr.DmaDimProp[0U].Wrap.Idx = 2U,
	.Aie2MultiDimAddr.DmaDimProp[0U].Wrap.Lsb = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_2_D0_WRAP_LSB,
	.Aie2MultiDimAddr.DmaDimProp[0U].Wrap.Mask = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_2_D0_WRAP_MASK,
	.Aie2MultiDimAddr.DmaDimProp[2U].StepSize.Idx = 4U,
	.Aie2MultiDimAddr.DmaDimProp[2U].StepSize.Lsb = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_4_D2_STEPSIZE_LSB,
	.Aie2MultiDimAddr.DmaDimProp[2U].StepSize.Mask = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_4_D2_STEPSIZE_MASK,
	.Aie2MultiDimAddr.DmaDimProp[2U].Wrap.Idx = 4U,
	.Aie2MultiDimAddr.DmaDimProp[2U].Wrap.Lsb = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_4_D2_WRAP_LSB,
	.Aie2MultiDimAddr.DmaDimProp[2U].Wrap.Mask = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_4_D2_WRAP_MASK,
	.Aie2MultiDimAddr.IterCurr.Idx = 6U,
	.Aie2MultiDimAddr.IterCurr.Lsb = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_6_ITERATION_CURRENT_LSB,
	.Aie2MultiDimAddr.IterCurr.Mask = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_6_ITERATION_CURRENT_MASK,
	.Aie2MultiDimAddr.Iter.Wrap.Idx = 6U,
	.Aie2MultiDimAddr.Iter.Wrap.Lsb = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_6_ITERATION_WRAP_LSB,
	.Aie2MultiDimAddr.Iter.Wrap.Mask = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_6_ITERATION_WRAP_MASK,
	.Aie2MultiDimAddr.Iter.StepSize.Idx = 6U,
	.Aie2MultiDimAddr.Iter.StepSize.Lsb = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_6_ITERATION_STEPSIZE_LSB,
	.Aie2MultiDimAddr.Iter.StepSize.Mask = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_6_ITERATION_STEPSIZE_MASK,
	.Aie2MultiDimAddr.DmaDimProp[3U].StepSize.Idx = 5U,
	.Aie2MultiDimAddr.DmaDimProp[3U].StepSize.Lsb = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_5_D3_STEPSIZE_LSB,
	.Aie2MultiDimAddr.DmaDimProp[3U].StepSize.Mask = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_5_D3_STEPSIZE_MASK,
};

const static XAie_DmaBdZeroPad Aie2MemTileZeroPadProp =
{
	.D0_ZeroBefore.Idx = 1U,
	.D0_ZeroBefore.Lsb = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_1_D0_ZERO_BEFORE_LSB,
	.D0_ZeroBefore.Mask = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_1_D0_ZERO_BEFORE_MASK,
	.D1_ZeroBefore.Idx = 3U,
	.D1_ZeroBefore.Lsb = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_3_D1_ZERO_BEFORE_LSB,
	.D1_ZeroBefore.Mask = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_3_D1_ZERO_BEFORE_MASK,
	.D2_ZeroBefore.Idx = 4U,
	.D2_ZeroBefore.Lsb = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_4_D2_ZERO_BEFORE_LSB,
	.D2_ZeroBefore.Mask = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_4_D2_ZERO_BEFORE_MASK,
	.D0_ZeroAfter.Idx = 5U,
	.D0_ZeroAfter.Lsb = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_5_D0_ZERO_AFTER_LSB,
	.D0_ZeroAfter.Mask = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_5_D0_ZERO_AFTER_MASK,
	.D1_ZeroAfter.Idx = 5U,
	.D1_ZeroAfter.Lsb = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_5_D1_ZERO_AFTER_LSB,
	.D1_ZeroAfter.Mask = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_5_D1_ZERO_AFTER_MASK,
	.D2_ZeroAfter.Idx = 5U,
	.D2_ZeroAfter.Lsb = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_5_D2_ZERO_AFTER_LSB,
	.D2_ZeroAfter.Mask = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_5_D2_ZERO_AFTER_MASK,
};

const static XAie_DmaBdCompression Aie2MemTileCompressionProp =
{
	.EnCompression.Idx = 4U,
	.EnCompression.Lsb = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_4_ENABLE_COMPRESSION_LSB,
	.EnCompression.Mask = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_4_ENABLE_COMPRESSION_MASK,
};

/* Data structure to capture register offsets and masks for Mem Tile Dma */
const static XAie_DmaBdProp Aie2MemTileDmaProp =
{
	.AddrAlignMask = 0x3,
	.AddrAlignShift = 0x2,
	.AddrMask = (1U << 20U) - 1U,
	.LenActualOffset = 0U,
	.Buffer = &Aie2MemTileBufferProp,
	.DoubleBuffer = &Aie2MemTileDoubleBufferProp,
	.Lock = &Aie2MemTileDmaLockProp,
	.Pkt = &Aie2MemTileDmaBdPktProp,
	.BdEn = &Aie2MemTileDmaBdEnProp,
	.AddrMode = &Aie2MemTileMultiDimProp,
	.ZeroPad = &Aie2MemTileZeroPadProp,
	.Compression = &Aie2MemTileCompressionProp,
	.SysProp = NULL
};

const static XAie_DmaChProp Aie2MemTileDmaChProp =
{
	.CtrlId.Idx = 0,
	.CtrlId.Lsb = XAIE2GBL_MEM_TILE_MODULE_DMA_S2MM_0_CTRL_CONTROLLER_ID_LSB,
	.CtrlId.Mask =XAIE2GBL_MEM_TILE_MODULE_DMA_S2MM_0_CTRL_CONTROLLER_ID_MASK ,
	.EnCompression.Idx = 0,
	.EnCompression.Lsb = XAIE2GBL_MEM_TILE_MODULE_DMA_S2MM_0_CTRL_DECOMPRESSION_ENABLE_LSB,
	.EnCompression.Mask = XAIE2GBL_MEM_TILE_MODULE_DMA_S2MM_0_CTRL_DECOMPRESSION_ENABLE_MASK,
	.EnOutofOrder.Idx = 0,
	.EnOutofOrder.Lsb = XAIE2GBL_MEM_TILE_MODULE_DMA_S2MM_0_CTRL_ENABLE_OUT_OF_ORDER_LSB,
	.EnOutofOrder.Mask = XAIE2GBL_MEM_TILE_MODULE_DMA_S2MM_0_CTRL_ENABLE_OUT_OF_ORDER_MASK,
	.Reset.Idx = 0,
	.Reset.Lsb = XAIE2GBL_MEM_TILE_MODULE_DMA_S2MM_0_CTRL_RESET_LSB,
	.Reset.Mask = XAIE2GBL_MEM_TILE_MODULE_DMA_S2MM_0_CTRL_RESET_MASK,
	.EnToken.Idx = 1,
	.EnToken.Lsb = XAIE2GBL_MEM_TILE_MODULE_DMA_S2MM_0_START_QUEUE_ENABLE_TOKEN_ISSUE_LSB,
	.EnToken.Mask = XAIE2GBL_MEM_TILE_MODULE_DMA_S2MM_0_START_QUEUE_ENABLE_TOKEN_ISSUE_MASK,
	.RptCount.Idx = 1,
	.RptCount.Lsb = XAIE2GBL_MEM_TILE_MODULE_DMA_S2MM_0_START_QUEUE_REPEAT_COUNT_LSB,
	.RptCount.Mask = XAIE2GBL_MEM_TILE_MODULE_DMA_S2MM_0_START_QUEUE_REPEAT_COUNT_MASK,
	.StartBd.Idx = 1,
	.StartBd.Lsb = XAIE2GBL_MEM_TILE_MODULE_DMA_S2MM_0_START_QUEUE_START_BD_ID_LSB,
	.StartBd.Mask = XAIE2GBL_MEM_TILE_MODULE_DMA_S2MM_0_START_QUEUE_START_BD_ID_MASK,
	.PauseStream = {0U},
	.PauseMem = {0U},
	.Enable = {0U},
};

/* Mem Tile Dma Module */
const static XAie_DmaMod Aie2MemTileDmaMod =
{
	.BaseAddr = XAIE2GBL_MEM_TILE_MODULE_DMA_BD0_0,
	.IdxOffset = 0x20,  /* This is the offset between each BD */
	.NumBds = 48,	   /* Number of BDs for AIE2 Tile DMA */
	.NumLocks = 64,
	.NumAddrDim = 4U,
	.DoubleBuffering = XAIE_FEATURE_UNAVAILABLE,
	.Compression = XAIE_FEATURE_UNAVAILABLE,
	.ZeroPadding = XAIE_FEATURE_UNAVAILABLE,
	.OutofOrderBdId = XAIE_FEATURE_AVAILABLE,
	.InterleaveMode = XAIE_FEATURE_UNAVAILABLE,
	.ChCtrlBase = XAIE2GBL_MEM_TILE_MODULE_DMA_S2MM_0_CTRL,
	.NumChannels = 6,  /* number of s2mm/mm2s channels */
	.ChIdxOffset = 0x8,  /* This is the offset between each channel */
	.BdProp = &Aie2MemTileDmaProp,
	.ChProp = &Aie2MemTileDmaChProp,
	.DmaBdInit = &_XAieMl_MemTileDmaInit,
	.SetLock = &_XAieMl_DmaSetLock,
	.SetIntrleave = NULL,
	.SetMultiDim = &_XAieMl_DmaSetMultiDim,
	.WriteBd = &_XAieMl_MemTileDmaWriteBd
};

const static XAie_DmaBdEnProp Aie2TileDmaBdEnProp =
{
	.NxtBd.Idx = 5U,
	.NxtBd.Lsb = XAIE2GBL_MEMORY_MODULE_DMA_BD0_5_NEXT_BD_LSB,
	.NxtBd.Mask = XAIE2GBL_MEMORY_MODULE_DMA_BD0_5_NEXT_BD_MASK,
	.UseNxtBd.Idx = 5U,
	.UseNxtBd.Lsb = XAIE2GBL_MEMORY_MODULE_DMA_BD0_5_USE_NEXT_BD_LSB,
	.UseNxtBd.Mask = XAIE2GBL_MEMORY_MODULE_DMA_BD0_5_USE_NEXT_BD_MASK,
	.ValidBd.Idx = 5U,
	.ValidBd.Lsb = XAIE2GBL_MEMORY_MODULE_DMA_BD0_5_VALID_BD_LSB,
	.ValidBd.Mask = XAIE2GBL_MEMORY_MODULE_DMA_BD0_5_VALID_BD_MASK,
	.OutofOrderBdId.Idx = 1U,
	.OutofOrderBdId.Lsb = XAIE2GBL_MEMORY_MODULE_DMA_BD0_1_OUT_OF_ORDER_BD_ID_LSB,
	.OutofOrderBdId.Mask = XAIE2GBL_MEMORY_MODULE_DMA_BD0_1_OUT_OF_ORDER_BD_ID_MASK,
};

const static XAie_DmaBdPkt Aie2TileDmaBdPktProp =
{
	.EnPkt.Idx = 1U,
	.EnPkt.Lsb = XAIE2GBL_MEMORY_MODULE_DMA_BD0_1_ENABLE_PACKET_LSB,
	.EnPkt.Mask = XAIE2GBL_MEMORY_MODULE_DMA_BD0_1_ENABLE_PACKET_MASK,
	.PktId.Idx = 1U,
	.PktId.Lsb = XAIE2GBL_MEMORY_MODULE_DMA_BD0_1_PACKET_ID_LSB,
	.PktId.Mask = XAIE2GBL_MEMORY_MODULE_DMA_BD0_1_PACKET_ID_MASK,
	.PktType.Idx = 1U,
	.PktType.Lsb = XAIE2GBL_MEMORY_MODULE_DMA_BD0_1_PACKET_TYPE_LSB,
	.PktType.Mask = XAIE2GBL_MEMORY_MODULE_DMA_BD0_1_PACKET_TYPE_MASK,
};

const static XAie_DmaBdLock Aie2TileDmaLockProp =
{
	.Aie2DmaLock.LckRelVal.Idx = 5U,
	.Aie2DmaLock.LckRelVal.Lsb = XAIE2GBL_MEMORY_MODULE_DMA_BD0_5_LOCK_REL_VALUE_LSB,
	.Aie2DmaLock.LckRelVal.Mask = XAIE2GBL_MEMORY_MODULE_DMA_BD0_5_LOCK_REL_VALUE_MASK,
	.Aie2DmaLock.LckRelId.Idx = 5U,
	.Aie2DmaLock.LckRelId.Lsb = XAIE2GBL_MEMORY_MODULE_DMA_BD0_5_LOCK_REL_ID_LSB,
	.Aie2DmaLock.LckRelId.Mask = XAIE2GBL_MEMORY_MODULE_DMA_BD0_5_LOCK_REL_ID_MASK,
	.Aie2DmaLock.LckAcqEn.Idx = 5U,
	.Aie2DmaLock.LckAcqEn.Lsb = XAIE2GBL_MEMORY_MODULE_DMA_BD0_5_LOCK_ACQ_ENABLE_LSB,
	.Aie2DmaLock.LckAcqEn.Mask = XAIE2GBL_MEMORY_MODULE_DMA_BD0_5_LOCK_ACQ_ENABLE_MASK,
	.Aie2DmaLock.LckAcqVal.Idx = 5U,
	.Aie2DmaLock.LckAcqVal.Lsb = XAIE2GBL_MEMORY_MODULE_DMA_BD0_5_LOCK_ACQ_VALUE_LSB,
	.Aie2DmaLock.LckAcqVal.Mask = XAIE2GBL_MEMORY_MODULE_DMA_BD0_5_LOCK_ACQ_VALUE_MASK,
	.Aie2DmaLock.LckAcqId.Idx = 5U,
	.Aie2DmaLock.LckAcqId.Lsb = XAIE2GBL_MEMORY_MODULE_DMA_BD0_5_LOCK_ACQ_ID_LSB,
	.Aie2DmaLock.LckAcqId.Mask = XAIE2GBL_MEMORY_MODULE_DMA_BD0_5_LOCK_ACQ_ID_MASK,
};

const static XAie_DmaBdBuffer Aie2TileDmaBufferProp =
{
	.TileDmaBuff.BaseAddr.Idx = 0U,
	.TileDmaBuff.BaseAddr.Lsb = XAIE2GBL_MEMORY_MODULE_DMA_BD0_0_BASE_ADDRESS_LSB,
	.TileDmaBuff.BaseAddr.Mask = XAIE2GBL_MEMORY_MODULE_DMA_BD0_0_BASE_ADDRESS_MASK,
	.TileDmaBuff.BufferLen.Idx = 0U,
	.TileDmaBuff.BufferLen.Lsb = XAIE2GBL_MEMORY_MODULE_DMA_BD0_0_BUFFER_LENGTH_LSB,
	.TileDmaBuff.BufferLen.Mask = XAIE2GBL_MEMORY_MODULE_DMA_BD0_0_BUFFER_LENGTH_MASK,
};

const static XAie_DmaBdDoubleBuffer Aie2TileDmaDoubleBufferProp = {0U};

const static XAie_DmaBdMultiDimAddr Aie2TileDmaMultiDimProp =
{
	.Aie2MultiDimAddr.DmaDimProp[0U].StepSize.Idx = 2U,
	.Aie2MultiDimAddr.DmaDimProp[0U].StepSize.Lsb = XAIE2GBL_MEMORY_MODULE_DMA_BD0_2_D0_STEPSIZE_LSB,
	.Aie2MultiDimAddr.DmaDimProp[0U].StepSize.Mask = XAIE2GBL_MEMORY_MODULE_DMA_BD0_2_D0_STEPSIZE_MASK,
	.Aie2MultiDimAddr.DmaDimProp[0U].Wrap.Idx = 3U,
	.Aie2MultiDimAddr.DmaDimProp[0U].Wrap.Lsb = XAIE2GBL_MEMORY_MODULE_DMA_BD0_3_D0_WRAP_LSB,
	.Aie2MultiDimAddr.DmaDimProp[0U].Wrap.Mask = XAIE2GBL_MEMORY_MODULE_DMA_BD0_3_D0_WRAP_MASK,
	.Aie2MultiDimAddr.DmaDimProp[1U].StepSize.Idx = 2U,
	.Aie2MultiDimAddr.DmaDimProp[1U].StepSize.Lsb = XAIE2GBL_MEMORY_MODULE_DMA_BD0_2_D1_STEPSIZE_LSB,
	.Aie2MultiDimAddr.DmaDimProp[1U].StepSize.Mask = XAIE2GBL_MEMORY_MODULE_DMA_BD0_2_D1_STEPSIZE_MASK,
	.Aie2MultiDimAddr.DmaDimProp[1U].Wrap.Idx = 3U,
	.Aie2MultiDimAddr.DmaDimProp[1U].Wrap.Lsb = XAIE2GBL_MEMORY_MODULE_DMA_BD0_3_D1_WRAP_LSB,
	.Aie2MultiDimAddr.DmaDimProp[1U].Wrap.Mask = XAIE2GBL_MEMORY_MODULE_DMA_BD0_3_D1_WRAP_MASK,
	.Aie2MultiDimAddr.DmaDimProp[2U].StepSize.Idx = 3U,
	.Aie2MultiDimAddr.DmaDimProp[2U].StepSize.Lsb = XAIE2GBL_MEMORY_MODULE_DMA_BD0_3_D2_STEPSIZE_LSB,
	.Aie2MultiDimAddr.DmaDimProp[2U].StepSize.Mask = XAIE2GBL_MEMORY_MODULE_DMA_BD0_3_D2_STEPSIZE_MASK,
	.Aie2MultiDimAddr.IterCurr.Idx = 4U,
	.Aie2MultiDimAddr.IterCurr.Lsb = XAIE2GBL_MEMORY_MODULE_DMA_BD0_4_ITERATION_CURRENT_LSB,
	.Aie2MultiDimAddr.IterCurr.Mask = XAIE2GBL_MEMORY_MODULE_DMA_BD0_4_ITERATION_CURRENT_MASK,
	.Aie2MultiDimAddr.Iter.Wrap.Idx = 4U,
	.Aie2MultiDimAddr.Iter.Wrap.Lsb = XAIE2GBL_MEMORY_MODULE_DMA_BD0_4_ITERATION_WRAP_LSB,
	.Aie2MultiDimAddr.Iter.Wrap.Mask = XAIE2GBL_MEMORY_MODULE_DMA_BD0_4_ITERATION_WRAP_MASK,
	.Aie2MultiDimAddr.Iter.StepSize.Idx = 4U,
	.Aie2MultiDimAddr.Iter.StepSize.Lsb = XAIE2GBL_MEMORY_MODULE_DMA_BD0_4_ITERATION_STEPSIZE_LSB,
	.Aie2MultiDimAddr.Iter.StepSize.Mask = XAIE2GBL_MEMORY_MODULE_DMA_BD0_4_ITERATION_STEPSIZE_MASK,
	.Aie2MultiDimAddr.DmaDimProp[2U].Wrap = {0U},
	.Aie2MultiDimAddr.DmaDimProp[3U].StepSize = {0U}
};

const static XAie_DmaBdCompression Aie2TileDmaCompressionProp =
{
	.EnCompression.Idx = 1U,
	.EnCompression.Lsb = XAIE2GBL_MEMORY_MODULE_DMA_BD0_1_ENABLE_COMPRESSION_LSB,
	.EnCompression.Mask = XAIE2GBL_MEMORY_MODULE_DMA_BD0_1_ENABLE_COMPRESSION_MASK,
};

/* Data structure to capture register offsets and masks for Tile Dma */
const static XAie_DmaBdProp Aie2TileDmaProp =
{
	.AddrAlignMask = 0x3,
	.AddrAlignShift = 0x2,
	.AddrMask = (1U << 17U) - 1U,
	.LenActualOffset = 0U,
	.Buffer = &Aie2TileDmaBufferProp,
	.DoubleBuffer = &Aie2TileDmaDoubleBufferProp,
	.Lock = &Aie2TileDmaLockProp,
	.Pkt = &Aie2TileDmaBdPktProp,
	.BdEn = &Aie2TileDmaBdEnProp,
	.AddrMode = &Aie2TileDmaMultiDimProp,
	.ZeroPad = NULL,
	.Compression = &Aie2TileDmaCompressionProp,
	.SysProp = NULL
};

/* Data structure to capture register offsets and masks for Mem Tile and
 * Tile Dma Channels
 */
const static XAie_DmaChProp Aie2DmaChProp =
{
	.CtrlId.Idx = 0,
	.CtrlId.Lsb = XAIE2GBL_MEMORY_MODULE_DMA_S2MM_0_CTRL_CONTROLLER_ID_LSB,
	.CtrlId.Mask =XAIE2GBL_MEMORY_MODULE_DMA_S2MM_0_CTRL_CONTROLLER_ID_MASK ,
	.EnCompression.Idx = 0,
	.EnCompression.Lsb = XAIE2GBL_MEMORY_MODULE_DMA_S2MM_0_CTRL_DECOMPRESSION_ENABLE_LSB,
	.EnCompression.Mask = XAIE2GBL_MEMORY_MODULE_DMA_S2MM_0_CTRL_DECOMPRESSION_ENABLE_MASK,
	.EnOutofOrder.Idx = 0,
	.EnOutofOrder.Lsb = XAIE2GBL_MEMORY_MODULE_DMA_S2MM_0_CTRL_ENABLE_OUT_OF_ORDER_LSB,
	.EnOutofOrder.Mask = XAIE2GBL_MEMORY_MODULE_DMA_S2MM_0_CTRL_ENABLE_OUT_OF_ORDER_MASK,
	.Reset.Idx = 0,
	.Reset.Lsb = XAIE2GBL_MEMORY_MODULE_DMA_S2MM_0_CTRL_RESET_LSB,
	.Reset.Mask = XAIE2GBL_MEMORY_MODULE_DMA_S2MM_0_CTRL_RESET_MASK,
	.EnToken.Idx = 1,
	.EnToken.Lsb = XAIE2GBL_MEMORY_MODULE_DMA_S2MM_0_START_QUEUE_ENABLE_TOKEN_ISSUE_LSB,
	.EnToken.Mask = XAIE2GBL_MEMORY_MODULE_DMA_S2MM_0_START_QUEUE_ENABLE_TOKEN_ISSUE_MASK,
	.RptCount.Idx = 1,
	.RptCount.Lsb = XAIE2GBL_MEMORY_MODULE_DMA_S2MM_0_START_QUEUE_REPEAT_COUNT_LSB,
	.RptCount.Mask = XAIE2GBL_MEMORY_MODULE_DMA_S2MM_0_START_QUEUE_REPEAT_COUNT_MASK,
	.StartBd.Idx = 1,
	.StartBd.Lsb = XAIE2GBL_MEMORY_MODULE_DMA_S2MM_0_START_QUEUE_START_BD_ID_LSB,
	.StartBd.Mask = XAIE2GBL_MEMORY_MODULE_DMA_S2MM_0_START_QUEUE_START_BD_ID_MASK,
	.PauseStream = {0U},
	.PauseMem = {0U},
	.Enable = {0U},
};

/* Tile Dma Module */
const static XAie_DmaMod Aie2TileDmaMod =
{
	.BaseAddr = XAIE2GBL_MEMORY_MODULE_DMA_BD0_0,
	.IdxOffset = 0x20,  	/* This is the offset between each BD */
	.NumBds = 16U,	   	/* Number of BDs for AIE2 Tile DMA */
	.NumLocks = 16U,
	.NumAddrDim = 3U,
	.DoubleBuffering = XAIE_FEATURE_UNAVAILABLE,
	.Compression = XAIE_FEATURE_AVAILABLE,
	.ZeroPadding = XAIE_FEATURE_UNAVAILABLE,
	.OutofOrderBdId = XAIE_FEATURE_AVAILABLE,
	.InterleaveMode = XAIE_FEATURE_UNAVAILABLE,
	.ChCtrlBase = XAIE2GBL_MEMORY_MODULE_DMA_S2MM_0_CTRL,
	.NumChannels = 2U,  /* Number of s2mm/mm2s channels */
	.ChIdxOffset = 0x8,  /* This is the offset between each channel */
	.BdProp = &Aie2TileDmaProp,
	.ChProp = &Aie2DmaChProp,
	.DmaBdInit = &_XAieMl_TileDmaInit,
	.SetLock = &_XAieMl_DmaSetLock,
	.SetIntrleave = NULL,
	.SetMultiDim = &_XAieMl_DmaSetMultiDim,
	.WriteBd = &_XAieMl_TileDmaWriteBd
};

const static XAie_DmaBdEnProp Aie2ShimDmaBdEnProp =
{
	.NxtBd.Idx = 7U,
	.NxtBd.Lsb = XAIE2GBL_NOC_MODULE_DMA_BD0_7_NEXT_BD_LSB,
	.NxtBd.Mask = XAIE2GBL_NOC_MODULE_DMA_BD0_7_NEXT_BD_MASK,
	.UseNxtBd.Idx = 7U,
	.UseNxtBd.Lsb = XAIE2GBL_NOC_MODULE_DMA_BD0_7_USE_NEXT_BD_LSB,
	.UseNxtBd.Mask = XAIE2GBL_NOC_MODULE_DMA_BD0_7_USE_NEXT_BD_MASK,
	.ValidBd.Idx = 7U,
	.ValidBd.Lsb = XAIE2GBL_NOC_MODULE_DMA_BD0_7_VALID_BD_LSB,
	.ValidBd.Mask = XAIE2GBL_NOC_MODULE_DMA_BD0_7_VALID_BD_MASK,
	.OutofOrderBdId.Idx = 2U,
	.OutofOrderBdId.Lsb = XAIE2GBL_NOC_MODULE_DMA_BD0_2_OUT_OF_ORDER_BD_ID_LSB,
	.OutofOrderBdId.Mask = XAIE2GBL_NOC_MODULE_DMA_BD0_2_OUT_OF_ORDER_BD_ID_MASK,
};

const static XAie_DmaBdPkt Aie2ShimDmaBdPktProp =
{
	.EnPkt.Idx = 2U,
	.EnPkt.Lsb = XAIE2GBL_NOC_MODULE_DMA_BD0_2_ENABLE_PACKET_LSB,
	.EnPkt.Mask = XAIE2GBL_NOC_MODULE_DMA_BD0_2_ENABLE_PACKET_MASK,
	.PktId.Idx = 2U,
	.PktId.Lsb = XAIE2GBL_NOC_MODULE_DMA_BD0_2_PACKET_ID_LSB,
	.PktId.Mask = XAIE2GBL_NOC_MODULE_DMA_BD0_2_PACKET_ID_MASK,
	.PktType.Idx = 2U,
	.PktType.Lsb = XAIE2GBL_NOC_MODULE_DMA_BD0_2_PACKET_TYPE_LSB,
	.PktType.Mask = XAIE2GBL_NOC_MODULE_DMA_BD0_2_PACKET_TYPE_MASK,
};

const static XAie_DmaBdLock Aie2ShimDmaLockProp =
{
	.Aie2DmaLock.LckRelVal.Idx = 7U,
	.Aie2DmaLock.LckRelVal.Lsb = XAIE2GBL_NOC_MODULE_DMA_BD0_7_LOCK_REL_VALUE_LSB,
	.Aie2DmaLock.LckRelVal.Mask = XAIE2GBL_NOC_MODULE_DMA_BD0_7_LOCK_REL_VALUE_MASK,
	.Aie2DmaLock.LckRelId.Idx = 7U,
	.Aie2DmaLock.LckRelId.Lsb = XAIE2GBL_NOC_MODULE_DMA_BD0_7_LOCK_REL_ID_LSB,
	.Aie2DmaLock.LckRelId.Mask = XAIE2GBL_NOC_MODULE_DMA_BD0_7_LOCK_REL_ID_MASK,
	.Aie2DmaLock.LckAcqEn.Idx = 7U,
	.Aie2DmaLock.LckAcqEn.Lsb = XAIE2GBL_NOC_MODULE_DMA_BD0_7_LOCK_ACQ_ENABLE_LSB,
	.Aie2DmaLock.LckAcqEn.Mask = XAIE2GBL_NOC_MODULE_DMA_BD0_7_LOCK_ACQ_ENABLE_MASK,
	.Aie2DmaLock.LckAcqVal.Idx = 7U,
	.Aie2DmaLock.LckAcqVal.Lsb = XAIE2GBL_NOC_MODULE_DMA_BD0_7_LOCK_ACQ_VALUE_LSB,
	.Aie2DmaLock.LckAcqVal.Mask = XAIE2GBL_NOC_MODULE_DMA_BD0_7_LOCK_ACQ_VALUE_MASK,
	.Aie2DmaLock.LckAcqId.Idx = 7U,
	.Aie2DmaLock.LckAcqId.Lsb = XAIE2GBL_NOC_MODULE_DMA_BD0_7_LOCK_ACQ_ID_LSB,
	.Aie2DmaLock.LckAcqId.Mask = XAIE2GBL_NOC_MODULE_DMA_BD0_7_LOCK_ACQ_ID_MASK,
};

const static XAie_DmaBdBuffer Aie2ShimDmaBufferProp =
{
	.ShimDmaBuff.AddrLow.Idx = 1U,
	.ShimDmaBuff.AddrLow.Lsb = XAIE2GBL_NOC_MODULE_DMA_BD0_1_BASE_ADDRESS_LOW_LSB,
	.ShimDmaBuff.AddrLow.Mask = XAIE2GBL_NOC_MODULE_DMA_BD0_1_BASE_ADDRESS_LOW_MASK,
	.ShimDmaBuff.AddrHigh.Idx = 2U,
	.ShimDmaBuff.AddrHigh.Lsb = XAIE2GBL_NOC_MODULE_DMA_BD0_2_BASE_ADDRESS_HIGH_LSB,
	.ShimDmaBuff.AddrHigh.Mask = XAIE2GBL_NOC_MODULE_DMA_BD0_2_BASE_ADDRESS_HIGH_MASK,
	.ShimDmaBuff.BufferLen.Idx = 0U,
	.ShimDmaBuff.BufferLen.Lsb = XAIE2GBL_NOC_MODULE_DMA_BD0_0_BUFFER_LENGTH_LSB,
	.ShimDmaBuff.BufferLen.Mask = XAIE2GBL_NOC_MODULE_DMA_BD0_0_BUFFER_LENGTH_MASK,
};

const static XAie_DmaBdDoubleBuffer Aie2ShimDmaDoubleBufferProp = {0U};

const static XAie_DmaBdMultiDimAddr Aie2ShimDmaMultiDimProp =
{
	.Aie2MultiDimAddr.DmaDimProp[0U].StepSize.Idx = 3U,
	.Aie2MultiDimAddr.DmaDimProp[0U].StepSize.Lsb = XAIE2GBL_NOC_MODULE_DMA_BD0_3_D0_STEPSIZE_LSB,
	.Aie2MultiDimAddr.DmaDimProp[0U].StepSize.Mask = XAIE2GBL_NOC_MODULE_DMA_BD0_3_D0_STEPSIZE_MASK,
	.Aie2MultiDimAddr.DmaDimProp[0U].Wrap.Idx = 3U,
	.Aie2MultiDimAddr.DmaDimProp[0U].Wrap.Lsb = XAIE2GBL_NOC_MODULE_DMA_BD0_3_D0_WRAP_LSB,
	.Aie2MultiDimAddr.DmaDimProp[0U].Wrap.Mask = XAIE2GBL_NOC_MODULE_DMA_BD0_3_D0_WRAP_MASK,
	.Aie2MultiDimAddr.DmaDimProp[1U].StepSize.Idx =3U ,
	.Aie2MultiDimAddr.DmaDimProp[1U].StepSize.Lsb = XAIE2GBL_NOC_MODULE_DMA_BD0_4_D1_STEPSIZE_LSB,
	.Aie2MultiDimAddr.DmaDimProp[1U].StepSize.Mask = XAIE2GBL_NOC_MODULE_DMA_BD0_4_D1_STEPSIZE_MASK,
	.Aie2MultiDimAddr.DmaDimProp[1U].Wrap.Idx = 3U,
	.Aie2MultiDimAddr.DmaDimProp[1U].Wrap.Lsb = XAIE2GBL_NOC_MODULE_DMA_BD0_4_D1_WRAP_LSB,
	.Aie2MultiDimAddr.DmaDimProp[1U].Wrap.Mask = XAIE2GBL_NOC_MODULE_DMA_BD0_4_D1_WRAP_MASK,
	.Aie2MultiDimAddr.DmaDimProp[2U].StepSize.Idx = 5U,
	.Aie2MultiDimAddr.DmaDimProp[2U].StepSize.Lsb = XAIE2GBL_NOC_MODULE_DMA_BD0_5_D2_STEPSIZE_LSB,
	.Aie2MultiDimAddr.DmaDimProp[2U].StepSize.Mask = XAIE2GBL_NOC_MODULE_DMA_BD0_5_D2_STEPSIZE_MASK,
	.Aie2MultiDimAddr.IterCurr.Idx = 6U,
	.Aie2MultiDimAddr.IterCurr.Lsb = XAIE2GBL_NOC_MODULE_DMA_BD0_6_ITERATION_CURRENT_LSB,
	.Aie2MultiDimAddr.IterCurr.Mask = XAIE2GBL_NOC_MODULE_DMA_BD0_6_ITERATION_CURRENT_MASK,
	.Aie2MultiDimAddr.Iter.Wrap.Idx = 6U,
	.Aie2MultiDimAddr.Iter.Wrap.Lsb = XAIE2GBL_NOC_MODULE_DMA_BD0_6_ITERATION_WRAP_LSB,
	.Aie2MultiDimAddr.Iter.Wrap.Mask = XAIE2GBL_NOC_MODULE_DMA_BD0_6_ITERATION_WRAP_MASK,
	.Aie2MultiDimAddr.Iter.StepSize.Idx = 6U,
	.Aie2MultiDimAddr.Iter.StepSize.Lsb = XAIE2GBL_NOC_MODULE_DMA_BD0_6_ITERATION_STEPSIZE_LSB,
	.Aie2MultiDimAddr.Iter.StepSize.Mask = XAIE2GBL_NOC_MODULE_DMA_BD0_6_ITERATION_STEPSIZE_MASK,
	.Aie2MultiDimAddr.DmaDimProp[2U].Wrap = {0U},
	.Aie2MultiDimAddr.DmaDimProp[3U].StepSize = {0U}
};

const static XAie_DmaSysProp Aie2ShimDmaSysProp =
{
	.SMID.Idx = 5U,
	.SMID.Lsb = XAIE2GBL_NOC_MODULE_DMA_BD0_5_SMID_LSB,
	.SMID.Mask = XAIE2GBL_NOC_MODULE_DMA_BD0_5_SMID_MASK,
	.BurstLen.Idx = 4U,
	.BurstLen.Lsb = XAIE2GBL_NOC_MODULE_DMA_BD0_4_BURST_LENGTH_LSB,
	.BurstLen.Mask = XAIE2GBL_NOC_MODULE_DMA_BD0_4_BURST_LENGTH_MASK,
	.AxQos.Idx = 5U,
	.AxQos.Lsb = XAIE2GBL_NOC_MODULE_DMA_BD0_5_AXQOS_LSB,
	.AxQos.Mask = XAIE2GBL_NOC_MODULE_DMA_BD0_5_AXQOS_MASK,
	.SecureAccess.Idx = 3U,
	.SecureAccess.Lsb = XAIE2GBL_NOC_MODULE_DMA_BD0_3_SECURE_ACCESS_LSB,
	.SecureAccess.Mask = XAIE2GBL_NOC_MODULE_DMA_BD0_3_SECURE_ACCESS_MASK,
	.AxCache.Idx = 5U,
	.AxCache.Lsb = XAIE2GBL_NOC_MODULE_DMA_BD0_5_AXCACHE_LSB,
	.AxCache.Mask = XAIE2GBL_NOC_MODULE_DMA_BD0_5_AXCACHE_MASK,
};

/* Data structure to capture register offsets and masks for Tile Dma */
const static XAie_DmaBdProp Aie2ShimDmaProp =
{
	.AddrAlignMask = 0xF,
	.AddrAlignShift = 0x0,
	.AddrMask = (1UL << 48U) - 1U,
	.LenActualOffset = 0U,
	.Buffer = &Aie2ShimDmaBufferProp,
	.DoubleBuffer = &Aie2ShimDmaDoubleBufferProp,
	.Lock = &Aie2ShimDmaLockProp,
	.Pkt = &Aie2ShimDmaBdPktProp,
	.BdEn = &Aie2ShimDmaBdEnProp,
	.AddrMode = &Aie2ShimDmaMultiDimProp,
	.ZeroPad = NULL,
	.Compression = NULL,
	.SysProp = &Aie2ShimDmaSysProp
};

/* Data structure to capture register offsets and masks for Mem Tile and
 * Tile Dma Channels
 */
const static XAie_DmaChProp Aie2ShimDmaChProp =
{
	.CtrlId.Idx = 0U,
	.CtrlId.Lsb = XAIE2GBL_NOC_MODULE_DMA_S2MM_0_CTRL_CONTROLLER_ID_LSB ,
	.CtrlId.Mask = XAIE2GBL_NOC_MODULE_DMA_S2MM_0_CTRL_CONTROLLER_ID_MASK ,
	.EnCompression.Idx = 0U,
	.EnCompression.Lsb = 0U,
	.EnCompression.Mask = 0U,
	.EnOutofOrder.Idx = 0U,
	.EnOutofOrder.Lsb = XAIE2GBL_NOC_MODULE_DMA_S2MM_0_CTRL_ENABLE_OUT_OF_ORDER_LSB,
	.EnOutofOrder.Mask = XAIE2GBL_NOC_MODULE_DMA_S2MM_0_CTRL_ENABLE_OUT_OF_ORDER_MASK,
	.Reset.Idx = 0U,
	.Reset.Lsb = 0U,
	.Reset.Mask = 0U,
	.EnToken.Idx = 1U,
	.EnToken.Lsb = XAIE2GBL_NOC_MODULE_DMA_S2MM_0_TASK_QUEUE_ENABLE_TOKEN_ISSUE_LSB,
	.EnToken.Mask = XAIE2GBL_NOC_MODULE_DMA_S2MM_0_TASK_QUEUE_ENABLE_TOKEN_ISSUE_MASK,
	.RptCount.Idx = 1U,
	.RptCount.Lsb = XAIE2GBL_NOC_MODULE_DMA_S2MM_0_TASK_QUEUE_REPEAT_COUNT_LSB,
	.RptCount.Mask = XAIE2GBL_NOC_MODULE_DMA_S2MM_0_TASK_QUEUE_REPEAT_COUNT_MASK,
	.StartBd.Idx = 1U,
	.StartBd.Lsb = XAIE2GBL_NOC_MODULE_DMA_S2MM_0_TASK_QUEUE_START_BD_ID_LSB,
	.StartBd.Mask = XAIE2GBL_NOC_MODULE_DMA_S2MM_0_TASK_QUEUE_START_BD_ID_MASK,
	.PauseStream = {0U},
	.PauseMem = {0U},
	.Enable = {0U},
};

/* Tile Dma Module */
const static XAie_DmaMod Aie2ShimDmaMod =
{
	.BaseAddr = XAIE2GBL_NOC_MODULE_DMA_BD0_0,
	.IdxOffset = 0x20,  	/* This is the offset between each BD */
	.NumBds = 16U,	   	/* Number of BDs for AIE2 Tile DMA */
	.NumLocks = 16U,
	.NumAddrDim = 3U,
	.DoubleBuffering = XAIE_FEATURE_UNAVAILABLE,
	.Compression = XAIE_FEATURE_UNAVAILABLE,
	.ZeroPadding = XAIE_FEATURE_UNAVAILABLE,
	.OutofOrderBdId = XAIE_FEATURE_AVAILABLE,
	.InterleaveMode = XAIE_FEATURE_UNAVAILABLE,
	.ChCtrlBase = XAIE2GBL_NOC_MODULE_DMA_S2MM_0_CTRL,
	.NumChannels = 2U,  /* Number of s2mm/mm2s channels */
	.ChIdxOffset = 0x8,  /* This is the offset between each channel */
	.BdProp = &Aie2ShimDmaProp,
	.ChProp = &Aie2ShimDmaChProp,
	.DmaBdInit = &_XAieMl_ShimDmaInit,
	.SetLock = &_XAieMl_DmaSetLock,
	.SetIntrleave = NULL,
	.SetMultiDim = &_XAieMl_DmaSetMultiDim,
	.WriteBd = &_XAieMl_ShimDmaWriteBd
};

/*
 * Array of all Tile Stream Switch Master Config registers
 * The data structure contains number of ports and the register offsets
 */
const static XAie_StrmPort Aie2TileStrmMstr[SS_PORT_TYPE_MAX] =
{
	{	/* Core */
		.NumPorts = 1,
		.PortBaseAddr = XAIE2GBL_CORE_MODULE_STREAM_SWITCH_MASTER_CONFIG_AIE_CORE0,
	},
	{	/* DMA */
		.NumPorts = 2,
		.PortBaseAddr = XAIE2GBL_CORE_MODULE_STREAM_SWITCH_MASTER_CONFIG_DMA0,
	},
	{	/* Ctrl */
		.NumPorts = 1,
		.PortBaseAddr = XAIE2GBL_CORE_MODULE_STREAM_SWITCH_MASTER_CONFIG_TILE_CTRL,
	},
	{	/* Fifo */
		.NumPorts = 1,
		.PortBaseAddr = XAIE2GBL_CORE_MODULE_STREAM_SWITCH_MASTER_CONFIG_FIFO0,
	},
	{	/* South */
		.NumPorts = 4,
		.PortBaseAddr = XAIE2GBL_CORE_MODULE_STREAM_SWITCH_MASTER_CONFIG_SOUTH0,
	},
	{	/* West */
		.NumPorts = 4,
		.PortBaseAddr = XAIE2GBL_CORE_MODULE_STREAM_SWITCH_MASTER_CONFIG_WEST0,
	},
	{	/* North */
		.NumPorts = 6,
		.PortBaseAddr = XAIE2GBL_CORE_MODULE_STREAM_SWITCH_MASTER_CONFIG_NORTH0,
	},
	{	/* East */
		.NumPorts = 4,
		.PortBaseAddr = XAIE2GBL_CORE_MODULE_STREAM_SWITCH_MASTER_CONFIG_EAST0,
	},
	{	/* Trace */
		.NumPorts = 0,
		.PortBaseAddr = 0
	}
};

/*
 * Array of all Tile Stream Switch Slave Config registers
 * The data structure contains number of ports and the register offsets
 */
const static XAie_StrmPort Aie2TileStrmSlv[SS_PORT_TYPE_MAX] =
{
	{	/* Core */
		.NumPorts = 1,
		.PortBaseAddr = XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_CONFIG_AIE_CORE0,
	},
	{	/* DMA */
		.NumPorts = 2,
		.PortBaseAddr = XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_CONFIG_DMA_0,
	},
	{	/* Ctrl */
		.NumPorts = 1,
		.PortBaseAddr = XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_CONFIG_TILE_CTRL,
	},
	{	/* Fifo */
		.NumPorts = 1,
		.PortBaseAddr = XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_CONFIG_FIFO_0,
	},
	{	/* South */
		.NumPorts = 6,
		.PortBaseAddr = XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_CONFIG_SOUTH_0,
	},
	{	/* West */
		.NumPorts = 4,
		.PortBaseAddr = XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_CONFIG_WEST_0,
	},
	{	/* North */
		.NumPorts = 4,
		.PortBaseAddr = XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_CONFIG_NORTH_0,
	},
	{	/* East */
		.NumPorts = 4,
		.PortBaseAddr = XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_CONFIG_EAST_0,
	},
	{	/* Trace */
		.NumPorts = 1,
		.PortBaseAddr = XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_CONFIG_MEM_TRACE
	}
};

/*
 * Array of all Shim NOC/PL Stream Switch Master Config registers
 * The data structure contains number of ports and the register offsets
 */
const static XAie_StrmPort Aie2ShimStrmMstr[SS_PORT_TYPE_MAX] =
{
	{	/* Core */
		.NumPorts = 0,
		.PortBaseAddr = 0,
	},
	{	/* DMA */
		.NumPorts = 0,
		.PortBaseAddr = 0,
	},
	{	/* Ctrl */
		.NumPorts = 1,
		.PortBaseAddr = XAIE2GBL_PL_MODULE_STREAM_SWITCH_MASTER_CONFIG_TILE_CTRL,
	},
	{	/* Fifo */
		.NumPorts = 1,
		.PortBaseAddr = XAIE2GBL_PL_MODULE_STREAM_SWITCH_MASTER_CONFIG_FIFO0,
	},
	{	/* South */
		.NumPorts = 6,
		.PortBaseAddr = XAIE2GBL_PL_MODULE_STREAM_SWITCH_MASTER_CONFIG_SOUTH0,
	},
	{	/* West */
		.NumPorts = 4,
		.PortBaseAddr = XAIE2GBL_PL_MODULE_STREAM_SWITCH_MASTER_CONFIG_WEST0,
	},
	{	/* North */
		.NumPorts = 6,
		.PortBaseAddr = XAIE2GBL_PL_MODULE_STREAM_SWITCH_MASTER_CONFIG_NORTH0,
	},
	{	/* East */
		.NumPorts = 4,
		.PortBaseAddr = XAIE2GBL_PL_MODULE_STREAM_SWITCH_MASTER_CONFIG_EAST0,
	},
	{	/* Trace */
		.NumPorts = 0,
		.PortBaseAddr = 0
	}
};

/*
 * Array of all Shim NOC/PL Stream Switch Slave Config registers
 * The data structure contains number of ports and the register offsets
 */
const static XAie_StrmPort Aie2ShimStrmSlv[SS_PORT_TYPE_MAX] =
{
	{	/* Core */
		.NumPorts = 0,
		.PortBaseAddr = 0,
	},
	{	/* DMA */
		.NumPorts = 0,
		.PortBaseAddr = 0,
	},
	{	/* Ctrl */
		.NumPorts = 1,
		.PortBaseAddr = XAIE2GBL_PL_MODULE_STREAM_SWITCH_SLAVE_CONFIG_TILE_CTRL,
	},
	{	/* Fifo */
		.NumPorts = 1,
		.PortBaseAddr = XAIE2GBL_PL_MODULE_STREAM_SWITCH_SLAVE_CONFIG_FIFO_0,
	},
	{	/* South */
		.NumPorts = 8,
		.PortBaseAddr = XAIE2GBL_PL_MODULE_STREAM_SWITCH_SLAVE_CONFIG_SOUTH_0,
	},
	{	/* West */
		.NumPorts = 4,
		.PortBaseAddr = XAIE2GBL_PL_MODULE_STREAM_SWITCH_SLAVE_CONFIG_WEST_0,
	},
	{	/* North */
		.NumPorts = 4,
		.PortBaseAddr = XAIE2GBL_PL_MODULE_STREAM_SWITCH_SLAVE_CONFIG_NORTH_0,
	},
	{	/* East */
		.NumPorts = 4,
		.PortBaseAddr = XAIE2GBL_PL_MODULE_STREAM_SWITCH_SLAVE_CONFIG_EAST_0,
	},
	{	/* Trace */
		.NumPorts = 1,
		.PortBaseAddr = XAIE2GBL_PL_MODULE_STREAM_SWITCH_SLAVE_CONFIG_TRACE
	}
};

/*
 * Array of all Mem Tile Stream Switch Master Config registers
 * The data structure contains number of ports and the register offsets
 */
const static XAie_StrmPort Aie2MemTileStrmMstr[SS_PORT_TYPE_MAX] =
{
	{	/* Core */
		.NumPorts = 0,
		.PortBaseAddr = 0,
	},
	{	/* DMA */
		.NumPorts = 6,
		.PortBaseAddr = XAIE2GBL_MEM_TILE_MODULE_STREAM_SWITCH_MASTER_CONFIG_DMA0,
	},
	{	/* Ctrl */
		.NumPorts = 1,
		.PortBaseAddr = XAIE2GBL_MEM_TILE_MODULE_STREAM_SWITCH_MASTER_CONFIG_TILE_CTRL,
	},
	{	/* Fifo */
		.NumPorts = 0,
		.PortBaseAddr = 0,
	},
	{	/* South */
		.NumPorts = 4,
		.PortBaseAddr = XAIE2GBL_MEM_TILE_MODULE_STREAM_SWITCH_MASTER_CONFIG_SOUTH0,
	},
	{	/* West */
		.NumPorts = 0,
		.PortBaseAddr = 0,
	},
	{	/* North */
		.NumPorts = 6,
		.PortBaseAddr = XAIE2GBL_MEM_TILE_MODULE_STREAM_SWITCH_MASTER_CONFIG_NORTH0,
	},
	{	/* East */
		.NumPorts = 0,
		.PortBaseAddr = 0,
	},
	{	/* Trace */
		.NumPorts = 0,
		.PortBaseAddr = 0
	}
};

/*
 * Array of all Mem Tile Stream Switch Slave Config registers
 * The data structure contains number of ports and the register offsets
 */
const static XAie_StrmPort Aie2MemTileStrmSlv[SS_PORT_TYPE_MAX] =
{
	{	/* Core */
		.NumPorts = 0,
		.PortBaseAddr = 0,
	},
	{	/* DMA */
		.NumPorts = 6,
		.PortBaseAddr = XAIE2GBL_MEM_TILE_MODULE_STREAM_SWITCH_SLAVE_CONFIG_DMA_0,
	},
	{	/* Ctrl */
		.NumPorts = 1,
		.PortBaseAddr = XAIE2GBL_MEM_TILE_MODULE_STREAM_SWITCH_SLAVE_CONFIG_TILE_CTRL,
	},
	{	/* Fifo */
		.NumPorts = 0,
		.PortBaseAddr = 0,
	},
	{	/* South */
		.NumPorts = 6,
		.PortBaseAddr = XAIE2GBL_MEM_TILE_MODULE_STREAM_SWITCH_SLAVE_CONFIG_SOUTH_0,
	},
	{	/* West */
		.NumPorts = 0,
		.PortBaseAddr = 0,
	},
	{	/* North */
		.NumPorts = 4,
		.PortBaseAddr = XAIE2GBL_MEM_TILE_MODULE_STREAM_SWITCH_SLAVE_CONFIG_NORTH_0,
	},
	{	/* East */
		.NumPorts = 0,
		.PortBaseAddr = 0,
	},
	{	/* Trace */
		.NumPorts = 1,
		.PortBaseAddr = XAIE2GBL_MEM_TILE_MODULE_STREAM_SWITCH_SLAVE_CONFIG_TRACE
	}
};

/*
 * Array of all Shim NOC/PL Stream Switch Slave Slot Config registers of AIE2.
 * The data structure contains number of ports and the register base address.
 */
const static XAie_StrmPort Aie2ShimStrmSlaveSlot[SS_PORT_TYPE_MAX] =
{
	{	/* Core */
		.NumPorts = 0,
		.PortBaseAddr = 0,
	},
	{	/* DMA */
		.NumPorts = 0,
		.PortBaseAddr = 0,
	},
	{	/* Ctrl */
		.NumPorts = 1,
		.PortBaseAddr = XAIE2GBL_PL_MODULE_STREAM_SWITCH_SLAVE_TILE_CTRL_SLOT0,
	},
	{	/* Fifo */
		.NumPorts = 1,
		.PortBaseAddr = XAIE2GBL_PL_MODULE_STREAM_SWITCH_SLAVE_FIFO_0_SLOT0,
	},
	{	/* South */
		.NumPorts = 8,
		.PortBaseAddr = XAIE2GBL_PL_MODULE_STREAM_SWITCH_SLAVE_SOUTH_0_SLOT0,
	},
	{	/* West */
		.NumPorts = 4,
		.PortBaseAddr = XAIE2GBL_PL_MODULE_STREAM_SWITCH_SLAVE_WEST_0_SLOT0,
	},
	{	/* North */
		.NumPorts = 4,
		.PortBaseAddr = XAIE2GBL_PL_MODULE_STREAM_SWITCH_SLAVE_NORTH_0_SLOT0,
	},
	{	/* East */
		.NumPorts = 4,
		.PortBaseAddr = XAIE2GBL_PL_MODULE_STREAM_SWITCH_SLAVE_EAST_0_SLOT0,
	},
	{	/* Trace */
		.NumPorts = 1,
		.PortBaseAddr = XAIE2GBL_PL_MODULE_STREAM_SWITCH_SLAVE_TRACE_SLOT0
	}
};

/*
 * Array of all AIE2 Tile Stream Switch Slave Slot Config registers.
 * The data structure contains number of ports and the register offsets
 */
const static XAie_StrmPort Aie2TileStrmSlaveSlot[SS_PORT_TYPE_MAX] =
{
	{	/* Core */
		.NumPorts = 1,
		.PortBaseAddr = XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_AIE_CORE0_SLOT0,
	},
	{	/* DMA */
		.NumPorts = 2,
		.PortBaseAddr = XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_DMA_0_SLOT0,
	},
	{	/* Ctrl */
		.NumPorts = 1,
		.PortBaseAddr = XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_TILE_CTRL_SLOT0,
	},
	{	/* Fifo */
		.NumPorts = 1,
		.PortBaseAddr = XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_FIFO_0_SLOT0,
	},
	{	/* South */
		.NumPorts = 6,
		.PortBaseAddr = XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_SOUTH_0_SLOT0,
	},
	{	/* West */
		.NumPorts = 4,
		.PortBaseAddr = XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_WEST_0_SLOT0,
	},
	{	/* North */
		.NumPorts = 4,
		.PortBaseAddr = XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_NORTH_0_SLOT0,
	},
	{	/* East */
		.NumPorts = 4,
		.PortBaseAddr = XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_EAST_0_SLOT0,
	},
	{	/* Trace */
		.NumPorts = 1,
		.PortBaseAddr = XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_AIE_TRACE_SLOT0
	}
};

/*
 * Array of all AIE2 Mem Tile Stream Switch Slave Slot Config registers
 * The data structure contains number of ports and the register offsets
 */
const static XAie_StrmPort Aie2MemTileStrmSlaveSlot[SS_PORT_TYPE_MAX] =
{
	{	/* Core */
		.NumPorts = 0,
		.PortBaseAddr = 0,
	},
	{	/* DMA */
		.NumPorts = 6,
		.PortBaseAddr = XAIE2GBL_MEM_TILE_MODULE_STREAM_SWITCH_SLAVE_DMA_0_SLOT0,
	},
	{	/* Ctrl */
		.NumPorts = 1,
		.PortBaseAddr = XAIE2GBL_MEM_TILE_MODULE_STREAM_SWITCH_SLAVE_TILE_CTRL_SLOT0,
	},
	{	/* Fifo */
		.NumPorts = 0,
		.PortBaseAddr = 0,
	},
	{	/* South */
		.NumPorts = 6,
		.PortBaseAddr = XAIE2GBL_MEM_TILE_MODULE_STREAM_SWITCH_SLAVE_SOUTH_0_SLOT0,
	},
	{	/* West */
		.NumPorts = 0,
		.PortBaseAddr = 0,
	},
	{	/* North */
		.NumPorts = 4,
		.PortBaseAddr = XAIE2GBL_MEM_TILE_MODULE_STREAM_SWITCH_SLAVE_NORTH_0_SLOT0,
	},
	{	/* East */
		.NumPorts = 0,
		.PortBaseAddr = 0,
	},
	{	/* Trace */
		.NumPorts = 1,
		.PortBaseAddr = XAIE2GBL_MEM_TILE_MODULE_STREAM_SWITCH_SLAVE_TRACE_SLOT0,
	}
};

/*
 * Data structure to capture all stream configs for XAIEGBL_TILE_TYPE_AIETILE
 */
const static XAie_StrmMod Aie2TileStrmSw =
{
	.SlvConfigBaseAddr = XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_CONFIG_AIE_CORE0,
	.PortOffset = 0x4,
	.NumSlaveSlots = 4U,
	.SlotOffsetPerPort = 0x10,
	.SlotOffset = 0x4,
	.MstrEn = {XAIE2GBL_CORE_MODULE_STREAM_SWITCH_MASTER_CONFIG_AIE_CORE0_MASTER_ENABLE_LSB, XAIE2GBL_CORE_MODULE_STREAM_SWITCH_MASTER_CONFIG_AIE_CORE0_MASTER_ENABLE_MASK},
	.MstrPktEn = {XAIE2GBL_CORE_MODULE_STREAM_SWITCH_MASTER_CONFIG_AIE_CORE0_PACKET_ENABLE_LSB, XAIE2GBL_CORE_MODULE_STREAM_SWITCH_MASTER_CONFIG_AIE_CORE0_PACKET_ENABLE_MASK},
	.DrpHdr = {XAIE2GBL_CORE_MODULE_STREAM_SWITCH_MASTER_CONFIG_AIE_CORE0_DROP_HEADER_LSB, XAIE2GBL_CORE_MODULE_STREAM_SWITCH_MASTER_CONFIG_AIE_CORE0_DROP_HEADER_MASK},
	.Config = {XAIE2GBL_CORE_MODULE_STREAM_SWITCH_MASTER_CONFIG_AIE_CORE0_CONFIGURATION_LSB, XAIE2GBL_CORE_MODULE_STREAM_SWITCH_MASTER_CONFIG_AIE_CORE0_CONFIGURATION_MASK},
	.SlvEn = {XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_CONFIG_AIE_CORE0_SLAVE_ENABLE_LSB, XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_CONFIG_AIE_CORE0_SLAVE_ENABLE_MASK},
	.SlvPktEn = {XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_CONFIG_AIE_CORE0_PACKET_ENABLE_LSB, XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_CONFIG_AIE_CORE0_PACKET_ENABLE_MASK},
	.SlotPktId = {XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_AIE_CORE0_SLOT0_ID_LSB, XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_AIE_CORE0_SLOT0_ID_MASK},
	.SlotMask = {XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_AIE_CORE0_SLOT0_MASK_LSB, XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_AIE_CORE0_SLOT0_MASK_MASK},
	.SlotEn = {XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_AIE_CORE0_SLOT0_ENABLE_LSB, XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_AIE_CORE0_SLOT0_ENABLE_MASK},
	.SlotMsel = {XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_AIE_CORE0_SLOT0_MSEL_LSB, XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_AIE_CORE0_SLOT0_MSEL_MASK},
	.SlotArbitor = {XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_AIE_CORE0_SLOT0_ARBIT_LSB, XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_AIE_CORE0_SLOT0_ARBIT_MASK},
	.MstrConfig = Aie2TileStrmMstr,
	.SlvConfig = Aie2TileStrmSlv,
	.SlvSlotConfig = Aie2TileStrmSlaveSlot
};

/*
 * Data structure to capture all stream configs for XAIEGBL_TILE_TYPE_SHIMNOC/PL
 */
const static XAie_StrmMod Aie2ShimStrmSw =
{
	.SlvConfigBaseAddr = XAIE2GBL_PL_MODULE_STREAM_SWITCH_SLAVE_CONFIG_TILE_CTRL,
	.PortOffset = 0x4,
	.NumSlaveSlots = 4U,
	.SlotOffsetPerPort = 0x10,
	.SlotOffset = 0x4,
	.MstrEn = {XAIE2GBL_CORE_MODULE_STREAM_SWITCH_MASTER_CONFIG_AIE_CORE0_MASTER_ENABLE_LSB, XAIE2GBL_CORE_MODULE_STREAM_SWITCH_MASTER_CONFIG_AIE_CORE0_MASTER_ENABLE_MASK},
	.MstrPktEn = {XAIE2GBL_CORE_MODULE_STREAM_SWITCH_MASTER_CONFIG_AIE_CORE0_PACKET_ENABLE_LSB, XAIE2GBL_CORE_MODULE_STREAM_SWITCH_MASTER_CONFIG_AIE_CORE0_PACKET_ENABLE_MASK},
	.DrpHdr = {XAIE2GBL_CORE_MODULE_STREAM_SWITCH_MASTER_CONFIG_AIE_CORE0_DROP_HEADER_LSB, XAIE2GBL_CORE_MODULE_STREAM_SWITCH_MASTER_CONFIG_AIE_CORE0_DROP_HEADER_MASK},
	.Config = {XAIE2GBL_CORE_MODULE_STREAM_SWITCH_MASTER_CONFIG_AIE_CORE0_CONFIGURATION_LSB, XAIE2GBL_CORE_MODULE_STREAM_SWITCH_MASTER_CONFIG_AIE_CORE0_CONFIGURATION_MASK},
	.SlvEn = {XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_CONFIG_AIE_CORE0_SLAVE_ENABLE_LSB, XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_CONFIG_AIE_CORE0_SLAVE_ENABLE_MASK},
	.SlvPktEn = {XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_CONFIG_AIE_CORE0_PACKET_ENABLE_LSB, XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_CONFIG_AIE_CORE0_PACKET_ENABLE_MASK},
	.SlotPktId = {XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_AIE_CORE0_SLOT0_ID_LSB, XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_AIE_CORE0_SLOT0_ID_MASK},
	.SlotMask = {XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_AIE_CORE0_SLOT0_MASK_LSB, XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_AIE_CORE0_SLOT0_MASK_MASK},
	.SlotEn = {XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_AIE_CORE0_SLOT0_ENABLE_LSB, XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_AIE_CORE0_SLOT0_ENABLE_MASK},
	.SlotMsel = {XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_AIE_CORE0_SLOT0_MSEL_LSB, XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_AIE_CORE0_SLOT0_MSEL_MASK},
	.SlotArbitor = {XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_AIE_CORE0_SLOT0_ARBIT_LSB, XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_AIE_CORE0_SLOT0_ARBIT_MASK},
	.MstrConfig = Aie2ShimStrmMstr,
	.SlvConfig = Aie2ShimStrmSlv,
	.SlvSlotConfig = Aie2ShimStrmSlaveSlot
};

/*
 * Data structure to capture all stream configs for XAIEGBL_TILE_TYPE_MEMTILE
 */
const static XAie_StrmMod Aie2MemTileStrmSw =
{
	.SlvConfigBaseAddr = XAIE2GBL_MEM_TILE_MODULE_STREAM_SWITCH_SLAVE_CONFIG_DMA_0,
	.PortOffset = 0x4,
	.NumSlaveSlots = 4U,
	.SlotOffsetPerPort = 0x10,
	.SlotOffset = 0x4,
	.MstrEn = {XAIE2GBL_CORE_MODULE_STREAM_SWITCH_MASTER_CONFIG_AIE_CORE0_MASTER_ENABLE_LSB, XAIE2GBL_CORE_MODULE_STREAM_SWITCH_MASTER_CONFIG_AIE_CORE0_MASTER_ENABLE_MASK},
	.MstrPktEn = {XAIE2GBL_CORE_MODULE_STREAM_SWITCH_MASTER_CONFIG_AIE_CORE0_PACKET_ENABLE_LSB, XAIE2GBL_CORE_MODULE_STREAM_SWITCH_MASTER_CONFIG_AIE_CORE0_PACKET_ENABLE_MASK},
	.DrpHdr = {XAIE2GBL_CORE_MODULE_STREAM_SWITCH_MASTER_CONFIG_AIE_CORE0_DROP_HEADER_LSB, XAIE2GBL_CORE_MODULE_STREAM_SWITCH_MASTER_CONFIG_AIE_CORE0_DROP_HEADER_MASK},
	.Config = {XAIE2GBL_CORE_MODULE_STREAM_SWITCH_MASTER_CONFIG_AIE_CORE0_CONFIGURATION_LSB, XAIE2GBL_CORE_MODULE_STREAM_SWITCH_MASTER_CONFIG_AIE_CORE0_CONFIGURATION_MASK},
	.SlvEn = {XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_CONFIG_AIE_CORE0_SLAVE_ENABLE_LSB, XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_CONFIG_AIE_CORE0_SLAVE_ENABLE_MASK},
	.SlvPktEn = {XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_CONFIG_AIE_CORE0_PACKET_ENABLE_LSB, XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_CONFIG_AIE_CORE0_PACKET_ENABLE_MASK},
	.SlotPktId = {XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_AIE_CORE0_SLOT0_ID_LSB, XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_AIE_CORE0_SLOT0_ID_MASK},
	.SlotMask = {XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_AIE_CORE0_SLOT0_MASK_LSB, XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_AIE_CORE0_SLOT0_MASK_MASK},
	.SlotEn = {XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_AIE_CORE0_SLOT0_ENABLE_LSB, XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_AIE_CORE0_SLOT0_ENABLE_MASK},
	.SlotMsel = {XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_AIE_CORE0_SLOT0_MSEL_LSB, XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_AIE_CORE0_SLOT0_MSEL_MASK},
	.SlotArbitor = {XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_AIE_CORE0_SLOT0_ARBIT_LSB, XAIE2GBL_CORE_MODULE_STREAM_SWITCH_SLAVE_AIE_CORE0_SLOT0_ARBIT_MASK},
	.MstrConfig = Aie2MemTileStrmMstr,
	.SlvConfig = Aie2MemTileStrmSlv,
	.SlvSlotConfig = Aie2MemTileStrmSlaveSlot
};

/* Register field attributes for PL interface down sizer for 32 and 64 bits */
const static XAie_RegFldAttr Aie2DownSzr32_64Bit[] =
{
	{XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_CONFIG_SOUTH0_LSB, XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_CONFIG_SOUTH0_MASK},
	{XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_CONFIG_SOUTH1_LSB, XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_CONFIG_SOUTH1_MASK},
	{XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_CONFIG_SOUTH2_LSB, XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_CONFIG_SOUTH2_MASK},
	{XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_CONFIG_SOUTH3_LSB, XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_CONFIG_SOUTH3_MASK},
	{XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_CONFIG_SOUTH4_LSB, XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_CONFIG_SOUTH4_MASK},
	{XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_CONFIG_SOUTH5_LSB, XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_CONFIG_SOUTH5_MASK},
	{XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_CONFIG_SOUTH6_LSB, XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_CONFIG_SOUTH6_MASK},
	{XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_CONFIG_SOUTH7_LSB, XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_CONFIG_SOUTH7_MASK}
};

/* Register field attributes for PL interface down sizer for 128 bits */
const static XAie_RegFldAttr Aie2DownSzr128Bit[] =
{
	{XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_CONFIG_SOUTH0_SOUTH1_128_COMBINE_LSB, XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_CONFIG_SOUTH0_SOUTH1_128_COMBINE_MASK},
	{XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_CONFIG_SOUTH2_SOUTH3_128_COMBINE_LSB, XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_CONFIG_SOUTH2_SOUTH3_128_COMBINE_MASK},
	{XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_CONFIG_SOUTH4_SOUTH5_128_COMBINE_LSB, XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_CONFIG_SOUTH4_SOUTH5_128_COMBINE_MASK},
	{XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_CONFIG_SOUTH6_SOUTH7_128_COMBINE_LSB, XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_CONFIG_SOUTH6_SOUTH7_128_COMBINE_MASK}
};

/* Register field attributes for PL interface up sizer */
const static XAie_RegFldAttr Aie2UpSzr32_64Bit[] =
{
	{XAIE2GBL_PL_MODULE_PL_INTERFACE_UPSIZER_CONFIG_SOUTH0_LSB, XAIE2GBL_PL_MODULE_PL_INTERFACE_UPSIZER_CONFIG_SOUTH0_MASK},
	{XAIE2GBL_PL_MODULE_PL_INTERFACE_UPSIZER_CONFIG_SOUTH1_LSB, XAIE2GBL_PL_MODULE_PL_INTERFACE_UPSIZER_CONFIG_SOUTH1_MASK},
	{XAIE2GBL_PL_MODULE_PL_INTERFACE_UPSIZER_CONFIG_SOUTH2_LSB, XAIE2GBL_PL_MODULE_PL_INTERFACE_UPSIZER_CONFIG_SOUTH2_MASK},
	{XAIE2GBL_PL_MODULE_PL_INTERFACE_UPSIZER_CONFIG_SOUTH3_LSB, XAIE2GBL_PL_MODULE_PL_INTERFACE_UPSIZER_CONFIG_SOUTH3_MASK},
	{XAIE2GBL_PL_MODULE_PL_INTERFACE_UPSIZER_CONFIG_SOUTH4_LSB, XAIE2GBL_PL_MODULE_PL_INTERFACE_UPSIZER_CONFIG_SOUTH4_MASK},
	{XAIE2GBL_PL_MODULE_PL_INTERFACE_UPSIZER_CONFIG_SOUTH5_LSB, XAIE2GBL_PL_MODULE_PL_INTERFACE_UPSIZER_CONFIG_SOUTH5_MASK}
};

/* Register field attributes for PL interface up sizer for 128 bits */
const static XAie_RegFldAttr Aie2UpSzr128Bit[] =
{
	{XAIE2GBL_PL_MODULE_PL_INTERFACE_UPSIZER_CONFIG_SOUTH0_SOUTH1_128_COMBINE_LSB, XAIE2GBL_PL_MODULE_PL_INTERFACE_UPSIZER_CONFIG_SOUTH0_SOUTH1_128_COMBINE_MASK},
	{XAIE2GBL_PL_MODULE_PL_INTERFACE_UPSIZER_CONFIG_SOUTH2_SOUTH3_128_COMBINE_LSB, XAIE2GBL_PL_MODULE_PL_INTERFACE_UPSIZER_CONFIG_SOUTH2_SOUTH3_128_COMBINE_MASK},
	{XAIE2GBL_PL_MODULE_PL_INTERFACE_UPSIZER_CONFIG_SOUTH4_SOUTH5_128_COMBINE_LSB, XAIE2GBL_PL_MODULE_PL_INTERFACE_UPSIZER_CONFIG_SOUTH4_SOUTH5_128_COMBINE_MASK}
};

/* Register field attributes for PL interface down sizer bypass */
const static XAie_RegFldAttr Aie2DownSzrByPass[] =
{
	{XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_BYPASS_SOUTH0_LSB, XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_BYPASS_SOUTH0_MASK},
	{XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_BYPASS_SOUTH1_LSB, XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_BYPASS_SOUTH1_MASK},
	{XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_BYPASS_SOUTH2_LSB, XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_BYPASS_SOUTH2_MASK},
	{XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_BYPASS_SOUTH4_LSB, XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_BYPASS_SOUTH4_MASK},
	{XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_BYPASS_SOUTH5_LSB, XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_BYPASS_SOUTH5_MASK},
	{XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_BYPASS_SOUTH6_LSB, XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_BYPASS_SOUTH6_MASK}
};

/* Register field attributes for PL interface down sizer enable */
const static XAie_RegFldAttr Aie2DownSzrEnable[] =
{
	{XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_ENABLE_SOUTH0_LSB, XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_ENABLE_SOUTH0_MASK},
	{XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_ENABLE_SOUTH1_LSB, XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_ENABLE_SOUTH1_MASK},
	{XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_ENABLE_SOUTH2_LSB, XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_ENABLE_SOUTH2_MASK},
	{XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_ENABLE_SOUTH3_LSB, XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_ENABLE_SOUTH3_MASK},
	{XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_ENABLE_SOUTH4_LSB, XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_ENABLE_SOUTH4_MASK},
	{XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_ENABLE_SOUTH5_LSB, XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_ENABLE_SOUTH5_MASK},
	{XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_ENABLE_SOUTH6_LSB, XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_ENABLE_SOUTH6_MASK},
	{XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_ENABLE_SOUTH7_LSB, XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_ENABLE_SOUTH7_MASK}
};

/* Register field attributes for SHIMNOC Mux configuration */
const static XAie_RegFldAttr Aie2ShimMuxConfig[] =
{
	{XAIE2GBL_NOC_MODULE_MUX_CONFIG_SOUTH2_LSB, XAIE2GBL_NOC_MODULE_MUX_CONFIG_SOUTH2_MASK},
	{XAIE2GBL_NOC_MODULE_MUX_CONFIG_SOUTH3_LSB, XAIE2GBL_NOC_MODULE_MUX_CONFIG_SOUTH3_MASK},
	{XAIE2GBL_NOC_MODULE_MUX_CONFIG_SOUTH6_LSB, XAIE2GBL_NOC_MODULE_MUX_CONFIG_SOUTH6_MASK},
	{XAIE2GBL_NOC_MODULE_MUX_CONFIG_SOUTH7_LSB, XAIE2GBL_NOC_MODULE_MUX_CONFIG_SOUTH7_MASK},
};

/* Register field attributes for SHIMNOC DeMux configuration */
const static XAie_RegFldAttr Aie2ShimDeMuxConfig[] =
{
	{XAIE2GBL_NOC_MODULE_DEMUX_CONFIG_SOUTH2_LSB, XAIE2GBL_NOC_MODULE_DEMUX_CONFIG_SOUTH2_MASK},
	{XAIE2GBL_NOC_MODULE_DEMUX_CONFIG_SOUTH3_LSB, XAIE2GBL_NOC_MODULE_DEMUX_CONFIG_SOUTH3_MASK},
	{XAIE2GBL_NOC_MODULE_DEMUX_CONFIG_SOUTH4_LSB, XAIE2GBL_NOC_MODULE_DEMUX_CONFIG_SOUTH4_MASK},
	{XAIE2GBL_NOC_MODULE_DEMUX_CONFIG_SOUTH5_LSB, XAIE2GBL_NOC_MODULE_DEMUX_CONFIG_SOUTH5_MASK}
};

/* Core Module */
const static XAie_CoreMod Aie2CoreMod =
{
	.ProgMemAddr = XAIE2GBL_CORE_MODULE_PROGRAM_MEMORY,
	.CoreCtrl = &Aie2CoreCtrlReg,
	.CoreSts = &Aie2CoreStsReg,
	.CoreMemSize = 0x10000,		/* AIE2 Tile Memory is 64kB */
	.CoreEastAddrStart = 0x70000,
	.CoreEastAddrEnd = 0x7FFFF,
	.CoreWestAddrStart = 0x50000,
	.CoreWestAddrEnd = 0x5FFFF,
	.CoreSouthAddrStart = 0x40000,
	.CoreSouthAddrEnd = 0x4FFFF,
	.CoreNorthAddrStart = 0x60000,
	.CoreNorthAddrEnd = 0x6FFFF,
};

/* Data Memory Module for Tile data memory*/
const static XAie_MemMod Aie2TileMemMod =
{
	.Size = 0x10000,
	.MemAddr = XAIE2GBL_MEMORY_MODULE_DATAMEMORY
};

/* Data Memory Module for Mem Tile data memory*/
const static XAie_MemMod Aie2MemTileMemMod =
{
	.Size = 0x80000,
	.MemAddr = XAIE2GBL_MEM_TILE_MODULE_DATAMEMORY
};

/* PL Interface module for SHIMPL Tiles */
const static XAie_PlIfMod Aie2PlIfMod =
{
	.UpSzrOff = XAIE2GBL_PL_MODULE_PL_INTERFACE_UPSIZER_CONFIG,
	.DownSzrOff = XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_CONFIG,
	.DownSzrEnOff = XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_ENABLE,
	.DownSzrByPassOff = XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_BYPASS,
	.NumUpSzrPorts = 0x6,
	.MaxByPassPortNum = 0x6,
	.NumDownSzrPorts = 0x8,
	.UpSzr32_64Bit = Aie2UpSzr32_64Bit,
	.UpSzr128Bit = Aie2UpSzr128Bit,
	.DownSzr32_64Bit = Aie2DownSzr32_64Bit,
	.DownSzr128Bit = Aie2DownSzr128Bit,
	.DownSzrEn = Aie2DownSzrEnable,
	.DownSzrByPass = Aie2DownSzrByPass,
	.ShimNocMuxOff = 0x0,
	.ShimNocDeMuxOff = 0x0,
	.ShimNocMux = NULL,
	.ShimNocDeMux = NULL
};

/* PL Interface module for SHIMNOC Tiles */
const static XAie_PlIfMod Aie2ShimTilePlIfMod =
{
	.UpSzrOff = XAIE2GBL_PL_MODULE_PL_INTERFACE_UPSIZER_CONFIG,
	.DownSzrOff = XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_CONFIG,
	.DownSzrEnOff = XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_ENABLE,
	.DownSzrByPassOff = XAIE2GBL_PL_MODULE_PL_INTERFACE_DOWNSIZER_BYPASS,
	.NumUpSzrPorts = 0x6,
	.MaxByPassPortNum = 0x6,
	.NumDownSzrPorts = 0x8,
	.UpSzr32_64Bit = Aie2UpSzr32_64Bit,
	.UpSzr128Bit = Aie2UpSzr128Bit,
	.DownSzr32_64Bit = Aie2DownSzr32_64Bit,
	.DownSzr128Bit = Aie2DownSzr128Bit,
	.DownSzrEn = Aie2DownSzrEnable,
	.DownSzrByPass = Aie2DownSzrByPass,
	.ShimNocMuxOff = XAIE2GBL_NOC_MODULE_MUX_CONFIG,
	.ShimNocDeMuxOff = XAIE2GBL_NOC_MODULE_DEMUX_CONFIG,
	.ShimNocMux = Aie2ShimMuxConfig,
	.ShimNocDeMux = Aie2ShimDeMuxConfig
};

/* Lock Module for AIE Tiles  */
const static XAie_LockMod Aie2TileLockMod =
{
	.BaseAddr = XAIE2GBL_MEMORY_MODULE_LOCK_REQUEST,
	.NumLocks = 16U,
	.LockIdOff = 0x400,
	.RelAcqOff = 0x200,
	.LockValOff = 0x4,
	.LockValUpperBound = 63,
	.LockValLowerBound = -64,
	.Acquire = &_XAieMl_LockAcquire,
	.Release = &_XAieMl_LockRelease
};

/* Lock Module for SHIM NOC Tiles  */
const static XAie_LockMod Aie2ShimNocLockMod =
{
	.BaseAddr = XAIE2GBL_NOC_MODULE_LOCK_REQUEST,
	.NumLocks = 16U,
	.LockIdOff = 0x400,
	.RelAcqOff = 0x200,
	.LockValOff = 0x4,
	.LockValUpperBound = 63,
	.LockValLowerBound = -64,
	.Acquire = &_XAieMl_LockAcquire,
	.Release = &_XAieMl_LockRelease
};

/* Lock Module for Mem Tiles  */
const static XAie_LockMod Aie2MemTileLockMod =
{
	.BaseAddr = XAIE2GBL_MEM_TILE_MODULE_LOCK_REQUEST,
	.NumLocks = 64U,
	.LockIdOff = 0x400,
	.RelAcqOff = 0x200,
	.LockValOff = 0x4,
	.LockValUpperBound = 63,
	.LockValLowerBound = -64,
	.Acquire = &_XAieMl_LockAcquire,
	.Release = &_XAieMl_LockRelease
};

/*
 * AIE2 Module
 * This data structure captures all the modules for each tile type.
 * Depending on the tile type, this data strcuture can be used to access all
 * hardware properties of individual modules.
 */
XAie_TileMod Aie2Mod[] =
{
	{
		/*
		 * AIE2 Tile Module indexed using XAIEGBL_TILE_TYPE_AIETILE
		 */
		.CoreMod = &Aie2CoreMod,
		.StrmSw  = &Aie2TileStrmSw,
		.DmaMod  = &Aie2TileDmaMod,
		.MemMod  = &Aie2TileMemMod,
		.PlIfMod = NULL,
		.LockMod = &Aie2TileLockMod,
	},
	{
		/*
		 * AIE2 Shim Noc Module indexed using XAIEGBL_TILE_TYPE_SHIMNOC
		 */
		.CoreMod = NULL,
		.StrmSw  = &Aie2ShimStrmSw,
		.DmaMod  = &Aie2ShimDmaMod,
		.MemMod  = NULL,
		.PlIfMod = &Aie2ShimTilePlIfMod,
		.LockMod = &Aie2ShimNocLockMod,
	},
	{
		/*
		 * AIE2 Shim PL Module indexed using XAIEGBL_TILE_TYPE_SHIMPL
		 */
		.CoreMod = NULL,
		.StrmSw  = &Aie2ShimStrmSw,
		.DmaMod  = NULL,
		.MemMod  = NULL,
		.PlIfMod = &Aie2PlIfMod,
		.LockMod = NULL,
	},
	{
		/*
		 * AIE2 MemTile Module indexed using XAIEGBL_TILE_TYPE_MEMTILE
		 */
		.CoreMod = NULL,
		.StrmSw  = &Aie2MemTileStrmSw,
		.DmaMod  = &Aie2MemTileDmaMod,
		.MemMod  = &Aie2MemTileMemMod,
		.PlIfMod = NULL,
		.LockMod = &Aie2MemTileLockMod
	}
};

/** @} */