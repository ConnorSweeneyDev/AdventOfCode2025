#include "utility.hpp"

#include <string>

namespace utility
{
  const char *exception::what() const noexcept
  {
    if (message.empty()) return "Unknown exception.";
    return message.c_str();
  }
}
