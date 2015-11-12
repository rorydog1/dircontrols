TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#=============================
# Build the IOC application

PROD_IOC = vgauge
# vgauge.dbd will be created and installed
DBD += vgauge.dbd

# vgauge.dbd will be made up from these files:
vgauge_DBD += base.dbd

# Include dbd files from all support applications:
vgauge_DBD += drvAsynSerialPort.dbd
vgauge_DBD += asyn.dbd
#vgauge_DBD += stream.dbd

# Add all the support libraries needed by this IOC
#vgauge_LIBS += stream
vgauge_LIBS += asyn 

# vgauge_registerRecordDeviceDriver.cpp derives from vgauge.dbd
vgauge_SRCS += vgauge_registerRecordDeviceDriver.cpp

# Build the main IOC entry point on workstation OSs.
vgauge_SRCS_DEFAULT += vgaugeMain.cpp
vgauge_SRCS_vxWorks += -nil-

# Add support from base/src/vxWorks if needed
#vgauge_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# Finally link to the EPICS Base libraries
vgauge_LIBS += $(EPICS_BASE_IOC_LIBS)

#===========================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

