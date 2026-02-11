#include <stdio.h>
#include <pthread.h>

int counter = 0;   // shared global variable
// Problem: both threads use the same variable at the same time
//          no control → race condition

void* increment(void* arg) 
{
    for (int i = 0; i < 500; i++) 
    {
        counter++;   // Problem: counter++ is NOT one single step
                     // Really: 1) load counter
                     //         2) add 1
                     //         3) store back
                     // If two threads do this together → one update can overwrite the other
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    // create 2 threads
    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, increment, NULL);

    // Problem: main does not know what happens inside increment()
    // pthread_join() only waits for threads to finish
    // but it cannot fix lost updates (race condition still happens)
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // Actually expected result = 500 + 500 = 1000
    // But because of race condition → final value < 1000
    // Different runs give different results (unpredictable scheduling)
    printf("Final counter value: %d\n", counter);

    return 0;
}
