#include "Photo.h"
#include "Album.h"
#include <iostream>
//Photo::Photo(const std::string & _roadTOFile, Date _year, Date _month, Date _Day, Time _hour, Time _minutes, const std::string & _commet)
#include <algorithm>
#include <memory>

int main()
{

	Photo Test1("D:\\ ", Date(1997, 10, 10), Time(13, 13), Place("��������", "������", "������"), "i`m in the moscov");
	Album testAlbum("TestAlbum");
	testAlbum.addPhoto(std::make_unique< Photo >("D:\\ ", Date(1997, 10, 10), Time(13, 13), Place("��������", "������", "������"), "� � ������"));
	testAlbum.addPhoto(std::make_unique< Photo >("D:\\ ", Date(1995, 10, 10), Time(13, 13), Place("�������sdf�", "�������", "�������"), "� � �������"));
	Album testAlbum2("TestAlbum2");
	Place testplace("sdfsdf", "sdfsdf", "sdfsdf");
	
	//std::cout << testAlbum.getPhotoRoadToFile();
	/*
	// ������� �������� ����� ����� ���������
	Album * pAlbum = &testAlbum;
	for (Photo const * pPhoto : pAlbu)
		std::cout << pPhoto->GetRoadToFile() << std::endl;
	// ���������� ����� ������ ����� ����� ������������ ���� for
	//for (std::unique_ptr< Photo > const & pPhoto : pAlbum->PhotosBegin)
		//sstd::cout << pPhoto->GetCommet() << std::endl;

	// ���������� �����
	delete pAlbum;


	system("pause");*/
}

/*int main ()
{
    Book b( "Some Title" );
    b.addChapter( std::make_unique< Chapter >( "AAA", 12 ) );
    b.addChapter( std::make_unique< Chapter >( "BBB", 15 ) );
    b.addChapter( std::make_unique< Chapter >( "CCC", 10 ) );

    // ... ��������� ���� ...
}*/