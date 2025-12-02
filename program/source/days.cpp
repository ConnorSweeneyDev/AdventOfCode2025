#include "days.hpp"

#include <functional>
#include <string>

#include "day1.hpp"
#include "day10.hpp"
#include "day11.hpp"
#include "day12.hpp"
#include "day2.hpp"
#include "day3.hpp"
#include "day4.hpp"
#include "day5.hpp"
#include "day6.hpp"
#include "day7.hpp"
#include "day8.hpp"
#include "day9.hpp"
#include "utility.hpp"

namespace days
{
  void run_part(int part, std::function<void()> part1, std::function<void()> part2)
  {
    if (part != 0 && part != 1 && part != 2) throw utility::exception("Invalid part (" + std::to_string(part) + ")");
    if (part == 0 || part == 1)
    {
      utility::print<COUT>("---------------------- Part 1 ----------------------\n");
      part1();
      utility::print<COUT>("---------------------- Part 1 ----------------------\n");
      if (part == 0) utility::print<COUT>("\n");
    }
    if (part == 0 || part == 2)
    {
      utility::print<COUT>("---------------------- Part 2 ----------------------\n");
      part2();
      utility::print<COUT>("---------------------- Part 2 ----------------------\n");
    }
  }

  void run_day(int day, int part)
  {
    switch (day)
    {
      case 1: run_part(part, day1::part1, day1::part2); break;
      case 2: run_part(part, day2::part1, day2::part2); break;
      case 3: run_part(part, day3::part1, day3::part2); break;
      case 4: run_part(part, day4::part1, day4::part2); break;
      case 5: run_part(part, day5::part1, day5::part2); break;
      case 6: run_part(part, day6::part1, day6::part2); break;
      case 7: run_part(part, day7::part1, day7::part2); break;
      case 8: run_part(part, day8::part1, day8::part2); break;
      case 9: run_part(part, day9::part1, day9::part2); break;
      case 10: run_part(part, day10::part1, day10::part2); break;
      case 11: run_part(part, day11::part1, day11::part2); break;
      case 12: run_part(part, day12::part1, day12::part2); break;
      default: throw utility::exception("Invalid day (" + std::to_string(day) + ")");
    }
  }

  void run_all_days()
  {
    for (int day = 1; day <= 12; ++day)
    {
      utility::print<COUT>("====================== Day {}{} ======================\n", (day >= 10 ? "" : " "), day);
      run_day(day, 0);
      utility::print<COUT>("====================== Day {}{} ======================\n", (day >= 10 ? "" : " "), day);
      if (day != 12) utility::print<COUT>("\n");
    }
  }
}
