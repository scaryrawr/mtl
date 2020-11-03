find_package(PkgConfig QUIET)

set(SOURCES
    ./src/string_icompare.cpp
    ./src/string_ifind.cpp
    ./src/string_replace.cpp
    ./src/string_split.cpp
    ./src/memory_out_ptr.cpp)

set(LIBRARIES mtl)
set(INCLUDE_DIRS)
set(CFLAGS)

if (${PKGCONFIG_FOUND})
    pkg_check_modules(GTEST REQUIRED gtest_main)
    set(LIBRARIES ${LIBRARIES} ${GTEST_LIBRARIES})
    set(INCLUDE_DIRS ${INCLUDE_DIRS} ${GTEST_INCLUDE_DIRS})
    set(CFLAGS ${CFLAGS} ${GTEST_CFLAGS})
else()
    include(FetchContent)
    FetchContent_Declare(
        gtest
        GIT_REPOSITORY https://github.com/google/googletest
        GIT_TAG release-1.10.0
    )

    set(FETCHCONTENT_QUIET OFF)
    FetchContent_MakeAvailable(gtest)

    set(LIBRARIES ${LIBRARIES} gtest_main)
endif()


add_executable(mtltests ${SOURCES})

target_link_libraries(mtltests ${LIBRARIES})
target_include_directories(mtltests PRIVATE ${INCLUDE_DIRS})
target_compile_options(mtltests PRIVATE ${CFLAGS})

add_test(mtltests mtltests)
