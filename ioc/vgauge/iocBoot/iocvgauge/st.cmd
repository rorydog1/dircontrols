#!../../bin/linux-x86_64/vgauge

## You may have to change vgauge to something else
## everywhere it appears in this file

< envPaths

cd "${TOP}"

## Register all support components
dbLoadDatabase "dbd/vgauge.dbd"
vgauge_registerRecordDeviceDriver pdbbase

## Configure devices
   drvAsynSerialPortConfigure("L0","/dev/ttyUSB0",0,0,0)
   asynSetOption("L0",-1,"baud","9600")
   asynSetOption("L0",-1,"bits","8")
   asynSetOption("L0",-1,"parity","even")
   asynSetOption("L0",-1,"stop","1")
   asynOctetSetOutputEos("L0",0,"\r")
   asynOctetSetInputEos("L0",0,"\r")

## Load record instances
#dbLoadRecords("db/xxx.db","user=roryHost")
dbLoadRecords("db/asynRecord.db","P=norum:,R=asyn,PORT=L0,ADDR=0,IMAX=100,OMAX=100")

cd "${TOP}/iocBoot/${IOC}"
iocInit

## Start any sequence programs
#seq sncxxx,"user=roryHost"
