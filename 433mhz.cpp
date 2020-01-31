#include "./433Utils/rc-switch/RCSwitch.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
 
int main(int argc, char *argv[]) {
    if (wiringPiSetup() == -1) return 1;
    
    RCSwitch s = RCSwitch();

    struct socket {
        int on;
        int off;
    } desk, kitchen, livingRoom;
    
    desk.on = 4215889;
    desk.off = 4215892;
    livingRoom.on = 4215121;
    livingRoom.off = 4215124;
    kitchen.off = 4212052;
    kitchen.on = 4212049;



    s.enableTransmit(0);
    switch(atoi(argv[1])){
        case 1:
            s.send(desk.on, 24);
            break;
        case 2:
            s.send(desk.off, 24);
            break;
        case 3:
            s.send(kitchen.on, 24);
            break;
        case 4:
            s.send(kitchen.off, 24);
            break;
        case 5:
            s.send(livingRoom.on, 24);
            break;
        case 6:
            s.send(livingRoom.off, 24);
            break;
        case 7:
            s.send(desk.off, 24);
            s.send(livingRoom.off, 24);
            s.send(kitchen.off, 24);
            break;
        case 8:
            s.send(kitchen.on, 24);
            s.send(livingRoom.on, 24);
            s.send(desk.on, 24);
            break;
        default:
            std::cout << "Befehl nicht verstanden!\n";
            std::cout << "\t1: Schreibtischlicht an\n";
            std::cout << "\t2: Schreibtischlicht aus\n";
            std::cout << "\t3: Küche an\n";
            std::cout << "\t4: Küche aus\n";
            std::cout << "\t5: Sideboard an\n";
            std::cout << "\t6: Sideboard aus\n";
            std::cout << "\t7: Alle aus\n";
            std::cout << "\t8: Alle an\n";
            break;
    }
}
