#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class DateProfile
{
private:
   int romance;
   int finance;
   char gender;
   char searchGender;
   string name;

public:
   static const char DEFAULT_GEND;
   static const char DEFAULT_SEARCH_GEND;
   static const int MIN_DIFFERENCE;
   static const int MIN_ROMANCE;
   static const int MAX_ROMANCE;
   static const int MIN_FINANCE;
   static const int MAX_FINANCE;
   static const int MIN_NAME_LEN;
   static const int MAX_NAME_LEN;
   static const int DEFAULT_ROMANCE;
   static const int DEFAULT_FINANCE;
   static const string DEFAULT_NAME;

   DateProfile();
   DateProfile(char gdr, char searchGender, int romance, int finance,
     string profileName);

   char getGender();
   char getSearchGender();
   int getRomance();
   int getFinance();
   string getName();

   bool setGender(char gdr);
   bool setSearchGender(char searchGender);
   bool setRomance(int romance);
   bool setFinance(int finance);
   bool setName(string profileName);

   void setAll(char gdr, char searchGender, int romance, int finance,
     string profileName);
   void setDefaults();

   double fitValue(DateProfile partner);

private:
   double determineGenderFit(DateProfile partner);
   double determineRomanceFit(DateProfile partner);
   double determineFinanceFit(DateProfile partner);

};

const int  DateProfile::MIN_DIFFERENCE = 1;
const int  DateProfile::MIN_ROMANCE = 0;
const int  DateProfile::MAX_ROMANCE = 10;
const int  DateProfile::MIN_FINANCE = 0;
const int  DateProfile::MAX_FINANCE = 10;
const int  DateProfile::MIN_NAME_LEN = 3;
const int  DateProfile::MAX_NAME_LEN = 20;
const int  DateProfile::DEFAULT_ROMANCE = 5;
const int  DateProfile::DEFAULT_FINANCE = 5;
const char DateProfile::DEFAULT_GEND = 'M';
const char DateProfile::DEFAULT_SEARCH_GEND = 'F';
const string DateProfile::DEFAULT_NAME = "Steve Nobody";

void displayTwoProfiles(DateProfile profile1, DateProfile profile2);

int main()
{
   DateProfile applicant1, applicant2, applicant3, applicant4;
   applicant1.setAll('M', 'F', 2, 5, "Sarah Somebody" );
   applicant3.setAll('F', 'F', 3, 5, "Jane Peabody");
   applicant4.setAll('F', 'M', 2, 6, "Helen Anybody");

   displayTwoProfiles(applicant1, applicant1);
   displayTwoProfiles(applicant1, applicant2);
   displayTwoProfiles(applicant1, applicant3);
   displayTwoProfiles(applicant1, applicant4);
   cout << endl << endl;

   displayTwoProfiles(applicant2, applicant1);
   displayTwoProfiles(applicant2, applicant2);
   displayTwoProfiles(applicant2, applicant3);
   displayTwoProfiles(applicant2, applicant4);
   cout << endl << endl;

   displayTwoProfiles(applicant3, applicant1);
   displayTwoProfiles(applicant3, applicant2);
   displayTwoProfiles(applicant3, applicant3);
   displayTwoProfiles(applicant3, applicant4);
   cout << endl << endl;

   displayTwoProfiles(applicant4, applicant1);
   displayTwoProfiles(applicant4, applicant2);
   displayTwoProfiles(applicant4, applicant3);
   displayTwoProfiles(applicant4, applicant4);
   
}

void displayTwoProfiles(DateProfile profile1, DateProfile profile2)
{
   cout << "Fit between " << profile1.getName() << " and "
      << profile2.getName() << ":    " << profile1.fitValue(profile2) << endl;
}

DateProfile::DateProfile()
{
   setDefaults();
}

DateProfile::DateProfile(char gdr, char searchGender,int romance,
   int finance, string profileName)
{
   setAll(gdr, searchGender, romance, finance, profileName);
}


bool DateProfile::setGender(char gdr)
{
   gender = gdr;
   return true;
}

bool DateProfile::setSearchGender(char searchGender)
{
   this->searchGender = searchGender;
   return true;
}

bool DateProfile::setRomance(int romance)
{
   if (romance > MAX_ROMANCE || romance < MIN_ROMANCE)
      return false;
   this->romance = romance;
   return true;
}

bool DateProfile::setFinance(int finance)
{
   if (finance > MAX_FINANCE || finance < MIN_FINANCE)
      return false;
   this->finance = finance;
   return true;
}

bool DateProfile::setName(string profileName)
{
   if ((profileName.length() > MAX_NAME_LEN) ||
      (profileName.length() < MIN_NAME_LEN))
      return false;
   name = profileName;
   return true;
}

void DateProfile::setAll(char gdr, char searchGender,int romance,
   int finance, string profileName)
{
   setGender(gdr);
   setSearchGender(searchGender);
   setRomance(romance);
   setFinance(finance);
   setName(profileName);
}

void DateProfile::setDefaults()
{
   gender = DEFAULT_GEND;
   searchGender = DEFAULT_SEARCH_GEND;
   romance = DEFAULT_ROMANCE;
   finance = DEFAULT_FINANCE;
   name = DEFAULT_NAME;
}

double DateProfile::fitValue(DateProfile partner)
{
   if (determineGenderFit(partner) == MIN_DIFFERENCE)
   {
      double average = (determineRomanceFit(partner) +
         determineFinanceFit(partner)) / 2;
      return average;
   }
   return 0.0;
}

double DateProfile::determineGenderFit(DateProfile partner)
{
   if (this->gender == partner.searchGender &&
       this->searchGender == partner.gender)
      return 1.0;
   return 0.0;
}

double DateProfile::determineRomanceFit(DateProfile partner)
{
   double value = 1 - abs(this->romance - partner.romance) * 0.1;
   return value;
}

double DateProfile::determineFinanceFit(DateProfile partner)
{
   double value = 1 - abs(this->finance - partner.finance) * 0.1;
   return value;
}

char DateProfile::getGender()
{
   return gender;
}

char DateProfile::getSearchGender()
{ 
   return searchGender;
}

int DateProfile::getRomance()
{
   return romance;
}

int DateProfile::getFinance()
{
   return finance;
}

string DateProfile::getName()
{ 
   return name;
}

/* -------------------------Paste of run #1--------------------------------------
Fit between Sarah Somebody and Sarah Somebody:    0
Fit between Sarah Somebody and Steve Nobody:    0
Fit between Sarah Somebody and Jane Peabody:    0
Fit between Sarah Somebody and Helen Anybody:    0.95


Fit between Steve Nobody and Sarah Somebody:    0
Fit between Steve Nobody and Steve Nobody:    0
Fit between Steve Nobody and Jane Peabody:    0
Fit between Steve Nobody and Helen Anybody:    0.8


Fit between Jane Peabody and Sarah Somebody:    0
Fit between Jane Peabody and Steve Nobody:    0
Fit between Jane Peabody and Jane Peabody:    1
Fit between Jane Peabody and Helen Anybody:    0


Fit between Helen Anybody and Sarah Somebody:    0.95
Fit between Helen Anybody and Steve Nobody:    0.8
Fit between Helen Anybody and Jane Peabody:    0
Fit between Helen Anybody and Helen Anybody:    0

Press any key to close this window . . .

--------------------------------------------------------------------------------*/

