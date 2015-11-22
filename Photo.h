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
		const std::string & _commet);
//	int SizePersonVec();
	//Person const & getPerson(int index) const;
	//void addPerson(Person const & _obj);
	const std::string & GetRoadToFile() const;
	const std::string & GetCommet() const;
	const Date & GetDate() const;
	const Time & GetTime() const;
	void IsValidePhoto() const;


private:

	Date m_date;
	Time m_time;
	const std::string m_roadToFile;
	const std::string m_commet;
	std::vector < Place > m_place;
	std::vector < Person > m_person;
	
	
};



//inline int Photo::SizePersonVec()
//{
	//return m_person.size();
//}

//inline Person const & Photo::getPerson(int index) const
//{
//	return m_person.at(index);
//}

/*int Parent::findXXXIndex(XXX const & obj) const
{
int nXXX = getXXXCount();
for (int i = 0; i < nXXX; i++)
if (m_VecXXX[i] == obj)
return i;
return -1;
}
*/


//inline void Photo::addPerson(Person const & _obj)
//{
	//m_person.push_back(_obj);
//}

inline const std::string & Photo::GetRoadToFile() const
{
	return m_roadToFile;
}

inline const std::string & Photo::GetCommet() const
{
	return m_commet;
}

inline const Date & Photo::GetDate() const
{
	return m_date;
}

inline const Time & Photo::GetTime() const
{
	return m_time;
}






//Photo testPhoto1( 2013, 03, 23, 11, 06, "This my test");









#endif//_PHOTO_HPP_
