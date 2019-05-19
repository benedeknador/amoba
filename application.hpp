#ifndef APPLICATION_HPP_INCLUDED
#define APPLICATION_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include <string>
#include <vector>

using namespace std;

class Widget;

class Application{
protected:
    int _focus;
    int _gx, _gy;
    int _mouse_x,_mouse_y;
    vector<Widget*> widgets;
public:
    Application(int gx, int gy);
    virtual ~Application(){};
    void registerWidget(Widget * pw);
    void event_loop();
};

#endif // APPLICATION_HPP_INCLUDED
