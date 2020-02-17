#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>    // std::sort
#include <set>

using namespace std;

int main() {
    long amount;
    cin >> amount;
    vector<long> additions;
    multiset<long> numbers;
    for(long i = 0; i < amount; i++){
        long num;
        cin >> num;
        numbers.insert(num);
    }
    auto it = numbers.begin();
    auto nxt = next(it);
    long previous{-1};
    while (it != numbers.end()) {
        if(previous >= 0){
            //cout << "works" << "\n";
            long sum = previous + *it;
            additions.push_back(sum);
            numbers.insert(sum);
            it = numbers.erase(numbers.find(previous));
            it = numbers.erase(numbers.find(*it));
        }
        previous = *it;
        it++;
    }
    
    for(long i = 0; i < additions.size(); i++){
        cout << additions[i] << "\n";
    }
}
