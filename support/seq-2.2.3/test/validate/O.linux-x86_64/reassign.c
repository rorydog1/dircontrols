/* C code for program reassignTest, generated by snc from ../reassign.st */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>

#include "seq_snc.h"
# line 11 "../reassign.st"
#include "../testSupport.h"

/* Variable declarations */
struct seqg_vars {
# line 13 "../reassign.st"
	int x;
# line 13 "../reassign.st"
	int y;
# line 13 "../reassign.st"
	int z;
};


/* Function declarations */

#define seqg_var (*(struct seqg_vars *const *)seqg_env)

/* Program init func */
static void seqg_init(PROG_ID seqg_env)
{
}

/* Program entry func */
static void seqg_entry(SS_ID seqg_env)
{
# line 21 "../reassign.st"
	seq_test_init(30);
}

/****** Code for state "start" in state set "reassign" ******/

/* Event function for state "start" in state set "reassign" */
static seqBool seqg_event_reassign_0_start(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
	if (TRUE)
	{
		*seqg_pnst = 1;
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "start" in state set "reassign" */
static void seqg_action_reassign_0_start(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 27 "../reassign.st"
			testDiag("start");
# line 28 "../reassign.st"
			testOk1(seq_pvChannelCount(seqg_env) == 3);
# line 29 "../reassign.st"
			testOk1(seq_pvAssignCount(seqg_env) == 2);
# line 30 "../reassign.st"
			testOk1(seq_pvConnectCount(seqg_env) == 2);
# line 31 "../reassign.st"
			testOk1(seq_pvAssign(seqg_env, 0/*x*/, "") == pvStatOK);
		}
		return;
	}
}

/****** Code for state "wait_x_nil" in state set "reassign" ******/

/* Event function for state "wait_x_nil" in state set "reassign" */
static seqBool seqg_event_reassign_0_wait_x_nil(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 35 "../reassign.st"
	if (seq_pvAssignCount(seqg_env) == 1)
	{
		*seqg_pnst = 2;
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "wait_x_nil" in state set "reassign" */
static void seqg_action_reassign_0_wait_x_nil(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 36 "../reassign.st"
			testDiag("wait_x_nil");
# line 37 "../reassign.st"
			testOk1(seq_pvChannelCount(seqg_env) == 3);
# line 38 "../reassign.st"
			testOk1(seq_pvAssignCount(seqg_env) == 1);
# line 39 "../reassign.st"
			testOk1(seq_pvAssign(seqg_env, 0/*x*/, "pv1") == pvStatOK);
# line 40 "../reassign.st"
			testOk1(seq_pvAssignCount(seqg_env) == 2);
		}
		return;
	}
}

/****** Code for state "wait_x_pv1" in state set "reassign" ******/

/* Event function for state "wait_x_pv1" in state set "reassign" */
static seqBool seqg_event_reassign_0_wait_x_pv1(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 44 "../reassign.st"
	if (seq_pvConnected(seqg_env, 0/*x*/))
	{
		*seqg_pnst = 3;
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "wait_x_pv1" in state set "reassign" */
static void seqg_action_reassign_0_wait_x_pv1(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 45 "../reassign.st"
			testDiag("wait_x_pv1");
# line 46 "../reassign.st"
			testOk1(seq_pvGetTmo(seqg_env, 0/*x*/, DEFAULT, DEFAULT_TIMEOUT) == pvStatOK);
# line 47 "../reassign.st"
			testOk1(seq_pvChannelCount(seqg_env) == 3);
# line 48 "../reassign.st"
			testOk1(seq_pvConnectCount(seqg_env) == 2);
# line 49 "../reassign.st"
			testOk1(seq_pvAssignCount(seqg_env) == 2);
# line 50 "../reassign.st"
			testOk1(seq_pvAssign(seqg_env, 0/*x*/, "pv2") == pvStatOK);
		}
		return;
	}
}

/****** Code for state "wait_x_pv2" in state set "reassign" ******/

