/* C code for program seqCmdBtns, generated by snc from ../cmdButtons.st */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>

#include "seq_snc.h"

/* Variable declarations */
struct seqg_vars {
# line 26 "../cmdButtons.st"
	short startBtn;
# line 27 "../cmdButtons.st"
	short stopBtn;
# line 30 "../cmdButtons.st"
	string seqMsg;
# line 33 "../cmdButtons.st"
	int ix;
};


/* Function declarations */

#define seqg_var (*(struct seqg_vars *const *)seqg_env)

/* Program init func */
static void seqg_init(PROG_ID seqg_env)
{
}

/****** Code for state "init" in state set "seqCmdBtns" ******/

/* Event function for state "init" in state set "seqCmdBtns" */
static seqBool seqg_event_seqCmdBtns_0_init(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 38 "../cmdButtons.st"
	if (seq_pvConnectCount(seqg_env) == seq_pvChannelCount(seqg_env))
	{
		*seqg_pnst = 1;
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "init" in state set "seqCmdBtns" */
static void seqg_action_seqCmdBtns_0_init(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 39 "../cmdButtons.st"
			printf("seqCmdBtns: All channels connected.\n");
# line 40 "../cmdButtons.st"
			sprintf(seqg_var->seqMsg, "Ready");
# line 41 "../cmdButtons.st"
			seq_pvPutTmo(seqg_env, 2/*seqMsg*/, DEFAULT, DEFAULT_TIMEOUT);
		}
		return;
	}
}

/****** Code for state "idle" in state set "seqCmdBtns" ******/

