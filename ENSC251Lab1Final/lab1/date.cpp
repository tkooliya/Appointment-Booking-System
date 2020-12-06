//date.cpp to implement your class
#include "date.hpp"
#include <stdlib.h>
#include <iostream>

using namespace std;

    
    
    int Date::getMonth() { // <COME BACK> possible issue, do we need to return getter values or not?
      
      return month;
    }

    int Date::getDay(){

      return day;
    }
    
    void Date::setDate(int m, int d) { // we dont want anything to return just to set so use void type
    
      month = m;
      day = d;
    }
    
    bool Date::isValid(int month, int day){
      
      bool Valid_day{false};
      
      if (month<9 || month>12){ // checks if months are out of range
        
        Valid_day = false;
        cout << "Out of scheduling range" << endl;
        exit(1);
      }
      else if (month==9 && day<8){ // checks start date range
        
        Valid_day = false;
        cout << "Out of scheduling range" << endl;
        exit(1);
      }
      else if (month==12 && day>20){ // checks end date range
        
        Valid_day = false;
        cout << "Out of scheduling range" << endl;
        exit(1);
      }
      else if ((month == 9 || month == 11) && day <= 30 && day >= 1) // checks sept and nov ranges
      {
        cout << "Within scheduling range" << endl;
        Valid_day = true;
      }
      else if ((month == 10 || month == 12) && day <= 31 && day >= 1) // checks oct and dec ranges
      {
        cout << "Within scheduling range" << endl;
        Valid_day = true;
      }
      
      else {

        cout << "Out of scheduling range" << endl; // catch all for any other conditions not addressed that aren't within range (negatives, bigger numbers, etc.)
        Valid_day = false;
        exit(1);
      }
      
      
      return Valid_day;
        
    }
    
    bool Date::isHoliday(int month, int day, const int thanksgivingDay, const int thanksgivingMonth, const int rememberanceDay, const int rememberanceMonth)
      {
      bool Valid_holiday{false}; // to  if tcheckhe day is holiday - if it is return false validity
      
      if (month == thanksgivingMonth && day == thanksgivingDay){
        Valid_holiday = false;
        cout << "This day is a holiday" << endl;
        exit(1);
      }
      else if (month == rememberanceMonth && day == rememberanceDay){
        Valid_holiday = false;
        cout << "This day is a holiday" << endl;
        exit(1);
      }
      else 
      {
        Valid_holiday = true;
      }
      
      return Valid_holiday;
    }
    
    bool Date::isWeekend(int month, int day){
      
      bool Valid_weekend{false}; // to check if the day is a weekend - if it is return false validity
      
      if (month == 9 && (day == 12 || day == 19 || day == 26 || day == 13 || day == 20 || day == 27)){ // can list all weekends because it won't significantly impact processing time
        
        Valid_weekend = false;
        cout << "This day falls on a weekend" << endl;
        exit(1);
      }
      
      else if(month == 10 && (day == 3 || day == 10 || day == 17 || day == 24 || day == 31 || day == 4 || day == 11 || day == 18 || day == 25)){
        
        Valid_weekend = false;
        cout << "This day falls on a weekend" << endl;
        exit(1);
        
      }
      
      else if(month == 11 && (day == 1 || day == 7 || day == 14 || day == 21 || day == 28 || day == 1 || day == 8 || day == 15 || day == 22 || day == 29)){
        
        Valid_weekend = false;
        cout << "This day falls on a weekend" << endl;
        exit(1);
        
      }
      
      else if(month == 12 && (day == 5 || day == 6 || day == 12 || day == 13 || day == 19 || day == 20 || day == 26 || day == 27)){
        
        Valid_weekend = false;
        cout << "This day falls on a weekend" << endl;
        exit(1);
        
      }
      
      else{
        
        Valid_weekend = true;
      }

     return Valid_weekend; 
    }
    
    void Date::output(int month, int day){

        cout << "your appointment month is " << month << " and your appointment day is " << day << endl;
    }

  void Date::printFreeTimeSlots(bool appointed[]) { //true in the context of boolean array appointed means slot is available
  cout << "Available times slots are: " << endl;

   for(int i {0}; i < 48; i++){
        
        if(appointed[i] == false){ // if appointed[i] == false, then it means a booking is available
      
          if(i%2 == 0) {
    
            cout << i/2 << ":" << "00 - " << i/2 << ":" << "30" << endl;
          
          }
    
          else {
    
            cout << ((double)i/2) - 0.5 << ":" << "30 - " << ((double)i/2) + 0.5 << ":" << "00" << endl; 
    
          }
    
        }

    }
  
  }

  void Date::printAppointedTimeSlots(bool appointed[]) { //false in the context of boolean array appointed means slot is not available


    cout << "All booked time slots are: " << endl;
     
     for(int i {0}; i < 48; i++){
        
        if(appointed[i] == true){ // if true, booking is already made and therefore unavailable
      
          if(i%2 == 0) {
    
            cout << i/2 << ":" << "00 - " << i/2 << ":" << "30" << endl;
          
          }
    
          else {
    
            cout << ((double)i/2) - 0.5 << ":" << "30 - " << ((double)i/2) + 0.5 << ":" << "00" << endl; 
    
          }
    
        }

    }

  }

  //This function tests if two dates are equal given the month and day of both dates
  bool equal(int m1, int d1, int m2, int d2){
    bool is_equal = {false};
    
    if (m1 == m2 && d1 == d2){
      is_equal = true;           //Both dates are equal
    }

    return is_equal;
  }

  Date::Date(){
    return;
  }

  Date::Date(int m, int d){
    month = m;
    day = d;
  }

