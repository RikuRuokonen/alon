#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>    // std::sort
using namespace std;

vector<pair<string, int>> results;

bool sortbyname(const pair<string,int> &a, 
              const pair<string, int> &b) 
{ 
    if(a.second == b.second){
        return a.first < b.first;
    }
    return (a.second > b.second); 
}

int main() {
    int amount;
    cin >> amount;
    for(int i = 0; i < amount; i++){
        string name;
        int score;
        cin >> name >> score;
        results.push_back(pair<string, int>(name, score));
    }
    sort(results.begin(), results.end(), sortbyname);
    for(int i = 0; i < results.size(); i++){
        cout << results[i].first << " " << results[i].second << "\n"; 
    }
}
