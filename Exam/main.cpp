#include <iostream>
#include <fstream>
#include "UI/menu.hpp"
#include "User/user_funcs.hpp"



int main()
{
	user main_user;
	std::fstream stream;
	std::string temp;
	//main_user = register_user();
	stream.open("logins.txt", std::ios::in);
	stream.peek();
	if (stream.eof())
	{
		stream.close();
		print_admin_signup(main_user);
	}
	else
	{
		stream.close();
		start_menu(main_user);
	}
}
