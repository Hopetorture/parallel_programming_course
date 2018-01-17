#include "mpiload.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QCryptographicHash>
//#include <mpi.h>
#include <stdio.h>


MPILoad::MPILoad()
{
    this->workloadName = "MPI thread load";
}

QStringList MPILoad::startLoad(QMap<QString, QVariant> args)
{
    if (!readDict())
        throw new QString("could not read dict");

    startTimer();
    //std::cout << "single thread calculations" << std::endl;
 //   int argc = 0;
//       int numberOfProcessors;
//       int rank;
//       int namelen;
//       char processor_name[MPI_MAX_PROCESSOR_NAME];
//       MPI_Init(&argc, NULL);
//       printf("Hello MPI\r\n");
//       MPI_Comm_size(MPI_COMM_WORLD,&numberOfProcessors);
//       printf("Number of processor = %d\r\n", numberOfProcessors);
//       MPI_Get_processor_name(processor_name, &namelen);
//       printf("Process Name = %s\r\n", processor_name);
//       MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//       printf("Proses pada %d\r\n", rank);
//       MPI_Finalize();

//    for (const QString &out : resultsHex)
//        std::cout << out.toStdString() << std::endl;
    stopTimer();
    return resultsHex;
}

