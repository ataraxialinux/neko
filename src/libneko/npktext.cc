#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <neko.h>

std::string npk_stripspaces(const std::string& s) {
	if (s.empty()) {
		return s;
	}

	int pos = 0;
	std::string line = s;
	std::string::size_type len = line.length();
	while (pos < len && isspace(line[pos])) {
		pos++;
	}
	line.erase(0, pos);
	pos = line.length()-1;
	while (pos > -1 && isspace(line[pos])) {
		pos--;
	}
	if (pos != -1) {
		line.erase(pos+1);
	}
	return line;
}

std::string npk_replaceall(std::string& in,
	const std::string& oldString,
	const std::string& newString) {
	size_t pos;
	while ((pos = in.find(oldString)) != std::string::npos) {
		in.replace(pos, oldString.length(), newString);
	}

	return in;
}
