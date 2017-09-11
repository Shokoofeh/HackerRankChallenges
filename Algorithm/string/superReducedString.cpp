#include <iostream>
#include <string>


std::string super_reduced_string(std::string s){
    
    if (s.empty()) {   
        return "Empty String";
    }
    
    int i = 1;
    while (i < s.size()) {
        if (s[i] == s[i - 1]) {
            s.erase(s.begin() + i - 1, s.begin() + i + 1);
            if (s.empty()) {   
                return "Empty String";
            }
            i = (i == 1) ? i : i - 1;
        }
        else {
            i++;
        }
    }
    
    return s;
}

int main() {
    std::string s;
    std::cin >> s;
    std::string result = super_reduced_string(s);
    std::cout << result << std::endl;
    return 0;
}