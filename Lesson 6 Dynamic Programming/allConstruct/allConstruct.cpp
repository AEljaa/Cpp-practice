#include <iostream>
#include <map>
#include <vector>

std::vector<std::vector<std::string>> allConstruct(std::string target, std::vector<std::string> wordBank,std::map<std::string, std::vector<std::vector<std::string>>>&memo) {
    if(memo.find(target)!=memo.end()){
        return memo[target];
    }
    if(target==""){
        return {{}};
    }
    std::vector<std::vector<std::string>> targetWays;
    for(auto i=0;i<wordBank.size();i++){
        if(target.find(wordBank[i]) == 0){
            std::string suffix = target.substr(wordBank[i].length(), target.length());
            auto suffixWays=allConstruct(suffix,wordBank,memo);
            for(auto j=0;j<suffixWays.size();j++){
                suffixWays[j].insert(suffixWays[j].begin(),wordBank[i]);
                targetWays.push_back(suffixWays[j]);
            }
        }
    }
    memo[target]=targetWays;
    return targetWays;
}

int main(){
    std::vector<std::vector <std::string>> vec;
    // std::map <std::string, bool> memo;
    std::map<std::string, std::vector<std::vector<std::string>>> memo;
    vec=allConstruct("purple",{"purp","p","ur","le","purpl"},memo);
    for(auto i=0;i<vec.size();i++){
        for(auto j=0;j<vec[i].size();j++){
            std::cout << vec[i][j] << " ";
        }
        std::cout << std::endl;
    }
}