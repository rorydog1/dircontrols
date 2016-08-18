#!../../bin/linux-x86_64/CLR1

## You may have to change CLR1 to something else
## everywhere it appears in this file

< envPaths
epicsEnvSet("EPICS_CA_MAX_ARRAY_BYTES","100000")

cd "${TOP}"

## Register all support components
dbLoadDatabase "dbd/CLR1.dbd"
CLR1_registerRecordDeviceDriver pdbbase

## Load record instances
dbLoadRecords("db/mv2.db")

drvAsynIPPortConfigure("L1","148.79.212.92:10014",0,0,0)
mv2init("A1","L1","MKS104-90716010")

drvAsynIPPortConfigure("L2","148.79.212.92:10014",0,0,0)
mv2init("A2","L2","MKS104-90716011")

drvAsynIPPortConfigure("L3","148.79.212.92:10014",0,0,0)
mv2init("A3","L3","MKS104-90716012")

drvAsynIPPortConfigure("L4","148.79.212.92:10014",0,0,0)
mv2init("A4","L4","MKS104-90716013")


cd "${TOP}/iocBoot/${IOC}"
iocInit

