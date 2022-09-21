//
// Created by antonio on 19/09/22.
//

#include "../../include/Matriz.h"

// Montar matriz usando parametros da função
// Corrigir bug de segmentation fault
void Matrix::mountMatrix(std::vector<int> numbersOfMatrix, int lines, int columns) {

    int k=0;

    _matrix.lines = lines;
    _matrix.columns = columns;

    for (int i = 0; i < lines; i++) {
        _matrix.matrix.push_back(std::vector<int>());
        for(int j=0;j<columns;j++){
            _matrix.matrix[i].push_back(numbersOfMatrix[k]);
            k++;
        }
    }
}

IMatrix &Matrix::getMatrix() {

    return _matrix;

}

std::vector<int> Matrix::generateNumbers(int lines, int columns) {

    std::vector<int> list;

    for(int i=0;i<lines*columns;i++){
        list.push_back(rand() % 100+3);
    }

    return list;
}
