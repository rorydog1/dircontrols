#!../../bin/linux-x86_64-debug/mv2

## You may have to change mv2 to something else
## everywhere it appears in this file

< envPathsLargeArray
cd ${TOP}

## Register all support components
dbLoadDatabase "dbd/mv2.dbd"
mv2_registerRecordDeviceDriver pdbbase



##Connect
drvAsynIPPortConfigure("L1","148.79.130.57:10014",0,0,0)

mv2init("A1","L1","<SN1>")
dbLoadRecords("db/rgamv2.template","device=rga1,PORT=A1")

drvAsynIPPortConfigure("L2","148.79.130.57:10014",0,0,0)

mv2init("A2","L2","<SN2>")
dbLoadRecords("db/rgamv2.template","device=rga2,PORT=A2")

drvAsynIPPortConfigure("L3","148.79.130.57:10014",0,0,0)

mv2init("A3","L3","<SN3>")
dbLoadRecords("db/rgamv2.template","device=rga3,PORT=A3")

drvAsynIPPortConfigure("L4","148.79.130.57:10014",0,0,0)

mv2init("A4","L4","<SN4>")
dbLoadRecords("db/rgamv2.template","device=rga4,PORT=A4")

cd "${TOP}/iocBoot/${IOC}"
iocInit

