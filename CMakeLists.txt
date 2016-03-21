cmake_minimum_required(VERSION 3.4)

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in
               googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This adds
# the following targets: gtest, gtest_main, gmock
# and gmock_main
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
                 ${CMAKE_BINARY_DIR}/googletest-build)

# The gtest/gmock targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include"
                      "${gmock_SOURCE_DIR}/include")
endif()

# Now simply link your own targets against gtest, gmock,
# etc. as appropriate

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(test_adcs
  test/test.cpp
  test/api/test_adcs_api.cpp
  test/geomagnetic_field/test_adcs_geomagnetic_field.cpp
  test/disturbance_torques/test_adcs_face_div.cpp

  src/api/adcs_api.c
  src/geomagnetic_field/adcs_geomagnetic_field.c
  src/disturbance_torques/adcs_face_div.c
)

target_link_libraries(test_adcs gtest gmock)
target_include_directories(test_adcs PRIVATE
  test
  include
  include/geomagnetic_field
  include/disturbance_torques
)

add_library(adcs
  src/api/adcs_api.c
  src/geomagnetic_field/adcs_geomagnetic_field.c
  src/disturbance_torques/adcs_face_div.c
)

target_include_directories(adcs PRIVATE
  include
  src
)

set(CMAKE_C_FLAGS "-Werror -Wall -Wextra -Wformat=2 -Wswitch-default -Wcast-align -Wpointer-arith -Wbad-function-cast -Wstrict-prototypes -Winline -Wundef -Wnested-externs -Wcast-qual -Wshadow -Wwrite-strings -Wconversion -Wunreachable-code -Wstrict-aliasing=2 -fno-common -fstrict-aliasing -std=c89 -pedantic -O3 -DNDEBUG -funroll-loops")
