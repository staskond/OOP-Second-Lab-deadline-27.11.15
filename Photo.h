#ifndef _PHOTO_HPP_
#define _PHOTO_HPP_
#include "person.h"
#include "place.h"
#include "Data.h"
#include "Time.h"
#include <string>
//Хз что и как делать, нужно читать 
class Photo
{
public:
	Photo(const std::string & _roadToFile, Date(int _year, int _month, int _day), Time(const int _hour, const int _minutes), const std::string & _commet);//узнать, можно ли так делать?
	//Photo(const std::string & _roadToFile, Date _date, Time _time, const std::sting & _commet, Person );
	const Date GetYear() const;
	const Date GetMonth() const;
	const Date GetDay() const;
	const Time GetHour() const;
	const Time GetMinutes() const;

private:
	const std::string m_roadToFile;
	const std::string m_commet;
	Time m_hour, m_minutes;
	Date m_year, m_month, m_day;
};

inline const Time Photo::GetHour() const
{
	return m_hour;
}

inline const Time Photo::GetMinutes() const
{
	return m_minutes;
}


inline const Date Photo::GetYear() const
{
	return m_year;
}

inline const Date Photo::GetMonth() const
{
	return m_month;
}

inline const Date Photo::GetDay() const
{
	return m_day;
}

//Photo testPhoto1( 2013, 03, 23, 11, 06, "This my test");









#endif//_PHOTO_HPP_
