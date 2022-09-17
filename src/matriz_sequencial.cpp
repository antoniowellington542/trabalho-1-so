//
// Created by antonio on 17/09/22.
//

#include <iostream>
#include <vector>


class Matrix{
    private:
        int lines;
        int columns;
        std::vector<std::vector<int> > matrix;

    public:
        Matrix(int lines, int columns){
            this->lines = lines;
            this->columns = columns;
        }
        void mountMatrix(){
            for(int i=0;i<this->lines;i++){
                matrix.push_back(std::vector<int>());
                for(int j = 0;j<this->columns;j++){
                    matrix[i].push_back(rand()%100 +1);
                }
            }
        }

        std::vector<std::vector<int> >& getMatrix(){
            return matrix;
        }
};

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
    std::vector<std::vector<int> > matrix_A;
    std::vector<std::vector<int> > matrix_B;
    std::vector<std::vector<int> > matrix_C;
    public:
        MultiplyMatrix(std::vector<std::vector<int> >* matrix_A, std::vector<std::vector<int> >* matrix_B){
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
    std::vector<std::vector<int> > matrix_b = matrix_B->getMatrix();

    MultiplyMatrix *multiplyMatrix = new MultiplyMatrix(&matrix_a, &matrix_b);

    multiplyMatrix->mountMatrix();

    // View
    View view;

    std::cout << "Matrix A\n";
    view.printMatrix(&matrix_A->getMatrix());
    std::cout << "\n";
    std::cout << "Matrix B\n";
    view.printMatrix(&matrix_B->getMatrix());
    std::cout << "\n";
    std::cout << "Matrix C\n";
    view.printMatrix(&multiplyMatrix->getMatrixResult());

    delete matrix_A;
    delete matrix_B;
    delete multiplyMatrix;

    return 0;
}