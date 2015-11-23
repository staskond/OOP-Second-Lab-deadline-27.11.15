#ifndef _PHOTO_HPP_
#define _PHOTO_HPP_
#include "person.h"
#include "place.h"
#include "Data.h"
#include "Time.h"
#include <string>
#include <iostream>
#include <vector>
#include <memory>


class Photo
{
public:
	Photo() = default;
	//конструктор, задающий путь к файлу, дату, время и комментарий
	Photo(const std::string & _roadTOFile, Date _date, Time _time, const std::string & _commet); 

	//конструктор, задающий путь к файлу, дату, время, место, личность на фотограффии и комментарий реализация №1
	Photo(const std::string & _roadTOFile, Date _date, Time _time, std::unique_ptr< Person > _person, Place _place, const std::string & _commet);

	//конструктор, задающий путь к файлу, дату, время,  личность на фотограффии и комментарий реализация №1	
	Photo(const std::string & _roadTOFile, Date _date, Time _time, std::unique_ptr< Person > _person, const std::string & _commet);
	//конструктор, задающий путь к файлу, дату, время,  личность на фотограффии и комментарий реализация №1
	Photo(const std::string & _roadTOFile, Date _date, Time _time, Place _place, const std::string & _commet);
//	int SizePersonVec();
	//Person const & getPerson(int index) const;
	//void addPerson(Person const & _obj);
	friend std::ostream & operator << (std::ostream &_o, Date _value);
	friend std::ostream & operator << (std::ostream &_o, Person _value);
	friend std::ostream & operator << (std::ostream &_o, Place _value);
	const std::string & GetRoadToFile() const;
	const std::string & GetCommet() const;
	const Date & GetDate() const;
	const Time & GetTime() const;
	void IsValidePhoto() const;
	void PrintTime();
	void PrintDate();
	int GetСonvertTheTimeInSeconds() const;

	const std::vector< std::unique_ptr< Person > >& GetPerson() const {
		return m_person;
	};
	const Place GetPlace() const { return m_place; };
private:
	friend class Album;
	friend class Contriller;
	Date m_date;
	Time m_time;
	const std::string m_roadToFile;
	const std::string m_commet;
	Place m_place;
	std::vector< std::unique_ptr< Person > > m_person;
	
	
	
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
