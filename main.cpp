#include <iostream>
#include "Button.h"
#include "TextBox.h"
#include "Gui.h"
#include <ProjGaia/Tools/Coord.h>
#include <SFML/Graphics/Font.hpp>
#include <ProjGaia/Graphics/Camera.h>
#include "Renderer.h"
#include <mutex>
using namespace std;

using namespace pg;
int main()
{
	//  Button novo=Button(pg::Coord(),"teste",2);

mutex a;





 Gui gui=Gui();
cout<< gui.ask("Hello world")<<endl;
cout<< gui.ask("Hello world2")<<endl;
cout<< gui.ask("Hello world3")<<endl;
cout<< gui.ask("Hello world4")<<endl;




	return 0;
}
