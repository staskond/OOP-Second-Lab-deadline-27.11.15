#ifndef _ALBUM_HPP_
#define _ALBUM_HPP_
#include "Photo.h"
#include <initializer_list>

class Album
{
public:
	Album(const std::string & _AlbumName);
	Album(const std::string & _AlbumName, std::initializer_list< Photo *> _photo);
	~Album();
	Album(const Album &) = delete;
	Album & operator = (const Album &) = delete;
	int getPhotoCount() const { return m_photo.size(); }//метод возвращающий количество фото в альбоме
	void addPhoto(Photo * _photo);//метод добовл€ющий фото в конец альбома
	void clearPhoto();



private:
	//название альбома
	const std::string & m_AlbumName;
	//набор фото
	std::vector <Photo *> m_photo;
};

#endif // _ALBUM_HPP_
