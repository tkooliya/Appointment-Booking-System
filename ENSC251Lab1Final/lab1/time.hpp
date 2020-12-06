//header file time.hpp to declare your class
class TimeRange {
  public:
    TimeRange(int beginH, int beginM, int endH, int endM);  //Constructor Functions
    TimeRange(int beginH, int beginM);  //Default end time for 30 min later
    TimeRange();                       
     
    int get_beginHour();
    int get_beginMinute();
    int get_endHour();
    int get_endMinute();
    void set_Time(int beginH, int beginM, int endH, int endM);
    void output(int beginH, int beginM, int endH, int endM); 
    bool isValid(int beginHour, int beginMinute, int endHour, int endMinute); 

  private:
    int beginHour;
    int beginMinute;
    int endHour;
    int endMinute;


};
