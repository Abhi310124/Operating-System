#include<semaphore>
using namespace std;

class DiningPhilosophers {
private:
    mutex mtx[5];
    counting_semaphore<5> sem{2};
public:
    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
		int left=philosopher;
        int right=(philosopher+1)%5;

        sem.acquire();
        unique_lock<mutex> lckLeft(mtx[left]);
        unique_lock<mutex> lckRight(mtx[right]);

        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();
        
        sem.release();

    }
};