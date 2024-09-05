//O Salão do Clube
#include<iostream>
#include<vector>

using namespace std;


int main(){
    int m, n, l, k;

    cin >> m >> n;

    while(m!= 0 && n!= 0){
        m*=100;
        n*=100;

        cin >> l;
        cin >> k;

        vector<int> pieces;
        vector<bool> chosenM;
        vector<bool> chosenN;

        int p;
        for(int i = 0; i < k; i++){
            cin >> p;
            pieces.push_back(p*100);
            chosenM.push_back(false);
            chosenN.push_back(false);
        }

        int mCount = 0;
        int nCount = 0;

        int size = pieces.size();
    
        if(m%l == 0){
          for(int i = 0; i < m; i+=l){
            int rest = n;
            int tempCount = 0;
            for(int j = size - 1; j >= 0; j--){
                if(pieces[j] <= rest && !chosenM[j]){
                  mCount++;
                  rest-=pieces[j];
                  tempCount++;

                  if(rest == 0 || tempCount >= 2){
                    j = -1;
                  }
                }

                if(j == 0 && rest != 0){
                  mCount = 0;
                  break;
                }
            }
          }
        } 
       
        if(n%l == 0){
          for(int i = 0; i < n; i+=l){
            int rest = m;
            int tempCount = 0;
            for(int j = size - 1; j >= 0; j--){
                if(pieces[j] <= rest && !chosenM[j]){
                  nCount++;
                  rest-=pieces[j];
                  tempCount++;

                  if(rest == 0 || tempCount >= 2){
                    j = -1;
                  }
                }

                if(j == 0 && rest != 0){
                  nCount = 0;
                  break;
                }
            }
          }
        }

        if(mCount == 0 & nCount == 0){
          cout << "impossivel" << endl;
        }else{
          cout << mCount << endl;
        }

        cin >> m >> n;
    }
    
    return 0;
}