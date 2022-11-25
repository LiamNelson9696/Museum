#include <iostream>
#include <fstream>
using namespace std;
#include "array.h"
#include "/cs/slott/cs211/checkInput.h"

int showMenu()
{
  int userInput = 0; //stores the user's input to be checked
  string errorMessage = "Invalid choice. Enter 1 or 2: "; //error message when input is invalid
  
  cout << "===================================" << endl;
  cout << "1. Visitor" << endl;
  cout << "2. Museum Staff" << endl;
  cout << "Enter your choice: ";
  userInput = getData(1, 2, errorMessage); //checks user input and stores it in userInput

  return userInput;
}

void getVisitorInfo(string countryAr[], int ageAr[] ,double timeAr[], int&n) //calls the fill function and fills the data at the current index
{ 
  int age; //stores age to be checked
  double time; //stores time to be checked
  string country; //temporarily stores the country

  //error messages
  string invalidTime = "The number of hours has to be between 0.0 and 10.0. Enter again: ";
  string invalidAge = "The age has to be between 0 and 200. Enter again: ";


  cout << "Enter your country: ";
  cin >> countryAr[n]; 
  cout << "Enter your age: ";
  age = getData(0, 200, invalidAge);
  ageAr[n] = age;
  cout << "Enter the amount of hours you explored: ";
  time = getData(0.0, 10.0, invalidTime);
  timeAr[n] = time;
}

bool checkPassword(string pass)
{
  if(pass == "5678")
    {
      return true;
    }
  else
    {
      return false;
    }
}

template <class O>

void showStatistic(O&out, string countryAr[], int agAr[], double hoursAr[], int size)
{
  double avg = getAvg(hoursAr, size); //a variable to store getAvg
  string uniqCountryAr[size]; //stores the unique countries to print

  sort(countryAr, size);
  unique(countryAr, uniqCountryAr, size);
  
  out << "The total number of visitors is "<< size << endl;
  out << endl << "------- The names of the countries of visitors -------" << endl;
  print(out, uniqCountryAr, size);
  out << endl;
  out << "The age of the youngest visitor: " << agAr[getLowest(agAr, size)] << endl;
  out << "The age of the oldest visitor: " << agAr[getHighest(agAr, size)] << endl;
  out << "The average age of the visitors: " << getAvg(agAr, size) << endl;
  out << "The shortest visit hours: " << hoursAr[getLowest(hoursAr, size)] << endl;
  out << "The longest visit hours: " << hoursAr[getHighest(hoursAr, size)] << endl;
  out << "The average visit hours: " << avg << endl;

}

//takes in the museum operator's choice for ending the museum and ends if yes or continues if n
int endMuseum(string countryArr[], int ageArr[], double hoursArr[], int visitorCount)
{
  char close;
  string date;
  string fileName;
  ofstream fout;

  cout << "Do you want to close the museum? Y or N: ";
  close = getYN("Invalid answer. Enter Y or N: ");

  //if operator choses to close
  if(close == 'Y' && visitorCount > 0)
    {
      cout << "Enter today's date: ";
      cin >> date;
      fileName = date+".txt";

      //opens and creates a file named 'fileName' and fills it with the info from showStatistic
      fout.open(fileName.c_str());
      showStatistic(fout, countryArr, ageArr, hoursArr, visitorCount);
      fout.close();

      return -1; //returns -1 to terminate the while loop in main()
    }
  else if(close == 'Y' && visitorCount == 0)
    {
      return -1; //same result as above if statement but for when the museum has no visitors
    }
  //if operator choses to stay open then it goes back to the menu
  else if(close == 'N')
    {
      return 0;
    }
}

int main()
{
  //two int variables, userInput: tracks user's menu choice || counter: keeps track of what index is being modified
  int userInput = 0; //stores user input from showMenu
  int visitorCount = 0; //tracks number of visitors
  int max = 100;

  //three arrays that store the visitor's information
  string countryArr[max];
  int ageArr[max];
  double hoursArr[max];

  string password;

  //conditions the while loop to keep running there is no way to input -1 so the loop runs until the operator closes it, loop also doesn't accept visitors past it's 100th visitor
  while(userInput != -1)
   {
     userInput = showMenu();
    if(userInput == 1 && visitorCount < max)
    {
      getVisitorInfo(countryArr, ageArr, hoursArr, visitorCount);
      visitorCount++;
    }
    else if(userInput == 1 && visitorCount >= max)
    {
      cout << "We cannot take any more visitor info." << endl << endl;
    } 
    else if(userInput == 2)
    {
      cout << "Enter the password: ";
      cin >> password;
      
      if(checkPassword(password) == true && visitorCount >= 1)
	{
	  showStatistic(cout, countryArr, ageArr, hoursArr, visitorCount);
	  cout << endl;
	  userInput = endMuseum(countryArr, ageArr, hoursArr, visitorCount);
	}
      else if(checkPassword(password) == true && visitorCount == 0)
	    {
	      cout << "The total number of visitors is 0" << endl;
	      userInput = endMuseum(countryArr, ageArr, hoursArr, visitorCount);
	    }
      else if(checkPassword(password) == false)
	{
	  cout << "Password is wrong." << endl << endl;
	}
    } //end of while loop 
  }

  return 0;
}
