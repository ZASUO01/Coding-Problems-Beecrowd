#include <iostream>
#include <string>

using namespace std;

int parseHeader(string header){
    int count = 0;

    for(char c : header){
        if(c == 'P'){
            count++;
        }else if(c == 'T'){
            break;
        }
    }

    return count;
}

int main(){
    int c;

    cin >> c;

    while(c--){
        string line;

        cin >> line;

        int productNum = parseHeader(line);

        string subLine = line.substr(0,2);
        while(subLine != "TP"){
            cin >> line;

            subLine = line.substr(0,2);
        }
        
    
        for(int i = 1; i <=  productNum; i++){
            cout << "P" << i << " ";
        }
        cout << "Totals" << endl;
    }   

    return 0;
}