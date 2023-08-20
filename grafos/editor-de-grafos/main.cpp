/***********************************************************************
 * Pontificia Universidade Catolica de Minas Gerais
 * Engenharia de Software
 * Teoria dos Grafos e Computabilidade
 * Prof. Luiz Henrique da Costa Silva
 ************************************************************************/
//=====================================================================
// BIBLIOTECAS
//=====================================================================
#include <fstream>
#include <iostream>
#include <stdio.h>

using namespace std;

//=====================================================================
// DEFINICAO DE CONSTANTES
//=====================================================================
#define MAX_VERTICE 500
#define MAX_INT 0x7FFFFFFF
#define NULO -1

//=====================================================================
// DEFINICAO DE TIPOS
//=====================================================================
typedef short boolean;
typedef int Vertice;
typedef int Peso;

struct Aresta {
  Vertice vi, vj;
  Peso peso;
};

//=====================================================================
// CLASSE GRAFO
//=====================================================================
class Grafo {
private:
  int numVertice, numAresta;

  Peso matriz[MAX_VERTICE][MAX_VERTICE];

public:
  // Construtor
  Grafo() {
    numVertice = 0;
    excluirTodasArestas();
  }

  // Destrutor
  ~Grafo() {
  } //-------------------------------------------------------------------

  //--------------------------------------------------------------------
  // lerGrafo: Realiza a leitura do grafo no arquivo.
  //--------------------------------------------------------------------
  boolean lerGrafo() {
    boolean resp;
    int temp;

    excluirTodasArestas();

    // Ler o numero de vertices
    cin >> temp;
    setNumVertice(temp);

    resp = (numVertice > 0) ? true : false;

    for (int i = 0; i < numVertice; i++) {
      inserirAresta(i, i, NULO);
      for (int j = i + 1; j < numVertice; j++) {
        cin >> temp;
        inserirAresta(i, j, temp);
        inserirAresta(j, i, temp);
      }
    }
    return resp;
  } //-------------------------------------------------------------------

  //--------------------------------------------------------------------
  // imprimir: Imprime o grafo.
  //--------------------------------------------------------------------
  void imprimir() {
    int i = 0, j = 0;

    printf("\nN = (%i)\n    \t", numVertice);
    for (i = 0; i < numVertice; i++) {
      if (i >= 100) {
        printf("\t(%i) ", i);
      } else if (i >= 10) {
        printf("\t(0%i) ", i);
      } else {
        printf("\t(00%i) ", i);
      }
    }

    for (i = 0; i < numVertice; i++) {
      if (i >= 100) {
        printf("\n(%i) - ", i);
      } else if (i >= 10) {
        printf("\n(0%i) - ", i);
      } else {
        printf("\n(00%i) - ", i);
      }

      for (j = 0; j < numVertice; j++) {
        if (matriz[i][j] == NULO) {
          printf("\t\t. ");
        } else {
          printf("\t\t%i ", matriz[i][j]);
        }
      }
    }

    printf("\n");
  } //-------------------------------------------------------------------

private:
  //--------------------------------------------------------------------
  // inserirAresta: Insere uma nova aresta.
  //--------------------------------------------------------------------
  void inserirAresta(Vertice v1, Vertice v2, Peso peso) {

    if (v1 > MAX_VERTICE) {
      printf("ERRO! Vertice %i nao existe no grafico", v1);
      return;
    }
    if (v2 > MAX_VERTICE) {
      printf("ERRO! Vertice %i nao existe no grafico", v2);
      return;
    }
    if (matriz[v1][v2] == NULO) {
      matriz[v1][v2] = peso;
      numAresta++;
    }
  } //-------------------------------------------------------------------

  //--------------------------------------------------------------------
  // isAresta: Retorna true se existe a aresta.
  //--------------------------------------------------------------------
  boolean isAresta(Vertice v1, Vertice v2) {
    return (matriz[v1][v2] != NULO);
  } //-------------------------------------------------------------------

public:
  void imprimirVerticeAresta() {
    cout << numVertice << " " << numAresta << "\n";
  }

  //--------------------------------------------------------------------
  // getAresta: Retorna o peso da aresta.
  //--------------------------------------------------------------------
  Peso getAresta(Vertice v1, Vertice v2) {
    return (matriz[v1][v2]);
  } //-------------------------------------------------------------------

