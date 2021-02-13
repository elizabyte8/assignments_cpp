
// ---------- 1st) TASK ---------- archer, aim, competition
#include <iostream>
#include <ctime>

int main()// START of MAIN
{
  srand(time(NULL));
  int random_bullet = rand()%101, aim = 100, 
  succes = 0, defeat = 0;

cout << "A sniper starts shoting... ->\n" << endl;

 while (succes != 3 && defeat != 2)
 {
   if (random_bullet > 0 && random_bullet < 77)
   {
    std::cout <<"Sniper missed!" << std::endl;
     defeat++;
   }

   if (random_bullet > 70 && random_bullet < 100)
   {
    std::cout <<"Sniper missed! BUT he was VERY close! " << std::endl;
     defeat++;
   }

   else
   {
    std::cout <<"Wow! Sniper shoted at the aim! He succeed! " << std::endl;
     succes++;
   }

   if (defeat == 2)
    std::cout << "\nUnfortunately, the sniper defeated 2 times. He lost the competition... " << std::endl;
   if (succes == 3)
    std::cout << "\n!OMG! The sniper won the competition! He is the winner!" << std::endl;
 }
return 0; 
}// END of MAIN
