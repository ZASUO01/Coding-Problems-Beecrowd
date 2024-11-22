//Lista Telefônica Econômica
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int numbersCount, economyNum, numSize, i, j;
    
    //read number of numbers
    while(cin >> numbersCount){
        cin.ignore();
        economyNum = 0;
        vector<string> numbers(numbersCount);

        //read the first number of the list to get its size
        getline(cin, numbers[0]);
        numSize = numbers[0].size();

        //read the others
        for(i = 1; i < numbersCount; i++){
            getline(cin, numbers[i]);
        }
        
        //sort the list of numbers to maximize the economy
        sort(numbers.begin(), numbers.end());

        //compare a number sufix to its previous number sufix
        for(i = 1; i < numbersCount; i++){
            for(j = 0; j < numSize; j++){
                if(numbers[i][j] == numbers[i - 1][j]) economyNum++;
                else break;
            }
        }
        
        cout << economyNum << "\n";
    }

    return  0;
}