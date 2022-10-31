#include <iostream>
#include <string>
using namespace std;

char getKeyCharacter()
{
   string keyCharacter_USERINPUT;
   const int NUMBEROFKEYCHARACTERS = 1;
   
   cout << "Please enter a SINGLE character to act as key : ";
   getline(cin, keyCharacter_USERINPUT);
   unsigned numberOfCharacters = keyCharacter_USERINPUT.length();
   while ((numberOfCharacters < NUMBEROFKEYCHARACTERS) ||
          (numberOfCharacters > NUMBEROFKEYCHARACTERS))
   {
      cout << "Please enter a SINGLE character to act as key : ";
      getline(cin, keyCharacter_USERINPUT);
      numberOfCharacters = keyCharacter_USERINPUT.length();
   }
   return keyCharacter_USERINPUT[0];
}

string getString()
{
   string sentencePhrases_USERINPUT;
   const int MIN_NUMBEROFPHRASECHARACTERS = 6;
   const int MAX_NUMBEROFPHRASECHARACTERS = 160;

   cout << endl;
   cout << "Please enter a phrase or a sentence that is between"
        << " 6 characters and 160 characters. : " << endl;
   getline(cin, sentencePhrases_USERINPUT);
   unsigned numberOfPhraseCharacters = sentencePhrases_USERINPUT.length();

   while ((numberOfPhraseCharacters < MIN_NUMBEROFPHRASECHARACTERS) ||
      (numberOfPhraseCharacters > MAX_NUMBEROFPHRASECHARACTERS ))
   {
      cout << "Please enter a phrase or a sentence that is between"
           << " 6 characters and 160 characters. : " << endl;
      getline(cin, sentencePhrases_USERINPUT);
      numberOfPhraseCharacters = sentencePhrases_USERINPUT.length();
   }
   return sentencePhrases_USERINPUT;
}

string maskCharacter(string theString, char keyCharacter)
{
   string maskedString = "";
   int stringSize;
   stringSize = theString.length();

   for (int i = 0; i < stringSize; i++)
   {
      if (theString[i] == keyCharacter)
         maskedString += "#";
      else
         maskedString += theString[i];
   }
   return maskedString;
}

string removeCharacter(string theString, char keyCharacter)
{
   string removedString = "";
   int stringSize;
   stringSize = theString.length();

   for (int i = 0; i < stringSize; i++)
   {
      if (theString[i] == keyCharacter)
         removedString += "";
      else
         removedString += theString[i];
   }
   return removedString;
}

int countKey(string theString, char keyCharacter)
{
   int keyCount = 0;
   int stringSize;
   stringSize = theString.length();

   for (int i = 0; i < stringSize; i++)
   {
      if (theString[i] == keyCharacter)
         keyCount++;
   }
   return keyCount;
}

int main()
{
   string stringSentence, maskedString, removedString;
   int keyCount;
   char key;
   key = getKeyCharacter();
   stringSentence = getString();
   maskedString=maskCharacter(stringSentence, key);
   removedString = removeCharacter(stringSentence, key);
   keyCount = countKey(stringSentence, key);

   cout << endl;
   cout << "String with key character '" << key << "' masked: "
        << maskedString << endl << endl;

   cout << "String with '" << key << "' removed: "
        << removedString << endl << endl;

   cout << "# of occurrences  of key character '" << key << "' : "
        << keyCount << endl;

   
   return 0;
}

/*-------------------------------Paste of Run#1 ----------------------------------
Please enter a SINGLE character to act as key : F

Please enter a phrase or a sentence that is between 6 characters and 160 characters. :
FASTER FISHING FALLING FELL SELF-DEFENSIVE DEFINE DEFINITION FLOWN FLY

String with key character 'F' masked: #ASTER #ISHING #ALLING #ELL SEL#-DE#ENSIVE DE#INE DE#INITION #LOWN #LY

String with 'F' removed: ASTER ISHING ALLING ELL SEL-DEENSIVE DEINE DEINITION LOWN LY

# of occurrences  of key character 'F' : 10

Press any key to close this window . . .


-------------------------------------------------------------------------------*/

