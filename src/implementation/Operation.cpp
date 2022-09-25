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

std::tuple<int,int,std::vector<int>> Operation::multiply_process(int *matrix,IMatrix matrix_A, IMatrix matrix_B, int last_line, int last_column, int p, int last_position) {

    int count = 0;
    std::vector<int> list;
    std::tuple<int,int,std::vector<int> > pos;
    auto stop_calculate = [](int a, int b) {
        if(a == b){
            return true;
        }
        return false;
    };

//    std::cout << "i:" << last_line <<" j: " << last_column << std::endl;
    for(int i= 0;i<matrix_A.matrix.size();i++){ // 0 1 2 3
//        if(stop_calculate(count, p)){
//            std::cout << "i:" << std::get<0>(pos) <<" j: " << std::get<1>(pos) << std::endl;
//            return pos;
//        }
        for(int j=0;j<matrix_B.matrix[0].size();j++){ // 0 1 2 3
            count++; // 1 2 3 4
            std::cout << "i:" << i <<" j: " << j << std::endl;
//            if(stop_calculate(count, p)){
//                std::get<1>(pos) = j;
//                std::get<2>(pos) = list;
//                break;
//            }
        }
    }

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