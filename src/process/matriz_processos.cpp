#include "../../include/index.h"

#include <cstring>
#include <iostream>
#include <sys/ipc.h>
#include <vector>
#include <unistd.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <chrono>

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

    File matrix_file;

    std::string matrix_A_file_name = argv[1];
    std::string matrix_B_file_name = argv[2];
    int p = atoi(argv[3]);

    IMatrix matrix_a = matrix_file.scanDataOfFile(matrix_A_file_name);
    IMatrix matrix_b = matrix_file.scanDataOfFile(matrix_B_file_name);

    int lines  = matrix_a.matrix.size();
    int columns = matrix_b.matrix[0].size();

    int size = lines*columns;

    int shmid = shmget(IPC_PRIVATE, size*sizeof(int), IPC_CREAT | 0666);

    if(shmid == -1){
        std::cout << "Erro ao criar memória compartilhada " << strerror(errno) << "\n!";
        exit(1);
    }

    int *matrix = (int*) shmat(shmid,0,0);

    double total_time;

    Operation operation;

    auto number_of_loop = [](int a, int b){
        int tam = a/b;
        if(a%b != 0)
            return ++tam;
        return tam;
    };

    int tam = number_of_loop(size, p);

    pid_t process[tam];


    int last_position=0;
    int k=0;
    int j=0;
    std::tuple<int,int,std::vector<int> > pos;
    std::get<0>(pos) = k;
    std::get<1>(pos) = j;
    for(int i=0;i<tam;i++){
        process[i] = fork();
        if(process[i] == 0){
            std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
            pos = operation.multiply_process(matrix, matrix_a, matrix_b, std::get<0>(pos), std::get<1>(pos), p, last_position);
//            std::cout << "i: " << std::get<0>(pos) << " j: " << std::get<1>(pos) << std::endl;
                                                                            std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
            total_time = std::chrono::duration_cast<std::chrono::milliseconds>(end-begin).count();
            std::string file_name = "process "+std::to_string(i+1);

            std::cout << std::endl;
            //std::tuple<int,int,std::vector<int> > list(lines,columns,std::get<2>(pos));
            //matrix_file.printDataInFIle(list, file_name, total_time, "sequential");
            exit(0);
        }
        last_position += p;

        process[i] =  wait(NULL);
    }
//
    wait(NULL);
//
////    for(int i=0;i<matrix_a.matrix.size();i++){
////        for(int j=0;j<matrix_a.matrix[0].size();j++){
////            std::cout << matrix_a.matrix[i][j] << " ";
////        }
////        std::cout << std::endl;
////    }
////    std::cout << std::endl;
////    for(int i=0;i<matrix_b.matrix.size();i++){
////        for(int j=0;j<matrix_b.matrix[0].size();j++){
////            std::cout << matrix_b.matrix[i][j] << " ";
////        }
////        std::cout << std::endl;
////    }
////
////    for(int i=0;i<size;i++){
////        std::cout << matrix[i] << "-";
////    }
//
////    std::cout << "Processo executado em " << total_time << "[ms] e a média de tempo foi de "<< media_time << "[ms].\n";

    shmdt(matrix);
    shmctl(shmid,IPC_RMID, NULL);

    return 0;
}