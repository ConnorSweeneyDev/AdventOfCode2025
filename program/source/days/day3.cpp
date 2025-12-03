#include "day3.hpp"

#include <algorithm>
#include <cstddef>
#include <string>
#include <vector>

#include "utility.hpp"

namespace day3
{
  void part1()
  {
    auto input = utility::read_file<std::vector<std::string>>("input/day3.txt");

    int total = {};
    for (const auto &line : input)
    {
      int max = {};
      for (std::size_t index = 0; index < line.length() - 1; ++index)
      {
        int first_digit = line[index] - '0';
        int max_second_digit = {};
        for (std::size_t jndex = index + 1; jndex < line.length(); ++jndex)
          max_second_digit = std::max(max_second_digit, line[jndex] - '0');
        max = std::max(max, std::stoi(std::to_string(first_digit) + std::to_string(max_second_digit)));
      }
      total += max;
    }

    utility::print<COUT>("Answer: {}\n", total);
  }

  void part2()
  {
    auto input = utility::read_file<std::vector<std::string>>("input/day3.txt");

    long long total = {};
    for (const auto &line : input)
    {
      std::string result = {};
      std::size_t length = line.length();
      std::size_t start_positon = {};
      for (std::size_t index = 0; index < 12; ++index)
      {
        char max_digit = '0';
        std::size_t max_position = start_positon;
        std::size_t end_position = (length - 12) + index;
        for (std::size_t position = start_positon; position <= end_position; ++position)
        {
          if (line[position] > max_digit)
          {
            max_digit = line[position];
            max_position = position;
          }
        }
        result += max_digit;
        start_positon = max_position + 1;
      }
      total += std::stoll(result);
    }

    utility::print<COUT>("Answer: {}\n", total);
  }
}
