#pragma once
#include <stdint.h>
#include <stdio.h>

typedef enum {
  VB_OK                 = 0,
  VB_INVALID_INPUT_FILE = 1 << 0,
} vb_result_t;

vb_result_t vb_init(void);
vb_result_t vb_eval(const char* str);
vb_result_t vb_run(uint64_t argc, const char** argv);
vb_result_t vb_close(void);
bool vb_ready(void);
