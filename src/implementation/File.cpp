//
// Created by antonio on 19/09/22.
//

#include "../../include/File.h"
#include <iostream>

File::File(std::string file) {
    this->file = file;
}

void File::printDataInFIle(IMatrix matrix_A, IMatrix matrix_B) {

    std::ofstream new_file;
    std::string file_name = "../data/" + file + ".txt";

    new_file.open(file_name, std::ios::trunc);

    if(new_file.is_open()){
       // Matrix A
       for(auto i: matrix_A.matrix){
           for(auto j: i){
               new_file << j << " ";
           }
           new_file << "\n";
       }

       // Matrix B
       for(auto i: matrix_B.matrix){
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