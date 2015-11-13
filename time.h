#pragma once
#ifndef _TIME_HPP_
#define _TIME_HPP_

class Time
{
public:
	Time();
	Time(const int _hour, const int _minutes);
	//static Time * Make(const int _hour, const int _minutes);в реализации не хочет работать функция isValide
	int GetHour() const;
	int GetMinutes() const;
	bool isValide() const;
	void NextMinute();
private:
	//Time(const int _hour, const int _minutes);закрытый конструктор фабрик, нужен только если буду использовать этот метод
	int m_hour;
	int m_minutes;

};


inline int Time::GetHour() const
{
	return m_hour;
}

inline int Time::GetMinutes() const
{
	return m_minutes;
}

#endif //_TIME_HPP_