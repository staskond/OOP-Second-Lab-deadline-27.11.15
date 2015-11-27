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
	//~Album();
	//Album(const Album &) = delete;
	//Album & operator = (const Album &) = delete;
//	friend std::ostream & operator << (std::ostream &_o, Album _value);
	void PrintAlbumName();
	size_t getPhotoCount() const;//����� ������������ ���������� ���� � �������
	void addPhoto(std::unique_ptr< Photo > _photo);//����� ����������� ���� � ����� �������
	void addPhoto(Photo &_photo);
	void clearPhoto();
	void removePhoto(Photo const & _photo);
	bool hasPhoto(Photo const & _photo) const;
	const std::string & GetAlbumName() const;
//	const std::vector< std::unique_ptr< Photo > > & GetPhoto() const { return m_photo; };

private:
	friend class Controller;
	//�������� �������
	const std::string & m_AlbumName;
	//����� ����
	std::vector< std::unique_ptr< Photo > > m_photo;//������ �� ����� ����������� 
	//std::vector <Photo *> m_photo;
};

inline const std::string & Album::GetAlbumName() const
{
	return m_AlbumName;
}


inline size_t Album::getPhotoCount() const
{
	return m_photo.size();
}



#endif // _ALBUM_HPP_


/*  ���������� ����� ������ ����� ����� ������������ ���� for
    for ( Chapter const * pChapter : pBook->chapters() )
        std::cout << pChapter->getTitle() << std::endl;*/