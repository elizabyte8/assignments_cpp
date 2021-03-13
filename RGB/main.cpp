#include <iostream>
#include <string>
#include <vector>
#include <cmath>// for pow() func
#include <map>
#include <algorithm>
#include <cctype>// for toupper() func

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define INT64 unsigned long long int// new datatype for hexadecimal value
const int NUM_OF_ALL_COLOURS = 25;
const int THREE = 3;// 3 is the MIN number for "very close" comparison statement


class Colours// START of class
{
 public:
//__data_segment

  INT64 array_of_colours[NUM_OF_ALL_COLOURS];
  std::map <char, int> hexadecimal
   {
   {'0',0}, {'1',1}, {'2',2}, {'3',3},
   {'4',4}, {'5',5}, {'6',6}, {'7',7},
   {'8',8}, {'9',9}, {'A',10}, {'B',11},
   {'C',12,}, {'D',13}, {'E',14}, {'F',15}
   }; 
  std::map <std::string, std::string> colours_table_hex
  {
  {"aliceblue","F0F8FF"}, {"antiquewhite","FAEBD7"}, 
  {"aqua", "00FFFF"}, {"aquamarine", "77FFD4"}, 
  {"azure", "F0FFFF"}, {"beige", "F5F5DC"}, 
  {"bisque", "FFE4C4"}, {"black", "000000"},
  {"blandchedalmond", "FFEBCD"}, {"blue", "0000FF"},
  {"blueviolet", "8A2BE2"}, {"brown", "A52A2A"},
  {"burlywood", "DEB887"}, {"cadetblue", "5F9EA0"},
  {"chartreuse", "7FFF00"}, {"chocolate", "D2691E"},
  {"coral", "FF7F50"}, {"cornflowerblue", "6495ED"},
  {"cornsilk" , "FFF8DC"}, {"crimson", "DC143C"},
  {"cyan", "00FFFF"}, {"darkblue", "00008B"},
  {"darkcyan", "008b8b"}, {"darkgoldengold", "B8860B"},
  {"darkgray", "A9A9A9"}
  };
  std::map <std::string, int> colours_table_dec;
  std::string users_colour;


//__code_segment

 Colours()// START of default constructor
 {
  INT64 multiplication = 0, result = 0;
  int power_of = 0;
  std::vector <std::string> vec;
  auto it = colours_table_hex.begin();  

   for(auto k = 0; k < colours_table_hex.size(); k++)
  {// fills a vector with hexadecimal values 
    vec.push_back(it->second);// "F0F8FF" & etc
    it++;
  }

  for(int i = 0; i < NUM_OF_ALL_COLOURS; i++)
  {// converts ALL map's hexadecimal values into decimal
    multiplication = 0;
    power_of = 0;
    result = 0;
      auto it = colours_table_hex.begin();  
      for(int j = vec[i].length() - 1; j >= 0; j--)  
      {
        multiplication = hexadecimal[vec[i][j]] * pow(16,power_of);
        result += multiplication;// the total result
        power_of++;  
      }
  array_of_colours[i] = result;// & fills them into array of ints
  it++;
  }
 }// END of default constructor


