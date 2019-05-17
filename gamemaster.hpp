#ifndef GAMEMASTER_HPP_INCLUDED
#define GAMEMASTER_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include "statictextbox.hpp"
#include "application.hpp"
#include "box.hpp"

class GameMaster: public Application{
protected:
    StaticTextBox* _textbox;
    vector<Widget*> boxes;
    bool _x_moves_next = true;
    bool _gameover = false;
    void game(int i, int j, Box* pbox);
public:
    GameMaster();
};

#endif // GAMEMASTER_HPP_INCLUDED