#include <unistd.h>
#include <cstdio>
#include <iostream>

#include "ev3dev.h"

using namespace ev3dev;

int main ()
{       
    
         motor a = {OUTPUT_B};
         motor b = {OUTPUT_C};
         motor c = {OUTPUT_A};
        
         bool down = false;
         bool up = false;
         bool right = false;
         bool left = false;
         bool enter = false;
         bool escape = false;

        int speed = 100;

         while(escape == 0)
         {
                 down = button::down.pressed();
                 up = button::up.pressed();
                 right = button::right.pressed();
                 left = button::left.pressed();
                 escape = button::back.pressed();
                 enter = button::enter.pressed();
                 
                 if(up)
                 {
                         a.set_speed_sp(-speed);
                         a.run_forever();
                 }

                 if(down)
                 {
                         a.set_speed_sp(speed);
                         a.run_forever();
                }

                if(left)
                {
                        b.set_speed_sp(speed);
                        b.run_forever();
                }

                if(right)
                {
                        b.set_speed_sp(-speed);
                        b.run_forever();
                }
                
                if(enter){
                    c.set_position(0);
                    c.set_speed_sp(200);
                    c.set_position_sp(-50);
                    c.run_to_abs_pos();
                    sleep(2);
                    c.set_position_sp(50);
                    c.run_to_rel_pos();
                    

                }
                
                if(!(up | down | right | left | enter))
                {
                        a.set_speed_sp(0);
                        a.run_forever();
                        b.set_speed_sp(0);
                        b.run_forever();
                }
        
                
         }
        c.stop();
        a.stop();
        b.stop();
}