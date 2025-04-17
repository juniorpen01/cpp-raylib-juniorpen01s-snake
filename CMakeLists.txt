cmake_minimum_required(VERSION 4.0.1)
project(Juniorpen01sSnake CXX)

set(EXE_NAME juniorpen01s_snake)

include(FetchContent)

FetchContent_Declare(
	raylib
	GIT_REPOSITORY https://github.com/raysan5/raylib.git
	GIT_TAG 5.5
	GIT_SHALLOW
	SYSTEM
)
FetchContent_MakeAvailable(raylib)

file(GLOB_RECURSE sources src/*.cpp)
add_library(core ${sources})
target_include_directories(core PUBLIC include)
target_compile_options(
	core PUBLIC
	$<$<CXX_COMPILER_ID:GNU,Clang>:-Wall -Wextra -Wpedantic -Werror>
	$<$<CXX_COMPILER_ID:MSVC>:/W4 /WX /permissive->
)

target_link_libraries(core raylib)

add_executable(${EXE_NAME} src/main.cpp)
target_link_libraries(${EXE_NAME} core)

install(TARGETS ${EXE_NAME} RUNTIME DESTINATION bin)
install(DIRECTORY assets DESTINATION bin/assets)

FetchContent_Declare(
	doctest
	GIT_REPOSITORY https://github.com/doctest/doctest.git
	GIT_TAG v2.4.11
	GIT_SHALLOW
	SYSTEM
)
FetchContent_MakeAvailable(doctest)

include(CTest)
if(BUILD_TESTING)
	file(GLOB_RECURSE test_sources tests/*_test.cpp)
	foreach(test_source IN LISTS test_sources)
		cmake_path(GET test_source STEM test_source_name)
		add_executable(${test_source_name} ${test_source})
		target_compile_definitions(
			${test_source_name}
			PRIVATE
			DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
		)
		target_link_libraries(${test_source_name} core doctest::doctest)
		add_test(NAME ${test_source_name} COMMAND ${test_source_name})
	endforeach()
endif()
