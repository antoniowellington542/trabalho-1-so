//
// Created by antonio on 20/09/22.
//

#ifndef TRABALHO_1_SO_OPERATIONS_H
#define TRABALHO_1_SO_OPERATIONS_H
#include "Matriz.h"
#include <tuple>

class Operation{
    public:
        IMatrix multiply(IMatrix matrix_A, IMatrix matrix_B);
        std::tuple<int,int,std::vector<int>> multiply_line(int *matrix, IMatrix matrix_A, IMatrix matrix_B, int i=0, int j=0, int p=1, int last_position=0);
        std::tuple<int,int, std::vector<int> > formatData(IMatrix matrix);
};


#endif //TRABALHO_1_SO_OPERATIONS_H
