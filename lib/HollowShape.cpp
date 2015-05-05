#include "HollowShape.h"
#include <ProjGaia/Tools/Angle.h>

#include <SFML/Graphics/RenderTarget.hpp>
using namespace sf;
using namespace pg;
HollowShape::HollowShape ( pg::Polygon poly, sf::Color color, int width ) :
	color ( color ), width ( width )
{
	shapes = std::list<sf::Shape*>();
	std::list<LineSeg> lines = poly.getLines();
for ( auto x: lines ) {
		shapes.push_back ( createLine ( x ) );
		shapes.push_back ( createCircle ( x.getStart() ) );

	}

}

HollowShape::~HollowShape()
{
	//dtor
}
Shape* HollowShape::createCircle ( Coord c ) {
	sf::Shape *novo = new CircleShape ( width / 2 );
	novo->setFillColor ( color );
	novo->setOrigin ( width / 2, width / 2 );
	novo->setPosition ( c.x, c.y );
	return novo;
}
Shape* HollowShape::createLine ( LineSeg line ) {

	Shape* shape = new RectangleShape ( Vector2f ( line.getSpeed(), width / 2 ) );
	shape->setFillColor ( color );
	shape->setPosition ( line.getStart().x, line.getStart().y );
	float ang = pg::Angle::radianToDegree ( ( line.getAngle() ) );
	shape->setRotation ( ang );
	return shape;



}

void HollowShape::update(void*) {
	//  shape->setPosition(position.x,position.y);


}
void HollowShape::draw ( sf::RenderTarget& rt, sf::RenderStates rs ) const {
for ( auto x: shapes ) {
		rt.draw ( *x, rs );
	}

}
