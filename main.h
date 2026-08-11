#ifndef MAIN
# define MAIN
// supported operations in sql:
// select
// update
// delete
// insert

// supported operations in meta commands:
//.exit


// basic CRUCD options for now

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

#include "gb_malloc.h"


#define MINIMUM_BUFFER_SIZE 128
#define EXIT_C ".exit"

// static const char* vocab[] = {
// 	"select",
// 	"update",
// 	"delete",
// 	"insert",
// 	"from",
// 	"into",
// 	"set",
// };

typedef enum TokenTypes {
	TOKEN_SELECT,
	TOKEN_FROM,
	TOKEN_INSERT,
	TOKEN_INTO,
	TOKEN_VALUES,
	TOKEN_UPDATE,
	TOKEN_DELETE,
	TOKEN_SET,
	TOKEN_WHERE,
	TOKEN_BRACKET_OPEN,
	TOKEN_BRACKET_CLOSE,
	TOKEN_COMMA,
	TOKEN_EQUAL,
	TOKEN_NUM,
	TOKEN_IDENTIFIER,

}	TokenTypes;

typedef struct InputBuffer {
    char    *buffer;
    size_t  buffer_size;
    size_t  input_size;

}   InputBuffer;

typedef struct Token {
	char		*token;
	size_t		token_size;
	TokenTypes	token_type;
	struct Token*		next;

}	Token;

// buffer operations:
InputBuffer*	create_input_buffer();
void			read_from_input(InputBuffer* input_buffer);
// parser operations:
void			branch_to_coammand(Token* root);
Token*			tokens_builder(InputBuffer* input_buffer);
void			assign_token_type(Token* token);
// token operations:
Token*			create_token(char* value);
void			debug_token(Token* token_seq);
void			append_token(Token** root_addr, Token* token);
// helper operations:
char*			lower_string(char* str);
bool			is_str_num(char *str, size_t str_size);


#endif