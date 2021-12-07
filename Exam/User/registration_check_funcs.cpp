#include "registration_check_funcs.hpp"

bool password_check(const std::string& str)
{
	if (str.size() < 8 || str.size() > 32)
	{
		return false;
	}
	int digit_counter = 0;
	for (const char i : str)
	{
		if (i >= 48 && i <= 57)
		{
			if (++digit_counter == 2)
			{
				return true;
			}
		}
	}
	return false;
}
bool letters_only_check(const std::string& str)
{
	for (const char i : str)
	{
		if (i >= 65 && i <= 90 || i >= 97 && i <= 122)
		{
			continue;
		}
		return false;
	}
	return true;
}
bool digits_only_check(const std::string& str)
{
	for (const char i : str)
	{
		if (i >= 48 && i <= 57)
		{
			continue;
		}
		return false;
	}
	return true;
}
