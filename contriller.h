
#ifndef _CONTROLLER_HPP_
#define _CONTROLLER_HPP_
#include "Album.h"

class Controller
{
public:

	void addAlbum(Album & _album);
	void printAllPhotosInTheLastYear();
	int OneYearInTheSeconds();

private:
	std::vector< std::unique_ptr< Album> > m_albums;

};


#endif//_CONTROLLER_HPP_
