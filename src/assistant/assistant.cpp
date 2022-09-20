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

    IMatrix matrix_a;
    matrix_a.lines = lines_matrix_A;
    matrix_a.columns = columns_matrix_A;

    IMatrix matrix_b;
    matrix_b.lines = lines_matrix_B;
    matrix_b.columns = columns_matrix_B;

    Matrix *matrix_A;
    matrix_A->mountMatrix(matrix_A->generateNumbers(lines_matrix_A, columns_matrix_A), lines_matrix_A, columns_matrix_A);

//    Matrix *matrix_B;
//    matrix_B->mountMatrix(matrix_b);

//    std::string file_name = "matrixA";
//    File *first_file = new File(file_name);
//    first_file->printDataInFIle(&matrix_A->getMatrix());
//
//    std::string file_name_2 = "matrixB";
//    File *second_file = new File(file_name_2);
//    second_file->printDataInFIle(&matrix_B->getMatrix());

}