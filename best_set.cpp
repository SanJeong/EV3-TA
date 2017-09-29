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
         
        a.set_stop_action("hold"); // set stop type
        c.set_stop_action("hold");
        b.set_stop_action("hold");
        
        ultrasonic_sensor p = {INPUT_1};
        sensor q = {INPUT_2};

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
        std::cout<<p.distance_centimeters()<<std::endl;
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

                
			

                if(!(up | down | right | left))
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