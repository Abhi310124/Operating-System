#include <bits/stdc++.h>
using namespace std;

class FizzBuzz {
private:
    int n;
    int curr = 1;
    mutex m;
    condition_variable cv;

public:
    FizzBuzz(int n) {
        this->n = n;
    }

    void fizz(function<void()> printFizz) {
        while (true) {
            unique_lock<mutex> lock(m);

            cv.wait(lock, [&]() {
                return curr > n || (curr % 3 == 0 && curr % 5 != 0);
            });

            if (curr > n) return;

            printFizz();
            curr++;
            cv.notify_all();
        }
    }

    void buzz(function<void()> printBuzz) {
        while (true) {
            unique_lock<mutex> lock(m);

            cv.wait(lock, [&]() {
                return curr > n || (curr % 5 == 0 && curr % 3 != 0);
            });

            if (curr > n) return;

            printBuzz();
            curr++;
            cv.notify_all();
        }
    }

    void fizzbuzz(function<void()> printFizzBuzz) {
        while (true) {
            unique_lock<mutex> lock(m);

            cv.wait(lock, [&]() {
                return curr > n || (curr % 3 == 0 && curr % 5 == 0);
            });

            if (curr > n) return;

            printFizzBuzz();
            curr++;
            cv.notify_all();
        }
    }

    void number(function<void(int)> printNumber) {
        while (true) {
            unique_lock<mutex> lock(m);

            cv.wait(lock, [&]() {
                return curr > n || (curr % 3 != 0 && curr % 5 != 0);
            });

            if (curr > n) return;

            printNumber(curr);
            curr++;
            cv.notify_all();
        }
    }
};
