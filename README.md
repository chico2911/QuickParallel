# Parallel Quicksort with OpenMP
## Projeto Inserido na Unidade Curricular Computação Paralela 2020/2021
### [Mestrado Integrado em Engenhária Informática na Universidade do Minho](https://miei.di.uminho.pt/)

Este projeto consistia na paralelização do algortimo **Quicksort** utilizando diretivas do **OpenMP**. Desta forma é possível através da atribuição de threads para cada recursividade da implementação, assim existirá, dentro de certas, condições um speed up do desempenho do algoritmo.
Nos [anexos](https://github.com/chico2911/QuickParallel/blop/master/Docs/anexos.xlsx) encontram-se uma série de testes efetuados para apurar o ganho. A estratégia utilizada é abordada e detalhada no [relatório](https://github.com/chico2911/QuickParallel/blop/master/Docs/relatorio_quicksort_a85367_a84092.pdf).

Na seguinte imagem podemos ver uma comparação entre a variação dos tempos de execução nas diferentes máquinas utilizadas. Os valores apresentados são em segundos(y), bem como o array ordenado é o [array1](https://github.com/chico2911/QuickParallel/blop/master/Inputs/array1.txt) que conta com 500k entradas.

<p align="center">
   <img src="https://github.com/chico2911/QuickParallel/blob/master/Docs/graph.png">
</p>

### [Relatório](https://github.com/chico2911/QuickParallel/blop/master/Docs/relatorio_quicksort_a85367_a84092.pdf)

### [Apresentação](https://github.com/chico2911/QuickParallel/blop/master/Docs/apresentacao.pdf)

## Development Team

* [Diogo Pereira](https://github.com/dpereira7)
* [Francisco Lopes](https://github.com/chico2911)
