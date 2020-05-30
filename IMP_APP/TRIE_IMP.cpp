struct TrieNode {
    TrieNode *t[26];
    int end;
    void display() { cout << end << " "; int cou = 0; for(int i=0;i<26;i++) { if(!(t[i])) cou++; } cout << cou << "\n"; }
};
TrieNode* getnode() {
    TrieNode* p = new TrieNode(); p->end = 0; 
    for(int i=0;i<26;i++) { p->t[i] = NULL; }
    return p;
}
void add(TrieNode* root, string str) {
    TrieNode *p = root;
    for(int i=0;i<str.size();i++) {
        int ch = str[i] - 'A';
        if(!(p->t[ch])) { p->t[ch] = getnode(); }
        p = p->t[ch];
    }
    p->end++; return;
}
pll merge(pll a, pll b) {
    return {a.first + b.first, a.second + b.second};
}
pll dfs(TrieNode *root) {
    pll temp = {0, 0};
    TrieNode *p = root;
    for(int i=0;i<26;i++) {
        if((p->t[i])) { temp = merge(temp, dfs(p->t[i])); }
    }
    temp.second += p->end;
    if(temp.second >= 2) { temp.first++; temp.second -= 2; }
    return temp;
}
