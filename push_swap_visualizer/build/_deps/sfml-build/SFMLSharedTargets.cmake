# Generated by CMake

if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" LESS 2.8)
   message(FATAL_ERROR "CMake >= 2.8.0 required")
endif()
if(CMAKE_VERSION VERSION_LESS "2.8.3")
   message(FATAL_ERROR "CMake >= 2.8.3 required")
endif()
cmake_policy(PUSH)
cmake_policy(VERSION 2.8.3...3.23)
#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

if(CMAKE_VERSION VERSION_LESS 3.0.0)
  message(FATAL_ERROR "This file relies on consumers using CMake 3.0.0 or greater.")
endif()

# Protect against multiple inclusion, which would fail when already imported targets are added once more.
set(_cmake_targets_defined "")
set(_cmake_targets_not_defined "")
set(_cmake_expected_targets "")
foreach(_cmake_expected_target IN ITEMS sfml-system sfml-window OpenGL sfml-graphics Freetype)
  list(APPEND _cmake_expected_targets "${_cmake_expected_target}")
  if(TARGET "${_cmake_expected_target}")
    list(APPEND _cmake_targets_defined "${_cmake_expected_target}")
  else()
    list(APPEND _cmake_targets_not_defined "${_cmake_expected_target}")
  endif()
endforeach()
unset(_cmake_expected_target)
if(_cmake_targets_defined STREQUAL _cmake_expected_targets)
  unset(_cmake_targets_defined)
  unset(_cmake_targets_not_defined)
  unset(_cmake_expected_targets)
  unset(CMAKE_IMPORT_FILE_VERSION)
  cmake_policy(POP)
  return()
endif()
if(NOT _cmake_targets_defined STREQUAL "")
  string(REPLACE ";" ", " _cmake_targets_defined_text "${_cmake_targets_defined}")
  string(REPLACE ";" ", " _cmake_targets_not_defined_text "${_cmake_targets_not_defined}")
  message(FATAL_ERROR "Some (but not all) targets in this export set were already defined.\nTargets Defined: ${_cmake_targets_defined_text}\nTargets not yet defined: ${_cmake_targets_not_defined_text}\n")
endif()
unset(_cmake_targets_defined)
unset(_cmake_targets_not_defined)
unset(_cmake_expected_targets)


# Create imported target sfml-system
add_library(sfml-system SHARED IMPORTED)

set_target_properties(sfml-system PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "/Users/leosohler/projectc2/push_swap/push_swap_visualizer/build/_deps/sfml-src/include"
)

# Create imported target sfml-window
add_library(sfml-window SHARED IMPORTED)

set_target_properties(sfml-window PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "/Users/leosohler/projectc2/push_swap/push_swap_visualizer/build/_deps/sfml-src/include"
  INTERFACE_LINK_LIBRARIES "sfml-system"
)

# Create imported target OpenGL
add_library(OpenGL INTERFACE IMPORTED)

set_target_properties(OpenGL PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "/Library/Developer/CommandLineTools/SDKs/MacOSX12.3.sdk/System/Library/Frameworks/OpenGL.framework"
  INTERFACE_LINK_LIBRARIES "/Library/Developer/CommandLineTools/SDKs/MacOSX12.3.sdk/System/Library/Frameworks/OpenGL.framework;/Library/Developer/CommandLineTools/SDKs/MacOSX12.3.sdk/System/Library/Frameworks/OpenGL.framework"
)

# Create imported target sfml-graphics
add_library(sfml-graphics SHARED IMPORTED)

set_target_properties(sfml-graphics PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "/Users/leosohler/projectc2/push_swap/push_swap_visualizer/build/_deps/sfml-src/include"
  INTERFACE_LINK_LIBRARIES "sfml-window"
)

# Create imported target Freetype
add_library(Freetype INTERFACE IMPORTED)

set_target_properties(Freetype PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "/Users/leosohler/projectc2/push_swap/push_swap_visualizer/build/_deps/sfml-src/extlibs/headers/freetype2;/opt/homebrew/include/freetype2"
  INTERFACE_LINK_LIBRARIES "/Users/leosohler/projectc2/push_swap/push_swap_visualizer/build/_deps/sfml-src/extlibs/libs-osx/Frameworks/freetype.framework"
)

# Import target "sfml-system" for configuration ""
set_property(TARGET sfml-system APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(sfml-system PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "/Users/leosohler/projectc2/push_swap/push_swap_visualizer/build/_deps/sfml-build/lib/libsfml-system.2.5.1.dylib"
  IMPORTED_SONAME_NOCONFIG "@rpath/libsfml-system.2.5.dylib"
  )

# Import target "sfml-window" for configuration ""
set_property(TARGET sfml-window APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(sfml-window PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "/Users/leosohler/projectc2/push_swap/push_swap_visualizer/build/_deps/sfml-build/lib/libsfml-window.2.5.1.dylib"
  IMPORTED_SONAME_NOCONFIG "@rpath/libsfml-window.2.5.dylib"
  )

# Import target "sfml-graphics" for configuration ""
set_property(TARGET sfml-graphics APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(sfml-graphics PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "/Users/leosohler/projectc2/push_swap/push_swap_visualizer/build/_deps/sfml-build/lib/libsfml-graphics.2.5.1.dylib"
  IMPORTED_SONAME_NOCONFIG "@rpath/libsfml-graphics.2.5.dylib"
  )

# This file does not depend on other imported targets which have
# been exported from the same project but in a separate export set.

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
cmake_policy(POP)
