#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>    // std::sort
using namespace std;

//mahdollista jos: tornit samankorkuiset, sillon kun 3 jaolliset ja toinen ei max 2x isompi kun toinen

bool canStacksBeEmptied(int s1, int s2){
    if(s1 == 0 && s2 == 0){
        return true;
    }
    if(s1 > s2 * 2){
        return false;
    }
    if(s2 > s1 * 2) {
        return false;
    }
    if(s1 == 0 || s2 == 0){
        return false;
    }
    if((s1 + s2) % 3 == 0){
        return true;
    }
    return false;
}


int main() {
    int amount;
    cin >> amount;
    vector<pair<int, int>> stacks;
    for(int i = 0; i < amount; i++){
        int stack1, stack2;
        cin >> stack1 >> stack2;
        stacks.push_back(pair<int, int>(stack1, stack2));
    }
    for(int i = 0; i < stacks.size(); i++){
        if(stacks[i].first > stacks[i].second){
            if(canStacksBeEmptied(stacks[i].first, stacks[i].second) == true) {
                cout << "YES" << "\n";
            } else {
                cout << "NO" << "\n";
            } 
        } else {
            if(canStacksBeEmptied(stacks[i].second, stacks[i].first) == true){
                cout << "YES" << "\n";
            } else {
                cout << "NO" << "\n";
            } 
        }
    }
}
