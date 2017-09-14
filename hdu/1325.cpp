#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int maxn = 100000 + 10;
int in_de[maxn], fa[maxn];
bool vis[maxn];

int find_set(int x)
{
 if(x == fa[x]) return x;
 else return fa[x] = find_set(fa[x]);
}
int union_set(int x, int y)
{
 int root_x = find_set(x);
 int root_y = find_set(y);
 if(root_x == root_y) return 0;
 else fa[root_y] = root_x;
 return 1;
}
int main()
{
 int u, v, cnt = 1, i, numOfEdg = 0, numOfVer = 0;
 bool ok = 1;
 memset(in_de, 0, sizeof(in_de));
 memset(vis, 0, sizeof(vis));
 for(i = 0; i < maxn; i++) fa[i] = i;
 while(cin>>u>>v)
 {
 if(u == -1 && v == -1) return 0;
 if(!u && !v)
 {
 if(numOfEdg+1 != numOfVer) ok = 0;
 if(ok) cout<<"Case "<<cnt++<<" is a tree."<<endl;
 else cout<<"Case "<<cnt++<<" is not a tree."<<endl;
 ok = 1;
 numOfEdg = 0;
 numOfVer = 0;
 memset(in_de, 0, sizeof(in_de));
 memset(vis, 0, sizeof(vis));
 for(i = 0; i < maxn; i++) fa[i] = i;
 }
 else
 {
 if(++in_de[v] > 1 || !union_set(u, v)) ok = 0;
 if(!vis[u])
 {
 vis[u] = 1;
 numOfVer++;
 }
 if(!vis[v])
 {
 vis[v] = 1;
 numOfVer++;
 }
 numOfEdg++;
 }
 }
 return 0;
}
