#ifndef DIRECTORY_H
#define DIRECTORY_H

#include "Entry.h"

#include <vector>

class Directory : public Entry {
private:
	std::vector<Entry*> entries;
	Directory* parent;

public:
	Directory(const std::string& name, Directory* parent = nullptr);
	bool isDirectory() const override;
	Directory* asDirectory() override;
	Directory* getParent() const;
	void addEntry(Entry* entry);
	Entry* find(const std::string& name) const;

	void show() const override;
	void edit() override;
	void cat() const override;

};

#endif
