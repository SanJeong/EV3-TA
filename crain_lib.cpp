//2017.09.09 Jeong San 
//Programming 2 class 
//This file contains essential lines and example lines.
//Any question  E-mail 21400684@handong.edu  SMS 010-2393-5390 


#include <unistd.h>
#include <cstdio>
#include <iostream>
#include <time.h>

#include "ev3dev.h"

using namespace ev3dev;
touch_sensor q = {INPUT_2};


class Crain
{
    private:
         clock_t tNow;
         int nDiff;
         motor a = {OUTPUT_B};
         motor b = {OUTPUT_C}; 
         motor c = {OUTPUT_A};
         
         bool down = false; //This line is for example, you should erase this ex_code in your 'real code' 
         bool up = false; //This line is for example, you should erase this ex_code in your 'real code' 
         bool right = false; //This line is for example, you should erase this ex_code in your 'real code' 
         bool left = false; //This line is for example, you should erase this ex_code in your 'real code' 
         bool enter = false; //This line is for example, you should erase this ex_code in your 'real code' 
         bool escape = false; //This line is for example, you should erase this ex_code in your 'real code' 
         int speed = 100; //This line is for example, you should erase this ex_code in your 'real code' 
         

         
        
    public:
        Crain(){
        tNow = clock(); //start time
        }
        
        ~Crain(){
            clock_t nDiff = clock() - this->tNow;
            std::cout<<"Timer :"<<((float)nDiff)/CLOCKS_PER_SEC<<" Sec"<<std::endl; //report progress time (sec)
        }
        
        void example_code(); //example code //This line is for example, you should erase this ex_code in your 'real code' 
        
        ///////////////////////
        ///////////////////////
        ///////Your func///////
        ///////////////////////
        ///////////////////////
};


void Crain::example_code(){ //This function is for example, you should erase this ex_func in your 'real code' 
    
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

int main()
{     
    while(true){
        if(q.is_pressed()==true){ 
            
        Crain crain;
        crain.example_code(); //This line is for example, you should erase this ex_code in your 'real code' 
        
        ///////////////////////
        ///////////////////////
        ///////Your main///////
        ///////////////////////
        ///////////////////////
        }
    }
}