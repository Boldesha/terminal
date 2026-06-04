#include "Terminal.h"
#include "SingleLineFile.h"
#include "MultiLineFile.h"

#include <iostream>
#include <sstream>
#include <limits>


Terminal::Terminal() : root(new Directory("root")), current(root) {}

void Terminal::parseCommand(const std::string& line) {
	std::istringstream iss(line);
	std::string cmd;

	iss >> cmd;

	if (cmd == "help") {
		std::cout
			<< "  ls                 "
			"- show the content of the current directory\n"
			<< "  cd <name|..>       "
			"- change a directory\n"
			<< "  cat <name>         "
			"- show a file content\n"
			<< "  touch <name>       "
			"- create a new file in the current directory\n"
			<< "  mkdir <name>       "
			"- create a new directory\n"
			<< "  rm <name>          "
			"- delete (hide)a file or directory\n"
			<< "  restore <name>     "
			"- restore the earlier hidden entity\n"
			<< "  mv <old> <new>     "
			"- rename a file or directory\n"
			<< "  edit <name>        "
			"- change the file content\n"
			<< "  exit               "
			"- exit\n";
	}

	else if (cmd == "exit") {
		std::exit(0);
	}

	else if (cmd == "ls") {
		current->show();
	}

	else if (cmd == "mkdir") {
		std::string name;
		iss >> name;
		if (!name.empty()) {
			current->addEntry(
				new Directory(name, current));
		}
	}

	else if (cmd == "touch") {
		std::string name;
		iss >> name;
		if (name.empty()) {
			std::cout 
				<< "Usage: touch <name>\n";
			return;
		}

		int type;
		std::cout << "Type (1: single-line, 2: multi-line): ";
		std::cin >> type;
		std::cin.ignore(
			std::numeric_limits<std::streamsize>::max(),
			'\n');

		Entry* newFile = nullptr;
		if (type == 1) newFile = new SingleLineFile(name);
		else           newFile = new MultiLineFile(name);

		newFile->edit();

		current->addEntry(newFile);
		std::cout << "File '" << name << "' created.\n";
	}

	else if (cmd == "cd") {
		std::string name;
		iss >> name;

		if (name == "..") {
			if (current->getParent()) {
				current = current->getParent();
			}
			else std::cout << "Already at root.\n";
		}

		else {
			Entry* e = current->find(name);
			if (e && e->isDirectory()) current = e->asDirectory();
			else std::cout << "Directory not found.\n";
		}
	}

	else if (
		cmd == "cat" ||
		cmd == "edit" ||
		cmd == "rm" ||
		cmd == "restore")
	{
		std::string name;
		iss >> name;
		Entry* e = current->find(name);

		if (!e) { std::cout << "Not found.\n"; return; }
		if (cmd == "cat") e->cat();
		else if (cmd == "edit") e->edit();
		else if (cmd == "rm") e->hide();
		else if (cmd == "restore") e->restore();
	}

	else if (cmd == "mv") {
		std::string oldName, newName;
		iss >> oldName >> newName;

		if (oldName.empty() || newName.empty()) {
			std::cout << "Usage: mv <old> <new>\n"; return;
		}

		Entry* e = current->find(oldName);
		if (e) {
			e->setName(newName);
			std::cout << "Renamed to '" << newName << "'.\n";
		}
		else {
			std::cout << "Entity '" 
				<< oldName 
				<< "' not found.\n";
		}
	}
}


void Terminal::run() {

	std::string line;
	std::cout << "Virtual Terminal(type 'help' for commands)\n";

	while (true) {

		std::cout << current->getName() << "> ";
		std::getline(std::cin, line);
		parseCommand(line);

	}
}
