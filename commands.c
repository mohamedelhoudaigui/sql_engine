#include "main.h"
// code meta commands here

void	_exit_c()
{
	printf("exiting...\n");
	gb_malloc(0, 1);
	exit(EXIT_SUCCESS);
}

void	branch_to_coammand(Token* root)
{
	
	if (strncmp(root->token, EXIT_C, root->token_size) == 0)
	{
		_exit_c();
	}
	// else
	// {
	// 	printf("unknown command !\n");
	// }
}
