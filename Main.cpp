#include <iostream>
#include <cstring>

using namespace std;

int main(){
  char command[32];
  cout << "Welcome to the Heap." << endl;
  bool running = true;
  while (running == true){
    cout << "Enter a command: run or quit" << endl;
    cin.get(command, 32);
    cin.ignore();
    if (0==strcmp(command, "run")){
      char decision[32];
      cout << "Enter a command to enter numbers: file or numbers" << endl;
      cin.get(decision, 32);
      cin.ignore();
      if (0 == strcmp(decision, "file")){
	running = false;
      }
      if (0 == strcmp (decision, "numbers")){
	running = false;
      }
    }
    if (0 == strcmp(command, "quit")){
      running = false;
    }
  }
}