 void from_hex_to_dec(std::string input)// START of method
 {// converts hexadecimal values into decimal numeral system
  // and shows neighbour colours by decimal values (the bigger & the lesser)

//__data_segment_of_method
  std::map <int, std::string> nMap;// KEY is decimal value of hexadecimal, VALUE is name of colour
  std::map <std::string, std::string>::iterator it = colours_table_hex.begin(); 
  INT64 multiplication = 0, result = 0;
  users_colour = input;
  int power_of = 0, k = 0;

  for(int i = 0;i < 25; i++)
  {
    nMap[array_of_colours[i]]  = it->first;// fills map with data from different sources (array of ints & another map)
  it++;
  }
  it = colours_table_hex.begin();// initializes to the begin for start in loop running

  std::map <int, std::string>:: iterator nMapIt = nMap.begin();// creates new iterator
//__end_of_data_segment

//__code_segment_of_method

  for(int i = users_colour.length() - 1; i >= 0; i--)  
  {// converts user's input into decimal 
    multiplication = hexadecimal[users_colour[i]] * pow(16,power_of);
    result += multiplication;// the total result
    power_of++;
  }

  do// main purpose of the method
  {
    if(array_of_colours[k] == result)
    { 
      it = std::next(it,k);
      std::cout << "\n\tyour hexadecimal is " << it->first << " colour & its decimal value is " << result << std::endl;
      std::cout << "\n\tNEIGHBOUR COLOURS with neighbour decimal values are:" << std::endl;
      
      for(int i = 0; i < NUM_OF_ALL_COLOURS; i++)
      {
        nMapIt = std::next(nMap.begin(),i);// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! (there were some problems with segmentation fault, took me days to find them out, a mark for me in the future)
        if(array_of_colours[k] == nMapIt->first)
        {
          nMapIt = std::next(nMap.begin(),i+1);      
          std::cout << "\t" << nMapIt->second << " colour and its decimal value is " << nMapIt->first << std::endl; 
          
          if(result != 0)
          {
            nMapIt = std::next(nMap.begin(),i-1);    
            std::cout << "\t" << nMapIt->second << " colour and its decimal value is " << nMapIt->first << std::endl; 
          }// end of if
        }// end of if
      }// end of for
    }// end of if  
   k++;    
  }while(k < NUM_OF_ALL_COLOURS);
 }// END of method


 void cold_or_warm(std::string &red, std::string &green, std::string &blue)// START of method
 {
  std::map <std::string, std::string>::iterator it = colours_table_hex.begin();
  users_colour  = red + green + blue; 
  int k = 0;

  std::cout << "\nThe colour number you gave is:" << std::endl;

  do
  {// do loop is for the iterator incrementation
  // 'cause there are 25 words in colours_table_hex map 
    std::string hex_colour = it->second;// but we put map's hex value in a string to make our life easier

    int counter1 = 0, counter2 = 0,  counter3 = 0;

      for(int i = 0; i < hex_colour.length(); i++)
      {
        if((i%2 == 0) && (users_colour[i] == hex_colour[i]))
          counter1++;// if the values differ only at every odd index (when i = 1,3,5)
          // exp: the correct is FAEBD7 but user gave F1E2D3
        if(users_colour[i] == hex_colour[i])
          counter2++;// if the values are completely the same
        if(i%2 == 0)
        {// if the values differ only at one pair of odd and even index
         // exp: the correct is FAEBD7 but user gave C1EBD7 or FAC1D7 or FAEBC1 
        int itemp = i + 1;
          if(users_colour[i] == hex_colour[i] && users_colour[itemp] == hex_colour[itemp])
            counter3++;
        }
      }// end of [i] loop
    
      if(counter2 >= hex_colour.length() - 1)
        std::cout << "\t1.a) " << it->first << " colour (" << it->second << ")";
      if(counter1 == THREE && counter2 < hex_colour.length() - 1) //&& (counter2 < s1.length()))
        std::cout << "\n\t1.b) VERY CLOSE to " << it->first << " colour (" << it->second << ")" << std::endl;  
      if(counter3 == 2)
        std::cout << "\n\t1.c) JUST CLOSE to " << it->first << " colour (" << it->second << ")" << std::endl;
  // preparation for the next do while loop (check control of the next hexadecimal value)
  hex_colour.clear();
  it++;// next map's value, exp: {"antiquewhite","FAEBD7"}
  k++;
  }while(k < NUM_OF_ALL_COLOURS);
 }// END of method


