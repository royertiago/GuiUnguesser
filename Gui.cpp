#include "Gui.h"
#include "Constants.h"

using namespace pg;
Gui::Gui()
{
    text=Constants::createQuestionText();
    buttons= Constants::createButtons();

	renderer = new Renderer ( "Janela Fofinha", new Camera(), Coord ( 800, 600 ), Coord ( 800, 600 ) );
	renderer->MouseReader::addListener ( this );
	renderer->beginAssync();



}

Gui::~Gui()
{
    delete(text);

}
void Gui::notify ( MouseEvent e ){
    if(e.click==e.LEFT_DOWN){
        for(auto button: buttons){
                HitBox* hb=button->getHitBox();
                if(hb->pointBelongsTo(e.coord)){
                    answer=button->getAnswer();
                    signal->lock();
                    ready=true;
                    signal->unlock();

                }

        }

    }

}
double Gui::ask ( std::string phrase )
{
    ready=false;

	text->setString(phrase);
    renderer->debugDraw.push_back(text);

	for ( auto x : buttons ) {
		renderer->addDrawable ( x );
	}

    ///waiting for answer
	bool cond = ready;
	while ( !cond ) {
		if ( signal->try_lock() ) {
			cond = ready;
			signal->unlock();
		} else {
			std::this_thread::sleep_for ( std::chrono::milliseconds ( 1 ) );
		}
	}

	///deleting images
	for ( auto x : buttons ) {
		renderer->removeDrawable ( x );
	}
	renderer->debugDraw.remove(text);




	return answer;

}

