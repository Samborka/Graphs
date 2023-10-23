#include <iostream>
#include <vector>
#include <algorithm>

//Kruskal algorithm
using namespace std;

typedef pair<double, pair<int, int>> estrada;

int N, M;
vector<int> id;

int find(int p){
  if(id[p] == p){
    return p;
  }

  id[p] = find(id[p]);
  return id[p];
}

void join(int p, int q){ //quick-union
  int id_p = find(p);
  int id_q = find(q);

  id[id_p] = id_q;
}

double mst(vector<estrada>& estradas){
  sort(estradas.begin(), estradas.end());

  for(int i = 0; i < N; i++){
    id[i] = i;
  }

  //Executando kruskal e computando custo mínimo

  double custo = 0.0;
  int j = 0, k=0;

  while(k < N - 1 and j < M){
    double u = estradas[j].first;
    int p = estradas[j].second.first;
    int q = estradas[j].second.second;

    //Verifica se o pai dos dois vértices é o mesmo
    if(find(p) != find(q)){
      join(p, q);
      custo += u;
      k++;
    }
    j++;
  }

  return custo;
}

int main(){
  cin >> N >> M;
  id = vector<int>(N);
  vector<estrada> estradas(M);

  for(int j = 0; j < M; j++){
    int p, q;
    double u; // Alterado para double para suportar pesos fracionários
    cin >> p >> q >> u;
    estradas[j] = {u, {p, q}};

  }
  
  //Aplicando Kruskal e imprimindo resultado
  cout << "-------------------" << endl;
  cout << "Peso final da árvore geradora de peso mínimo: ";
  cout << mst(estradas) << endl;
  cout << "-------------------" << endl;
  return 0;
}
