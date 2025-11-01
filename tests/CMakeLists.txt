file(GLOB source_list "*.cpp")

add_executable(test_tetravex ${source_list})
target_include_directories(test_tetravex PRIVATE ../include/)
target_link_libraries(test_tetravex tetravex gtest gtest_main)