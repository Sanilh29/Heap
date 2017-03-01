#include <iostream>

class Heap {
 public:
  Heap();
  ~Heap();
  void insert(int value);
  void remove(int value);
  void print();
  bool checkNode();
  void bubbleUp();
  void bubbleDown();
 private:
  int index;
  int value;
  
};
