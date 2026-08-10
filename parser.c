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
	else
		token->token_type = TOKEN_IDENTIFIER;
}

// Token*	tokens_builder(InputBuffer* input_buffer)
// {
// 	char*	word = strtok(input_buffer->buffer, DELIM);
// 	Token*	token = NULL;
// 	Token*	root = NULL;

// 	while (word) {
// 		token = create_token(word);
// 		if (!token || !token->token) {
// 			fprintf(stderr, "failed to create token sequence !\n");
// 			exit(EXIT_FAILURE);
// 		}
// 		assign_token_type(token);
// 		append_token(&root, token);
// 		word = strtok(NULL, DELIM);
// 	}
// 	printf("done building tokens\n");
// 	return (root);
// }

Token*	tokens_builder(InputBuffer* input_buffer)
{
	char*	buffer_line = input_buffer->buffer;
	Token*	token = NULL;
	Token*	root = NULL;

	int start_idx = -1;
	int end_indx = -1;

	size_t i = 0;
	while (i < input_buffer->buffer_size)
	{
		if (isalnum(buffer_line[i]) == 0) {
			++i;
		}

		if (isalnum(buffer_line[i]) != 0)
		{
			start_idx = i;
			while (isalnum(buffer_line[i]) != 0 && i < input_buffer->buffer_size)
				++i;
			end_indx = i;
			int len = end_indx - start_idx;
			token = create_token(strndup(buffer_line + start_idx, len));
			assign_token_type(token);
			append_token(&root, token);
		}
		else
			++i;
	}
	printf("done building tokens\n");
	return (root);
}