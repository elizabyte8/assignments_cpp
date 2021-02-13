// ---------- 5th) TASK ---------- DNA, CGTA, find appropriate [N]itrogenous base
#include <iostream>
#include <cstring>
#include <ctime>

const int SIZE_OF_DNA_CHAIN = 27;

void generate (char *dna_1, char *dna_2)// START of FUNCTION
{ 
  srand(time(NULL));

  int i = 0;

   while (i < SIZE_OF_DNA_CHAIN)
   {
     int nitro_base = rand()%4;
     
      switch (nitro_base) // let's generate a RANDOM DNA chain
      {
        case 0:       
         na_1[i] = 'A';
         break;
        case 1:
         dna_1[i] = 'T';
         break;
        case 2:          
         dna_1[i] = 'G';
         break;
        case 3:
         dna_1[i] = 'C';
         break;
      }

// now let's generate its compatible part

    if (dna_1[i] == 'G')
    dna_2[i] = 'C';
    else if (dna_1[i] == 'C')
    dna_2[i] = 'G';
    else if (dna_1[i] == 'A')
    dna_2[i] = 'T';
    else 
    dna_2[i] = 'A';

    i++;
   }// end of while() loop

 cout << "\nThe RANDOMLY generated DNA chain:    ";
  for (i = 0; i < SIZE_OF_DNA_CHAIN; i++)
 {
  cout << dna_1[i];
 }

 cout << "\nIts compatible DNA chain looks like: ";
  for (i = 0; i < SIZE_OF_DNA_CHAIN; i++)
 {
  cout << dna_2[i];
 }

} // END OF FUNCTION

int main () // MAIN
{
  string dna_1 = {"GGAGATGGTATGCGGCATTTAAAGAGC"}; // the given DNA chain
  char dna_2[SIZE_OF_DNA_CHAIN]; // the DNA chain which will be generated 
  char dna_3[SIZE_OF_DNA_CHAIN]; // the DNA for the function generate()

cout << "\nThe given DNA chain is: " << dna_1 << "\nIts compatible DNA chain looks like: ";
  for (int i = 0; i < SIZE_OF_DNA_CHAIN; i++)
 {
   if (dna_1[i] == 'G')
   dna_2[i] = 'C';
   else if (dna_1[i] == 'C')
   dna_2[i] = 'G';
   else if (dna_1[i] == 'A')
   dna_2[i] = 'T';
   else 
   dna_2[i] = 'A';
   cout << dna_2[i];
 }

cout << "\n\nThe program will RANDOMLY generate another 5 DNA chains and will find its compatible chains.\n\n1st pair: ";
generate(dna_2,dna_3);

cout <<"\n\n2nd pair: ";
 generate(dna_2,dna_3);

cout <<"\n\n3rd pair: ";
 generate(dna_2,dna_3);

cout <<"\n\n4th pair: ";
 generate(dna_2,dna_3);

cout <<"\n\n5th pair: ";
generate(dna_2,dna_3);

return 0;
} // END


