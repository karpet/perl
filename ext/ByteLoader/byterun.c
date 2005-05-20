/* -*- buffer-read-only: t -*-
 *
 *      Copyright (c) 1996-1999 Malcolm Beattie
 *
 *      You may distribute under the terms of either the GNU General Public
 *      License or the Artistic License, as specified in the README file.
 *
 */
/*
 * This file is autogenerated from bytecode.pl. Changes made here will be lost.
 */

#define PERL_NO_GET_CONTEXT
#include "EXTERN.h"
#include "perl.h"
#define NO_XSLOCKS
#include "XSUB.h"

#include "byterun.h"
#include "bytecode.h"


static const int optype_size[] = {
    sizeof(OP),
    sizeof(UNOP),
    sizeof(BINOP),
    sizeof(LOGOP),
    sizeof(LISTOP),
    sizeof(PMOP),
    sizeof(SVOP),
    sizeof(PADOP),
    sizeof(PVOP),
    sizeof(LOOP),
    sizeof(COP)
};

void *
bset_obj_store(pTHX_ struct byteloader_state *bstate, void *obj, I32 ix)
{
    if (ix > bstate->bs_obj_list_fill) {
	Renew(bstate->bs_obj_list, ix + 32, void*);
	bstate->bs_obj_list_fill = ix + 31;
    }
    bstate->bs_obj_list[ix] = obj;
    return obj;
}

