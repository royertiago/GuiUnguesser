#include "Gui.h"
#include "Constants.h"
#include "DrawableTypeBox.h"
using namespace pg;
Gui::Gui(){

    prompt=Constants::createOkButton();
    text=Constants::createQuestionText();
    buttons= Constants::createButtons();

    typebox= new DrawableTypeBox(Constants::arial,Coord(200,350));



	renderer = new Renderer ( "Janela Fofinha", new Camera(), Coord ( 800, 600 ), Coord ( 800, 600 ) );
	renderer->beginAssync();

	renderer->MouseReader::addListener ( this );
	renderer->KeyBoardReader::addListener(this);

	renderer->Observer<char>::addListener(typebox);
}

void Gui::promptMessage(std::string phrase){
    stage=PROMPT;
    ready=false;

	text->setString(phrase);
    renderer->debugDraw.push_back(text);


    renderer->addDrawable ( prompt);

    ///waiting for answer
	waitReady();

	///deleting images

    renderer->removeDrawable ( prompt );

	renderer->debugDraw.remove(text);

}
Gui::~Gui()
{
    delete(text);

}
void Gui::notify ( MouseEvent e ){
    if(e.click==e.LEFT_DOWN){
        switch (stage)
        {
            case PROMPT :{
                 HitBox* hb=prompt->getHitBox();
                    if(hb->pointBelongsTo(e.coord)){
                        answer=prompt->getAnswer();
                        signal->lock();
                        ready=true;
                        signal->unlock();
                    }
                break;
                }
            case ASK :{
                for(auto button: buttons){
                    HitBox* hb=button->getHitBox();
                    if(hb->pointBelongsTo(e.coord)){
                        answer=button->getAnswer();
                        signal->lock();
                        ready=true;
                        signal->unlock();
                    }
                }
                break;
            }
            default:
                break;
        }
    }
}
void Gui::notify(pg::KeyBoardEvent e){
    if(e.type==e.DOWN){
        if(stage==TYPE_TEXT){
            if(sf::Keyboard::Return==e.key){
                ready=true;
            }
        }

    }
}


std::string Gui::typeMessage(std::string phrase){

    ready=false;
    stage=TYPE_TEXT;
    typebox->activate();
    text->setString(phrase);
    renderer->debugDraw.push_back(text);

    renderer->addDrawable(typebox);

    waitReady();

    renderer->removeDrawable(typebox);
    renderer->debugDraw.remove(text);



    return typebox->getText();

}
void Gui::waitReady(){
  bool cond = ready;
	while ( !cond ) {
		if ( signal->try_lock() ) {
			cond = ready;
			signal->unlock();
		} else {
			std::this_thread::sleep_for ( std::chrono::milliseconds ( 1 ) );
		}
	}

}


double Gui::ask ( std::string phrase )
{
    stage=ASK;
    ready=false;

	text->setString(phrase);
    renderer->debugDraw.push_back(text);

	for ( auto x : buttons ) {
		renderer->addDrawable ( x );
	}

    ///waiting for answer
	waitReady();

	///deleting images

	renderer->debugDraw.remove(text);

	return answer;

}

