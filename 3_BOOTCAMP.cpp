// ---------- 3rd) TASK ---------- convert decimal to binary or binary to decimal

#include <iostream> 
#include <cstring>
#include <cctype>
#include <cmath>

using namespace std;

void decimal_to_binary(int number, int arr[], int *size)  // FUNCTION 
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
}  // END

int binary_to_decimal(int number)  // FUNCTION
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
}  // END


int main()  // MAIN
{ 
 char choice; int number, binary[50], size = 0;
 bool check = false;

 cout << "\nThis program will help you to convert the given decimal number to binary  numeral system\n\tor\n binary number to decimal numeral system!\n\n TAP [D] if you want to convert binary number to decimal numeral system\n\n\tor\n\nTAP [B] if you want to convert decimal number to binary numeral system.\n \nPlease, enter your choice: " <<  endl;

   do
 {
   cin >> choice;
   choice = toupper(choice);
   if (choice != 'D' && choice != 'B')
   cout << "Please, try again: " << endl;
 } while (choice != 'D' && choice != 'B');

 cout << "\nVery well!\nNow enter the desired number to convert and the program will make it for you. \nWarning! Your number must consist MINIMUM 3 digits or MAXIMUM 6 digits: \n"; 

   do
 {  
   cin >> number;
   if (isdigit(number) == 1 || (number >= 100 && number <= 999999))
   check = true; 
   else
   cout <<" Please, try again: " << endl;
 } while (check == false);

  if (choice == 'D' && (number%10 == 0 && number%2 == 0 ))
  cout << "Your number is binary! Its decimal form looks like " <<        binary_to_decimal(number);
 
 else 
 { 
  cout << "Your number is decimal! Its binary form looks like ";
  decimal_to_binary(number,binary,&size);
 }
 for (int i = size-1; i >= 0 ; i--)
 { cout << (binary[i]); }

cout << "\nDo you wish to continue? Y/n" << endl;
cin >> choice;
if (choice == 'Y' || choice == 'y')
return main();
else
cout << "Thank you for using my program! Goodbye ~" << endl;
return 0;
} // END

