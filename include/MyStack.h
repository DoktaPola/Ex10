//// Copyright 2021 Ozhiganova Polina
#ifndef INCLUDE_MYSTACK_H_
#define INCLUDE_MYSTACK_H_

#include <climits>
template<class T>
class MyStack {
 public:
  explicit MyStack(size_t size)
      : index(0),
        size(size),
        arr(new T[size + 1]) {}

  explicit MyStack(const MyStack &st) {
    this->index = st.index;
    this->size = st.size;
    this->arr = new T[st.size + 1];
    for (auto i = 0; i < size; ++i) {
      this->arr[i] = st.arr[i];
    }
  }

  ~MyStack() {
    delete[] arr;
    this->index = 0;
    this->size = 0;
  }

  T get() const {
    if (index) {
      return arr[index - 1];
    } else {
      return NO_VALUE;
    }
  }

  T pop() {
    if (index == 0) {
      return NO_VALUE;
    } else {
      int del_first = arr[index - 1];
      index--;
      return del_first;
    }
  }

  void push(T var) {
    if (index == size) {
      T *arr2 = new T[size * 2];
      for (auto i = 0; i < size; i++) {
        arr2[i] = arr[i];
      }
      size = size * 2;
      delete[] arr;
      arr = arr2;
    }
    arr[index] = var;
    index++;
  }

  [[nodiscard]] bool isFull() const {
    return index == size;
  }

  [[nodiscard]] bool isEmpty() const {
    if (index == 0) {
      return true;
    } else {
      return false;
    }
  }

  const int NO_VALUE = INT_MAX;

 private:
  int size;
  T *arr;
  int index;
};

#endif  // INCLUDE_MYSTACK_H_
