#include <unistd.h>
#include <cstdio>
#include <iostream>

#include "ev3dev.h"

using namespace ev3dev;

class good_crain
{
    private:
         int abc; //tmp_variable
         int kfc; //tmp_variable
        
         float dst; //tmp_variable
         motor a = {OUTPUT_B};
         motor b = {OUTPUT_C}; 
         motor c = {OUTPUT_A}; //grab_motor

         ultrasonic_sensor p = {INPUT_1}; //ultrasonic_sensor
    
    public:
        good_crain(int Aa, int Bb, int Cc, const char* Zz){
        a.set_position(Aa); //set start position as 0
        b.set_position(Bb);
        c.set_position(Cc);
        a.set_stop_action(Zz); // set stop type
        c.set_stop_action(Zz);
        b.set_stop_action(Zz);
        }
        
        void Grab(); // Grab
        void Lost(); // put down the thing
        void ToGo(); // going down
        void ToUp(); // going up
        void Toend(); // go to finish line
        void Tostart(); // go to start line
        void search(); //search the thing and get it
};

void good_crain::Grab(){
                c.set_position(0);
                c.set_speed_sp(600);
                abc = c.position();
                c.set_position_sp(-70);
                c.run_to_abs_pos();
                c.stop();
        }
void good_crain::Lost(){
                c.set_speed_sp(600);
                c.set_position_sp(70);
                kfc = c.position();
                c.set_position_sp(abc-kfc); //grab stronger
                c.run_to_abs_pos();
                c.run_to_rel_pos();
        }

void good_crain::ToGo(){
            while(a.position()<170){
              a.set_speed_sp(400);
              a.set_position_sp(12);
              a.run_to_rel_pos();
    }
}

void good_crain::ToUp(){
             while(a.position()>0){
              a.set_speed_sp(600);
              a.set_position_sp(-12);
              a.run_to_rel_pos();
              a.stop();
    }
}

void good_crain::Toend(){
    while(b.position()<650){
        b.set_speed_sp(900);
        b.set_position_sp(12);
        b.run_to_rel_pos();
        b.stop();
    }
}

void good_crain::Tostart(){
    while(b.position()>0){
        b.set_speed_sp(1000);
        b.set_position_sp(-12);
        b.run_to_rel_pos();
    }
}

void good_crain::search(){
    sleep(1);
    abc = p.distance_centimeters(); //set_default height
    while(b.position()<650){
        std::cout<<p.distance_centimeters()<<std::endl;
        b.set_speed_sp(200);
        b.set_position_sp(15);
        b.run_to_rel_pos();
    
        if(p.distance_centimeters()<= (abc- 1.2)){//if someting detected,
            b.stop();
            sleep(1);
            b.set_speed_sp(100);
            b.set_position_sp(-60);
            b.run_to_rel_pos();
            sleep(1);
            ToGo();
            sleep(0.5);
            Grab();
            sleep(0.5);
            ToUp();
            
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
        good_crain Crain(0,0,0,"hold");
        sleep(1);
        Crain.search();
        Crain.search();
        Crain.search();
        Crain.search();
        Crain.search();
        Crain.Tostart(); // rearrange
}