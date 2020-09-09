/*
 * Copyright (C) 2015 MediaTek Inc.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#ifndef __CMDQ_ENGINE_H__
#define __CMDQ_ENGINE_H__

enum CMDQ_ENG_ENUM {
	/* ISP */
	CMDQ_ENG_WPEI = 0,
	CMDQ_ENG_WPEO,			/* 1 */
	CMDQ_ENG_WPEI2,			/* 2 */
	CMDQ_ENG_WPEO2,			/* 3 */
	CMDQ_ENG_ISP_IMGI,		/* 4 */
	CMDQ_ENG_ISP_IMGO,		/* 5 */
	CMDQ_ENG_ISP_IMG2O,		/* 6 */

	/* IPU */
	CMDQ_ENG_IPUI,			/* 7 */
	CMDQ_ENG_IPUO,			/* 8 */

	/* MDP */
	CMDQ_ENG_MDP_CAMIN,		/* 9 */
	CMDQ_ENG_MDP_CAMIN2,		/* 10 */
	CMDQ_ENG_MDP_RDMA0,		/* 11 */
	CMDQ_ENG_MDP_RDMA1,		/* 12 */
	CMDQ_ENG_MDP_HDR0,		/* 13 */
	CMDQ_ENG_MDP_AAL0,		/* 14 */
	CMDQ_ENG_MDP_RSZ0,		/* 15 */
	CMDQ_ENG_MDP_RSZ1,		/* 16 */
	CMDQ_ENG_MDP_TDSHP0,		/* 17 */
	CMDQ_ENG_MDP_COLOR0,		/* 18 */
	CMDQ_ENG_MDP_PATH0_SOUT,	/* 19 */
	CMDQ_ENG_MDP_PATH1_SOUT,	/* 20 */
	CMDQ_ENG_MDP_WROT0,		/* 21 */
	CMDQ_ENG_MDP_WROT1,		/* 22 */

	/* JPEG & VENC */
	CMDQ_ENG_JPEG_ENC,		/* 23 */
	CMDQ_ENG_VIDEO_ENC,		/* 24 */
	CMDQ_ENG_JPEG_DEC,		/* 25 */
	CMDQ_ENG_JPEG_REMDC,		/* 26 */

	/* DISP */
	CMDQ_ENG_DISP_AAL,		/* 27 */
	CMDQ_ENG_DISP_COLOR0,		/* 28 */
	CMDQ_ENG_DISP_RDMA0,		/* 29 */
	CMDQ_ENG_DISP_RDMA1,		/* 30 */
	CMDQ_ENG_DISP_WDMA0,		/* 31 */
	CMDQ_ENG_DISP_WDMA1,		/* 32 */
	CMDQ_ENG_DISP_OVL0,		/* 33 */
	CMDQ_ENG_DISP_OVL1,		/* 34 */
	CMDQ_ENG_DISP_OVL2,		/* 35 */
	CMDQ_ENG_DISP_GAMMA,		/* 36 */
	CMDQ_ENG_DISP_DSI0,		/* 37 */
	CMDQ_ENG_DISP_2L_OVL0,		/* 38 */
	CMDQ_ENG_DISP_2L_OVL1,		/* 39 */

	/* ISP */
	CMDQ_ENG_DPE,			/* 40 */
	CMDQ_ENG_RSC,			/* 41 */
	CMDQ_ENG_GEPF,			/* 42 */
	CMDQ_ENG_EAF,			/* 43 */
	CMDQ_ENG_OWE,			/* 44 */
	CMDQ_ENG_MFB,			/* 45 */
	CMDQ_ENG_FDVT,			/* 46 */

	/* temp: CMDQ internal usage */
	CMDQ_ENG_CMDQ,			/* 47 */

	/* Dummy Engine */
	CMDQ_ENG_MDP_RSZ2,		/* 48 */
	CMDQ_ENG_MDP_TDSHP1,		/* 49 */
	CMDQ_ENG_MDP_WDMA,		/* 50 */

	/* ISP sec */
	CMDQ_ENG_ISP_VIPI,		/* 51 */
	CMDQ_ENG_ISP_LCEI,		/* 52 */
	CMDQ_ENG_ISP_IMG3O,		/* 53 */
	CMDQ_ENG_ISP_SMXIO,		/* 54 */
	CMDQ_ENG_ISP_DMGI_DEPI,		/* 55 */
	CMDQ_ENG_ISP_IMGCI,		/* 56 */
	CMDQ_ENG_ISP_TIMGO,		/* 57 */

	CMDQ_ENG_INORDER,		/* 58 */

	/* Dummy DISP */
	CMDQ_ENG_DISP_2L_OVL2,		/* 59 */

	CMDQ_MAX_ENGINE_COUNT		/* ALWAYS keep at the end */
};

