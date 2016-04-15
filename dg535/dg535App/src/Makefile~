TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS BELOW HERE

# xxxRecord.h will be created from xxxRecord.dbd
DBDINC += xxxRecord

# Install xxxSupport.dbd into <top>/dbd
DBD += xxxSupport.dbd

# Build an IOC support library
LIBRARY_IOC += dg535Support

# Compile and add the code to the support library
dg535Support_SRCS += xxxRecord.c
dg535Support_SRCS += devXxxSoft.c

# Link locally-provided code into the support library,
# rather than directly into the IOC application.
# This is required for Windows DLL builds.
dg535Support_SRCS += dbSubExample.c
dg535Support_SRCS += dg535Hello.c
dg535Support_SRCS += initTrace.c

dg535Support_LIBS += $(EPICS_BASE_IOC_LIBS)

# Build the IOC application
PROD_IOC = dg535

# dg535.dbd will be created and installed
DBD += dg535.dbd

# dg535.dbd will include these files:
dg535_DBD += base.dbd
dg535_DBD += xxxSupport.dbd
dg535_DBD += dbSubExample.dbd
dg535_DBD += dg535Hello.dbd
dg535_DBD += initTrace.dbd
dg535_DBD += drvAsynSerialPort.dbd
dg535_DBD += asyn.dbd
dg535_DBD += stream.dbd

# Add all the support libraries needed by this IOC
dg535_LIBS += stream
dg535_LIBS += asyn 


# dg535_registerRecordDeviceDriver.cpp derives from dg535.dbd
dg535_SRCS += dg535_registerRecordDeviceDriver.cpp

# Build the main IOC entry point where needed
dg535_SRCS_DEFAULT += dg535Main.cpp
dg535_SRCS_vxWorks += -nil-

# Add support from base/src/vxWorks if needed
#dg535_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# Link in the code from our support library
dg535_LIBS += dg535Support

# To build SNL programs, SNCSEQ must be defined
# in the <top>/configure/RELEASE file
ifneq ($(SNCSEQ),)
    # Build sncExample into dg535Support
    sncExample_SNCFLAGS += +r
    dg535_DBD += sncExample.dbd
    dg535Support_SRCS += sncExample.stt
    dg535Support_LIBS += seq pv
    dg535_LIBS += seq pv

    # Build sncProgram as a standalone program
    PROD_HOST += sncProgram
    sncProgram_SNCFLAGS += +m
    sncProgram_SRCS += sncProgram.st
    sncProgram_LIBS += seq pv
    sncProgram_LIBS += $(EPICS_BASE_HOST_LIBS)
endif

# Finally link IOC to the EPICS Base libraries
dg535_LIBS += $(EPICS_BASE_IOC_LIBS)

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD EXTRA GNUMAKE RULES BELOW HERE

