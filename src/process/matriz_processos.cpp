#include "../../include/Matriz.h"

#include <cstring>
#include <iostream>
#include <sys/ipc.h>
#include <vector>
#include <unistd.h>
#include <sys/shm.h>
#include <stdlib.h>

//void multiply_matrix(int *matrix_result, Matrix *matrix_A, Matrix *matrix_B, int line){
//
//    int columns_A = matrix_A->getMatrix()[0].size();
//    int columns_B = matrix_B->getMatrix()[0].size();
//    long int posFinal = (line+1)*columns_B; // 2
//    long int posInicial = posFinal-columns_B; // 0
//    for(int j=0;j<columns_B;j++) {
//        for(int k=0;k<columns_A;k++){
//            matrix_result[posInicial] += matrix_A->getMatrix()[line][k] * matrix_B->getMatrix()[k][j];
//        }
//        posInicial++;
//    }
//}

int main(int argc, char* argv[]){

    int lines_matrix_A = atoi(argv[1]);
    int columns_matrix_A = atoi(argv[2]);
    int lines_matrix_B = atoi(argv[3]);
    int columns_matrix_B = atoi(argv[4]);

    int size = lines_matrix_A*columns_matrix_B;

    int shmid = shmget(IPC_PRIVATE, size*sizeof(int), IPC_CREAT | 0666);

    if(shmid == -1){
        std::cout << "Erro ao criar memória compartilhada " << strerror(errno) << "\n!";
        exit(1);
    }

    Matrix *matrix_A = new Matrix(lines_matrix_A, columns_matrix_A);
    matrix_A->mountMatrix();
    Matrix *matrix_B = new Matrix(lines_matrix_B, columns_matrix_B);
    matrix_B->mountMatrix();

    int *matrix = (int*) shmat(shmid,0,0);

    pid_t process[lines_matrix_A];

    int total_time;

    for(int k=0;k<10;k++){
        std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
        for(int i=0;i<lines_matrix_A;i++){
            process[i] = fork();
            if(process[i] == 0){
                multiply_matrix(matrix, matrix_A, matrix_B, i);
                exit(0);
            }
            process[i] =  wait(NULL);
        }
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        total_time = std::chrono::duration_cast<std::chrono::milliseconds>(end-begin).count();
    }

    double media_time = total_time/10;
    wait(NULL);
    std::cout << "Processo executado em " << total_time << "[ms] e a média de tempo foi de "<< media_time << "[ms].\n";

    shmdt(matrix);
    shmctl(shmid,IPC_RMID, NULL);

    return 0;
}