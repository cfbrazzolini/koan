#include "Music.h"

std::unordered_map<std::string,Mix_Music*>  Music::assetTable;

Music::Music()
{
	music = nullptr;
}

Music::Music(const std::string& file){
	open(file);
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
