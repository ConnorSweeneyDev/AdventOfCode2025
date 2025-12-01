#include "day4.hpp"

#include <string>

#include "utility.hpp"

namespace day4
{
  const std::string &read_input()
  {
    static auto input = utility::read_file<std::string>("input/day4.txt");
    return input;
  }

  void part1() { utility::print<utility::COUT>("Day 4, Part 1\n"); }

  void part2() { utility::print<utility::COUT>("Day 4, Part 2\n"); }
}
