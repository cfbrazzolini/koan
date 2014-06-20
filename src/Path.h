#ifndef PATH_H
#define PATH_H

#include <string>

class Path
{
public:
    Path(int,int,std::string);
    int getTarget();
    int getDistance();
    std::string getPath();
private:
	int target;
	int distance;
	std::string path;
};

#endif // PATH_H
