#include "day1.hpp"

#include "utility.hpp"

#include <string>
#include <vector>

namespace day1
{
  auto input = utility::read_file<std::vector<std::string>>("input/day1.txt");

  void part1()
  {
    int sum = 50;
    int count = 0;
    for (const auto &line : input)
    {
      std::string direction = line.substr(0, 1);
      int number = std::stoi(line.substr(1));
      if (direction == "L")
        sum -= number;
      else if (direction == "R")
        sum += number;
      sum = ((sum % 100) + 100) % 100;
      if (sum == 0) count++;
    }
    utility::print<utility::COUT>("Answer: {}\n", count);
  }

  void part2()
  {
    auto floor_divide = [](const int x) { return x >= 0 ? x / 100 : (x - 99) / 100; };

    int sum = 50;
    int count = 0;
    for (const auto &line : input)
    {
      std::string direction = line.substr(0, 1);
      int number = std::stoi(line.substr(1));
      if (direction == "R")
      {
        count += (sum + number) / 100 - (sum / 100);
        sum += number;
      }
      else if (direction == "L")
      {
        count += floor_divide(sum - 1) - floor_divide(sum - number - 1);
        sum -= number;
      }
      sum = ((sum % 100) + 100) % 100;
    }
    utility::print<utility::COUT>("Answer: {}\n", count);
  }
}
