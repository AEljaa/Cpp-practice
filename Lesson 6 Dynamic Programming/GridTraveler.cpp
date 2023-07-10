#include <iostream>
#include <map>
using namespace std;



const int gridTraveler(int x,int y,map<pair<int, int>, int> memo) {
    //if we have already computed the value, return it
    if(memo[{x,y}]){
        return memo[{x,y}];
    }
    //Base cases
    if(x==0 || y==0){
        return 0;
    }
    if(x==1 && y==1){
        return 1;
    }
    //Recursive calls, store the result in the memo
    memo[{x,y}]=gridTraveler(x-1,y,memo)+gridTraveler(x,y-1,memo);
    return memo[{x,y}];

}

int main() {
    int x,y; 
    cin >> x >> y;
    map<pair<int, int>, int> memo;
    cout << "Ans: " << gridTraveler(x, y, memo) << endl;
    for (const auto& kvp : memo) {
        cout << "Key: (" << kvp.first.first << ", " << kvp.first.second << "), Value: " << kvp.second << endl;
    }

}