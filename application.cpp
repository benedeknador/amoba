#include "application.hpp"
#include "graphics.hpp"
#include <string>
#include <fstream>
#include <iostream>

using namespace genv;

Application::Application(){
}

void Application::registerWidget(Widget * pw){
        widgets.push_back(pw);
}

void Application::event_loop() {

        gout<<move_to(0,0)<<color(140,200,90)<<box(650,700);

        for (Widget * w : widgets) {
                w->draw();
        }

        event ev;
        _focus = -1;
        gin.timer(500);
        while(gin >> ev && ev.keycode != key_escape) {
            if (ev.type == ev_mouse && ev.button==btn_left) {
                for (size_t i=0;i<widgets.size();i++) {
                    if (widgets[i]->is_selected(ev.pos_x, ev.pos_y)) {
                            _focus = i;
                    }
                }
            }
            for (size_t i=0;i<widgets.size();i++) {
                if (i!=_focus) {
                    widgets[i]->unselect();
                }
            }
            if (_focus!=-1) {
                widgets[_focus]->handle(ev);
            }
            for (Widget * w : widgets) {
                w->draw();
            }
            gout << refresh;
        }
}


