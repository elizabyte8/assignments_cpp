// ---------- 2nd) TASK ---------- fun with maths

#include <iostream>
#include <ctime> 

using namespace std;

int main () // MAIN
{
 int first_num, second_num;
 
// 1st) subtask
 cout << "\nThis programm will help you to have some fun with mathemathical operations.\nJust give me two three-digit numbers.\n!PLEASE NOTICE! that their range can be STRICTLY from -999 up to 999.\nSo, your first three-digit number is: "<< endl;

 do 
 {
   cin >> first_num;

   if (first_num < -999 || first_num > 999)
   cout << "The range can be only from -999 up to 999!" << endl;

   else if (first_num < 100 && first_num > -100)
   cout << "The number must be THREE_DIGIT!" << endl;

 } while (first_num < -999 || first_num > 999 || (first_num < 100 && first_num > -100));

cout << "\nGreat! Now enter a second three-digit number: \n";

 do 
 {
   cin >> second_num;

   if (second_num < -999 || second_num > 999)
   cout << "The range can be only from -999 up to 999!" << endl;

   else if (second_num < 100 && second_num > -100)
   cout << "The number must be THREE_DIGIT!" << endl;
 } while (second_num < -999 || second_num > 999 || (second_num < 100 && second_num > -100));

 cout << "\nThank you! Now the program will make some magic for you...~\nSo\n";

 int result;

  if (first_num > 0 && second_num > 0 && first_num != second_num)
 {
   result = first_num + second_num;
   cout << "You entered two positive numbers, the program decided to show you their addition: " << result;
 }

 else if (first_num < 0 && second_num < 0 && first_num != second_num)
 {
   result = first_num - second_num;
   cout << "You entered two negative numbers, the program decided to show you their subtraction: " << result;
}

else if (first_num == second_num)
 {
   result = first_num * second_num;
   result = -result;
   cout << "You entered two equal numbers, the program decided to show you their multiplication with an opposite sign: "<< result;
 }
 else 
 {
   result = first_num * second_num;
   cout << "You entered two numbers with differend signs, the program decided to show you their multiplication: " << result;
 }

// 2nd) subtask
 int num1 = first_num/100%10; // the way to get the first digit only
 int num2 = second_num%10; // the way to get the third digit only
// first_num/10%10 -> the way to get the second digit only

  if (num1 > num2)
 {
   result = (first_num/10%10) + (second_num/10%10);
   cout << "\n\nThe first digit of the first three-digit number is bigger that the third digit of the second three-digit number, thus the program decided to show you the addition of the numbers in the middle: " << result << endl;
 }

  else
 {
 result = (first_num/10%10) * (second_num/10%10);
 cout << "\n\nThe first digit of the first three-digit number is less that the third digit of the second three-digit number, thus the program decided to show you the multiplication of the numbers in the middle: " << result << endl;
 }

return 0;
} // END
