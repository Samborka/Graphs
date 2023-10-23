#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
       n = numCourses;

       adjs = vector<vector<int>> (n);
       mk = vector<bool> (n);
       onStack = vector<bool> (n);
       hasCycle = false;

       //Edges->adjs
       for(auto a: prerequisites){
           int u = a[1], v = a[0];
           adjs[u].push_back(v);
       }

      cout << "Adjacencias: " << endl;
      for(int i = 0; i < adjs[6].size(); i++)
        cout << adjs[6][i] << ' ';
       //DFS
       cout << "-------------------" << endl;
       dfs(6);
       for(int s = 0; s < n; s++){
           if(!mk[s]){
            dfs(s);
            if(hasCycle)
                break;
           }
       }

       //Answer
       if(hasCycle)
        return vector<int>();
    
       return revPosOrdem();
    }

private:
    vector<vector<int>> adjs;
    vector<bool> mk;
    vector<int> posOrdem;
    vector<bool> onStack;
    bool hasCycle;
    int n;

    void dfs(int u){
        mk[u] = true;
        onStack[u] = true;
        for(int v: adjs[u]){
            if(hasCycle)
                return;
                
            if(!mk[v])
                dfs(v);
            else if(onStack[v]){
                hasCycle = true;
                break;
            } 
        }
        posOrdem.push_back(u);
        onStack[u] = false;
    }

    vector<int> revPosOrdem(){
        vector<int>revPosOrdem(posOrdem);
        reverse(revPosOrdem.begin(), revPosOrdem.end());
        return revPosOrdem;
    }
};

int main(){
  Solution s;
  vector<vector<int>> prerequisites = {{2,0},{5,0},{1,0},{4,1}, {4, 6}, {0, 6}, {6, 3}, {4, 3}, {5, 3}, {2, 3}, {2, 5}};
  int numCourses = 7;

  vector<int> ans = s.findOrder(numCourses, prerequisites);

  for(int i = 0; i < ans.size(); i++){
    cout << ans[i] << ' ';
  }
  return 0;
}