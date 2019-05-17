#ifndef BOX_HPP_INCLUDED
#define BOX_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include <functional>

using namespace std;

class Box : public Widget {
protected:
    function<void(Box*)> _f;
    bool _focused = false;
    char _id;
    bool _clicked = false;
public:
    Box(Application * parent, int x, int y, int sx, int sy, char id, function<void(Box*)> f);
    virtual void unselect();
    virtual void draw();
    virtual void handle(genv::event ev);
    virtual char get_id();
    virtual void set_id(char c);
};


#endif // BOX_HPP_INCLUDED
