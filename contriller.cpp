
#include "contriller.h"
#include <ctime>
#include <algorithm>
#include <unordered_map>
//����� ���������� ������ �������
void Controller::addAlbum(Album & _album)
{
m_albums.push_back(std::make_unique<Album>(std::move(_album)));
}
//���������� ���� ��� � ��������
int Controller::OneYearInTheSeconds()
{
	int DaysInYear{ 365 };
	int hoursInDay{ 24 };
	int minutesInHour{ 60 };
	int SecondsInMinute{ 60 };
	return (DaysInYear * hoursInDay * minutesInHour * SecondsInMinute);
}


//�������� ��� ���� �� ��������� ���
void Controller::printAllPhotosInTheLastYear()
{
	std::cout << "Photo for the last year: " << std::endl;
	for (auto const & pAlbum : m_albums)
		for (auto const & pPhoto : pAlbum->GetPhoto())
		{
			size_t currentTime = time(nullptr);
			size_t timePhotoInSeconds = pPhoto->Get�onvertTheTimeInSeconds();
			if ((currentTime - timePhotoInSeconds) < OneYearInTheSeconds())
			{
				std::cout << pPhoto->GetRoadToFile() << std::endl;;
				pPhoto->PrintDate();
				pPhoto->PrintTime();
				
			}
		}
}
//�������� ������� ��� ��� �����
void Controller::AlbumWithoutPeople()
{
	std::cout << "Albums where are no people: " << std::endl;
	bool isEmpty{ true };
	for (auto const & pAlbum : m_albums)
	{
		for (auto const & pPhoto : pAlbum->GetPhoto())
		{
			if (pPhoto->GetPerson().empty())
			{
				isEmpty = false;
				break;
			}
		}
		if (isEmpty)
			std::cout << pAlbum->GetAlbumName() << std::endl;
	}
}

void Controller::AlbumWithPeople()
{
	std::cout << "Albums with people: " << std::endl;
	bool isEmpty{ true };
	for (auto const & pAlbum : m_albums)
	{
		for (auto const & pPhoto : pAlbum->GetPhoto())
		{
			if (pPhoto->GetPerson().empty())
			{
				isEmpty = false;
				break;
			}
		}
		if (!isEmpty)
			std::cout << pAlbum->GetAlbumName() << std::endl;
	}
}

void Controller::printSeason(std::vector <std::string > _value)
{
	if (!_value.empty())
	{
		for (auto pvector : _value)
			std::cout << pvector << std::endl;
	}
}
void Controller::printPhotoSeasonal()
{
	
	std::vector < std::string > m_winter;
	std::vector < std::string > m_spring;
	std::vector < std::string > m_summer;
	std::vector < std::string > m_autumn;
	for(auto const & pAlbum : m_albums)
		for (auto const & pPhoto : pAlbum->GetPhoto())
		{
			if (pPhoto->GetDate().GetMonth() > 11 &&
				pPhoto->GetDate().GetMonth() < 3)
				m_winter.push_back(pPhoto->GetRoadToFile());

			else if (pPhoto->GetDate().GetMonth() > 2 &&
				pPhoto->GetDate().GetMonth() < 6)
				m_spring.push_back(pPhoto->GetRoadToFile());

			else if (pPhoto->GetDate().GetMonth() > 5 &&
				pPhoto->GetDate().GetMonth() < 9)
				m_summer.push_back(pPhoto->GetRoadToFile());

			else if (pPhoto->GetDate().GetMonth() > 8 &&
				pPhoto->GetDate().GetMonth() < 12)
				m_autumn.push_back(pPhoto->GetRoadToFile());
			else break;
		}
	std::cout << "Photos made in  winter: " << std::endl;
	printSeason(m_winter);
	std::cout << "Photos made in autumn: " << std::endl;
	printSeason(m_autumn);
	std::cout << "Photos made in spring: " << std::endl;
	printSeason(m_spring);
	std::cout << "Photos made in summer: " << std::endl;
	printSeason(m_summer);
	
}

void Controller::printTheFiveMostPopular�ities()
{
	struct HelpTempStruct
	{
		std::string m_city;
		int count;

	};

	std::vector <HelpTempStruct> m_cities;
	for (auto const & pAlbum : m_albums)
	{
		for (auto const & pPhoto : pAlbum->GetPhoto())
		{
			if (m_cities.empty())
			{
				HelpTempStruct newCity{ pPhoto->GetPlace().GetCity(), 1};
				m_cities.push_back(newCity);
			}
			//std::vector<HelpTempStruct>::iterator
			auto begincopy = m_cities.begin();
			if (m_cities.begin()->m_city == pPhoto->GetPlace().GetCity())
			{
				m_cities.begin()->count++;
				break;
			}
			begincopy++;
		};
	};

	std::sort(m_cities.begin(), m_cities.end(),
		[](HelpTempStruct _first, HelpTempStruct _second)
	{
		return (_first.count < _second.count);
	});

		std::cout << "The five most popular cities: " << std::endl;
		for (auto it = m_cities.begin(); it < m_cities.begin() + 5; it++)
			std::cout << it->m_city << std::endl;
}

void Controller::printTheFiveMostPopularPeoples()
{
	struct HelpTempStruct
	{
		std::string m_name;
		int m_count;
	};

	std::vector<HelpTempStruct> m_persons;
	for (auto const & pAlbum : m_albums)
	{
		for (auto const & pPhoto : pAlbum->GetPhoto())
			std::for_each(pPhoto->GetPerson().begin(), pPhoto->GetPerson().end(), [&](auto &_person)//std::unique_ptr <Person> & _person ������ ���� ����, �� � ����� �������� �� ����������� 
		{
			if (m_persons.empty())
			{
				HelpTempStruct newPerson{ _person->GetFullName(), 1 };
				m_persons.push_back(newPerson);
			}
			else {
				std::vector<HelpTempStruct>::iterator begincopy = m_persons.begin();
				while (m_persons.begin() == m_persons.end())
				{
					if (m_persons.begin()->m_name == _person->GetFullName())
					{
						m_persons.begin()->m_count++;
						break;
					}
				}
			}
		});
	}
		std::sort(m_persons.begin(), m_persons.end(), [](HelpTempStruct _first, HelpTempStruct _second)
		{
			return _first.m_count < _second.m_count;
		}
		);

		std::cout << "The five most popular peoples: " << std::endl;
		for (auto it = m_persons.begin(); it != m_persons.begin() + 5; it++)
			std::cout << it->m_name << std::endl;;
}

void Controller::printAllFriends()
{
	struct HelpTempStruct
	{
		std::string m_name;
		std::vector <std::string > m_PhotoWithPerson;
	};

	std::vector <HelpTempStruct> m_persons;
}


