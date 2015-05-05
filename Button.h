#ifndef BUTTON_H
#define BUTTON_H
#include "DrawableSprite.h"
#include "ColoredShape.h"
#include <ProjGaia/Tools/Coord.h>
#include <iostream>
#include <ProjGaia/Tools/HasCollison.h>




class Button: public pg::DrawableType, public pg::HasCollison
{
	public:
		Button ( pg::HitBox* hitbox, pg::Sprite* sprite, double answer ) :
			hitbox ( hitbox ), sprite ( sprite ), answer ( answer ){}
		virtual ~Button(){}

		double getAnswer() {return answer;}

		pg::HitBox* getHitBox() {return hitbox;}

		pg::Sprite* getSprite() {return sprite;}

	protected:
		pg::HitBox* hitbox;
		pg::Sprite* sprite;
		double answer;
	private:
};

#endif // BUTTON_H
