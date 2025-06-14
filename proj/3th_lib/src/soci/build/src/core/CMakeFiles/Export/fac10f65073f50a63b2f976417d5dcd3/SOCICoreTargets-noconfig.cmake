#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "SOCI::Core" for configuration ""
set_property(TARGET SOCI::Core APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(SOCI::Core PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libsoci_core.so.4.1.2"
  IMPORTED_SONAME_NOCONFIG "libsoci_core.so.4"
  )

list(APPEND _cmake_import_check_targets SOCI::Core )
list(APPEND _cmake_import_check_files_for_SOCI::Core "${_IMPORT_PREFIX}/lib/libsoci_core.so.4.1.2" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
