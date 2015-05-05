#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <SFML/Graphics/Text.hpp>
#include <list>
#include "Button.h"

#define TEXT_YES "Yes"
#define TEXT_NO "No"
#define TEXT_MAYBE "Maybe"
#define TEXT_UNLIKELY "Unlikely"
#define TEXT_IDK "I don't know"
#define FONT_FILE "Font/arial.ttf"

#define POS_X 200
#define VAR_X 150
#define VAR_Y 75

#define POS_Y 200
#define TAM_X 100
#define TAM_Y 50

class Constants
{
    public:
        static const int BUTTON_WIDTH=300;
        static const int BUTTON_HEIGHT=300;
        static sf::Text* createQuestionText();
        static std::list<Button*> createButtons();

    protected:
        static sf::Font* arial;
         static bool loaded;

    private:
};

#endif // CONSTANTS_H
