#ifndef pino_h
#define pino_h

#include <iostream>

using std::string;

template <typename T>
class Pino{
private:
	T color;
	int quantidade;
public:
  //CONSTRUTORES
  Pino();
  Pino(const T &cor, const int &qtd);
  //SETTERS
  void setCor(T cor);
  void setQuantidade(int qtd);
  //GETTERS
  T getCor()const;
  int getQuantidade() const;
  //DESTRUTOR
  ~Pino();
};

#endif
