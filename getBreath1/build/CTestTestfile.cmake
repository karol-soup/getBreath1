# CMake generated Testfile for 
# Source directory: C:/Users/Karol Suarez/Desktop/getBreath1/getBreath1
# Build directory: C:/Users/Karol Suarez/Desktop/getBreath1/getBreath1/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test([=[calculatorTests]=] "C:/Users/Karol Suarez/Desktop/getBreath1/getBreath1/build/Debug/test_exec.exe")
  set_tests_properties([=[calculatorTests]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Karol Suarez/Desktop/getBreath1/getBreath1/CMakeLists.txt;28;add_test;C:/Users/Karol Suarez/Desktop/getBreath1/getBreath1/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test([=[calculatorTests]=] "C:/Users/Karol Suarez/Desktop/getBreath1/getBreath1/build/Release/test_exec.exe")
  set_tests_properties([=[calculatorTests]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Karol Suarez/Desktop/getBreath1/getBreath1/CMakeLists.txt;28;add_test;C:/Users/Karol Suarez/Desktop/getBreath1/getBreath1/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test([=[calculatorTests]=] "C:/Users/Karol Suarez/Desktop/getBreath1/getBreath1/build/MinSizeRel/test_exec.exe")
  set_tests_properties([=[calculatorTests]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Karol Suarez/Desktop/getBreath1/getBreath1/CMakeLists.txt;28;add_test;C:/Users/Karol Suarez/Desktop/getBreath1/getBreath1/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test([=[calculatorTests]=] "C:/Users/Karol Suarez/Desktop/getBreath1/getBreath1/build/RelWithDebInfo/test_exec.exe")
  set_tests_properties([=[calculatorTests]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Karol Suarez/Desktop/getBreath1/getBreath1/CMakeLists.txt;28;add_test;C:/Users/Karol Suarez/Desktop/getBreath1/getBreath1/CMakeLists.txt;0;")
else()
  add_test([=[calculatorTests]=] NOT_AVAILABLE)
endif()
subdirs("extern/googletest")
