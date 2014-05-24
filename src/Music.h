#ifndef MUSIC_H
#define MUSIC_H

#include <cstdio>
#include <SDL_Mixer.h>
#include <string>
#include <unordered_map>

#define MUSIC_FADE_OUT_TIME 2000

class Music
{
public:
    Music();
    Music(const std::string&);
    void play(int);
    void stop();
    void open(const std::string&);
    bool isOpen();
    static void clear();
private:
    std::string file;
	Mix_Music* music;
	static std::unordered_map<std::string,Mix_Music*> assetTable;
};

#endif // MUSIC_H
