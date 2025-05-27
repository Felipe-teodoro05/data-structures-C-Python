#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vetor = {10, 20, 30, 40, 50};

    // Acessando elementos
    cout << "Primeiro elemento: " << vetor[0] << endl;
    cout << "Ultimo elemento: " << vetor.back() << endl;

    // Percorrendo o vetor
    cout << "Elementos do vetor: ";
    for (int elemento : vetor) {
        cout << elemento << " ";
    }
    cout << endl;

    // Modificando um elemento
    vetor[2] = 99;
    cout << "Vetor apos modificacao: ";
    for (int elemento : vetor) {
        cout << elemento << " ";
    }
    cout << endl;

    // Adicionando um elemento ao final
    vetor.push_back(60);
    cout << "Vetor apos adicionar um elemento: ";
    for (int elemento : vetor) {
        cout << elemento << " ";
    }
    cout << endl;

    // Removendo o segundo elemento (índice 1)
    vetor.erase(vetor.begin() + 1);
    cout << "Vetor apos remover um elemento: ";
    for (int elemento : vetor) {
        cout << elemento << " ";
    }
    cout << endl;

    // Tamanho do vetor
    cout << "Tamanho do vetor: " << vetor.size() << endl;

    return 0;
}
