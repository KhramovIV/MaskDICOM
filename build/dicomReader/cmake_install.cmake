# Install script for directory: /home/fuirm/Mask/MaskDICOM/dicomReader

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

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/dicomReader" TYPE FILE FILES
    "/home/fuirm/Mask/MaskDICOM/dicomReader/include/DicomBeam.hh"
    "/home/fuirm/Mask/MaskDICOM/dicomReader/include/DicomBeamBlock.hh"
    "/home/fuirm/Mask/MaskDICOM/dicomReader/include/DicomBeamCompensator.hh"
    "/home/fuirm/Mask/MaskDICOM/dicomReader/include/DicomBeamControlPoint.hh"
    "/home/fuirm/Mask/MaskDICOM/dicomReader/include/DicomBeamDevice.hh"
    "/home/fuirm/Mask/MaskDICOM/dicomReader/include/DicomBeamDevicePos.hh"
    "/home/fuirm/Mask/MaskDICOM/dicomReader/include/DicomBeamDeviceRef.hh"
    "/home/fuirm/Mask/MaskDICOM/dicomReader/include/DicomBeamWedge.hh"
    "/home/fuirm/Mask/MaskDICOM/dicomReader/include/DicomFileCT.hh"
    "/home/fuirm/Mask/MaskDICOM/dicomReader/include/DicomFileCT_NOdcmrt.hh"
    "/home/fuirm/Mask/MaskDICOM/dicomReader/include/DicomFileMgr.hh"
    "/home/fuirm/Mask/MaskDICOM/dicomReader/include/DicomFilePET.hh"
    "/home/fuirm/Mask/MaskDICOM/dicomReader/include/DicomFilePlan.hh"
    "/home/fuirm/Mask/MaskDICOM/dicomReader/include/DicomFileStructure.hh"
    "/home/fuirm/Mask/MaskDICOM/dicomReader/include/DicomROI.hh"
    "/home/fuirm/Mask/MaskDICOM/dicomReader/include/DicomROIContour.hh"
    "/home/fuirm/Mask/MaskDICOM/dicomReader/include/DicomVBeamDevice.hh"
    "/home/fuirm/Mask/MaskDICOM/dicomReader/include/DicomVFile.hh"
    "/home/fuirm/Mask/MaskDICOM/dicomReader/include/DicomVFileImage.hh"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libdicomReader.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libdicomReader.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libdicomReader.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/fuirm/Mask/MaskDICOM/build/dicomReader/libdicomReader.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libdicomReader.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libdicomReader.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libdicomReader.so"
         OLD_RPATH "/home/fuirm/Документы/GEANT4/geant4-v11.1.2-build/BuildProducts/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libdicomReader.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/Geant4-11.1.2/dicomReaderTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/Geant4-11.1.2/dicomReaderTargets.cmake"
         "/home/fuirm/Mask/MaskDICOM/build/dicomReader/CMakeFiles/Export/lib/Geant4-11.1.2/dicomReaderTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/Geant4-11.1.2/dicomReaderTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/Geant4-11.1.2/dicomReaderTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/Geant4-11.1.2" TYPE FILE FILES "/home/fuirm/Mask/MaskDICOM/build/dicomReader/CMakeFiles/Export/lib/Geant4-11.1.2/dicomReaderTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/Geant4-11.1.2" TYPE FILE FILES "/home/fuirm/Mask/MaskDICOM/build/dicomReader/CMakeFiles/Export/lib/Geant4-11.1.2/dicomReaderTargets-release.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/Geant4-11.1.2" TYPE FILE FILES
    "/home/fuirm/Mask/MaskDICOM/build/dicomReader/InstallTreeFiles/dicomReaderConfig.cmake"
    "/home/fuirm/Mask/MaskDICOM/build/dicomReader/InstallTreeFiles/dicomReaderConfigVersion.cmake"
    )
endif()

