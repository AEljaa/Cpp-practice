#include <iostream>
#include <vector>
#include <map>

bool canSum(int targetsum, std::vector<int>& vec, std::map<int, bool>& memo) {
    if (memo.count(targetsum) > 0){
        return memo[targetsum];
    }
    if (targetsum == 0) {
        memo[targetsum] = true;
        return memo[targetsum];
    }
    if (targetsum < 0) {
        memo[targetsum] = false;
        return memo[targetsum];
    }
    for (int i = 0; i < vec.size(); i++) {
        int newval = targetsum - vec[i];
        if (canSum(newval, vec, memo)) {
            memo[targetsum] = true;
            return memo[targetsum];
        }
    }
    memo[targetsum] = false;
    return memo[targetsum];
}

int main(){
    int trgt=300;
    // std::cout<<"Enter the target number"<<std::endl;
    // trgt=7
    // std::cout<<"Enter How"
    std::vector<int> vec;
    std::map<int, bool> memo;
    for(int i=0;i<2;i++){
        vec.push_back((i+1)*7);
    }
    std::cout<<canSum(trgt,vec,memo)<<std::endl;


}
