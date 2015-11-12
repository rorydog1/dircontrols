/* C code for program cppCommentTest, generated by snc from ../cppComment.st */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>

#include "seq_snc.h"

/* Variable declarations */


/* Function declarations */

#define seqg_var (*(struct seqg_vars *const *)seqg_env)

/* Program init func */
static void seqg_init(PROG_ID seqg_env)
{
}

/****** Code for state "simple" in state set "simple" ******/

/* Event function for state "simple" in state set "simple" */
static seqBool seqg_event_simple_0_simple(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
	if (TRUE)
	{
		seq_exit(seqg_env);
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "simple" in state set "simple" */
static void seqg_action_simple_0_simple(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
		}
		return;
	}
}

/* Program exit func */
static void seqg_exit(SS_ID seqg_env)
{
# line 8 "../cppComment.st"
	int x = 0 + 0 - 0 * 0;
# line 10 "../cppComment.st"
	printf("%d", x);
}

#undef seqg_var

/************************ Tables ************************/

/* No channel definitions */
#define seqg_chans 0

/* Event masks for state set "simple" */
static const seqMask seqg_mask_simple_0_simple[] = {
	0x00000000,
};

/* State table for state set "simple" */
static seqState seqg_states_simple[] = {
	{
	/* state name */        "simple",
	/* action function */   seqg_action_simple_0_simple,
	/* event function */    seqg_event_simple_0_simple,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_simple_0_simple,
	/* state options */     (0)
	},
};

/* State set table */
static seqSS seqg_statesets[] = {
	{
	/* state set name */    "simple",
	/* states */            seqg_states_simple,
	/* number of states */  1
	},
};

/* Program table (global) */
seqProgram cppCommentTest = {
	/* magic number */      2002003,
	/* program name */      "cppCommentTest",
	/* channels */          seqg_chans,
	/* num. channels */     0,
	/* state sets */        seqg_statesets,
	/* num. state sets */   1,
	/* user var size */     0,
	/* param */             "",
	/* num. event flags */  0,
	/* encoded options */   (0 | OPT_CONN | OPT_NEWEF),
	/* init func */         seqg_init,
	/* entry func */        0,
	/* exit func */         seqg_exit,
	/* num. queues */       0
};

#define PROG_NAME cppCommentTest
#include "seqMain.c"

/* Register sequencer commands and program */
#include "epicsExport.h"
static void cppCommentTestRegistrar (void) {
    seqRegisterSequencerCommands();
    seqRegisterSequencerProgram (&cppCommentTest);
}
epicsExportRegistrar(cppCommentTestRegistrar);
