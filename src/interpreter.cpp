#include <vibe.h>
#include <vibe/token.h>

namespace vibe {

  auto Vibe::repl(std::istream& input, std::ostream& out_channel, std::ostream& error_channel) -> Result {
    this->in = &input;
    this->out = &out_channel;
    this->err = &error_channel;

    // execute

    this->out->flush();
    this->err->flush();

    this->in = nullptr;
    this->out = nullptr;
    this->err = nullptr;
  }
}
