#ifndef _PHOTO_HPP_
#define _PHOTO_HPP_
#include "person.h"
#include "place.h"
#include "Data.h"
#include "Time.h"
//’з что и как делать, нужно читать 
class Photo
{
public:
	Photo(const std::string & _roadToFile, Date _date, Time _time, const std::sting & _commet);
	Photo(const std::string & _roadToFile, Date _date, Time _time, const std::sting & _commet, Person );

private:

};




#endif//_PHOTO_HPP_
