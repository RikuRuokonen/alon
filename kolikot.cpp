#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>    // std::sort
using namespace std;

vector<long> coins;
vector<int> added;
long missing{0};

int main() {
    long amount;
    cin >> amount;
    for(int i = 0; i < amount; i++){
        int coin;
        cin >> coin;
        coins.push_back(coin);
    }
    sort(coins.begin(), coins.end());
    //cout << "-------" << "\n";
    long cumul{0};
    if(coins[0] == 1){
        for(long i = 0; i < coins.size(); i++){
            cumul = cumul + coins[i];
            //cout << coins[i] << "\n";
            if(coins[i] == coins[i+1]){
                //cout << "first continue" << "\n";
                continue;
                //seuraava case: i+1 on enemmän kuin 1 isompi kuin i -> välistä puuttuu raaka kolikko jolla muodostaa
            }
            //cout << "compare: " << coins[i+1] << "-" << cumul << "\n";
            if(coins[i+1] > cumul + 1){
                //cout << "missing found: " << cumul + 1 << "\n";
                missing = cumul +1;
                //cout << "breaking condition" << "\n";
                break;
            }
            
        }   
    } else {
        missing = 1;
    }
    if(missing == 0){
        missing = cumul + 1;
    }
    cout << missing << "\n";
}
