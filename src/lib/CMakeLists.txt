# ============================================================================
# External requirements
# ============================================================================

# ----------------------------------------------------------------------------
# Boost
# ----------------------------------------------------------------------------

find_package (Boost REQUIRED)

# ============================================================================
# Targets configuration
# ============================================================================

configure_file (${CMAKE_SOURCE_DIR}/cmake-modules/nael_version.hh.in ${CMAKE_CURRENT_BINARY_DIR}/toy_cpp_version.hh)

add_library (lib_toy_cpp)

set_target_properties (lib_toy_cpp
	PROPERTIES
		OUTPUT_NAME lib_toy_cpp
	)

target_sources (lib_toy_cpp
	PRIVATE
	src/bo/BoIn.cc
	src/bo/FirstClass.cc
	src/bo/SecondClass.cc
	src/dto_handler/dto_handler.cc
	)

set_default_warnings (TARGET lib_toy_cpp)

target_include_directories (lib_toy_cpp
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
	)

target_link_libraries (lib_toy_cpp
	PUBLIC
		nael_utils::nael_utils
	)

if (NOT ${PROJECT_NAME}_AS_SUBMODULE AND ${PROJECT_NAME}_WITH_COVERAGE)
	enable_coverage(TARGET lib_toy_cpp)
endif()

# ============================================================================
# Install configuration
# ============================================================================

install (TARGETS lib_toy_cpp EXPORT lib_toy_cpp-export
	INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install (DIRECTORY src/lib_toy_cpp
	DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
	FILES_MATCHING
		PATTERN "*.hh"
		PATTERN "*.tpp"
)

install (FILES ${CMAKE_CURRENT_BINARY_DIR}/toy_cpp_version.hh
	DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install (EXPORT lib_toy_cpp-export
	FILE ${PROJECT_NAME}-targets.cmake
	NAMESPACE ${PROJECT_NAME}::
	DESTINATION "${ConfigPackageLocation}"
)

# ----------------------------------------------------------------------------
# Export configuration
# ----------------------------------------------------------------------------
add_library (${PROJECT_NAME}::lib_toy_cpp ALIAS lib_toy_cpp)

