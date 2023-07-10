#include <iostream>
#include <map>
using namespace std;

map<int, unsigned long long> memo;

unsigned long long fibo(int n) {
    if (memo[n]) {
        return memo[n];
    }

    if (n <= 1) {
        return n;
    }
    memo[n] = fibo(n-1) + fibo(n-2);
    return memo[n];
}

int main() {
    int n; 
    cin >> n;
    cout << "Ans: " << fibo(n)<<endl;

}