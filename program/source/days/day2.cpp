#include "day2.hpp"

#include <string>

#include "utility.hpp"

namespace day2
{
  const std::string &read_input()
  {
    static auto input = utility::read_file<std::string>("input/day2.txt");
    return input;
  }

  void part1() { utility::print<utility::COUT>("Day 2, Part 1\n"); }

  void part2() { utility::print<utility::COUT>("Day 2, Part 2\n"); }
}
