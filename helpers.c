#include "main.h"

char*	lower_string(char* str)
{
	int size = strlen(str);
	for (int i = 0; i < size; ++i)
		str[i] = tolower(str[i]);
	return (str);
}

bool	is_str_num(char *str, size_t str_size)
{
	for (int i = 0; i < str_size; ++i)
	{
		if (isdigit(str[i]) == 0) {
			return (false);
		}
	}
	return (true);
}