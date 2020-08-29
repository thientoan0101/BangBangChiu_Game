#include "Audio.h"

// Audio:
Mix_Chunk* g_sound_bullet[2];	//am thanh cac loai dan: (2 loai)
Mix_Chunk* g_sound_ex_boss = NULL;
Mix_Chunk* g_sound_ex_main = NULL;
Mix_Chunk* g_sound_injured = NULL;
Mix_Chunk* g_sound_ready = NULL;


void AudioFunction::prepareAudioFile()
{
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)	//return false;
		return;


	//Read file wav audio:
	g_sound_bullet[0] = Mix_LoadWAV("bullet.wav");
	g_sound_bullet[1] = Mix_LoadWAV("rocket.wav");
	g_sound_injured = Mix_LoadWAV("small_explo.wav");

	g_sound_ex_boss = Mix_LoadWAV("boss_died.wav");
	g_sound_ex_main = Mix_LoadWAV("main_died.wav");
	g_sound_ready = Mix_LoadWAV("ready.wav");
	if (g_sound_bullet[0] == NULL || g_sound_bullet[1] == NULL || g_sound_injured == NULL || g_sound_ex_boss == NULL || g_sound_ex_main == NULL)
	{
		//return false;
		return;
	}
}

