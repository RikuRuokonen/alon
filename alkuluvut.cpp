#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>    // std::sort
using namespace std;
vector<int> primes;
vector<int> pairs;
int lastAmount{0};

int findPairFromPrime(int n){
    for(int i = 0; i <=primes.size(); i++){
        cout << "PRIME PHASE: " << primes[i] << "\n";
        if(n >= primes[i]){
            continue;
        }
        if(primes[i] -n <= lastAmount){
            continue;
        }
        lastAmount = primes[i] - n;
        return (primes[i] - n);
    }
    return 0;
}

void sieveOfEratosthenes(int n) { 
    // Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true. 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            // Update all multiples of p greater than or  
            // equal to the square of it 
            // numbers which are multiple of p and are 
            // less than p^2 are already been marked.  
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    // Print all prime numbers 
    for (int p=2; p<=n; p++) 
       if (prime[p]) 
          primes.push_back(p);
} 

int main() {
    int n;
    cin >> n;
    //maksimi pituus 2n
    //luo 2n pituinen lista mahdollisista primeistä
    sieveOfEratosthenes(2 * n);
    for(int i = 1; i <= n; i++){
        int value = findPairFromPrime(i);
        pairs.push_back(value);
    }
    
    for(int i = 1; i <=n; i++){
        cout << "PAIR: ";
        cout << i << " - ";
        cout << pairs[i] << "\n";
    }
}
