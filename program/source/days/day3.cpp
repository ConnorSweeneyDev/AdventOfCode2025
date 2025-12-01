#include "day3.hpp"

#include <string>

#include "utility.hpp"

namespace day3
{
  const std::string &read_input()
  {
    static auto input = utility::read_file<std::string>("input/day3.txt");
    return input;
  }

  void part1() { utility::print<utility::COUT>("Day 3, Part 1\n"); }

  void part2() { utility::print<utility::COUT>("Day 3, Part 2\n"); }
}
