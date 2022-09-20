//
// Created by antonio on 19/09/22.
//

#include <chrono>
#include "../../include/Matriz.h"
#include "../../include/File.h"

int main(){

    File *matrix_A_file;
    File *matrix_B_file;

    std::string matrix_A_file_name = "matrixA";
    std::string matrix_B_file_name = "matrixB";

    Matrix *matrix_A;
    matrix_A->mountMatrix(matrix_A_file->scanDataOfFile(matrix_A_file_name));

    Matrix *matrix_B;
    matrix_B->mountMatrix(matrix_B_file->scanDataOfFile(matrix_B_file_name));

    int total_time;
    for(int i=0;i<10;i++){
        std::cout << "Execução " << i << "\n";
        std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
        matrix_A->multiplyMatrix(&matrix_B->getMatrix());
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        total_time += std::chrono::duration_cast<std::chrono::milliseconds>(end-begin).count();

    }

    std::cout << "Média de tempo: " << total_time/10 << "ms\n";

    File *data_file = new File("sequential");
    data_file->printDataInFIle(&matrix_A->multiplyMatrix(&matrix_B->getMatrix()));

    delete matrix_A;
    delete matrix_B;

    return 0;
}