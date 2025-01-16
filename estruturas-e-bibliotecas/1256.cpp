//Tabelas Hash
#include <iostream>
#include <vector>

using namespace std;


int main(){
  int n, m, c, i, j;

  cin >> n;

  while(n--){
    cin >> m >> c;

    vector<vector<int>> hashTable(m, vector<int>());

    int num, index;
    for(i = 0; i <  c; i++){
      cin >> num;
      index = num % m;

      hashTable[index].push_back(num);
    }
  
    for(i = 0; i < m; i++){
      cout << i << " -> ";
      int sz = hashTable[i].size();

      for(j = 0; j < sz; j++){
        cout << hashTable[i][j] << " -> ";
      }

      cout << "\\" << endl;
    }

    if(n > 0){
      cout << endl;
    }
  }

  return 0;
}
