#include <vibe/vibe.h>

typedef struct {
  bool         isReady;
  const char** argv;
  uint64_t     argc;
  FILE*        input;
} Vibe;

static Vibe self = { 0 };

void vb_init(void) {
  self.isReady = true;
}

void vb_run(FILE* input, const char* argv[], uint64_t argc) {
  self.argv = argv;
  self.argc = argc;
  self.input = input;
}

void vb_close(void) {
  self.isReady = false;  
}
