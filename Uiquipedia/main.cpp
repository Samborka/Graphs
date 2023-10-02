#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> d;
vector<bool> mk;
vector<vector<int>> adjs;

int bfs(int s, int t){
  d[s] = 0;
  mk[s] = true;

  vector<int> q;
  q.push_back(s);

  while(!q.empty()){
    int u = q.front();
    q.erase(q.begin());

    for(int v : adjs[u]){
      if(!mk[v]){
        mk[v] = true;
        d[v] = d[u] + 1;
        q.push_back(v);
      }
    }
  }

  return d[t];
}

int main(){
  int n;
  cin >> n;

  //Inicializando
  mk = vector<bool>(2 * n, false);
  d = vector<int>(2 * n, false);
  adjs = vector<vector<int>>(2 * n);

  //Lendo links diretos e registrando em adjs
  map<string, int> ind;
  int nc = 0;

  for(int i = 0; i < n; i++){
    string x;
    cin >> x;
    if(ind.count(x) == 0) //Se x não existe no map
      ind[x] = nc++;

    string y;
    cin >> y;

    if(ind.count(y) == 0)
      ind[y] = nc++;

    adjs[ind[x]].push_back(ind[y]);
  }

  //Adicionando os links da ordem alfabétic (o map já mantém tudo em ordem)
  int ix = -1; //ind's começa em 0

  for(auto p : ind){
    int iy = p.second;

    if(ix != -1){
      adjs[ix].push_back(iy);
      adjs[iy].push_back(ix);
    }

    ix = iy;
  }

  //Processando a query
  string p, a;
  cin >> p >> a;

  cout << bfs(ind[p], ind[a]) << '\n';

  return 0;
}