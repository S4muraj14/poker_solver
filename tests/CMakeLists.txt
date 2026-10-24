include(GoogleTest)

add_executable(ps_tests smoke_test.cpp)
target_link_libraries(ps_tests PRIVATE ps GTest::gtest_main)
gtest_discover_tests(ps_tests)
