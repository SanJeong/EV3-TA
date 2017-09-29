#include <unistd.h>
#include <cstdio>
#include <iostream>

#include "ev3dev.h"

using namespace ev3dev;
        int abc;
        int kfc;
         motor a = {OUTPUT_B};
         motor b = {OUTPUT_C};
         motor c = {OUTPUT_A};

        sensor p = {INPUT_1};
        sensor q = {INPUT_2};
        int position;
        int position_sp;
         bool down = false;
         bool up = false;
         bool right = false;
         bool left = false;
         bool enter = false;
         bool escape = false;
        float distance,distance_start;
        distance = p.distance_centimeters();
        distance_start = distance;
        int tmp_position();
        bool flag = false;
        
void Grab(){
                c.set_position(0);
                c.set_speed_sp(200);
                
                abc = c.position();
                c.set_position_sp(-70);
                //std::cout<< abc << std::endl;
                //std::cout<<c.position_sp()<<std::endl;
                
                c.run_to_abs_pos();
        }
void Lost(){
                c.set_speed_sp(200);
                c.set_position_sp(70);
                //std::cout<< abc << std::endl;
                //std::cout<<c.position_sp()<<std::endl;
                kfc = c.position();
                c.set_position_sp(abc-kfc);
                c.run_to_abs_pos();
                c.run_to_rel_pos();
         
        }


void ToGo(){
              a.set_speed_sp(100);
              
              a.set_position_sp(500);
              a.run_to_abs_pos();
              
}
void ToUp(){
             
              a.set_speed_sp(100);
              a.set_position_sp(-500);
              a.run_to_rel_pos();
              

}

void Toend(){
    b.set_position(0);
    b.set_speed_sp(150);
    b.set_position_sp(-600);
    b.run_to_abs_pos();
    
}

void Tostart(){
    b.set_speed_sp(150);
    b.set_position_sp(600);
    b.run_to_rel_pos();
}

void detect_grab{
    b.set_position(0);
    b.set_speed_sp(400);
    while (b.position<600){
        b.set_position_sp(-60);
        if(distance<=5.0){
            flag = true
            sleep(1);
            ToGo();
            sleep(5);
            Grab();
            sleep(5);
            ToUp();
        }
        
    }
    
    
    
    
}
int main ()
{     
 a.set_position(0);
 b.set_position(0);
 c.set_position(0);
 a.set_stop_action("hold");
 
 
        
        
         while(escape == 0)
         
         {
                 
                 escape = button::back.pressed();
                 
                 
                 
                 
            
               
               
               
         }
        c.stop();
        a.stop();
        b.stop();

}