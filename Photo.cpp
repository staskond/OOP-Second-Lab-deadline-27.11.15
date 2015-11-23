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



std::ostream & operator << (std::ostream & _o, Date _d)
{
	_o << _d.GetYear() << '/' << _d.GetMonth() << '/' << _d.GetDay();
	return _o;
}

std::ostream & operator << (std::ostream & _o, Person _p)
{
	_o << _p.GetFullName() << "\t" << _p.GetGender() << std::endl;
	return _o;
}

std::ostream & operator << (std::ostream & _o, Place _p)
{
	_o << _p.GetPlaceNamed() << "\t" << _p.GetCountry() << "\t" << _p.GetCity() << std::endl;
	return _o;
}
void Photo::IsValidePhoto() const
{
	if (m_roadToFile.empty())
		throw std::logic_error("Error: Road to file is empty.");
	if (m_commet.empty())
		throw std::logic_error("Error: Commet is empty.");
}

void Photo::PrintTime()
{
	std::cout << "\t" <<m_time.GetHour() << ":" << m_time.GetMinutes() << std::endl;
}

void Photo::PrintDate()
{
	std::cout << m_date.GetYear() << "/" << m_date.GetMonth() << "/" << m_date.GetDay();
}



Photo::Photo(const std::string & _roadTOFile, Date _date, Time _time, const std::string & _commet)
	:m_roadToFile(_roadTOFile),
	m_date(_date),
	m_time(_time),
	m_commet(_commet)
{
	IsValidePhoto();
}


Photo::Photo(const std::string & _roadTOFile, Date _date, Time _time, std::unique_ptr< Person > _person , Place _place, const std::string & _commet)
	:m_roadToFile(_roadTOFile),
	m_date(_date),
	m_time(_time),
	m_place(_place),
	m_commet(_commet)
{
	m_person.push_back(std::move(_person));
	IsValidePhoto();
}

Photo::Photo(const std::string & _roadTOFile, Date _date, Time _time, std::unique_ptr<Person> _person, const std::string & _commet)
	:m_roadToFile(_roadTOFile),
	m_date(_date),
	m_time(_time),
	m_commet(_commet)
{
	m_person.push_back(std::move(_person));
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



int Photo::Get—onvertTheTimeInSeconds() const
{
	int hoursInDay{ 24 };
	int minutesInHour{ 60 };
	int SecondsInMinute{ 60 };
	return ((m_date.GetYear() - 1970) * 365 + m_date.GetDay()) * hoursInDay * minutesInHour * SecondsInMinute + (m_time.GetHour() * minutesInHour * SecondsInMinute) + (m_time.GetMinutes() * SecondsInMinute);
}