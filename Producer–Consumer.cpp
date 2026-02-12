#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

mutex m;
condition_variable cv;

int buffer = 0;
bool full = false;

void producer() {
    for(int i = 1; i <= 5; i++) {
        unique_lock<mutex> lock(m);

        // Wait until buffer is empty
        cv.wait(lock, [] { return full == false; });

        buffer = i;
        full = true;
        cout << "Produced: " << buffer << endl;

        cv.notify_one(); // Wake consumer
    }
}

void consumer() {
    for(int i = 1; i <= 5; i++) {
        unique_lock<mutex> lock(m);

        // Wait until buffer is full
        cv.wait(lock, [] { return full == true; });

        cout << "Consumed: " << buffer << endl;
        full = false;

        cv.notify_one(); // Wake producer
    }
}

int main() {
    thread t1(producer);
    thread t2(consumer);

    t1.join();
    t2.join();
}
