#include <cstdlib>
#include <exception>

#include "days.hpp"
#include "utility.hpp"

int try_main()
{
  days::run_all_days();
  return EXIT_SUCCESS;
}

int main()
{
  try
  {
    return try_main();
  }
  catch (const std::exception &error)
  {
    utility::print<CERR>("{}\n", error.what());
    return EXIT_FAILURE;
  }
}
