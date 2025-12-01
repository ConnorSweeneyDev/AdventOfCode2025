#include "day7.hpp"

#include <string>

#include "utility.hpp"

namespace day7
{
  const std::string &read_input()
  {
    static auto input = utility::read_file<std::string>("input/day7.txt");
    return input;
  }

  void part1() { utility::print<utility::COUT>("Day 7, Part 1\n"); }

  void part2() { utility::print<utility::COUT>("Day 7, Part 2\n"); }
}
