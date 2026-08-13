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


Token* tokens_builder(InputBuffer* input_buffer)
{
	char*	buffer_line = input_buffer->buffer;
	Token*	root = NULL;

	size_t i = 0;
	while (i < input_buffer->input_size)
	{
		// skip spaces
		if (is_space_or_tab(buffer_line[i])) {
			++i;
			continue;
		}

		Token* token = NULL;
		int start_idx = i;

		if (isalnum((unsigned char)buffer_line[i])) {
			while (i < input_buffer->input_size && isalnum(buffer_line[i]))
				++i;
			token = prepare_and_assign_token(buffer_line, start_idx, i - start_idx);
		} else if (is_special_token(buffer_line[i])) {
			// special / unrecognized single-char token
			token = prepare_and_assign_token(buffer_line, start_idx, 1);
			++i;
		}
		// error in non recon character
		else
		{
			fprintf(stderr, "unknown character %c\n", buffer_line[i]);
			return (NULL);
		}

		append_token(&root, token);
	}
	printf("done building tokens\n");
	return (root);
}