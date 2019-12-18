#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>

std::string npk_stripspaces(const std::string& s);
std::string npk_replaceall(std::string& in,
	const std::string& oldString,
	const std::string& newString);
bool npk_parse(char* filename, const std::string& pattern);
bool npk_pkg_is_installed(const std::string pkg);
