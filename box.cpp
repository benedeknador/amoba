#include "box.hpp"
#include "graphics.hpp"
#include <string>
#include <iostream>
#include <cmath>

using namespace genv;
using namespace std;

Box::Box(Application * parent, int x, int y, int sx, int sy, char id, string text, function<void(Box*)> f):Widget(parent,x,y,sx,sy)
{
    _parent->registerWidget(this);
    _text = text;
    _id = id;
    _f = f;
}


void Box::unselect(){
     if(_focused){
        _focused = false;
     }
};

char Box::get_id(){
    return _id;
}

void Box::set_id(char c){
    _id = c;
}


void Box::draw()
{
        ///ures box

        gout << move_to(_x, _y)     << color(200,200,200) << box(_size_x, _size_y);
        gout << move_to(_x+1, _y+1) << color(100,100,100) << box(_size_x-2, _size_y-2);
        gout << move_to(_x+2, _y+2) << color(200,200,200) << box(_size_x-4, _size_y-4);

        ///X kirajzolasa

        if(_id == 'x'){
            gout << color(255,75,100);
            for(size_t i = 0; i<3; i++){
                gout << move_to(_x+7+i, _y+8)  << line_to(_x+_size_x-9+i, _y+_size_y-8);
                gout << move_to(_x+_size_x-9+i, _y+8) << line_to(_x+7+i, _y+_size_y-8);
            }
        }

        ///O kirajzolasa

        else if(_id == 'o'){
            gout << color(100,75,255);
            for(int i=_x-_size_x; i<_x+_size_x; i++){
               for(int j=_y-_size_y; j<_y+_size_y; j++){
                    double diff = sqrt(pow(_x - i, 2) + pow(_y - j, 2));
                    if(diff < _size_x/2 - 6 &&  diff > _size_x/2 - 9){
                            gout << move_to(i+_size_x/2, j+_size_y/2) << dot;
                    }
                }
            }
        }

        ///Restart gomb kirajzolasa

        if(_id == 'r'){
            gout  << move_to(_x+3+(_size_x-4-gout.twidth(_text))/2, _y+2+gout.cascent()) << color(100,100,100) << text(_text);
        }
}
void Box::handle(event ev){
    if(ev.button == btn_left){
        _f(this);
    }
}
