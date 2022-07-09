#include <iostream>

using namespace std;

typedef int TipoChave;

class TipoItem
{

public:
    TipoItem();

    TipoItem(TipoChave c);

    void SetChave(TipoChave c);

    TipoChave GetChave();

    void Imprime();

private:
    TipoChave chave;
};

TipoItem::TipoItem()
{

    chave = -1; // indica um item vazio
}

TipoItem::TipoItem(TipoChave c)
{

    chave = c;
}

void

TipoItem::SetChave(TipoChave c)
{

    chave = c;
}

TipoChave
TipoItem::GetChave()
{

    return chave;
}

void TipoItem::Imprime()
{

    printf("%d ", chave);
}

class TipoNo

{

public:
    TipoNo();

private:
    TipoItem item;

    TipoNo *esq;

    TipoNo *dir;

    friend class ArvoreBinaria;
};

TipoNo::TipoNo()
{

    item.SetChave(-1);

    esq = NULL;

    dir = NULL;
}

class Fila

{

public:
    Fila()
    {

        tamanho = 0;
    };

    int
    GetTamanho()
    {

        return tamanho;
    };

    bool Vazia()
    {

        return tamanho == 0;
    };

    virtual void
    Enfileira(TipoNo *item) = 0;

    virtual TipoNo *Desenfileira() = 0;

    virtual void
    Limpa() = 0;

protected:
    int
        tamanho;
};

class ArvoreBinaria
{

public:
    ArvoreBinaria();

    void
    Insere(TipoItem item);

    void
    Caminha(int tipo);

    void
    CaminhaNivel(int qtd_num);

private:
    void
    InsereRecursivo(TipoNo *&p, TipoItem item);

    void
    ApagaRecursivo(TipoNo *p);

    TipoNo *raiz;
};

ArvoreBinaria::ArvoreBinaria()
{

    raiz = NULL;
}

void

ArvoreBinaria::Insere(TipoItem item)
{

    InsereRecursivo(raiz, item);
}

void

ArvoreBinaria::InsereRecursivo(TipoNo *&p, TipoItem item)
{

    if (p == NULL)

    {

        p = new TipoNo();

        p->item = item;
    }

    else

    {

        if (item.GetChave() < p->item.GetChave())

            InsereRecursivo(p->esq, item);

        else

            InsereRecursivo(p->dir, item);
    }
}

class FilaArranjo : public Fila
{

public:
    FilaArranjo();

    void Enfileira(TipoNo *item);

    TipoNo *Desenfileira();

    void Limpa();

private:
    int frente;

    int tras;

    static const int MAXTAM = 1005;

    TipoNo *itens[MAXTAM];
};

FilaArranjo::FilaArranjo() : Fila()
{

    frente = 0;

    tras = 0;
}

void

FilaArranjo::Enfileira(TipoNo *item)
{

    if (tamanho == MAXTAM)

        throw "Fila Cheia!";

    itens[tras] = item;

    tras = (tras + 1);

    tamanho++;
}

TipoNo *FilaArranjo::Desenfileira()
{

    TipoNo *aux;

    if (tamanho == 0)

        throw "Fila estC! vazia!";

    aux = itens[frente];
    frente = (frente + 1);
    tamanho--;

    return aux;
}

void FilaArranjo::Limpa()
{

    frente = 0;

    tras = 0;

    tamanho = 0;
}

void

ArvoreBinaria::CaminhaNivel(int qtd_num)
{

    FilaArranjo F; // fila de apontadores para nos
    TipoNo *p;

    // int esq = 0, dir = 0;

    // raiz->item.Imprime();
    F.Enfileira(raiz);

    while (!F.Vazia())

    {

        p = F.Desenfileira();

        if (p != NULL)

        {
            qtd_num--;
            printf("%d", p->item);
            F.Enfileira(p->esq);
            F.Enfileira(p->dir);
            if (qtd_num > 0)
                cout << " ";
        }
    }
}

int main()
{

    int num_testes = 0, qtd_num = 0;

    int num_analisado = 0;

    cin >> num_testes;

    for (int i = 0; i < num_testes; i++)

    {

        ArvoreBinaria arv;

        cin >> qtd_num;

        for (int j = 0; j < qtd_num; j++)

        {

            cin >> num_analisado;

            TipoItem analisado;

            analisado.SetChave(num_analisado);

            arv.Insere(analisado);
        }
        printf("Case %d:\n", i + 1);

        arv.CaminhaNivel(qtd_num);

        printf("\n\n");
    }
}