//
// Created by antonio on 19/09/22.
//

#ifndef TRABALHO_1_SO_FILE_H
#define TRABALHO_1_SO_FILE_H

#include "Matriz.h"
#include <fstream>

class File{
    private:
        std::string file;
    public:
        File(std::string file);
        void printDataInFIle(IMatrix matrix_A, IMatrix matrix_B);
        void scanDataOfFile(FILE file);
};

#endif //TRABALHO_1_SO_FILE_H
