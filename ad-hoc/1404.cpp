//MegaDamas
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>

using namespace std;

#define EVEN(a) (a % 2 == 0) 

//It returns the maximum number of pieces the player 1 can capture in 1 round given a initial board state
//It uses memoization to avoid calculating a board state value twice
int getMaxMoves(int m, int n, int y, int x, string board, unordered_map<string, int> &memo){
    //initially the max value of captures is 0
    int max = 0;
    
    //Check if the current state was calculated before
    string key = board + "_" + to_string(x) + "_" + to_string(y);  
    if(memo.find(key) != memo.end()){
        return memo[key];
    }

    //Check all the four sides to see where a capture can be executed
    //If can capure, then update the board, add 1 to number of captures and call the function with the updated state
    //Check if the chosen movment will be greater than the current maxmium value of captures
    int pos = (y * n) + x;
    
    //Top Left
    if((y - 2) >= 0 && (x - 2) >= 0 && board[pos - n - 1] == '2' && board[pos - 2*n - 2] == '0'){
        string newBoard = board;
        newBoard[pos] = '0';
        newBoard[pos - n - 1] = '0';
        newBoard[pos - 2*n - 2] = '1';
        int curr = 1 + getMaxMoves(m, n, y - 2, x - 2, newBoard, memo);
        if(curr > max) max = curr;
    }

    //Top Right
     if((y - 2) >= 0 && (x + 2) < n && board[pos - n + 1] == '2' && board[pos - 2*n + 2] == '0'){
        string newBoard = board;
        newBoard[pos] = '0';
        newBoard[pos - n + 1] = '0';
        newBoard[pos - 2*n + 2] = '1';
        int curr = 1 + getMaxMoves(m, n, y - 2, x + 2, newBoard, memo);
        if(curr > max) max = curr;
    }

    //Bottom Left
    if((y + 2) < m  && (x - 2) >= 0 && board[pos + n - 1] == '2' && board[pos + 2*n - 2] == '0'){
        string newBoard = board;
        newBoard[pos] = '0';
        newBoard[pos + n - 1] = '0';
        newBoard[pos + 2*n - 2] = '1';
        int curr = 1 + getMaxMoves(m, n, y + 2, x - 2, newBoard, memo);
        if(curr > max) max = curr;
    }

    //Bottom Right
    if((y + 2) < m && (x + 2) < n && board[pos + n + 1] == '2' && board[pos + 2*n + 2] == '0'){
        string newBoard = board;
        newBoard[pos] = '0';
        newBoard[pos + n + 1] = '0';
        newBoard[pos + 2*n + 2] = '1';
        int curr = 1 + getMaxMoves(m, n, y + 2, x + 2, newBoard, memo);
        if(curr > max) max = curr;
    }

    //Store the maximum value of the current state and return it
    memo[key] = max;
    return max;
}


int main(){
    int m, n;

    cin >> m >> n;
    
    while(m != 0 && n != 0){
       string board = "";

       vector<pair<int, int>> player1;

        char ch;
        for(int i = m - 1; i >= 0; i--){
            string subs = "";
            for(int j = 0; j < n; j++){   
                int row = (m - i + 1);

                if((EVEN(j) && EVEN(row)) || (!EVEN(j) && !EVEN(row))){
                    cin >> ch;
                    subs += ch;

                    if(ch == '1') player1.push_back({i, j});
                }else{
                    subs += '0';
                }
            }
            board = subs + board;
        }
         
        int max = 0;
        for(pair<int, int> pos : player1){    
            unordered_map<string, int> memo;
            int tempMax = getMaxMoves(m, n, pos.first, pos.second, board, memo);
            if(tempMax > max) max = tempMax;
        }

        cout << max << endl;

        cin >> m >> n;
    }
    return 0;
}