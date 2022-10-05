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

    int tam = number_of_loop(size, p);

    int MAX_THREADS = (matrix_a.matrix.size() * matrix_b.matrix.size()) / p;

    pthread_t threads[MAX_THREADS];

    int first_position=0;
    int last_position=0;
    int k=0;
    int j=0;
    std::tuple<int,int,std::vector<int> > pos;
    std::get<0>(pos) = k;
    std::get<1>(pos) = j;
    for(int i=0;i<tam;i++){
        process[i] = fork();
        begin = p*i;
        process[i] = fork;
        if(process[i] == 0){
            std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
            for (int i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, multi, (void*)(size_t)(i));
    }
            for (int i = 0; i < MAX_THREADS; i++){
		pthread_join(threads[i], NULL);
	}  

                chrono::steady_clock::time_point end = chrono::steady_clock::now();
            file<<"Tempo: "<<chrono::duration_cast<chrono::milliseconds>(end - begin).count() << "(ms)" <<endl;
            
            file.close();
            cout <<i<< " Tempo " <<chrono::duration_cast<chrono::milliseconds>(end - begin).count() << "(ms)" <<endl;
        
            break;
            }
            
    }
//
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