/*---------------------Paste of Run#2(Invalid Input Key) -------------------------
Please enter a SINGLE character to act as key : HEY
Please enter a SINGLE character to act as key : HE
Please enter a SINGLE character to act as key : H

Please enter a phrase or a sentence that is between 6 characters and 160 characters. :
HEY HOW ARE YOU,HOWARD?

String with key character 'H' masked: #EY #OW ARE YOU,#OWARD?

String with 'H' removed: EY OW ARE YOU,OWARD?

# of occurrences  of key character 'H' : 3

Press any key to close this window . . .

-------------------------------------------------------------------------------*/

/*---------------------Paste of run #3(Invalid Input Phrase)---------------------
Please enter a SINGLE character to act as key : o

Please enter a phrase or a sentence that is between 6 characters and 160 characters. :
o
Please enter a phrase or a sentence that is between 6 characters and 160 characters. :
ov
Please enter a phrase or a sentence that is between 6 characters and 160 characters. :
ove
Please enter a phrase or a sentence that is between 6 characters and 160 characters. :
over
Please enter a phrase or a sentence that is between 6 characters and 160 characters. :
overcome

String with key character 'o' masked: #verc#me

String with 'o' removed: vercme

# of occurrences  of key character 'o' : 2

Press any key to close this window . . .

--------------------------------------------------------------------------------*/

/*-------------------------Paste of run #4(No key found)--------------------------
Please enter a SINGLE character to act as key : L

Please enter a phrase or a sentence that is between 6 characters and 160 characters. :
love living life leash lover lie like liked literally length

String with key character 'L' masked: love living life leash lover lie like liked literally length

String with 'L' removed: love living life leash lover lie like liked literally length

# of occurrences  of key character 'L' : 0

Press any key to close this window . . .

--------------------------------------------------------------------------------*/

/*---------------------Paste of run #5 (Long sentences > 160)--------------------
Please enter a SINGLE character to act as key : Purchase
Please enter a SINGLE character to act as key : purchase
Please enter a SINGLE character to act as key : Purchasing
Please enter a SINGLE character to act as key : purchased
Please enter a SINGLE character to act as key : p

Please enter a phrase or a sentence that is between 6 characters and 160 characters. :
Mark Zuckerberg had done a great job in launching Facebook on laptops, which allows me to communicate with people such as my family, friends, classmates, lecturers, and others. I am not only awestruck with his creation, but at the same time, I am also surprised that he used a laptop to write codes to build the Facebook application (Kamboj). I bet there are not many people who are aware of it because many still argue that writing codes and programming can only be done on a desktop computer.
Please enter a phrase or a sentence that is between 6 characters and 160 characters. :
Mark Zuckerberg had done a great job in launching Facebook on laptops, which allows me to communicate with people such as my family, friends, classmates, lecturers, and others. I am not only awestruck with his creation, but at the same time, I am also surprised that he used a laptop to write codes to build the Facebook application (Kamboj). I bet there are not many peo
Please enter a phrase or a sentence that is between 6 characters and 160 characters. :
Mark Zuckerberg had done a great job in launching Facebook on laptops, which allows me to communicate with people such as my family, friends, classmates, lecturers, and other.
Please enter a phrase or a sentence that is between 6 characters and 160 characters. :
Mark Zuckerberg had done a great job in launching Facebook on laptops, which allows me to communicate with peopl

String with key character 'p' masked: Mark Zuckerberg had done a great job in launching Facebook on la#to#s, which allows me to communicate with #eo#l

String with 'p' removed: Mark Zuckerberg had done a great job in launching Facebook on latos, which allows me to communicate with eol

# of occurrences  of key character 'p' : 4

Press any key to close this window . . .

--------------------------------------------------------------------------------*/

/*--------------------------Paste of run #5(Number input)-------------------------
Please enter a SINGLE character to act as key : 1

Please enter a phrase or a sentence that is between 6 characters and 160 characters. :
1+2+3+4+5+6+11+12+13+234441=

String with key character '1' masked: #+2+3+4+5+6+##+#2+#3+23444#=

String with '1' removed: +2+3+4+5+6++2+3+23444=

# of occurrences  of key character '1' : 6

Press any key to close this window . . .

-------------------------------------------------------------------------------*/
