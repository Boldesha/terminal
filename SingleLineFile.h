#ifndef SINGLELINEFILE_H
#define SINGLELINEFILE_H

#include "Entry.h"

class SingleLineFile :public Entry {
private:
	std::string content;
public:
	SingleLineFile(const std::string& name);
	void show() const override;
	void edit() override;
	void cat() const override;
};

#endif