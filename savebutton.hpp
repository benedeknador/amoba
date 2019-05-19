#ifndef SAVEBUTTON_HPP_INCLUDED
#define SAVEBUTTON_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include <string>
using namespace std;

class Button : public Widget {
protected:
    bool _focused = false;
    string t;
    string _id;
public:
    Button(Application * parent, int x, int y, int sx, int sy, string text, string id);
    virtual void unselect();
    virtual void draw();
    virtual void handle(genv::event ev);
};


#endif // SAVEBUTTON_HPP_INCLUDED
