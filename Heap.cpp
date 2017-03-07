//Sanil Hattangadi, this is the cpp of the Heap methods. It contains all the algorithms
#include <iostream>
#include "Heap.h"

using namespace std;

int getParent(int child);
int getLeft(int parent);
int getRight(int parent);
void bubbleUp(int index, int* array);

Heap::Heap(){//constructor of the heap and sets the variables
  count = 0;
  size = 128;
  value = new int[size];
}

Heap::~Heap(){//deconstructor and deletes all the integer values
  delete[] value;
}

void Heap::insert(int inserted){//puts the inserted integer into the count spot, the last spot
  value[count] = inserted;
  bubbleUp(count);//bubbles up the last spot until it is a correct max heap tree
  count++;//adds one to the count
}

int Heap::remove(){//removes a value
  int toReturn = value[0];//the top value, max
  value[0] = value[count-1];//puts value into the last spot
  bubbleDown(0);//moves new top value t correct spot
  count--;//takea away one from count
  return toReturn;
}

void Heap::print(int i, int indent){//prints out the tree
  if (i < count){
    print(getLeft(i), indent+3);//recursion and prints the left and indents it 3
    for (int j = 0; j <=indent; j++){ //go through it
      cout << " ";
    }
    cout << value[i] << endl;
    print(getRight(i), indent+3);//get the right tree 
  }
}

void Heap::bubbleUp(int i){//moves value up
  if(i != 0){
    if(value[i] > value[getParent(i)]){//if child is bigger than parent
      int temp = value[i]; //set the last one to temp
      value[i] = value[getParent(i)];//switch the two
      value[getParent(i)] = temp;
      bubbleUp(getParent(i));//recursion
    }
  }
}
void Heap::bubbleDown(int i){//moves value down until tree is correct
  int swapIndex = -1;
  if (getLeft(i) <= count-1 && getRight(i) <= count-1){//if the left index and right index are less than count -1
    swapIndex = (value[getRight(i)] > value[getLeft(i)]) ? getRight(i) : getLeft(i);//swap them
  }
  else if(getLeft(i) <= count-1){//if get left is greater 
    swapIndex = getLeft(i);
  }
  if(value[swapIndex] > value[i] && i != -1){//switches the 2
    int temp = value[i];
    value[i] = value[swapIndex];
    value[swapIndex] = temp;
    bubbleDown(swapIndex);
  }
}

int getLeft(int parent){//gets left child by using equation
  return (parent*2+1);
 }

int getRight(int parent){//gets right child by using equation
  return (parent*2+2);
}

int getParent(int child){//gets parent by using equation
  if (child > 0){
    if (child %2 ==1){
      return ((child-1)/2);
    }
    else{
      return ((child-2)/2);
    }
  }
  else{
    return child;
  }
}

int Heap::getCount(){//returns the spot of the last one
  return count;
}

