
// ---------- 4th) TASK ----------  convert a decimal number to hexadecimal number 
#include<iostream> 
#include <cctype>


void decimal_to_hexadecimal(int number)// START of func
{ 
 // char array to store hexadecimal number 
 char hexaDeciNum[100]; 
 // counter for hexadecimal number array 
 int i = 0; 
 while (number!=0) 
 { 
  // temporary variable to store remainder 
  int temp = 0; 
  // storing remainder in temp variable. 
  temp = number % 16; 
  // check if temp < 10 
  if (temp < 10) 
  { 
    hexaDeciNum[i] = temp + 48; 
     i++; 
  } 
  else
  { 
    hexaDeciNum[i] = temp + 55; 
     i++; 
  } 
  number = number/16; 
 }// END of while loop 
std::cout << "Your decimal number looks like ";
 // printing hexadecimal number array in reverse order 
 for (int j = i-1; j >= 0; j--) 
 {
   std::cout << hexaDeciNum[j]; 
 }
std::cout << " in hexacedimal numeric system.";
}// END of func


int main()// START of MAIN
{ 
 int number; bool check;

 std::cout << "This program will help you to convert any decimal number to its hexadecimal form. WARNING! Your number must include digits in the range of between three digits up to six digits.\nPlease, enter the desired number to convert: " << std::endl;

 do
 {
  std::cin >> number;
  if (isdigit(number) == 0)
   check = false;
  else
   check = true;
 } while ((number < 100 && number > 99999) || check == false);

 decimal_to_hexadecimal(number); 
return 0; 
}// END of MAIN
