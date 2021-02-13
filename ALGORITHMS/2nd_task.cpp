// ---------- 2nd) TASK ---------- winds direction, ship, island X

#include <iostream>
#include <ctime>

using namespace std;

int main() // MAIN
{

 srand(time(NULL));
 int days = 1, good_condition = 0;

 while (good_condition != 5)
{
  int air = rand()%4;
  cout << "\n\n~~~ It is a " << days << " day of our trip. ~~~";
  cout << "\nWind Direction: ";

  switch(air)
 {
   case 0:
   cout << "West"; 
   break;
   case 1:
   cout << "North";
   break;
   case 2:
   cout <<"East";
   break;
   case 3:
   cout <<"South";
   break;
 }

  if (air == 2 || air == 1)
 {
   days++;
   good_condition++;
   cout << "\nA good day! We are lucky.";
  }

 else
 {
   days++;
   cout << "\nWind conditions are against us.\nThe ship did not move towards its destination today..." << endl;
  }

  if (good_condition == 5)
  cout << "\n\n...EVENTUALLY we arrived! The ship reached the destination in " << days << " days!...";

 }

return 0;
} // END

