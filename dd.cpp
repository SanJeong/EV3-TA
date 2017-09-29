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
         bool down = false;
         bool up = false;
         bool right = false;
         bool left = false;
         bool enter = false;
         bool escape = false;   
         bool flag = false;


void Grab(){
                c.set_position(0);
                c.set_speed_sp(400);
                abc = c.position();
                c.set_position_sp(-70);
                c.run_to_abs_pos();
                c.stop();
        }
void Lost(){
                c.set_speed_sp(400);
                c.set_position_sp(70);
                kfc = c.position();
                c.set_position_sp(abc-kfc);
                c.run_to_abs_pos();
                c.run_to_rel_pos();
         
        }

void ToGo(){
            while(a.position()<170){
              a.set_speed_sp(300);
              a.set_position_sp(12);
              a.run_to_rel_pos();
    }
}

void ToUp(){
             while(a.position()>0){
              a.set_speed_sp(300);
              a.set_position_sp(-12);
              a.run_to_rel_pos();
    }
}

void Toend(){
    while(b.position()<640){
        b.set_speed_sp(100);
        b.set_position_sp(6);
        b.run_to_rel_pos();
        b.stop();
    }
}

void Tostart(){
    while(b.position()>0){
        b.set_speed_sp(500);
        b.set_position_sp(-12);
        b.run_to_rel_pos();
    }
}

void search(){
    sleep(1);
    while(b.position()<640){
        std::cout<<p.distance_centimeters()<<std::endl;
        b.set_speed_sp(110);
        b.set_position_sp(24);
        b.run_to_rel_pos();
    
        if(p.distance_centimeters()<= (abc- 1.2)){
            
            b.stop();
            sleep(1);
            b.set_speed_sp(100);
            b.set_position_sp(-80);
            b.run_to_rel_pos();
            sleep(1);
            ToGo();
            sleep(1);
            Grab();
            sleep(1);
            ToUp();
            sleep(1);
            Toend();
            sleep(1);
            ToGo();
            sleep(1);
            Lost();
            sleep(1);
            ToUp();
            sleep(1);
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


                 sleep(2);
                 abc = p.distance_centimeters();
                 search();
                 sleep(1);
                 abc = p.distance_centimeters();
                 search();
                 sleep(1);
                 abc = p.distance_centimeters();
                 search();
                 sleep(1);
                 abc = p.distance_centimeters();
                 search();
                 sleep(1);
                 abc = p.distance_centimeters();
                 search();
                 sleep(1);
                 Tostart();

            
}