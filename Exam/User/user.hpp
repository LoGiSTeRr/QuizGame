#pragma once
#ifndef __USER_HPP__
#define	__USER_HPP__	

#include <string>
#include <iostream>
struct full_name
{
	std::string name;
	std::string surname;
	std::string patronymic;
};
class user
{
public:
	friend std::ostream& operator<<(std::ostream& os, user& a_user);
	user(const char* login, const char* password,
		const char* name, const char* surname, const char* patronymic,
		const char* phone_number) : login(login), password(password), m_is_admin(false),
		m_full_name({ name, surname, patronymic }), phone_number(phone_number) {}
	user() : login(" "), password(" "), m_is_admin(false),
		m_full_name({ " ", " ", " " }), phone_number(" ") {}

	const std::string& get_login() const;
	std::string& get_login();

	const std::string& get_password() const;
	std::string& get_password();

	const bool is_admin() const;
	bool is_admin();
	void set_admin(bool value);

	const full_name& get_full_name() const;
	full_name& get_full_name();

	const std::string& get_phone_number() const;
	std::string& get_phone_number();



private:
	bool m_is_admin;
	std::string login;
	std::string password;
	full_name m_full_name;
	std::string phone_number;
};

#endif