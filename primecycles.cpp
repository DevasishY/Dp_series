#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;


int N;
int countCycles = 0;
set<int> used;
vector<bool> isPrime;


// Precompute primes up to 2N
void sieve(int limit) {
    isPrime.assign(limit + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= limit; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= limit; j += i)
                isPrime[j] = false;
        }
    }
}

void primeCycles(int level, int prev_elt){ // this gives level ...n-1 is cyclicprime or not
    //pruning
    
    //basecase
    if(level == N){
        if(isPrime[prev_elt+1])
        {
            countCycles++;
        }
        
        return;
    }
    //compute (choice, check)
     if((level&1) == 1){// i have only even choices
        for(int i = 2;i<=N;i=i+2)
        {
            if(!used.count(i) && isPrime[prev_elt + i])
            {
                used.insert(i);
                primeCycles(level+1, i);
                //backtrack
                used.erase(i);
            }
        }
     }
     if((level&1) == 0){// i have only odd choices
        for(int i = 3;i<=N;i=i+2)
        {
            if(!used.count(i) && isPrime[prev_elt + i])
            {
                used.insert(i);
                primeCycles(level+1, i);
                //backtrack
                used.erase(i);
            }
        }
     }
    
}



int main() {
    cin >> N;

    if (N % 2 == 1) {  // parity argument
        cout << 0 << endl;
        return 0;
    }

    sieve(2 * N);

    used.insert(1);

    primeCycles(1, 1); // pos 1 is fixed, start from true


    cout << countCycles << endl;
}