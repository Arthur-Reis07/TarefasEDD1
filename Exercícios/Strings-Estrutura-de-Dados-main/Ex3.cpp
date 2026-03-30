#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    ifstream arquivo("nomes.txt");
    
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo nomes.txt!" << endl;
        return 1;
    }
    
    cout << "--- FORMATO AGENDA TELEFONICA ---" << endl;
    
    string linha;
    while (getline(arquivo, linha)) {
        if (linha.empty()) continue;
        
        stringstream ss(linha);
        string palavra;
        vector<string> nomes;
        
        // Separa o nome completo por espaços
        while (ss >> palavra) {
            nomes.push_back(palavra);
        }
        
        if (!nomes.empty()) {
            // Pega o último sobrenome
            string ultimoSobrenome = nomes.back();
            
            // Mostra o último sobrenome primeiro
            cout << ultimoSobrenome << ", ";
            
            // Mostra o restante do nome
            for (size_t i = 0; i < nomes.size() - 1; i++) {
                cout << nomes[i] << (i == nomes.size() - 2 ? "" : " ");
            }
            cout << endl;
        }
    }
    
    arquivo.close();
    return 0;
}