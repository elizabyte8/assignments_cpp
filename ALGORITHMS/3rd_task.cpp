// ---------- 3rd) TASK ---------- bus, passangers, stations, summer 2018
#include <iostream>
#include <ctime>

int main()// START of MAIN
{
 srand(time(NULL));

 int days = 0, people = 0, random_passangers, double_passangers_for_another_if = 0,   total_people = 0;

 string week[6] = {"Sunday", "Monday", "Tuesday", "Wednesday","Thursday", "Friday"};

 char stations[4] = {'A', 'B', 'C', 'D'};
 
  while (days != 6)
  {
    for (int i = 0; i < 6; i++)
    { 
      days++;
       for (int j = 0; j < 4; j++)
       { 
         if (i != 4 && j == 0)
         { 
           random_passangers = rand()%10+6; 
           total_people += random_passangers;

           double_passangers_for_another_if = random_passangers;

           std::cout <<"\n\nIt is " << week[i] << "\nThe bus went through the \n" << stations [j]  << "_station and it took " << random_passangers << " passangers."; 
          }

         if (i == 4 && j == 0)
         {
           std::cout <<"\n\nIt is " << week[i]<<" today.\n The bus went through the\n" << stations[j] <<" _station and it took 7 passangers."; 
           people = 7;
           total_people += people;

           double_passangers_for_another_if = 7;
         }

         if ((i != 1 || i != 5) && j == 1)
         {
          random_passangers = rand()%2+6;
          total_people += random_passangers;

          std::cout <<"\n\nIt is " << week[i] << "\nThe bus went through the\n" << stations[j]<<"_station and it took "<< random_passangers << " passangers"; 
         }

         if ((i == 1 && i == 5) && j == 1)
         {
          people = double_passangers_for_another_if*2; 
          total_people += people;
          std::cout <<"\n\nIt is " << week[i] << "\nThe bus went through the\n" << stations[j]<<" _station and it took "<< people << " passangers";
         }

         if (i == 6 && j == 2)
         { 
          people = 6;
          total_people += people;
          std::cout <<"\n\nIt is " << week[i] << "\nThe bus went through the\n" <<   stations[j]<<"_station and it took "<< people << " passangers"; 
         }

         if (i == 0 && j == 2)
         {
          people = 0;
          std::cout <<"\n\nIt is " << week[i] << "\nThe bus went through the\n" <<   stations[j]<<"_station and it took "<< people << " passangers because\nTHIS STATION DOES NOT WORK ON SUNDAYS!"; 
         }

         if ((i != 0 && i != 6) && j == 2)
         { 
          random_passangers = rand()%5+7;
          total_people += random_passangers;
          std::cout <<"\n\nIt is " << week[i] << "\nThe bus went through the\n" << stations[j]<<"_station and it took "<< random_passangers << " passangers"; 
         }

         if (j == 3)
         {
          people = 0; 
          std::cout <<"\n\nIt is " << week[i] << "\nThe bus went through the\n" << stations[j]<<"_station and it took "<< people << " passangers because it is a TERMINAL STATION."; 
         }
       } 
     } 
   }// END of main while loop
 std::cout <<"\n\n\n[_The bus had total " << total_people << " passangers from 9/7 to 15/7 of the Summer 2018_]";

return 0;
}// END of MAIN
