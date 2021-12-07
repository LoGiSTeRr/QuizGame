#pragma once
#ifndef __REGISTRATION_CHECK_FUNCS_HPP__
#define __REGISTRATION_CHECK_FUNCS_HPP__
#include <string>
bool password_check(const std::string& str);
bool letters_only_check(const std::string& str);
bool digits_only_check(const std::string& str);


#endif