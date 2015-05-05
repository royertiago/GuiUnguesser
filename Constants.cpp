#include "Constants.h"
#include <SFML/Graphics/Font.hpp>
#include <ProjGaia/Tools/Coord.h>
#include <ProjGaia/Tools/SquareHitBox.h>
#include "TextBox.h"
using namespace pg;
using namespace std;

bool Constants::loaded = false;
sf::Font* Constants::arial = 0;

static sf::Font* loadFont ( string file )
{
	sf::Font* font = new sf::Font();
	if ( !font->loadFromFile ( file ) ) {
		std::cout << "Cannot Load " << file << " \n Segmentation fault imminent" << std::endl;
		return 0;///Segmentation Fault inc.
	};
	return font;
}



sf::Text* Constants::createQuestionText()
{
	if ( !loaded ) {
		arial = loadFont ( FONT_FILE );
		loaded = true;
	}

	sf::Text* novo = new sf::Text();
	novo->setFont ( *arial );
	novo->setString ( "Frase default" );
	novo->setCharacterSize ( 24 );
	novo->setColor ( sf::Color::White );
	novo->setPosition(300,50);


	return novo;
}
static std::list<Coord> getCoords ( Coord pos, Coord dimension )
{
	std::list<Coord> lista = std::list<Coord>();
	//making the square
	Coord bottomLeft = pos;
	Coord bottomRight = Coord ( pos.x + dimension.x, pos.y );
	Coord topLeft = Coord ( pos.x, pos.y + dimension.y );
	Coord topRight = dimension + pos;

	lista.push_back ( bottomLeft );
	lista.push_back ( bottomRight );
	lista.push_back ( topRight );
	lista.push_back ( topLeft );

	return lista;

}

static Button* createButton ( Coord pos, Coord dim, sf::Color cor, string text, sf::Font* font, double answer,sf::Color fontColor=sf::Color::White )
{
	HitBox* hb = new pg::SquareHitBox ( dim.x, dim.y, pos );
	pg::Sprite* sprite = new TextBox ( dim, pos, cor, font, text,fontColor );

	return new Button ( hb, sprite, answer );
}

std::list<Button*> Constants::createButtons()
{
	if ( !loaded ) {
		arial = loadFont ( FONT_FILE );
		loaded = true;
	}



	Button* yes = createButton   ( Coord ( POS_X, POS_Y ), Coord ( TAM_X, TAM_Y ), sf::Color::Green, TEXT_YES, arial, 1 );

	Button* no = createButton    ( Coord ( POS_X + VAR_X, POS_Y ), Coord ( TAM_X, TAM_Y ), sf::Color::Red, TEXT_NO, arial, -1 );

	Button* maybe = createButton ( Coord ( POS_X , POS_Y +VAR_Y), Coord ( TAM_X, TAM_Y ), sf::Color::Blue, TEXT_MAYBE, arial, 0.5 );

	Button* unlikely = createButton ( Coord ( POS_X + VAR_X, POS_Y +VAR_Y ), Coord ( TAM_X+20, TAM_Y ), sf::Color::Yellow, TEXT_UNLIKELY, arial, -0.5,sf::Color::Black );

	Button* idk = createButton ( Coord ( POS_X + 2 * VAR_X, POS_Y+VAR_Y ), Coord ( TAM_X+70, TAM_Y ), sf::Color(155,155,155), TEXT_IDK, arial, 0 );

	std::list<Button*> lista={yes,no,maybe,unlikely,idk};



	return lista;
}