#define CMDQ_ENG_WPE_GROUP_BITS	((1LL << CMDQ_ENG_WPEI) |	\
				 (1LL << CMDQ_ENG_WPEO) |	\
				 (1LL << CMDQ_ENG_WPEI2) |	\
				 (1LL << CMDQ_ENG_WPEO2))

#define CMDQ_ENG_IPU_GROUP_BITS	((1LL << CMDQ_ENG_IPUI) |	\
				 (1LL << CMDQ_ENG_IPUO))

#define CMDQ_ENG_ISP_GROUP_BITS	((1LL << CMDQ_ENG_ISP_IMGI) |	\
				 (1LL << CMDQ_ENG_ISP_IMGO) |	\
				 (1LL << CMDQ_ENG_ISP_IMG2O))

#define CMDQ_ENG_MDP_GROUP_BITS	((1LL << CMDQ_ENG_MDP_CAMIN) |	\
				 (1LL << CMDQ_ENG_MDP_CAMIN2) |	\
				 (1LL << CMDQ_ENG_MDP_RDMA0) |	\
				 (1LL << CMDQ_ENG_MDP_RDMA1) |	\
				 (1LL << CMDQ_ENG_MDP_AAL0) |	\
				 (1LL << CMDQ_ENG_MDP_HDR0) |	\
				 (1LL << CMDQ_ENG_MDP_RSZ0) |	\
				 (1LL << CMDQ_ENG_MDP_RSZ1) |	\
				 (1LL << CMDQ_ENG_MDP_RSZ2) |	\
				 (1LL << CMDQ_ENG_MDP_TDSHP0) |	\
				 (1LL << CMDQ_ENG_MDP_TDSHP1) |	\
				 (1LL << CMDQ_ENG_MDP_COLOR0) |	\
				 (1LL << CMDQ_ENG_MDP_WROT0) |	\
				 (1LL << CMDQ_ENG_MDP_WROT1))

#define CMDQ_ENG_DISP_GROUP_BITS	\
				((1LL << CMDQ_ENG_DISP_AAL) |		\
				(1LL << CMDQ_ENG_DISP_COLOR0) |	\
				(1LL << CMDQ_ENG_DISP_RDMA0) |		\
				(1LL << CMDQ_ENG_DISP_RDMA1) |		\
				(1LL << CMDQ_ENG_DISP_WDMA0) |		\
				(1LL << CMDQ_ENG_DISP_WDMA1) |		\
				(1LL << CMDQ_ENG_DISP_OVL0) |		\
				(1LL << CMDQ_ENG_DISP_OVL1) |		\
				(1LL << CMDQ_ENG_DISP_2L_OVL0) |	\
				(1LL << CMDQ_ENG_DISP_2L_OVL1) |	\
				(1LL << CMDQ_ENG_DISP_GAMMA) |		\
				(1LL << CMDQ_ENG_DISP_DSI0))

#define CMDQ_ENG_VENC_GROUP_BITS	((1LL << CMDQ_ENG_VIDEO_ENC))

#define CMDQ_ENG_JPEG_GROUP_BITS	((1LL << CMDQ_ENG_JPEG_ENC) |	\
					 (1LL << CMDQ_ENG_JPEG_REMDC) |	\
					 (1LL << CMDQ_ENG_JPEG_DEC))

