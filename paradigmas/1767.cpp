//Saco do Papai Noel
#include <iostream>
#include <vector>

using namespace std;

#define SIZE 50

vector<int> getMaxQuantity(int maxWeight, vector<int> &qts, vector<int> &weights, int n){
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(maxWeight + 1, {0, 0, 0}));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= maxWeight; j++){

            int currWeight = weights[i - 1];
            int currQtd = qts[i - 1];

            if(currWeight > j){
                dp[i][j] = dp[i-1][j];
            }else{
                vector<int> included = dp[i-1][j - currWeight]; 
                
                included[0] += currQtd;
                included[1] += currWeight;
                included[2] += 1;

                if(included[0] > dp[i-1][j][0]){
                    dp[i][j] = included;
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }

   return dp[n][maxWeight];
}

int main(){
    int n, pac, qt, weight, i, j, k;
    
    cin >> n;

    for(i= 0; i < n; i++){
        cin >> pac;

        vector<int> qts(pac);
        vector<int> weights(pac);
        
        for(j = 0; j < pac; j++){
            cin >> qts[j] >> weights[j];    
        }

        vector<int> result = getMaxQuantity(SIZE, qts, weights, pac); 

        cout << result[0] << " brinquedos" << endl;
        cout << "Peso: " << result[1] << " kg" << endl;
        cout << "sobra(m) " << (pac - result[2]) << " pacote(s)" << endl;
        cout << endl;
    }


    return 0;
}