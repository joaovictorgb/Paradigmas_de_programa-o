
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main()
{
    vector<string> palavras;
    palavras.push_back("casa");
    palavras.push_back("carro");
    palavras.push_back("computador");
    palavras.push_back("celular");
    palavras.push_back("televisao");

    srand(time(NULL));
    random_shuffle(palavras.begin(), palavras.end());
    string palavra_secreta = palavras[0];

    int tam = palavra_secreta.size();
    string palavra_usuario(tam, '_');

    int erros = 0;

    while (1)
    {
        cout << "Palavra: " << palavra_usuario << endl;
        cout << "Erros: " << erros << endl;

        if (palavra_usuario == palavra_secreta)
        {
            cout << "Voce venceu!" << endl;
            break;
        }

        char ch;
        cout << "Digite uma letra: ";
        cin >> ch;

        if (find(palavra_secreta.begin(), palavra_secreta.end(), ch) == palavra_secreta.end())
        {
            cout << "Letra nao encontrada!" << endl;
            erros++;

            if (erros == 6)
            {
                cout << "Voce perdeu!" << endl;
                break;
            }
        }
        else
        {
            for (int i = 0; i < tam; i++)
            {
                if (palavra_secreta[i] == ch)
                {
                    palavra_usuario[i] = ch;
                }
            }
        }
    }
}
