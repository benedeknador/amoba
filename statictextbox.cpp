#include "statictextbox.hpp"
#include "graphics.hpp"
#include <string>
using namespace genv;

StaticTextBox::StaticTextBox(Application * parent, int x, int y, int sx, int sy, std::string text):Widget(parent,x,y,sx,sy)
{
    t = text;
     _parent->registerWidget(this);
}


void StaticTextBox::unselect(){};

void StaticTextBox::draw()
{
        gout << move_to(_x, _y) << color(140,200,90) << box(_size_x, _size_y);
        gout << move_to(_x+3, _y+3+gout.cascent()) << color(255,255,255) << text(t);

}
void StaticTextBox::handle(event ev){
}

string StaticTextBox::get_text(){
    return t;
}
void StaticTextBox::set_text(string text){
    t = text;
}
