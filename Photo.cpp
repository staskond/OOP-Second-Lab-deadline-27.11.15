#include "Photo.h"
/*
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
}*/





void Photo::IsValidePhoto() const
{
	if (m_roadToFile.empty())
		throw std::logic_error("Error: Road to file is empty.");
	if (m_commet.empty())
		throw std::logic_error("Error: Commet is empty.");
}



Photo::Photo(const std::string & _roadTOFile, Date _date, Time _time, const std::string & _commet)
	:m_roadToFile(_roadTOFile),
	m_date(_date),
	m_time(_time),
	m_commet(_commet)
{
	IsValidePhoto();
}


Photo::Photo(const std::string & _roadTOFile, Date _date, Time _time, std::vector<Person> _person, Place _place, const std::string & _commet)
	:m_roadToFile(_roadTOFile),
	m_date(_date),
	m_time(_time),
	m_place(_place),
	m_person(_person),
	m_commet(_commet)
{
	IsValidePhoto();
}

Photo::Photo(const std::string & _roadTOFile, Date _date, Time _time, Place _place, const std::string & _commet)
	:m_roadToFile(_roadTOFile),
	m_date(_date),
	m_time(_time),
	m_place(_place),
	m_commet(_commet)
{
	IsValidePhoto();
}



