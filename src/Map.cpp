#include "Map.h"

std::unordered_map<int,Stone*> Map::nodeMap;

Map::Map()
{
	 int i;

    std::ifstream file ("map/stoneMap.txt");
    std::string str,type;
    std::vector<int> links;
    int id;
    int end;
    int pos[2];


    if(file.is_open()){
        while(!file.eof()){
            getline(file,str,'\t'); 
            id = strtol(str.c_str(),nullptr,10);


            for(i=0;i<3;i++){
                getline(file,str,',');
                links.emplace_back(strtol(str.c_str(),nullptr,10));
            }

            for(i=0;i<2;i++){
                getline(file,str,',');
                pos[i] = strtol(str.c_str(),nullptr,10);
            }

            getline(file,type);
            //end = type.size() - type.find_last_of("\t");

            type.erase(0,type.find_last_of("\t")+1);


            nodeMap.emplace(id,new Stone((float)pos[0]+200,(float)pos[1],id,&links,type));
            links.clear();

        }
    }else{
        printf("Nao conseguiu abrir\n");
    }

    file.close();

    for(auto it=nodeMap.begin();it != nodeMap.end();++it){
        it->second->findPaths(6,nodeMap);
    }
}

Map& Map::getInstance(){
    static Map instance;
    return instance;
}

