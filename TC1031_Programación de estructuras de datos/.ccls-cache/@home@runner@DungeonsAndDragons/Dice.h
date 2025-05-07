#pragma once
#include <iostream>
#include <cstdio>     
#include <cstdlib>
#include <ctime>
using namespace std;
#pragma once

class Dice{
    int faces; 

    public: 
        Dice(){
          this->faces = 6; 
        }
        Dice(int faces){
          this->faces = faces;
        }
        ~Dice(){};  
        int getFaces(){
          return faces; 
        } 
        void setFaces(int faces){
          this->faces = faces;
        }
        int roll(){
          srand(time(0));
          int number = rand() % (faces - 1 + 1) + 1; 
          return number; 
        }
};