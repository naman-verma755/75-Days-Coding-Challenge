class Solution {
public:
    int countPrimes(int n) {
        if(n <2)
            return 0;
        bool *primes = new bool[n+1];
  for(long long i =0; i<n+1; i++) {
    primes[i] = true;
  }
  long long sqr = sqrt(n+1);
  primes[0] = false;
  primes[1] = false;
  for(long long p=2; p<=sqr; p++){
    if(primes[p]) {
      for(long long i = p*p; i<n+1; i+=p) {
        primes[i] = false;
      }
    }
  }
        
        
        if(n <2)
            return 0;
        // cout<<primes[2]<<" ";
        int count = 0;
        for(int i = 2; i < n; i++) {
            if(primes[i])
                count++;
        }
        return count;
        
    }
};


// #include<bits/stdc++.h>
// typedef long long ll;
// #define MAX 1000000000
// using namespace std;
// int main() {
//   bool *primes = new bool[MAX+1];
//   for(ll i =0; i<MAX+1; i++) {
//     primes[i] = true;
//   }
//   ll sqr = sqrt(MAX);
//   primes[0] = false;
//   primes[1] = false;
//   for(ll p=2; p<=sqr; p++){
//     if(primes[p]) {
//       for(ll i = p*p; i<=MAX; i+=p) {
//         primes[i] = false;
//       }
//     }
//   }
//   cout<<"prime numbers done";
//   int t;
//   cin>>t;
//   while(t--){
//     ll m, n;
//     cin>>m>>n;