// ---------- 5th) TASK ---------- STRINGS

#include <iostream>
#include <string> 
#include <cctype>

using namespace std;

void reverse (string users_string) // FUNCTION 
{
 for (int i = users_string.length() - 1; i >= 0; i--)
 {
    for (int j = 0; j < '\0'; j++)
    users_string[i] = users_string[j]; 
 cout << users_string[i];
 }
} // END

void lowercase_or_uppercase (string users_string) // FUNCTION 
{ 
 char temp_for_uppercase;

   for (int i = 0; i < users_string.length(); i++)
  { 
     if (i%2 == 0)
     { 
       temp_for_uppercase = toupper(users_string[i]);
       users_string[i] = temp_for_uppercase;
      }
    cout << users_string[i];
  }
} // END

void if_odd_then_ascci_symbol (string users_string) // FUNCTION 
{ 
  for (int i = 0; i < users_string.length(); i ++)
  {
     if (i%2 == 1)
     cout << (int)users_string[i];
     else
     cout << users_string[i];
  }
} // END

void in_descending_order (string users_string) // FUNCTION 
{
 int size = users_string.length() - 1;

  for (int i = 0; i <= size; i ++)
  { 
     for (int j = i + 1; j <= size; j ++)
       if ( (int)users_string[i] < (int)users_string[j] )
      {
         int temp = users_string[i];
         users_string[i] = users_string[j]; 
         users_string[j] = temp;
      }
   cout << users_string[i];
 }
} // END

void swapped_by_next (string users_string) // FUNCTION 
{
 int size = users_string.length() - 1;
  for (int i = 0; i <= size; i ++)
    if (i%2 == 0) 
    cout << users_string[i];
} // END

void number_in_alphapet_instead_of_letter (string users_string) // FUNCTION 
{ 
 string alphabet = "abcdefghijklmnopqrstuvwxyz";

  for (int i = 0; i <= users_string.length() - 1; i ++)
    for (int k = 0; k <= alphabet.length() - 1; k ++)
    {
      if (users_string[i] == alphabet[k])
      cout << k+1;
    }
} // END

void consonant_and_vowel (string users_string) // FUNCTION 
{
 string vowels = "aeiouy"; 
 string consonants = "bcdfghjklmnpqrstvxzw";

  for (int i = 0; i <= users_string.length() - 1; i++)
    for (int k = 0; k <= consonants.length() - 1; k++)
   {
      if (users_string[i] == consonants[k])
      cout << users_string[i];
   }
  for (int i = 0; i <= users_string.length() - 1; i++)
    for (int k = 0; k <= vowels.length() - 1; k ++)
   {
      if (users_string[i] == vowels[k])
      cout << users_string[i];
   } 
} // END


int main() // MAIN
{
 string users_string;
 bool check = false;

 cout <<"This program is going to print your string in different ways! Enter your word or  name, but be sure that it does not include non alphabetic characters: ";
 do 
 {
   cin >> users_string;
     for (int i = 0; i < users_string.length(); i++)
    {
       if (isalpha(users_string[i]) == 0)
       check = false;
       else
       check = true;
    } 
 } while (check == false);

 cout <<"\nIts reverse form looks like: ";
 reverse (users_string); // 1st) subtask
 cout <<"\nFor each even iterator of the word its letters will be converted into uppercase,  for each odd into lowercase: ";
 lowercase_or_uppercase (users_string); // 2nd) subtask

 cout << "\nEach odd letter will be removed by its ASCCI symbol ";
 if_odd_then_ascci_symbol (users_string); // 3rd) subtask

 cout << "\nAll letters are sorted in alphabetical descending order ";
 in_descending_order (users_string); // 4rth) subtask

 cout << "\nThe previous letter will be swapped by the next one ";
 swapped_by_next (users_string); // 5th) subtask

 cout << "\nLetter's number in alphabet will be printed ";
 number_in_alphapet_instead_of_letter (users_string); // 6th) subtask

 cout << "\nConsonants will be priinted fistly, and after that vowels ";
 consonant_and_vowel (users_string); // 7th) subtask

return 0;
} // END
