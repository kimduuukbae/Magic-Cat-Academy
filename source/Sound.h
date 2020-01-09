#pragma once

#include <map>
#include "./Dependencies/IrrKlang.h"
#pragma comment(lib, "irrKlang.lib") 

using namespace irrklang;

class Sound
{
public:
	Sound();
	~Sound();
	static Sound& instance();
	int CreateBGSound(char* filePath);
	void DeleteBGSound(int index);
	void PlayBGSound(int index, bool bLoop, float volume);
	void StopBGSound(int index);

	int CreateShortSound(char* filePath);
	void DeleteShortSound(int index);
	void PlayShortSound(int index, bool bLoop, float volume);		

private:
	ISoundEngine* m_engine = NULL;

	std::map<int, ISound*> m_bgSoundList;
	std::map<int, ISoundSource*> m_shortSoundList;
};

