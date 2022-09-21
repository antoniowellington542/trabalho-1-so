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

    Matrix matrix_A;

    std::vector<int> list_A = matrix_A.generateNumbers(lines_matrix_A, columns_matrix_A);
    matrix_A.mountMatrix(list_A, lines_matrix_A, columns_matrix_A);

    Matrix matrix_B;

    std::vector<int> list_B = matrix_A.generateNumbers(lines_matrix_A, columns_matrix_A);
    matrix_B.mountMatrix(list_B, lines_matrix_B, columns_matrix_B);

    std::string file_name = "matrixA";
    File first_file;
    first_file.printDataInFIle(&matrix_A.getMatrix(), file_name);

    std::string file_name_2 = "matrixB";
    File second_file;
    second_file.printDataInFIle(&matrix_B.getMatrix(), file_name_2);

}