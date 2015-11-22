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
	int getPhotoCount() const { return m_photo.size(); }//����� ������������ ���������� ���� � �������
	void addPhoto(Photo * _photo);//����� ����������� ���� � ����� �������
	void clearPhoto();



private:
	//�������� �������
	const std::string & m_AlbumName;
	//����� ����
	std::vector <Photo *> m_photo;
};

#endif // _ALBUM_HPP_
