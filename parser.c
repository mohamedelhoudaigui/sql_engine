#include "main.h"

// parsing operations

void	assign_token_type(Token* token)
{
	if (strncmp(token->token, "select", token->token_size) == 0)
		token->token_type = TOKEN_SELECT;
	else if (strncmp(token->token, "from", token->token_size) == 0)
		token->token_type = TOKEN_FROM;
	else if (strncmp(token->token, "insert", token->token_size) == 0)
		token->token_type = TOKEN_INSERT;
	else if (strncmp(token->token, "into", token->token_size) == 0)
		token->token_type = TOKEN_INTO;
	else if (strncmp(token->token, "values", token->token_size) == 0)
		token->token_type = TOKEN_VALUES;
	else if (strncmp(token->token, "update", token->token_size) == 0)
		token->token_type = TOKEN_UPDATE;
	else if (strncmp(token->token, "delete", token->token_size) == 0)
		token->token_type = TOKEN_DELETE;
	else if (strncmp(token->token, "set", token->token_size) == 0)
		token->token_type = TOKEN_SET;
	else if (strncmp(token->token, "where", token->token_size) == 0)
		token->token_type = TOKEN_WHERE;
	else if (strncmp(token->token, "=", token->token_size) == 0)
		token->token_type = TOKEN_EQUAL;
	else if (strncmp(token->token, "(", token->token_size) == 0)
		token->token_type = TOKEN_BRACKET_OPEN;
	else if (strncmp(token->token, ")", token->token_size) == 0)
		token->token_type = TOKEN_BRACKET_CLOSE;
	else if (strncmp(token->token, ",", token->token_size) == 0)
		token->token_type = TOKEN_COMMA;
	else if (is_str_num(token->token, token->token_size) == true)
		token->token_type = TOKEN_NUM;
	else
		token->token_type = TOKEN_IDENTIFIER;
}

Token*	prepare_and_assign_token(char* buffer_line, int start_idx, int len)
{
	Token* token = NULL;
	token = create_token(strndup(buffer_line + start_idx, len));
	assign_token_type(token);
	return (token);
}


Token*	tokens_builder(InputBuffer* input_buffer)
{
	char*	buffer_line = input_buffer->buffer;
	Token*	root = NULL;

	size_t i = 0;
	for (;i < input_buffer->buffer_size; ++i)
	{
		// skip spaces
		if (is_space_or_tab(buffer_line[i]) == false)
		{
			Token* token = NULL;

			int start_idx = i;
			int end_idx = i;

			while (i < input_buffer->buffer_size && isalnum((unsigned char)buffer_line[i]) != 0)
				++i;

			end_idx = i;

			if (end_idx == start_idx) {
				// unrecognized char - consume it as a 1-char token (or skip it) so we always progress
				token = prepare_and_assign_token(buffer_line, i, 1);
			} else {
				token = prepare_and_assign_token(buffer_line, start_idx, end_idx - start_idx);
			}
			append_token(&root, token);
		}
	}
	printf("done building tokens\n");
	return (root);
}