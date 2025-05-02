cmake_minimum_required (VERSION 3.21)
project(getBreath)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

add_subdirectory (extern/googletest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


#main
add_executable(main_exec main.cpp 
	src/beginBreathing.cpp
	src/getFunctions.cpp
	src/logUser.cpp
)
#test
add_executable(test_exec src/beginBreathing.cpp 
		src/getFunctions.cpp
		src/logUser.cpp
		test/test_main.cpp)


target_link_libraries(test_exec gtest gtest_main)

enable_testing()
add_test (NAME calculatorTests COMMAND test_exec)
