#include "day11.hpp"

#include <string>

#include "utility.hpp"

namespace day11
{
  const std::string &read_input()
  {
    static auto input = utility::read_file<std::string>("input/day11.txt");
    return input;
  }

  void part1() { utility::print<utility::COUT>("Day 11, Part 1\n"); }

  void part2() { utility::print<utility::COUT>("Day 11, Part 2\n"); }
}
