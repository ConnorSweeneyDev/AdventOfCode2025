#include "day2.hpp"

#include <cstddef>
#include <string>
#include <vector>

#include "utility.hpp"

namespace day2
{
  void part1()
  {
    auto input = utility::read_file<std::string>("input/day2.txt");
    input.pop_back();

    std::vector<std::string> ranges = {};
    for (std::size_t index = 0; index < input.length(); ++index)
    {
      std::size_t pos = input.find(',', index);
      if (pos == std::string::npos) pos = input.length();
      ranges.push_back(input.substr(index, pos - index));
      index = pos;
    }

    auto is_invalid = [](const std::string &string) -> bool
    {
      if (string.length() % 2 != 0) return false;
      if (string.substr(0, string.length() / 2) == string.substr(string.length() / 2)) return true;
      return false;
    };

    unsigned long long sum = {};
    for (const auto &range : ranges)
    {
      std::size_t dash_pos = range.find('-');
      long long start = std::stoll(range.substr(0, dash_pos));
      long long end = std::stoll(range.substr(dash_pos + 1));
      for (long long number = start; number <= end; ++number)
        if (is_invalid(std::to_string(number))) sum += static_cast<unsigned long long>(number);
    }

    utility::print<utility::COUT>("Answer: {}\n", sum);
  }

  void part2()
  {
    auto input = utility::read_file<std::string>("input/day2.txt");
    input.pop_back();

    std::vector<std::string> ranges = {};
    for (std::size_t index = 0; index < input.length(); ++index)
    {
      std::size_t pos = input.find(',', index);
      if (pos == std::string::npos) pos = input.length();
      ranges.push_back(input.substr(index, pos - index));
      index = pos;
    }

    auto is_invalid = [](const std::string &string) -> bool
    {
      std::size_t length = string.length();
      if (length <= 1) return false;

      for (size_t pattern_length = 1; pattern_length <= length / 2; ++pattern_length)
      {
        if (length % pattern_length != 0) continue;
        std::string pattern = string.substr(0, pattern_length);

        bool is_repeating = true;
        for (size_t index = pattern_length; index < length; index += pattern_length)
        {
          if (string.substr(index, pattern_length) != pattern)
          {
            is_repeating = false;
            break;
          }
        }
        if (is_repeating) return true;
      }

      return false;
    };

    unsigned long long sum = {};
    for (const auto &range : ranges)
    {
      std::size_t dash_pos = range.find('-');
      long long start = std::stoll(range.substr(0, dash_pos));
      long long end = std::stoll(range.substr(dash_pos + 1));
      for (long long number = start; number <= end; ++number)
        if (is_invalid(std::to_string(number))) sum += static_cast<unsigned long long>(number);
    }

    utility::print<utility::COUT>("Answer: {}\n", sum);
  }
}
