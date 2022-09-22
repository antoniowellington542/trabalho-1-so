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

    std::cout << std::endl;

    return matrix_C;
}

std::tuple<int,int,std::vector<int>> Operation::multiply_line(int *matrix,IMatrix matrix_A, IMatrix matrix_B, int i, int j, int p, int last_position) {

    int count = 0;
    std::vector<int> list;
    for(;i<matrix_A.matrix.size();i++){
        for(;j<matrix_B.matrix[i].size();j++){
            for(int k=0;k<matrix_A.matrix[0].size();k++){
               matrix[last_position] += matrix_A.matrix[i][k] * matrix_B.matrix[k][j];
               std::cout << matrix[last_position] << "-";
            }
            last_position++;
            count++;
            if(count == p){
                break;
            }
        }
    }

    std::tuple<int,int,std::vector<int> > pos(i,j, list);

    return pos;

}

std::tuple<int,int, std::vector<int> > Operation::formatData(IMatrix matrix) {
    std::tuple<int, int, std::vector<int> > list;
    std::get<0>(list) = matrix.matrix.size();
    std::get<1>(list) = matrix.matrix[0].size();
    for(auto i: matrix.matrix){
        for(auto j: i){
            std::get<2>(list).push_back(j);
        }
    }

    return list;
}