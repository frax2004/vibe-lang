#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <vibe.h>

typedef int64_t vb_token_type_t;
typedef int32_t vb_token_tag_t;

typedef struct {
  vb_token_type_t type;
  struct {
    union {
      char*   as_str;
      double  as_double;
      int64_t as_int;
      char    as_char;
    };
    vb_token_tag_t tag;
  };
} vb_token_t;

extern void vb_error(const char* fmt, ...);
extern void vb_note(const char* fmt, ...);
static int32_t vb_token_compare(vb_token_t, vb_token_t);

static const struct {
  vb_token_tag_t STR;
  vb_token_tag_t DOUBLE;
  vb_token_tag_t INT;
  vb_token_tag_t CHAR;
} Tags = {
  .STR = 1,
  .DOUBLE = 2,
  .INT = 3,
  .CHAR = 4,
};

static const struct {
  vb_result_t OK;
  vb_result_t INVALID_INPUT_FILE;
  vb_result_t ALREADY_INITIALIZED;
  vb_result_t NOT_READY;
} Result = {
  .OK = VB_OK,
  .INVALID_INPUT_FILE = VB_INVALID_INPUT_FILE,
  .ALREADY_INITIALIZED = VB_ALREADY_INITIALIZED,
  .NOT_READY = VB_NOT_READY,
};

static const struct {
  struct {
    vb_token_type_t $;
    vb_token_type_t IDENTIFIER;
    vb_token_type_t NUMBER;
    vb_token_type_t STRING;
    vb_token_type_t CHAR;
    vb_token_type_t WHILE;
    vb_token_type_t FOR;
    vb_token_type_t ASSIGN;
    vb_token_type_t FALSE;
    vb_token_type_t TRUE;
    vb_token_type_t ARROW;
    vb_token_type_t COLUMN;
    vb_token_type_t COMMA;
    vb_token_type_t DOT;
    vb_token_type_t DOTDOT;
    vb_token_type_t LPAR;
    vb_token_type_t RPAR;
    vb_token_type_t LBRACE;
    vb_token_type_t RBRACE;
    vb_token_type_t LSQUARE;
    vb_token_type_t RSQUARE;
    vb_token_type_t IF;
    vb_token_type_t ELSE;
    vb_token_type_t PRINT;
  } Type;

  vb_token_t $;
  vb_token_t WHILE;
  vb_token_t FOR;
  vb_token_t ASSIGN;
  vb_token_t FALSE;
  vb_token_t TRUE;
  vb_token_t ARROW;
  vb_token_t COLUMN;
  vb_token_t COMMA;
  vb_token_t DOT;
  vb_token_t DOTDOT;
  vb_token_t LPAR;
  vb_token_t RPAR;
  vb_token_t LBRACE;
  vb_token_t RBRACE;
  vb_token_t LSQUARE;
  vb_token_t RSQUARE;
  vb_token_t IF;
  vb_token_t ELSE;
  vb_token_t PRINT;
} Token = {
  .Type.$ = -1,
  .Type.IDENTIFIER = 1,
  .Type.NUMBER = 2,
  .Type.STRING = 3,
  .Type.CHAR = 4,
  .Type.WHILE = 5,
  .Type.FOR = 6,
  .Type.ASSIGN = 7,
  .Type.FALSE = 8,
  .Type.TRUE = 9,
  .Type.ARROW = 10,
  .Type.COLUMN = 11,
  .Type.COMMA = 12,
  .Type.DOT = 13,
  .Type.DOTDOT = 14,
  .Type.LPAR = 15,
  .Type.RPAR = 16,
  .Type.LBRACE = 17,
  .Type.RBRACE = 18,
  .Type.LSQUARE = 19,
  .Type.RSQUARE = 20,
  .Type.IF = 21,
  .Type.ELSE = 22,
  .Type.PRINT = 23,
  .$ = {
    .type = Token.Type.$,
    .tag = Tags.STR,
    .as_str = "",
  },
  .WHILE = {
    .type = Token.Type.WHILE,
    .tag = Tags.STR,
    .as_str = "while",
  },
  .FOR = {
    .type = Token.Type.FOR,
    .tag = Tags.STR,
    .as_str = "for",
  },
  .ASSIGN = {
    .type = Token.Type.ASSIGN,
    .tag = Tags.STR,
    .as_str = "=",
  },
  .FALSE = {
    .type = Token.Type.FALSE,
    .tag = Tags.STR,
    .as_str = "false",
  },
  .TRUE = {
    .type = Token.Type.TRUE,
    .tag = Tags.STR,
    .as_str = "true",
  },
  .ARROW = {
    .type = Token.Type.ARROW,
    .tag = Tags.STR,
    .as_str = "=>",
  },
  .COLUMN = {
    .type = Token.Type.COLUMN,
    .tag = Tags.STR,
    .as_str = ":",
  },
  .COMMA = {
    .type = Token.Type.COMMA,
    .tag = Tags.STR,
    .as_str = ",",
  },
  .DOT = {
    .type = Token.Type.DOT,
    .tag = Tags.STR,
    .as_str = ".",
  },
  .DOTDOT = {
    .type = Token.Type.DOTDOT,
    .tag = Tags.STR,
    .as_str = "..",
  },
  .LPAR = {
    .type = Token.Type.LPAR,
    .tag = Tags.STR,
    .as_str = "(",
  },
  .RPAR = {
    .type = Token.Type.RPAR,
    .tag = Tags.STR,
    .as_str = ")",
  },
  .LBRACE = {
    .type = Token.Type.LBRACE,
    .tag = Tags.STR,
    .as_str = "{",
  },
  .RBRACE = {
    .type = Token.Type.RBRACE,
    .tag = Tags.STR,
    .as_str = "}",
  },
  .LSQUARE = {
    .type = Token.Type.LSQUARE,
    .tag = Tags.STR,
    .as_str = "[",
  },
  .RSQUARE = {
    .type = Token.Type.RSQUARE,
    .tag = Tags.STR,
    .as_str = "]",
  },
  .IF = {
    .type = Token.Type.IF,
    .tag = Tags.STR,
    .as_str = "if",
  },
  .ELSE = {
    .type = Token.Type.ELSE,
    .tag = Tags.STR,
    .as_str = "else",
  },
  .PRINT = {
    .type = Token.Type.PRINT,
    .tag = Tags.STR,
    .as_str = "print",
  },
};

