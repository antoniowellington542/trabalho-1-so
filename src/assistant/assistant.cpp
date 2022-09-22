//
// Created by antonio on 19/09/22.
//

#include "../../include/index.h"
#include <vector>
#include <tuple>

int main(int argc, char* argv[]){

    int lines_matrix_A = atoi(argv[1]);
    int columns_matrix_A = atoi(argv[2]);
    int lines_matrix_B = atoi(argv[3]);
    int columns_matrix_B = atoi(argv[4]);



    Matrix matrix_A;

    std::vector<int> list_A = matrix_A.generateNumbers(lines_matrix_A, columns_matrix_A);
    matrix_A.mountMatrix(list_A, lines_matrix_A, columns_matrix_A);

    Matrix matrix_B;

    std::vector<int> list_B = matrix_A.generateNumbers(lines_matrix_A, columns_matrix_A);
    matrix_B.mountMatrix(list_B, lines_matrix_B, columns_matrix_B);

    std::string file_name = "matrixA";

    Operation operation;

    auto matrix_a = operation.formatData(matrix_A.getMatrix());
    auto matrix_b = operation.formatData(matrix_B.getMatrix());
    File file;
    file.printDataInFIle(matrix_a, file_name);

    std::string file_name_2 = "matrixB";
    file.printDataInFIle(matrix_b, file_name_2);

}