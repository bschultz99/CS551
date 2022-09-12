#!/bin/bash

# iterate over the program parameters using nested for loops
# program usage: ./filebenchmark <workload><num_procs>
#     - num_procs: 1-100

# right now the bash script calls the program with only one configuration
for i in {0..99} 
do
    fallocate -l 5M $i.bin
done
