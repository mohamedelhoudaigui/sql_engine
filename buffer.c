#include "main.h"

// buffer operations

InputBuffer*    create_input_buffer()
{
	InputBuffer* input_buffer = (InputBuffer*)gb_malloc(sizeof(InputBuffer), 0);
	if (!input_buffer) {
		fprintf(stderr, "failed to allocate input_buffer struct.\n");
		return (NULL);
	}

	input_buffer->buffer = NULL;
	input_buffer->buffer_size = 0;
	input_buffer->input_size = 0;

	return (input_buffer);
}

void    read_from_input(InputBuffer* input_buffer)
{
	ssize_t bytes_read = getline(&(input_buffer->buffer),
								&(input_buffer->buffer_size),
								stdin);
	if (bytes_read <= 0) {
		fprintf(stderr, "error reading input.\n");
		exit(EXIT_FAILURE);
	}

	input_buffer->input_size = bytes_read - 1;
	input_buffer->buffer[bytes_read - 1] = 0;
}
