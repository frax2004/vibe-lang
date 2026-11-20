#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

#include <vibe.h>


#define RGB(r, g, b) "\033[38;2;"#r";"#g";"#b"m"
#define RED RGB(227, 61, 61)
#define GREEN RGB(121, 237, 121)
#define BLUE RGB(21, 163, 224)
#define ORANGE RGB(253, 160, 40)
#define WHITE RGB(255, 255, 255)
#define GRAY RGB(100, 100, 100)
#define RESET "\033[0m"
#define BOLD "\033[1m"

extern const char* vb_path(void);

void vb_error(const char* fmt, ...) {
  const char* path = vb_path();

  fprintf(
    stderr,
    "[%s%sError%s] in file %s%s%s: %s", 
    BOLD,
    RED, 
    RESET, 
    GRAY,
    path != NULL ? path : "<stdin>", 
    RESET,
    RED
  );

  va_list args;
  va_start(args, fmt);
  vfprintf(stderr, fmt, args);
  va_end(args);

  fprintf(stderr, "%s\n", RESET);
  fflush(stderr);
}

void vb_note(const char* fmt, ...) {
  const char* path = vb_path();

  fprintf(
    stderr,
    "[%s%sNote%s] in file %s%s%s: ", 
    BOLD,
    BLUE,  
    RESET, 
    GRAY,
    path != NULL ? path : "<stdin>", 
    RESET
  );

  va_list args;
  va_start(args, fmt);
  vfprintf(stderr, fmt, args);
  va_end(args);

  fprintf(stderr, "\n");
  fflush(stderr);
}