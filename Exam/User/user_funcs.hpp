#pragma once

#ifndef __USER_FUNCS_HPP__
#define __USER_FUNCS_HPP__

#include "user.hpp"
#include <iostream>
#include <fstream>
#include <string>

int search_login(const std::string& login);
void load_main_user(int cursor, user& main_user);
void print_user(const std::string& login);
user register_user();
void save_user_data(user& a_user);
bool is_password_correct(int cursor, const std::string& password);

#endif
