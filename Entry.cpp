#include "Entry.h"
#include <iostream>

Entry::Entry(const std::string& name) : name(name), hidden(false) {}
Entry::~Entry() = default;


std::string Entry::getName() const { return name; }
void Entry::setName(const std::string& newName) { name = newName; }
bool Entry::isHidden() const { return hidden; }

void Entry::hide() { hidden = true; }
void Entry::restore() { hidden = false; }

void Entry::show() const { std::cout << "[FILE]" << name << "\n"; }
void Entry::edit() { std::cout << "Edit is not supported for this entry type.\n"; }
void Entry::cat() const {std::cout << "Cannot display this entry type.\n"; }

bool Entry::isDirectory() const { return false; }
Directory* Entry::asDirectory() { return nullptr; }