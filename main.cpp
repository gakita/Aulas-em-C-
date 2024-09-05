#include <iostream>

using namespace std;

int getDeterminant(int M[2][2]) {
    return M[0][0] * M[1][1] - M[0][1] * M[1][0];
}

void getAdj(int M[2][2], int adj[2][2]) {
    adj[0][0] = M[1][1];
    adj[0][1] = -M[0][1];
    adj[1][0] = -M[1][0];
    adj[1][1] = M[0][0];
}

void getInverse(int M[2][2], int inv[2][2]) {
    int det = getDeterminant(M);
    if (det == 0) {
        cout << "Matriz não é invertível." << endl;
        return;
    }
    int adj[2][2];
    getAdj(M, adj);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            inv[i][j] = adj[j][i] / det;
        }
    }
}

void multiply(int M[2][2], int b[2], int sol[2]) {
    sol[0] = M[0][0] * b[0] + M[0][1] * b[1];
    sol[1] = M[1][0] * b[0] + M[1][1] * b[1];
}

void drawMatrix(int M[2][2]) {
    cout << "Matriz:" << endl;
    cout << "-----" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-----" << endl;
}

int getOption() {
    int escolha;
    do {
        cout << "Escolha uma opcao:" << "\n========================================================" <<endl;
        cout << "1. Resolver sistema de equações lineares." << endl;
        cout << "2. Determinar todos os numeros primos ate um certo valor"<< endl;
        cout << "3. Sair." << "\n========================================================"<<endl;

        cin >> escolha;

        switch (escolha){
            case 1:
                int M[2][2], b[2], sol[2];
            cout << "Digite a matriz 2x2:" << endl;
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    cin >> M[i][j];
                }
            }
            drawMatrix(M);
            cout << "Digite o vetor:" << endl;
            for (int i = 0; i < 2; i++) {
                cin >> b[i];
            }
            int inv[2][2];
            getInverse(M, inv);
            cout << "Inversa da matriz:" << endl;
            drawMatrix(inv);
            multiply(inv, b, sol);
            cout << "Solucao:" << endl;
            for (int i = 0; i < 2; i++) {
                cout << sol[i] << " ";
            }
            cout << endl;
            break;

            case 2:
            cout << "Digite o valor maximo:" << endl;
            int n;
            cin >> n;
            for (int i = 2; i <= n; i++) {
                bool isPrime = true;
                for (int j = 2; j <= i / 2; j++) {
                    if (i % j == 0) {
                        isPrime = false;
                        break;
                    }
                }
                if (isPrime) {
                    cout << i << " \n";
                }

            }
        }
    }while (escolha != 3);
}

int main() {

    getOption();
    return 0;
}