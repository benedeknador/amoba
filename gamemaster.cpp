#include "graphics.hpp"
#include "gamemaster.hpp"
#include "statictextbox.hpp"
#include "box.hpp"
#include <iostream>
#include <string>

void GameMaster::game(int x, int y, Box* pbox){
    if(_gameover==false){
        char sign;
        if(_x_moves_next == true && pbox->get_id()=='-'){        //kattintás elhelyezése
            pbox->set_id('x');
            sign = 'x';
            _textbox->set_text("Next player: O");
            _x_moves_next = false;

        }else if(pbox->get_id()=='-'){
            pbox->set_id('o');
            sign = 'o';
            _textbox->set_text("Next player: X");
            _x_moves_next = true;
        }
        ///vizszintes vizsgalat

        int s_count = 0;
        int y_min = max(0, y-4);
        int y_max = min(14, y+4);
        for(int i= y_min; i<=y_max; i++){
            if(boxes[x][i]->get_id() == sign){
                s_count++;
                //cout << s_count;
                if(s_count == 5){
                    _gameover = true;
                }
            }else{
                s_count = 0;
            }
        }

        ///fuggoleges vizsgalat

        s_count = 0;
        int x_min = max(0, x-4);
        int x_max = min(14, x+4);
        for(int i= x_min; i<=x_max; i++){
            if(boxes[i][y]->get_id() == sign){
                s_count++;
                //cout << s_count << endl;
                if(s_count == 5){
                    _gameover = true;
                }
            }else{
                s_count = 0;
            }
        }
        /*
        ///jobbra-le atlos vizsgalat

        s_count = 0;
        int d_min = min(x_min, y_min);
        int d_max = min(x_max, y_max);
        cout<<d_max<<" "<<d_max<<endl;
        for(int i= d_min; i<=d_max; i++){
            if(boxes[i][i]->get_id() == sign){
                s_count++;
                //cout << s_count << endl;
                if(s_count == 5){
                    _gameover = true;
                }
            }else{
                s_count = 0;
            }
        }*/

    }

}



GameMaster::GameMaster(int gx, int gy):Application(gx, gy){
    _textbox = new StaticTextBox(this, 25, 25, 250, 25, "The first player to move: X");
    for(size_t i=0; i<15; i++){
        vector<Box*> temp;
        for(size_t j=0; j<15; j++){
            temp.push_back(new Box(this,25+40*j,75+40*i,40,40,'-', [i,j,this](Box* pbox){
                game(i, j, pbox);
            }));
        }
        boxes.push_back(temp);
    }

}
