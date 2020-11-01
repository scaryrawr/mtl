find_package(PkgConfig REQUIRED)

pkg_check_modules(GTEST REQUIRED gtest_main)

set(SOURCES
    ./src/string_icompare.cpp
    ./src/string_ifind.cpp
    ./src/string_replace.cpp
    ./src/string_split.cpp
    ./src/memory_out_ptr.cpp)

add_executable(mtltests ${SOURCES})

target_link_libraries(mtltests mtl ${GTEST_LIBRARIES})
target_include_directories(mtltests PRIVATE ${GTEST_INCLUDE_DIRS})
target_compile_options(mtltests PRIVATE ${GTEST_CFLAGS_OTHER})

add_test(mtltests mtltests)
