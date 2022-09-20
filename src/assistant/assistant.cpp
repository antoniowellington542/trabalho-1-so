//
// Created by antonio on 19/09/22.
//

#include "../../include/Matriz.h"
#include "../../include/File.h"
#include <vector>

int main(int argc, char* argv[]){
    int lines_matrix_A = atoi(argv[1]);
    int columns_matrix_A = atoi(argv[2]);
    int lines_matrix_B = atoi(argv[3]);
    int columns_matrix_B = atoi(argv[4]);

    Matrix *matrix_A = new Matrix(lines_matrix_A, columns_matrix_A);
    matrix_A->mountMatrix();

    Matrix *matrix_B = new Matrix(lines_matrix_B, columns_matrix_B);
    matrix_B->mountMatrix();

    std::string file_name = "matrix";
    File *operation = new File(file_name);

    operation->printDataInFIle(matrix_A->getMatrix(), matrix_B->getMatrix());

}