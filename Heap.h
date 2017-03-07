//Sanil Hattangadi, this is the heap header that creates the methods and variables
#include <iostream>

class Heap {
 public://the methods
  Heap();//contstuctor
  ~Heap();//deconstructor
  void insert(int inserted);//insert numbers into array
  int remove();//remove numbers from array
  void print(int i = 0, int indent=0);//creates the tree
  void printSequence();//prints the array
  void bubbleUp(int i);//moves up the value up in the tree
  void bubbleDown(int i);//moves down the valuein the tree
  int getCount();//gets count
 private:
  int count;//count variable
  int* value;//value 
  int size;
};
