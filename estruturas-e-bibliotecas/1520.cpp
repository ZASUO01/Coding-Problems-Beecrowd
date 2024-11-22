//Parafusos e Porcas
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, num, i, j, l, r, gap;

    while(cin >> n){
        vector<int> lot;

        //add the numbers range to the lot
        for(i = 0; i < n; i++){
            cin >> l >> r;    
        
            for(j = l; j <= r; j++){
                lot.push_back(j);
            }
        }

        //sort the lot to group duplicated numbers
        sort(lot.begin(), lot.end());

        cin >> num;

        int sz = lot.size();
        bool found = true;

        int first = -1;
        int last;

        //check the first and the last position the target can be found
        for(i = 0; i < sz; i++){
            if(num == lot[i]){
                if(first == -1) first = i;
                last = i;
            }    
        }

        if(first != -1){
            cout <<  num << " found from " << first << " to " << last << "\n";
        }else{
            cout << num << " not found\n";
        } 
    }

    return 0;
}