/* Event function for state "idle" in state set "seqCmdBtns" */
static seqBool seqg_event_seqCmdBtns_0_idle(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 46 "../cmdButtons.st"
	if (seq_pvConnectCount(seqg_env) < seq_pvChannelCount(seqg_env))
	{
		*seqg_pnst = 0;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 53 "../cmdButtons.st"
	if (seqg_var->startBtn)
	{
		*seqg_pnst = 2;
		*seqg_ptrn = 1;
		return TRUE;
	}
# line 59 "../cmdButtons.st"
	if (seqg_var->stopBtn)
	{
		*seqg_pnst = 1;
		*seqg_ptrn = 2;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "idle" in state set "seqCmdBtns" */
static void seqg_action_seqCmdBtns_0_idle(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 47 "../cmdButtons.st"
			printf("seqCmdBtns: Lost pv connection.\n");
# line 48 "../cmdButtons.st"
			sprintf(seqg_var->seqMsg, "Lost connection");
# line 49 "../cmdButtons.st"
			seq_pvPutTmo(seqg_env, 2/*seqMsg*/, DEFAULT, DEFAULT_TIMEOUT);
		}
		return;
	case 1:
		{
# line 54 "../cmdButtons.st"
			sprintf(seqg_var->seqMsg, "0 s");
# line 55 "../cmdButtons.st"
			seq_pvPutTmo(seqg_env, 2/*seqMsg*/, DEFAULT, DEFAULT_TIMEOUT);
		}
		return;
	case 2:
		{
# line 60 "../cmdButtons.st"
			seqg_var->stopBtn = 0;
# line 61 "../cmdButtons.st"
			seq_pvPutTmo(seqg_env, 1/*stopBtn*/, DEFAULT, DEFAULT_TIMEOUT);
		}
		return;
	}
}

/****** Code for state "start" in state set "seqCmdBtns" ******/

/* Event function for state "start" in state set "seqCmdBtns" */
static seqBool seqg_event_seqCmdBtns_0_start(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 69 "../cmdButtons.st"
	if (seqg_var->startBtn)
	{
		*seqg_pnst = 1;
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "start" in state set "seqCmdBtns" */
static void seqg_action_seqCmdBtns_0_start(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 70 "../cmdButtons.st"
			for (seqg_var->ix = 1; seqg_var->ix <= 10; seqg_var->ix++)
			{
# line 71 "../cmdButtons.st"
				if (seqg_var->stopBtn)
				{
# line 72 "../cmdButtons.st"
					seqg_var->stopBtn = 0;
# line 73 "../cmdButtons.st"
					seq_pvPutTmo(seqg_env, 1/*stopBtn*/, DEFAULT, DEFAULT_TIMEOUT);
					break;
				}
				else
				{
# line 76 "../cmdButtons.st"
					epicsThreadSleep(1);
# line 77 "../cmdButtons.st"
					sprintf(seqg_var->seqMsg, "%d s", seqg_var->ix);
# line 78 "../cmdButtons.st"
					seq_pvPutTmo(seqg_env, 2/*seqMsg*/, DEFAULT, DEFAULT_TIMEOUT);
				}
			}
# line 84 "../cmdButtons.st"
			seqg_var->startBtn = 0;
# line 85 "../cmdButtons.st"
			seq_pvPutTmo(seqg_env, 0/*startBtn*/, DEFAULT, DEFAULT_TIMEOUT);
		}
		return;
	}
}

#undef seqg_var

/************************ Tables ************************/

/* Channel table */
static seqChan seqg_chans[] = {
	/* chName, offset, varName, varType, count, eventNum, efId, monitored, queueSize, queueIndex */
	{"{P}start", offsetof(struct seqg_vars, startBtn), "startBtn", P_SHORT, 1, 1, 0, 1, 0, 0},
	{"{P}stop", offsetof(struct seqg_vars, stopBtn), "stopBtn", P_SHORT, 1, 2, 0, 1, 0, 0},
	{"{P}seqMsg", offsetof(struct seqg_vars, seqMsg), "seqMsg", P_STRING, 1, 3, 0, 0, 0, 0},
};

/* Event masks for state set "seqCmdBtns" */
static const seqMask seqg_mask_seqCmdBtns_0_init[] = {
	0x00000000,
};
static const seqMask seqg_mask_seqCmdBtns_0_idle[] = {
	0x00000006,
};
static const seqMask seqg_mask_seqCmdBtns_0_start[] = {
	0x00000002,
};

/* State table for state set "seqCmdBtns" */
static seqState seqg_states_seqCmdBtns[] = {
	{
	/* state name */        "init",
	/* action function */   seqg_action_seqCmdBtns_0_init,
	/* event function */    seqg_event_seqCmdBtns_0_init,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_seqCmdBtns_0_init,
	/* state options */     (0)
	},
	{
	/* state name */        "idle",
	/* action function */   seqg_action_seqCmdBtns_0_idle,
	/* event function */    seqg_event_seqCmdBtns_0_idle,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_seqCmdBtns_0_idle,
	/* state options */     (0)
	},
	{
	/* state name */        "start",
	/* action function */   seqg_action_seqCmdBtns_0_start,
	/* event function */    seqg_event_seqCmdBtns_0_start,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_seqCmdBtns_0_start,
	/* state options */     (0)
	},
};

/* State set table */
static seqSS seqg_statesets[] = {
	{
	/* state set name */    "seqCmdBtns",
	/* states */            seqg_states_seqCmdBtns,
	/* number of states */  3
	},
};

/* Program table (global) */
seqProgram seqCmdBtns = {
	/* magic number */      2002003,
	/* program name */      "seqCmdBtns",
	/* channels */          seqg_chans,
	/* num. channels */     3,
	/* state sets */        seqg_statesets,
	/* num. state sets */   1,
	/* user var size */     sizeof(struct seqg_vars),
	/* param */             "P=cmdBtns:",
	/* num. event flags */  0,
	/* encoded options */   (0 | OPT_NEWEF | OPT_REENT),
	/* init func */         seqg_init,
	/* entry func */        0,
	/* exit func */         0,
	/* num. queues */       0
};

/* Register sequencer commands and program */
#include "epicsExport.h"
static void seqCmdBtnsRegistrar (void) {
    seqRegisterSequencerCommands();
    seqRegisterSequencerProgram (&seqCmdBtns);
}
epicsExportRegistrar(seqCmdBtnsRegistrar);
