
#include "contriller.h"
#include <ctime>
//метод добавления нового альбома
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
				std::cout << pPhoto->GetRoadToFile() << std::endl;;
				pPhoto->PrintDate();
				pPhoto->PrintTime();
				
			}
		}
}
//печатает альбомы где НЕТ людей
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
	//пытался закинуть в функцию, но там была ошибка, уже было влом разбиратся 
	if (!m_winter.empty())
	{
		std::cout << "Photos made in  winter: " << std::endl;
		for (auto pwinter : m_winter)
			std::cout << pwinter << std::endl;
	}

	if (!m_autumn.empty())
	{
		std::cout << "Photos made in  winter: " << std::endl;
		for (auto pautumn : m_autumn)
			std::cout << pautumn << std::endl;
	}

	if (!m_spring.empty())
	{
		std::cout << "Photos made in spring: " << std::endl;
		for (auto pspring : m_spring)
			std::cout << pspring << std::endl;
	}

	if (!m_summer.empty())
	{
		std::cout << "Photos made in spring: " << std::endl;
		for (auto psummer : m_summer)
			std::cout << psummer << std::endl;
	}
}


/*
void Application::printPhotosByseasons()
{
	std::vector<std::string> summer, autumn, winter, spring;

	for (auto const & a : albums) {
		for (auto const & photo : a->m_photos)
		{
			if (photo->getTime().getMonth() == 12 || photo->getTime().getMonth() == 1 ||
				photo->getTime().getMonth() == 2)
				winter.push_back(photo->getPath());

			else if (photo->getTime().getMonth() > 2 && photo->getTime().getMonth() < 6)
				spring.push_back(photo->getPath());

			else if (photo->getTime().getMonth() > 5 && photo->getTime().getMonth() < 9)
				summer.push_back(photo->getPath());

			else if (photo->getTime().getMonth() > 8 && photo->getTime().getMonth() < 12)
				autumn.push_back(photo->getPath());
		}
	}
	if (!winter.empty())
	{
		std::cout << "Winter photos:\n";
		for (auto win : winter)
			std::cout << '\t' << win << '\n';
	}

	if (!spring.empty())
	{
		std::cout << "Spring photos:\n";
		for (auto spr : spring)
			std::cout << '\t' << spr << '\n';
	}

	if (!summer.empty())
	{
		std::cout << "Summer photos:\n";
		for (auto sum : summer)
			std::cout << '\t' << sum << '\n';
	}

	if (!autumn.empty())
	{
		std::cout << "Autumn photos:\n";
		for (auto aut : autumn)
			std::cout << '\t' << aut << '\n';
	}
}*/

