//
// Created by antonio on 19/09/22.
//

#include "../../include/File.h"
#include <iomanip>
#include <tuple>
void File::printDataInFIle(std::tuple<int,int, std::vector<int> > matrix, std::string file_name, double time_execution, std::string algorithm) {

    std::ofstream new_file;
    std::string path = "../../data/" + file_name + ".txt";

    new_file.open(path, std::ios::trunc);

    if(new_file.is_open()){
       // Matrix
       int rows = std::get<0>(matrix);
       int columns = std::get<1>(matrix);
       std::vector<int> list_numbers = std::get<2>(matrix);
       if(algorithm == "assistant"){
           for(int i=0;i<rows*columns;i++){
               new_file << list_numbers[i] << " ";
               if((i+1)%columns == 0){
                   new_file << "\n";
               }
           }
       }else{
           new_file << rows << "x" << columns << std::endl;
           int j=1;
           int k=1;
           for(int i=0;i<rows*columns;i++){
               new_file << "C(" << k << "," <<j << ") " << list_numbers[i] << std::endl;
               j++;
               if((i+1)%columns == 0){
                   j=1;
                   k++;
               }
           }
       }
        if(time_execution != -1){
            new_file << std::fixed << std::setprecision(4);
            new_file << time_execution << "[ms]\n";
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