  //--------------------------------------------------------------------
  // excluirAresta: Exclui uma aresta.
  //--------------------------------------------------------------------
  void excluirAresta(Vertice v1, Vertice v2) {
    if (v1 > numVertice) {
      printf("ERRO! Vertice %i nao existe no grafico", v1);
      return;
    }
    if (v2 > numVertice) {
      printf("ERRO! Vertice %i nao existe no grafico", v2);
      return;
    }
    if (matriz[v1][v2] != NULO) {
      matriz[v1][v2] = NULO;
      numAresta--;
    }
  } //-------------------------------------------------------------------

  //--------------------------------------------------------------------
  // excluirTodasArestas: Atribui NULO para todas as arestas.
  //--------------------------------------------------------------------
  void excluirTodasArestas() {
    for (int i = 0; i < MAX_VERTICE; i++) {
      matriz[i][i] = NULO;
      for (int j = i + 1; j < MAX_VERTICE; j++) {
        matriz[i][j] = matriz[j][i] = NULO;
      }
    }
    numAresta = 0;
  } //-------------------------------------------------------------------

  //--------------------------------------------------------------------
  // setNumVertice: Altera a variavel numVertice.
  //--------------------------------------------------------------------
  void setNumVertice(int nVertice) {
    if (nVertice > MAX_VERTICE) {
      printf("ERRO: Numero de vertices\n");
      return;
    }
    numVertice = nVertice;
  } //-------------------------------------------------------------------

  //--------------------------------------------------------------------
  // getGrau: Retorna o grau do vertice.
  //--------------------------------------------------------------------
  int getGrau(Vertice v) {
    if (v > numVertice) {
      printf("ERRO: Vertice %i nao existe no grafico", v);
      return -1;
    }

    int grauVertice = 0;
    for (int i = 0; i < numVertice; i++) {
      if (matriz[v][i] != NULO) {
        grauVertice++;
      } else if (matriz[i][v] != NULO) {
        grauVertice++;
      }
    }
    return grauVertice;
  } //-------------------------------------------------------------------

  //--------------------------------------------------------------------
  // isSimples: Retorna true se o grafo for simples
  // (sem loops ou arestas multiplas).
  //--------------------------------------------------------------------
  boolean isSimples() {
    for (int i = 0; i < numVertice; i++) {
      for (int j = 0; j < numVertice; j++) {
        // verifica se existem loops
        if ((i == j) && matriz[i][j] != NULO) {
          return false;
        }

        // verifica se existem arestas multiplas
        if (matriz[i][j] != NULO && matriz[j][i] != NULO && i != j) {
          return false;
        }

        // verifica simetria
        if (matriz[i][j] != matriz[j][i]) {
          return false;
        }
      }
    }

    return true;
  } //-------------------------------------------------------------------

  //--------------------------------------------------------------------
  // isRegular: Retorna true se o grafo for regular
  // (todos os vertices com o mesmo grau).
  //--------------------------------------------------------------------
  boolean isRegular() {
    for (int i = 0; i < numVertice; i++) {
      for (int j = 0; j < numVertice; j++) {
        if (getGrau(i) != getGrau(j)) {
          return false;
        }
      }
    }

    return true;
  } //-------------------------------------------------------------------

  //--------------------------------------------------------------------
  // isNulo: Retorna true se o grafo for nulo
  // (sem arestas).
  //--------------------------------------------------------------------
  boolean isNulo() {
    return (numAresta == 0);
  } //-------------------------------------------------------------------

  //--------------------------------------------------------------------
  // isCompleto: Retorna true se o grafo for completo
  // (todos os vertices sao adjacentes).
  //--------------------------------------------------------------------
  boolean isCompleto() {
    for (int i = 0; i < numVertice; i++) {
      for (int j = 0; j < numVertice; j++) {
        if (i != j && !isAresta(i, j)) {
          return false;
        }
      }
    }

    return true;
  }
};

//=====================================================================
// FUNCAO PRINCIPAL
//=====================================================================
int main(int argc, char **argv) {
  Grafo *g = new Grafo;

  while (g->lerGrafo() == true) {
    g->imprimir();
    g->imprimirVerticeAresta();
    delete g;
    g = new Grafo;
  }

  delete g;

  return 0;
} //--------------------------------------------------------------------
