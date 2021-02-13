// ---------- 1st) TASK ---------- hours until the Christmas
#include <iostream>
#include <ctime> // we use the header <ctime> to find out the current time of the system


class Christmas// START of CLASS
{
  public:
 int seconds = 0;
 int minutes = 0;
 int hours = 0;
 int day = 25;
 int month = 12;
 int year = 2020;


 int count_difference_in_days (int day, int month)// START of method
 {
  int days;

  if (day > this->day)
   days = ((day - this->day) + ((this->month - month)*30));

  else
   days = ((this->day - day) + ((this->month - month)*30));

 return days;
 }// END of method

 
 int transfer_difference_in_days_into_hours (int hour,int *day, int *month)// START of method
 {
  int hours = ((count_difference_in_days (*day,*month) * 24) - hour);

 return hours;
 }// END of method
};// END of class


int main ()// START of MAIN
{
// we use the header <ctime> to find out the current time of the system, in that header are located classes, structures and functions which will help us (time_t, tm, localtime()).
 time_t ttime = time(0); 
 tm *local_time = localtime(&ttime);
 std::cout << "\n~ Hello, user! ~\nThis program will help you to find out how many hours are remained until the Christmas!\nJust reminding you that the current date is:\n " << endl;
 std::cout << "-------------------------------" << std::endl;
 std::cout << "Year: "<< 1900 + local_time->tm_year << std::endl;
 std::cout << "Month: "<< 1 + local_time->tm_mon<< std::endl;
 std::cout << "Day: "<< local_time->tm_mday << std::endl;
 std::cout << "Time: ["<< 1 + local_time->tm_hour << ":";
 std::cout << local_time->tm_min << ":";
 std::cout << local_time->tm_sec << "]" << std::endl;
 std::cout << "-------------------------------" << std::endl;

// just making our life easier by initializing shorter variables' names of the user's system date
 int day = local_time->tm_mday; 
 int month = local_time->tm_mon;
 int hour = local_time->tm_hour;
 int minutes = local_time->tm_min;
 int seconds = local_time->tm_sec;
 Christmas c; // an object c of a class Christmas

std::cout <<"\nThere are " << c.count_difference_in_days (day, month) << " days or " << c.transfer_difference_in_days_into_hours (hour, &day, &month) << " hours until the Christmas!" << std::endl;

return 0;
}// END of MAIN
