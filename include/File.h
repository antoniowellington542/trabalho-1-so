//
// Created by antonio on 19/09/22.
//

#ifndef TRABALHO_1_SO_FILE_H
#define TRABALHO_1_SO_FILE_H

#include "Matriz.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>

class File{
    public:
        void printDataInFIle(IMatrix *matrix_A, std::string file_name);
        IMatrix scanDataOfFile(std::string file_name);
};

#endif //TRABALHO_1_SO_FILE_H
