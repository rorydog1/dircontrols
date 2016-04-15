#!../../bin/linux-x86_64/dg535

## You may have to change dg535 to something else
## everywhere it appears in this file

< envPaths

cd "${TOP}"

## Register all support components
dbLoadDatabase "dbd/dg535.dbd"
dg535_registerRecordDeviceDriver pdbbase

## Load the StreamDevice path to the protocol files
epicsEnvSet ("STREAM_PROTOCOL_PATH","$(EPICS_BASE)/dg535/dg535_db_protocol")

## Configure devices
   drvAsynSerialPortConfigure("L0","/home/rory/COM8",0,0,0)
   asynSetOption("L0",-1,"baud","9600")
   asynSetOption("L0",-1,"bits","8")
   asynSetOption("L0",-1,"parity","even")
   asynSetOption("L0",-1,"stop","1")
   asynOctetSetOutputEos("L0",0,"\r")
   asynOctetSetInputEos("L0",0,"\r")

## Load record instances

dbLoadRecords("db/asynRecord.db","P=norum:,R=asyn,PORT=L0,ADDR=0,IMAX=100,OMAX=100")
dbLoadRecords("$(EPICS_BASE)/dg535/dg535_db_protocol/dg535.db","DEVICE=dg535,PORT=L0")

cd "${TOP}/iocBoot/${IOC}"
iocInit

## Start any sequence programs
#seq sncxxx,"user=roryHost"

## Testing

##General
#dbl
#dbgf dg535:StOM

##Serial Debug On
asynSetTraceIOMask("L0",-1,0x2)
asynSetTraceMask("L0",-1,0x9)

#Test output mode sequence
#dbpf dg535:StC1 3
#dbtr  dg535:GtOM
#dbtr  dg535:GtTrigM

#####Test trigger mode
#dbpf  dg535:GtTrigRateInf.PROC 1
#Should be machine values
#dbgf  dg535:StTrigRtInt
#dbgf  dg535:StTrigRtBurst

###Test Trigger settings
#Set some values local
#dbpf  dg535:StTrigRtBurst 1000
#dbpf  dg535:StTrigRtInt   8000
#Send to machine
#dbpf  dg535:StTrigRtBurst.PROC 1
#dbpf  dg535:StTrigRtInt.PROC 1
#Change local to dummy values
#dbpf  dg535:StTrigRtInt  1
#dbpf  dg535:StTrigRtBurst 1
##Should change back to set values of 1000, 8000 from machine:
#dbpf  dg535:GtTrigRateInf.PROC 1
#dbpf  dg535:StTrigRtInt.PROC 1
#dbgf  dg535:StTrigRtBurst

###Test external trigger voltage setting
#dbpf  dg535:GtExtTrig.PROC 1
#dbgf  dg535:StExtTrig
#dbpf  dg535:StExtTrig 2
#dbpf  dg535:StExtTrig.PROC 2
#dbpf  dg535:GtExtTrig.PROC 1



