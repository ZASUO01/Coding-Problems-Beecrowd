//Em Braille
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define BOOLTOSIGN(N) (N ? '*' : '.')
#define SIGNTOBOOL(S) (S == '*' ? 1 : S == '.' ? 0 : -1);

void printBraille(vector<vector<bool>> &seq){
    int i;
    int size = seq.size();

    for(i =  0; i < size; i++){
        cout << BOOLTOSIGN(seq[i][0]) << BOOLTOSIGN(seq[i][1]);
        if(i != (size - 1)) cout << " ";
    }

    cout << endl;

    for(i =  0; i < size; i++){
        cout << BOOLTOSIGN(seq[i][2]) << BOOLTOSIGN(seq[i][3]);
        if(i != (size - 1)) cout << " ";
    }

    cout << endl;

    for(i =  0; i < size; i++){
        cout << BOOLTOSIGN(seq[i][4]) << BOOLTOSIGN(seq[i][5]);
        if(i != (size - 1)) cout << " ";
    }

    cout << endl;
}

bool compareBraille(vector<bool> &a, vector<bool> &b){
    int size = a.size();

    bool equal = true;

    for(int i = 0; i < size; i++){
        if(a[i] != b[i]){
            equal = false;
            break;
        }
    }
    return equal;
}

int main(){
    int d, i;
    char op;

    //Dictionary of Braille symbols
    vector<vector<bool>> dict(10, vector<bool>(6));
    dict[0] = {0, 1, 1, 1, 0, 0};
    dict[1] = {1, 0, 0, 0, 0, 0};
    dict[2] = {1, 0, 1, 0, 0, 0};
    dict[3] = {1, 1, 0, 0, 0, 0};
    dict[4] = {1, 1, 0, 1, 0, 0};
    dict[5] = {1, 0, 0, 1, 0, 0};
    dict[6] = {1, 1, 1, 0, 0, 0};
    dict[7] = {1, 1, 1, 1, 0, 0};
    dict[8] = {1, 0, 1, 1, 0, 0};
    dict[9] = {0, 1, 1, 0, 0, 0};

    cin >> d;

    while(d != 0){
        cin >> op;
        
        if(op == 'S'){
            vector<vector<bool>> bValues(d, vector<bool>(6));
            string aux;
            int idx;

            cin >> aux;

            for(i = 0; i < d; i++){ 
                idx = int(aux[i]) - 48;
                vector<bool> temp = dict[idx];
                bValues[i] = temp;
            }

            printBraille(bValues);

        }else if (op == 'B'){
            vector<vector<bool>> bValues(d, vector<bool>(6));
            string aux;
            
            for(i = 0; i < d; i++){
                cin >> aux;
                bValues[i][0] = SIGNTOBOOL(aux[0]);
                bValues[i][1] = SIGNTOBOOL(aux[1]);     
            }

            for(i = 0; i < d; i++){
                cin >> aux;
                bValues[i][2] = SIGNTOBOOL(aux[0]);
                bValues[i][3] = SIGNTOBOOL(aux[1]);
            }

            for(i = 0; i < d; i++){
                cin >> aux;
                bValues[i][4] = SIGNTOBOOL(aux[0]);
                bValues[i][5] = SIGNTOBOOL(aux[1]);
            }

            for(i = 0; i < d; i++){
                int j;
                vector<bool> temp = bValues[i];

                for(j = 0; j < 10; j++){
                    vector<bool> temp2 = dict[j];

                    if(compareBraille(temp, temp2)){ break;}
                }

                cout << j;
            }

            cout << endl;
        }


        cin >> d;
    }
    

    return 0;
}