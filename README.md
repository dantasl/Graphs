# Graphs
Developing the final project of 2019.1 class of Graphs, at IMD/UFRN. Implementing DSATUR's algorithm.

## Compiling

The code is compiled using a simple Makefile, configured to run C++11. You can compile this project with:

```make```

## Running

To run this project, you need to provide a valid xml graph file. You can find samples of the test cases inside ```test_cases``` directory.

An example of this is:

```./graphs.out test_cases/test_1_1000_patients.xml```

Where ```graphs.out``` is the executable for this project generated after compiling and ```test_cases/test_1_1000_patients.xml``` is the path to the graph file.
After running, there will be a new file inside ```results``` called ```result_dsatur.txt```. This file is the log of the execution.

### This is a work in progress. There's still some optmizations to be made.
