/*
#include "controller.h"
#include <ctime>
#include <algorithm>
#include <unordered_map>

void Controller::addAlbum(Album & _album)
{
m_albums.push_back(std::make_unique<Album>(std::move(_album)));
}




//возвращает один год в секундах
int Controller::OneYearInTheSeconds()
{
	int DaysInYear{ 365 };
	int hoursInDay{ 24 };
	int minutesInHour{ 60 };
	int SecondsInMinute{ 60 };
	return (DaysInYear * hoursInDay * minutesInHour * SecondsInMinute);
}


//печатает все фото за последний год
void Controller::printAllPhotosInTheLastYear()
{
	std::cout << "Photo for the last year: " << std::endl;
	for (auto const & pAlbum : m_albums)
		for (auto const & pPhoto : pAlbum->GetPhoto())
		{
			size_t currentTime = time(nullptr);
			size_t timePhotoInSeconds = pPhoto->GetСonvertTheTimeInSeconds();
			if ((currentTime - timePhotoInSeconds) < OneYearInTheSeconds())
			{
				std::cout << "\t"<< pPhoto->GetRoadToFile();
				pPhoto->PrintDate();
				pPhoto->PrintTime();
				
			}
		}
}
//печатает альбомы где НЕТ людей
void Controller::AlbumWithoutPeople()
{
	std::cout << "Albums where are no people: " << std::endl;
	
	for (auto const & pAlbum : m_albums)
	{
		bool Empty = true;
		for (auto const & pPhoto : pAlbum->GetPhoto())
		{
			if (!pPhoto->GetPerson().empty())
			{
				Empty = false;
				break;			
			}
		}
		if (Empty)
			std::cout << "\t prohod"<< pAlbum->GetAlbumName()<< std::endl;//проход чтобы спецально видеть сколько значений должно добавится
	}
}




void Controller::printSeason(std::vector <std::string > _value)
{
	
	if (!_value.empty())
	{
		for (auto pvector : _value)
			std::cout << "\t" << pvector << std::endl;
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
//	assert(!m_summer.empty());
	
}

void Controller::printTheFiveMostPopularСities()
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
				HelpTempStruct newTempCity{ pPhoto->GetPlace().GetCity(), 1};
				m_cities.push_back(newTempCity);
			}
			else {
				//std::vector<HelpTempStruct>::iterator
				bool TempBool = false;
				auto begincopy = m_cities.begin();
				while (begincopy != m_cities.end())
				{
					if (begincopy->m_city == pPhoto->GetPlace().GetCity())
					{
						begincopy->count++;
						TempBool = true;
						break;
					}
					begincopy++;
				}
				if(!TempBool){
					HelpTempStruct newTempCity{ pPhoto->GetPlace().GetCity(), 1 };
					m_cities.push_back(newTempCity);
				}
			}
		};
	};

	std::sort(m_cities.begin(), m_cities.end(),
		[](HelpTempStruct _first, HelpTempStruct _second)
	{
		return (_first.count < _second.count);
	});

	
	std::cout << "The five most popular cities: " << std::endl;
		for (auto it = m_cities.begin(); it < m_cities.begin() + 5; it++)
			std::cout << "\t"<< it->m_city << std::endl;


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
			std::for_each(pPhoto->GetPerson().begin(), pPhoto->GetPerson().end(), [&](auto &_person)//std::unique_ptr <Person> & _person должно было быть, но в таком варианте не компилелось 
		{
			if (m_persons.empty())
			{
				HelpTempStruct newTempPerson{ _person->GetFullName(), 1 };
				m_persons.push_back(newTempPerson);
			}
			else {
				bool namePhoto = false;
					std::vector<HelpTempStruct>::iterator begincopy = m_persons.begin();
				while (begincopy == m_persons.end())
				{
			//	for (auto it = m_persons.begin(); it < m_persons.end(); it++){
					if (begincopy->m_name == _person->GetFullName())
					{
						//begincopy->m_count++;
						begincopy->m_count++;
						namePhoto = true;
						break;
				//	}
				}
					begincopy++;
					}
				if (!namePhoto)
				{
					HelpTempStruct newTempPerson{ _person->GetFullName(), 1 };
					m_persons.push_back(newTempPerson);
					
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
			std::cout << "\t" << it->m_name << std::endl;

}
void Controller::FindandPrintPhotoWithAllFrineds()
{
	struct HelpTempStruct
	{
		std::string m_name;
		std::vector <std::string > m_PhotoWithPerson;
	};

	std::vector <HelpTempStruct> m_persons;
	for (auto const & pAlbum : m_albums)
	{
		for (auto const & pPhoto : pAlbum->GetPhoto())
		{
			for (auto const & pPerson : pPhoto->GetPerson())
			{
				if (m_persons.empty())
				{
					HelpTempStruct newTempPerson;
					newTempPerson.m_name = pPerson->GetFullName();
					newTempPerson.m_PhotoWithPerson.push_back(pPhoto->GetRoadToFile());
					m_persons.push_back(newTempPerson);
				}
				else {
					bool HelpBoolPerson = false;
					auto begincopy = m_persons.begin();
					while (begincopy != m_persons.end())
					{
						if (begincopy->m_name == pPerson->GetFullName())
						{
							begincopy->m_PhotoWithPerson.push_back(pPhoto->GetRoadToFile());
							HelpBoolPerson = true;
							break;
						}
						begincopy++;
					}
					if(!HelpBoolPerson){
						HelpTempStruct newTempPerson;
						newTempPerson.m_name = pPerson->GetFullName();
						newTempPerson.m_PhotoWithPerson.push_back(pPhoto->GetRoadToFile());
						m_persons.push_back(newTempPerson);
					}
				}
			}
		}
	}

	struct PairFriends
	{
		std::string m_firstFriend;
		std::string m_secondFriend;
	};
	std::vector<PairFriends> m_vecFriends;
	for (int i = 0; i < m_persons.size() - 1; i++)
	{
		for (int j = i + 1; j < m_persons.size(); j++)
		{
			int count{ 0 };
			for (auto pFirstFriend : m_persons[i].m_PhotoWithPerson)
			{
				for (auto pSecondFriend : m_persons[j].m_PhotoWithPerson)
				{
					if (pFirstFriend == pSecondFriend)
						count++;
					if (count > 3)
					{
						PairFriends newTempPair{ m_persons[i].m_name, m_persons[j].m_name };
						m_vecFriends.push_back(newTempPair);
						count = -1;
						break;
					}
				}
			}
		}
	}
	if (!m_vecFriends.empty())
	{
		std::cout << "Friends:(Two men captured more than three times in the photos: )" << std::endl;
		for (auto PairFriends : m_vecFriends)
			std::cout << "\t"<< PairFriends.m_firstFriend << " friends with " << PairFriends.m_secondFriend << std::endl;

	}
}

*/

