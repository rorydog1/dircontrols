#!../../bin/linux-x86_64/vgauge

## You may have to change vgauge to something else
## everywhere it appears in this file

< envPaths
cd "${TOP}"
dbLoadDatabase "dbd/vgauge.dbd"

dbLoadRecords("DB_alice_test/alice.db")

cd "${TOP}/iocBoot/${IOC}"
iocInit

## Start any sequence programs
#seq sncxxx,"user=roryHost"
