# Add unit test executables
add_executable(test_weekday test_weekday.cpp)
add_executable(test_weekday_bulk test_weekday_bulk.cpp)

# Link the library to the tests
target_link_libraries(test_weekday juliandates)
target_link_libraries(test_weekday_bulk juliandates)

# Add tests to CTest
add_test(NAME TestWeekDay COMMAND test_weekday)
add_test(NAME TestWeekDayBulk COMMAND test_weekday_bulk WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/tests)
