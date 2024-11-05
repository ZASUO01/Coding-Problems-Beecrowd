//Máquina Dobradora
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Given an index of the original vector, it returns the result vector after a fold
vector<int> getFold(int index, vector<int> &vec){
    vector<int> left(vec.begin(), vec.begin() + index);
    vector<int> right(vec.begin() + index, vec.end());
    reverse(right.begin(), right.end());

    int lSize = left.size();
    int rSize = right.size();

    if(lSize > rSize){
        for(int i = 0; i < rSize; i++){
            int lIdx = lSize - rSize + i;
            left[lIdx] += right[i];
        }

        return left;
    }else{
        for(int i = 0; i < lSize; i++){
            int rIdx = rSize - lSize + i;
            right[rIdx] += left[i];
        }

        return right;
    }
}

//Aux function to check if the fold is equal the original vector reversed
bool compareReverse(vector<int> &input, vector<int> &output){
    vector<int> temp(input.begin(), input.end());
    reverse(temp.begin(), temp.end());

    return(temp == output);
}

//Compare an original vector to a folded vector. 
//It returns true if the the folded can be achived by folding the original
bool compareFold(vector<int> &input, vector<int> &output){
    //Base cases
    if(input == output) return true;
    if(compareReverse(input, output)) return true;

    bool isEqual = false;

    //Iterate through each vector position and get a fold from it
    for(int i = 1; i < input.size(); i++){
        if(isEqual) break;

        vector<int> fold = getFold(i, input);

        if(fold.size() < output.size()) continue;

        //if a fold from this position is equal to the output then return true
        //else, try folding from the current fold until finding some equal to the output
        if(fold == output){
            isEqual = true;
            break;
        }else{
            isEqual = compareFold(fold, output);
        }
    }

    return isEqual;
}

int main(){
    int m, n;

    while(cin >> m){
        vector<int> input(m);
        
        for(int i = 0; i < m; i++){
            cin >> input[i];
        }

        cin >> n;

        vector<int> output(n);

        for(int i = 0; i < n; i++){
            cin >> output[i];
        }
 
        bool isEqual = compareFold(input, output);

        if(isEqual){
            cout << "S" << endl;
        }else{
            cout << "N" << endl;
        }
        
    }

    return 0;
}