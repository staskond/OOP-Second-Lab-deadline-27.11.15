#include "Album.h"

Album::Album(const std::string & _AlbumName, Photo _photo)
	:m_AlbumName(_AlbumName),
	m_photo(_photo)
{
}

Album::~Album()
{
	delete std::vector<Photo>m_photo;
}