/* Event function for state "wait_x_pv2" in state set "reassign" */
static seqBool seqg_event_reassign_0_wait_x_pv2(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 54 "../reassign.st"
	if (seq_pvConnected(seqg_env, 0/*x*/))
	{
		*seqg_pnst = 4;
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "wait_x_pv2" in state set "reassign" */
static void seqg_action_reassign_0_wait_x_pv2(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 55 "../reassign.st"
			testDiag("wait_x_pv2");
# line 56 "../reassign.st"
			testOk1(seq_pvGetTmo(seqg_env, 0/*x*/, DEFAULT, DEFAULT_TIMEOUT) == pvStatOK);
# line 57 "../reassign.st"
			testOk1(seq_pvChannelCount(seqg_env) == 3);
# line 58 "../reassign.st"
			testOk1(seq_pvConnectCount(seqg_env) == 2);
# line 59 "../reassign.st"
			testOk1(seq_pvAssignCount(seqg_env) == 2);
# line 61 "../reassign.st"
			testOk1(seq_pvAssign(seqg_env, 1/*y*/, "") == pvStatOK);
# line 62 "../reassign.st"
			testOk1(seq_pvConnectCount(seqg_env) == 2);
# line 63 "../reassign.st"
			testOk1(seq_pvAssignCount(seqg_env) == 2);
# line 64 "../reassign.st"
			testOk1(seq_pvAssign(seqg_env, 1/*y*/, "pv1") == pvStatOK);
# line 65 "../reassign.st"
			testOk1(seq_pvAssignCount(seqg_env) == 3);
		}
		return;
	}
}

/****** Code for state "wait_y_pv1" in state set "reassign" ******/

/* Event function for state "wait_y_pv1" in state set "reassign" */
static seqBool seqg_event_reassign_0_wait_y_pv1(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 69 "../reassign.st"
	if (seq_pvConnected(seqg_env, 1/*y*/))
	{
		*seqg_pnst = 5;
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "wait_y_pv1" in state set "reassign" */
static void seqg_action_reassign_0_wait_y_pv1(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 70 "../reassign.st"
			testDiag("wait_y_pv1");
# line 71 "../reassign.st"
			testOk1(seq_pvGetTmo(seqg_env, 1/*y*/, DEFAULT, DEFAULT_TIMEOUT) == pvStatOK);
# line 72 "../reassign.st"
			testOk1(seq_pvChannelCount(seqg_env) == 3);
# line 73 "../reassign.st"
			testOk1(seq_pvConnectCount(seqg_env) == 3);
# line 74 "../reassign.st"
			testOk1(seq_pvAssign(seqg_env, 2/*z*/, "pv2") == pvStatOK);
		}
		return;
	}
}

/****** Code for state "wait_z_pv2" in state set "reassign" ******/

/* Event function for state "wait_z_pv2" in state set "reassign" */
static seqBool seqg_event_reassign_0_wait_z_pv2(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 78 "../reassign.st"
	if (seq_pvConnected(seqg_env, 2/*z*/))
	{
		*seqg_pnst = 6;
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "wait_z_pv2" in state set "reassign" */
static void seqg_action_reassign_0_wait_z_pv2(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 79 "../reassign.st"
			testDiag("wait_z_pv2");
# line 80 "../reassign.st"
			testOk1(seq_pvChannelCount(seqg_env) == 3);
# line 81 "../reassign.st"
			testOk1(seq_pvConnectCount(seqg_env) == 3);
# line 82 "../reassign.st"
			testOk1(seq_pvAssignCount(seqg_env) == 3);
# line 83 "../reassign.st"
			seqShow(epicsThreadGetIdSelf());
		}
		return;
	}
}

/****** Code for state "done" in state set "reassign" ******/

/* Event function for state "done" in state set "reassign" */
static seqBool seqg_event_reassign_0_done(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 87 "../reassign.st"
	if (1)
	{
		seq_exit(seqg_env);
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "done" in state set "reassign" */
static void seqg_action_reassign_0_done(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 88 "../reassign.st"
			testPass("ok");
		}
		return;
	}
}

/* Program exit func */
static void seqg_exit(SS_ID seqg_env)
{
# line 94 "../reassign.st"
	seq_test_done();
}

#undef seqg_var

/************************ Tables ************************/

