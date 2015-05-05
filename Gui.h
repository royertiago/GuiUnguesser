#ifndef GUI_H
#define GUI_H

#include "Renderer.h"
#include "Button.h"
#include <iostream>
#include <ProjGaia/Tools/Coord.h>
#include <list>
#include <ProjGaia/Graphics/Camera.h>
#include <ProjGaia/Tools/MouseEvent.h>
#include <ProjGaia/Tools/Listener.h>


#include <mutex>
#include <thread>
#include <chrono>
#include <SFML/Graphics/Text.hpp>

class Gui: public pg::Listener<pg::MouseEvent>
{
	public:

		Gui();
		virtual ~Gui();
		double ask ( std::string question );

		void notify ( pg::MouseEvent e );


	protected:

		std::list<Button*> buttons;


		sf::Text* text;

		pg::Renderer* renderer;
		float answer;

	private:


		std::mutex* signal=new std::mutex();
	    bool ready = false;
};

#endif // GUI_H
