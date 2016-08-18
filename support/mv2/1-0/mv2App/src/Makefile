TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#==================================================
# build a support library

LIBRARY_IOC += mv2

# xxxRecord.h will be created from xxxRecord.dbd
#DBDINC += xxxRecord
# install mv2.dbd into <top>/dbd
DBD += mv2.dbd 
mv2_DBD += base.dbd
mv2_DBD += drvAsynIPPort.dbd
mv2_DBD += asyn.dbd
mv2_DBD += rgamv2Include.dbd
# mv2_registerRecordDeviceDriver.cpp derives from mv2.dbd
mv2_SRCS += rgamv2.cpp 
mv2_SRCS_vxWorks += -nil-

mv2_LIBS += $(EPICS_BASE_IOC_LIBS)

#===========================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

