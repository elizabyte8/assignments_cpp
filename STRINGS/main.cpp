/*static std::string first =   "Το 75% περίπου του εγκεφάλου μας αποτελείται από νερό.\n";
static std::string second =  "Ο ανθρώπινος εγκέφαλος έχει την δυνατότητα να αποθηκεύση χίλια terabytes πληροφοριών.\n";
static std::string third =   "Ο ανθρώπινος εγκέφαλος έχει περίπου 100 δυσεκατομμύρια νευρώνες.\n";
static std::string fourth =  "Τα τεχνητά νευρωνικά δίκτυα μιμούνται το κεντρικό νευρικό σύστημα. Ωστόσο τα δίκτυα αυτά χρειάζονται 40 λεπτά να επεξεργαστούν αυτό που ο ανθρώπινος εγκέφαλος επεξεργάζεται σε ένα δευτερόλεπτο.\n";
static std::string fifth =   "Υπάρχουν περίπου 160.000 χλμ. αιμοφόρων αγγείων στον ανθρώπινο εγκέφαλο. Το μήκος τους επαρκεί για να κάνει το γύρο της Γης τέσσερεις φορές.\n";
static std::string sixth =   "ΦΑΙΆ ΟΥΣΊΑ: Έτσι ονομάζονται οι νευρώνες που είναι υπεύθυνοι για την ομιλία, την μνήμη και τον έλεγχο των μυών.\n";
static std::string seventh = "Όταν αναπαύεται ο ανθρώπινος εγκέφαλος παράγει αρκετή ενέργεια για να ανάψει μια λάμπα 25 watt.\n";
static std::string eighth =  "Οι επιστήμονες έχουν έχουν καταλήξει στο συμπέρασμα ότι ο ανθρώπινος εγκέφαλος φτάνει στην πλήρη ωριμότητά στα 25 μας χρόνια.\n";
static std::string ninth =   "Η χαμηλότερη ταχύτητα με την οποία επεξεργάζεται ο εγκέφαλος μας την πληροφορία είναι 418 χλμ./ωρα.\n";
static std::string tenth =   "Ο εγκέφαλος του ανθρώπου δεν χάνει ποτέ την οικανότητά του να μαθαίνει και να αλλάζει. Αυτό οφείλεται στην ελαστικότητά του και στο γεγονός ότι δημιουργεί συνεχώς νέες συνάψεις.\n";
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>

const int THREE = 3;// assignment's 5th)subtask's requirement
const int LEAST = 1;// assignment's 6th)subtask's requirement
const int BIGGEST = 15;// assignment's 6th)subtask's requirement

class String// START of class
{
  public:
//__data segment

 int counter;
 std::string first;
 std::string second;
 std::string third;
 std::string fourth;
 std::string fifth;
 std::string sixth;
 std::string seventh;
 std::string eighth; 
 std::string ninth;
 std::string tenth;
 std::string vowels; 
 std::string temporary;
 std::string consonants; 
 std::string all_characters;
 std::vector <std::string> strings;// dynamic array of strings
 std::vector <std::string>::iterator it;// pointer for array & strings
 std::vector <std::string> splitted_words;

//__code_segment

 String()// START of default constructor
 {
  first    =   "1. About 75% of our brain is made up of water . ";
  second   =   "4. The human brain has the ability to store a thousand terabytes of information . ";
  third    =   "2. The human brain has about 100 billion neurons . ";
  fourth   =   "10. Artificial neural networks mimic the central nervous system. However, these networks take 40 minutes to process what the human brain processes in one second . ";
  fifth    =   "8. There are about 160,000 km of blood vessels in the human brain. Their length is enough to make the rotation of the Earth four times . ";
  sixth    =   "7. GRAY ESSENCE: This is the name of the neurons responsible for speech, memory and muscle control . ";
  seventh  =   "5. While resting, the human brain produces enough energy to light a 25 watt light bulb . ";
  eighth   =   "6. Scientists have concluded that the human brain reaches full maturity in our 25 years . ";
  ninth    =   "3. The lowest speed at which our brain processes information is 418 km / h . ";
  tenth    =   "9. The human brain never loses its ability to learn & change. This is due to its elasticity and the fact that it constantly creates new synapses . ";
  vowels   =   "aeiouy";
  consonants = "bcdfghjklmnpqrstvwxz";
  strings = {first, second, third, fourth, fifth, sixth, seventh, eighth, ninth, tenth};
 }// END of constructor
 

 void sorted()// START of method
 {// prints strings by sorted size of strings (from least to biggest)
  std::cout << std::endl << "\n\t\t\t\t1_PRINTS IN ASCENDING ORDER\n" << std::endl;
  for(decltype(strings.size()) i = 0; i < strings.size(); i++)
    for(decltype(strings.size()) j = i + 1; j < strings.size(); j++) 
      if(strings[i].size() > strings[j].size())
      {
        temporary = strings[j];
        strings[j] = strings[i];
        strings[i] = temporary;
      }
  for(auto const &string : strings)
  std::cout << string << std::endl;
 }// END of method


 int *letters(int index)// START of method
 {
  int number_of[2] = {0,0};// returns both vowels and consonants

  it = std::next(strings.begin(), index);// iterator == index
  temporary = *it;// new string has iterator's value (string's characters)

  for(auto i = 0; i <= temporary.size(); i++)
  {
    for(auto j = 0; j < vowels.size(); j++)
      if(temporary[i] == vowels[j])
        number_of[0]++;

    for(auto j = 0; j <= consonants.size(); j++)
      if(temporary[i] == consonants[j])
        number_of[1]++;
  }
 return number_of;
 }// END of method


 void dublicate(std::vector <std::vector <std::string>> &_2d_vec_of_strings)// START of method
 { 
  std::cout << std::endl << "\n\t\t\t\t3_PRINTS DUBLICATE WORDS\n" << std::endl;
  
  std::map <std::string, int> Map;
  std::string word = "";   
  it = splitted_words.begin();
  
    for(decltype(strings.size()) k = 0; k < strings.size(); k++)
    { 
      for (auto x : strings[k])// picks words from each string  
      { 
        if (x == ' ') 
        { 
          splitted_words.push_back(word);// collects words separately
          word = "";// "clears" string for a new word
        } 
          else
            word = word + x;  

      for(decltype(splitted_words.size()) i = 0; i < splitted_words.size(); i++)     
      {           
        for(decltype(splitted_words.size()) j = i + 1; j < splitted_words.size(); j++)
        {   
          if(splitted_words[i] == splitted_words[j])
          { 
            counter++;         
            Map[splitted_words[i]] = counter;
          }                     
        } counter = 1;   
      }// end of dublicate words control [i] & [j] loops 
      }// end of picking words from each string & collecting them to vector [x] loop
    for(auto const &m : Map)
    std::cout << "The " << k + 1 << " string has repeated word << "<< m.first << " >> and it's repeated " << m.second << " times." << std::endl;

    // for the 4th subtask
    for(auto const &c : splitted_words)
     all_characters.append(c);// fills words into array of letters (without spaces)
    // for the func number_of_all_letters(), which counts occurrence of each letter in all 10 strings
    
    // for the 5th subtask
    for(auto i = 0; i < splitted_words.size(); i++)
    _2d_vec_of_strings[k].push_back(splitted_words[i]);

    splitted_words.clear();// deletes items for new loop (new string)
    Map.clear();// deletes items for new loop (new string)
  }// end of [k] loop  
 }// END of method


 void number_of_all_letters()// START of method
 {
  std::cout << std::endl << "\n\t\t\t\t4_PRINTS DUBLICATE NUMBER OF EVERY LETTER IN ALL STRINGS\n" << std::endl;
  std::string::iterator it1;
    for(auto i = 0; i < all_characters.size(); i++)
    {
     counter++; 
      for(auto j = i + 1; j < all_characters.size(); j++)
      {
        it1 = std::next(all_characters.begin(),j);
        if(all_characters[i] == all_characters[j])
        {         
          all_characters.erase(it1);        
          counter++; 
        }     
      }                      
      std::cout <<"The letter /symbol < " << all_characters[i] << " > is repeated " << counter << " times" << std::endl;
     counter = 0;   
    }// end of [i] loop
 }// END of method


 void enter_word(std::vector <std::vector<::std::string>> &_2d_vec_of_strings, std::string &input)// START of method
 { 
  std::cout << std::endl << "\n\t\t\t\t5_PRINTS A WHOLE STRING INCLUDED A GIVEN WORD\n" << std::endl;

  do
  {
   if(input.size() > THREE)
   {  
    // checks user's input and strings' content to print the result
    for(auto  i = 0; i < _2d_vec_of_strings.size(); i++ )
    { 
      for (auto j = 0; j < _2d_vec_of_strings[i].size(); j++ )
      { 
        if(input == _2d_vec_of_strings[i][j])
          for(auto string_ : _2d_vec_of_strings[i]) 
          {  
            std::cout <<" ";
            for(auto char_ : string_)
            std::cout << char_;
          }
      } std::cout << std::endl;
    }// end of [i] loop
   }//end of if

    std::cout << "\n\t!_In case you wish to go back, enter < . > (dot)_!" << std::endl;   
    std::cout << "\tEnter a word (it must be bigger than 3 letters)" << std::endl;
    std::cin >> input;      
  
  }while((input != ".") && (input.size() > THREE));// end of while loop
 }//END of method           


void enter_number(std::vector<std::vector<std::string>> &_2d_vec_of_strings, int &int_input)// START of method
{
 std::cout << std::endl << "\n\t\t\t\t6_PRINTS ALL WORDS FROM ALL STRINGS WITH THE GIVEN SIZE\n" << std::endl;
 std::vector <std::string>::iterator it1; 

 do
 {
  if(int_input == THREE)
  {  
    std::cout << "\n\n\tYOU ENTERED 3 OR LESS, THE PROGRAM WILL DELETE ALL WORDS WITH 3 LETTERS FROM A\n";
    std::cout << "\tTHE STRING WITHOUT THOSE WORDS WILL LOOK LIKE: ->\n" << std::endl;

    for(auto i = 0; i < _2d_vec_of_strings.size(); i++ )
    { 
      for (auto j = 0; j < _2d_vec_of_strings[i].size(); j++)
      {
        it1 = next(_2d_vec_of_strings[i].begin(), j);
          if(_2d_vec_of_strings[i][j].size() == int_input)
            _2d_vec_of_strings[i].erase(it1);// deletes word with 3 letters
      }// end of [j] loop  
    }// end of [i] loop
    // start of loops to print the result ->
      for(auto i = 0; i < _2d_vec_of_strings.size(); i++ )
        for(auto string_ : _2d_vec_of_strings[i])
        {
          std::cout <<" ";
            for(auto char_ : string_)
              std::cout << char_;
        } std::cout << std::endl;
  }// end of first MAIN if (which excludes 3-lengthed words)
      
  if((int_input > THREE) && (int_input <= BIGGEST))
  {  
    std::cout << "\n\n\tYOU ENTERED MORE THAN 3 OR LESS THAN/EQUAL TO 15" << std::endl;
    std::cout << "\tSO, THE PROGRAM WILL ONLY PRINT THOSE STRINGS WHICH INLUDE WORDS OF THAT SIZE" << std::endl;;

    for(auto i = 0; i < _2d_vec_of_strings.size(); i++)
    {
      for(auto j = 0; j < _2d_vec_of_strings[i].size(); j++)
      {
        it1 = _2d_vec_of_strings[i].begin();
        if(_2d_vec_of_strings[i][j].size() == int_input)
        {
          std::cout << std::endl;   
        // start of loops to print the result ->
          for(auto const string_ : _2d_vec_of_strings[i])
          {
            std::cout <<" ";
              for(auto const char_ : string_)
                std::cout << char_;      
          } std::cout << std::endl; 
        }//end of nested if 
        it1 = next(_2d_vec_of_strings[i].begin(), j);
      }// end of [j] loop
    }// end of [i] loop
  }// end of second MAIN if 

    std::cout << "\n\t!_In case you wish to go back, enter < 0 > (zero)_!" << std::endl;
    std::cout << "\tEnter a number (ONLY in a range of 1 to 15) : ";
    std::cin >> int_input;

  }while ((int_input != 0) && int_input <= BIGGEST);
 }// END of method
};// END of class


int identify_input(const std::string &input)// START of func
{
  std::string alphabet{"abcdefghijklmnopqrstuvwxyz"};
  std::string digits{"1234567890"};
  std::string help{"help"};
  std::string dot{"."};
  int ret, help_counter = 0;

  for(auto i = 0; i < alphabet.size(); i++)
    if(input[0] == alphabet[i])
      ret = 0;// if input is a string

  for(auto i = 0; i < digits.size(); i++)
    if(input[0] == digits[i])
      ret = 1;// if input is a number

   for(auto i = 0; i < input.size(); i++)
    {
      for(auto j = 0; j < help.size(); j++)
      {
        if(input[i] == help[j])
          help_counter++;
        if(help_counter == 3)
          ret = -1;// if input is "help"
      }
    }

  if(input[0] == dot[0])
    ret = 2;// if input is < . > dot symbol

  if(ret != 0 && ret != 1 && ret != -1 && ret != 2)
    ret = 3;// if input is out of required range

 return ret;
}// END of func


void help(String s)// START of func
{
 std::cout << std::endl << std::endl;
 std::cout << std::endl << "\n\t\t\t\t8_HELP\n" << std::endl;
 std::cout << "\n\tA TOPIC FROM THE FIRST PART OF ASSIGNMENT\n\n";
   
 for(auto const & strings_ : s.strings)
  for(auto const & string : strings_)
    std::cout << string;

 std::cout << "\n\n\tA TOPIC FROM THE SECOND PART OF ASSIGNMENT\n";

 std::cout << "\nSince 1945, scientists have known that a human's brain consists of 75% of water.\n";
 std::cout << "Good hydration of the brain is essential.\n";
 std::cout << "Dehydration of only 2% can affect a person's ability to perform tasks related to attention, memory and motor skills.\n";
 std::cout << "Cholesterol is a type of fat that is often considered bad for a human's health.\n";
 std::cout << "It is true that consumption of too much cholesterol is bad for the heart.\n"; 
 std::cout << "However, many people are not aware of the fact that cholesterol plays important role in a human's brain.\n";

 std::cout << "\n\n\tTHE PROGRAM IS DEDICATED TO\n";
 std::cout << " strings\n";
 std::cout << " STL (Standart Template Library)\n";
 std::cout << " algorithms\n";
 std::cout << "\n\n\tTHE PROGRAM IS WRITTEN TO\n";
 std::cout << " print all strings (from FIRST PART of the assignment) in ASCENDING order\n";
 std::cout << " print NUMBER of vowels and consonants in every string\n";
 std::cout << " print DUBLICATE words in every string\n";
 std::cout << " print ACCURACY of every letter in the entire topic (all strings)\n";
 std::cout << " print a whole string which includes a given word FROM A USER_: \n";
 std::cout << " print all words from all strings with the given size FROM A USER_: \n";
}// END of func


int main()// START of MAIN
{
// |__FIRST_PART_OF_THE_ASSIGNMENT__|
 
 String s;// initializes an object of a class String and its default constructor
 static int size = s.strings.size();
 static std::vector <std::vector <std::string>> _2d_vec_of_strings(size);
 
 //__1st_subtask_of_FIRST_TASK_segment
 s.sorted();// prints in ascending order according to sizes of strings

 //__2nd_subtask_of_FIRST_TASK_segment
 std::cout << std::endl << "\n\t\t\t\t2_PRINTS NUMBER OF VOWELS AND CONSONANTS\n" << std::endl;
 for(decltype(s.strings.size()) i = 0; i < s.strings.size(); i++) 
 {
  std::cout << "The " << i + 1 << " string has the following letters:" << std::endl;
  std::cout << "\tnumber of vowels: " << *(s.letters(i)) << std::endl;
  std::cout << "\tnumber of consonants: " << *(s.letters(i)+1) << std::endl;
  std::cout << std::endl;
 }
  
 //__3rd_subtask_of_FIRST_TASK_segment
 s.dublicate(_2d_vec_of_strings);

 //__4rth_subtask_of_FIRST_TASK_segment
 s.number_of_all_letters();

// |__SECOND_PART_OF_THE_ASSIGNMENT__|
 //__1-2-3-4_subtasks_of_SECOND_TASK_segment
 std::string input;
 int int_input;// for atoi() func
 bool terminate = false;// for do while loop

 do
 {
  std::cout << "\n\nNOW\n\tenter a word (it must be bigger than 3 letters)" << std::endl;
  std::cout << "\tor enter a number (ONLY in a range of 1 to 15)" << std::endl;
  std::cout << "\tor write < help > for more information" << std::endl;
  std::cout << "\tor < . > (dot) to quit the program" << std::endl;
  std::cout << "\nyour choice is: ";  
    std::cin >> input;

    if(identify_input(input) == -1)
    help(s);

    if(identify_input(input) == 0)
      s.enter_word(_2d_vec_of_strings, input);

    if(identify_input(input) == 1)
      { 
        int_input = std::stoi(input);
        s.enter_number(_2d_vec_of_strings, int_input);
      }

    if(identify_input(input) == 2)
    {
    std::cout << "\n\t\t\t\t7_DO YOU REALLY WANT TO QUIT?" << std::endl;
    std::cout <<"\n\t[y] to quit completely/ [n] to go back to menu " << std::endl;
      std::cin >> input;

      if(input == "y")
      {
        std::cout << "\nThank you! Hope to see you soon." << std::endl;
        std::cout << "Goodbye! ~" << std::endl;
        terminate = true;
      }
        else
          continue;
    }
      else
      {
        std::cout << "\nPlease, make sure you entered number/ word/ HELP/ < . >symbol" << std::endl;
        std::cin >> input;
      }
 }while(!terminate);

return 0;
}// END of MAIN
