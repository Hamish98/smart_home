# Install script for directory: /root/proj/3th_lib/src/soci/src/core

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/root/proj/3th_lib/bin")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
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

if(CMAKE_INSTALL_COMPONENT STREQUAL "soci_runtime" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoci_core.so.4.1.2"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoci_core.so.4"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "\$ORIGIN")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/root/proj/3th_lib/src/soci/build/lib/libsoci_core.so.4.1.2"
    "/root/proj/3th_lib/src/soci/build/lib/libsoci_core.so.4"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoci_core.so.4.1.2"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoci_core.so.4"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHANGE
           FILE "${file}"
           OLD_RPATH ":::::::"
           NEW_RPATH "\$ORIGIN")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "soci_development" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/root/proj/3th_lib/src/soci/build/lib/libsoci_core.so")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "soci_development" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/soci" TYPE FILE FILES
    "/root/proj/3th_lib/src/soci/include/soci/backend-loader.h"
    "/root/proj/3th_lib/src/soci/include/soci/bind-values.h"
    "/root/proj/3th_lib/src/soci/include/soci/blob-exchange.h"
    "/root/proj/3th_lib/src/soci/include/soci/blob.h"
    "/root/proj/3th_lib/src/soci/include/soci/boost-fusion.h"
    "/root/proj/3th_lib/src/soci/include/soci/boost-gregorian-date.h"
    "/root/proj/3th_lib/src/soci/include/soci/boost-optional.h"
    "/root/proj/3th_lib/src/soci/include/soci/boost-tuple.h"
    "/root/proj/3th_lib/src/soci/include/soci/callbacks.h"
    "/root/proj/3th_lib/src/soci/include/soci/column-info.h"
    "/root/proj/3th_lib/src/soci/include/soci/connection-parameters.h"
    "/root/proj/3th_lib/src/soci/include/soci/connection-pool.h"
    "/root/proj/3th_lib/src/soci/include/soci/error.h"
    "/root/proj/3th_lib/src/soci/include/soci/exchange-traits.h"
    "/root/proj/3th_lib/src/soci/include/soci/fixed-size-ints.h"
    "/root/proj/3th_lib/src/soci/include/soci/into-type.h"
    "/root/proj/3th_lib/src/soci/include/soci/into.h"
    "/root/proj/3th_lib/src/soci/include/soci/is-detected.h"
    "/root/proj/3th_lib/src/soci/include/soci/log-context.h"
    "/root/proj/3th_lib/src/soci/include/soci/logger.h"
    "/root/proj/3th_lib/src/soci/include/soci/noreturn.h"
    "/root/proj/3th_lib/src/soci/include/soci/once-temp-type.h"
    "/root/proj/3th_lib/src/soci/include/soci/prepare-temp-type.h"
    "/root/proj/3th_lib/src/soci/include/soci/procedure.h"
    "/root/proj/3th_lib/src/soci/include/soci/query_transformation.h"
    "/root/proj/3th_lib/src/soci/include/soci/ref-counted-prepare-info.h"
    "/root/proj/3th_lib/src/soci/include/soci/ref-counted-statement.h"
    "/root/proj/3th_lib/src/soci/include/soci/row-exchange.h"
    "/root/proj/3th_lib/src/soci/include/soci/row.h"
    "/root/proj/3th_lib/src/soci/include/soci/rowid-exchange.h"
    "/root/proj/3th_lib/src/soci/include/soci/rowid.h"
    "/root/proj/3th_lib/src/soci/include/soci/rowset.h"
    "/root/proj/3th_lib/src/soci/include/soci/session.h"
    "/root/proj/3th_lib/src/soci/include/soci/soci-backend.h"
    "/root/proj/3th_lib/src/soci/include/soci/soci-platform.h"
    "/root/proj/3th_lib/src/soci/include/soci/soci-simple.h"
    "/root/proj/3th_lib/src/soci/include/soci/soci-types.h"
    "/root/proj/3th_lib/src/soci/include/soci/soci-unicode.h"
    "/root/proj/3th_lib/src/soci/include/soci/soci.h"
    "/root/proj/3th_lib/src/soci/include/soci/statement.h"
    "/root/proj/3th_lib/src/soci/include/soci/std-optional.h"
    "/root/proj/3th_lib/src/soci/include/soci/transaction.h"
    "/root/proj/3th_lib/src/soci/include/soci/trivial-blob-backend.h"
    "/root/proj/3th_lib/src/soci/include/soci/type-conversion-traits.h"
    "/root/proj/3th_lib/src/soci/include/soci/type-conversion.h"
    "/root/proj/3th_lib/src/soci/include/soci/type-holder.h"
    "/root/proj/3th_lib/src/soci/include/soci/type-ptr.h"
    "/root/proj/3th_lib/src/soci/include/soci/type-wrappers.h"
    "/root/proj/3th_lib/src/soci/include/soci/use-type.h"
    "/root/proj/3th_lib/src/soci/include/soci/use.h"
    "/root/proj/3th_lib/src/soci/include/soci/values-exchange.h"
    "/root/proj/3th_lib/src/soci/include/soci/values.h"
    "/root/proj/3th_lib/src/soci/include/soci/version.h"
    "/root/proj/3th_lib/src/soci/build/include/soci/soci-config.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "soci_development" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/soci-4.1.2/SOCICoreTargets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/soci-4.1.2/SOCICoreTargets.cmake"
         "/root/proj/3th_lib/src/soci/build/src/core/CMakeFiles/Export/fac10f65073f50a63b2f976417d5dcd3/SOCICoreTargets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/soci-4.1.2/SOCICoreTargets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/soci-4.1.2/SOCICoreTargets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/soci-4.1.2" TYPE FILE FILES "/root/proj/3th_lib/src/soci/build/src/core/CMakeFiles/Export/fac10f65073f50a63b2f976417d5dcd3/SOCICoreTargets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/soci-4.1.2" TYPE FILE FILES "/root/proj/3th_lib/src/soci/build/src/core/CMakeFiles/Export/fac10f65073f50a63b2f976417d5dcd3/SOCICoreTargets-noconfig.cmake")
  endif()
endif()

