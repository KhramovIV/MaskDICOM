#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "dicomReader" for configuration "Release"
set_property(TARGET dicomReader APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(dicomReader PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libdicomReader.so"
  IMPORTED_SONAME_RELEASE "libdicomReader.so"
  )

list(APPEND _cmake_import_check_targets dicomReader )
list(APPEND _cmake_import_check_files_for_dicomReader "${_IMPORT_PREFIX}/lib/libdicomReader.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
