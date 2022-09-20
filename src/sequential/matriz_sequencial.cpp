//
// Created by antonio on 17/09/22.
//

#include <iostream>
#include <vector>
#include <chrono>
#include "../../include/Matriz.h"


class View{
    public:
        void printMatrix(std::vector<std::vector<int> > *matrix){
            for (auto i: *matrix) {
                for (auto j: i) {
                    std::cout << j << " ";
                }
                std::cout << "\n";
            }
        }
};

class MultiplyMatrix{
    IMatrix matrix_A;
    IMatrix matrix_B;
    IMatrix matrix_C;
    public:
        MultiplyMatrix(IMatrix *matrix_A, IMatrix *matrix_B){
            this->matrix_A = *matrix_A;
            this->matrix_B = *matrix_B;
        }

        void mountMatrix(){
              int lines_A = matrix_A.size();
              int columns_A = matrix_A[0].size();
              int columns_B = matrix_B[0].size();
              for(int i=0;i<lines_A;i++){
                  matrix_C.push_back(std::vector<int>());
                  for(int j=0;j<columns_B;j++){
                      matrix_C[i].push_back(0);
                      for(int k=0;k<columns_A;k++){
                          matrix_C[i][j] += matrix_A[i][k] * matrix_B[k][j];
                      }
                  }
              }

        }

        std::vector<std::vector<int> >& getMatrixResult(){
            return matrix_C;
        }
};

int main(int argc, char *argv[]){

    int lines = atoi(argv[1]);
    int columns = atoi(argv[2]);

    // Matrix A
    Matrix *matrix_A;
    matrix_A = new Matrix(lines, columns);

    matrix_A->mountMatrix();
    std::vector<std::vector<int> > matrix_a = matrix_A->getMatrix();

    // Matrix B

    lines = atoi(argv[3]);
    columns = atoi(argv[4]);

    Matrix *matrix_B = new Matrix(lines, columns);

    matrix_B->mountMatrix();
    IMatrix matrix_b = matrix_B->getMatrix();

    MultiplyMatrix *multiplyMatrix = new MultiplyMatrix(&matrix_a, &matrix_b);

    int total_time;
    for(int i=0;i<10;i++){
        std::cout << "Execução " << i << "\n";
        std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
        multiplyMatrix->mountMatrix();
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        
        total_time += std::chrono::duration_cast<std::chrono::milliseconds>(end-begin).count();
        
    }

    std::cout << "Média de tempo: " << total_time/10 << "ms\n";

    delete matrix_A;
    delete matrix_B;
    delete multiplyMatrix;

    return 0;
}