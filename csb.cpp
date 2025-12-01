#include "csb.hpp"

#include <string>

void configure()
{
  csb::target_name = "Advent";
  csb::target_artifact = EXECUTABLE;
  csb::target_linkage = STATIC;
  csb::target_subsystem = CONSOLE;
  csb::target_configuration = RELEASE;
  csb::cxx_standard = CXX20;
  csb::warning_level = W4;
  csb::include_files = csb::files_from({"program/include"});
  csb::source_files = csb::files_from({"program/source"});
  if (csb::host_platform == WINDOWS)
    csb::libraries = {"kernel32"};
  else if (csb::host_platform == LINUX)
    csb::libraries = {"c", "m"};
}

int clean()
{
  csb::clean_build_directory();
  csb::remove_files({"input"});
  return CSB_SUCCESS;
}

int build()
{
  if (auto session = csb::get_environment_variable("AOC_SESSION"); !session.empty())
    for (int day = 1; day <= 1; ++day)
      csb::file_install({{"https://adventofcode.com/2025/day/" + std::to_string(day) + "/input",
                          "input/day" + std::to_string(day) + ".txt"}},
                        {"-b", "session=" + session});

  if (!csb::is_subproject)
  {
    csb::clang_format("21.1.1");
    csb::generate_compile_commands();
  }
  csb::compile();
  csb::link();
  return CSB_SUCCESS;
}

int run()
{
  csb::run_target();
  return CSB_SUCCESS;
}

CSB_MAIN()
