#!../../bin/linux-x86_64/mv2

## You may have to change mv2 to something else
## everywhere it appears in this file

< envPaths


## Register all support components
dbLoadDatabase "dbd/mv2.dbd"
mv2_registerRecordDeviceDriver pdbbase

## Load record instances
dbLoadTemplate "db/userHost.substitutions"
dbLoadRecords "db/dbSubExample.db", "user=roryHost"

## Set this to see messages from mySub
#var mySubDebug 1

## Run this to trace the stages of iocInit
#traceIocInit

cd "${TOP}/iocBoot/${IOC}"
iocInit

## Start any sequence programs
#seq sncExample, "user=roryHost"
