//
// Created by antonio on 19/09/22.
//

#include "../../include/Matriz.h"

Matrix::Matrix(int lines, int columns) {
    this->_matrix.lines = lines;
    this->_matrix.columns = columns;
}
void Matrix::mountMatrix() {
    for (int i = 0; i < _matrix.lines; i++) {
        _matrix.matrix.push_back(std::vector<int>());
        for (int j = 0; j < _matrix.columns; j++) {
            _matrix.matrix[i].push_back(rand()%100 +3);
        }
    }
}

IMatrix &Matrix::getMatrix() {
    return _matrix;
}