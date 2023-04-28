//
// KAYLA DE VIVANCO BRICENO
//

#ifndef PROG3_PC1_TEO3_V2023_1_P2_H
#define PROG3_PC1_TEO3_V2023_1_P2_H
#include <vector>
#include<iostream>
#include <iostream>
#include <vector>
#include <initializer_list>
#include<deque>
#include <iomanip>
using namespace std;
template <
        int a, int b, //Dimensiones de la matriz
        template<typename...> class Container = vector, //Tipo de contenedor por default = vector
        typename T> //Tipo de dato que contiene el contenedor
Container<Container<T>> generate_matrix(Container<T> input) {
    Container<Container<T>> matriz;
    //Por cada inserta una fila por cada a: si a es 3 inserta tres filas de tamano b
    for (int i = 0; i < a; i++) {
        Container<T> fila(b);
        matriz.push_back(fila);
    }

    //Itero sobre input para copiar cada valor a la matriz
    typename Container<T>::const_iterator it = input.begin();
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            if (it != input.end()) {
                matriz[i][j] = *it;
                ++it;
            }
        }
    }
    return matriz; //Retorna nuestro contenedor tipo Container<Container<T>>
    }



void question_2();

#endif //PROG3_PC1_TEO3_V2023_1_P2_H
