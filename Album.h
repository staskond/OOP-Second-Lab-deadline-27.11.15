#ifndef _ALBUM_HPP_
#define _ALBUM_HPP_
#include "Photo.h"
#include <initializer_list>
#include <memory>
class Album
{
public:
	Album(const std::string & _AlbumName);
	Album(const std::string & _AlbumName, std::initializer_list< Photo *> _photo);
	~Album();
	Album(const Album &) = delete;
	Album & operator = (const Album &) = delete;
	int getPhotoCount() const;//метод возвращающий количество фото в альбоме
	void Album::addPhoto(std::unique_ptr< Photo > _photo);//метод добовл€ющий фото в конец альбома
	void clearPhoto();
	void removePhoto(Photo const & _photo);
	int GetAlbumSize();
	typedef std::vector< std::unique_ptr< Photo > >::const_iterator PhotoIterator;
	/*https://github.com/zaychenko-sergei/oop-ki14/blob/master/lab2/demo_solution_14/employee.hpp */
	PhotoIterator AlbumBegin () const ;

	PhotoIterator AlbumEnd () const;
	bool hasPhoto(Photo const & _Photo) const;
	class IterablePhoto
	{
	public:

		IterablePhoto(PhotoIterator _photoBegin, PhotoIterator _photosEnd)
			: m_begin(_photoBegin), m_end(_photosEnd)
		{}

		PhotoIterator begin() const { return m_begin; }
		PhotoIterator end() const { return m_end; }

	private:

		PhotoIterator m_begin, m_end;
	};
	

private:
	//название альбома
	const std::string & m_AlbumName;
	//набор фото
	std::vector< std::unique_ptr< Photo > > m_photo;//храним по умным указзател€м 
	//std::vector <Photo *> m_photo;
};

inline Album::PhotoIterator
Album::AlbumBegin() const
{
	return m_photo.begin();
}

inline Album::PhotoIterator
Album::AlbumEnd() const
{
	return m_photo.end();
}

inline int Album::getPhotoCount() const
{
	return m_photo.size();
}
#endif // _ALBUM_HPP_
