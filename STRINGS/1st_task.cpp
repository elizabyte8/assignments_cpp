#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <iterator>
#include <map>
#include <algorithm>

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
 std::string temporary;
 std::string vowels;
 std::string consonants;
 std::vector <std::string> splitted_words;
 std::string splitted_words2;
 std::vector <std::string> strings;
 std::vector <std::string>::iterator it;


 String()// START of default constructor
 {
  first    =   "About 75% of our brain is made up of water.";
  second   =   "The human brain has the ability to store a thousand terabytes of information.";
  third    =   "The human brain has about 100 billion neurons.";
  fourth   =   "Artificial neural networks mimic the central nervous system. However, these networks take 40 minutes to process what the human brain processes in one second.";
  fifth    =   "There are about 160,000 km of blood vessels in the human brain. Their length is enough to make the rotation of the Earth four times.";
  sixth    =   "GRAY ESSENCE: This is the name of the neurons responsible for speech, memory and muscle control.";
  seventh  =   "While resting, the human brain produces enough energy to light a 25 watt light bulb.";
  eighth   =   "Scientists have concluded that the human brain reaches full maturity in our 25 years.";
  ninth    =   "The lowest speed at which our brain processes information is 418 km / h.";
  tenth    =   "The human brain never loses its ability to learn and change. This is due to its elasticity and the fact that it constantly creates new synapses.";
  vowels   =   "aeiouy";
  consonants = "bcdfghjklmnpqrstvwxz";
  strings = {first, second, third, fourth, fifth, sixth, seventh, eighth, ninth, tenth};
 }// END of constructor


 void sorted()// START of method
 {// prints strings by sorted size of strings (from least to biggest)
  std::cout << std::endl << "\n\t\t\t\t1__PRINTS IN ASCENDING ORDER\n" << std::endl;
  for(decltype(strings.size()) i = 0; i < strings.size(); i++)
    for(decltype(strings.size()) j = i + 1; j < strings.size(); j++) 
      if(strings[i].size() > strings[j].size())
      {
        temporary = strings[j];
        strings[j] = strings[i];
        strings[i] = temporary;
      }
  for(auto const s : strings)
  std::cout << s << std::endl;
 }// END of method


 int *letters(int index)// START of method
 {
  static int number_of[2] = {0,0};// returns both vowels and consonants

  it = std::next(strings.begin(), index);// iterator == index
  temporary = *it;// new string has iterator's value (string's characters)

  for(int i = 0; i < temporary.size(); i++)
  {
    for(int j = 0; j < vowels.size(); j++)
      if(temporary[i] == vowels[j])
        number_of[0]++;

    for(int j = 0; j < consonants.size(); j++)
      if(temporary[i] == consonants[j])
        number_of[1]++;
  }
 return number_of;
 }// END of method


 void dublicate()// START of method
 { 
  std::string word = "";   
  std::map <std::string, int> Map;
  int num;

  std::cout << std::endl << "\n\t\t\t\t3__PRINTS DUBLICATE WORDS\n" << std::endl;
    for(decltype(strings.size()) k = 0; k < strings.size(); k++)
    { 
      for (auto x : strings[k])// picks words from each string  
      { 
        if (x == ' ') 
        { 
          splitted_words.push_back(word);// collects words separately
          word = ""; 
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
      }// end of dublicate words control [i] & [j]    
    }// end of picking words from each string & collecting them to vector [x]

  for(auto const &c : splitted_words)
    splitted_words2.append(c);// fills words into array of letters (without spaces)
    // for the func number_of_all_letters(), which counts occurrence of each letter in all 10 strings

  for(auto const &m : Map)
    std::cout << "The " << k + 1 << " string has repeated word << "<< m.first << " >> and it's repeated " << m.second << " times." << std::endl;
      
 splitted_words.clear();// deletes items for new loop(new string)
 Map.clear();// deletes items for new loop(new string)
  }// end of [k] loop    
 }// END of method


 void number_of_all_letters()// START of func
 {
  int counter2 = 1;
  
  std::cout << std::endl << "\n\t\t\t\t4__PRINTS DUBLICATE NUMBER OF EVERY LETTER IN ALL STRINGS\n" << std::endl;
    for(auto i = splitted_words2.begin(); i < splitted_words2.end(); i++)
    {   
      for(auto j = i + 1; j < splitted_words2.end(); j++)
      {     
        if(*i == *j)
        {         
          counter2++; 
          splitted_words2.erase(j);    
        }     
      }
                      
      std::cout <<"The letter /symbol < " << *i << " > is repeated " << counter2 << " times" << std::endl;
      counter2 = 1;

      splitted_words2.erase(i); 
    }// end of [i] loop
 }// END of func
};// END of class


int main()// START of MAIN
{
 String s;// initializes an object of a class str and its default constructor

 //__1st_subtask_segment

 s.sorted();// prints in ascending order according to sizes of strings

//__2nd_subtask_segment
 
 std::cout << std::endl << "\n\t\t\t\t2__PRINTS NUMBER OF VOWELS AND CONSONANTS\n" << std::endl;
 for(decltype(s.strings.size()) i = 0; i < s.strings.size(); i++) 
 {
  std::cout << "The " << i + 1 << " string has the following letters:" << std::endl;
  std::cout << "\tnumber of vowels: " << *(s.letters(i)) << std::endl;
  std::cout << "\tnumber of consonants: " << *(s.letters(i))+1 << std::endl;
  std::cout << std::endl;
 }
 
 //__3rd_subtask_segment

 s.dublicate();

 //__4rth_subtask_segment

 s.number_of_all_letters();
return 0;
}// END of MAIN
