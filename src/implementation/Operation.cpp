//
// Created by antonio on 20/09/22.
//

#include "../../include/Operations.h"

IMatrix Operation::multiply(IMatrix matrix_A, IMatrix matrix_B) {

    IMatrix matrix_C;

    for(int i=0;i<matrix_A.matrix.size();i++){
        matrix_C.matrix.push_back(std::vector<int>());
        for(int j=0;j<matrix_B.matrix[0].size();j++){
            matrix_C.matrix[i].push_back(0);
            for(int k=0;k<matrix_A.matrix[0].size();k++){
                matrix_C.matrix[i][j] += matrix_A.matrix[i][k] * matrix_B.matrix[k][j];

            }
        }
    }

    return matrix_C;
}