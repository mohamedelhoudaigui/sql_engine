#include "main.h"

void    print_banner(void)
{
    printf("Sql clone version 0.1\n");
}

void	print_prompt()
{
	printf(">> ");
}

int main()
{
    print_banner();
    while (true) {
		print_prompt();
		InputBuffer* input_buffer = create_input_buffer();
        read_from_input(input_buffer);
		Token* root = tokens_builder(input_buffer);
		debug_token(root);
		// branch_to_coammand(root);
		root = NULL;
		input_buffer = NULL;
    }
    return 0;
}