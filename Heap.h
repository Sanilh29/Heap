#include <iostream>

class Heap {
 public:
  Heap();
  ~Heap();
  void insert(int inserted);
  int remove();
  void print(int i = 0, int indent=0);
  void printSequence();
  void bubbleUp(int i);
  void bubbleDown(int i);
  int getCount();
 private:
  int count;
  int* value;
  int size;
};
