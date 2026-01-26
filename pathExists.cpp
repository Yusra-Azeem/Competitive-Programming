#include <iostream>
using namespace std;
#include <vector>
#include <list>

class Graph{
public:
    int v;
    list<int>*l;
    Graph(int V){
        this->v=V;
        l=new list<int>[V];

    }

    void addEdge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }
    
    bool dfs(int node,int dest, vector<bool>&vis){
        vis[node]=true;
        if(node==dest){
            return true;
        }
        for(auto& ngh:l[node]){
            if(!vis[ngh]){
                if( dfs(ngh,dest,vis)) return true;
            }
            
        }
        return false;
        
    }
    bool pathExists(int src,int dest){
        vector<bool>vis(v,false);
        
        return dfs(src,dest,vis);
    }
};

int main(){
    Graph g1(7);
    g1.addEdge(0,1);
    g1.addEdge(1,2);
    g1.addEdge(3,0);
    g1.addEdge(5,0);
    g1.addEdge(5,2);
    g1.addEdge(2,3);
    g1.addEdge(2,4);
    cout<<"enter source:"<<endl;
    int src,dest;
    cin>>src;
    cout<<"enter destination:"<<endl;
    cin>>dest;
    if(g1.pathExists(src,dest)){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
}
