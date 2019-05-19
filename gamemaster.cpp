#include "graphics.hpp"
#include "gamemaster.hpp"
#include "statictextbox.hpp"
#include "box.hpp"
#include <iostream>
#include <string>

void GameMaster::game(int x, int y, Box* pbox){
    if(!_gameover){
        char sign;
        if(pbox->get_id()=='-'){ //ha sikeres lepes tortent
            if(_x_moves_next){
                pbox->set_id('x');
                sign = 'x';
                _textbox->set_text("Next player: O");
                _x_moves_next = false;
            }else{
                pbox->set_id('o');
                sign = 'o';
                _textbox->set_text("Next player: X");
                _x_moves_next = true;
            }

            ///vizszintes vizsgalat

            int s_count = 0;
            for(int i= -4; i<=4; i++){
                if(x+i>=0 && x+i<=14){
                    if(boxes[y][x+i] && boxes[y][x+i]->get_id() == sign){
                        s_count++;
                        if(s_count == 5){
                            _gameover = true;
                        }
                    }else{
                        s_count = 0;
                    }
                //cout<<y<<" "<<x+i<<" "<<boxes[y][x+i]->get_id()<<" "<<sign<<" s_count: "<<s_count<<endl;
                }
            }
            //cout<<endl;

            ///fuggoleges vizsgalat

            s_count = 0;
            for(int i= -4; i<=4; i++){
                if(y+i>=0 && y+i<=14){
                    if(boxes[y+i][x] && boxes[y+i][x]->get_id() == sign){
                        s_count++;
                        if(s_count == 5){
                            _gameover = true;
                        }
                    }else{
                        s_count = 0;
                    }
                //cout<<y+i<<" "<<x<<" "<<boxes[y+i][x]->get_id()<<" "<<sign<<" s_count: "<<s_count<<endl;
                }
            }
            //cout<<endl;

            ///jobbra-le atlos vizsgalat

            s_count = 0;
            for(int i= -4; i<=4; i++){
                if(x+i>=0 && x+i<=14 && y+i>=0 && y+i<=14){
                    if(boxes[y+i][x+i] && boxes[y+i][x+i]->get_id() == sign){
                        s_count++;
                        if(s_count == 5){
                            _gameover = true;
                        }
                    }else{
                        s_count = 0;
                    }
                    //cout<<y+i<<" "<<x+i<<" "<<boxes[y+i][x+i]->get_id()<<" "<<sign<<" s_count: "<<s_count<<endl;
                }
            }
            //cout<<endl;

            ///balra-le atlos vizsgalat

            s_count = 0;
            for(int i= -4; i<=4; i++){
                if(x-i>=0 && x-i<=14 && y+i>=0 && y+i<=14){
                    if(boxes[y+i][x-i] && boxes[y+i][x-i]->get_id() == sign){
                        s_count++;
                        if(s_count == 5){
                            _gameover = true;
                        }
                    }else{
                        s_count = 0;
                    }
                    //cout<<y+i<<" "<<x-i<<" "<<boxes[y+i][x-i]->get_id()<<" "<<sign<<" s_count: "<<s_count<<endl;
                }
            }
            //cout<<endl;

            ///nyertes

            if(_gameover && _x_moves_next){
                _textbox->set_text("The winner is: O");
            }else if(_gameover && !_x_moves_next){
                _textbox->set_text("The winner is: X");
            }


            ///dontetlen vizsgalat

            s_count = 0;
            for(int i=0; i<15; i++){
                for(int j=0; j<15; j++){
                    if(boxes[i][j]->get_id()!='-'){
                        s_count++;
                    };
                }
            }
            if(s_count == 15*15 && !_gameover){
                _gameover = true;
                _textbox->set_text("It's a tie.");
            }
            /*
            for(int i=0; i<15; i++){
                for(int j=0; j<15; j++){
                    cout<< boxes[i][j]->get_id()<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
            */
        }

    }

}



GameMaster::GameMaster(int gx, int gy):Application(gx, gy){
    _textbox = new StaticTextBox(this, 25, 25, 250, 25, "The first player to move: X");
    for(int i=0; i<15; i++){
        for(int j=0; j<15; j++){
            boxes[i][j] = new Box(this,25+40*j,75+40*i,40,40,'-', [j,i,this](Box* pbox){
                game(j, i, pbox);
            });
        }
    }
    /* dontetlen tesztelesehez (az osszes box-ot o-ra allitva es az elsot uresre...
    boxes[0][0] = new Box(this,25+40*0,75+40*0,40,40,'-', [this](Box* pbox){
                game(0, 0, pbox);
            });
    */
}
