#pragma once
#include <vector>
#include <string>

#include "Observer.h"

template<typename T>
class Observable
{
public:
	void notified(T& source, std::string field);

	void addLieners(Observer<T>* newLisener);
	void removeLisener(Observer<T>* lisener);

private:
	std::vector<Observer<T>*> m_Liseners{};
};

template<typename T>
inline void Observable<T>::notified(T& source, std::string field)
{
	for (auto& it : m_Liseners)
	{
		it->field_changed(source, field);
	}
}

template<typename T>
inline void Observable<T>::addLieners(Observer<T>* newLisener)
{
	m_Liseners.push_back(newLisener);
}

template<typename T>
inline void Observable<T>::removeLisener(Observer<T>* lisener)
{
	m_Liseners.erase(lisener);
}
