cmake_minimum_required(VERSION 3.8.2)

project(Devenir CXX)

##################### Finding packages ###############################

find_package(Boost REQUIRED COMPONENTS serialization)
find_package(GTest REQUIRED)

find_program(CLANG-CHECK clang-check)
message(${CLANG-CHECK})

find_program(CLANG-FORMAT clang-format)
message(${CLANG-FORMAT})

find_program(GCOV gcov)
message(${GCOV})

find_program(MAKE make)
message(${MAKE})

find_program(VALGRIND valgrind)
message(${VALGRIND})

#add_compile_options (-fprofile-arcs -ftest-coverage)
add_compile_options(-pedantic -Wall -Weffc++)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

link_libraries(gtest)
link_libraries(gtest_main)

enable_testing()

##################### Targets ###############################

function(make_test TestName)
  add_executable(${TestName} ${ARGN})
  add_custom_command(OUTPUT ${TestName}.tmp COMMAND ${VALGRIND} ${TestName} > ${TestName}.tmp)
  add_custom_target(${TestName}.c++x DEPENDS ${TestName}.tmp)

  add_test(${TestName}.check1 ${CLANG-CHECK} -extra-arg=-std=c++11 ../${TestName}.c++ --)
  add_test(${TestName}.check2 ${CLANG-CHECK} -extra-arg=-std=c++11 -analyze ../${TestName}.c++ --)
  add_test(${TestName} ${MAKE} ${TestName}.c++x)

  set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES "${TestName}.bin" "${TestName}.plist")
endfunction()

add_executable(Devenir main.cpp
    lexer/Lexer.h lexer/Lexer.cpp
    parser/Parse.h parser/Parse.cpp
    )

make_test(TestLexer lexer/TestLexer.cpp
    lexer/Lexer.h lexer/Lexer.cpp)

make_test(TestParser parser/TestParser.cpp
    lexer/Lexer.h lexer/Lexer.cpp
    parser/Parse.h parser/Parse.cpp
    )

make_test(TestOtto otto/TestOtto.cpp
    lexer/Lexer.h lexer/Lexer.cpp
    parser/Parse.h parser/Parse.cpp
    otto/Otto.h otto/Otto.cpp
    )

##################### Versions #############################

add_custom_target(versions)

set(APPS
    clang-check
    clang-format
    cmake
    doxygen
    g++
    gcov
    git
    make
    valgrind)

foreach (app ${APPS})
  add_custom_command(TARGET versions
      COMMAND echo which ${app}
      COMMAND which ${app}
      COMMAND echo ${app} --version
      COMMAND ${app} --version
      COMMAND echo)
endforeach ()

set(PKGS
    Boost
    GTest)

foreach (pkg ${PKGS})
  add_custom_command(TARGET versions
      COMMAND echo ${pkg}_VERSION
      COMMAND echo ${${pkg}_VERSION}
      COMMAND echo)
endforeach ()
