#ifndef _PHOTO_HPP_
#define _PHOTO_HPP_
#include "person.h"
#include "place.h"
#include "Data.h"
#include "Time.h"
#include <string>
#include <iostream>
#include <vector>
//Хз что и как делать, нужно читать 
class Photo
{
public:



	Photo(const std::string & _roadTOFile,//конструктор, задающий путь к файлу, дату, время и комментарий 
		Date _date, 
		Time _time,
		const std::string & _commet);


	Photo(const std::string & _roadTOFile,//конструктор, задающий путь к файлу, дату, время, место, личность на фотограффии и комментарий реализация №1
		Date _date,
		Time _time,
		std::vector <Person> _person,
		std::vector <Place> _place,
		const std::string & _commet);

	Photo(const std::string & _roadTOFile,//конструктор, задающий путь к файлу, дату, время,  личность на фотограффии и комментарий реализация №1
		Date _date,
		Time _time,
		std::vector <Person> _person,
		const std::string & _commet);
	
	Photo(const std::string & _roadTOFile,//конструктор, задающий путь к файлу, дату, время,  личность на фотограффии и комментарий реализация №1
		Date _date,
		Time _time,
		std::vector <Place> _place,
		const std::string & _commet)
	{
	}


	const std::string & GetRoadToFile() const;
	const std::string & GetCommet() const;


	const Person & GetFullName() const;
	const Person & GetGender() const;



private:

	Date m_date;
	Time m_time;
	const std::string m_roadToFile;
	const std::string m_commet;
	const Time m_hour, m_minutes;
	const Date m_year, m_month, m_day;
	std::vector < Place > m_place;
	std::vector < Person > m_person;
	
	
};

inline const std::string & Photo::GetRoadToFile() const
{
	return m_roadToFile;
}

inline const std::string & Photo::GetCommet() const
{
	return m_commet;
}




//Photo testPhoto1( 2013, 03, 23, 11, 06, "This my test");









#endif//_PHOTO_HPP_
