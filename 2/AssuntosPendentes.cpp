#include <iostream>

using namespace std;

class Pilha
{
public:
    Pilha() { tamanho = 0; };
    int GetTamanho() { return tamanho; };
    bool Vazia() { return tamanho == 0; };
    virtual void Empilha(char item) = 0;
    virtual void Desempilha() = 0;
    virtual void Limpa() = 0;

protected:
    int tamanho;
};

class TipoCelula
{
public:
    TipoCelula();

private:
    char item;
    TipoCelula *prox;

    friend class PilhaEncadeada;
};

TipoCelula::TipoCelula()
{
    prox = NULL;
}

class PilhaEncadeada : public Pilha
{
public:
    PilhaEncadeada();
    virtual ~PilhaEncadeada();
    void Empilha(char item);
    void Desempilha();
    void Limpa();

private:
    TipoCelula *topo;
};

PilhaEncadeada::PilhaEncadeada() : Pilha()
{
    topo = NULL;
}

PilhaEncadeada::~PilhaEncadeada()
{
    Limpa();
}

void PilhaEncadeada::Empilha(char item)
{
    TipoCelula *nova;

    nova = new TipoCelula();
    // printf("%c ",nova->item);
    nova->item = item;
    nova->prox = topo;
    topo = nova;
    tamanho++;
};

void PilhaEncadeada::Desempilha()
{
    char aux;
    TipoCelula *p;

    if (tamanho == 0)
        throw "A pilha está vazia!";

    aux = topo->item;
    p = topo;
    topo = topo->prox;
    delete p;
    tamanho--;
};

void PilhaEncadeada::Limpa()
{
    while (!Vazia())
    {
        Desempilha();
    }
}

int main()
{
    string str;
    char x;
    int qtd_par = 0;
    PilhaEncadeada *p = new PilhaEncadeada;

    cin >> str; // lê uma string
    for (int i = 0; i < str.length(); i++)
    {
        x = str[i];
        if (x == '(')
        {
            p->Empilha(x);
            qtd_par++;
        }
        else if (x == ')' && qtd_par != 0)
        {
            p->Desempilha();
            qtd_par--;
        }
    }

    if (p->GetTamanho() == 0)
    {
        printf("Partiu RU!\n");
    }
    else
    {
        printf("Ainda temos %i assunto(s) pendente(s)!\n", p->GetTamanho());
    }

    return 0;
}