#include "Path.h"

Path::Path(int target,int distance,std::string path) : target(target),distance(distance),path(path)
{
}

int Path::getTarget(){
	return target;
}

int Path::getDistance(){
	return distance;
}

std::string Path::getPath(){
	return path;
}