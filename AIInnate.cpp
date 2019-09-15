// identification comments code block
// Ramy Fekry
// Artificial Intelligence With Innate Knowledge
// Editor used: Visual Studio
// Compiler used: MinGW GNU


#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

struct Movie 
{
  string sayThis;
  Movie* yes;
  Movie* no;
};

void ID(string);

int main()
{
  ID("Artificial Intelligence With Innate Knowledge");
  // all of the diagnoses
  Movie guess1 = {"You need to check the fuel to be in place, if that's fine then I would recommend to check your engine."};
  Movie guess2 = {"The transmission doesn't seem to be functioning very properly."};
  Movie guess3 = {"The wiring in the car seems to be loose."};
  Movie guess4 = {"The battery seems to be dead."};
  Movie guess5 = {"The car is probably fine, you could probably check if a tire is flat or so."};
  Movie guess6 = {"The car probably needs washer fluid, you washer fluid is running low."};
  Movie guess7 = {"We just ran a whole test to the car and it seems to be running just fine."};
  Movie guess8 = {"Try turning the engine on, if that doesn't turn off the light then the car needs to be manually checked"};
  
  // all of the questions
  Movie question1 = {"Did the car have any weird sound the last time it ran?", &guess2, &guess4};
  Movie question2 = {"Is the check engine light on?", &guess1, &guess5};
  Movie question3 = {"Does it look like the light invloves water?", &guess6, &guess3};
  Movie question4 = {"Do you have any weird, irregular or irreasonable light on the dashboard?", &guess8, &guess7};
  Movie question5 = {"Is the engine starting?", &question2, &question1};
  Movie question6 = {"Is the dashboard turning on?", &question4, &question3};
  Movie question7 = {"Is the ignition turning on?", &question6, &question5};
 
  Movie* top = &question7; // the full tree
  string buf;
 
  // the "challenge" to the user
  cout << "\nTell me about the condition your car and I'll identify the problem.\n";
 
  Movie* p = top; // move p through the tree
  while (true) // the p-loop
  {
    cout << p->sayThis; // could be the answer or could be another question
    if (p->yes == 0 && p->no == 0) break; // it was the answer -- we're done!
    cout << " [yes/no] ";

    getline(cin, buf);
    if (buf == "yes"|| buf =="y" || buf =="Y") p = p->yes;
    else if (buf == "no"|| buf =="n" || buf =="N") p = p->no;
  }
}

void ID(string lab)
{
  // identification output code block
  cout << "Ramy Fekry \n\n";
  cout << lab << "\n";  
  cout << "Editor(s) used: Visual Studio\n";
  cout << "Compiler(s) used: MinGW GNU\n";
  cout << "File: " << __FILE__ << "\n"; 
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << "\n";
  cout << "Hi I hope you like my program \n\n";
}