#ifndef ENTRY_H
#define ENTRY_H

#include <iostream>
#include <string>

class Directory;

class Entry {

protected:
	std::string name;
	bool hidden;

public:
	Entry(const std::string& name);
	virtual ~Entry();

	std::string getName() const;
	void setName(const std::string& newName);
	bool isHidden() const;

	void hide();
	void restore();

	virtual void show() const;
	virtual void edit();
	virtual void cat() const;
	virtual bool isDirectory() const;
	virtual Directory* asDirectory();
};

#endif