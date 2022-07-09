#include <iostream>

using namespace std;

int main()
{

    int qtd_pessoas;
    float qtd_consumida = 0.0, qtd_garrafa = 0.0;
    int j = 0;

    cin >> qtd_pessoas;
    string pessoas[qtd_pessoas];

    cin >> qtd_garrafa;
    cin >> qtd_consumida;

    for (int dados = 0; dados < qtd_pessoas; dados++)
    {
        cin >> pessoas[dados];
    }

    while (qtd_garrafa > qtd_consumida)
    {
        qtd_garrafa = qtd_garrafa - qtd_consumida;
        j++;
        j = j % qtd_pessoas;
    }
    cout << pessoas[j] << " ";
    printf("%.1f", qtd_garrafa);
    printf("\n");

    return 0;
}