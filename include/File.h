//
// Created by antonio on 19/09/22.
//

#ifndef TRABALHO_1_SO_FILE_H
#define TRABALHO_1_SO_FILE_H

#include "Matriz.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <tuple>

class File{
    public:
        void printDataInFIle(std::tuple<int,int, std::vector<int> > matrix, std::string file_name, double time_execution=-1, std::string algorithm="assistant");
        IMatrix scanDataOfFile(std::string file_name);
};

#endif //TRABALHO_1_SO_FILE_H
