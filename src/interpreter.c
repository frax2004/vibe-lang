#include <stdio.h>
#include <stdlib.h>

#include <vibe/vibe.h>

extern void vb_error(const char* fmt, ...);
extern void vb_note(const char* fmt, ...);

static struct {
  bool         isReady;
  const char** argv;
  uint64_t     argc;
  FILE*        input;
  const char*  path;
} self = { 0 };

bool vb_ready(void) {
  return self.isReady;
}

const char* vb_path(void) {
  return self.path;
}

vb_result_t vb_init(void) {
  if(self.isReady) return VB_ALREADY_INITIALIZED;
  self.isReady = true;
  self.argc = 0;
  self.argv = NULL;
  self.path = "<stdin>";
  self.input = stdin;

  return VB_OK;
}

vb_result_t vb_eval(const char* str) {
  
  return VB_OK;
}

vb_result_t vb_run(uint64_t argc, const char** argv) {

  if(argc == 0) return VB_OK;
  
  const char* path = argv[0];
  FILE* stream = fopen(path, "r");

  if(stream == NULL) {
    vb_error("invalid input file \"%s\"", path);
    
    return VB_INVALID_INPUT_FILE;
  }

  self.argc = argc-1;
  self.argv = argv+1;
  self.path = path;
  self.input = stream;

  return vb_eval(NULL);
}

vb_result_t vb_close(void) {
  if(!self.isReady) return VB_NOT_READY;

  if(self.input != stdin) {
    fclose(self.input);
  }

  self.argc = 0;
  self.argv = NULL;
  self.path = NULL;
  self.input = NULL;
  self.isReady = false;

  fflush(stderr);
  fflush(stdout);

  return VB_OK;
}

