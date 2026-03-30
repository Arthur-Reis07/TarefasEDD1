#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream arquivo("nomes.txt");
    
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo nomes.txt!" << endl;
        return 1;
    }
    
    cout << "--- FORMATO CITACAO BIBLIOGRAFICA ---" << endl;
    
    string linha;
    while (getline(arquivo, linha)) {
        if (linha.empty()) continue;
        
        stringstream ss(linha);
        string palavra;
        vector<string> nomes;
        
        while (ss >> palavra) {
            nomes.push_back(palavra);
        }
        
        if (!nomes.empty()) {
            string ultimoSobrenome = nomes.back();
            
            // Transforma o último sobrenome em MAIÚSCULO
            for (char &c : ultimoSobrenome) c = toupper(c);
            
            cout << ultimoSobrenome << ", ";
            
            // O primeiro nome fica completo
            cout << nomes[0] << " ";
            
            // Os nomes do meio viram apenas as iniciais
            for (size_t i = 1; i < nomes.size() - 1; i++) {
                // Desconsidera conectores comuns se quiser (opcional)
                string nomeMeio = nomes[i];
                if (nomeMeio != "dos" && nomeMeio != "das" && nomeMeio != "de" && nomeMeio != "do") {
                     cout << (char)toupper(nomeMeio[0]) << ". ";
                }
            }
            cout << endl;
        }
    }
    
    arquivo.close();
    return 0;
}