#include <unistd.h>
#include <cstdio>
#include <iostream>

#include "ev3dev.h"

using namespace ev3dev;
        int abc;
        int kfc;
        
        float dst;
         motor a = {OUTPUT_B};
         motor b = {OUTPUT_C};
         motor c = {OUTPUT_A};

         ultrasonic_sensor p = {INPUT_1};
        int position;
        int position_sp;
         bool down = false;
         bool up = false;
         bool right = false;
         bool left = false;
         bool enter = false;
         bool escape = false;   
        int tmp_position;
        bool flag = false;
        
void Grab(){
                c.set_position(0);
                c.set_speed_sp(600);
                
                abc = c.position();
                c.set_position_sp(-70);
                //std::cout<< abc << std::endl;
                //std::cout<<c.position_sp()<<std::endl;
                
                c.run_to_abs_pos();
                c.stop();
        }
void Lost(){
                c.set_speed_sp(600);
                c.set_position_sp(70);
                //std::cout<< abc << std::endl;
                //std::cout<<c.position_sp()<<std::endl;
                kfc = c.position();
                c.set_position_sp(abc-kfc);
                c.run_to_abs_pos();
                c.run_to_rel_pos();
         
        }


void ToGo(){
            while(a.position()<170){
              a.set_speed_sp(800);
              a.set_position_sp(12);
              a.run_to_rel_pos();
        
    }
}
void ToUp(){
             while(a.position()>0){
              a.set_speed_sp(800);
              a.set_position_sp(-12);
              a.run_to_rel_pos();
}
}

void Toend(){
    while(b.position()<610){
        b.set_speed_sp(100);
        b.set_position_sp(12);
        b.run_to_rel_pos();
        b.stop();
    }
    
}
void Tostart(){
    while(b.position()>0){
        b.set_speed_sp(1000);
        b.set_position_sp(-24);
        b.run_to_rel_pos();
        
    }

}

void search(){
    
    while(b.position()<610){
        std::cout<<p.distance_centimeters()<<std::endl;
        b.set_speed_sp(350);
        b.set_position_sp(15);
        b.run_to_rel_pos();
        
        if(p.distance_centimeters()<= (abc- 1.2)){
            
            b.stop();
            sleep(1);
            b.set_speed_sp(100);
            b.set_position_sp(-100);
            
            b.run_to_rel_pos();
            sleep(1);
            
            
            ToGo();
            sleep(1);
            Grab();
            sleep(0.5);
            ToUp();
            sleep(0.5);
            Toend();
            
            ToGo();
            
            Lost();
            ToUp();
            
            Tostart();
            
            break;
        }
    }
}



int main()
{     
 a.set_position(0);
 b.set_position(0);
 c.set_position(0);
 a.set_stop_action("hold");
 c.set_stop_action("hold");
 b.set_stop_action("hold");
 escape = button::back.pressed();
 
                 sleep(0.5);
                 abc = p.distance_centimeters();
                 search();
                 sleep(0.5);
                 abc = p.distance_centimeters();
                 search();
                 sleep(0.5);
                 abc = p.distance_centimeters();
                 search();
                 sleep(0.5);
                 abc = p.distance_centimeters();
                 search();
                 sleep(0.5);
                 abc = p.distance_centimeters();
                 search();
                 sleep(0.5);

}