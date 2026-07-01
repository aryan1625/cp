//use of join detach and joinable in cpp
//JOIN Notes
//0. once a thread is started we wait for the thread to finish its execution using join() function.
//1. Double Join will result into program termination (system_error will occur and program will terminate)
//2. We should check if the thread is joinable or not before calling join() function by using joinable() function


//DETACH
//0. This is used to detach newly created thread from the parent thread
//1. Once a thread is detached it will run in background and we cannot join it anymore
//2. Always check before detaching a thread if it is joinable or not using joinable() function otherwise
//   we may end up double detaching and terminating the program 
//3. If we have detached thread and main function is returning then the detached thread execution is suspended

//NOTES
// Either join() or detach() should be called on a thread object before it is destroyed otherwise program will terminate as thread object
// destructor will be called. Because inside destructor it will check if the thread is joinable or not and if it is joinable then it will terminate the program. 
// So we should always call either join() or detach() before thread object is destroyed.
#include <iostream>
#include <thread>
#include <chrono>
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
void run(int count){
    while(count-->0){
        cout<< count <<" hello"<<endl;
    }
    std::this_thread::sleep_for(chrono::seconds(3));
}
int main() {
    std::thread t1(run, 10);
    cout<<"main()"<<endl;
    // t1.join();
    // if(t1.joinable()){
    //     t1.join();
    // }
    t1.detach();
    //it will not wait for 3 seconds if detach is called
    if(t1.joinable()){
        t1.detach();
    }
    cout<<"main() after"<<endl;
    return 0;
}