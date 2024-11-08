//Canhão de Destruição
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

#define MAX(A, B) (A > B ? A : B)

//It returns the max firepower it's possible to put in a canon limited by ammo weight 
//(Bottom Up Knapsack algorithm)
int getMaxPower(int n, int capacity,  vector<pair<int, int>> &ammo){
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for(int currShot = 1; currShot <= n; currShot++){
        for(int currWeight = 0; currWeight <= capacity; currWeight++){
            int shotPower = ammo[currShot - 1].first;
            int shotWeight = ammo[currShot - 1].second;
            if(shotWeight <= currWeight){
                int included = dp[currShot - 1][currWeight - shotWeight] + shotPower;
                int notIncluded = dp[currShot - 1][currWeight];

                dp[currShot][currWeight] = MAX(included, notIncluded);
            }else{
                dp[currShot][currWeight] = dp[currShot - 1][currWeight];
            }
        }
    }

    return dp[n][capacity];
}


int main(){
    int c, n, x, y, k, r;

    cin >> c;

    for(int i = 0; i < c; i++){
        cin >> n;

        vector<pair<int, int>> ammo;

        for(int j = 0; j < n; j++){
            cin >> x >>  y;
            ammo.push_back({x, y});
        }

        cin >> k;
        cin >> r;

        int result = getMaxPower(n, k, ammo);
        if(result >= r){
            cout << "Missao completada com sucesso\n";
        }else{
            cout << "Falha na missao\n"; 
        }
    }

    return 0;
}