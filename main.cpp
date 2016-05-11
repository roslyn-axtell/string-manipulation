/*
 *  Source program for Lab Assignment #5 for CS 2A
 *  Written by Roslyn Axtell, 5/10/16
 */

#include <iostream>
#include <string>
using namespace std;

// method prototypes
char getKeyCharacter();
string getString();
string maskCharacter(string theString, char keyCharacter);
string removeCharacter(string theString, char keyCharacter);
int countKey(string theString, char keyCharacter);

int main()
{
   char keyCharacter;
   string theString;

   keyCharacter = getKeyCharacter();
   theString = getString();

   // allow main to do the output directly
   cout << "\nString with key character, \"" << keyCharacter << "\" masked:\n"
   << maskCharacter(theString, keyCharacter) << endl;

   cout << "\nString with \"" << keyCharacter << "\" removed:\n"
   << removeCharacter(theString, keyCharacter) << endl;

   cout << "\n# of occurrences of key character, \"" << keyCharacter << "\": "
   << countKey(theString, keyCharacter) << endl;
}

// asks for keyCharacter and returns valid input
char getKeyCharacter()
{
   string instructions, input;

   instructions = "Please enter a SINGLE character to act as key: ";

   do
   {
      cout << instructions;
      getline(cin, input);
   }
   while(input.length() != 1);

   // convert to char and return
   return input[0];
}

// asks for theString and returns valid input
string getString()
{
   string instructions, input;
   const int MIN_STR_LEN = 4;
   const int MAX_STR_LEN = 500;

   instructions =
   "Please enter a phrase or sentence >= 4 and <= 500 characters:";

   do
   {
      cout << instructions;
      getline(cin, input);
   }
   while(input.length() <= MIN_STR_LEN || input.length() >= MAX_STR_LEN);

   return input;
}
string maskCharacter(string theString, char keyCharacter)
{
   string myString = "";

   for(int k = 0; k < theString.length(); k++)
   {
      if(theString[k] == keyCharacter)
         myString += "!";
      else
         myString += theString[k];
   }
   return myString;
}
string removeCharacter(string theString, char keyCharacter)
{
   string myString = "";

   for(int k = 0; k < theString.length(); k++)
   {
      if(theString[k] != keyCharacter)
         myString += theString[k];
   }
   return myString;
}
int countKey(string theString, char keyCharacter)
{
   int numKeyChar = 0;

   for(int k = 0; k < theString.length(); k++)
      if(theString[k] == keyCharacter)
         numKeyChar++; // adds 1 to keyCharacter count

   return numKeyChar;
}
/*
 ====== run 1 ===================================================================
 Please enter a SINGLE character to act as key: 5
 Please enter a phrase or sentence >= 4 and <= 500 characters:jfkdjfe fjiefjd jieof fjdiso

 String with key character, "5" masked:
 jfkdjfe fjiefjd jieof fjdiso

 String with "5" removed:
 jfkdjfe fjiefjd jieof fjdiso

 # of occurrences of key character, "5": 0
 Program ended with exit code: 0

 ====== run 2 ===================================================================
 Please enter a SINGLE character to act as key: fdk
 Please enter a SINGLE character to act as key: E$
 Please enter a SINGLE character to act as key: $
 Please enter a phrase or sentence >= 4 and <= 500 characters:$4#fr T5$ fd$ $rs $rt $rd opcode blah $$r

 String with key character, "$" masked:
 *4#fr T5* fd* *rs *rt *rd opcode blah **r

 String with "$" removed:
 4#fr T5 fd rs rt rd opcode blah r

 # of occurrences of key character, "$": 8
 Program ended with exit code: 0

 ====== run 3 ===================================================================
 Please enter a SINGLE character to act as key: t
 Please enter a phrase or sentence >= 4 and <= 500 characters:
 Please enter a phrase or sentence >= 4 and <= 500 characters:43
 Please enter a phrase or sentence >= 4 and <= 500 characters:t rte jfdk te jfkd tkj ftjek ttssefc

 String with key character, "t" masked:
 * r*e jfdk *e jfkd *kj f*jek **ssefc

 String with "t" removed:
 re jfdk e jfkd kj fjek ssefc

 # of occurrences of key character, "t": 7
 Program ended with exit code: 0

 ====== run 4 ===================================================================
 Please enter a SINGLE character to act as key: i
 Please enter a phrase or sentence >= 4 and <= 500 characters:this is so fun!!! my methods really work!!

 String with key character, "i" masked:
 th*s *s so fun!!! my methods really work!!

 String with "i" removed:
 ths s so fun!!! my methods really work!!

 # of occurrences of key character, "i": 2
 Program ended with exit code: 0
 
 */


