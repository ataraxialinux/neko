#include <iostream>
#include "neko.h"

int main(int argc, char* argv[]) {
	if (!npk_pkg_is_installed(argv[1])) {
		return true;
	}
}
