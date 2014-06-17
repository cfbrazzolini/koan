#ifndef STATE_H
#define STATE_H

#include <memory>
#include <vector>

#include "GameObject.h"

class State
{
public:
    State();
    virtual ~State();
    virtual void update(float) = 0;
    virtual void render() = 0;
    virtual void addObject(GameObject*);
    bool requestedDelete();
    bool requestedQuit();
protected:

	virtual void updateArray(float);
	virtual void renderArray();

    std::vector<std::unique_ptr<GameObject>> objectArray;
    bool hasRequestedDelete;
    bool hasRequestedQuit;
};

#endif // STATE_H
