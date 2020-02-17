#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>    // std::sort

using namespace std;
string palindrom{""};

bool checkPalindrom(string input, bool even) {
    vector<char> parsed;
    string sorted = input;
    sort(sorted.begin(), sorted.end());
    for(char& c : sorted ) {
        parsed.push_back(c);
    }
    bool failure{false};
    if(even == true){
        for (int i = 0; i <= parsed.size(); i += 2) {
            if(parsed[i] != parsed[i+1]){
              failure = true;
            }
        }
        if(failure == true){
            return false;
        } else {
            for(char& c : sorted ) {
                if(palindrom.size() < 2) {
                    palindrom.append(1, c);
                } else {
                    palindrom.insert(palindrom.size()/2, 1, c);
                }    
            }
            return true;
        }
    } else {
        int count{0};
        string temp = sorted;
        vector<char> uneven;
        std::map<char,int> m;
        for (int i = 0; i <= parsed.size()-1; i++) {
            count++;
            if(parsed[i] != parsed[i+1]){
                m[parsed[i]] = count;
                count = 0;
            }
        }
        int unevenCount{0};
        for (const auto &p : m) {
            if(p.second % 2 != 0){
                unevenCount++;
                temp.erase(std::remove(temp.begin(), temp.end(), p.first), temp.end());
                for (int i = 0; i < p.second; i++) {
                    palindrom.append(1, p.first);
                }
            }
        }
        if(unevenCount > 1 ) {
            return false;
        }
        int index{0};
        for(char& c : temp ) {
            index++;
            if(index % 2 == 0) {
                palindrom.append(1, c);
            } else {
                palindrom.insert(0, 1, c);
            }
              
        }
        return true;
    }
    return false;
    
}


int main() {
    string input;
    cin >> input;
    vector<char> chars;
    bool palindromFound{false};
    if(input.size() % 2 == 0){
        palindromFound = checkPalindrom(input, true);
    } else {
        palindromFound = checkPalindrom(input, false);
    }
    if(palindromFound == true){
        cout << palindrom << "\n";
    } else  {
        cout << "NO SOLUTION" << "\n";
    }
}
