#include "day9.hpp"

#include <string>

#include "utility.hpp"

namespace day9
{
  const std::string &read_input()
  {
    static auto input = utility::read_file<std::string>("input/day9.txt");
    return input;
  }

  void part1() { utility::print<utility::COUT>("Day 9, Part 1\n"); }

  void part2() { utility::print<utility::COUT>("Day 9, Part 2\n"); }
}
