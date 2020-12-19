cmake_minimum_required(VERSION 3.13)
project(netsim-grupa-3)

set(CMAKE_CXX_STANDARD 17)
add_executable(untitled1 main.cpp)
add_compile_options(-Wall -Wextra -Werror -Wpedantic -pedantic-errors -Werror=switch)
include_directories(include)
add_executable(netsim-grupa-3_debug ${SOURCE_FILES} main.cpp)

#Ustawienia testów jednostkowych
set(SOURCES_FILES_TESTS
        test/test_package.cpp
        )
# Dodaj konfigurację typu `Test`.
add_executable(netsim-grupa-3_test ${SOURCE_FILES} ${SOURCES_FILES_TESTS} test/main_gtest.cpp)
# FIXME: Uzupełnij.
# Dodaj katalogi z plikami nagłówkowymi wyłącznie do konkretnej konfiguracji (tu: `Test`).
target_include_directories(netsim-grupa-3_test PUBLIC
        googletest/googlemock/include
        googletest/googletest/include
        mocks
        )

# Dodaj podkatalog `googletest`.
add_subdirectory(googletest)
target_link_libraries(netsim-grupa-3_test gmock)
