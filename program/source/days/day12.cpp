#include "day12.hpp"

#include <string>

#include "utility.hpp"

namespace day12
{
  const std::string &read_input()
  {
    static auto input = utility::read_file<std::string>("input/day12.txt");
    return input;
  }

  void part1() { utility::print<utility::COUT>("Day 12, Part 1\n"); }

  void part2() { utility::print<utility::COUT>("Day 12, Part 2\n"); }
}
