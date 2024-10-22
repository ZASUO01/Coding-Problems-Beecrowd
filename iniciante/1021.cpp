//Notas e Moedas
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    double n;

    cin >> n;

    int iPart = (int)n;
    int dPart = (n - iPart)*100;

    int notes[] = {100, 50, 20, 10, 5, 2};
    int coins[] = {50, 25, 10, 5, 1};

    cout << "NOTAS:" << endl;
    for(int i = 0; i < 6; i++){
        int div = iPart/notes[i];
        cout << div << " nota(s) de R$ " << notes[i] <<".00" << endl;
        iPart%=notes[i];
    }

    
    cout << "MOEDAS:" << endl;
    cout << iPart << " moeda(s) de R$ 1.00" << endl;

    for(int i = 0; i < 5; i++){
        int div = dPart/coins[i];
        cout << div << " moeda(s) de R$ " << fixed << setprecision(2) << (double)coins[i]/100<< endl;
        dPart%=coins[i];
    }

    return 0;
}