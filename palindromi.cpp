#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>    // std::sort

using namespace std;
string palindrom{""};

bool checkPalindrom(string input) {
    int count{1};
    int uneven{0};
    char temp{'a'};
    int help{0};
    std::map<char,int> m;
    for(std::string::size_type i = 0; i < input.size(); i++) {
        m[input[i]]++;
    }
    map<char , int >::iterator itr;
    for(auto const& x : m){
        ///cout << x.first << "-" << x.second << "\n";
        if (x.second % 2 == 0) {
            if(palindrom.size() % 2 == 0) {
                palindrom.insert(palindrom.size()/2, x.second, x.first);
            } else {
                palindrom.insert(palindrom.size()/2, x.second, x.first);
            } 
        } else {
            uneven++;
            if(uneven > 1){
                return false;
            }
            help = x.second;
            temp = x.first;
        }
         count++;
    }
    palindrom.insert(palindrom.size()/2, help, temp);
    return true;
}


int main() {
    string input;
    cin >> input;
    vector<char> chars;
    bool palindromFound{false};
    palindromFound = checkPalindrom(input);
    if(palindromFound == true){
        cout << palindrom << "\n";
    } else  {
        cout << "NO SOLUTION" << "\n";
    }
}
