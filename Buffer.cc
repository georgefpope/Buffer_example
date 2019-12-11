#include <iostream>
using namespace std;

class Buffer {

  private:
  int * arr;
  int s;
  int head;
  int tail;
  enum BufferState {Ready, Empty, Full};
  BufferState state;
  
  public:
  Buffer(int size) {
    s = size;
    arr = new int[s];
    head = 0;
    tail = 0;
    state = Empty;
  }
  
  ~Buffer() {
    delete [] arr;
  }
  
  void push(int val, bool &errCode) {
    errCode = false;
    if(state != Full) {
      arr[head] = val;
      head++;
      if(head==s) head = 0;
      if(head==tail) state = Full;
      else state = Ready;
    }
    else {
        errCode = true;
        //cout << "But I am full!" << endl;
    }
  }
  
  void push(int val) {
      bool errCode;
      push(val, errCode);
  }
  
  int pop(bool &errCode) {
    int val=0;
    errCode = false;
    if(state != Empty) {
      val = arr[tail];
      tail++;
      if(tail==s) tail = 0;
      if(tail==head) state = Empty;
      else state = Ready;
    }
    else {
        errCode = true;
        //cout << "But I am empty!" << endl;
    }
    return val;
  }

  int pop() {
    bool errCode;
    return pop(errCode);
  }

};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    Buffer b(5);
    bool err = true;
    cout << "Pushing 1" << endl;
    b.push(1,err);
    if(err) cout << "There was a problem" << endl;
    cout << "Pushing 2" << endl;
    b.push(2);
    cout << "Pushing 3" << endl;
    b.push(3);
    cout << "Popping " << b.pop(err) << endl;
    if(err) cout << "There was a problem with the pop" << endl;
    cout << "Pushing 4" << endl;
    b.push(4,err);
    if(err) cout << "There was a problem" << endl;
    cout << "Pushing 5" << endl;
    b.push(5);
    cout << "Popping " << b.pop(err) << endl;
    cout << "Pushing 6" << endl;
    b.push(6);
    cout << "Pushing 7" << endl;
    b.push(7,err);
    if(err) cout << "There was a problem with the push" << endl;
    cout << "Pushing 8" << endl;
    b.push(8,err);
    if(err) cout << "There was a problem with the push" << endl;
    cout << "Popping " << b.pop() << endl;
    cout << "Popping " << b.pop() << endl;
    cout << "Popping " << b.pop(err) << endl;
    if(err) cout << "There was a problem with the pop" << endl;
    cout << "Popping " << b.pop(err) << endl;
    if(err) cout << "There was a problem with the pop" << endl;
    cout << "Popping " << b.pop(err) << endl;
    if(err) cout << "There was a problem with the pop" << endl;
    cout << "Popping " << b.pop(err) << endl;
    if(err) cout << "There was a problem with the pop" << endl;
    return 0;
}
