#include "Photo.h"
#include "Album.h"
#include <iostream>
//Photo::Photo(const std::string & _roadTOFile, Date _year, Date _month, Date _Day, Time _hour, Time _minutes, const std::string & _commet)
#include <algorithm>
#include <memory>

int main() {
	Photo Test1("D:\\ ", Date(1997, 10, 10), Time(13, 13), Place("Памятник", "Москва", "Россия"), "i`m in the moscov");
	Album testAlbum("TestAlbum");
	testAlbum.addPhoto(std::make_unique< Photo >("D:\\ ", Date(1997, 10, 10), Time(13, 13), Place("AAA", "BBB", "CCC"), "Я в москве"));
	testAlbum.addPhoto(std::make_unique< Photo >("D:\\ ", Date(1995, 10, 10), Time(13, 13), std::make_unique <Person>("naklme", Person::Gender::Male), "i1m "));
	Test1.addPerson(std::make_unique <Person>("naksdsalme", Person::Gender::Male));
	//testAlbum.GetPhoto()->addPerson(std::make_unique <Person>("naksdsasdslme", Person::Gender::Male));

	Album testAlbum2("TestAlbum2");
	Place testplace("sdfsdf", "sdfsdf", "sdfsdf");
	for (auto const & photo : testAlbum.GetPhoto()) {
		std::cout << photo->GetDate() << std::endl;
		for (auto const & pPerson : photo->GetPerson())
			std::cout << pPerson->GetFullName() << "\t" << pPerson->GetGender() << std::endl;
	}
	for (auto const & photo : testAlbum.GetPhoto())
	{
		std::cout << photo->GetPlace() << std::endl;
	}

//	for (auto const & pPhoto : testAlbum.GetPhoto())
//	{
//		for(auto const & pPerson: pPhoto->GetPerson())
			
	//		pPhoto->GetPerson().push_back()
//	}

		system("pause >> void");
		//Photo(const std::string & _roadTOFile, Date _date, Time _time, std::vector <Person> _person, const std::string & _commet);
}

/*int main ()
{
    Book b( "Some Title" );
    b.addChapter( std::make_unique< Chapter >( "AAA", 12 ) );
    b.addChapter( std::make_unique< Chapter >( "BBB", 15 ) );
    b.addChapter( std::make_unique< Chapter >( "CCC", 10 ) );

    // ... обработка глав ...
}*/