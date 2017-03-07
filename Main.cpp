#include <iostream>
#include <fstream>
#include <cstring>
#include "Heap.h"

using namespace std;

void addToHeap(istream &from, Heap* heap);
void checkInput(ifstream &stream, bool &isFile);

int main(){
  Heap heap;
  char command[32];
  cout << "Welcome to the Heap." << endl;
  bool running = true;
  while (running == true){
    cout << "Enter a command: run or quit" << endl;
    cin.get(command, 32);
    cin.ignore();
    if (0==strcmp(command, "run")){
      char decision[32];
      cout << "Enter a command: add, print, or tree." << endl;
      cin.get(decision, 32);
      cin.ignore();
      if (0 == strcmp(decision, "tree")){
	heap.print();
      }
      if (0 == strcmp (decision, "print")){
	while(heap.getCount() > 0){
	  cout << heap.remove() << " ";
	}
	cout << endl;
      }
      if (0 == strcmp(decision, "add")){
	ifstream stream;
	bool isFile;
	checkInput(stream, isFile);
	addToHeap(isFile ? stream: cin, &heap);
	if (isFile) stream.close();
	cin.ignore();
      }
    }
    if (0 == strcmp(command, "quit")){
      running = false;
    }
  }
}

void checkInput(ifstream &stream, bool &isFile){ 
  char input[128];
  isFile = false;
  cout << "Do you want to read from a file or input your own text?(file or input)" << endl;
  cin.getline(input,128); 
  if (0== strcmp(input, "file")){
    char name[128];
    cout << "What file?" << endl;
    cin.getline(name, 128);
    stream.open(name);
    if(stream.is_open()){
      isFile = true;
    }
    else {
      cout << "The file could not be opened" << endl;
    }
  }
  if (0==strcmp(input, "input")){
    cout << "Enter the numbers please." << endl;
  }
}

void addToHeap(istream &from, Heap* heap){
  int numbers;
  //
  heap->insert(numbers);
  while(from.peek() != '\n' && !from.eof()){
    if(isdigit(from.peek())){
      from >> numbers;
      heap->insert(numbers);
    }
    else{
      from.ignore();
    }
  }
}
   
