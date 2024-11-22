//Compras em FdI
#include <iostream>
#include <vector>
#include <utility>
#include <climits>

using namespace std;

#define MAX(a, b) a > b ? a : b
#define MIN(a, b) a < b ? a : b

class SegmentTree{
public:
    SegmentTree(vector<int> &input);
    pair<int, int> query(int left, int right);
    void update(int idx, int value);

private:
    vector<pair<int, int>> tree;      // node: {min, max}
    vector<int> list;
    int size;

    void buildRec(int node, int start, int end);
    void build();
    void updateRec(int node, int start, int end, int idx, int val);
    pair<int, int> queryRec(int node, int start, int end, int left, int right);
};

SegmentTree::SegmentTree(vector<int> &input){
    this->size = input.size();
    this->list = input;
    this->tree.resize(4 * this->size);
    build();
}

// it builds a segment tree from a list of values.
void SegmentTree::buildRec(int node, int start, int end){
    //  if it reached the leaf node then take the values from the original list
    if(start == end){
        this->tree[node] = {this->list[start], this->list[start]};
    }
    // navigate through the tree otherwise
    else{
        int mid = (start + end) / 2;
        int leftChild = (node * 2) + 1;
        int rightChild = (node * 2) + 2;
        
        // go to the left and right nodes
        buildRec(leftChild, start, mid);
        buildRec(rightChild, mid + 1, end);

        // set the current node min and max value
        int nodeMin = MIN(tree[leftChild].first, tree[rightChild].first);
        int nodeMax = MAX(tree[leftChild].second, tree[rightChild].second);

        tree[node] = {nodeMin, nodeMax};
    }
}

void SegmentTree::build(){
    buildRec(0, 0, this->size - 1);
}

// it updates a leaf node of the tree and propagates the change up in the tree
void SegmentTree::updateRec(int node, int start, int end, int idx, int value){
    // if it reachead the leaf node then update its value
    if(start == end){
        this->list[idx] = value;
        this->tree[node] = {value, value};
    }
    // navigate in the tree otherwise
    else{
        int mid = (start + end) / 2;
        int leftChild = (node * 2) + 1;
        int rightChild = (node * 2) + 2;

        // check only the side the index belongs
        if(idx <= mid){
            updateRec(leftChild, start, mid, idx, value);
        }else{
            updateRec(rightChild, mid + 1, end, idx, value);
        }
        
        // propagates the change
        int nodeMin = MIN(tree[leftChild].first, tree[rightChild].first);
        int nodeMax = MAX(tree[leftChild].second, tree[rightChild].second);

        tree[node] = {nodeMin, nodeMax};
    }
}

void SegmentTree::update(int idx, int value){
    updateRec(0, 0, this->size - 1, idx, value);
}

// it returns the correspondent node considering a given range 
pair<int, int> SegmentTree::queryRec(int node, int start, int end, int left, int right){
    if(left <= start && right >= end){
        return this->tree[node];
    }
    
    if(right < start || left > end){
        return {INT_MAX, INT_MIN};
    }
    
    int mid = (start + end) / 2;
    int leftChild = (node * 2) + 1;
    int rightChild = (node * 2) + 2;
    
    pair<int, int> leftQuery = queryRec(leftChild, start, mid, left, right);
    pair<int, int> rightQuery = queryRec(rightChild, mid + 1, end, left, right);

    int nodeMin = MIN(leftQuery.first, rightQuery.first);
    int nodeMax = MAX(leftQuery.second, rightQuery.second);

    return {nodeMin, nodeMax};
}

pair<int, int> SegmentTree::query(int left, int right){
    return queryRec(0, 0, this->size - 1, left, right);
}


int main(){
    int n, q, op, i, j, aux, k, key;

    while(scanf("%d", &n) != EOF){
        aux = n;
        vector<int> prices(n);        
        
        while(aux--){
            scanf("%d", &prices[n - aux - 1]);     
        }

        SegmentTree *st = new SegmentTree(prices);
        
        scanf("%d", &q);
        aux = q;

        while(q--){
            scanf("%d %d %d", &op, &i, &j);
        
            if(op == 1){
                st->update(i - 1, j);
            }else{
                pair<int, int> minMax = st->query(i - 1, j - 1);

                printf("%d\n", minMax.second - minMax.first);
            }
        }

        delete st;
    }
    
    return 0;
}