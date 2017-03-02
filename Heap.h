#include <iostream>

class Heap {
 public:
  Heap();
  ~Heap();
  void insert(int inserted);
  void remove(int removed);
  void print();
  void printSequence();
  void bubbleUp(int index, int* array);
  void bubbleDown(int index, int* array);
 private:
  int count;
  int* value;
  int size;
};
