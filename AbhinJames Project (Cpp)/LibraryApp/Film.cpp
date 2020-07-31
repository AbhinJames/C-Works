#include "Film.h"
using std::string;
using utility::Strings;

Film::Film(string title, string director, int durationMinutes)
	: Item("Film")
{
	this->director = director;
	this->durationInMinutes = 120;

}

string Film::getDirector()
{
	return director;
}

int Film::getDurationMinutes()
{
	return durationInMinutes;
}

double Film::getLateFeePerSecond()
{
	return 0.04;
}


string Film::toString()
{
	return Item::toString() + "Directed by: " +" " + this->director +" "+ "Duration of: " + std::to_string(getDurationMinutes()) + "minutes";
}
