#include <iostream>

using namespace std;

#define TrocaString(a, b) \
    {                     \
        string aux = a;   \
        a = b;            \
        b = aux;          \
    }

#define TrocaInt(a, b) \
    {                  \
        int aux = a;   \
        a = b;         \
        b = aux;       \
    }

typedef struct Medalhas
{
    string Nome_Pais;
    int ouro;
    int prata;
    int bronze;
} Medalhas;

void Imprime(Medalhas *v, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << v[i].Nome_Pais << " " << v[i].ouro << " " << v[i].prata << " " << v[i].bronze << endl;
    }
}

void Bolha(Medalhas *v, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 1; j < n - i; j++)
        {
            if (v[j].ouro > v[j - 1].ouro)
            {
                TrocaString(v[j - 1].Nome_Pais, v[j].Nome_Pais);
                TrocaInt(v[j - 1].ouro, v[j].ouro);
                TrocaInt(v[j - 1].prata, v[j].prata);
                TrocaInt(v[j - 1].bronze, v[j].bronze);
            }
            else if (v[j].ouro == v[j - 1].ouro && v[j].prata >= v[j - 1].prata)
            {
                TrocaString(v[j - 1].Nome_Pais, v[j].Nome_Pais);
                TrocaInt(v[j - 1].ouro, v[j].ouro);
                TrocaInt(v[j - 1].prata, v[j].prata);
                TrocaInt(v[j - 1].bronze, v[j].bronze);
            }
            else if (v[j].ouro == v[j - 1].ouro && v[j].prata == v[j - 1].prata && v[j].bronze >= v[j - 1].bronze)
            {
                TrocaString(v[j - 1].Nome_Pais, v[j].Nome_Pais);
                TrocaInt(v[j - 1].ouro, v[j].ouro);
                TrocaInt(v[j - 1].prata, v[j].prata);
                TrocaInt(v[j - 1].bronze, v[j].bronze);
            }
        }
    }
}

int main()
{
    int qtde_paises = 0;
    cin >> qtde_paises;

    Medalhas *olimpiada = new Medalhas[qtde_paises];

    for (int i = 0; i < qtde_paises; i++)
    {
        cin >> olimpiada[i].Nome_Pais;
        cin >> olimpiada[i].ouro;
        cin >> olimpiada[i].prata;
        cin >> olimpiada[i].bronze;
    }

    Bolha(olimpiada, qtde_paises);
    Imprime(olimpiada, qtde_paises);

    delete[] olimpiada;
    return 0;
}