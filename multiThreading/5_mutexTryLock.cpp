//TOPIC: std::mutex::try_lock() function 
//0. try_lock() - tries to lock the mutex. Returns immediately. On successful lock acquisition returns true otherwise false
//1. try_lock() is non-blocking function. It will not wait for the mutex to be unlocked if it is already locked by another thread. It will return false immediately if the mutex is already locked by another thread.
//2. If try_lock() is called again by the same thread which owns the mutex, the behaviuour is undefined.
//   If you want to be able to lock the same mutex multiple times by the same thread, you should use std::recursive_mutex instead of std::mutex.     

#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <string>

using ll = long long;
using namespace std;
void func(){
   cout<<"hello"<<endl;
}
int main() {
    std::thread t1(func);
    t1.join();
    return 0;
}