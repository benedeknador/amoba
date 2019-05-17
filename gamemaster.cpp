#include "gamemaster.hpp"
#include "statictextbox.hpp"
#include "box.hpp"

void GameMaster::game(int i, int j, Box* pbox){
    if(_gameover==false){
        if(_x_moves_next == true && pbox->get_id()=='-'){        //kattintás elhelyezése
            pbox->set_id('x');
            _textbox->set_text("Next player: O");
            _x_moves_next = false;
        }else if(pbox->get_id()=='-'){
            pbox->set_id('o');
            _textbox->set_text("Next player: X");
            _x_moves_next = true;
        }else {
            //cout << "error: Az adott mezo mar nem ures" << endl;
            return;
        }
    }
}



GameMaster::GameMaster(){
    _textbox = new StaticTextBox(this, 25, 25, 250, 25, "The first player to move: X");
    for(size_t i=0; i<15; i++){
        for(size_t j=0; j<15; j++){
            boxes.push_back(new Box(this,25+40*i,75+40*j,40,40,'-', [i,j,this](Box* pbox){
                game(i, j, pbox);
            }));
        }
    }
}
