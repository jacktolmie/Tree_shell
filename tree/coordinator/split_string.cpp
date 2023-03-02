#include "../tree_shell.hpp"

void Coordinator::split_string(std::string& sent, char split, std::vector<std::string>& vec){
    std::string word;
    std::for_each(sent.begin(), sent.end(), [&](auto& ch){

        if(ch != split) word += ch;
        else{
            vec.push_back(word);
            word = std::string();
            ch = '.';
        }
    }
                  );
    vec.push_back(word);
}
