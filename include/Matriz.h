//
// Created by antonio on 19/09/22.
//

#ifndef TRABALHO_1_SO_MATRIZ_H
#define TRABALHO_1_SO_MATRIZ_H
#include <vector>
#include <iostream>
struct IMatrix{

    int lines;
    int columns;
    std::vector<std::vector<int> > matrix;

};

class Matrix{

    private:
        IMatrix _matrix;
    public:
        void mountMatrix(std::vector<int> numbersOfMatrix, int lines, int columns);
        IMatrix &getMatrix();
        std::vector<int> generateNumbers(int lines, int columns);

};
#endif //TRABALHO_1_SO_MATRIZ_H