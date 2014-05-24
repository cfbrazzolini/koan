#ifndef SOUND_H
#define SOUND_H

#include <cstdio>
#include <SDL_Mixer.h>
#include <string>
#include <unordered_map>

#define MUSIC_FADE_OUT_TIME 2000

class Sound
{
public:
    Sound();
    Sound(const std::string&);
    void play(int);
    void stop();
    void open(const std::string&);
    bool isOpen();
    static void clear();
private:
    std::string file;
	Mix_Chunk* chunk;
	int channel;
	static std::unordered_map<std::string,Mix_Chunk*> assetTable;
};
#endif // SOUND_H
