#include "Photo.h"

void Photo::IsValidePhoto() const
{
	if (m_roadToFile.empty())
		throw std::logic_error("Error: Road to file is not found.");
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


Photo::Photo(const std::string & _roadTOFile, Date _date, Time _time, std::vector<Person> _person, std::vector<Place> _place, const std::string & _commet)
	:m_roadToFile(_roadTOFile),
	m_date(_date),
	m_time(_time),
	m_place(_place),
	m_person(_person),
	m_commet(_commet)
{
	IsValidePhoto();
}

Photo::Photo(const std::string & _roadTOFile, Date _date, Time _time, std::vector <Place> _place, const std::string & _commet)
	:m_roadToFile(_roadTOFile),
	m_date(_date),
	m_time(_time),
	m_place(_place),
	m_commet(_commet)
{
	IsValidePhoto();
}