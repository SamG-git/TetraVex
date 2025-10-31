add_executable(test_tetravex test_tetravex.cpp)
target_include_directories(test_tetravex PRIVATE ../include/)
target_link_libraries(test_tetravex tetravex gtest gtest_main)