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
	Photo(Person _fullName, Person _Gender, Place _PlaceNamed, Place _city, Place _country);//Полное имя,
	//Photo(  int _year, int _month, int _day, const int _hour, const int _minutes);
	/*класс Photo(фотография) :
		? путь к дисковому файлу?
		? дата и время снимка?
		? необязательный набор запечатленных людей и мест?
		? комментарий*/
	Photo(const std::string & _roadTOFile,
		Date _year,
		Date _month,
		Date _Day,
		Time _hour,
		Time _minutes,
		const std::string & _commet);

	Photo(const std::string & _roadTOFile,
		Date _year,
		Date _month,
		Date _Day,
		Time _hour,
		Time _minutes,
		Person _fullName,
		Person _Gender,
		Place _PlaceNamed,
		Place _city,
		Place _country,
		const std::string & _commet);
	
	const std::string & GetRoadToFile() const;
	const std::string & GetCommet() const;
	const Place & GetPlaceNamed() const;
	const Place & GetCity() const;
	const Place & GetCountry() const;

	const Person & GetFullName() const;
	const Person & GetGender() const;

	const Date GetYear() const;
	const Date GetMonth() const;
	const Date GetDay() const;

	const Time GetHour() const;
	const Time GetMinutes() const;
	

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

inline const std::string & Photo::GetRoadToFile() const
{
	return m_roadToFile;
}

inline const std::string & Photo::GetCommet() const
{
	return m_commet;
}

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

inline const Person & Photo::GetGender() const
{
	return m_Gender;
}

inline const Person & Photo::GetFullName() const
{
	return m_FullName;
}

inline const Person & Photo::GetGender() const
{
	return m_FullName;
}


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
