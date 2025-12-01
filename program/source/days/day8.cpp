#include "day8.hpp"

#include <string>

#include "utility.hpp"

namespace day8
{
  const std::string &read_input()
  {
    static auto input = utility::read_file<std::string>("input/day8.txt");
    return input;
  }

  void part1() { utility::print<utility::COUT>("Day 8, Part 1\n"); }

  void part2() { utility::print<utility::COUT>("Day 8, Part 2\n"); }
}
