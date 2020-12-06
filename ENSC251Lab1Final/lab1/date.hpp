//header file date.hpp to declare your class

/*You use the hpp files for declaring the class with the needed variables and member functions. And you use the cpp files for defining those member functions*/




class Date {
  public:
    Date(int m, int d); //Constructor functions
    Date();
    friend bool equal(int m1, int d1, int m2, int d2);
    void output(int month, int day);
    int getMonth();
    int getDay();
    void setDate(int m, int d);
    void setDate(); // test exception involving no input, default to sept 8th
    void printFreeTimeSlots (bool appointed[48] = {});
    void printAppointedTimeSlots (bool appointed[48] = {});
    bool isValid(int month, int day);
    bool isHoliday(int month, int day, const int thanksgivingDay = 12, const int thanksgivingMonth = 10, const int rememberanceDay = 11, const int rememberanceMonth = 11);
    bool isWeekend(int month, int day);


  private:
    int month;
    int day;
    bool appointed[48] = {}; // array called appointed of 48 (every 30 minute interval)

};



// use a 2d array? 48 x 103 where 103 represents the days in between sept 8th and dec 20th