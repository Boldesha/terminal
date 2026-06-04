#ifndef MULTILINEFILE_H
#define MULTILINEFILE_H

#include "Entry.h"
#include <vector>

class MultiLineFile : public Entry {
private:
	std::vector<std::string> lines;

public:
	MultiLineFile(const std::string& name);

	void show() const override;
	void edit() override;
	void cat() const override;
};

#endif
