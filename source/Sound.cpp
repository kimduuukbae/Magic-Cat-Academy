#include "stdafx.h"
#include <iostream>
#include "Sound.h"

#define MAX_SOUND 100

Sound::Sound()
{
	m_engine = createIrrKlangDevice();

	if (!m_engine)
	{
		std::cout << "Sound Initialization failed. \n";
	}
}

int Sound::CreateBGSound(char* filePath)
{
	int index = 0;

	for (int i = 1; i < MAX_SOUND; i++)
	{
		if (m_bgSoundList.find(i) == m_bgSoundList.end())
		{
			index = i;
			break;
		}
	}
	ISound* tempSound = m_engine->play2D(filePath, false, true, true);
	if (tempSound == NULL)
	{
		std::cout << "Sound creation fails. \n";
		return -1;
	}
	m_bgSoundList.insert(std::pair<int, ISound*>(index, tempSound));

	return index;
}

void Sound::DeleteBGSound(int index)
{
	std::map<int, ISound*>::iterator iter;

	iter = m_bgSoundList.find(index);

	if (iter == m_bgSoundList.end())
	{
		std::cout << "No such sound with index " << index << ". \n";
		return;
	}
	(*iter).second->stop();
	m_bgSoundList.erase(index);
}

void Sound::PlayBGSound(int index, bool bLoop, float volume)
{
	std::map<int, ISound*>::iterator iter;

	iter = m_bgSoundList.find(index);

	if (iter == m_bgSoundList.end())
	{
		std::cout << "No such sound with index " << index << ". \n";
		return;
	}
	(*iter).second->setVolume(volume); 
	(*iter).second->setPlayPosition(0);
	(*iter).second->setIsPaused(false); 
	(*iter).second->setIsLooped(bLoop);
}

void Sound::StopBGSound(int index)
{
	std::map<int, ISound*>::iterator iter;

	iter = m_bgSoundList.find(index);

	if (iter == m_bgSoundList.end())
	{
		std::cout << "No such sound with index " << index << ". \n";
		return;
	}
	(*iter).second->setIsPaused(true);
}

int Sound::CreateShortSound(char* filePath)
{
	int index = 0;

	for (int i = 1; i < MAX_SOUND; i++)
	{
		if (m_shortSoundList.find(i) == m_shortSoundList.end())
		{
			index = i;
			break;
		}
	}
	ISoundSource* tempSound = m_engine->addSoundSourceFromFile(filePath);
	if (tempSound == NULL)
	{
		std::cout << "Sound creation fails. \n";
		return -1;
	}
	m_shortSoundList.insert(std::pair<int, ISoundSource*>(index, tempSound));

	return index;
}

void Sound::DeleteShortSound(int index)
{
	std::map<int, ISoundSource*>::iterator iter;

	iter = m_shortSoundList.find(index);

	if (iter == m_shortSoundList.end())
	{
		std::cout << "No such sound with index " << index << ". \n";
		return;
	}
	m_shortSoundList.erase(index);
}

void Sound::PlayShortSound(int index, bool bLoop, float volume)
{
	std::map<int, ISoundSource*>::iterator iter;

	iter = m_shortSoundList.find(index);

	if (iter == m_shortSoundList.end())
	{
		std::cout << "No such sound with index " << index << ". \n";
		return;
	}
	(*iter).second->setDefaultVolume(volume);
	m_engine->play2D((*iter).second, bLoop);
}

Sound::~Sound()
{
	m_bgSoundList.clear();
	m_shortSoundList.clear();

	delete m_engine;
}

Sound & Sound::instance(){
	static Sound inst;
	return inst;
}
