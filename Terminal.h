#ifndef TERMINAL_H
#define TERMINAL_H

#include "Directory.h"
#include <string>

class Terminal {
private:
	Directory* root;
	Directory* current;
	void parseCommand(const std::string& line);

public:
	Terminal();
	void run();

};

#endif
