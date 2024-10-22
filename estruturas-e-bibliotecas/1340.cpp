//Eu Posso Adivinhar a Estrutura de Dados!
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

int main(){
    int n, op, val, i;

    while(cin >> n){
        queue<int> q;
        stack<int> s;
        priority_queue<int> pq;

        vector<bool> isDs(3, true);
        
        for(i = 0; i < n; i++){
            cin >> op >> val;

            if(op == 1){
                q.push(val);
                s.push(val);
                pq.push(val);
            }else if(op == 2){
                if(isDs[0]){
                    int qVal = q.front();
                    isDs[0] = qVal == val;
                    q.pop();
                }
                
                if(isDs[1]){
                    int sVal = s.top();
                    isDs[1] = sVal == val;
                    s.pop();
                }

                if(isDs[2]){
                    int pqVal = pq.top();
                    isDs[2] = pqVal == val;
                    pq.pop();
                }
            }
        }

        int bin = 0;
        i = 0;
        for(int j = 2; j >= 0; j--){
            bool ds = isDs[j];
            if(ds){ bin += (pow(2, i)); }
            i++;
        }

        switch(bin){
        case 4:
            cout << "queue" << endl;
            break;
        case 2:
            cout << "stack" << endl;
            break;
        case 1: 
            cout << "priority queue" << endl;
            break;
        case 0:
            cout << "impossible" << endl;
            break;
        default:
            cout << "not sure" << endl;
            break;
        }
    }
    
    return 0;
}