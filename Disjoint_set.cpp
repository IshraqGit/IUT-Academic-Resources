#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
private:
    vector<int>rank,parent,size;
public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,0);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }
    int findUPar(int node){
        if(node == parent[node])return node;
        return parent[node] = findUPar(parent[node]); //path compression ta ekhanei
        //as we are saving the findUPar(parent[node]) in parent[node] instead of
        //just returning it like  return findUPar(parent[node]);
        //the concept is based on DP.
    }

    void unionByRank(int u,int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v)return;
        else{
            if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            }else if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_v] = ulp_u;
            }else{
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }
    }
    void unionBySize(int u,int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v)return;
        else{
            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }else if(size[ulp_u] > size[ulp_v]){
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }else{
                //either one is okay~
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
    }
};
int main(){
    DisjointSet ds(7);

    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);

    //finding if 3 and 7 are under the same set or not.
    cout << (ds.findUPar(3) == ds.findUPar(7) ? "YES":"NO") << endl;

    //After union
    //finding if 3 and 7 are under the same set or not.
    ds.unionByRank(3,7);
    cout << (ds.findUPar(3) == ds.findUPar(7) ? "YES":"NO") << endl;



    ///////////////////////////////////////////////////////////////
    //Now we do the same unions by size.
    // Note -> we can never simultaneously do union by size and rank.
    DisjointSet ss(7);

    ss.unionBySize(1,2);
    ss.unionBySize(2,3);
    ss.unionBySize(4,5);
    ss.unionBySize(6,7);
    ss.unionBySize(5,6);


    //finding if 3 and 7 are under the same set or not.
    cout << (ss.findUPar(3) == ss.findUPar(7) ? "YES":"NO") << endl;

    //After union
    //finding if 3 and 7 are under the same set or not.
    ss.unionByRank(3,7);
    cout << (ss.findUPar(3) == ss.findUPar(7) ? "YES":"NO") << endl;

}
