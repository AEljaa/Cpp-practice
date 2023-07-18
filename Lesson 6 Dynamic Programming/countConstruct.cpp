#include <iostream>
#include <map>


int countConstruct(std::string target, std::vector<std::string> wordBank, std::map<std::string, bool>& memo){
    int total=0 ;
    if(target==""){
        memo[target]=1;
        return 1;
    }
    for(auto i=0;i<wordBank.size();i++){
        if(target.find(wordBank[i])==0){
            std::string suffix = target.substr(wordBank[i].length(),target.length());
            auto numWays = countConstruct(suffix,wordBank,memo);
            total+=numWays;
            // if(){
            //     return 1;
            // }
        }
    }
    memo[target]=total;
    return total;    
}


int main() {
    std::map <std::string, bool> memo;
    std::cout << countConstruct("abcdef", {"ab", "abc", "cd", "def", "abcd"},memo) << std::endl; // true
    std::cout << countConstruct("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"},memo) << std::endl; // false
    std::cout << countConstruct("enterapotentpot", {"a", "p", "ent", "enter", "ot", "o", "t"},memo) << std::endl; // true
    std::cout << countConstruct("eeeeeeeeeeeddeeeeeeeeeeeeeeeeeeeeeeeeef", {"e", "ee", "eee", "eeee", "eeeee", "eeeeee"},memo) << std::endl; // false


}