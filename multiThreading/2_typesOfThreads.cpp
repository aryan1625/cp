// topic - types of threads in cpp
// 5 different types we can create threads in cpp using callable objects

//NOTE
// if we create multiple threads at the same time it doesn't guarantee which one will execute first 

#include<iostream>
#include<thread>
using namespace std;


// 1. Function Pointer
//this is the very basic form of thread creation

    void fun(int x){
        while(x-->0)cout<<x<<endl;
    }
    int main() {
        std::thread t1(fun,11);
        std::thread t2(fun,10);
        t1.join();
        return 0;
    }



// 2. Lambda Functions

    int main() {
        // lambda function - inject lambda at thread creation time
        auto fun= [](int x){
            while(x-->0)cout<<x<<endl;
        };
        std::thread t(fun,10);

        //or

        std::thread t1([](int x){
            while(x-->0)cout<<x<<endl;
        },10);


        t.join();
        return 0;
    }




// 3. Functor
// it work as function and achieved by overloading "operator ()" in some class 
// Functors are objects that can be treated as though they are a function or function pointer
    //example - 

    //https://www.geeksforgeeks.org/cpp/functors-in-cpp/
    class Mul{
        int _val;
        public:
            Mul(){}
            Mul(int val): _val(val){}
            int operator()(int val){
                return val*_val;
            }
    };
    int main(){
        Mul mul12(12);
        cout<< mul12(2)<<endl;
        cout<< mul12(3)<<endl;
        return 0;
    }


// Functor use in threads
    class Base{
        public: 
            void operator()(int x){
                while(x-->0){
                    cout<<x<<endl;
                }
            }
    };
    int main() {
        std::thread t((Base()),10);
        t.join();
        return 0;
    }


//4. Non-static member function
 class Base{
    public:
        void run(int x){
            while(x-->0)cout<<x<<endl;
        }
 };

 int main(){
    Base b;
    std::thread t(&Base::run, &b, 10);
    t.join();
    return 0;
 }


 //5. Static member function
 class Base{
    public:
        static void run(int x){
            while(x-->0)cout<<x<<endl;
        }
 };

 int main(){
    std::thread t(&Base::run, 10);
    t.join();
    return 0;
 }
