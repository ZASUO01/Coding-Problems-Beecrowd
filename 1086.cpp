#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int minBoardsToCover(int length, vector<int>& boards) {
    vector<int> dp(length + 1, INT_MAX);
    dp[0] = 0;
    
    for (int i = 1; i <= length; ++i) {
        for (int board : boards) {
            if (i >= board && dp[i - board] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - board] + 1);
            }
        }
    }
    
    return dp[length] == INT_MAX ? -1 : dp[length];
}

int main() {
    int M, N, L, K;
    while (cin >> M >> N, M || N) {
        cin >> L;
        cin >> K;
        vector<int> boards(K);
        for (int i = 0; i < K; ++i) {
            cin >> boards[i];
        }

        int length1 = M;
        int length2 = N;

        int width = L / 100; // Convert width to meters

        if (width <= 0) {
            cout << "impossivel" << endl;
            continue;
        }

        int minBoardsForDimension1 = minBoardsToCover(length1, boards);
        int minBoardsForDimension2 = minBoardsToCover(length2, boards);

        if (minBoardsForDimension1 == -1 && minBoardsForDimension2 == -1) {
            cout << "impossivel" << endl;
        } else {
            int minBoards = INT_MAX;
            if (minBoardsForDimension1 != -1) {
                minBoards = min(minBoards, minBoardsForDimension1);
            }
            if (minBoardsForDimension2 != -1) {
                minBoards = min(minBoards, minBoardsForDimension2);
            }
            cout << minBoards << endl;
        }
    }
    return 0;
}