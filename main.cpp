#include "graphics.hpp"
#include "widgets.hpp"
#include "box.hpp"
#include "application.hpp"
#include "gamemaster.hpp"
#include "statictextbox.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
using namespace genv;
using namespace std;


int main()
{
    gout.open(650,700);

    GameMaster app;
    app.event_loop();

    return 0;
}
