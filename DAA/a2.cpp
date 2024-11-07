#include<iostream>
#include<queue>

using namespace std;

class MinHeapNode{
    public:
    char data;
    int freq;
    MinHeapNode *left;
    MinHeapNode *right;

    MinHeapNode(char c, int f){
        data = c;
        freq = f;
        left = NULL;
        right = NULL;
    }

};

class Compare{
    public:
    bool operator()(MinHeapNode* a, MinHeapNode* b){
        return a->freq > b->freq;
    }
};

void print(MinHeapNode* root, string s){
    if(root == NULL)
        return;
    if(root->data != '$'){
        cout << root->data << " : " << s << endl;
    }
    print(root->left, s + "0");
    print(root->right, s + "1");
}

void huffmancode(char data[], int freq[], int n){
    MinHeapNode *left;
    MinHeapNode *right;
    priority_queue<MinHeapNode *, vector<MinHeapNode *>, Compare> pq;
    for (int i = 0; i < n; i++){
        pq.push(new MinHeapNode(data[i], freq[i]));
    }
    while(pq.size() != 1){
        left = pq.top();
        pq.pop();
        right = pq.top();
        pq.pop();
        MinHeapNode *temp = new MinHeapNode('$', left->freq + right->freq);
        temp->left = left;
        temp->right = right;
        pq.push(temp);
    }
    print(pq.top(), "");
}

int main(){

    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    cout << "Generated huffman code is: " << endl;
    huffmancode(data, freq, 6);
}