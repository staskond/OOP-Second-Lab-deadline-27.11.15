#ifndef _PHOTO_HPP_
#define _PHOTO_HPP_
#include "person.h"
#include "place.h"
#include "Data.h"
#include "Time.h"
//Хз что и как делать, нужно читать 
class Photo
{
public:
	Photo(const std::string & _roadToFile, Date(int _year, int _month, int _day), Time(const int _hour, const int _minutes), const std::string & _commet);//узнать, можно ли так делать?
	//Photo(const std::string & _roadToFile, Date _date, Time _time, const std::sting & _commet, Person );
private:

};




#endif//_PHOTO_HPP_
