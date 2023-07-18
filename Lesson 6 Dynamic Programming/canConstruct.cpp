#include <iostream>
#include <map>  
const bool canConstruct(std::string target, std::vector<std::string> wordBank,std::map <std::string, bool>&memo) {
    if(target == ""){
        memo[target]=true;
        return true;
    }
    for(auto i=0;i<wordBank.size();i++){
        if(target.find(wordBank[i]) == 0){
            std::string suffix = target.substr(wordBank[i].length(), target.length());
            if(canConstruct(suffix, wordBank,memo)){
                memo[target]=true;
                return true;
            }
        }
            
    }      
    memo[target]=false;                                              
    return false;
}

int main(){
    std::map <std::string, bool> memo;
    std::cout << canConstruct("abcdef", {"ab", "abc", "cd", "def", "abcd"},memo) << std::endl; // true
    std::cout << canConstruct("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"},memo) << std::endl; // false
    std::cout << canConstruct("enterapotentpot", {"a", "p", "ent", "enter", "ot", "o", "t"},memo) << std::endl; // true
    std::cout << canConstruct("eeeeeeeeeeeddeeeeeeeeeeeeeeeeeeeeeeeeef", {"e", "ee", "eee", "eeee", "eeeee", "eeeeee"},memo) << std::endl; // false

}


