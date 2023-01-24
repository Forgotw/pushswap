# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/leosohler/projectc2/pushswap42/push_swap_visualizer/build/_deps/sfml-src"
  "/Users/leosohler/projectc2/pushswap42/push_swap_visualizer/build/_deps/sfml-build"
  "/Users/leosohler/projectc2/pushswap42/push_swap_visualizer/build/_deps/sfml-subbuild/sfml-populate-prefix"
  "/Users/leosohler/projectc2/pushswap42/push_swap_visualizer/build/_deps/sfml-subbuild/sfml-populate-prefix/tmp"
  "/Users/leosohler/projectc2/pushswap42/push_swap_visualizer/build/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp"
  "/Users/leosohler/projectc2/pushswap42/push_swap_visualizer/build/_deps/sfml-subbuild/sfml-populate-prefix/src"
  "/Users/leosohler/projectc2/pushswap42/push_swap_visualizer/build/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/leosohler/projectc2/pushswap42/push_swap_visualizer/build/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/leosohler/projectc2/pushswap42/push_swap_visualizer/build/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
