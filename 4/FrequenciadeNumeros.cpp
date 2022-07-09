#include <iostream>

using namespace std;

#define Troca(A, B) \
    {               \
        int c = A;  \
        A = B;      \
        B = c;      \
    }

void Ordena(int v[], int n)
{

    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = n - 1; j > i; j--)
        {
            if (v[j - 1] > v[j])       /* comparações */
                Troca(v[j - 1], v[j]); /* trocas */
        }
    }
}

void Selecao(int dados[], int tamanho)
{
    int i, j, Min;

    for (i = 0; i < tamanho - 1; i++)
    {
        Min = i;
        for (j = i + 1; j < tamanho; j++)
        {

            if (dados[j] < dados[Min])
                Min = j;
        }
        Troca(dados[i], dados[Min]);

        // cout<<dados[i]<<endl;
    }
}

void Imprime(int v[], int tam)
{
    int i, repetido = 1;

    for (i = 0; i < tam; i++)
    {
        if (v[i] == v[i + 1])
        {
            repetido++;
        }
        else
        {
            cout << v[i] << " aparece " << repetido << " vez(es)" << endl;
            repetido = 1;
        }
    }
}

int main()
{
    int qtd_numeros;
    cin >> qtd_numeros;
    int numeros[qtd_numeros];

    for (int x = 0; x < qtd_numeros; x++)
    {
        int aux;
        cin >> aux;
        numeros[x] = aux;
    }
    Selecao(numeros, qtd_numeros);
    Imprime(numeros, qtd_numeros);

    return 0;
}