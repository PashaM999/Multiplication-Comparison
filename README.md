# Overview

This algorithm was created to develop from scratch and compare divide-and-conquer and school multiplication algorithms:
The program was developed entirely in ```c++``` language to make it more efficiet.
Custom classes were defined for ease of application. For instance, Class ```Multiplicator``` was created to deal with calculation of large numbers
which are not natively supported by ```c++``` and were stored as a ```Number``` class. ```Multiplicator``` also has functions to apply both algorithms
and store data into a  ```csv``` file for plot creation.

# Usage

Compile and run the ```c++``` code:
```sh
$ g++ main.cpp multiplicator.cpp number.cpp multiplicator.h number.h
$ ./a.out
```
Then you will be prompted to choose what will be the maximum number of digits for the numbers.
After successfull completion you may create a graph using a ```python``` script:
```sh
$ python Main.py
```

Here is the result:

![graph](https://github.com/PashaM999/Multiplication-Comparison/blob/master/Graph/Graph.PNG)
