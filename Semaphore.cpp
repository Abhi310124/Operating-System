#include <iostream>
#include <thread>
#include <semaphore>
using namespace std;

binary_semaphore empty(1); // buffer is empty initially
binary_semaphore full(0);  // nothing produced initially

int buffer = 0;

void producer() {
    for(int i = 1; i <= 5; i++) {
        empty.acquire();   // wait for empty slot

        buffer = i;
        cout << "Produced: " << buffer << endl;

        full.release();    // signal consumer
    }
}

void consumer() {
    for(int i = 1; i <= 5; i++) {
        full.acquire();    // wait for full slot

        cout << "Consumed: " << buffer << endl;

        empty.release();   // signal producer
    }
}

int main() {
    thread t1(producer);
    thread t2(consumer);

    t1.join();
    t2.join();
}
