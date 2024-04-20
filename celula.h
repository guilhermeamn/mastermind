#ifndef CELULA_H
#define CELULA_H

#include <iostream>

template <typename T> class Lista;

template <typename T>
class Celula{
    friend class Lista <T>;
private:
    T dado;
    Celula *prox;
    Celula *ant;
public:
    //CONSTRUTOR
    Celula(const T &info);
    //SETTERS
    void setDado(T info);
    //GETTERS
    T getDado() const;
    //SOBRECARGA DE OPERADOR
    template <typename T1>
    friend bool operator == (const Celula <T1> &c1, const Celula <T1> &c2);
    //DESTRUTOR
    ~Celula();
};

#endif
