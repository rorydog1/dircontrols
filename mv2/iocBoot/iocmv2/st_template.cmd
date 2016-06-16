#!../../bin/linux-x86_64-debug/mv2

## You may have to change mv2 to something else
## everywhere it appears in this file

< envPathsLargeArray
cd ${TOP}

## Register all support components
dbLoadDatabase "dbd/mv2.dbd"
mv2_registerRecordDeviceDriver pdbbase



##Connect
drvAsynIPPortConfigure("<PIN>","148.79.130.57:10014",0,0,0)

mv2init("<POU>","<PIN>","<SN>")
dbLoadRecords("db/rgamv2.template","device=<DEV>,PORT=<POU>")

cd "${TOP}/iocBoot/${IOC}"
iocInit


