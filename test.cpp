#include "Photo.h"
#include <iostream>
//Photo::Photo(const std::string & _roadTOFile, Date _year, Date _month, Date _Day, Time _hour, Time _minutes, const std::string & _commet)

int main()
{
	Photo test1("D:\ ", 1997, 10, 2, 12, 15, "Коментарий");
	std::cout << test1.GetYear;

	Photo test2("D;\ ", Date(1997, 10, 2), Time(13, 15), "Коментарий");
}
