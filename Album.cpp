#include "Album.h"




Album::Album(const std::string & _AlbumName)
	:m_AlbumName(_AlbumName)
{
}

Album::Album(const std::string & _AlbumName, std::initializer_list<Photo*> _photo)
	:m_AlbumName(_AlbumName)
{
	// Обходим список инициализаторов и поэлементно добавляем фото в альбом
	for (Photo * m_photo : _photo)
		// Для добавления фото сразу оборачиваем сырые указатели в умные обертки
		addPhoto(std::unique_ptr< Photo >(m_photo));
}
/*
Album::~Album()
{
	clearPhoto();
}*/


void Album::addPhoto(std::unique_ptr< Photo > _photo)
{
	// Объекты std::unique_ptr не копируются, но зато эффективно перемещаются
	m_photo.push_back(std::move(_photo));
}

void Album::clearPhoto()
{
	// Достаточно просто очистить сам вектор.
	// Элементы уничтожатся автоматически
	m_photo.clear();
}


void Album::removePhoto(Photo const & _photo)
{
	size_t nPhoto = getPhotoCount();
	for (int i = 0; i < nPhoto; i++)
		if (m_photo[i].get() == &_photo)
		{// Достаточно убрать элемент из нужной позиции вектора
			// Уничтожение этого фото происходит автоматически
			m_photo.erase(m_photo.begin() + i);
			return;
		}
	//ошибка, такого фото нет
		throw std::logic_error("Photo does not exists in Album");

}



// Реализация метода, подтверждающего наличие главы в книге
bool Album::hasPhoto(Photo const & _photo) const
{
	size_t nPhoto = getPhotoCount();
	for (int i = 0; i < nPhoto; i++)
		// Извлекаем сырой указатель из умного при помощи метода get(),
		// сравниваем его с образцом
		if (m_photo[i].get() == &_photo)
			return true;

	return false;
}








//большая часть реализации подобна до 27 стр лк 8
//тест, пример стр 27 лк 8