#include "MultiLineFile.h"

#include <iostream>

MultiLineFile::MultiLineFile(const std::string& name) : Entry(name) {}

void MultiLineFile::show() const { std::cout << "[FILE] " << name << "\n"; }

void MultiLineFile::edit() {

    if (lines.empty()) {
        std::string newLine;
        std::cout << "File is empty. Enter the first line: ";
        std::getline(std::cin, newLine);
        lines.push_back(newLine);
        std::cout << "First line added.\n";
        return;
    }

 
    for (size_t i = 0; i < lines.size(); ++i) {
        std::cout << i << ": " << lines[i] << "\n";
    }

    std::cout << lines.size() << ": [Add new line]\n";

    int choice;
    std::cout << "Choose line number to edit, or " << lines.size() << " to add: ";
    std::cin >> choice;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (choice >= 0 && choice < static_cast<int>(lines.size())) {

        std::cout << "New text for line " << choice << ": ";
        std::getline(std::cin, lines[choice]);
    }
    else if (choice == static_cast<int>(lines.size())) {

        std::string newLine;
        std::cout << "Enter new line: ";
        std::getline(std::cin, newLine);
        lines.push_back(newLine);
    }
    else {
        std::cout << "Invalid choice.\n";
    }
}

void MultiLineFile::cat() const {
	for (const auto& line : lines) {
		std::cout << line << "\n";
	}
}