 void neighbour_colours_by_name(std::string &users_colour2)// START of method
 {
  std::map <std::string, std::string>::iterator it = colours_table_hex.begin(); 
  int k = 0;
  
  do
  {
   std::string name_colour = it->first;

    if(users_colour2 == name_colour && k == 0)
      {
        std::cout << "\tyour colour is " << name_colour << " and its hex value is (0x" <<  it->second << ")" << std::endl;
        std::cout << "\n\tand its neighbour colours are: " << std::endl;
          it++;
        std::cout << "\t" << it->first << " (0x" << it->second << ")" << std::endl;
          it = std::next(it, +4);
        std::cout << "\t" << it->first << " (0x" << it->second << ")" << std::endl;
      }
      if(users_colour2 == name_colour && k > 0 && k < 5)
      {
        std::cout << "\tyour colour is " << name_colour << " and its hex value is (0x" <<  it->second << ")" << std::endl;
        std::cout << "\n\tand its neighbour colours are: " << std::endl;
          it++;
        std::cout << "\n\t" << it->first << " (0x" << it->second << ")" << std::endl;
          it = std::next(it, -2);
        std::cout << "\t" << it->first << " (0x" << it->second << ")" << std::endl;
          it = std::next(it, +6);
        std::cout << "\t" << it->first << " (0x" << it->second << ")" << std::endl;
      }
      if(users_colour2 == name_colour && k >= 5 && k < 20)
      {   
        std::cout << "\tyour colour is " << name_colour << " and its hex value is (0x" <<  it->second << ")" << std::endl;
        std::cout << "\n\tand its neighbour colours are: " << std::endl;
          it++;
        std::cout << "\n\t" << it->first << " (0x" << it->second << ")" << std::endl;
          it = std::next(it, -2);
        std::cout << "\t" << it->first << " (0x" << it->second << ")" << std::endl;
          it = std::next(it, +6);
        std::cout << "\t" << it->first << " (0x" << it->second << ")" << std::endl;
          it = std::next(it, -10);
        std::cout << "\t" << it->first << " (0x" << it->second << ")" << std::endl;
          it = std::next(it, k);
      }
      if(users_colour2 == name_colour && k >= 20 && k < 24)
      {
        std::cout << "\tyour colour is " << name_colour << " and its hex value is (0x" <<  it->second << ")" << std::endl;
        std::cout << "\n\tand its neighbour colours are: " << std::endl;
          it++;
        std::cout << "\n\t" << it->first << " (0x" << it->second << ")" << std::endl;
          it = std::next(it, -2);
        std::cout << "\t" << it->first << " (0x" << it->second << ")" << std::endl;
          it = std::next(it, -4);
        std::cout << "\t" << it->first << " (0x" << it->second << ")" << std::endl;
      }
      if(users_colour2 == name_colour && k == 24)
      {
        std::cout << "\tyour colour is " << name_colour << " and its hex value is (0x" <<  it->second << ")" << std::endl;
        std::cout << "\n\tand its neighbour colours are: " << std::endl;
         it = std::next(it, -1);
        std::cout << "\t" << it->first << " (0x" << it->second << ")" << std::endl;
          it = std::next(it, -4);
        std::cout << "\t" << it->first << " (0x" << it->second << ")" << std::endl;
      } 
    name_colour.clear();
   it++;
  k++;
  }while(k < NUM_OF_ALL_COLOURS);
 }// END of method
};//END of class


void table()// START of func
{
 std::cout << "\n\t\t\t\t\t\t\t\t\t\t\t\tTHE COLOUR PALETTE" << std::endl;
  std::cout << "\n| aliceblue #F0F8FF  |";
  std::cout << " antiquewhite #FAEBD7 | ";
  std::cout << ANSI_COLOR_CYAN << "     aqua #00FFFF      | " << ANSI_COLOR_RESET;
  std::cout << ANSI_COLOR_CYAN << "  aquamarine #77FFD4    | " << ANSI_COLOR_RESET;
  std::cout << "  azure #F0FFFF    |" << std::endl;
  std::cout << "|   beige #F5F5DC    | "; 
  std::cout << "   bisque #FFE4C4    | "; 
  std::cout << "    black #000000      | ";
  std::cout << "blandchedalmond #FFEBCD | ";
  std::cout << ANSI_COLOR_BLUE << "   blue #0000FF    | " << ANSI_COLOR_RESET << std::endl;
  std::cout << ANSI_COLOR_MAGENTA << "| blueviolet #8A2BE2 |" << ANSI_COLOR_RESET; 
  std::cout << "     brown #A52A2A    | ";
  std::cout << "   burlywood #DEB887   | ";
  std::cout << ANSI_COLOR_CYAN << "    cadetblue #5F9EA0   | " << ANSI_COLOR_RESET;
  std::cout << ANSI_COLOR_GREEN << "chartreuse #7FFF00 | " << ANSI_COLOR_RESET << std::endl;
  std::cout << "| chocolate #D2691E  | ";
  std::cout << ANSI_COLOR_YELLOW << "    coral #FF7F50    | " << ANSI_COLOR_RESET;
  std::cout << ANSI_COLOR_CYAN << "cornflowerblue #6495ED | " << ANSI_COLOR_RESET;
  std::cout << "    cornsilk #FFF8DC    | ";
  std::cout << ANSI_COLOR_RED << "  crimson #DC143C  | " << ANSI_COLOR_RESET << std::endl;
  std::cout << ANSI_COLOR_CYAN << "|    cyan #00FFFF    | " << ANSI_COLOR_RESET;
  std::cout << ANSI_COLOR_BLUE << "  darkblue #00008B   | " << ANSI_COLOR_RESET;
  std::cout << ANSI_COLOR_CYAN << "   darkcyan #008b8b    | " << ANSI_COLOR_RESET;
  std::cout << ANSI_COLOR_YELLOW << " darkgoldengold #B8860B | " << ANSI_COLOR_RESET;
  std::cout << " darkgray #A9A9A9  | " << std::endl;
}// END of func


