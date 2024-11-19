//Sort! Sort!! e Sort!!!
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main(){
    int n, m, i;

    cin >> n >> m;

    while(n != 0 && m != 0){
        vector<int> lst(n);

        for(i = 0; i < n; i++){
            cin >> lst[i];
        }

        sort(lst.begin(), lst.end(), [m](int p1, int p2){
            int mod1 = p1 % m;
            int mod2 = p2 % m;
            int evenP1 = p1 % 2;
            int evenP2 = p2 % 2;

            if(mod1 == mod2){
                if(evenP1 == 0 &&  evenP2 == 0) return p1 < p2;
                else if(evenP1 != 0 && evenP2 != 0) return p1 > p2;
                else if(evenP1 != 0 && evenP2 == 0) return true;
                else return false;
            }else{
                return mod1 < mod2;
            }
        });

        cout << n << " " << m << "\n"; 
        for(i = 0; i < n; i++){
            cout << lst[i] << "\n";
        }
        cin >> n >> m;
    }

    cout << "0 0\n";  

    return 0;
}