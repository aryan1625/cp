// Mutex in C++ Threading | Why use MUTEX | What is Race Condition | What is Critical Section
//MUTEX - Mutual Exclusion
// Race Condition - 
// 0. When multiple threads are trying to access the same resource at the same time then it is called Race Condtion
// 1. There is a section called Critical Section where only one thread can access the resource at a time and other threads have to wait for their turn to access the resource.
//   This helps in preventing race condition

// MUTEX
// 0. Mutex is used to protect the critical section and prevent race condition. It is a locking mechanism that allows only one thread to access the critical section at a time.
// 1. We use lock() and unlock() functions to lock and unlock the mutex respectively. 
// 2. When a thread locks the mutex, other threads have to wait for their turn to access the critical section.

#include <iostream>
#include <thread>
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


int myAmount = 0;
std::mutex m;
void addMoney(){
    //common variable
    m.lock();
    ++myAmount;
    m.unlock();
}
int main() {
    std::thread t1(addMoney);
    std::thread t2(addMoney);
    t1.join();
    t2.join();
    cout<<"myAmount: "<<myAmount<<endl;

    return 0;
}