int main()// START of MAIN
{
 std::string red, green, blue;// for user's input
 std::string input;// for user's input
 Colours c;// an object c of a class Colours
 
 table();// prints the colours palette

  std::cout << "\n\t Hello, user!\nThis program was made to:" << std::endl;
  std::cout << "\n [1] 1.a) Identify YOUR hexadecimal value and find its name value" << std::endl;
  std::cout << "     OR 1.b,c) how far/ how close your value is to a certain colour value" << std::endl;
  std::cout << "     (if your value is out of pallete's range)" << std::endl;
  std::cout << "\n— 1.b) if the hex you entered differ in even digit," << std::endl;
  std::cout << "  the program will print: <VERY CLOSE to> (colour name)" << std::endl;
  std::cout << "example: the correct is FAEBD7 but user gave F" << ANSI_COLOR_RED << "0" << ANSI_COLOR_RESET << "EBD7" << ", or FAE" << ANSI_COLOR_RED << "C" << ANSI_COLOR_RESET "D7" << ", or FAEBD" << ANSI_COLOR_RED << "3" << ANSI_COLOR_RESET << std::endl; 
  std::cout << "or F" << ANSI_COLOR_RED << "0" << ANSI_COLOR_RESET << "E" << ANSI_COLOR_RED << "C" << ANSI_COLOR_RESET << "D" << ANSI_COLOR_RED << "3" << ANSI_COLOR_RESET << " or any other variation" << std::endl;
  std::cout << "\n— 1.c) if the hex you entered differ in one pair of digits only," << std::endl;
  std::cout << "  the program will print: <JUST CLOSE to> (colour name)" << std::endl;
  std::cout << "example: the correct is FAEBD7 but user gave " << ANSI_COLOR_RED << "C0" << ANSI_COLOR_RESET << "EBD7" << ", or FA" << ANSI_COLOR_RED << "F4" << ANSI_COLOR_RESET "D7" << ", or FAEB" << ANSI_COLOR_RED << "03" << ANSI_COLOR_RESET << std::endl; 
  std::cout << "\n [2] Identify YOUR colour name, find its hexadecimal value and all neighbour colours [cross]" << std::endl;
  std::cout << "\n [3] Convert YOUR hexadecimal value to decimal numeral system" << std::endl;
  std::cout << "     and show neighbour colours according to their decimal value" << std::endl;
  std::cout << "\n\t\t_Enter: 1 or 2 or 3_" << std::endl;
    std::cin >> input;
  
  if(input == "1")
  { 
    std::cout << "\nEnter saturation of RED colour: \n";
      std::cin >> red;
        for(auto &c : red)
          c = toupper(c);
    std::cout << "Enter saturation of GREEN colour: \n";
      std::cin >> green;
        for(auto &c : green)
          c = toupper(c);
    std::cout << "Enter saturation of BLUE colour: \n";
      std::cin >> blue; 
        for(auto &c : blue)
          c = toupper(c);
    c.cold_or_warm(red, green, blue);
  }

  if(input == "2")
  { 
    std::cout << "\nEnter the desired colour NAME: " << std::endl;
      std::cin >> input;
        for(auto &c : input)
          c = tolower(c);
    c.neighbour_colours_by_name(input);
  }

  if(input == "3")
  { 
    std::cout << "\nEnter your HEX number: " << std::endl;
      std::cin >> input;
        for(auto &c : input)
          c = toupper(c);
    c.from_hex_to_dec(input);
  }
return 0;
}// END of MAIN
