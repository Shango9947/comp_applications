# Lichao Tree Explanation and Code

Let us assume we want to find out the min value and we have n lines given as (Mi, Ci). First let us have a line (0, inf) which is the topmost line 

Now we are inserting a line : if the line have lower value than value at the segment node for some segment in the left and right, we need to update the line as the new line, if not we need to call it to the side which is expected it to have the lower value.

Let us check left, mid. True if the value is less than the given line at segment node, let us see :

| Left (nice) | Mid(niche) | Update current Node | Forward Update |
| --------- | ---------- | ------- | --------- |
| true | true |   Update with new line | now update **right** side with **previous segment node** |
| true | false |  No - Update | now update **left** side with **new line** |
| false | true |  Update with new line | now update **left** side with **previous segment node** | 
| false | false | No - Update | now update **right** side with **new line** |

> Update segment node : Mid = true

> Right : Left == Mid

> Left : Left != Mid

> Previous segment Forward / New line forward = Update segment (hence change accordingly while updating current node) 


```
const int maxn = 2e5;
const long long int inf = 1e18;

pair<ll, ll> line[4 * maxn] = {{0, inf}}; 

void add_line(pair<ll, ll> nw, int v = 1, int l = 0, int r = maxn) {
    int m = (l + r) / 2;
    bool lef = (nw.first*l + nw.second) < (line[v].first*l + line[v].second);
    bool mid = (nw.first*m + nw.second) < (line[v].first*m + line[v].second);
    if(mid) {
        swap(line[v], nw);
    }
    if(r - l == 1) {
        return;
    } else if(lef != mid) {
        add_line(nw, 2 * v, l, m);
    } else {
        add_line(nw, 2 * v + 1, m, r);
    }
}

//query
int get(int x, int v = 1, int l = 0, int r = maxn) {
    int m = (l + r) / 2;
    if(r - l == 1) {
        return f(line[v], x);
    } else if(x < m) {
        return min(f(line[v], x), get(x, 2 * v, l, m));
    } else {
        return min(f(line[v], x), get(x, 2 * v + 1, m, r));
    }
}
```
