//
// Created by antonio on 19/09/22.
//

#include "../../include/File.h"

File::File(std::string file) {

    this->file = file;

}

void File::printDataInFIle(IMatrix *matrix_A) {

    std::ofstream new_file;
    std::string path = "../../data/" + file + ".txt";

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

IMatrix &File::scanDataOfFile(std::string file_name) {

    std::ifstream new_file;
    std::string path = "../../data/" + file + ".txt";
    std::vector<int> numbersOfMatrix;
    int rows = 0;
    std::string line;

    new_file.open(path, std::ios::in);

    if(new_file.is_open()){
        while(std::getline(new_file, line, '\n')){
            int pos = line.find(" ");
            numbersOfMatrix.push_back(stol(line.substr(pos+1)));
            rows++;
        }
    }else{
        std::cout << "Arquivo não existe!";
    }

    new_file.close();

    IMatrix *_matrix;
    int k=0;

    for(int i=0;i<rows;i++){
        for(int j=0;j<numbersOfMatrix.size();j++){
            _matrix->matrix[i][j] = numbersOfMatrix[k];
            k++;
        }
    }

    return *_matrix;

}