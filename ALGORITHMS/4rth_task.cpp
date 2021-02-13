// ---------- 4th) TASK -------- bees (males and females) and honey
#include <iostream>
#include <cstring>
#include <ctime>

class bee// START of CLASS
{
 public:

 string head;
 string thorax;
 string abdomen;
 int compound_eye;
 int small_eyes;
 int antennae;
 int wings;

 bee () // constructor of bee class
 {
  head = "head";
  thorax = "thorax";
  abdomen = "abdomen";

  compound_eye = 2;
  small_eyes = 3;
  antennae = 2;
  wings = 2;
 }

  class female// START of CLASS
  {
   public:

    int stinger;
    string glands;

     female () // START of constructor
     {
      stinger = 1;
      glands = "many glands";
     }

     int get_stinger()// START of getter
     {
       return stinger;
     }

     string get_glands()// START of getter
     {
       return glands;
     }
   };// END OF FEMALE CLASS

  void print(bool sex, female f)// START of method
  {
    std::cout << "\nOne " << head <<"\nOne " << thorax << "\nOne " << abdomen << "." << std::endl;

    std::cout << 2 << compound_eye << " compound eyes, " << small_eyes << " small eyes, " << antennae << " antennaes, " << wings << " wings.\n";

    if (sex == 0)
    std::cout << "ANY MALE DOES NOT possess stinger and glands. It cannot produce honey!" << std::endl;
    else
    std::cout << "EVERY FEMALE HAS " << f.get_stinger() << " stinger and " << f.get_glands() << "." << std::endl;
   }// END of method
};// END OF BEE CLASS


int main()// START of MAIN
{
 srand(time(NULL));
 int random_females = rand()%50+41, random_males = rand()%25+26, i = 0;
 bool sex;

 bee female[90];
 bee male[50];
 bee::female f;

std::cout << "\n\n~ The program is going to describe parts of a female or a male bee. ~\n\n [...Let's begin with female bees...]\n_We have them in a quantity of: " << random_females << "_" << std::endl;
 while (i < random_females)
 {
  female[i].print(1,f);
   i++;
 }

 random_males = rand()%50+41, i = 0;
std::cout << "\n\n[...NOW The program is going to describe parts of male bees...]\n_We have them in a quantity of " << random_males << "_" << std::endl;
 while (i < random_males)
 {
  male[i].print(0,f);
   i++;
 }
 
 if (random_females >= 70)
 std::cout << "\nThere are " << random_females << " bees and they ARE ENOUGH to produce honey! :-) ";
 else
 std::cout << "\nThere are " << random_females << " bees and they ARE NOT ENOUGH to produce honey... :-(... T_T";

return 0;
}// END of MAIN
