#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>    // std::sort
using namespace std;

vector<string> words;

int main() {
    long amount;
    cin >> amount;
    for(int i = 0; i < amount; i++){
        string word;
        cin >> word;
        sort(word.begin(), word.end());
        words.push_back(word);
    }
    sort(words.begin(), words.end());
    //cout << "-------" << "\n";
    map<string, int> groups;
    for(int i = 0; i < words.size(); i++){
        groups[words[i]]++;
    }
    cout << groups.size() << "\n";
    
}
