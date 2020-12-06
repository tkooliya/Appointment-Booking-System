//time.cpp to implement your class
#include "time.hpp"
#include <stdlib.h>
#include <iostream>
#include <iomanip>
using namespace std;

int TimeRange::get_beginHour(){

  return beginHour;

}

int TimeRange::get_beginMinute(){

  return beginMinute;

}

int TimeRange::get_endHour(){

  return endHour;

}

int TimeRange::get_endMinute(){

  return endMinute;

}

//Sets the timerange for an appointment
void TimeRange::set_Time(int beginH, int beginM, int endH, int endM){
  beginHour = beginH;
  beginMinute = beginM;
  endHour = endH;
  endMinute = endM;
}

//Constructor function (This one will be used the most)
TimeRange::TimeRange(int beginH, int beginM, int endH, int endM){
  beginHour = beginH;
  beginMinute = beginM;
  endHour = endH;
  endMinute = endM;
}

//Constructor function (default end time is 30 minutes after start time)
//Will most likely never be used
TimeRange::TimeRange(int beginH, int beginM){
  beginHour = beginH;
  beginMinute = beginM;

  if (beginM == 30){       //Making sure hours increments if mins starts at 30
    endMinute = 0;
    endHour = beginH + 1;
  }
  else if (beginM == 0){
    endMinute = 30;
    endHour = beginH;
  }
  else{                 //Input is invalid is minutes isn't either 0 or 30
    cout<<"Invalid input for start minute\n";
    exit(1);
  }
  
}

//Constructor Function (no timerange has been set)
TimeRange::TimeRange(){
  //Do nothing
}


bool TimeRange::isValid(int beginHour, int beginMinute, int endHour, int endMinute){

    bool Valid_time {false}; // Local variable to help return a true or false as to whther or not the time slot is valid
    
    if (beginHour <= 24 && beginHour >= 0){
        
        if (endHour < 24 && endHour > beginHour) // Tests for general conditions (e.g. start time != end time, must be within a day (<24 hours and >0 hours)
            
            if (beginMinute == 30 || beginMinute == 00)
                
                if (endMinute == 30 || endMinute == 00)
                  Valid_time = true;
        
                
                
                else {
                    cout << "not a possible option";
                    Valid_time = false;
                    exit(1);

                }
                
                
            else {
                cout << "not a possible option";
                Valid_time = false; 
                exit(1);
            }

        else if (endHour == 24 && endHour > beginHour){
            
            if (endMinute != 30)
              Valid_time = true;

            else {
                
                cout << "not a possible option";
                Valid_time = false; 
                exit(1);             
            }
        }

        else if (endHour <= 24 && endHour == beginHour) {//Tests the codition if hour is same (e.g. booking only for 30 mins with hour same)
          
          if (beginMinute != endMinute){  
            
            if (beginMinute == 00){
              
              if (endMinute == 30)
                Valid_time = true;

            }

            else {
                cout << "not a possible option"; 
                Valid_time = false;
                exit(1);

            }
          
          }
          
          else {
              cout << "not a possible option";
              Valid_time = false;
              exit(1);
          }
          
        
        }
          
        else {
            cout << "not a possible option";
            Valid_time = false;
            exit(1);
        
        }

      
      
    } 
    
    else {
        cout << "not a possible option";
        Valid_time = false;
        exit(1);
    
    }
        
      
  return Valid_time;
}


void TimeRange::output(int beginHour, int beginMinute, int endHour, int endMinute){

  cout << "your appointment time range is " << beginHour << ":" << setfill('0') << setw(2) << beginMinute << " - " << endHour << ":" << setfill('0') << setw(2) << endMinute << endl;
}

