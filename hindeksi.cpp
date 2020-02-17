#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>    // std::sort
using namespace std;

vector<int> refs;

int main() {
    long amount;
    cin >> amount;
    for(int i = 0; i < amount; i++){
        int refamount;
        cin >> refamount;
        refs.push_back(refamount);
    }
    long refcount{0};
    long index{0};
    if(refs.size() == 1){
        cout << 0 << "\n";
    }
    bool c{false};
    sort(refs.begin(), refs.end());
    for(int i = refs.size()-1; i > 0; i--){
        index++;
        //cout << refs[i] << "\n";
        if(refs[i] > refs[i-1]){
            refcount = index;
        }
        if(refs[i] = refs[i-1]){
            refcount++;
            //cout << "refcount: " << refcount << "\n";
            if(index >= refs[i-1]){
                cout << index << "\n";
                c = true;
                break;
            }
        }
    }
    if(c == false && refs.size() != 1) {
        cout << index +1 << "\n";
    }
}
