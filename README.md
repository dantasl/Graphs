# Graphs
Developing the final project of 2019.1 class of Graphs, at IMD/UFRN. Implementing DSATUR's algorithm.

## Compiling

The code is compiled using a simple Makefile, configured to run C++11. You can compile this project with:

```make```

## Running

To run this project, you need to provide a valid xml graph file. You can find samples of the test cases inside ```files``` directory.

An example of this is:

```./graphs.out files/base_test_01.xml```

Where ```graphs.out``` is the executable for this projected generated after compiling and ```files/base_test_01.xml``` is the path to the graph file.
dsatur
After running, there will be a new file inside ```files``` called ```result_dsatur.txt```. This file is the log of the execution.

## This is a work in progress. There's still some optmizations to be made.
