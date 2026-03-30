#include <iostream>
#include <string>
#include <windows.h>
#include <chrono>
#include <thread>

using namespace std;

// Função para mover o cursor para uma coordenada (X, Y) na tela
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {
    system("cls"); // Limpa a tela no Windows
    
    string mensagem;
    cout << "Digite uma mensagem: ";
    getline(cin, mensagem);
    
    system("cls");
    
    int larguraTela = 80; // Largura padrão do terminal
    int tam = mensagem.length();
    int colunaInicial = (larguraTela - tam) / 2; // Centraliza
    
    // Apresenta a mensagem centralizada na linha 5
    gotoxy(colunaInicial, 5);
    cout << mensagem;
    
    // Efeito cascata: letra por letra
    for (int i = 0; i < tam; i++) {
        char letra = mensagem[i];
        
        // Se for um espaço, não precisa fazer animação de queda
        if (letra == ' ') continue; 
        
        for (int linha = 5; linha < 20; linha++) {
            // Apaga a letra na posição anterior
            gotoxy(colunaInicial + i, linha);
            cout << " ";
            
            // Desenha a letra na nova posição
            gotoxy(colunaInicial + i, linha + 1);
            cout << letra;
            
            // Pausa pequena para dar o efeito visual (50 milissegundos)
            this_thread::sleep_for(chrono::milliseconds(50));
        }
    }
    
    // Move o cursor para o final para não bagunçar o terminal
    gotoxy(0, 22);
    return 0;
}