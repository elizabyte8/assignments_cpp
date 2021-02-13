// ---------- 5th) TASK ---------- STRINGS
#include <iostream>
#include <string> 
#include <cctype>


void reverse (string users_string)// START of func
{
 for (int i = users_string.length() - 1; i >= 0; i--)
 {
    for (int j = 0; j < '\0'; j++)
    users_string[i] = users_string[j]; 
  std::cout << users_string[i];
 }
}// END of func


void lowercase_or_uppercase (string users_string)// START of func
{ 
 char temp_for_uppercase;

  for (int i = 0; i < users_string.length(); i++)
  { 
    if (i%2 == 0)
    { 
      temp_for_uppercase = toupper(users_string[i]);
      users_string[i] = temp_for_uppercase;
    }
    std::cout << users_string[i];
  }
}// END of func


void if_odd_then_ascci_symbol (string users_string)// START of func
{ 
  for (int i = 0; i < users_string.length(); i ++)
  {
    if (i%2 == 1)
     std::cout << (int)users_string[i];
    else
     std::cout << users_string[i];
  }
}// END of func


void in_descending_order (string users_string)// START of func
{
 int size = users_string.length() - 1;

  for (int i = 0; i <= size; i ++)
  { 
   for (int j = i + 1; j <= size; j ++)
    if ((int)users_string[i] < (int)users_string[j])
    {
      int temp = users_string[i];
      users_string[i] = users_string[j];
      users_string[j] = temp;
    }
   std::cout << users_string[i];
  }
}// END of func


void swapped_by_next (string users_string) // START of func
{
 int size = users_string.length() - 1;
  for (int i = 0; i <= size; i ++)
   if (i%2 == 0) 
    std::cout << users_string[i];
}// END of func


void number_in_alphapet_instead_of_letter (string users_string)// START of func
{ 
 string alphabet = "abcdefghijklmnopqrstuvwxyz";

  for (int i = 0; i <= users_string.length() - 1; i ++)
   for (int k = 0; k <= alphabet.length() - 1; k ++)
   {
     if (users_string[i] == alphabet[k])
      std::cout << k+1;
   }
}// END of func


void consonant_and_vowel (string users_string)// START of func
{
 string vowels = "aeiouy"; 
 string consonants = "bcdfghjklmnpqrstvxzw";

  for (int i = 0; i <= users_string.length() - 1; i++)
   for (int k = 0; k <= consonants.length() - 1; k++)
   {
     if (users_string[i] == consonants[k])
     std::cout << users_string[i];
   }
  for (int i = 0; i <= users_string.length() - 1; i++)
   for (int k = 0; k <= vowels.length() - 1; k ++)
   {
     if (users_string[i] == vowels[k])
     std::cout << users_string[i];
   } 
}// END of func


int main()// START of MAIN
{
 string users_string;
 bool check = false;

 std::cout <<"This program is going to print your string in different ways! Enter your word or  name, but be sure that it does not include non alphabetic characters: ";
 do 
 {
   std::cin >> users_string;
    for (int i = 0; i < users_string.length(); i++)
    {
      if (isalpha(users_string[i]) == 0)
       check = false;
      else
       check = true;
    } 
 } while (check == false);

  std::cout <<"\nIts reverse form looks like: ";
   reverse (users_string);// 1st) subtask
  std::cout <<"\nFor each even iterator of the word its letters will be converted into uppercase,  for each odd into lowercase: ";
   lowercase_or_uppercase (users_string);// 2nd) subtask

  std::cout << "\nEach odd letter will be removed by its ASCCI symbol ";
   if_odd_then_ascci_symbol (users_string);// 3rd) subtask

 std::cout << "\nAll letters are sorted in alphabetical descending order ";
  in_descending_order (users_string);// 4rth) subtask

 std::cout << "\nThe previous letter will be swapped by the next one ";
  swapped_by_next (users_string);// 5th) subtask

 std::cout << "\nLetter's number in alphabet will be printed ";
  number_in_alphapet_instead_of_letter (users_string);// 6th) subtask

 std::cout << "\nConsonants will be priinted fistly, and after that vowels ";
  consonant_and_vowel (users_string);// 7th) subtask

return 0;
}// END of MAIN
