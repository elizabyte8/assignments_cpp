// ---------- 3rd) TASK ---------- convert decimal to binary or binary to decimal
#include <iostream> 
#include <cstring>
#include <cctype>
#include <cmath>


void decimal_to_binary(int number, int arr[], int *size)// START of func
{ 
 int i = 0;
  while(true) 
  {
   if (number <= 0) 
    break;

   arr[i] = number%2; 
   number = number/2;
   *size += 1; 
    i++;
  } 
}// END of func


int binary_to_decimal(int number)// START of func
{
 int i = 0, remainder, sum;

 while(true)
 {
   if(number <= 0)
    break;
  
   remainder = number%10;
   sum = sum + (remainder*pow(2,i));
   number = number/10;
    i++;
 }
return sum;
}// END of func


int main()// START of MAIN
{ 
 char choice; int number, binary[50], size = 0;
 bool check = false;

 std::cout << "\nThis program will help you to convert the given decimal number to binary  numeral system\n\tor\n binary number to decimal numeral system!\n\n TAP [D] if you want to convert binary number to decimal numeral system\n\n\tor\n\nTAP [B] if you want to convert decimal number to binary numeral system.\n \nPlease, enter your choice: " << std::endl;

  do
 {
  std::cin >> choice;
  choice = toupper(choice);
  if (choice != 'D' && choice != 'B')
   std::cout << "Please, try again: " << std::endl;
 } while (choice != 'D' && choice != 'B');

 std::cout << "\nVery well!\nNow enter the desired number to convert and the program will make it for you. \nWarning! Your number must consist MINIMUM 3 digits or MAXIMUM 6 digits: \n"; 

  do
 {  
   std::cin >> number;
   if (isdigit(number) == 1 || (number >= 100 && number <= 999999))
    check = true; 
   else
    std::cout <<" Please, try again: " << std::endl;
 } while (check == false);

  if (choice == 'D' && (number%10 == 0 && number%2 == 0 ))
   std::cout << "Your number is binary! Its decimal form looks like " << binary_to_decimal(number);
 
 else 
 { 
   std::cout << "Your number is decimal! Its binary form looks like ";
  decimal_to_binary(number,binary,&size);
 }
 
 for (int i = size-1; i >= 0 ; i--)
  std::cout << (binary[i]); 

 std::cout << "\nDo you wish to continue? Y/n" << std::endl;
 std::cin >> choice;
 
 if (choice == 'Y' || choice == 'y')
  return main();
 else
  std::cout << "Thank you for using my program! Goodbye ~" << std::endl;
return 0;
}// END of MAIN

