cmake_minimum_required (VERSION 3.21)
project(getBreath)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

add_subdirectory (extern/googletest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


#main
add_executable(main_exec main.cpp 
	
	"src/utils.cpp"
	
 "src/User.cpp" "src/Date.cpp" "src/BasicUser.cpp" "include/BasicUser.h" "include/PremiumUser.h" "src/PremiumUser.cpp" )
#test
add_executable(test_exec  
		"src/utils.cpp"
		
		test/test_main.cpp "src/User.cpp" "src/Date.cpp" "src/BasicUser.cpp" "include/BasicUser.h" "include/PremiumUser.h" "src/PremiumUser.cpp" )


target_link_libraries(test_exec gtest gtest_main)

enable_testing()
add_test (NAME calculatorTests COMMAND test_exec)
