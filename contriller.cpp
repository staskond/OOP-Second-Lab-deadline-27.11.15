
#include "contriller.h"
#include <ctime>

void Controller::addAlbum(Album & _album)
{
m_albums.push_back(std::make_unique<Album>(std::move(_album)));
}

void Controller::printAllPhotosInTheLastYear()
{
	std::cout << "Photo for the last year: " << std::endl;
	for (auto const & pAlbum : m_albums)
		for (auto const & pPhoto : pAlbum->GetPhoto())
		{
			size_t currentTime = time(nullptr);
			size_t timePhotoInSeconds = pPhoto->Get—onvertTheTimeInSeconds();
		}
}

int Controller::OneYearInTheSeconds()
{
	int DaysInYear{ 365 };
	int hoursInDay{ 24 };
	int minutesInHour{ 60 };
	int SecondsInMinute{ 60 };
	return (DaysInYear * hoursInDay * minutesInHour * SecondsInMinute);
}
