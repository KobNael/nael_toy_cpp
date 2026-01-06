
include (unit_tests)

target_sources (unit_tests
    PRIVATE
    src/simple.test.cc
    )

##########################
# Include nael utils test
##########################
add_subdirectory( ${CMAKE_SOURCE_DIR}/nael_utils/src/test nael_tests )

target_link_libraries (unit_tests
    PRIVATE
        GTest::gtest_main
        lib_toy_cpp
    )

target_include_directories (unit_tests
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
    )

# ----------------------------------------------------------------------------
# run_unit_tests
# ----------------------------------------------------------------------------
if (${PROJECT_NAME}_WITH_COVERAGE)
    generate_coverage_report (TARGET run_unit_tests)
endif ()

if (${PROJECT_NAME}_WITH_VALGRIND)
    enable_memcheck (TARGET unit_tests)
endif ()


