#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;

mutex cpu_lock;  // This acts like "1 CPU core"

void task(int id) {
    cpu_lock.lock(); // Only one thread can execute now

    cout << "Thread " << id << " START running on CPU\n";

    this_thread::sleep_for(chrono::seconds(2));

    cout << "Thread " << id << " END running on CPU\n\n";

    cpu_lock.unlock();
}

int main() {
    thread t1(task, 1);
    thread t2(task, 2);
    thread t3(task, 3);

    t1.join();
    t2.join();
    t3.join();

    cout << "All threads finished.\n";
    return 0;
}

