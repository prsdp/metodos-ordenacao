## Projeto de Análise de Algoritmos
Trabalho para analisar o desempenho dos métodos de ordenação heap-sort, merg-sorte e count sort.

### Estrutura de diretórios

.

|--- include    (declaração e implementação das bibliotecas usadas no programa)

|--- src        (source dos programas de exemplo)

|--- tests      (diretório criado a partir do uso do make, contém os exemplos)
***

### Dependências

* gcc
* automake

***

### Build

O projeto possui um arquivo Makefile para buildar o projeto com todos os exemplos disponíveis ou parte deles.

*obs: todo processo de compilação se encontra no arquivo Makefile*

Para criar os executáveis de todos os exemplos disponíveis, digite:

    make

Para criar um executável específico é necessário digitar alguma das regras válidas abaixo:

* bubble-sort
* insertion-sort
* quick-sort
* heap-sort
* count-sort
* selection-sort
* merge-sort
* bubble-sort-random-array
* heap-sort-random-array
* quick-sort-random-array
* merge-sort-random-array
* random-arrays-with-ranges
* sortable

O programa mais importante do projeto se chama __sortable__ e possui o mesmo nome nas regras do Makefile, para fazer o build deste exemplo digite:

    make sortable

o programa será criado na pasta *tests*, para obter informações sobre o programa digite:

    ./tests/sortable --help

Para limpar a pasta do projeto, digite:

    make clean
