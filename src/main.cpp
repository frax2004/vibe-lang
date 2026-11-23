#include <csignal>
#include <print>
#include <fstream>

#include <vibe.h>

auto client(int32_t argc, const char* argv[]) -> void {
  std::span args{ argv+1, static_cast<size_t>(argc-1) };

  vibe::Vibe vibe{};

  if(args.empty()) {
    vibe.repl(std::cin, std::cout, std::cerr);
  } else {
    std::fs::path path = std::fs::canonical(args[0]);
    if(not std::fs::exists(path)) {
      vibe::error("Invalid input file.");
      return;
    }

    std::ifstream input { path };

    vibe.repl(input, std::cout, std::cerr);
  }
}

auto main(int32_t argc, const char* argv[]) -> int32_t {
  std::signal(SIGSEGV, [](int32_t _) {
    (void)_;
    std::println(stderr, "Segmentation Fault.");
  });

  client(argc, argv);
  return 0;
}
