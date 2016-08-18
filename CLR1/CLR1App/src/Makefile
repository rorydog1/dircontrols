TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#=============================
# Build the IOC application

PROD_IOC = CLR1
# CLR1.dbd will be created and installed
DBD += CLR1.dbd

# CLR1.dbd will be made up from these files:
CLR1_DBD += base.dbd

# Include dbd files from all support applications:
CLR1_DBD += drvAsynIPPort.dbd
CLR1_DBD += mv2.dbd 

# Add all the support libraries needed by this
CLR1_LIBS += asyn
CLR1_LIBS += mv2

# CLR1_registerRecordDeviceDriver.cpp derives from CLR1.dbd
CLR1_SRCS += CLR1_registerRecordDeviceDriver.cpp

# Build the main IOC entry point on workstation OSs.
CLR1_SRCS_DEFAULT += CLR1Main.cpp
CLR1_SRCS_vxWorks += -nil-

# Add support from base/src/vxWorks if needed
#CLR1_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# Finally link to the EPICS Base libraries
CLR1_LIBS += $(EPICS_BASE_IOC_LIBS)

#===========================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

