#include "Directory.h"
#include <iostream>

Directory::Directory(const std::string& name, Directory* parent) : Entry(name), parent(parent) {}
bool Directory::isDirectory() const { return true; }

Directory* Directory::asDirectory() { return this; }
Directory* Directory::getParent() const { return parent; }

void Directory::addEntry(Entry* entry) { entries.push_back(entry); }

Entry* Directory::find(const std::string& name) const {

	for (const auto& e : entries) {

		if (e->getName() == name) {
			return e;
		}
	}
	return nullptr;
}

void Directory::show() const {
    for (const auto& e : entries) {
        if (!e->isHidden()) {
            std::cout << (e->isDirectory() ? "[DIR] " : "[FILE] ")
                << e->getName() << "\n";
        }
    }
}



void Directory::edit() { std::cout << "Cannot edit a directory.\n"; }
void Directory::cat() const { std::cout << "Is a directory.\n"; }