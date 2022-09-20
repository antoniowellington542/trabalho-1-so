//
// Created by antonio on 19/09/22.
//

#include "../../include/Matriz.h"

// Montar matriz usando parametros da função
// Corrigir bug de segmentation fault
void Matrix::mountMatrix(std::vector<int> numbersOfMatrix, int lines, int columns) {

    int k=0;

    std::vector<int> list;

    for (int i = 0; i < lines; i++) {
        this->_matrix.matrix.push_back(std::vector<int>());
        for (int j = 0; j < columns; j++) {
            list.push_back(numbersOfMatrix[k]);
            k++;
        }
    }

}

IMatrix &Matrix::multiplyMatrix(IMatrix *matrix_B) {

    int lines_A = _matrix.lines;
    int columns_A = _matrix.columns;
    int columns_B = matrix_B->columns;
    IMatrix *matrix_C;

    for(int i=0;i<lines_A;i++){
        matrix_C->matrix.push_back(std::vector<int>());
        for(int j=0;j<columns_B;j++){
            matrix_C->matrix[i].push_back(0);
            for(int k=0;k<columns_A;k++){
                matrix_C->matrix[i][j] += _matrix.matrix[i][k] * matrix_B->matrix[k][j];
            }
        }
    }

    return *matrix_C;
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
