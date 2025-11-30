#pragma once

#include <concepts>
#include <exception>
#include <filesystem>
#include <format>
#include <mutex>
#include <string>
#include <vector>

namespace utility
{
  class exception : public std::exception
  {
  public:
    template <typename... message_arguments> exception(const std::string &message_, message_arguments &&...arguments_);
    const char *what() const noexcept override;

  protected:
    std::string message = {};
  };

  enum print_stream
  {
    COUT,
    CERR,
    CLOG
  };
  template <print_stream stream, typename... message_arguments>
  void print(std::format_string<message_arguments...> message, message_arguments &&...arguments);
  inline static std::mutex print_mutex = {};

  template <typename type>
  concept serializable = std::same_as<type, std::string> || std::same_as<type, std::vector<std::string>>;
  template <serializable type> type read_file(const std::filesystem::path &file);
  template <serializable type> void write_file(const std::filesystem::path &file, const type &container);
}

#include "utility.inl"
