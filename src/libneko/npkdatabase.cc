#include <iostream>
#include <fstream>
#include <string>
#include <neko.h>

const std::string nekobase = "var/lib/neko/";

bool npk_pkg_is_installed(const std::string pkg) {
	std::string summaryfile, rootfs, pos;

	if (getenv("ROOTDIR")) {
		rootfs = getenv("ROOTDIR");
		pos = rootfs.back();

		if (pos.c_str() != "/") {
			rootfs = rootfs + "/";
		}
	} else {
		rootfs = "/";
	}

	summaryfile = rootfs + nekobase + pkg + "/summary.json";

	std::ifstream f(summaryfile.c_str());

	return f.good();
}
