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
	for (size_t i = 0; i < str_size; ++i)
	{
		if (isdigit(str[i]) == 0) {
			return (false);
		}
	}
	return (true);
}

bool	is_space_or_tab(char c)
{
	return (c == 0x09 || c == 0x20 || c == 0x0A || c == 0x0D);
}

bool	is_special_token(char c)
{
	return (c == ',' || c == '(' || c == ')' || c == '=');
}
