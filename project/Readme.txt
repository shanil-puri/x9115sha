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
2) Use the following command to compile the source code:
	
	-> OS-X Compilation: g++ -o crossover_testing crossover_testing.cpp $(pkg-config opencv --cflags --libs);
	
	-> Python Compilation:  g++ -o  crossover_testing crossover_testing.cpp -I/usr/include/python2.7  -DNDEBUG -g -fwrapv -O3 -Wall -lpython2.7 -L/usr/lib/python2.7/config-x86_64-linux-gnu/ -std=c++11  $(pkg-config opencv --cflags --libs);

	-> Should compile without any erros or warnings.
3) ./crossover_testing: Select between options shown on screen.
4) Now you shoudl see it run on terminal  and output will be printed to terminal.

Instructions on how to interpret the results.
=====
1. Each "#########" sepreated value set represents a parent data set with how the other history sets rank with respect to that dataset. It also will display the relative probability of similarity with that data-set (Summation of all the probabilities of the individual dimension) and the also show the t-statistic also as a summation for all dimensions.
2. Run Time for training data-set has been displayed at end.

Limitations:
======
1. Only in memory implementation has been done, thus input size will be dependent on the memory available.

Code Structure:
======
1. 3 header files have been made:
	a. datastore.hpp: Contains all the computations that are carried out on the data-set including metric calculations and PCA and bin based reductions.
	b. utilities.hpp: Contains utilitu functions for custom sorter for map etc.
	c. t_test.hpp: Contains implementation of Welch's Test.
2. crossover_testing.cpp: Main file. Contains code to run and compare kmeans, kmeans++ and Kmeans with History Reuse performances.

Notes:
======
1. Report can be found [here](https://github.com/shanil-puri/x9115sha/blob/master/project/Project_Report.pdf)
2. Paper in ICML format can be found [here](https://github.com/shanil-puri/x9115sha/blob/master/project/history_reuse-kmeans.pdf). Please note this paper is a work in progress and has not been completed.
3. All experiments have been perfomed on the following system configurations:
	a. RAM: 8 GB 1600 MHz DDR3
	b. Processor: 2.6 GHz Intel Core i5
	c. OS: OS X El Capitan.
