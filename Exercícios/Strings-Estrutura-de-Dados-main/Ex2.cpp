#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string mensagem, processada = "";
    
    cout << "Digite a mensagem para verificar palindromo: ";
    getline(cin, mensagem);
    
    // Remove os espaços e padroniza para maiúsculo
    for (char c : mensagem) {
        if (c != ' ') {
            processada += toupper(c);
        }
    }
    
    // Inverte a string processada
    string invertida = processada;
    reverse(invertida.begin(), invertida.end());
    
    // Verifica se elas são iguais
    cout << "\n----------------------------------------" << endl;
    if (processada == invertida && !processada.empty()) {
        cout << "A mensagem E um palindromo!" << endl;
    } else {
        cout << "A mensagem NAO e um palindromo." << endl;
    }
    cout << "----------------------------------------" << endl;
    
    return 0;
}