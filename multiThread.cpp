#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void downloadPart(int part) {
    cout << "Downloading part " << part 
         << " in thread: " << this_thread::get_id() << endl;

    this_thread::sleep_for(chrono::seconds(2)); // simulate delay

    cout << "Finished part " << part << endl;
}

int main() {
    thread t1(downloadPart, 1);
    thread t2(downloadPart, 2);
    thread t3(downloadPart, 3);

    t1.join();
    t2.join();
    t3.join();

    cout << "Download complete!" << endl;
    return 0;
}

