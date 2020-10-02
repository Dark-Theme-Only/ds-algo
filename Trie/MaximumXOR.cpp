// Maximum XOR of two number in an array. This is a good first problem for people who are trying to implement Trie.
// Leetcode link: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    Node* child[2];

    Node() {
        child[0] = child[1] = NULL;
    }
};

Node* root = NULL;

void insert(string b) {
    Node* crawl = root;
    for(int i=0;i<b.length();i++) {
        int index = b[i] - '0';
        if(!crawl->child[index])
            crawl->child[index] = new Node();
        crawl = crawl->child[index];
    }
}

int findMaximumXOR(vector<int>& nums) {
    root = new Node();
    string ans = "";
    for(int num: nums) {
        string b = bitset<32> (num).to_string();
        // cout<<b<<'\t';
        insert(b);
        Node* crowl = root;
        string temp = "";
        for(int i=0; i<b.length();i++) {
            if(b[i] == '1') {
                if(crowl->child[0]) {
                    temp += '1';
                    crowl = crowl->child[0];
                }
                else {
                    temp += '0';
                    crowl = crowl->child[1];
                }
            } else {
                if(crowl->child[1]) {
                    temp += '1';
                    crowl = crowl->child[1];
                }
                else {
                    temp += '0';
                    crowl = crowl->child[0];
                }
            }
        }
        ans = max(ans, temp);
    }

    return stoull(ans, 0, 2);
}

int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<findMaximumXOR(a);
    return 0;
}
