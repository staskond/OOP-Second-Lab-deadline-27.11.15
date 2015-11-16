#include "Photo.h"

Photo::Photo(Person _fullName, Person _Gender, Place _PlaceNamed, Place _city, Place _country)
	:m_FullName(_fullName),
	m_Gender(_Gender),
	m_PlaceNamed(_PlaceNamed),
	m_city(_city),
	m_country(_country)
{
}

Photo::Photo(const std::string & _roadTOFile, Date _year, Date _month, Date _Day, Time _hour, Time _minutes, const std::string & _commet)
	:m_roadToFile(_roadTOFile),
	m_year(_year),
	m_month(_month),
	m_day(_Day),
	m_hour(_hour),
	m_minutes(_minutes),
	m_commet(_commet)
{
}

Photo::Photo(const std::string & _roadTOFile, Date(int _year, int _month, int _day))
	:m_roadToFile(_roadTOFile),
	m_month(_)
{
}

Photo::Photo(const std::string & _roadTOFile, Date _year, Date _month, Date _Day, Time _hour, Time _minutes, Person _fullName, Person _Gender, Place _PlaceNamed, Place _city, Place _country, const std::string & _commet)
{
}

