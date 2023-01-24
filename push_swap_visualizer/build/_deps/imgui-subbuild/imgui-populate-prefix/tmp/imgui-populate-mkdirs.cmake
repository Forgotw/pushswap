# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/leosohler/projectc2/pushswap42/push_swap_visualizer/build/_deps/imgui-src"
  "/Users/leosohler/projectc2/pushswap42/push_swap_visualizer/build/_deps/imgui-build"
  "/Users/leosohler/projectc2/pushswap42/push_swap_visualizer/build/_deps/imgui-subbuild/imgui-populate-prefix"
  "/Users/leosohler/projectc2/pushswap42/push_swap_visualizer/build/_deps/imgui-subbuild/imgui-populate-prefix/tmp"
  "/Users/leosohler/projectc2/pushswap42/push_swap_visualizer/build/_deps/imgui-subbuild/imgui-populate-prefix/src/imgui-populate-stamp"
  "/Users/leosohler/projectc2/pushswap42/push_swap_visualizer/build/_deps/imgui-subbuild/imgui-populate-prefix/src"
  "/Users/leosohler/projectc2/pushswap42/push_swap_visualizer/build/_deps/imgui-subbuild/imgui-populate-prefix/src/imgui-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/leosohler/projectc2/pushswap42/push_swap_visualizer/build/_deps/imgui-subbuild/imgui-populate-prefix/src/imgui-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/leosohler/projectc2/pushswap42/push_swap_visualizer/build/_deps/imgui-subbuild/imgui-populate-prefix/src/imgui-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
