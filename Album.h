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
	void Album::addPhoto(std::unique_ptr< Photo > _photo);//метод добовляющий фото в конец альбома
	void clearPhoto();
	void removePhoto(Photo const & _photo);
	int GetAlbumSize();
	typedef std::vector< std::unique_ptr< Photo > >::const_iterator PhotoIterator;
	/*https://github.com/zaychenko-sergei/oop-ki14/blob/master/lab2/demo_solution_14/employee.hpp */
	PhotoIterator AlbumBegin () const ;

	PhotoIterator AlbumEnd () const;
	/*bool hasPhoto(Photo const & _Photo) const;
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
	*/
	//https://docs.google.com/document/d/1UP9SSuE8wHZ18VnLXTET0yagEWAr3ms-xb07Xfs5l7o/edit# cтр 29 лекция 8
	class PhotoIterator
	{
	public:
		// Синонимы типов, нужные для согласования итератора и стандартной библиотеки
		typedef std::input_iterator_tag iterator_category;
		typedef Photo const * value_type;
		typedef ptrdiff_t difference_type;
		typedef Photo const ** pointer;
		typedef Photo const * & reference;
		// Синоним типа для итератора реально используемого контейнера
		typedef std::vector< std::unique_ptr< Photo > >::const_iterator BaseIterator;

		// Конструктор - принимает и запоминает итератор от контейнера
		PhotoIterator(BaseIterator _baseIt)
			: m_baseIt(_baseIt) {}

		// Оператор разыменования с целью чтения: превращаем умный указатель в обычный
		Photo const * operator * () const
		{
			return (*m_baseIt).get();
		}

		// Оператор префиксного инкремента: перенаправляем дочернему итератору
		PhotoIterator & operator ++ ()
		{
			++m_baseIt;
			return *this;
		}

		// Оператор сравнения на равенство: перенаправляем дочернему итератору
		bool operator == (PhotoIterator _it) const
		{
			return m_baseIt == _it.m_baseIt;
		}

		// Оператор сравнения на неравенство: перенаправляем дочернему итератору
		bool operator != (PhotoIterator _it) const
		{
			return m_baseIt != _it.m_baseIt;
		}

	private:

		// Итератор, полученный от контейнера
		BaseIterator m_baseIt;
	};


private:
	//название альбома
	const std::string & m_AlbumName;
	//набор фото
	std::vector< std::unique_ptr< Photo > > m_photo;//храним по умным указзателям 
	//std::vector <Photo *> m_photo;
};

inline Album::PhotoIterator
Album::AlbumBegin() const
{
	return PhotoIterator(m_photo.begin());
}

inline Album::PhotoIterator
Album::AlbumEnd() const
{
	return PhotoIterator(m_photo.end());
}

inline int Album::getPhotoCount() const
{
	return m_photo.size();
}
#endif // _ALBUM_HPP_


/*  Перебираем главы первой книги через интервальный цикл for
    for ( Chapter const * pChapter : pBook->chapters() )
        std::cout << pChapter->getTitle() << std::endl;*/