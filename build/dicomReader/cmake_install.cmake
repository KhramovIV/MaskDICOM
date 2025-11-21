# Install script for directory: /home/vanya/MODELLING/dicomReader

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

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/dicomReader" TYPE FILE FILES
    "/home/vanya/MODELLING/dicomReader/include/DicomBeam.hh"
    "/home/vanya/MODELLING/dicomReader/include/DicomBeamBlock.hh"
    "/home/vanya/MODELLING/dicomReader/include/DicomBeamCompensator.hh"
    "/home/vanya/MODELLING/dicomReader/include/DicomBeamControlPoint.hh"
    "/home/vanya/MODELLING/dicomReader/include/DicomBeamDevice.hh"
    "/home/vanya/MODELLING/dicomReader/include/DicomBeamDevicePos.hh"
    "/home/vanya/MODELLING/dicomReader/include/DicomBeamDeviceRef.hh"
    "/home/vanya/MODELLING/dicomReader/include/DicomBeamWedge.hh"
    "/home/vanya/MODELLING/dicomReader/include/DicomFileCT.hh"
    "/home/vanya/MODELLING/dicomReader/include/DicomFileCT_NOdcmrt.hh"
    "/home/vanya/MODELLING/dicomReader/include/DicomFileMgr.hh"
    "/home/vanya/MODELLING/dicomReader/include/DicomFilePET.hh"
    "/home/vanya/MODELLING/dicomReader/include/DicomFilePlan.hh"
    "/home/vanya/MODELLING/dicomReader/include/DicomFileStructure.hh"
    "/home/vanya/MODELLING/dicomReader/include/DicomROI.hh"
    "/home/vanya/MODELLING/dicomReader/include/DicomROIContour.hh"
    "/home/vanya/MODELLING/dicomReader/include/DicomVBeamDevice.hh"
    "/home/vanya/MODELLING/dicomReader/include/DicomVFile.hh"
    "/home/vanya/MODELLING/dicomReader/include/DicomVFileImage.hh"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libdicomReader.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libdicomReader.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libdicomReader.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/vanya/MODELLING/build/dicomReader/libdicomReader.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libdicomReader.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libdicomReader.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libdicomReader.so"
         OLD_RPATH "/opt/geant4-v11.3.2/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libdicomReader.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  include("/home/vanya/MODELLING/build/dicomReader/CMakeFiles/dicomReader.dir/install-cxx-module-bmi-Release.cmake" OPTIONAL)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/Geant4-11.3.2/dicomReaderTargets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/Geant4-11.3.2/dicomReaderTargets.cmake"
         "/home/vanya/MODELLING/build/dicomReader/CMakeFiles/Export/2acb06591c73bcb50e7a32d23e6a2a24/dicomReaderTargets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/Geant4-11.3.2/dicomReaderTargets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/Geant4-11.3.2/dicomReaderTargets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/Geant4-11.3.2" TYPE FILE FILES "/home/vanya/MODELLING/build/dicomReader/CMakeFiles/Export/2acb06591c73bcb50e7a32d23e6a2a24/dicomReaderTargets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/Geant4-11.3.2" TYPE FILE FILES "/home/vanya/MODELLING/build/dicomReader/CMakeFiles/Export/2acb06591c73bcb50e7a32d23e6a2a24/dicomReaderTargets-release.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/Geant4-11.3.2" TYPE FILE FILES
    "/home/vanya/MODELLING/build/dicomReader/InstallTreeFiles/dicomReaderConfig.cmake"
    "/home/vanya/MODELLING/build/dicomReader/InstallTreeFiles/dicomReaderConfigVersion.cmake"
    )
endif()

