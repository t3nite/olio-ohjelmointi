#include "view.h"
#include "button.h"
#include "controller.h"
#include <iostream>

using namespace std;

char Button::readKeyboard()
{
    character = getch();
    return character;
}

void View::printCharacter(char parameterCharacter)
{
    printf("%c", parameterCharacter);
}

void Controller::listenMessages()
{
    char keyPressed='0';
    while (keyPressed!='q')
    {
        // if (kbhit()) ehtolause toteutuu, jos näppäinta painetaan
        if (kbhit())
        {
            //alla koodi, jossa oliot hoitavat merkin lukemisen ja tulostamisen, muodostetun 1:1 yhteyden
            // avulla. Eli oliot tekevät yhteistyötä. Jokaisella oliolla/luokalla oma tehtävä.
            keyPressed=objectButton->readKeyboard();
            objectView->printCharacter(keyPressed);
        }
    }
}

Controller::Controller (View *parameterView, Button *parameterButton)
{
    objectView = parameterView;
    objectButton = parameterButton;
    this->listenMessages();
}

int main()
{
    View *mainObjectView = new View;
    Button *mainObjectButton = new Button;
    Controller *mainObjectController;

    // Yhteyssuhteen 1:1 muodostaminen alla olevalla rivillä
    mainObjectController = new Controller(mainObjectView, mainObjectButton);
    // Ylläolevan olion luonti aiheuttaa muodostinfunktion suorittamisen

    delete mainObjectView;
    mainObjectView = nullptr;

    delete mainObjectButton;
    mainObjectButton = nullptr;

    delete mainObjectController;
    mainObjectController = nullptr;

    return 0;
}
