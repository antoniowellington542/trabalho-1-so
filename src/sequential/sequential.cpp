//
// Created by antonio on 19/09/22.
//

#include <chrono>
#include "../../include/index.h"

int main(){

    File matrix_A_file;
    File matrix_B_file;

    std::string matrix_A_file_name = "matrixA";
    std::string matrix_B_file_name = "matrixB";

    IMatrix matrix_a = matrix_A_file.scanDataOfFile(matrix_A_file_name);
    IMatrix matrix_b = matrix_B_file.scanDataOfFile(matrix_B_file_name);

    Operation operation;

    IMatrix matrix_resultado;

    int total_time;
    for(int i=0;i<10;i++){
        std::cout << "Execução " << i << "\n";
        std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
        matrix_resultado = operation.multiply(matrix_a, matrix_b);
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        total_time += std::chrono::duration_cast<std::chrono::milliseconds>(end-begin).count();

    }

    std::cout << "Média de tempo: " << total_time/10 << "ms\n";

    File data_file;
    data_file.printDataInFIle(&matrix_resultado, "sequential");

    return 0;
}