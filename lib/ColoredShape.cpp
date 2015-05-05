#include "ColoredShape.h"
#include <list>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <ProjGaia/Tools/Polygon.h>
namespace pg{
ColoredShape::ColoredShape ( std::list<pg::Coord> coords, sf::Color color ) :
	color ( color )
{
	pg::Polygon poly ( coords );
	createShape ( poly );
	/*
	lines=poly.getLines();

	int points=coords.size();
	shape=sf::ConvexShape(points);
	int i=0;
	for(auto c: coords){
	    sf::Vector2<float> vector=sf::Vector2<float>(c.x,c.y);
	    shape.setPoint(i,vector);
	    i++;
	}
	shape.setFillColor(color);
	*/

}
ColoredShape::ColoredShape ( sf::Shape* shape ) :
	shape ( shape )
{
	this->hitbox->position.x = shape->getPosition().x;
	this->hitbox->position.y = shape->getPosition().y;

}

ColoredShape::ColoredShape() {
}

ColoredShape::ColoredShape ( pg::Polygon polygon, sf::Color color ) :
	color ( color )
{
	createShape ( polygon );

}
ColoredShape::ColoredShape ( pg::Polygon polygon, pg::Coord position, pg::Coord scale, float rotation, float height, sf::Color color )
	: DrawableSprite ( position, scale, rotation, height ), color ( color )
{
	createShape ( polygon );
}

ColoredShape::~ColoredShape()
{
	delete ( shape );
}
void ColoredShape::createShape ( pg::Polygon polygon ) {
	std::list<pg::LineSeg> lines = polygon.getLines();
	int points = lines.size();
	sf::ConvexShape* shape2 = new sf::ConvexShape ( points );
	int i = 0;
for ( auto line: lines ) {
		sf::Vector2<float> vector = sf::Vector2<float> ( line.getStart().x, line.getStart().y );
		shape2->setPoint ( i, vector );
		i++;
	}
	shape2->setFillColor ( color );
	shape = shape2;

}
void ColoredShape::update() {
	shape->setPosition ( hitbox->position.x, hitbox->position.y );


}
void ColoredShape::draw ( sf::RenderTarget& rt, sf::RenderStates rs ) const {
	rt.draw ( *shape, rs );
}

}