/* Channel table */
static seqChan seqg_chans[] = {
	/* chName, offset, varName, varType, count, eventNum, efId, monitored, queueSize, queueIndex */
	{"pv1", offsetof(struct seqg_vars, x), "x", P_INT, 1, 1, 0, 0, 0, 0},
	{"", offsetof(struct seqg_vars, y), "y", P_INT, 1, 2, 0, 0, 0, 0},
	{"pv1", offsetof(struct seqg_vars, z), "z", P_INT, 1, 3, 0, 0, 0, 0},
};

/* Event masks for state set "reassign" */
static const seqMask seqg_mask_reassign_0_start[] = {
	0x00000000,
};
static const seqMask seqg_mask_reassign_0_wait_x_nil[] = {
	0x00000000,
};
static const seqMask seqg_mask_reassign_0_wait_x_pv1[] = {
	0x00000002,
};
static const seqMask seqg_mask_reassign_0_wait_x_pv2[] = {
	0x00000002,
};
static const seqMask seqg_mask_reassign_0_wait_y_pv1[] = {
	0x00000004,
};
static const seqMask seqg_mask_reassign_0_wait_z_pv2[] = {
	0x00000008,
};
static const seqMask seqg_mask_reassign_0_done[] = {
	0x00000000,
};

/* State table for state set "reassign" */
static seqState seqg_states_reassign[] = {
	{
	/* state name */        "start",
	/* action function */   seqg_action_reassign_0_start,
	/* event function */    seqg_event_reassign_0_start,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_reassign_0_start,
	/* state options */     (0)
	},
	{
	/* state name */        "wait_x_nil",
	/* action function */   seqg_action_reassign_0_wait_x_nil,
	/* event function */    seqg_event_reassign_0_wait_x_nil,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_reassign_0_wait_x_nil,
	/* state options */     (0)
	},
	{
	/* state name */        "wait_x_pv1",
	/* action function */   seqg_action_reassign_0_wait_x_pv1,
	/* event function */    seqg_event_reassign_0_wait_x_pv1,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_reassign_0_wait_x_pv1,
	/* state options */     (0)
	},
	{
	/* state name */        "wait_x_pv2",
	/* action function */   seqg_action_reassign_0_wait_x_pv2,
	/* event function */    seqg_event_reassign_0_wait_x_pv2,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_reassign_0_wait_x_pv2,
	/* state options */     (0)
	},
	{
	/* state name */        "wait_y_pv1",
	/* action function */   seqg_action_reassign_0_wait_y_pv1,
	/* event function */    seqg_event_reassign_0_wait_y_pv1,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_reassign_0_wait_y_pv1,
	/* state options */     (0)
	},
	{
	/* state name */        "wait_z_pv2",
	/* action function */   seqg_action_reassign_0_wait_z_pv2,
	/* event function */    seqg_event_reassign_0_wait_z_pv2,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_reassign_0_wait_z_pv2,
	/* state options */     (0)
	},
	{
	/* state name */        "done",
	/* action function */   seqg_action_reassign_0_done,
	/* event function */    seqg_event_reassign_0_done,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_reassign_0_done,
	/* state options */     (0)
	},
};

/* State set table */
static seqSS seqg_statesets[] = {
	{
	/* state set name */    "reassign",
	/* states */            seqg_states_reassign,
	/* number of states */  7
	},
};

/* Program table (global) */
seqProgram reassignTest = {
	/* magic number */      2002003,
	/* program name */      "reassignTest",
	/* channels */          seqg_chans,
	/* num. channels */     3,
	/* state sets */        seqg_statesets,
	/* num. state sets */   1,
	/* user var size */     sizeof(struct seqg_vars),
	/* param */             "",
	/* num. event flags */  0,
	/* encoded options */   (0 | OPT_CONN | OPT_NEWEF | OPT_REENT | OPT_SAFE),
	/* init func */         seqg_init,
	/* entry func */        seqg_entry,
	/* exit func */         seqg_exit,
	/* num. queues */       0
};

#define PROG_NAME reassignTest
#include "seqMain.c"

/* Register sequencer commands and program */
#include "epicsExport.h"
static void reassignTestRegistrar (void) {
    seqRegisterSequencerCommands();
    seqRegisterSequencerProgram (&reassignTest);
}
epicsExportRegistrar(reassignTestRegistrar);