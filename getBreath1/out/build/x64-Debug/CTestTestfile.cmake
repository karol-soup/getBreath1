# CMake generated Testfile for 
# Source directory: C:/Users/Karol Suarez/Desktop/getBreath1/getBreath1
# Build directory: C:/Users/Karol Suarez/Desktop/getBreath1/getBreath1/out/build/x64-Debug
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[calculatorTests]=] "C:/Users/Karol Suarez/Desktop/getBreath1/getBreath1/out/build/x64-Debug/test_exec.exe")
set_tests_properties([=[calculatorTests]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Karol Suarez/Desktop/getBreath1/getBreath1/CMakeLists.txt;28;add_test;C:/Users/Karol Suarez/Desktop/getBreath1/getBreath1/CMakeLists.txt;0;")
subdirs("extern/googletest")
