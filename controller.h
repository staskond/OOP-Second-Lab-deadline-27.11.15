
#ifndef _CONTROLLER_HPP_
#define _CONTROLLER_HPP_
#include "Album.h"

class Controller
{
public:

	enum Season{
		Winter,
		Spring,
		Summer,
		Autumn,
		Incorrect
};

	Season distributionSeason();
	//void addPerson(Person & _person, std::string & _roadToFile);
	//
	//void PushVecAndPrint();
	void printSeason(std::vector <std::string > _value);
	void addAlbum(Album & _album);
	void addPhoto(Photo & _album);
	void printAllPhotosInTheLastYear();
	int OneYearInTheSeconds();
	void AlbumWithoutPeople();
	//void AlbumWithPeople();
	void printPhotoSeasonal();
	void printTheFiveMostPopular—ities();
	void printTheFiveMostPopularPeoples();;
	void FindandPrintPhotoWithAllFrineds();
private:
	std::vector< std::unique_ptr< Photo> > m_photos;
	std::vector< std::unique_ptr< Place> > m_places;
	std::vector< std::unique_ptr< Album> > m_albums;

};


#endif//_CONTROLLER_HPP_
