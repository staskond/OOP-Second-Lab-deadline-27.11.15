#include "Photo.h"
#include "Album.h"
#include <iostream>
//Photo::Photo(const std::string & _roadTOFile, Date _year, Date _month, Date _Day, Time _hour, Time _minutes, const std::string & _commet)
#include <algorithm>
#include <memory>
#include "controller.h"

int main() {
//Photo Test1("D:\\ ", Date(1995, 10, 10), Time(13, 13), std::make_unique <Person>("naklme", Person::Gender::Male), "i1m ");
//Photo Test2("D:\\ ", Date(1995, 10, 10), Time(13, 13), std::make_unique <Person>("naklme", Person::Gender::Male), "i1m ");

//	Album testAlbum("TestAlbum");
//	testAlbum.addPhoto(std::make_unique< Photo >("D:\\ ", Date(1997, 10, 10), Time(13, 13), Place("AAA", "BBB", "CCC"), "Я в москве"));

	//testAlbum.addPhoto(std::make_unique< Photo > ("D:\\ ", Date(1995, 10, 10), Time(13, 13), std::make_unique <Person>("naklme", Person::Gender::Male), "i1m "));

//	for (auto const & pPhoto : testAlbum.GetPhoto())
//	{
	//	std::cout << pPhoto->GetPerson();
//	}
	//testAlbum.addPhoto((std::make_unique<Photo>(std::move(Test1))));

	//testAlbum.addPhoto(std::make_unique<Photo>(Test1));
//	Test1.addPerson(std::make_unique <Person>("naksdsalme", Person::Gender::Male));
	//testAlbum.GetPhoto()->addPerson(std::make_unique <Person>("naksdsasdslme", Person::Gender::Male));

	//Album testAlbum2("TestAlbum2");
//	Place testplace("sdfsdf", "sdfsdf", "sdfsdf");
//	for (auto const & photo : testAlbum.GetPhoto()) {
//		std::cout << photo->GetDate() << std::endl;
//		for (auto const & pPerson : photo->GetPerson())
//			std::cout << pPerson->GetFullName() << "\t" << pPerson->GetGender() << std::endl;
//	}
//	for (auto const & photo : testAlbum.GetPhoto())
//	{
//		std::cout << photo->GetPlace() << std::endl;
//	}*/
	//"Andrey", "Stas", "Kiril", "Sveta", "Julia", "Alina", "Nika"
	//p1 Andrey, Sveta, Julia        // Andrey - Julia :1    Andrey-Sveta :1     Sveta-Julia :1
	//p2 Julia, Alina, Andrey        // Andrey - Julia :2    Andrey-Alina :1     Alina-Julia:1
	//p3 Julia, Kiril, Andrey        //Andrey - Julia:3      Julia-Kiril:1      Kiril-Andrey:1
	//p4 Andrey - Alina:2/*
	
	Photo PhotoA1Test1("D:\\AlbumFirst\\phototest1.jpg", Date(2015, 1, 10), Time(14, 07), std::make_unique <Person>("Andrey", Person::Gender::Male), Place("Mountain", "Dombai", "Russia"), "Отдых 2015");
	Photo PhotoA1Test2("D:\\AlbumFirst\\phototest2.jpg", Date(2015, 10, 23), Time(23, 16), std::make_unique <Person>("Alina", Person::Gender::Fermale), "Отдых 2015");
	Photo PhotoA1Test3("D:\\AlbumFirst\\phototest3.jpg", Date(2015, 10, 11), Time(21, 9), std::make_unique <Person>("Kiril", Person::Gender::Male), Place("Kreml", "Moscow", "Russia"), "Отдых 2015");
	Photo PhotoA1Test4("D:\\AlbumFirst\\phototest4.jpg", Date(2014, 9, 05), Time(23, 07), std::make_unique <Person>("Alina", Person::Gender::Fermale), Place("Ploshad", "Kiev", "Ukrain"), "Отдых 2014");
	Photo PhotoA1Test5("D:\\AlbumFirst\\phototest5.jpg", Date(2013, 9, 06), Time(00, 01), std::make_unique <Person>("Alina", Person::Gender::Fermale), Place("Otel", "Kiev", "Ukrain"), "Отдых 2013");
	Photo PhotoA1Test6("D:\\AlbumFirst\\phototest6.jpg", Date(2012, 5, 30), Time(20, 00), std::make_unique <Person>("Kiril", Person::Gender::Male), "Отдых 2012");
	Photo PhotoA1Test7("D:\\AlbumFirst\\phototest5.jpg", Date(2010, 1, 11), Time(8, 40), std::make_unique <Person>("Stas", Person::Gender::Male), Place("Kurort", "Dombai", "Russia"), "Отдых 2010");
	Photo PhotoA1Test8("D:\\AlbumFirst\\phototest4.jpg", Date(2014, 9, 05), Time(18, 15), std::make_unique <Person>("Stas", Person::Gender::Fermale), Place("Ploshad", "Kiev", "Ukrain"), "Отдых 2014");
	Photo PhotoA1Test9("D:\\AlbumFirst\\phototest4.jpg", Date(2014, 5, 05), Time(17, 33), std::make_unique <Person>("Bernard", Person::Gender::Male), Place("Subway", "New-York", "USA"), "Отдых 2014");
	Photo PhotoA1Test10("D:\\AlbumFirst\\phototest4.jpg", Date(2015, 11, 23), Time(07, 11), std::make_unique <Person>("Kristina", Person::Gender::Fermale), Place("Home", "Moscow", "Russia"), "Отдых 2015");
	//"Kristina", "Masha", "Bernard", "Bonifaciy", "Lionel" "Benedict", "Barbara", "Beatrisa", 
	Photo PhotoA2Test1("D:\\AlbumSecond\\phototest1.jpg", Date(2009, 6, 10), Time(14, 07), std::make_unique <Person>("Andrey", Person::Gender::Male), Place("Mountain", "Dombai", "Russia"), "Отдых 2015");
	Photo PhotoA2Test2("D:\\AlbumSecond\\phototest2.jpg", Date(2011, 10, 23), Time(23, 16), "Отдых 2015");
	Photo PhotoA2Test3("D:\\AlbumSecond\\phototest3.jpg", Date(2014, 10, 11), Time(21, 9), Place("Kreml", "Moscow", "Russia"), "Отдых 2015");
	Photo PhotoA2Test4("D:\\AlbumSecond\\phototest4.jpg", Date(2014, 9, 05), Time(23, 07), std::make_unique <Person>("Kristina", Person::Gender::Fermale), Place("Ploshad", "Kharkiv", "Ukrain"), "Отдых 2014");
	Photo PhotoA2Test5("D:\\AlbumSecond\\phototest5.jpg", Date(2008, 9, 06), Time(00, 01), std::make_unique <Person>("Alina", Person::Gender::Fermale), Place("Subway", "New-York", "USA"), "Отдых 2013");
	Photo PhotoA2Test6("D:\\AlbumSecond\\phototest6.jpg", Date(2005, 5, 30), Time(20, 00), std::make_unique <Person>("Bonifaciy", Person::Gender::Male), "Отдых 2012");
	Photo PhotoA2Test7("D:\\AlbumSecond\\phototest5.jpg", Date(2007, 1, 11), Time(8, 40), std::make_unique <Person>("Stas", Person::Gender::Male), Place("Kurort", "Dombai", "Russia"), "Отдых 2010");
	Photo PhotoA2Test8("D:\\AlbumSecond\\phototest4.jpg", Date(2010, 9, 05), Time(18, 15), std::make_unique <Person>("Barbara", Person::Gender::Fermale), Place("Ploshad", "Kiev", "Ukrain"), "Отдых 2014");
	Photo PhotoA2Test9("D:\\AlbumSecond\\phototest4.jpg", Date(2014, 5, 05), Time(17, 33), std::make_unique <Person>("Beatrisa", Person::Gender::Fermale), Place("Subway", "New-York", "USA"), "Отдых 2014");
	Photo PhotoA2Test10("D:\\AlbumSecond\\phototest4.jpg", Date(2015, 10, 23), Time(07, 11), std::make_unique <Person>("Bernard", Person::Gender::Male), "Отдых 2015");

	Photo PhotoA3Test1("D:\\AlbumThird\\phototest1.jpg", Date(2009, 6, 10), Time(14, 07), Place("Mountain", "Dombai", "Russia"), "Отдых 2015");
	Photo PhotoA3Test2("D:\\AlbumThird\\phototest2.jpg", Date(2011, 10, 24), Time(23, 16), "Отдых 2015");
	Photo PhotoA3Test3("D:\\AlbumThird\\phototest3.jpg", Date(2014, 10, 11), Time(15, 10), Place("Kreml", "Sankt-Peterburg", "Russia"), "Отдых 2015");
	Photo PhotoA3Test4("D:\\AlbumThird\\phototest4.jpg", Date(2014, 9, 11), Time(23, 07), std::make_unique <Person>("Kristina", Person::Gender::Fermale), Place("Ploshad", "Kharkiv", "Ukrain"), "Отдых 2014");
	Photo PhotoA3Test5("D:\\AlbumThird\\phototest5.jpg", Date(2008, 9, 06), Time(00, 01), std::make_unique <Person>("Alina", Person::Gender::Fermale), Place("Subway", "New-York", "USA"), "Отдых 2013");
	Photo PhotoA3Test6("D:\\AlbumThird\\phototest6.jpg", Date(2005, 9, 30), Time(20, 01), std::make_unique <Person>("Bonifaciy", Person::Gender::Male), "Отдых 2012");
	Photo PhotoA3Test7("D:\\AlbumThird\\phototest5.jpg", Date(2007, 1, 12), Time(8, 45), std::make_unique <Person>("Stas", Person::Gender::Male), Place("Kurort", "Moscow", "Russia"), "Отдых 2010");
	Photo PhotoA3Test8("D:\\AlbumThird\\phototest4.jpg", Date(2010, 9, 16), Time(15, 16), std::make_unique <Person>("Barbara", Person::Gender::Fermale), Place("Ploshad", "Kharkiv", "Ukrain"), "Отдых 2014");
	Photo PhotoA3Test9("D:\\AlbumThird\\phototest4.jpg", Date(2014, 5, 15), Time(19, 33), std::make_unique <Person>("Beatrisa", Person::Gender::Fermale), Place("Subway", "New-York", "USA"), "Отдых 2014");
	Photo PhotoA3Test10("D:\\AlbumThird\\phototest4.jpg", Date(2015, 5, 23), Time(11, 11), std::make_unique <Person>("Bernard", Person::Gender::Male), "Отдых 2015");


	Photo PhotoA4Test1("D:\\AlbumFourth\\phototest1.jpg", Date(2009, 6, 10), Time(14, 07), Place("Mountain", "Kiev", "Ukrain"), "Отдых 2015");
	Photo PhotoA4Test2("D:\\AlbumFourth\\phototest2.jpg", Date(2011, 10, 24), Time(23, 16), "Отдых 2015");
	Photo PhotoA4Test3("D:\\AlbumFourth\\phototest3.jpg", Date(2014, 10, 11), Time(15, 10), Place("Kreml", "Sankt-Peterburg", "Russia"), "Отдых 2015");
	Photo PhotoA4Test4("D:\\AlbumFourth\\phototest4.jpg", Date(2014, 9, 11), Time(23, 07), Place("Ploshad", "Kharkiv", "Ukrain"), "Отдых 2014");
	Photo PhotoA4Test5("D:\\AlbumFourth\\phototest5.jpg", Date(2008, 9, 06), Time(00, 01), Place("Subway", "New-York", "USA"), "Отдых 2013");
	Photo PhotoA4Test6("D:\\AlbumFourth\\phototest6.jpg", Date(2005, 9, 30), Time(20, 01),  "Отдых 2012");
	Photo PhotoA4Test7("D:\\AlbumFourth\\phototest5.jpg", Date(2007, 1, 12), Time(8, 45),  Place("Kurort", "Moscow", "Russia"), "Отдых 2010");
	Photo PhotoA4Test8("D:\\AlbumFourth\\phototest4.jpg", Date(2010, 9, 16), Time(15, 16),  Place("Ploshad", "Kharkiv", "Ukrain"), "Отдых 2014");
	Photo PhotoA4Test9("D:\\AlbumFourth\\phototest4.jpg", Date(2014, 5, 15), Time(19, 33),  Place("Subway", "New-York", "USA"), "Отдых 2014");
	Photo PhotoA4Test10("D:\\AlbumFourth\\phototest4.jpg", Date(2015, 5, 23), Time(11, 11), "Отдых 2015");
	//"Kristina", "Masha", "Bernard", "Bonifaciy", "Lionel" "Benedict", "Barbara", "Beatrisa", 
	
	PhotoA1Test1.addPerson("Sveta", Person::Gender::Fermale);
	PhotoA1Test1.addPerson("Julia", Person::Gender::Fermale);

	PhotoA2Test2.addPerson("Sveta", Person::Gender::Fermale);
	PhotoA2Test2.addPerson("Andrey", Person::Gender::Male);

	PhotoA1Test3.addPerson("Alina", Person::Gender::Male);
	PhotoA1Test3.addPerson("Andrey", Person::Gender::Male);

	PhotoA1Test4.addPerson("Stas", Person::Gender::Male);
	PhotoA1Test4.addPerson("Andrey", Person::Gender::Male);

	PhotoA1Test5.addPerson("Stas", Person::Gender::Male);
	PhotoA1Test5.addPerson("Sveta", Person::Gender::Fermale);

	PhotoA1Test6.addPerson("Bernard", Person::Gender::Male);
	PhotoA1Test6.addPerson("Nika", Person::Gender::Fermale);

	PhotoA1Test7.addPerson("Kiril", Person::Gender::Male);
	PhotoA1Test7.addPerson("Nika", Person::Gender::Fermale);

	PhotoA1Test8.addPerson("Julia", Person::Gender::Fermale);
	PhotoA1Test8.addPerson("Andrey", Person::Gender::Male);

	PhotoA1Test9.addPerson("Vlad", Person::Gender::Male);
	PhotoA1Test9.addPerson("Akim", Person::Gender::Male);

	PhotoA1Test10.addPerson("Vlad", Person::Gender::Male);
	PhotoA1Test10.addPerson("Akim", Person::Gender::Male);

	//"Kristina", "Masha", "Bernard", "Bonifaciy", "Lionel" "Benedict", "Barbara", "Beatrisa",
	PhotoA2Test1.addPerson("Kristina", Person::Gender::Fermale);
	PhotoA2Test1.addPerson("Masha", Person::Gender::Fermale);

	PhotoA2Test3.addPerson("Kiril", Person::Gender::Male);
	PhotoA2Test3.addPerson("Bernard", Person::Gender::Male);

	PhotoA2Test4.addPerson("Stas", Person::Gender::Male);
	PhotoA2Test4.addPerson("Beatrisa", Person::Gender::Fermale);

	PhotoA2Test5.addPerson("Stas", Person::Gender::Male);
	PhotoA2Test5.addPerson("Beatrisa", Person::Gender::Fermale);

	PhotoA2Test6.addPerson("Bernard", Person::Gender::Male);
	PhotoA2Test6.addPerson("Benedict", Person::Gender::Male);

	PhotoA2Test7.addPerson("Kristina", Person::Gender::Fermale);
	PhotoA2Test7.addPerson("Masha", Person::Gender::Fermale);

	PhotoA2Test9.addPerson("Vlad", Person::Gender::Male);
	PhotoA2Test9.addPerson("Ivan", Person::Gender::Male);

	PhotoA2Test10.addPerson("Ivan", Person::Gender::Male);
	PhotoA2Test10.addPerson("Akim", Person::Gender::Male);

	//
	PhotoA3Test1.addPerson("Akim", Person::Gender::Male);
	PhotoA3Test1.addPerson("Ivan", Person::Gender::Male);

	PhotoA3Test3.addPerson("Kiril", Person::Gender::Male);
	PhotoA3Test3.addPerson("Vlad", Person::Gender::Male);

	PhotoA3Test4.addPerson("Ivan", Person::Gender::Male);
	PhotoA3Test4.addPerson("Beatrisa", Person::Gender::Fermale);

	PhotoA3Test5.addPerson("Stas", Person::Gender::Male);
	PhotoA3Test5.addPerson("Beatrisa", Person::Gender::Fermale);

	PhotoA3Test6.addPerson("Bernard", Person::Gender::Male);
	PhotoA3Test6.addPerson("Benedict", Person::Gender::Male);

	PhotoA3Test7.addPerson("Kristina", Person::Gender::Fermale);
	PhotoA3Test7.addPerson("Masha", Person::Gender::Male);

	PhotoA3Test9.addPerson("Masha", Person::Gender::Male);
	PhotoA3Test9.addPerson("Ivan", Person::Gender::Male);

	PhotoA3Test10.addPerson("Masha", Person::Gender::Fermale);
	PhotoA3Test10.addPerson("Akim", Person::Gender::Male);

	Album TestAlbum1("TestAlbum1");

	TestAlbum1.addPhoto(PhotoA1Test1);
	TestAlbum1.addPhoto(PhotoA1Test2);
	TestAlbum1.addPhoto(PhotoA1Test3);
	TestAlbum1.addPhoto(PhotoA1Test4);
	TestAlbum1.addPhoto(PhotoA1Test5);
	TestAlbum1.addPhoto(PhotoA1Test6);
	TestAlbum1.addPhoto(PhotoA1Test7);
	TestAlbum1.addPhoto(PhotoA1Test8);
	TestAlbum1.addPhoto(PhotoA1Test9);
	TestAlbum1.addPhoto(PhotoA1Test10);

	Album TestAlbum2("TestAlbum2");

	TestAlbum2.addPhoto(PhotoA2Test1);
	TestAlbum2.addPhoto(PhotoA2Test2);
	TestAlbum2.addPhoto(PhotoA2Test3);
	TestAlbum2.addPhoto(PhotoA2Test4);
	TestAlbum2.addPhoto(PhotoA2Test5);
	TestAlbum2.addPhoto(PhotoA2Test6);
	TestAlbum2.addPhoto(PhotoA2Test7);
	TestAlbum2.addPhoto(PhotoA2Test8);
	TestAlbum2.addPhoto(PhotoA2Test9);
	TestAlbum2.addPhoto(PhotoA2Test10);

	Album TestAlbum3("TestAlbum3");

	TestAlbum3.addPhoto(PhotoA3Test1);
	TestAlbum3.addPhoto(PhotoA3Test2);
	TestAlbum3.addPhoto(PhotoA3Test3);
	TestAlbum3.addPhoto(PhotoA3Test4);
	TestAlbum3.addPhoto(PhotoA3Test5);
	TestAlbum3.addPhoto(PhotoA3Test6);
	TestAlbum3.addPhoto(PhotoA3Test7);
	TestAlbum3.addPhoto(PhotoA3Test8);
	TestAlbum3.addPhoto(PhotoA3Test9);
	TestAlbum3.addPhoto(PhotoA3Test10);

	Album TestAlbum4("TestAlbum4");

	TestAlbum4.addPhoto(PhotoA4Test1);
	TestAlbum4.addPhoto(PhotoA4Test2);
	TestAlbum4.addPhoto(PhotoA4Test3);
	TestAlbum4.addPhoto(PhotoA4Test4);
	TestAlbum4.addPhoto(PhotoA4Test5);
	TestAlbum4.addPhoto(PhotoA4Test6);
	TestAlbum4.addPhoto(PhotoA4Test7);
	TestAlbum4.addPhoto(PhotoA4Test8);
	TestAlbum4.addPhoto(PhotoA4Test9);
	TestAlbum4.addPhoto(PhotoA4Test10);
	

	

	//TestAlbum4.addPhoto(PhotoA4Test10);
	
	Controller temp;
	temp.addAlbum(TestAlbum1);
	temp.addAlbum(TestAlbum4);
	temp.addAlbum(TestAlbum2);
	temp.addAlbum(TestAlbum3);
	
	temp.AlbumWithPeople();
	temp.AlbumWithoutPeople();
	std::cin.get();
	temp.FindandPrintPhotoWithAllFrineds();//не работает
	std::cin.get();
	temp.printAllPhotosInTheLastYear();//работает
	std::cin.get();
	temp.printPhotoSeasonal();//работает
	std::cin.get();
	temp.printTheFiveMostPopularPeoples();
	std::cin.get();
	temp.printTheFiveMostPopularСities();
	std::cin.get();
	

//	for (auto const & pPhoto : testAlbum.GetPhoto())
//	{
//		for(auto const & pPerson: pPhoto->GetPerson())
			
	//		pPhoto->GetPerson().push_back()
//	}


		//Photo(const std::string & _roadTOFile, Date _date, Time _time, std::vector <Person> _person, const std::string & _commet);
}

/*int main ()
{
    Book b( "Some Title" );
    b.addChapter( std::make_unique< Chapter >( "AAA", 12 ) );
    b.addChapter( std::make_unique< Chapter >( "BBB", 15 ) );
    b.addChapter( std::make_unique< Chapter >( "CCC", 10 ) );

    // ... обработка глав ...}
}*/