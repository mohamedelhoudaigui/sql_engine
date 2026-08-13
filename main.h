#ifndef MAIN
# define MAIN

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


typedef enum TokenTypes {
	TOKEN_SELECT,
	TOKEN_INSERT,
	TOKEN_UPDATE,
	TOKEN_DELETE,
	TOKEN_FROM,
	TOKEN_INTO,
	TOKEN_VALUES,
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

typedef struct select_s {
	Token*	column_names;
	Token*	table_name;

}	select_t;

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
Token*			prepare_and_assign_token(char* buffer_line, int start_idx, int len);
// helper operations:
char*			lower_string(char* str);
bool			is_str_num(char *str, size_t str_size);
bool			is_space_or_tab(char c);
bool			is_special_token(char c);
void			graceful_crash(char* msg);
// syntax / parser operations:
void			syntax_analyses(Token* root);
void			parse(Token* root);


#endif