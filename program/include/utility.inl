#pragma once

#include "utility.hpp"

#include <concepts>
#include <filesystem>
#include <format>
#include <fstream>
#include <iostream>
#include <iterator>
#include <mutex>
#include <string>
#include <vector>

namespace utility
{
  template <typename... message_arguments>
  exception::exception(const std::string &message_, message_arguments &&...arguments_)
    : message(std::format(
        "{}.", std::vformat(message_, std::make_format_args(std::forward<const message_arguments>(arguments_)...))))
  {
  }

  template <print_stream stream, typename... message_arguments>
  void print(std::format_string<message_arguments...> message, message_arguments &&...arguments)
  {
    std::lock_guard<std::mutex> lock(print_mutex);
    auto formatted_message = std::format(message, std::forward<message_arguments>(arguments)...);
    if constexpr (stream == COUT)
    {
      std::cout << formatted_message;
      std::cout.flush();
    }
    else if constexpr (stream == CERR)
    {
      std::cerr << formatted_message;
      std::cerr.flush();
    }
    else if constexpr (stream == CLOG)
    {
      std::clog << formatted_message;
      std::clog.flush();
    }
    else
      throw exception("Invalid print stream specification");
  }

  template <serializable type> type read_file(const std::filesystem::path &file)
  {
    if (!std::filesystem::exists(file)) throw exception("File does not exist: {}", file.string());

    std::ifstream input_file(file);
    if (!input_file.is_open()) throw exception("Failed to open file: {}", file.string());

    type container = {};
    if constexpr (std::same_as<type, std::string>)
      container.assign(std::istreambuf_iterator<char>(input_file), std::istreambuf_iterator<char>());
    else if constexpr (std::same_as<type, std::vector<std::string>>)
    {
      std::string line;
      while (std::getline(input_file, line)) container.push_back(line);
    }
    return container;
  }

  template <serializable type> void write_file(const std::filesystem::path &file, const type &container)
  {
    if (file.has_parent_path()) std::filesystem::create_directories(file.parent_path());

    std::ofstream output_file(file);
    if (!output_file.is_open()) throw exception("Failed to open file: {}", file.string());

    if constexpr (std::same_as<type, std::string>)
      output_file << container;
    else if constexpr (std::same_as<type, std::vector<std::string>>)
      for (const auto &line : container) output_file << line << '\n';
  }
}
