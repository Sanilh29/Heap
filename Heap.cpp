#include <iostream>
#include "Heap.h"

int getParent(int child);
int getLeft(int parent);
int getRight(int parent);

Heap::Heap(){
  count = 0;
  //missing stuff
}

Heap::~Heap(){
  delete[] value;
}

void Heap::insert(int inserted){
  //put the node data into the last
  
}

void Heap::remove(int removed){//not done

}

void Heap::print(){//not done

}

void Heap::bubbleUp(int index, int* array){
  while (index !=0){
    if(array[index] > array[getParent(index)]){
      int temp = array[index];
      array[index] = array[getParent(index)];
      array[getParent(index)] = temp;
      index = getParent(index);
    }
    else{
      return;
    }
  }
}

void Heap::bubbleDown(int index, int* array){//not done
  int left;
  int right;
  // if(array[getLeft(index)] > array[get
}

int getLeft(int parent){
  return (parent*2+1);
 }

int getRight(int parent){
  return (parent*2+2);
}

int getParent(int child){
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

