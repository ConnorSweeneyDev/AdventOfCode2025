#include "day10.hpp"

#include <string>

#include "utility.hpp"

namespace day10
{
  const std::string &read_input()
  {
    static auto input = utility::read_file<std::string>("input/day10.txt");
    return input;
  }

  void part1() { utility::print<utility::COUT>("Day 10, Part 1\n"); }

  void part2() { utility::print<utility::COUT>("Day 10, Part 2\n"); }
}
