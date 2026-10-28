#include <stdint.h>
#include <vibe/vibe.h>
#include <signal.h>


void segfault_handler(int32_t _) {
  (void)_;
  fprintf(stderr, "Segmentation Fault.");
}

int32_t main(int32_t argc, const char* argv[]) {
  signal(SIGSEGV, segfault_handler);

  if(argc == 1) {
    vb_init();
    vb_run(stdin, NULL, 0);
    vb_close();
  } else {
    FILE* input = fopen(argv[1], "r");

    if(input == NULL) {
      fprintf(stderr, "error: invalid input file \"%s\"\n", argv[1]);
    } else {
      vb_init();
      vb_run(input, argv+2, argc-2);
      vb_close();
      fclose(input);
    }
  }

  fflush(stdout);
  fflush(stderr);
  return 0;
}
