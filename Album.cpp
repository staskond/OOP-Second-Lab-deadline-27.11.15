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

void Album::removePhoto(Photo const & _photo)
{
	int PhotoIndex = -1;

	int nPhoto = GetAlbumSize();
	for (int i = 0; i < nPhoto; i++)
		if (m_photo[i] == &_photo)
		{
			PhotoIndex = i;
			break;
		}

	if (PhotoIndex == -1)
		throw std::logic_error("Photo does not exists in Album");

	delete m_photo.at(PhotoIndex);
	m_photo.erase(m_photo.begin() + PhotoIndex);
}

int Album::GetAlbumSize()
{
	return m_photo.size();
}
