#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>    // std::sort
#include <set>

using namespace std;

int main() {
    long cAm, rAm; //customer amount && room amount
    cin >> rAm >> cAm;
    multiset<long>rooms;
    vector<long> cRequirements;
    for(long i = 0; i < rAm; i++){
        long num2;
        cin >> num2;
        rooms.insert(num2);
    }
    for(long i = 0; i < cAm; i++){
        long num;
        cin >> num;
        cRequirements.push_back(num);
    }
    for(long i = 0; i < cRequirements.size(); i++){
        if(rooms.lower_bound(cRequirements[i]) == rooms.end()){
            cout << "-1" << " " << " ";
        } else{
            long x = *rooms.lower_bound(cRequirements[i]);
            //cout << "----iteration starts---" << "\n";
            if(x < cRequirements[i]){
                cout << "-1" << " " << " ";
            } else {
                cout <<  x << " ";
                //cout << "try to erase" << "\n";
                rooms.erase(rooms.find(x));
            }   
        }
        //cout << "----iteration ends---" << "\n";
    }
    cout << "\n";

}
