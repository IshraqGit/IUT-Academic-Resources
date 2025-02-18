#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class DisjointSet{
private:
    vector <ll> Parent;
    vector <ll> Rank;
public:
    void makeset(ll u){ //Initializes a Node by appointing itself as a representative.
        Parent[u] = u;
    }
    void init(ll num){
        Parent.resize(num);
        Rank.assign(num,0);

        for(ll i=0;i<num;i++){
            makeset(i);
        }
    }
    ll find(ll u){  // Returns the Representative of a Node.
        if(Parent[u]==u)return u;
        return Parent[u] = find(Parent[u]);
    }
    void set_union(ll i,ll j){
        ll ri = find(i);
        ll rj = find(j);

        if(ri != rj){
            if(Rank[ri] > Rank[rj]){
                Parent[rj] = ri;
            }else if (Rank[ri] < Rank[rj]){
                Parent[ri] = rj;
            }else{
                Parent[rj] = ri;
                Rank[ri]++;
            }
        }
    }

    void PrintSet(){
       for(int i=0;i<Parent.size();i++){
            cout << "The Parent of " << i << " is " << Parent[i] << " and its rank is " << Rank[i] << ".\n";
       }
    }
};
int main(){
    cout << "Enter number of elements: ";
    ll num; cin >> num;

    DisjointSet ds;
    ds.init(num);
    ds.set_union(2,3);
    ds.set_union(4,5);
    ds.set_union(3,5);
    ds.PrintSet();
}
