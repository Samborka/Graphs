#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M, count = 1; //Count começa em 1 pois o primeiro é sempre um O
    cin >> N >> M;

    vector<string> wall(N);
    
    for (int i = 0; i < N; i++)
        cin >> wall[i];

    for (int i = 0; i < N; i++) {
        if (i > 0) {
            for (int j = 0; j < M; j++) { 
                if (wall[i][j] == '.' && wall[i - 1][j] == 'o'){
                    wall[i][j] = 'o';
                    count++;
                }
            }
        }
        if (i < N - 1) {
            for (int j = M - 2; j >= 0; j--) {
                if (wall[i][j] == '.' && wall[i][j + 1] == 'o' && wall[i + 1][j + 1] == '#'){
                    wall[i][j] = 'o';
                    count++;
                }
            }
            for (int j = 1; j < M; j++) {
                if (wall[i][j] == '.' && wall[i][j - 1] == 'o' && wall[i + 1][j - 1] == '#'){
                    wall[i][j] = 'o';
                    count++;
                }
            }
        }
    }

    cout << "\n----------------" <<endl;

    for (int i = 0; i < N; i++){
        cout << wall[i] << endl;
    }

    cout << "Número de O's: " << count << endl;


    return 0;
}
