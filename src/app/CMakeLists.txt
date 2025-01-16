find_package (Boost REQUIRED COMPONENTS program_options)

add_executable (toy_cpp)

set_target_properties (toy_cpp
	PROPERTIES
		OUTPUT_NAME toy_cpp
	)

target_sources (toy_cpp
	PRIVATE
	src/main.cc
	)

set_default_warnings (TARGET toy_cpp)

target_include_directories (toy_cpp
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
	)

target_link_libraries (toy_cpp
	PRIVATE
        lib_toy_cpp
		Boost::program_options
	)

# ============================================================================
# Install configuration
# ============================================================================

install (TARGETS toy_cpp EXPORT toy_cpp-export)

# ----------------------------------------------------------------------------
# Export configuration
# ----------------------------------------------------------------------------

add_executable (${PROJECT_NAME}::toy_cpp ALIAS toy_cpp)

