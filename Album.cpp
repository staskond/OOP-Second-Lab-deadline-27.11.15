#include "Album.h"




Album::Album(const std::string & _AlbumName)
	:m_AlbumName(_AlbumName)
{
}

Album::Album(const std::string & _AlbumName, std::initializer_list<Photo*> _photo)
	:m_AlbumName(_AlbumName)
{
	// ������� ������ ��������������� � ����������� ��������� ���� � ������
	for (Photo * m_photo : _photo)
		// ��� ���������� ���� ����� ����������� ����� ��������� � ����� �������
		addPhoto(std::unique_ptr< Photo >(m_photo));
}
/*
Album::~Album()
{
	clearPhoto();
}*/


void Album::addPhoto(std::unique_ptr< Photo > _photo)
{
	// ������� std::unique_ptr �� ����������, �� ���� ���������� ������������
	m_photo.push_back(std::move(_photo));
}

void Album::clearPhoto()
{
	// ���������� ������ �������� ��� ������.
	// �������� ����������� �������������
	m_photo.clear();
}


void Album::removePhoto(Photo const & _photo)
{
	size_t nPhoto = getPhotoCount();
	for (int i = 0; i < nPhoto; i++)
		if (m_photo[i].get() == &_photo)
		{// ���������� ������ ������� �� ������ ������� �������
			// ����������� ����� ���� ���������� �������������
			m_photo.erase(m_photo.begin() + i);
			return;
		}
	//������, ������ ���� ���
		throw std::logic_error("Photo does not exists in Album");

}



// ���������� ������, ��������������� ������� ����� � �����
bool Album::hasPhoto(Photo const & _photo) const
{
	size_t nPhoto = getPhotoCount();
	for (int i = 0; i < nPhoto; i++)
		// ��������� ����� ��������� �� ������ ��� ������ ������ get(),
		// ���������� ��� � ��������
		if (m_photo[i].get() == &_photo)
			return true;

	return false;
}








//������� ����� ���������� ������� �� 27 ��� �� 8
//����, ������ ��� 27 �� 8