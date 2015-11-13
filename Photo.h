#ifndef _PHOTO_HPP_
#define _PHOTO_HPP_
#include "person.h"
#include "place.h"
#include "Data.h"
#include "Time.h"
#include <string>
//’з что и как делать, нужно читать 
class Photo
{
public:
	//Photo(  int _year, int _month, int _day, const int _hour, const int _minutes);
	Photo(const std::string & _fullName, const std::string & _Gender, const std::string & _PlaceNamed, const std::string & _city, const std::string & _country);

	const Place & GetPlaceNamed() const;
	const Place & GetCity() const;
	const Place & GetCountry() const;
	const Person & GetFullName() const;
	const Person & GetGender() const;


private:
	const std::string m_roadToFile;
	const std::string m_commet;
	const Time m_hour, m_minutes;
	const Date m_year, m_month, m_day;
	Person m_FullName;
	Person m_Gender;

	Place m_PlaceNamed;
	Place m_city;
	Place m_country;
};

inline const Place & Photo::GetPlaceNamed() const
{
	return m_PlaceNamed;
}

inline const Place & Photo::GetCity() const
{
	return m_city;
}

inline const Place & Photo::GetCountry() const
{
	return m_country;
}

const Person & Photo::GetGender() const
{
	return m_Gender;
}

const Person & Photo::GetGender() const
{
	return m_FullName;
}
//Photo testPhoto1( 2013, 03, 23, 11, 06, "This my test");









#endif//_PHOTO_HPP_
