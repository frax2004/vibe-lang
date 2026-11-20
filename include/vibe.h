#pragma once
#include <stdint.h>
#include <stdio.h>

typedef uint64_t vb_result_t;
const vb_result_t VB_OK                  = 0;
const vb_result_t VB_INVALID_INPUT_FILE  = 1 << 0;
const vb_result_t VB_ALREADY_INITIALIZED = 1 << 1;
const vb_result_t VB_NOT_READY           = 1 << 2;

vb_result_t vb_init(void);
vb_result_t vb_eval(const char* str);
vb_result_t vb_run(uint64_t argc, const char** argv);
vb_result_t vb_close(void);
bool vb_ready(void);
