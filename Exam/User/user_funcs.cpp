#include "user_funcs.hpp"
#include "registration_check_funcs.hpp"
void save_user_data(user& a_user)
{
	std::fstream stream;
	stream.open("accounts_data.txt", std::ios::ate);
	size_t cpos = stream.tellg();
	stream << "&login:" << a_user.get_login() << '\n';
	stream << "&password:" << a_user.get_password() << '\n';
	stream << "&name:" << a_user.get_full_name().name << '\n';
	stream << "&surname:" << a_user.get_full_name().surname << '\n';
	stream << "&patronymic:" << a_user.get_full_name().patronymic << '\n';
	stream << "&phone_number:" << a_user.get_phone_number() << '\n';
	stream << "&is_admin:" << a_user.is_admin() << "\n\n";

	stream.close();
	stream.open("logins.txt", std::ios::app);
	stream << "&user:" << a_user.get_login() << ' ' << cpos << '\n';
	stream.close();
}
user register_user()
{
	user u{};
	std::string check_line = " ";
	std::cout << "Sign up.\n";
	std::cout << "Login(all characters allowed): "; std::getline(std::cin, check_line);
	while (search_login(check_line) != -1)
	{
		std::cout << "\nThis login is busy\n";
		std::cout << "Login(all characters allowed): "; std::getline(std::cin, check_line);
	}
	u.get_login() = check_line;

	std::cout << "\nPassword(must contain at least 6 symbols and 2 digits. max size - 32 ): "; std::getline(std::cin, check_line);
	while (!password_check(check_line))
	{
		std::cout << "\nThis Password is incorrect\n";
		std::cout << "Password(must contain at least 6 symbols and 2 digits. max size - 32 ): "; std::getline(std::cin, check_line);
	}
	u.get_password() = check_line;

	do
	{
		std::cout << "\nName(letters only): "; std::getline(std::cin, check_line);
	}
	while (!letters_only_check(check_line));
	u.get_full_name().name = check_line;

	do
	{
		std::cout << "\nSurname(letters only): "; std::getline(std::cin, check_line);
	} while (!letters_only_check(check_line));
	u.get_full_name().surname = check_line;

	do
	{
		std::cout << "\nPatronymic(letters only): "; std::getline(std::cin, check_line);
	} while (!letters_only_check(check_line));
	u.get_full_name().patronymic = check_line;
	do
	{
		std::cout << "\nPhone number(digits only): "; std::getline(std::cin, check_line);
	} while (!digits_only_check(check_line));
	u.get_phone_number() = check_line;

	save_user_data(u);
	return u;
}
int search_login(const std::string& login)
{
	std::ifstream stream;
	stream.open("logins.txt", std::ios::in);
	std::string buf;
	while (getline(stream, buf))
	{
		if (buf.substr(0, 6) == "&user:")
		{
			if (buf.substr(6, login.size()) == login.data())
			{
				stream.close();
				int cursor = std::stoi(buf.substr(7 + login.size(), buf.size() - 6 - login.size()));
				return cursor;
			}
		}
	}
	stream.close();
	return -1;
}
void load_main_user(int cursor, user& main_user)
{
	std::fstream stream;
	stream.open("accounts_data.txt", std::ios::in);
	stream.seekg(cursor);

	std::string line;
	std::getline(stream, line);
	main_user.get_login() = line.substr(7, line.size() - 7);

	std::getline(stream, line);
	main_user.get_password() = line.substr(10, line.size() - 10);

	std::getline(stream, line);
	main_user.get_full_name().name = line.substr(6, line.size() - 6);

	std::getline(stream, line);
	main_user.get_full_name().surname = line.substr(9, line.size() - 9);

	std::getline(stream, line);
	main_user.get_full_name().patronymic = line.substr(12, line.size() - 12);

	std::getline(stream, line);
	main_user.get_phone_number() = line.substr(14, line.size() - 14);

}
void print_user(const std::string& login)
{
	std::fstream stream;
	stream.open("accounts_data.txt", std::ios::in);
	int cursor = search_login(login);
	if (cursor != -1)
	{
		std::string line;
		stream.seekg(cursor);
		for (int i = 0; i < 7; ++i)
		{
			std::getline(stream, line);
			std::cout << line << '\n';
		}
	}
}
bool is_password_correct(int cursor, const std::string& password)
{
	std::fstream stream;
	stream.open("accounts_data.txt", std::ios::in);
	stream.seekg(cursor);

	std::string line;
	std::getline(stream, line);
	std::getline(stream, line);
	if (line.substr(10, line.size() - 10) == password)
	{
		return true;
	}
	return false;
}