#define CMDQ_ENG_DPE_GROUP_BITS		(1LL << CMDQ_ENG_DPE)
#define CMDQ_ENG_RSC_GROUP_BITS		(1LL << CMDQ_ENG_RSC)
#define CMDQ_ENG_GEPF_GROUP_BITS	(1LL << CMDQ_ENG_GEPF)
#define CMDQ_ENG_OWE_GROUP_BITS		(1LL << CMDQ_ENG_OWE)
#define CMDQ_ENG_MFB_GROUP_BITS		(1LL << CMDQ_ENG_MFB)
#define CMDQ_ENG_EAF_GROUP_BITS		(1LL << CMDQ_ENG_EAF)
#define CMDQ_ENG_FDVT_GROUP_BITS	(1LL << CMDQ_ENG_FDVT)

#define CMDQ_ENG_ISP_GROUP_FLAG(flag)   ((flag) & (CMDQ_ENG_ISP_GROUP_BITS))
#define CMDQ_ENG_MDP_GROUP_FLAG(flag)   ((flag) & (CMDQ_ENG_MDP_GROUP_BITS))
#define CMDQ_ENG_DISP_GROUP_FLAG(flag)  ((flag) & (CMDQ_ENG_DISP_GROUP_BITS))
#define CMDQ_ENG_JPEG_GROUP_FLAG(flag)  ((flag) & (CMDQ_ENG_JPEG_GROUP_BITS))
#define CMDQ_ENG_VENC_GROUP_FLAG(flag)	((flag) & (CMDQ_ENG_VENC_GROUP_BITS))
#define CMDQ_ENG_DPE_GROUP_FLAG(flag)	((flag) & (CMDQ_ENG_DPE_GROUP_BITS))
#define CMDQ_ENG_RSC_GROUP_FLAG(flag)	((flag) & (CMDQ_ENG_RSC_GROUP_BITS))
#define CMDQ_ENG_GEPF_GROUP_FLAG(flag)	((flag) & (CMDQ_ENG_GEPF_GROUP_BITS))
#define CMDQ_ENG_WPE_GROUP_FLAG(flag)	((flag) & (CMDQ_ENG_WPE_GROUP_BITS))
#define CMDQ_ENG_OWE_GROUP_FLAG(flag)	((flag) & (CMDQ_ENG_OWE_GROUP_BITS))
#define CMDQ_ENG_MFB_GROUP_FLAG(flag)	((flag) & (CMDQ_ENG_MFB_GROUP_BITS))
#define CMDQ_ENG_EAF_GROUP_FLAG(flag)	((flag) & (CMDQ_ENG_EAF_GROUP_BITS))
#define CMDQ_ENG_FDVT_GROUP_FLAG(flag)	((flag) & (CMDQ_ENG_FDVT_GROUP_BITS))

#define CMDQ_FOREACH_GROUP(ACTION_struct)\
	ACTION_struct(CMDQ_GROUP_ISP, ISP)	\
	ACTION_struct(CMDQ_GROUP_MDP, MDP)	\
	ACTION_struct(CMDQ_GROUP_DISP, DISP)	\
	ACTION_struct(CMDQ_GROUP_JPEG, JPEG)	\
	ACTION_struct(CMDQ_GROUP_VENC, VENC)	\
	ACTION_struct(CMDQ_GROUP_DPE, DPE)	\
	ACTION_struct(CMDQ_GROUP_RSC, RSC)	\
	ACTION_struct(CMDQ_GROUP_GEPF, GEPF)	\
	ACTION_struct(CMDQ_GROUP_WPE, WPE)	\
	ACTION_struct(CMDQ_GROUP_OWE, OWE)	\
	ACTION_struct(CMDQ_GROUP_MFB, MFB)	\


#define MDP_GENERATE_ENUM(_enum, _string) _enum,

enum CMDQ_GROUP_ENUM {
	CMDQ_FOREACH_GROUP(MDP_GENERATE_ENUM)
	CMDQ_MAX_GROUP_COUNT,	/* ALWAYS keep at the end */
};

#endif				/* __CMDQ_ENGINE_H__ */
