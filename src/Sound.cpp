#include "Sound.h"


std::unordered_map<std::string,Mix_Chunk*>  Sound::assetTable;

Sound::Sound()
{
	chunk = nullptr;
}

Sound::Sound(const std::string& file){
	open(file);
}

void Sound::play(int times){
	channel = Mix_PlayChannel(-1,chunk,times);
}

void Sound::stop(){
	Mix_HaltChannel(channel);
}

void Sound::open(const std::string& file){

	 if(assetTable.find(file) == assetTable.end()){
        if((chunk=Mix_LoadWAV(file.c_str()))==nullptr){
            printf("nao foi possivel carregar o chunck %s\n", file.c_str());
            printf("%s\n",SDL_GetError());
            return;
        }else{
            assetTable.emplace(file,chunk);
        }

    }else{
        chunk = assetTable[file];
    }
}

bool Sound::isOpen(){
	return chunk != nullptr;
}

void Sound::clear(){	
	for ( auto it = assetTable.begin(); it!= assetTable.end(); ++it ){
       Mix_FreeChunk(it->second);
    }
    assetTable.clear();
}

