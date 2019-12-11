class Buffer() {

  int * arr;
  int s;
  int head;
  int tail;
  enum BufferState {Ready, Empty, Full};
  BufferState state;
  
  Buffer::Buffer(int size) {
    s = size;
    arr = new Int[s];
    head = 0;
    tail = 0;
    state = Empty;
  }
  
  Buffer::~Buffer() {
    delete [] arr;
  }
  
  void Buffer::push(int val) {
    if(state != Full) {
      arr[head] = val;
      head++;
      if(head==s) head = 0;
      if(head==tail) state = Full;
      else state = Ready;
    }
  }
  
  int Buffer::pope() {
    if(state != Empty) {
    inv val = arr[tail];
    tail++;
    if(tail==s) tail = 0;
    if(tail==head) state = Empty;
    else state = Ready;
    return val;
  }
}  
