# Leitura e Impressão de Grafos em C++

Este é um programa em C++ que lê informações de um grafo de no máximo 500 vértices e imprime sua matriz de adjacência.

### Classe `Grafo`

A classe `Grafo` é responsável por manipular grafos e contém os seguintes métodos:

-   `lerGrafo()`: Realiza a leitura do grafo. Lê o número de vértices, insere as arestas na matriz de adjacência e retorna `true` se a leitura for bem-sucedida.
-   `imprimir()`: Imprime a matriz de adjacência do grafo, mostrando as arestas e os pesos.
-   `imprimirVerticeAresta()`: Imprime o número de vértices e arestas do grafo.

-   `inserirAresta(v1, v2, peso)`: Insere uma nova aresta na matriz de adjacência.
-   `isAresta(v1, v2)`: Retorna `true` se existe uma aresta entre os vértices `v1` e `v2`.
-   `getAresta(v1, v2)`: Retorna o peso da aresta entre os vértices `v1` e `v2`.
-   `excluirAresta(v1, v2)`: Exclui a aresta entre os vértices `v1` e `v2`.
-   `excluirTodasArestas()`: Remove todas as arestas do grafo.
-   `setNumVertice(nVertice)`: Define o número de vértices no grafo.

Claro, aqui está a explicação dos métodos adicionais em formato markdown:

## Métodos Adicionais

Além dos métodos da classe `Grafo`, inseri os seguintes métodos:

### `getGrau(v)`

Esse método retorna o grau do vértice `v` no grafo. O grau de um vértice é o número de arestas que o conectam a outros vértices.

### `isSimples()`

Esse método verifica se o grafo é simples, ou seja, se ele não possui loops (arestas que conectam um vértice a ele mesmo) nem múltiplas arestas entre dois vértices.

### `isRegular()`

Esse método verifica se o grafo é regular, ou seja, se todos os vértices têm o mesmo grau. Um grafo regular é aquele em que todos os vértices têm o mesmo número de arestas conectadas a eles.

### `isNulo()`

Esse método verifica se o grafo é nulo, ou seja, se ele não possui nenhuma aresta. Em um grafo nulo, todos os vértices são isolados, ou seja, não estão conectados a nenhum outro vértice.

### `isCompleto()`

Esse método verifica se o grafo é completo, ou seja, se todos os pares distintos de vértices estão conectados por uma aresta. Em um grafo completo, todos os vértices estão interconectados.

```
Esses métodos adicionais podem ser usados para realizar análises específicas do grafo e entender suas propriedades.
```
