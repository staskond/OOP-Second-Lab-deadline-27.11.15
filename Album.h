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
	size_t getPhotoCount() const;//����� ������������ ���������� ���� � �������
	void addPhoto(std::unique_ptr< Photo > _photo);//����� ����������� ���� � ����� �������
	void clearPhoto();
	void removePhoto(Photo const & _photo);
	bool hasPhoto(Photo const & _photo) const;
	const std::vector< std::unique_ptr< Photo > > & GetPhoto() const { return m_photo; };

private:
	friend class Application;
	//�������� �������
	const std::string & m_AlbumName;
	//����� ����
	std::vector< std::unique_ptr< Photo > > m_photo;//������ �� ����� ����������� 
	//std::vector <Photo *> m_photo;
};



inline size_t Album::getPhotoCount() const
{
	return m_photo.size();
}



#endif // _ALBUM_HPP_


/*  ���������� ����� ������ ����� ����� ������������ ���� for
    for ( Chapter const * pChapter : pBook->chapters() )
        std::cout << pChapter->getTitle() << std::endl;*/