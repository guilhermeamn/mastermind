#ifndef LISTA_H
#define LISTA_H

#include "celula.h"

template <typename T>
class Lista{
private:
    Celula <T> *cabeca;
    Celula <T> *cauda;
    int tamanho;
public:
    //CONSTRUTOR
    Lista();
    //GETTERS
    int getTamanho() const;
    Celula <T> *getCabeca() const;
    Celula <T> *getCauda() const;
    T lista_dado(const Celula <T> *c);
    T lista_dado_AUXILIAR(int posicao);
    //SETTERS
    void setTamanho(int tam);
    void setCabeca(Celula <T> *head);
    void setCauda(Celula <T> *tail);
    //OUTROS METODOS
    int vazia() const;
    int lista_eh_cabeca(const Celula <T> *c);
    int lista_eh_cauda(const Celula <T> *c);
    int insere_proximo(Celula <T> *c, const T &elem);
    int remove(Celula <T> *c);
    bool lista_pertence(T dado);
    void imprime();
    //DESTRUTOR
    ~Lista();
};

#endif
