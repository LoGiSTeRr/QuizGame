#include "menu.hpp"
void start_menu(user& main_user)
{
	system("cls");
	std::cout << "Welcome to Quiz game!\n";
	std::cout << "So, first of all, choose what you want.\n";
	std::cout << "1 - Log in		2 - Sign up\n";
	std::string choice = "0";
	while (choice[0] != '1' && choice[0] != '2')
	{
		std::cout << "Choose: "; std::cin >> choice;
	} 
	switch (choice[0])
	{
	case '1':
		print_log_in_menu(main_user);
		break;
	case '2':
		register_user();
		break;
	default:
		break;
	}

}
void print_admin_signup(user& main_user)
{
	system("cls");
	std::cout << "Welcome new admin!\n";
	std::cout << "Register new admin account, for full access to this application.\n";
	main_user.set_admin(true);
}
void print_log_in_menu(user& main_user)
{
	system("cls");
	std::string login;
	std::string password;
	std::cout << "Welcome to \"log in\" menu.\n";
	std::cout << "Write \'0\' at login field, if you want to exit this menu.\n";
	std::cout << "login: "; std::cin >> login;
	if (login.size() == 1 && login[0] == '0')
	{
		start_menu(main_user);
		return;
	}
	std::cout << "password: "; std::cin >> password;
	int cursor = search_login(login);
	while (cursor == -1 || !is_password_correct(cursor, password))
	{
		std::cout << "incorrect login or password.\n\n";
		std::cout << "login: "; std::cin >> login;
		if (login.size() == 1 && login[0] == '0')
		{
			start_menu(main_user);
			return;
		}
		std::cout << "password: "; std::cin >> password;

		cursor = search_login(login);
	}
	load_main_user(cursor, main_user);
	system("cls");
	std::cout << main_user;
}
