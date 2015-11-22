#include "Album.h"




Album::Album(const std::string & _AlbumName)
	:m_AlbumName(_AlbumName)
{
}

Album::Album(const std::string & _AlbumName, std::initializer_list<Photo*> _photo)
	:m_AlbumName(_AlbumName),
	m_photo(_photo)
{
}

Album::~Album()
{
	clearPhoto();
}

void Album::addPhoto(Photo * _photo)
{
	m_photo.push_back(_photo);
}

void Album::clearPhoto()
{
	for (Photo * p_photo : m_photo)
		delete p_photo;
	m_photo.clear();
}

