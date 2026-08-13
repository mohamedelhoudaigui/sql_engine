#include "main.h"

int main()
{
	printf("Sql clone version 0.1\n");

    while (true) {
		printf(">> ");
		InputBuffer* input_buffer = create_input_buffer();
        read_from_input(input_buffer);
		Token* root = tokens_builder(input_buffer);
		debug_token(root);
		parse(root);
    }

    return (0);
}
