#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>    // std::sort
using namespace std;

int main() {
    int amount;
    cin >> amount;
    vector<int> numbers;
    for(int i = 0; i < amount; i++){
        int num;
        cin >> num;
        numbers.push_back(num);
    }
    for(int i = 0; i < numbers.size(); i++){
        cout << numbers[i] << "\n"; 
    }
}
