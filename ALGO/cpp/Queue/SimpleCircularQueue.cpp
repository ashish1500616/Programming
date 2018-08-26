#include <bits/stdc++.h>
using namespace std;

template <typename T> class Queue {

public:
  int limit;
  int front = -1;
  int rear = -1;
  int size = 0;
  T *queue = NULL;

  Queue(int ld) {
    limit = ld;
    queue = new T[limit];
  }

  void enqueue(T data) {
    int index;
    if (size >= limit) {
      if ((rear + 1) % limit == front)
        cout << "Overflow Cannot Enter Data!" << endl;
      return;
    } else {
      index = (rear + 1) % limit;
      queue[index] = data;
      size += 1;
    }
    if (front == -1) {
      front = rear = 0;
    } else {
      rear = index;
    }
  }

  void dequeue() {
    if (size <= 0) {
      cout << "Queue UnderFlow!" << endl;
      return;
    } else {
      // queue[front] = INT_MAX;
      front = (front + 1) % limit;
      size -= 1;
    }
    if (front == rear) {
      front = rear = -1;
    }
  }
  int sizeQueue() { return size; }
  void print() {
    for (int i = 0; i < limit; i++) {
      // if (queue[i] != INT_MAX)
      cout << queue[i] << " ";
    }
  }
  T frontQueue() { return queue[front]; }
  T rearQueue() { return queue[rear]; }
  bool isEmpty() { return front == -1; }
  bool isFull() { return size == limit; }
};
int main() {
  Queue<string> obj(5);
  obj.enqueue("I");
  obj.enqueue("Love");
  obj.enqueue("India");
  obj.enqueue("My");
  obj.enqueue("Country");
  obj.dequeue();
  obj.dequeue();
  obj.enqueue("Incredible");
  cout << "Size::" << obj.size << endl;
  cout << "Front::" << obj.frontQueue() << endl;
  cout << "Back::" << obj.rearQueue() << endl;
}
