#include <iostream>
#include <vector>
#include <time.h>
#include <chrono>

using namespace std;

void findPrimes(int limit) {
    
    vector<bool> isPrime(limit + 1, true); // true or false vector
    isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime numbers

    // Apply the Sieve of Eratosthenes (Discussed with Mr. Hansen)
    for (int p = 2; p * p <= limit; ++p) {
        if (isPrime[p]) {
            for (int i = p * p; i <= limit; i += p) {
                isPrime[i] = false;
            }
        }
    }

    // Output the prime numbers
    for (int i = 2; i <= limit; ++i) {
        if (isPrime[i]) {
            cout << i << " ";

        }
    }
}

int main() {
   //attributes
    chrono::time_point<chrono::system_clock> start;
    chrono::time_point<chrono::system_clock> end;
    chrono::duration<float> elapsed;
    
    // Timing
    start = chrono::system_clock::now();
    
    int limit = 999983; // make the liimit the highest prime number up to one million
    findPrimes(limit);
    end = chrono::system_clock::now();
    
    elapsed = end - start;
    
    cout << endl << "Time to complete task: " << elapsed.count() << " seconds"<< endl; //Output the amount of time
    return 0;
}
