#include "juliandates.hpp"

#include <cassert>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main(void) {
  std::string filePath = "dates_2020_2070.txt";

  std::vector<struct tm> datetimes;
  std::vector<int32_t> expected_values;
  int32_t num_lines = 0;

  // read File
  std::ifstream file_in(filePath.data());
  if (file_in.is_open()) {
    file_in >> num_lines;

    for (int32_t i = 0; i < num_lines; ++i) {
      int32_t year;
      int32_t month;
      int32_t mday;
      int32_t expected_weekday;

       file_in >> year;
       file_in >> month;
       file_in >> mday;
       file_in >> expected_weekday;

      struct tm st_date;
      st_date.tm_year = year - 1900;
      st_date.tm_mon = month - 1;
      st_date.tm_mday = mday;

      datetimes.push_back(st_date);
      expected_values.push_back(expected_weekday);
    }
  }
  else {
    std::cout << "Cannot Open test data file\n";
    return 1;
  }

  // Act
  for (int32_t i = 0; i < num_lines; ++i) {
    int32_t calculated_week_day = juliandates::CalcDayFromDate(datetimes[i]);

    // Assert
    std::cout << "Expected : " << expected_values[i]
              << ", Actual : " << calculated_week_day << "\n";
    assert(calculated_week_day == expected_values[i]);
  }

  return 0;
}