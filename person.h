#ifndef _PERSON_HPP_
#define _PERSON_HPP_
#include <string>


class Person
{
public:
	enum Gender
	{
		Fermale, Male
	};
	Person() = default;
	const std::string & GetFullName() const;
	const Gender & GetGender() const;
	Person(const std::string & _fullName, Gender _gender);

//	const std::vector <Person > GetPersons() {
	//	return m_persons;
	//};
	//static Person * Make(const std::string & _fullName, const std::string & _Gender);//обьявления метода фабрик
	
private:
	friend class Photo;
	friend class Controller;
	//закрытый конструктор, для использования метод фабрик
//	std::vector <Person > m_persons;
	const std::string m_FullName;
	Gender m_Gender;
};

inline const std::string & Person::GetFullName() const
{
	return m_FullName;
}
inline const Person::Gender & Person::GetGender() const
{
	return m_Gender;
}
;



#endif // _PERSON_HPP_
