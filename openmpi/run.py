#!/usr/bin/python
import time
import os
import subprocess

def main():
    start_time= time.time()
    #os.system("mpirun ./a.out")
    proc = subprocess.call(["mpirun", "-n", "2", "./a.out"])
    print('--- %s seconds ---' % (time.time() - start_time))


if __name__ == "__main__":
    main()
