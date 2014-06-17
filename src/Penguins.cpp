#include "Penguins.h"

Penguins* Penguins::player = nullptr;

Penguins::Penguins(float x, float y) : 	bodySp("img/penguindad.png"),
										cannonSp("img/cubngun.png"),
										linearSpeed(0),
										cannonAngle(0),
										hp(50),
										exploded(false)
{

	rotation = 0;
	box.setX(x - bodySp.getWidth()/2);
	box.setY(y - bodySp.getHeight()/2);
	box.setW(bodySp.getWidth());
	box.setH(bodySp.getHeight());

	player = this;
}

Penguins::~Penguins(){
	player = nullptr;
}

void Penguins::update(float dt){

	auto& input = InputManager::getInstance();
	Point click;


    click.setX((float)input.getMouseX() + Camera::pos.getX());
    click.setY((float)input.getMouseY() + Camera::pos.getY());

    cannonAngle = box.getCenter().computeInclination(click);

 	if(timer.getTime() > 0 && timer.getTime() < PENGUINS_SHOOT_COOLDOWN){
        timer.update(dt);
        if(timer.getTime() >= PENGUINS_SHOOT_COOLDOWN){
            timer.restart();
        }
    }

    if(timer.getTime() == 0 && input.mousePress(SDL_BUTTON_LEFT)){
        shoot();
        timer.update(dt);
    }


	if(input.isKeyDown(W_KEY)){
		linearSpeed += ACCELARATION * dt;
	}
	else if(input.isKeyDown(S_KEY)){
		linearSpeed -= ACCELARATION * dt;
	}else{
		linearSpeed = linearSpeed*0.99;
	}


	if(input.isKeyDown(A_KEY)){
		rotation += ROTATION_ANGLE;
	}

	if(input.isKeyDown(D_KEY)){
		rotation -= ROTATION_ANGLE;
	}

	if(input.isKeyDown(Z_KEY)){
       linearSpeed = 0;
    }

    speed.setX(linearSpeed * cos(CustomMath::degToRad(rotation)));
    speed.setY(linearSpeed * sin(CustomMath::degToRad(rotation)));

    box.sumPoint(speed.vectorXScalar(dt));
}

void Penguins::render(){

	bodySp.render(box.getX() - Camera::pos.getX(),box.getY() - Camera::pos.getY(),rotation);
	cannonSp.render(box.getCenter().getX() - cannonSp.getWidth()/2 - Camera::pos.getX(),box.getCenter().getY() - cannonSp.getHeight()/2 - Camera::pos.getY(),CustomMath::radToDeg(cannonAngle));
}

bool Penguins::isDead(){
	return hp <= 0;
}

void Penguins::shoot(){
    int radius = 60;
	Point bullet_origin(box.getCenter().getX() + radius*cos(cannonAngle),box.getCenter().getY() + radius*sin(cannonAngle));
    Game::getInstance().getCurrentState().addObject(new Bullet(bullet_origin.getX(),bullet_origin.getY(),cannonAngle,PENGUINS_BULLET_SPEED,PENGUINS_BULLET_RANGE,"img/penguinshot.png",PENGUINS_BULLET_FRAME_COUNT,PENGUINS_BULLET_FRAME_TIME,"Penguins"));
}


void Penguins::notifyCollision(GameObject& other){

	if(other.is("Bullet") && ((Bullet&)other).getShooter() == "Minion"){
		hp -= 10;
	}
	else if(other.is("Alien")){
		hp = 0;
	}

	if(!exploded && hp <= 0){
		exploded = true;
		Sound sound("audio/boom.wav");
		Sprite explosion("img/penguindeath.png",PENGUINS_DEATH_FRAME_COUNT,PENGUINS_DEATH_FRAME_TIME);
        Game::getInstance().getCurrentState().addObject(new StillAnimation(box.getCenter().getX(),box.getCenter().getY(),rotation,explosion,PENGUINS_DEATH_TIME_LIMIT,PENGUINS_DEATH_ENDS,sound));
	}
}

bool Penguins::is(const std::string& type){
	return type == "Penguins";
}
