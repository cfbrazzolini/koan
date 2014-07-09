#ifndef MUSIC_H
#define MUSIC_H

#include <cstdio>
#include <SDL_mixer.h>
#include <string>
#include <unordered_map>

#define MUSIC_FADE_OUT_TIME 2000

class Music
{
public:
    Music();
    Music(const std::string&, int);
    void play(int);
    void stop();
    void open(const std::string&);
    void open(const std::string&, int);
    bool isOpen();
    static void clear();

    void pause();
    void resume();
    int isPaused();
    void playChannel(int);
    void stopChannel();
    static void clearChannel();
private:
    std::string file;
	Mix_Music* music;
    Mix_Chunk* sound;
	static std::unordered_map<std::string,Mix_Music*> assetTable;
    static std::unordered_map<std::string,Mix_Chunk*> assetTableChannel;
    int channel;
};

#endif // MUSIC_H
