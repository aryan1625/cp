/* 

Threading in CPP
Q. What do you understand by thread and give an example of it in cpp
A.  0. In every application there is a defaul thread which is main() and inside this we create other threads
    1. A thread is also known as a lightweight process. Our main goal with threads is to achieve parallelism by dividing a process 
        into multiple threads.
        For ex - 
            a. The browser has multiple tabs - can become different threads
            b. Ms word uses different threads - one thread for formatting text, one thread for processing inputs
            c. Vs code editor may use threading for auto completing the code. (Intellisense)

Ways to create threads in cpp 11
1. Function Pointers
2. Lambda Functions
3. Functors
4. Member Functions
5. Static Member Functions

*/


// Requirement - find sum of all odd numbers from 1 to 1900000000 and all even between 1 to 1900000000
#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;
using namespace std:: chrono;

using ll = long long;
typedef unsigned long long ull;

ull oddSum = 0;
ull evenSum = 0;

void findEven(ull st, ull end){
    ull loc = 0;
    for(ull i=st; i<=end; ++i){
        if(!(i&1))loc += i;
    }
    evenSum = loc;
}

void findOdd(ull st, ull end){
    ull loc = 0;
    for(ull i=st; i<=end; ++i){
        if((i&1))loc += i;
    }
    oddSum = loc;
}

int main() {
    ull st = 0, end = 1900000000;
    auto startTime = high_resolution_clock::now();

    std::thread t1(findEven,st,end);
    std::thread t2(findOdd,st,end);

    t1.join();
    t2.join();

    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stopTime-startTime);

    cout<<"oddSum: "<<oddSum<<endl;
    cout<<"evenSum: "<<oddSum<<endl;
    cout<<"time duration in seconds: "<< duration.count()/1000000 <<endl;
    return 0;
}