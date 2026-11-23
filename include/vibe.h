#pragma once
#include <stdint.h>
#include <filesystem>
#include <iostream>

#include <vector>

namespace std {
  namespace fs = filesystem;
}

namespace vibe {
  struct Result {
    enum Code : uint32_t {
      OK                  = 0,
      INVALID_INPUT_FILE  = 1 << 0,
      ALREADY_INITIALIZED = 1 << 1,
      NOT_READY           = 1 << 2,
    };

    uint32_t flags { 0 };

    Result() = default;
    Result(uint32_t flags);
    Result(Result const&) = default;
    Result(Result &&) = default;
    ~Result() = default;

    auto operator<=>(Result const&) const -> std::strong_ordering = default;
    auto operator==(Result const&) const -> bool = default;
    auto operator!=(Result const&) const -> bool = default;

    operator uint32_t() const;
    
    auto to_string() const -> std::string;
    auto hash_code() const -> std::size_t;
  };

  struct Vibe {
    auto repl(std::istream& input, std::ostream& out_channel, std::ostream& error_channel) -> Result;

    private:
    
    private:
    std::vector<std::string_view> args = { };
    std::ostream* out = nullptr;
    std::ostream* err = nullptr;
    std::istream* in = nullptr;
  };

  auto error(std::string const& msg, std::ostream& err = std::cerr) -> void;
}
