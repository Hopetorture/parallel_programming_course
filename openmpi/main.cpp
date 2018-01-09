#include "mpi.h"
//#include <QCoreApplication>
//#include "QCryptographicHash"
#include <openssl/md5.h>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <sstream>
#include <list>

#define bufferSize 16

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
    //MPI_Init(&argc,&argv);
    //MPI::Init();
    int size, rank;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    printf("SIZE = %d RANK = %d\n",size,rank);
    std::ifstream infile(std::to_string(rank));

    /* https://stackoverflow.com/questions/47779060/how-to-scatter-an-array-of-strings-in-mpi-c
     * cluster-version:
     * if (rank == 0){
     * std::ifstream infile("passwords.txt");
     * std::list<std::string> dict;
     *  while(infile >>digest){
     *    dict.push_back(digest);
     *  }     *
     *  MPI_Scatter(..);
     * }
     */

    //std::cout << std::to_string(rank) << "opened" << std::endl;
    std::string digest;
    std::list<std::string> totalResult;
    while(infile >> digest){
        unsigned char result[MD5_DIGEST_LENGTH];
        MD5((unsigned char*)digest.c_str(),digest.size(),result);

        char converted[bufferSize*2 + 1];
        int i;
         for(i=0;i<bufferSize;i++) {
           sprintf(&converted[i*2], "%02X", result[i]);
         }
        std::string s = converted;
        totalResult.push_back(s);
        //std::cout << s << " <<value" << std::endl;
    }

    MPI_Barrier(MPI_COMM_WORLD);

    MPI_Finalize();

    //unsigned char *str = (unsigned char*)"abca";
    //MD5(str, 4, result);
    //QCryptographicHash::hash("test", QCryptographicHash::Md5);
//    unsigned char buffer[bufferSize] = {0,1,2,3,4,5,6,7,8,9,
//                                        10,11,12,13,14,15};
//    for (int i = 0; i < bufferSize; i++)
//        buffer[i] = result[i];

///    char converted[bufferSize*2 + 1];
///    int i;

///     for(i=0;i<bufferSize;i++) {
///       sprintf(&converted[i*2], "%02X", result[i]);
///     }


    ///std::cout << converted << std::endl;
   // return a.exec();
    return 0;
}
