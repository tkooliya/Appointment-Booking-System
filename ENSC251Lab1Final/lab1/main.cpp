#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include "time.hpp"
#include "date.hpp"
/*
This is a project dedicated to create an appointment booking system using a date and timerange class. As of Lab 1, the current funcionality is only able to check whether an interval of time and date chosen is valid or not.
*/

using namespace std;

int main(){
START:
Date appointment1_date;
TimeRange appointment1_time;
int yes_or_no = 0;
cout<<"Would you like to set a date?"<< endl << "Input ""1"" for yes or ""2"" for no" <<endl;
cin>>yes_or_no;

if (yes_or_no == 1){
  int m{0};
  int d{0};
  int beginhour{0};
  int beginminute{0};
  int endhour{0};
  int endminute{0};
  cout<<"Enter the month as a number"<<endl;
  cin>>m;
  cout<<"Enter the day as a number"<<endl;
  cin>>d;
  
  appointment1_date.isWeekend(m, d);
  appointment1_date.isHoliday(m, d);
  appointment1_date.isValid(m, d);
  appointment1_date.setDate(m,d);
  appointment1_date.output(m, d);

  cout << "Enter the beginning hour followed by beginning minute (only intervals of 30) " << endl;
  cin >> beginhour >> beginminute;
  cout << "Enter the end hour followed by end minute (only intervals of 30) " << endl;
  cin >> endhour >> endminute;

  appointment1_time.isValid(beginhour, beginminute, endhour, endminute); // only checks if they are viable options after time
  appointment1_time.set_Time(beginhour, beginminute, endhour, endminute);
  appointment1_time.output(beginhour, beginminute, endhour, endminute);




}
else if (yes_or_no == 2){
  cout << "Bye" << endl;
  exit(1);                     //Later this should change to be goto menu
}
else if (yes_or_no == false){       //Used exit function to stop infinite loop
  cout << "Invalid input" << endl;
  exit(1);
}
else{
  cout << "Invalid input" << endl << endl << endl;
  goto START;
}

LOOP:

int monthmain = appointment1_date.getMonth();
int daymain = appointment1_date.getDay();
int beginhourmain = appointment1_time.get_beginHour();
int beginminmain = appointment1_time.get_beginMinute();
int endhourmain = appointment1_time.get_endHour();
int endminmain = appointment1_time.get_endMinute();

cout << endl << "--------------------------------------------------------" << endl << endl;
cout << "Your current appointment day is " << monthmain << "/" << daymain << "/2020 " << endl;
cout << "Your current appointment time is " << beginhourmain << ":" << setfill('0') << setw(2) << beginminmain << " - " << endhourmain << ":" << setfill('0') << setw(2) << endminmain << endl;


int changeChoice;
cout << "Enter 1 if you would like to change the appointment date" << endl;
cout << "Enter 2 if you would like to change the appointment time" << endl;
cout << "Enter 3 if you would like to change both the date and time" << endl;
cout << "Enter 4 if you would like to keep the current appointment date and time" << endl;
cin >> changeChoice;
cout << endl;

if (changeChoice == 1){         //Change appointment date
  int m{0};
  int d{0};
  
  cout<<"Enter the new month as a number"<<endl;
  cin>>m;
  cout<<"Enter the new day as a number"<<endl;
  cin>>d;
  
  appointment1_date.isWeekend(m, d);
  appointment1_date.isHoliday(m, d);
  appointment1_date.isValid(m, d);
  appointment1_date.setDate(m,d);
  //appointment1_date.output(m, d);
  cout << "Your new date is " << appointment1_date.getMonth() << "/" << appointment1_date.getDay() << "/2020" << endl;

  goto LOOP;
  
}
else if (changeChoice == 2){    //Change appointment time
  
  int beginhour{0};
  int endhour{0};
  int beginminute{0};
  int endminute{0};
  cout << "Enter the beginning hour followed by beginning minute (only intervals of 30) " << endl;
  cin >> beginhour >> beginminute;
  cout << "Enter the end hour followed by end minute (only intervals of 30) " << endl;
  cin >> endhour >> endminute;

  appointment1_time.isValid(beginhour, beginminute, endhour, endminute);
  appointment1_time.set_Time(beginhour, beginminute, endhour, endminute);
  //appointment1_time.output(beginhour, beginminute, endhour, endminute);
  cout << "Your new time slot is " << appointment1_time.get_beginHour() << ":" << appointment1_time.get_beginMinute() << " - " << appointment1_time.get_endHour() << ":" << appointment1_time.get_endMinute() << endl;


  goto LOOP;
}
else if (changeChoice == 3){    //Change appointment date and time
  
  int m{0};
  int d{0};
  int beginhour{0};
  int endhour{0};
  int beginminute{0};
  int endminute{0};
  cout<<"Enter the new month as a number"<<endl;
  cin>>m;
  cout<<"Enter the new day as a number"<<endl;
  cin>>d;
  
  appointment1_date.isWeekend(m, d);
  appointment1_date.isHoliday(m, d);
  appointment1_date.isValid(m, d);
  appointment1_date.setDate(m,d);
  //appointment1_date.output(m, d);
  cout << "Your new date is " << appointment1_date.getMonth() << "/" << appointment1_date.getDay() << "/2020" << endl;
  
  cout << "Enter the beginning hour followed by beginning minute (only intervals of 30) " << endl;
  cin >> beginhour >> beginminute;
  cout << "Enter the end hour followed by end minute (only intervals of 30) " << endl;
  cin >> endhour >> endminute;

  appointment1_time.isValid(beginhour, beginminute, endhour, endminute);
  appointment1_time.set_Time(beginhour, beginminute, endhour, endminute);
  //appointment1_time.output(beginhour, beginminute, endhour, endminute);
  cout << "Your new time slot is " << appointment1_time.get_beginHour() << ":" << appointment1_time.get_beginMinute() << " - " << appointment1_time.get_endHour() << ":" << appointment1_time.get_endMinute() << endl;

  goto LOOP;
}
else if (changeChoice == 4){    //Change nothing
  cout << "Okay, your schedule is confirmed!" << endl;
  return (0);
}
else{                           //Invalid input   
  cout << "Invalid input, try again" << endl;
  goto LOOP;
} 


}



// may want to remove exit code and utilize return values instead
