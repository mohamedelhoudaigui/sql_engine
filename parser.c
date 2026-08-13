#include "main.h"

// parser operations

void	_check_for_comma_sep(Token* root)
{
	bool comma = false;

	while (root) {
		if ((comma == false && root->token_type == TOKEN_COMMA) ||
			(comma == true && root->token_type != TOKEN_COMMA)) {
				graceful_crash("syntax error in select statement");
		}
		comma = !comma;
		root = root->next;
	}
}

void	_parse_select(Token* root)
{
	_check_for_comma_sep(root);
}

void	_parse_insert(Token* root)
{
	// checking into token
	if (root->token_type != TOKEN_INTO)
		graceful_crash("syntax error in insert statement, \'into\' is missing");

	root = root->next;

	if (!root || root->token_type != TOKEN_VALUES)
		graceful_crash("syntax error in insert statement, \'values\' is missing");

	root = root->next;

	if (!root || root->token_type != TOKEN_BRACKET_OPEN)
		graceful_crash("syntax error in insert statement, \')\' is missing");

	root = root->next;

	if (!root || root->token_type != TOKEN_BRACKET_OPEN)
		graceful_crash("syntax error in insert statement, \')\' is missing");

	root = root->next
}

void	_parse_update(Token* root)
{

}

void	_parse_delete(Token* root)
{

}

// check for syntax error
void	syntax_analyses(Token* root)
{
	Token* keyword = root;

	// enums are numbered
	if (keyword->token_type > TOKEN_DELETE)
		return graceful_crash("first token is not a keyword");

	// select syntax check
	switch (keyword->token_type)
	{
		case TOKEN_SELECT:
			_parse_select(root);
		case TOKEN_INSERT:
			_parse_insert(root);
		case TOKEN_UPDATE:
			_parse_update(root);
		case TOKEN_DELETE:
			_parse_delete(root);
		default:
			;
	}

}

void	parse(Token* root)
{
	syntax_analyses(root);
}