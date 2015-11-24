
#ifndef _CONTROLLER_HPP_
#define _CONTROLLER_HPP_
#include "Album.h"

class Controller
{
public:

	void addPerson(Person & _person, std::string & _roadToFile);
	void printSeason(std::vector <std::string > _value);
	void addAlbum(Album & _album);
	void printAllPhotosInTheLastYear();
	int OneYearInTheSeconds();
	void AlbumWithoutPeople();
	void AlbumWithPeople();
	void printPhotoSeasonal();
	void printTheFiveMostPopular—ities();
	void printTheFiveMostPopularPeoples();;
	void FindandPrintPhotoWithAllFrineds();
private:
	std::vector< std::unique_ptr< Album> > m_albums;

};


#endif//_CONTROLLER_HPP_
