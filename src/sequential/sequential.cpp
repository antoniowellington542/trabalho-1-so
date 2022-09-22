//
// Created by antonio on 19/09/22.
//

#include <chrono>
#include "../../include/index.h"

int main(int argc, char* argv[]){

    File matrix_A_file;
    File matrix_B_file;

    std::string matrix_A_file_name = argv[1];
    std::string matrix_B_file_name = argv[2];

    IMatrix matrix_a = matrix_A_file.scanDataOfFile(matrix_A_file_name);
    IMatrix matrix_b = matrix_B_file.scanDataOfFile(matrix_B_file_name);

    Operation operation;

    IMatrix matrix_result;

    double total_time;
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    matrix_result = operation.multiply(matrix_a, matrix_b);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    total_time = std::chrono::duration_cast<std::chrono::milliseconds>(end-begin).count();

    auto matrix = operation.formatData(matrix_result);

    File data_file;
    data_file.printDataInFIle(matrix,"sequential", total_time, "sequential");

    return 0;
}