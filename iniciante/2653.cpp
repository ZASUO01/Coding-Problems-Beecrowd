//Dijkstra
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool found(vector<string> &jewels, string curr){
    bool found = false;
    
    for(string st : jewels){
        if(st == curr){
            found = true;
            break;
        }
    }

    return found;
}

int main(){
    string curr;
    vector<string> jewels;

    while(cin >> curr){
        if(!found(jewels, curr)){
            jewels.push_back(curr);
        }
    }

    cout << jewels.size() << endl;
    return  0;
}