int
byterun(pTHX_ register struct byteloader_state *bstate)
{
    dVAR;
    register int insn;
    U32 ix;
    SV *specialsv_list[6];

    BYTECODE_HEADER_CHECK;	/* croak if incorrect platform */
    New(666, bstate->bs_obj_list, 32, void*); /* set op objlist */
    bstate->bs_obj_list_fill = 31;
    bstate->bs_obj_list[0] = NULL; /* first is always Null */
    bstate->bs_ix = 1;

    specialsv_list[0] = Nullsv;
    specialsv_list[1] = &PL_sv_undef;
    specialsv_list[2] = &PL_sv_yes;
    specialsv_list[3] = &PL_sv_no;
    specialsv_list[4] = pWARN_ALL;
    specialsv_list[5] = pWARN_NONE;

    while ((insn = BGET_FGETC()) != EOF) {
	switch (insn) {
	  case INSN_COMMENT:		/* 35 */
	    {
		comment_t arg;
		BGET_comment_t(arg);
		arg = arg;
		break;
	    }
	  case INSN_NOP:		/* 10 */
	    {
		break;
	    }
	  case INSN_RET:		/* 0 */
	    {
		BSET_ret(none);
		break;
	    }
	  case INSN_LDSV:		/* 1 */
	    {
		svindex arg;
		BGET_svindex(arg);
		bstate->bs_sv = arg;
		break;
	    }
	  case INSN_LDOP:		/* 2 */
	    {
		opindex arg;
		BGET_opindex(arg);
		PL_op = arg;
		break;
	    }
	  case INSN_STSV:		/* 3 */
	    {
		U32 arg;
		BGET_U32(arg);
		BSET_OBJ_STORE(bstate->bs_sv, arg);
		break;
	    }
	  case INSN_STOP:		/* 4 */
	    {
		U32 arg;
		BGET_U32(arg);
		BSET_OBJ_STORE(PL_op, arg);
		break;
	    }
	  case INSN_STPV:		/* 5 */
	    {
		U32 arg;
		BGET_U32(arg);
		BSET_stpv(bstate->bs_pv.xpv_pv, arg);
		break;
	    }
	  case INSN_LDSPECSV:		/* 6 */
	    {
		U8 arg;
		BGET_U8(arg);
		BSET_ldspecsv(bstate->bs_sv, arg);
		break;
	    }
	  case INSN_LDSPECSVX:		/* 7 */
	    {
		U8 arg;
		BGET_U8(arg);
		BSET_ldspecsvx(bstate->bs_sv, arg);
		break;
	    }
	  case INSN_NEWSV:		/* 8 */
	    {
		U8 arg;
		BGET_U8(arg);
		BSET_newsv(bstate->bs_sv, arg);
		break;
	    }
	  case INSN_NEWSVX:		/* 9 */
	    {
		U32 arg;
		BGET_U32(arg);
		BSET_newsvx(bstate->bs_sv, arg);
		break;
	    }
	  case INSN_NEWOP:		/* 11 */
	    {
		U8 arg;
		BGET_U8(arg);
		BSET_newop(PL_op, arg);
		break;
	    }
	  case INSN_NEWOPX:		/* 12 */
	    {
		U16 arg;
		BGET_U16(arg);
		BSET_newopx(PL_op, arg);
		break;
	    }
	  case INSN_NEWOPN:		/* 13 */
	    {
		U8 arg;
		BGET_U8(arg);
		BSET_newopn(PL_op, arg);
		break;
	    }
	  case INSN_NEWPV:		/* 14 */
	    {
		PV arg;
		BGET_PV(arg);
		break;
	    }
	  case INSN_PV_CUR:		/* 15 */
	    {
		STRLEN arg;
		BGET_PADOFFSET(arg);
		bstate->bs_pv.xpv_cur = arg;
		break;
	    }
	  case INSN_PV_FREE:		/* 16 */
	    {
		BSET_pv_free(bstate->bs_pv);
		break;
	    }
	  case INSN_SV_UPGRADE:		/* 17 */
	    {
		U8 arg;
		BGET_U8(arg);
		BSET_sv_upgrade(bstate->bs_sv, arg);
		break;
	    }
	  case INSN_SV_REFCNT:		/* 18 */
	    {
		U32 arg;
		BGET_U32(arg);
		SvREFCNT(bstate->bs_sv) = arg;
		break;
	    }
	  case INSN_SV_REFCNT_ADD:		/* 19 */
	    {
		I32 arg;
		BGET_I32(arg);
		BSET_sv_refcnt_add(SvREFCNT(bstate->bs_sv), arg);
		break;
	    }
	  case INSN_SV_FLAGS:		/* 20 */
	    {
		U32 arg;
		BGET_U32(arg);
		SvFLAGS(bstate->bs_sv) = arg;
		break;
	    }
	  case INSN_XRV:		/* 21 */
	    {
		svindex arg;
		BGET_svindex(arg);
		BSET_xrv(bstate->bs_sv, arg);
		break;
	    }
	  case INSN_XPV:		/* 22 */
	    {
		BSET_xpv(bstate->bs_sv);
		break;
	    }
	  case INSN_XPV_CUR:		/* 23 */
	    {
		STRLEN arg;
		BGET_PADOFFSET(arg);
		BSET_xpv_cur(bstate->bs_sv, arg);
		break;
	    }
	  case INSN_XPV_LEN:		/* 24 */
	    {
		STRLEN arg;
		BGET_PADOFFSET(arg);
		BSET_xpv_len(bstate->bs_sv, arg);
		break;
	    }
	  case INSN_XIV:		/* 25 */
	    {
		IV arg;
		BGET_IV(arg);
		BSET_xiv(bstate->bs_sv, arg);
		break;
	    }
	  case INSN_XNV:		/* 26 */
	    {
		NV arg;
		BGET_NV(arg);
		BSET_xnv(bstate->bs_sv, arg);
		break;
	    }
	  case INSN_XLV_TARGOFF:		/* 27 */
	    {
		STRLEN arg;
		BGET_PADOFFSET(arg);
		LvTARGOFF(bstate->bs_sv) = arg;
		break;
	    }
	  case INSN_XLV_TARGLEN:		/* 28 */
	    {
		STRLEN arg;
		BGET_PADOFFSET(arg);
		LvTARGLEN(bstate->bs_sv) = arg;
		break;
	    }
	  case INSN_XLV_TARG:		/* 29 */
	    {
		svindex arg;
		BGET_svindex(arg);
		LvTARG(bstate->bs_sv) = arg;
		break;
	    }
	  case INSN_XLV_TYPE:		/* 30 */
	    {
		char arg;
		BGET_U8(arg);
		LvTYPE(bstate->bs_sv) = arg;
		break;
	    }
	  case INSN_XBM_USEFUL:		/* 31 */
	    {
		I32 arg;
		BGET_I32(arg);
		BmUSEFUL(bstate->bs_sv) = arg;
		break;
	    }
	  case INSN_XBM_PREVIOUS:		/* 32 */
	    {
		U16 arg;
		BGET_U16(arg);
		BmPREVIOUS(bstate->bs_sv) = arg;
		break;
	    }
	  case INSN_XBM_RARE:		/* 33 */
	    {
		U8 arg;
		BGET_U8(arg);
		BmRARE(bstate->bs_sv) = arg;
		break;
	    }
	  case INSN_XFM_LINES:		/* 34 */
	    {
		IV arg;
		BGET_IV(arg);
		FmLINES(bstate->bs_sv) = arg;
		break;
	    }
	  case INSN_XIO_LINES:		/* 36 */
	    {
		IV arg;
		BGET_IV(arg);
		IoLINES(bstate->bs_sv) = arg;
		break;
	    }
	  case INSN_XIO_PAGE:		/* 37 */
	    {
		IV arg;
		BGET_IV(arg);
		IoPAGE(bstate->bs_sv) = arg;
		break;
	    }
	  case INSN_XIO_PAGE_LEN:		/* 38 */
	    {
		IV arg;
		BGET_IV(arg);
		IoPAGE_LEN(bstate->bs_sv) = arg;
		break;
	    }
	  case INSN_XIO_LINES_LEFT:		/* 39 */
	    {
		IV arg;
		BGET_IV(arg);
		IoLINES_LEFT(bstate->bs_sv) = arg;
		break;
	    }
	  case INSN_XIO_TOP_NAME:		/* 40 */
	    {
		pvindex arg;
		BGET_pvindex(arg);
		IoTOP_NAME(bstate->bs_sv) = arg;
		break;
	    }
	  case INSN_XIO_TOP_GV:		/* 41 */
	    {
		svindex arg;
		BGET_svindex(arg);
		*(SV**)&IoTOP_GV(bstate->bs_sv) = arg;
		break;
	    }
	  case INSN_XIO_FMT_NAME:		/* 42 */
	    {
		pvindex arg;
		BGET_pvindex(arg);
		IoFMT_NAME(bstate->bs_sv) = arg;
		break;
	    }
	  case INSN_XIO_FMT_GV:		/* 43 */
	    {
		svindex arg;
		BGET_svindex(arg);
		*(SV**)&IoFMT_GV(bstate->bs_sv) = arg;
		break;
	    }
	  case INSN_XIO_BOTTOM_NAME:		/* 44 */
	    {
		pvindex arg;
		BGET_pvindex(arg);
		IoBOTTOM_NAME(bstate->bs_sv) = arg;
		break;
	    }
	  case INSN_XIO_BOTTOM_GV:		/* 45 */
	    {
		svindex arg;
		BGET_svindex(arg);
		*(SV**)&IoBOTTOM_GV(bstate->bs_sv) = arg;
		break;
	    }
	  case INSN_XIO_SUBPROCESS:		/* 46 */
	    {
		short arg;
		BGET_U16(arg);
		IoSUBPROCESS(bstate->bs_sv) = arg;
		break;
	    }
	  case INSN_XIO_TYPE:		/* 47 */
	    {
		char arg;
		BGET_U8(arg);
		IoTYPE(bstate->bs_sv) = arg;
		break;
	    }
	  case INSN_XIO_FLAGS:		/* 48 */
	    {
		char arg;
		BGET_U8(arg);
		IoFLAGS(bstate->bs_sv) = arg;
		break;
	    }
	  case INSN_XCV_XSUBANY:		/* 49 */
	    {
		svindex arg;
		BGET_svindex(arg);
		*(SV**)&CvXSUBANY(bstate->bs_sv).any_ptr = arg;
		break;
	    }
	  case INSN_XCV_STASH:		/* 50 */
	    {
		svindex arg;
		BGET_svindex(arg);
		*(SV**)&CvSTASH(bstate->bs_sv) = arg;
		break;
	    }
	  case INSN_XCV_START:		/* 51 */
	    {
		opindex arg;
		BGET_opindex(arg);
		CvSTART(bstate->bs_sv) = arg;
		break;
	    }
	  case INSN_XCV_ROOT:		/* 52 */
	    {
		opindex arg;
		BGET_opindex(arg);
		CvROOT(bstate->bs_sv) = arg;
		break;
	    }
	  case INSN_XCV_GV:		/* 53 */
	    {
		svindex arg;
		BGET_svindex(arg);
		*(SV**)&CvGV(bstate->bs_sv) = arg;
		break;
	    }
	  case INSN_XCV_FILE:		/* 54 */
	    {
		pvindex arg;
		BGET_pvindex(arg);
		CvFILE(bstate->bs_sv) = arg;
		break;
	    }
	  case INSN_XCV_DEPTH:		/* 55 */
	    {
		long arg;
		BGET_long(arg);
		CvDEPTH(bstate->bs_sv) = arg;
		break;
	    }
	  case INSN_XCV_PADLIST:		/* 56 */
	    {
		svindex arg;
		BGET_svindex(arg);
		*(SV**)&CvPADLIST(bstate->bs_sv) = arg;
		break;
	    }
	  case INSN_XCV_OUTSIDE:		/* 57 */
	    {
		svindex arg;
		BGET_svindex(arg);
		*(SV**)&CvOUTSIDE(bstate->bs_sv) = arg;
		break;
	    }
	  case INSN_XCV_OUTSIDE_SEQ:		/* 58 */
	    {
		U32 arg;
		BGET_U32(arg);
		CvOUTSIDE_SEQ(bstate->bs_sv) = arg;
		break;
	    }
	  case INSN_XCV_FLAGS:		/* 59 */
	    {
		U16 arg;
		BGET_U16(arg);
		CvFLAGS(bstate->bs_sv) = arg;
		break;
	    }
	  case INSN_AV_EXTEND:		/* 60 */
	    {
		SSize_t arg;
		BGET_PADOFFSET(arg);
		BSET_av_extend(bstate->bs_sv, arg);
		break;
	    }
	  case INSN_AV_PUSHX:		/* 61 */
	    {
		svindex arg;
		BGET_svindex(arg);
		BSET_av_pushx(bstate->bs_sv, arg);
		break;
	    }
	  case INSN_AV_PUSH:		/* 62 */
	    {
		svindex arg;
		BGET_svindex(arg);
		BSET_av_push(bstate->bs_sv, arg);
		break;
	    }
	  case INSN_XAV_FILL:		/* 63 */
	    {
		SSize_t arg;
		BGET_PADOFFSET(arg);
		AvFILLp(bstate->bs_sv) = arg;
		break;
	    }
	  case INSN_XAV_MAX:		/* 64 */
	    {
		SSize_t arg;
		BGET_PADOFFSET(arg);
		AvMAX(bstate->bs_sv) = arg;
		break;
	    }
	  case INSN_XHV_RITER:		/* 65 */
	    {
		I32 arg;
		BGET_I32(arg);
		HvRITER(bstate->bs_sv) = arg;
		break;
	    }
	  case INSN_XHV_NAME:		/* 66 */
	    {
		pvindex arg;
		BGET_pvindex(arg);
		HvNAME(bstate->bs_sv) = arg;
		break;
	    }
	  case INSN_XHV_PMROOT:		/* 67 */
	    {
		opindex arg;
		BGET_opindex(arg);
		*(OP**)&HvPMROOT(bstate->bs_sv) = arg;
		break;
	    }
	  case INSN_HV_STORE:		/* 68 */
	    {
		svindex arg;
		BGET_svindex(arg);
		BSET_hv_store(bstate->bs_sv, arg);
		break;
	    }
	  case INSN_SV_MAGIC:		/* 69 */
	    {
		char arg;
		BGET_U8(arg);
		BSET_sv_magic(bstate->bs_sv, arg);
		break;
	    }
	  case INSN_MG_OBJ:		/* 70 */
	    {
		svindex arg;
		BGET_svindex(arg);
		SvMAGIC(bstate->bs_sv)->mg_obj = arg;
		break;
	    }
	  case INSN_MG_PRIVATE:		/* 71 */
	    {
		U16 arg;
		BGET_U16(arg);
		SvMAGIC(bstate->bs_sv)->mg_private = arg;
		break;
	    }
	  case INSN_MG_FLAGS:		/* 72 */
	    {
		U8 arg;
		BGET_U8(arg);
		SvMAGIC(bstate->bs_sv)->mg_flags = arg;
		break;
	    }
	  case INSN_MG_NAME:		/* 73 */
	    {
		pvcontents arg;
		BGET_pvcontents(arg);
		BSET_mg_name(SvMAGIC(bstate->bs_sv), arg);
		break;
	    }
	  case INSN_MG_NAMEX:		/* 74 */
	    {
		svindex arg;
		BGET_svindex(arg);
		BSET_mg_namex(SvMAGIC(bstate->bs_sv), arg);
		break;
	    }
	  case INSN_XMG_STASH:		/* 75 */
	    {
		svindex arg;
		BGET_svindex(arg);
		BSET_xmg_stash(bstate->bs_sv, arg);
		break;
	    }
	  case INSN_GV_FETCHPV:		/* 76 */
	    {
		strconst arg;
		BGET_strconst(arg);
		BSET_gv_fetchpv(bstate->bs_sv, arg);
		break;
	    }
	  case INSN_GV_FETCHPVX:		/* 77 */
	    {
		strconst arg;
		BGET_strconst(arg);
		BSET_gv_fetchpvx(bstate->bs_sv, arg);
		break;
	    }
	  case INSN_GV_STASHPV:		/* 78 */
	    {
		strconst arg;
		BGET_strconst(arg);
		BSET_gv_stashpv(bstate->bs_sv, arg);
		break;
	    }
	  case INSN_GV_STASHPVX:		/* 79 */
	    {
		strconst arg;
		BGET_strconst(arg);
		BSET_gv_stashpvx(bstate->bs_sv, arg);
		break;
	    }
	  case INSN_GP_SV:		/* 80 */
	    {
		svindex arg;
		BGET_svindex(arg);
		GvSV(bstate->bs_sv) = arg;
		break;
	    }
	  case INSN_GP_REFCNT:		/* 81 */
	    {
		U32 arg;
		BGET_U32(arg);
		GvREFCNT(bstate->bs_sv) = arg;
		break;
	    }
	  case INSN_GP_REFCNT_ADD:		/* 82 */
	    {
		I32 arg;
		BGET_I32(arg);
		BSET_gp_refcnt_add(GvREFCNT(bstate->bs_sv), arg);
		break;
	    }
	  case INSN_GP_AV:		/* 83 */
	    {
		svindex arg;
		BGET_svindex(arg);
		*(SV**)&GvAV(bstate->bs_sv) = arg;
		break;
	    }
	  case INSN_GP_HV:		/* 84 */
	    {
		svindex arg;
		BGET_svindex(arg);
		*(SV**)&GvHV(bstate->bs_sv) = arg;
		break;
	    }
	  case INSN_GP_CV:		/* 85 */
	    {
		svindex arg;
		BGET_svindex(arg);
		*(SV**)&GvCV(bstate->bs_sv) = arg;
		break;
	    }
	  case INSN_GP_FILE:		/* 86 */
	    {
		pvindex arg;
		BGET_pvindex(arg);
		GvFILE(bstate->bs_sv) = arg;
		break;
	    }
	  case INSN_GP_IO:		/* 87 */
	    {
		svindex arg;
		BGET_svindex(arg);
		*(SV**)&GvIOp(bstate->bs_sv) = arg;
		break;
	    }
	  case INSN_GP_FORM:		/* 88 */
	    {
		svindex arg;
		BGET_svindex(arg);
		*(SV**)&GvFORM(bstate->bs_sv) = arg;
		break;
	    }
	  case INSN_GP_CVGEN:		/* 89 */
	    {
		U32 arg;
		BGET_U32(arg);
		GvCVGEN(bstate->bs_sv) = arg;
		break;
	    }
	  case INSN_GP_LINE:		/* 90 */
	    {
		line_t arg;
		BGET_U32(arg);
		GvLINE(bstate->bs_sv) = arg;
		break;
	    }
	  case INSN_GP_SHARE:		/* 91 */
	    {
		svindex arg;
		BGET_svindex(arg);
		BSET_gp_share(bstate->bs_sv, arg);
		break;
	    }
	  case INSN_XGV_FLAGS:		/* 92 */
	    {
		U8 arg;
		BGET_U8(arg);
		GvFLAGS(bstate->bs_sv) = arg;
		break;
	    }
	  case INSN_OP_NEXT:		/* 93 */
	    {
		opindex arg;
		BGET_opindex(arg);
		PL_op->op_next = arg;
		break;
	    }
	  case INSN_OP_SIBLING:		/* 94 */
	    {
		opindex arg;
		BGET_opindex(arg);
		PL_op->op_sibling = arg;
		break;
	    }
	  case INSN_OP_PPADDR:		/* 95 */
	    {
		strconst arg;
		BGET_strconst(arg);
		BSET_op_ppaddr(PL_op->op_ppaddr, arg);
		break;
	    }
	  case INSN_OP_TARG:		/* 96 */
	    {
		PADOFFSET arg;
		BGET_PADOFFSET(arg);
		PL_op->op_targ = arg;
		break;
	    }
	  case INSN_OP_TYPE:		/* 97 */
	    {
		OPCODE arg;
		BGET_U16(arg);
		BSET_op_type(PL_op, arg);
		break;
	    }
	  case INSN_OP_OPT:		/* 98 */
	    {
		U8 arg;
		BGET_U8(arg);
		PL_op->op_opt = arg;
		break;
	    }
	  case INSN_OP_STATIC:		/* 99 */
	    {
		U8 arg;
		BGET_U8(arg);
		PL_op->op_static = arg;
		break;
	    }
	  case INSN_OP_FLAGS:		/* 100 */
	    {
		U8 arg;
		BGET_U8(arg);
		PL_op->op_flags = arg;
		break;
	    }
	  case INSN_OP_PRIVATE:		/* 101 */
	    {
		U8 arg;
		BGET_U8(arg);
		PL_op->op_private = arg;
		break;
	    }
	  case INSN_OP_FIRST:		/* 102 */
	    {
		opindex arg;
		BGET_opindex(arg);
		cUNOP->op_first = arg;
		break;
	    }
	  case INSN_OP_LAST:		/* 103 */
	    {
		opindex arg;
		BGET_opindex(arg);
		cBINOP->op_last = arg;
		break;
	    }
	  case INSN_OP_OTHER:		/* 104 */
	    {
		opindex arg;
		BGET_opindex(arg);
		cLOGOP->op_other = arg;
		break;
	    }
	  case INSN_OP_PMREPLROOT:		/* 105 */
	    {
		opindex arg;
		BGET_opindex(arg);
		cPMOP->op_pmreplroot = arg;
		break;
	    }
	  case INSN_OP_PMREPLSTART:		/* 106 */
	    {
		opindex arg;
		BGET_opindex(arg);
		cPMOP->op_pmreplstart = arg;
		break;
	    }
	  case INSN_OP_PMNEXT:		/* 107 */
	    {
		opindex arg;
		BGET_opindex(arg);
		*(OP**)&cPMOP->op_pmnext = arg;
		break;
	    }
#ifdef USE_ITHREADS
	  case INSN_OP_PMSTASHPV:		/* 108 */
	    {
		pvindex arg;
		BGET_pvindex(arg);
		BSET_op_pmstashpv(cPMOP, arg);
		break;
	    }
	  case INSN_OP_PMREPLROOTPO:		/* 109 */
	    {
		PADOFFSET arg;
		BGET_PADOFFSET(arg);
		cPMOP->op_pmreplroot = (OP*)arg;
		break;
	    }
#else
	  case INSN_OP_PMSTASH:		/* 110 */
	    {
		svindex arg;
		BGET_svindex(arg);
		*(SV**)&cPMOP->op_pmstash = arg;
		break;
	    }
	  case INSN_OP_PMREPLROOTGV:		/* 111 */
	    {
		svindex arg;
		BGET_svindex(arg);
		*(SV**)&cPMOP->op_pmreplroot = arg;
		break;
	    }
#endif
	  case INSN_PREGCOMP:		/* 112 */
	    {
		pvcontents arg;
		BGET_pvcontents(arg);
		BSET_pregcomp(PL_op, arg);
		break;
	    }
	  case INSN_OP_PMFLAGS:		/* 113 */
	    {
		U16 arg;
		BGET_U16(arg);
		cPMOP->op_pmflags = arg;
		break;
	    }
	  case INSN_OP_PMPERMFLAGS:		/* 114 */
	    {
		U16 arg;
		BGET_U16(arg);
		cPMOP->op_pmpermflags = arg;
		break;
	    }
	  case INSN_OP_PMDYNFLAGS:		/* 115 */
	    {
		U8 arg;
		BGET_U8(arg);
		cPMOP->op_pmdynflags = arg;
		break;
	    }
	  case INSN_OP_SV:		/* 116 */
	    {
		svindex arg;
		BGET_svindex(arg);
		cSVOP->op_sv = arg;
		break;
	    }
	  case INSN_OP_PADIX:		/* 117 */
	    {
		PADOFFSET arg;
		BGET_PADOFFSET(arg);
		cPADOP->op_padix = arg;
		break;
	    }
	  case INSN_OP_PV:		/* 118 */
	    {
		pvcontents arg;
		BGET_pvcontents(arg);
		cPVOP->op_pv = arg;
		break;
	    }
	  case INSN_OP_PV_TR:		/* 119 */
	    {
		op_tr_array arg;
		BGET_op_tr_array(arg);
		cPVOP->op_pv = arg;
		break;
	    }
	  case INSN_OP_REDOOP:		/* 120 */
	    {
		opindex arg;
		BGET_opindex(arg);
		cLOOP->op_redoop = arg;
		break;
	    }
	  case INSN_OP_NEXTOP:		/* 121 */
	    {
		opindex arg;
		BGET_opindex(arg);
		cLOOP->op_nextop = arg;
		break;
	    }
	  case INSN_OP_LASTOP:		/* 122 */
	    {
		opindex arg;
		BGET_opindex(arg);
		cLOOP->op_lastop = arg;
		break;
	    }
	  case INSN_COP_LABEL:		/* 123 */
	    {
		pvindex arg;
		BGET_pvindex(arg);
		cCOP->cop_label = arg;
		break;
	    }
#ifdef USE_ITHREADS
	  case INSN_COP_STASHPV:		/* 124 */
	    {
		pvindex arg;
		BGET_pvindex(arg);
		BSET_cop_stashpv(cCOP, arg);
		break;
	    }
	  case INSN_COP_FILE:		/* 125 */
	    {
		pvindex arg;
		BGET_pvindex(arg);
		BSET_cop_file(cCOP, arg);
		break;
	    }
#else
	  case INSN_COP_STASH:		/* 126 */
	    {
		svindex arg;
		BGET_svindex(arg);
		BSET_cop_stash(cCOP, arg);
		break;
	    }
	  case INSN_COP_FILEGV:		/* 127 */
	    {
		svindex arg;
		BGET_svindex(arg);
		BSET_cop_filegv(cCOP, arg);
		break;
	    }
#endif
	  case INSN_COP_SEQ:		/* 128 */
	    {
		U32 arg;
		BGET_U32(arg);
		cCOP->cop_seq = arg;
		break;
	    }
	  case INSN_COP_ARYBASE:		/* 129 */
	    {
		I32 arg;
		BGET_I32(arg);
		cCOP->cop_arybase = arg;
		break;
	    }
	  case INSN_COP_LINE:		/* 130 */
	    {
		line_t arg;
		BGET_U32(arg);
		cCOP->cop_line = arg;
		break;
	    }
	  case INSN_COP_IO:		/* 131 */
	    {
		svindex arg;
		BGET_svindex(arg);
		cCOP->cop_io = arg;
		break;
	    }
	  case INSN_COP_WARNINGS:		/* 132 */
	    {
		svindex arg;
		BGET_svindex(arg);
		cCOP->cop_warnings = arg;
		break;
	    }
	  case INSN_MAIN_START:		/* 133 */
	    {
		opindex arg;
		BGET_opindex(arg);
		PL_main_start = arg;
		break;
	    }
	  case INSN_MAIN_ROOT:		/* 134 */
	    {
		opindex arg;
		BGET_opindex(arg);
		PL_main_root = arg;
		break;
	    }
	  case INSN_MAIN_CV:		/* 135 */
	    {
		svindex arg;
		BGET_svindex(arg);
		*(SV**)&PL_main_cv = arg;
		break;
	    }
	  case INSN_CURPAD:		/* 136 */
	    {
		svindex arg;
		BGET_svindex(arg);
		BSET_curpad(PL_curpad, arg);
		break;
	    }
	  case INSN_PUSH_BEGIN:		/* 137 */
	    {
		svindex arg;
		BGET_svindex(arg);
		BSET_push_begin(PL_beginav, arg);
		break;
	    }
	  case INSN_PUSH_INIT:		/* 138 */
	    {
		svindex arg;
		BGET_svindex(arg);
		BSET_push_init(PL_initav, arg);
		break;
	    }
	  case INSN_PUSH_END:		/* 139 */
	    {
		svindex arg;
		BGET_svindex(arg);
		BSET_push_end(PL_endav, arg);
		break;
	    }
	  case INSN_CURSTASH:		/* 140 */
	    {
		svindex arg;
		BGET_svindex(arg);
		*(SV**)&PL_curstash = arg;
		break;
	    }
	  case INSN_DEFSTASH:		/* 141 */
	    {
		svindex arg;
		BGET_svindex(arg);
		*(SV**)&PL_defstash = arg;
		break;
	    }
	  case INSN_DATA:		/* 142 */
	    {
		U8 arg;
		BGET_U8(arg);
		BSET_data(none, arg);
		break;
	    }
	  case INSN_INCAV:		/* 143 */
	    {
		svindex arg;
		BGET_svindex(arg);
		*(SV**)&GvAV(PL_incgv) = arg;
		break;
	    }
	  case INSN_LOAD_GLOB:		/* 144 */
	    {
		svindex arg;
		BGET_svindex(arg);
		BSET_load_glob(none, arg);
		break;
	    }
#ifdef USE_ITHREADS
	  case INSN_REGEX_PADAV:		/* 145 */
	    {
		svindex arg;
		BGET_svindex(arg);
		*(SV**)&PL_regex_padav = arg;
		break;
	    }
#endif
	  case INSN_DOWARN:		/* 146 */
	    {
		U8 arg;
		BGET_U8(arg);
		PL_dowarn = arg;
		break;
	    }
	  case INSN_COMPPAD_NAME:		/* 147 */
	    {
		svindex arg;
		BGET_svindex(arg);
		*(SV**)&PL_comppad_name = arg;
		break;
	    }
	  case INSN_XGV_STASH:		/* 148 */
	    {
		svindex arg;
		BGET_svindex(arg);
		*(SV**)&GvSTASH(bstate->bs_sv) = arg;
		break;
	    }
	  case INSN_SIGNAL:		/* 149 */
	    {
		strconst arg;
		BGET_strconst(arg);
		BSET_signal(bstate->bs_sv, arg);
		break;
	    }
	  case INSN_FORMFEED:		/* 150 */
	    {
		svindex arg;
		BGET_svindex(arg);
		PL_formfeed = arg;
		break;
	    }
	  default:
	    Perl_croak(aTHX_ "Illegal bytecode instruction %d\n", insn);
	    /* NOTREACHED */
	}
    }
    return 0;
}

/* ex: set ro: */