static struct {
  bool         isReady;
  const char** argv;
  uint64_t     argc;
  FILE*        input;
  const char*  path;
} self = {
  .isReady = 0,
  .argv = 0,
  .argc = 0,
  .input = 0,
  .path = 0,
};


int32_t vb_token_compare(vb_token_t lhs, vb_token_t rhs) {
  if(lhs.type - rhs.type != 0) return lhs.type - rhs.type;
  if(lhs.tag - rhs.tag != 0) return lhs.tag - rhs.tag;

  return lhs.tag == Tags.STR ? strcmp(lhs.as_str, rhs.as_str)
  : lhs.tag == Tags.DOUBLE ? (lhs.as_double < rhs.as_double ? -1 : lhs.as_double == rhs.as_double ? 0 : 1)
  : lhs.tag == Tags.INT ? (lhs.as_int < rhs.as_int ? -1 : lhs.as_int == rhs.as_int ? 0 : 1)
  : lhs.tag == Tags.CHAR ? (lhs.as_char < rhs.as_char ? -1 : lhs.as_char == rhs.as_char ? 0 : 1)
  : 0
  ; 
}

bool vb_ready(void) {
  return self.isReady;
}

const char* vb_path(void) {
  return self.path;
}

vb_result_t vb_init(void) {
  if(self.isReady) return Result.ALREADY_INITIALIZED;
  self.isReady = true;
  self.argc = 0;
  self.argv = NULL;
  self.path = "<stdin>";
  self.input = stdin;

  return Result.OK;
}



vb_result_t vb_eval(const char* str) {
  (void)str;


  return Result.OK;
}

vb_result_t vb_run(uint64_t argc, const char** argv) {

  if(argc == 0) return Result.OK;
  
  const char* path = argv[0];
  FILE* stream = fopen(path, "r");

  if(stream == NULL) {
    vb_error("invalid input file \"%s\"", path);
    return Result.INVALID_INPUT_FILE;
  }

  self.argc = argc-1;
  self.argv = argv+1;
  self.path = path;
  self.input = stream;

  return Result.OK;
}

vb_result_t vb_close(void) {
  if(!self.isReady) return Result.NOT_READY;

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

  return Result.OK;
}

