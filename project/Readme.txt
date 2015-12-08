Software that needs to be installed (if any) with download and installation instructions.
=====
1. Python:
	a. Build dependecies:
		-> sudo yum install build-essential
		-> sudo yum install libreadline-gplv2-dev libncursesw5-dev libssl-dev libsqlite3-dev tk-dev libgdbm-dev libc6-dev libbz2-dev
	b. Download Zip file for python:
		-> wget http://python.org/ftp/python/2.7.5/Python-2.7.5.tgz
	c. Extract and go to the dirctory:
		-> tar -xvf Python-2.7.5.tgz
		-> cd Python-2.7.5
	d. Compile and Install from source:
		-> ./configure
		-> make
		-> sudo make install
2. OpenCV installation:
	a. Lunch Git client and clone into working repo:
		-> cd ~/<my_working _directory>
		-> git clone https://github.com/Itseez/opencv.git
	b. Make new directory for Makefiles and then install
		-> cd ~/opencv
		-> mkdir build
		-> cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local ..
		->  cd build/
		-> make
		-> sudo make install

Environment variable settings (if any).
=====
No additional environment variables are needed for this.

Instructions on how to run the program.
=====
1) Extract folder to working directory.
2) cd ~/final_proj/src: Open file: prepareHistory.cpp and change path of variable “const string dir” to directory path to ~/final_proj/input_data.
3) Use the following command to compile the source code:
	
	-> OS-X Compilation: g++ -o crossover_testing crossover_testing.cpp $(pkg-config opencv --cflags --libs);
	
	-> Python Compilation:  g++ -o  crossover_testing crossover_testing.cpp -I/usr/include/python2.7  -DNDEBUG -g -fwrapv -O3 -Wall -lpython2.7 -L/usr/lib/python2.7/config-x86_64-linux-gnu/ -std=c++11  $(pkg-config opencv --cflags --libs);

	-> Should compile without any erros or warnings.
4) ./initKmeans
5) Now you shoudl see it run on and temincal will be printed to terminal.

Instructions on how to interpret the results.
=====
1. Each "#########" sepreated value set represents a parent data set with how the other history sets rank with respect to that dataset. It also will display the relative probability of similarity with that data-set (Summation of all the probabilities of the individual dimension) and the also show the t-statistic also as a summation for all dimensions.
2. Run Time for training data-set has been displayed at end.

Sample input and output files (if applicable).
=====
1. Sample input files containing data sets are in the ~/final_proj/input_data folder.
2. Sample input files contain 10 pts each represented by 3 dimensions.
3. Sample output is printed on terminal.

Limitations:
======
1. Only in memory implementation has been done, thus input size will be dependent on the memory available.
2. Only hostory training implementation has been done. Adding implementation with K-means algorithms has not been done yet.

Code Structure:
======
1. 3 header files have been made:
	a. datastore.hpp: Contains all the computations that are carried out on the data-set including metric calculations and PCA and bin based reductions.
	b. utilities.hpp: Contains utilitu functions for custom sorter for map etc.
2. One test file has been provided which reads the input files in ~/final_proj/input_data and prepares the history set.
3. tTestScript.py: Python script to run pair-wise t-test on comparable data-set dimensions has been implemented. This file is invoked by the "rank_data_set" function provided in the datastore.hpp file.

References to any software you may have used (if applicable).
=====
OpenCV
Python T-Test library.
