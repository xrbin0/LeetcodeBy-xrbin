#include <bits/stdc++.h>
using namespace std;

class LRUCache {
  public: //这题做的效率很低，LRU本身是个蛮有意思的问题。
    LRUCache(int capacity) :capacity(capacity), use(0) {
        data = vector <vector <int>>(capacity, vector <int>(3, 0x80000000));
    }

    int intHashInt(int a){ return a % capacity; }
    
    int get(int key) {
      int index = intHashInt(key);
      for(int i = 0;data[index][0] != key;i++){
        index = (index + 1) % capacity;
        if(i == capacity) return -1;
      } 
      data[index][2] = use++;
      return data[index][1];
    }
    
    void put(int key, int value) {
      int index = intHashInt(key);
      for(int i = index, j = 0;j != capacity;j++){
        if(data[i][0] == 0x80000000 || key == data[i][0]){
          data[i][0] = key;
          data[i][1] = value;
          data[i][2] = use++;
          return ;
        }
        i = (i + 1) % capacity;
      }
      int minx = index;
      for(int i = (index + 1) % capacity;i != index;){
        if(data[i][2] < data[minx][2]) minx = i;
        i = (i + 1) % capacity;
      }
      data[minx][0] = key;
      data[minx][1] = value;
      data[minx][2] = use++;
    }
  private:
    vector <vector <int>> data;
    int capacity; int use;
};