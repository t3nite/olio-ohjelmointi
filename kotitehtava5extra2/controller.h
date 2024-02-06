#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "view.h"
#include "button.h"
class Controller
{
private:
    View *objectView;
    Button *objectButton;
public:
    Controller(View *parameterView,
               Button *parameterButton);
    void listenMessages();
};

#endif // CONTROLLER_H
