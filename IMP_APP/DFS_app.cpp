const int MAX_N = 200005;

vector<int>vec[MAX_N];
int dep[MAX_N], par[MAX_N]; 
bool vis[MAX_N]; 
pii lol[MAX_N];
 
int path = 0; //global path calc
void dfs(int a, int p) {
	vis[a] = true; 
	dep[a] = dep[p] + 1;
	par[a] = p; path++;
    lol[a] = {path, path};
	for(auto i : vec[a]) {
		if(vis[i]) continue;
		dfs(i, a);
	}
    lol[a].second = path;
}

//dfs(1, 1)
