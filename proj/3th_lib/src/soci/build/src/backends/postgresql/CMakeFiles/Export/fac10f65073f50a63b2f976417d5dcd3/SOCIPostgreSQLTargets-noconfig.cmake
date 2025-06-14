#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "SOCI::PostgreSQL" for configuration ""
set_property(TARGET SOCI::PostgreSQL APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(SOCI::PostgreSQL PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libsoci_postgresql.so.4.1.2"
  IMPORTED_SONAME_NOCONFIG "libsoci_postgresql.so.4"
  )

list(APPEND _cmake_import_check_targets SOCI::PostgreSQL )
list(APPEND _cmake_import_check_files_for_SOCI::PostgreSQL "${_IMPORT_PREFIX}/lib/libsoci_postgresql.so.4.1.2" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
