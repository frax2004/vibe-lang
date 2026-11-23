#include <print>
#include <vibe.h>

using namespace std::string_literals;

namespace vibe::inline detail {
  auto rgb(uint8_t r, uint8_t  g, uint8_t b) -> std::string {
    return std::format("\033[38;2;{};{};{}m", r, g, b);
  }
  
  static const auto RED = rgb(227, 61, 61);
  static const auto GREEN = rgb(121, 237, 121);
  static const auto BLUE = rgb(21, 163, 224);
  static const auto ORANGE = rgb(253, 160, 40);
  static const auto WHITE = rgb(255, 255, 255);
  static const auto GRAY = rgb(100, 100, 100);
  static const auto RESET = "\033[0m"s;
  static const auto BOLD = "\033[1m"s;
}


namespace vibe {

  auto error(std::string const& msg, std::ostream& err) -> void {
    std::println(
      err, 
      "[{}{}Error{}]: {}{}{}", 
      BOLD,
      RED, 
      RESET, 
      RED,
      msg,
      RESET
    );

    err.flush();
  }
}