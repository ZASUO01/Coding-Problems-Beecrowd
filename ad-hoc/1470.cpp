//Máquina Dobradora
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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

bool compareReverse(vector<int> &input, vector<int> &output){
    vector<int> temp(input.begin(), input.end());
    reverse(temp.begin(), temp.end());

    return(temp == output);
}

bool compareFold(vector<int> &input, vector<int> &output){
    if(input == output) return true;
    if(compareReverse(input, output)) return true;

    bool isEqual = false;

    for(int i = 1; i < input.size(); i++){
        if(isEqual) break;

        vector<int> fold = getFold(i, input);

        if(fold.size() < output.size()) continue;

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