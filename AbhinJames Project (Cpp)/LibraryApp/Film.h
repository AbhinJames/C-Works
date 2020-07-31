#pragma once
#include <string>
#include "Item.h"
#include "Strings.h"

class Film : public Item
{

	std::string director;
	int durationInMinutes;

public:
	Film(std::string title, std::string director, int durationMinutes);

	std::string getDirector();
	int getDurationMinutes();

	virtual double getLateFeePerSecond() override;

	virtual std::string toString() override;
};

