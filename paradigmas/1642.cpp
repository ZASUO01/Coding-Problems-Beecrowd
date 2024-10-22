//1642
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

#define MAX(a, b) (a > b ? a : b)

int getMaxSubSequence(int m, string &text) {
    unordered_map<char, int> charCount;
    int maxSequence = 0;
    int left = 0;

    for (int right = 0; right < text.size(); ++right) {
        charCount[text[right]]++;

        while (charCount.size() > m) {
            charCount[text[left]]--;
            if (charCount[text[left]] == 0) {
                charCount.erase(text[left]);
            }
            left++;
        }

        maxSequence = MAX(maxSequence, right - left + 1);
    }

    return maxSequence;
}

int main(){
    int m;
    string text;

    cin >> m;
    cin.ignore();

    while(m){
        getline(cin, text);

        cout << getMaxSubSequence(m, text) << endl;
        
        cin >> m;
        cin.ignore();
    }
    

    return 0;
}