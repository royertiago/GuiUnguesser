#ifndef GUI_H
#define GUI_H

#include "Renderer.h"
#include "Button.h"
#include "DrawableTypeBox.h"

#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
#include <list>

#include <ProjGaia/Graphics/Camera.h>
#include <ProjGaia/Tools/MouseEvent.h>
#include <ProjGaia/Tools/Listener.h>
#include <ProjGaia/Tools/Coord.h>
#include <SFML/Graphics/Text.hpp>

class Gui: public pg::Listener<pg::MouseEvent>,public pg::Listener<pg::KeyBoardEvent>
{
	public:
        enum Stage{
            PROMPT,ASK,TYPE_TEXT
        };

		Gui();
		virtual ~Gui();


		void notify ( pg::MouseEvent e );
		void notify(  pg::KeyBoardEvent e);

		double ask ( std::string question );
		void promptMessage(std::string text);
		std::string typeMessage(std::string phrase);

		void nothing();

	protected:

		std::list<Button*> buttons;
		Button* prompt;
		Stage stage;
		DrawableTypeBox* typebox;

		sf::Text* text;
		pg::Renderer* renderer;

		float answer;
        void waitReady();

	private:


		std::mutex* signal=new std::mutex();
	    bool ready = false;
};

#endif // GUI_H
