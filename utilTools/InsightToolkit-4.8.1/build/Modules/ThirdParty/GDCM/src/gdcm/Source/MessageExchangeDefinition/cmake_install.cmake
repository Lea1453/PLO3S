# Install script for directory: /home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Libraries")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libitkgdcmMEXD-4.8.so.1" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libitkgdcmMEXD-4.8.so.1")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libitkgdcmMEXD-4.8.so.1"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/jeremy/kit/InsightToolkit-4.8.1/build/lib/libitkgdcmMEXD-4.8.so.1")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libitkgdcmMEXD-4.8.so.1" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libitkgdcmMEXD-4.8.so.1")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libitkgdcmMEXD-4.8.so.1"
         OLD_RPATH "/home/jeremy/kit/InsightToolkit-4.8.1/build/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libitkgdcmMEXD-4.8.so.1")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "DebugDevel")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libitkgdcmMEXD-4.8.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libitkgdcmMEXD-4.8.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libitkgdcmMEXD-4.8.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/jeremy/kit/InsightToolkit-4.8.1/build/lib/libitkgdcmMEXD-4.8.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libitkgdcmMEXD-4.8.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libitkgdcmMEXD-4.8.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libitkgdcmMEXD-4.8.so"
         OLD_RPATH "/home/jeremy/kit/InsightToolkit-4.8.1/build/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libitkgdcmMEXD-4.8.so")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.8" TYPE FILE FILES
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmBasePDU.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmAReleaseRPPDU.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmCompositeMessageFactory.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmNDeleteMessages.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmRoleSelectionSub.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmPDataTFPDU.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmPDUFactory.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmCFindMessages.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmFindPatientRootQuery.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmApplicationContext.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmCommandDataSet.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmFindStudyRootQuery.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmCStoreMessages.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmULConnectionInfo.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmAAssociateRJPDU.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmSOPClassExtendedNegociationSub.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmQueryImage.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmCMoveMessages.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmAReleaseRQPDU.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmAsynchronousOperationsWindowSub.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmModalityPerformedProcedureStepCreateQuery.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmULConnection.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmULAction.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmServiceClassApplicationInformation.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmBaseCompositeMessage.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmAAbortPDU.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmMaximumLengthSub.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmULWritingCallback.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmULTransitionTable.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmNetworkEvents.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmULConnectionManager.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmBaseRootQuery.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmAbstractSyntax.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmBaseNormalizedMessage.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmARTIMTimer.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmULActionDT.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmPresentationContext.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmCompositeNetworkFunctions.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmWLMFindQuery.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmAAssociateACPDU.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmULConnectionCallback.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmMoveStudyRootQuery.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmQueryPatient.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmPresentationContextAC.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmModalityPerformedProcedureStepSetQuery.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmImplementationVersionNameSub.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmPresentationContextGenerator.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmNActionMessages.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmNCreateMessages.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmImplementationClassUIDSub.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmULActionAA.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmQueryBase.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmDIMSE.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmULActionAR.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmULEvent.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmImplementationUIDSub.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmPresentationDataValue.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmULActionAE.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmTransferSyntaxSub.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmNSetMessages.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmNEventReportMessages.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmNormalizedNetworkFunctions.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmNormalizedMessageFactory.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmUserInformation.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmAAssociateRQPDU.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmMovePatientRootQuery.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmCEchoMessages.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmPresentationContextRQ.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmNetworkStateID.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmServiceClassUser.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmNGetMessages.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmBaseQuery.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmQuerySeries.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmQueryFactory.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmQueryStudy.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MessageExchangeDefinition/gdcmULBasicCallback.h"
    )
endif()

