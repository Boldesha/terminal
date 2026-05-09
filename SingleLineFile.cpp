#include "SingleLineFile.h"
#include <iostream>

SingleLineFile::SingleLineFile(const std::string& name) : Entry(name), content("") {}

void SingleLineFile::show() const { std::cout << "[FILE] " << name << "\n"; }
void SingleLineFile::edit() { std::cout << "Enter new line: "; std::getline(std::cin, content); }
void SingleLineFile::cat() const { std::cout << content << "\n"; }

