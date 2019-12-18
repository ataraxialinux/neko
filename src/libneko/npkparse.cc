#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <neko.h>

bool npk_parse(char* filename, const std::string& pattern) {
	FILE *fp = fopen(filename, "r");
	char buffer[512];
	std::string input;
	std::string rmchar = " :";

	if (!filename) {
		printf("File was not specified.\n");
		return false;
	}

	if (!fp) {
		printf("Failed to open file: %s\n", filename);
		return false;
	}

	while (fgets(buffer, 512, fp)) {
		input = buffer;
		input = npk_stripspaces(input);

		if (input.rfind(pattern, 0) == 0) {
			input = npk_replaceall(input, "  ", " ");
			input = npk_replaceall(input, "  ", ",");
			input = npk_replaceall(input, ",,", ",");
			input = strchr(input.c_str(), ':');

			size_t pos = input.find(":");

			if (pos != std::string::npos) {
				input.erase(pos, rmchar.length());
			}

			std::cout << input << std::endl;
		}
	}

	fclose(fp);

	return true;
}
