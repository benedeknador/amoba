#include "button.hpp"
#include "graphics.hpp"
#include <string>
#include <iostream>
using namespace genv;
using namespace std;

Button::Button(Application * parent, int x, int y, int sx, int sy, string text, string id):Widget(parent,x,y,sx,sy)
{
    t = text;
    _id = id;
    _parent->registerWidget(this);
}

void Button::unselect(){
     if(_focused){
        _focused = false;
     }
};

void Button::draw()
{
        gout << move_to(_x, _y)  << color(200,200,200) << box(_size_x, _size_y);
        if (_focused) {
            gout << color(0,75,255);
        } else {
            gout << color(100,100,100);
        }
        gout << move_to(_x+1, _y+1) << box(_size_x-2, _size_y-2);
        gout << move_to(_x+2, _y+2) << color(200,200,200) << box(_size_x-4, _size_y-4);
        gout << move_to(_x+3+(_size_x-4-gout.twidth(t))/2, _y+2+gout.cascent()) << color(0,0,0) << text(t);

}
void Button::handle(event ev){
    if(!_focused){
        _focused = true;
        if (ev.type == ev_mouse && ev.button==btn_left) {
                _parent->action(_id);
        }
    }
}
