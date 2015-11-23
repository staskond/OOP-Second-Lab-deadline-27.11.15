#ifndef _PERSON_HPP_
#define _PERSON_HPP_
#include <string>


class Person
{
public:
	enum Gender
	{
		Male, Fermale
	};
	Person() = default;
	const std::string & GetFullName() const;
	const Gender & GetGender() const;
	Person(const std::string & _fullName, Gender _gender);
	//static Person * Make(const std::string & _fullName, const std::string & _Gender);//обьявления метода фабрик
	
private:
	friend class Photo;
	friend class Controller;
	//закрытый конструктор, для использования метод фабрик
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
