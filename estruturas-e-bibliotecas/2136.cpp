//Amigos do Habay
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main(){
    string name, option;

    cin >> name >> option;

    //Unordered map to deal with duplicates
    unordered_map<string, pair<string, int>> candidatesMap; // {name: {option, order}}
    
    int order = 0;
    while(name != "FIM"){
        if(candidatesMap.find(name) == candidatesMap.end()){
            order++;
            candidatesMap[name] = {option, order}; 
        }
    
        cin >> name >> option;
    }

    //copy unordered map to a vector to apply order function
    vector<pair<string, pair<string, int>>> candidatesVec(candidatesMap.begin(), candidatesMap.end());

    //Ordered by option and alphabetical order
    sort(candidatesVec.begin(), candidatesVec.end(), [](pair<string, pair<string, int>> &p1, pair<string, pair<string, int>> &p2){
        if(p1.second.first == p2.second.first){
            return p1.first < p2.first;
        }
        
        return p1.second.first == "YES";
    });

    int sz = candidatesVec.size();

     for(int i = 0; i < sz; i++){
        cout << candidatesVec[i].first << "\n";
    }
    
    //Ordered by option, name size, and order priority 
    sort(candidatesVec.begin(), candidatesVec.end(), [](pair<string, pair<string, int>> &p1, pair<string, pair<string, int>> &p2){
        if(p1.second.first == p2.second.first){
            if(p1.first.size() == p2.first.size()){
                return p1.second.second < p2.second.second;
            }

            return p1.first.size() > p2.first.size();
        }
        
        return p1.second.first == "YES";
    });

    cout << "\n";
    cout << "Amigo do Habay:\n";
    cout << candidatesVec[0].first << "\n";  
    

    return 0;

}