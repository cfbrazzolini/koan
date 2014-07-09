#include "Music.h"

#include <ostream>
using namespace std;
std::unordered_map<std::string,Mix_Music*>  Music::assetTable;
std::unordered_map<std::string,Mix_Chunk*>  Music::assetTableChannel;

Music::Music()
{
	music = nullptr;
}

Music::Music(const std::string& file, int times){
    if(times != 0)
    	open(file);
    else
        open(file, times);
}

void Music::play(int times){
	Mix_PlayMusic(music,times);
}

void Music::stop(){
	Mix_FadeOutMusic(MUSIC_FADE_OUT_TIME);
}

void Music::open(const std::string& file){

	 if(assetTable.find(file) == assetTable.end()){
        if((music=Mix_LoadMUS(file.c_str()))==nullptr){
            printf("nao foi possivel carregar a musica %s\n", file.c_str());
            printf("%s\n",SDL_GetError());
            return;
        }else{
            assetTable.emplace(file,music);
        }

    }else{
        music = assetTable[file];
    }
}

bool Music::isOpen(){
	return music != nullptr;
}

void Music::clear(){	
	for ( auto it = assetTable.begin(); it!= assetTable.end(); ++it ){
       Mix_FreeMusic(it->second);
    }
    assetTable.clear();
}

void Music::pause(){
    Mix_PauseMusic();
}

void Music::resume(){
    if(Mix_PausedMusic() == 1){
        Mix_ResumeMusic();
    }
}

int Music::isPaused(){
    return(Mix_PausedMusic());
}

void Music::open(const std::string& file, int times){
    ;
    if(assetTableChannel.find(file) == assetTableChannel.end()){
        if((sound=Mix_LoadWAV(file.c_str()))==nullptr){
            printf("nao foi possivel carregar o channel %s\n", file.c_str());
            printf("%s\n",SDL_GetError());
            return;
        }else{
            assetTableChannel.emplace(file,sound);
        }

    }else{
        sound = assetTableChannel[file];
    }
}

void Music::playChannel(int times){
    channel = Mix_PlayChannel(1,sound,0);
}

void Music::stopChannel(){
    Mix_FadeOutChannel(channel, MUSIC_FADE_OUT_TIME);
}

void Music::clearChannel(){    
    for ( auto it = assetTableChannel.begin(); it!= assetTableChannel.end(); ++it ){
       Mix_FreeChunk(it->second);
    }
    assetTableChannel.clear();
}