//Sanil Hattangadi, March 7, the program receives numbers from input or file and puts them in order
//based on a tree or in sequence
#include <iostream>
#include <fstream>
#include <cstring>
#include "Heap.h"

using namespace std;

void addToHeap(istream &from, Heap* heap);//add the input to heap
void checkInput(ifstream &stream, bool &isFile);//checks if the input is file or input

int main(){
  Heap heap;
  char command[32];
  cout << "Welcome to the Heap." << endl;
  bool running = true;
  while (running == true){//keeps the program running
    cout << "Enter a command: add, print, tree or quit" << endl;
    cin.get(command, 32);//put the command entered into variable command
    cin.ignore();
    if (0 == strcmp(command, "tree")){//compare tree to command
      heap.print();//print out the tree
    }
    if (0 == strcmp (command, "print")){//if command is equal to print
      while(heap.getCount() > 0){//if there is stuff in the heap
	cout << heap.remove() << " ";//print it out in order
      }
      cout << endl;
    }
    if (0 == strcmp(command, "add")){//if add is inputted
      ifstream stream;//create the variable
      bool isFile;
      checkInput(stream, isFile);//run checkInput
      addToHeap(isFile ? stream: cin, &heap);//run add to heap
      if (isFile) stream.close();//if its a file, do this
      cin.ignore();
    }
    if (0==strcmp(command, "quit")){//if quit, quit program
      running = false;
    }
  }
}

void checkInput(ifstream &stream, bool &isFile){ //checks if the input is file or input
  char input[128];
  isFile = false;
  cout << "Do you want to read from a file or input your own text?(file or input)" << endl;//check how it will be inputted
  cin.getline(input,128); 
  if (0== strcmp(input, "file")){//if file and input are equal
    char name[128];
    cout << "What file?" << endl;
    cin.getline(name, 128);//get the name of the file
    stream.open(name);//try to open it
    if(stream.is_open()){//if it opends, there is a file
      isFile = true;
      cout << "Thanks. Enter a command above." << endl;
    }
    else {
      cout << "The file could not be opened" << endl;
    }
  }
  if (0==strcmp(input, "input")){
    cout << "Enter the numbers please." << endl;
  }
}

void addToHeap(istream &from, Heap* heap){//add to heap
  int numbers;
  while(from.peek() != '\n' && !from.eof()){
    if(isdigit(from.peek())){
      from >> numbers;
      heap->insert(numbers);//put numbers into heap
    }
    else{
      from.ignore();
    }
  }
}
   
