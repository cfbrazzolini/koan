#include "Alien.h"

int Alien::alienCount = 0;

Alien::Alien(float x,float y,int nMinions) : sp("img/alien.png"),exploded(false){

	int i;
    float angle;
	Point click;

    hp = ALIEN_HP;
    alienCount++;
    rotation = 0;
    alienState = RESTING;
    //sp.setScale(0.5);

    box.setX(x - sp.getWidth()/2);
	box.setY(y - sp.getHeight()/2);
	box.setW(sp.getWidth());
	box.setH(sp.getHeight());



	for(i=0;i<nMinions;i++){
		angle = CustomMath::degToRad(i * 360/nMinions);
		minionArray.emplace_back(this,angle);
	}
}

void Alien::update(float dt){

	auto& input = InputManager::getInstance();
	Point pos,click;
	int i,closest = 0;
    float distance = std::numeric_limits<float>::max();

	rotation -= 3;



	if(alienState == RESTING){
		shootCooldown.update(dt);

		if(shootCooldown.getTime() >= ALIEN_SHOOT_COOLDOWN){
			if(Penguins::player != nullptr){
				taskQueue.push(Penguins::player->box.getCenter());
			}

			alienState = MOVING;
		}
	}
	else if(alienState == MOVING){

		if(!taskQueue.empty()){
			pos = taskQueue.front();

			if(box.getCenter().computeDistance(pos) < 5){

				taskQueue.pop();

				if(Penguins::player != nullptr){

                    click.setX(Penguins::player->box.getCenter().getX());
                    click.setY(Penguins::player->box.getCenter().getY());
                    
					for(i=0;i<minionArray.size();i++){
			            if(distance > minionArray[i].box.getCenter().computeDistance(click)){
			                distance = minionArray[i].box.getCenter().computeDistance(click);
			                closest = i;
			            }
			        }

	        		minionArray[closest].shoot(click.getX(),click.getY());
        		}

        		shootCooldown.restart();
        		alienState = RESTING;


			}else{

				speed = pos.sub(box.getCenter());
				speed = speed.vectorNormalize().vectorXScalar(ALIEN_SPEED*dt);

				box.sumPoint(speed);
			}
		}
	}

	for(i=0;i<minionArray.size();i++){
        minionArray[i].update(dt);
	}

}


void Alien::render(){
	int i;

	sp.render(box.getX() - Camera::pos.getX(),box.getY() - Camera::pos.getY(),rotation);
	for(i=0;i<minionArray.size();i++){
		minionArray[i].render();
	}
}

bool Alien::isDead(){
	return hp <= 0;
}

Alien::~Alien(){
	alienCount--;
}

void Alien::notifyCollision(GameObject& other){

	if(other.is("Bullet") && ((Bullet&)other).getShooter() == "Penguins"){
		hp -= 10;
	}

	if(!exploded && hp <= 0){
		exploded = true;
		Sound sound("audio/boom.wav");
		Sprite explosion("img/aliendeath.png",ALIEN_DEATH_FRAME_COUNT,ALIEN_DEATH_FRAME_TIME);
		Game::getCurrentState().addObject(new StillAnimation(box.getCenter().getX(),box.getCenter().getY(),rotation,explosion,ALIEN_DEATH_TIME_LIMIT,ALIEN_DEATH_ENDS,sound));
	}

}

bool Alien::is(const std::string& type){
	return type == "Alien";
}
