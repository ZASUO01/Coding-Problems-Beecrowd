//Tomadas
#include <iostream>
#include <queue> 
 
using namespace std;

int main() {
    int t1, t2, t3, t4;
    cin >> t1 >> t2 >> t3 >> t4;
    
    queue<int> q;
    q.push(t1);
    q.push(t2);
    q.push(t3);
    q.push(t4);

    int result = 0;

    result += q.front();
    q.pop();

    while(result--){
        if(q.empty()) break;
        result += q.front();
        q.pop();
    }
    
    
    cout << result + 1 << "\n";

    return 0;
}