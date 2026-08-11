#include "main.h"

//token operations

Token* create_token(char* value)
{
	Token* token = (Token*)gb_malloc(sizeof(Token), 0);
	if (!token) {
		return (NULL);
	}

	token->token = strdup(lower_string(value));
	if (!token->token)
	{
		fprintf(stderr, "failed to allocate token value\n");
		return (NULL);
	}
	token->token_size = strlen(token->token);
	token->token_type = 0;
	token->next = NULL;

	return (token);
}

void	append_token(Token** root_addr, Token* token)
{
	if (!root_addr || !token)
		return ;

	if (*root_addr == NULL) {
		*root_addr = token;
		return ;
	}

	Token* root = *root_addr;

	while (root->next) {
		root = root->next;
	}
	root->next = token;
}

void	debug_token(Token* token_seq)
{
	if (!token_seq)
		return ;
	printf("--------------------------\n");
	while (token_seq) {
		printf("token_value: \"%s\" | token_size: %zu | token_type: %u\n",
			token_seq->token,
			token_seq->token_size,
			token_seq->token_type
		);
		printf("--------------------------\n");
		token_seq = token_seq->next;
	}
}