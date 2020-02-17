#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>    // std::sort
using namespace std;

std::map<char,int> m;

int main() {
    string input;
    cin >> input;
    string str1;
    string str2;
    std::map<char,int> m;
    for(std::string::size_type i = 0; i < input.size(); i++) {
        m[input[i]]++;
    }
    std::sort( std::begin( input ) , std::end( input ) , 
        [&]( char lhs , char rhs )
        {
            return m[lhs] > m[rhs];
        }
        );
    //cout << m[input[0]] << "--" << input.size()/2 << "\n";
    if(m[input[0]] > input.size()/2 && input.size() % 2 == 0){
        cout << "-1" << "\n";
    }else if(m[input[0]] > input.size()/2 +1 && input.size() % 2 != 0){
        cout << "-1" << "\n";
    } else if (input.size() % 2 == 0) {
        //cout << input << "\n";
        string final;
        for(std::string::size_type i = 0; i < input.size()/2; i++) {
            //cout << input[i];
            //cout << "--";
            //cout << input[input.size()/2+i] <<"\n";
            final += input[i];
            final += input[input.size()/2+i]; 
        }
        cout << final << "\n";
    } else {
        //cout << input << "\n";
        string final;
        for(std::string::size_type i = 0; i < input.size()/2; i++) {
            //cout << input[i];
            //cout << "--";
            //cout << input[input.size()/2+i] <<"\n";
            final += input[i];
            final += input[input.size()-i-1]; 
            if(final.size() == input.size()-1){
                final += input[i+1];
            }
        }
        cout << final << "\n";
        
    }
}
