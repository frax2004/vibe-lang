#include <stdint.h>
#include <signal.h>
#include <stdio.h>

#include <vibe/vibe.h>


void client(int32_t argc, const char* argv[]) {

  vb_result_t result = VB_OK
  | vb_init()
  | vb_run(argc-1, argv+1)
  | vb_close()
  ;

  if(result != VB_OK) {
    fprintf(stderr, "error");
  }
}

void segfault_handler(int32_t _) {
  (void)_;
  fprintf(stderr, "Segmentation Fault.");
}

int32_t main(int32_t argc, const char* argv[]) {
  signal(SIGSEGV, segfault_handler);
  client(argc, argv);
  return 0;
}
