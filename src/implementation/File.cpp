//
// Created by antonio on 19/09/22.
//

#include "../../include/File.h"

void File::printDataInFIle(IMatrix *matrix_A, std::string file_name) {

    std::ofstream new_file;
    std::string path = "../../data/" + file_name + ".txt";

    new_file.open(path, std::ios::trunc);

    if(new_file.is_open()){
       // Matrix A
       for(auto i: matrix_A->matrix){
           for(auto j: i){
               new_file << j << " ";
           }
           new_file << "\n";
       }
    }else{
        std::cout << "Arquivo não existe!";
    }

    new_file.close();

}

IMatrix File::scanDataOfFile(std::string file_name) {

    std::ifstream new_file;
    std::string path = "../../data/" + file_name + ".txt";
    std::vector<int> numbersOfMatrix;
    int rows = 0;
    int columns = 0;
    std::string line;

    new_file.open(path, std::ios::in);

    if(new_file.is_open()){
        int aux = 1;
        int pos = 0;
        while(std::getline(new_file, line, '\n')){
            char target = ' ';
            while((pos = line.find_first_of(target)) != std::string::npos) {
                numbersOfMatrix.push_back(stol(line.substr(0, pos)));
                line.erase(0,pos+1);
                aux++;
            }
            rows++;
            columns = aux;
            aux=0;
        }
    }else{
        std::cout << "Arquivo não existe!";
    }

    new_file.close();

    IMatrix _matrix;
    int k=0;
    for(int i=0;i<rows;i++){
        _matrix.matrix.push_back(std::vector<int>());
        for(int j=0;j<columns;j++){
            _matrix.matrix[i].push_back(numbersOfMatrix[k]);
            k++;
        }
    }

//    for(int i=0;i<rows;i++){
//        for(int j=0;j<columns;j++){
//            std::cout << _matrix.matrix[i][j] << "-";
//        }
//    }

    return _matrix;

}