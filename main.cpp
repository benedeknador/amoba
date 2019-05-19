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
    GameMaster app(650,700);
    app.event_loop();

    return 0;
}
