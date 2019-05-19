#ifndef STATICTEXTBOX_HPP_INCLUDED
#define STATICTEXTBOX_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include <string>
using namespace std;

class StaticTextBox : public Widget {
protected:
    string t;
    bool kirajzolt = false;
public:
    StaticTextBox(Application * parent, int x, int y, int sx, int sy, string text);
    virtual void unselect();
    virtual void draw();
    virtual void handle(genv::event ev);
    virtual string get_text();
    virtual void set_text(string text);
};


#endif // STATICTEXTBOX_HPP_INCLUDED
