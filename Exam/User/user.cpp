#include "user.hpp"

std::ostream& operator<<(std::ostream& os, user& a_user)
{
	os << "Login: " << a_user.get_login() << '\n';
	os << "Password: ********\n";
	os << "Name: " << a_user.get_full_name().name << '\n';
	os << "Surname: " << a_user.get_full_name().surname << '\n';
	os << "Patronymic: " << a_user.get_full_name().patronymic << '\n';
	os << "Phone number: " << a_user.get_phone_number() << '\n';

	return os;
}

const std::string& user::get_login() const
{
	return login;
}
std::string& user::get_login()
{
	return login;
}

const std::string& user::get_password() const
{
	return password;
}
std::string& user::get_password()
{
	return password;
}

const bool user::is_admin() const
{
	return m_is_admin;
}
bool user::is_admin()
{
	return m_is_admin;
}
void user::set_admin(bool value)
{
	m_is_admin = value;
}
const full_name& user::get_full_name() const
{
	return m_full_name;
}
full_name& user::get_full_name()
{
	return m_full_name;
}

const std::string& user::get_phone_number() const
{
	return phone_number;
}
std::string& user::get_phone_number()
{
	return phone_number;
}
