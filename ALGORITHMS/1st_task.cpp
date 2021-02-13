
// ---------- 1st) TASK ---------- archer, aim, competition


#include <iostream>
#include <ctime>

using namespace std;

int main() //MAIN
{
  srand(time(NULL));
  int random_bullet = rand()%101, aim = 100, 
  succes = 0, defeat = 0;

cout << "A sniper starts shoting... ->\n" << endl;

  while (succes != 3 && defeat != 2)
 {
    if (random_bullet > 0 && random_bullet < 77)
   {
     cout <<"Sniper missed!" << endl;
   defeat++;
    }

    if (random_bullet > 70 && random_bullet < 100)
   {
     cout <<"Sniper missed! BUT he was VERY close! " << endl;
   defeat++;
   }

   else
  {
    cout <<"Wow! Sniper shoted at the aim! He succeed! " << endl;
   succes++;
  }

   if (defeat == 2)
    cout << "\nUnfortunately, the sniper defeated 2 times. He lost the competition... " << endl;
   if (succes == 3)
    cout << "\n!OMG! The sniper won the competition! He is the winner!" << endl;
 }


return 0; 
} // END
