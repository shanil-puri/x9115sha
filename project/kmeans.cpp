#include "iostream"
// #include "Python.h"
#include "string"
#include "vector"
#include "map"
#include <unordered_map>
#include <sys/types.h>
#include "utilities.hpp"
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <dirent.h>
#include <errno.h>
#include "fstream"
#include <sstream>
#include "limits"
#include <ctime>
#include "algorithm"
#include "set"
// #include "python.h"
#include <ctime>
#include <sys/time.h>
#include "datastore.hpp"

std::vector<dataDb *> read_test_dataStore(const string dir, int test_set_count, int total_sets)
{
    // std::vector<string> v;
    std::vector<dataDb *> test_dataStore;
    // std::vector<cv::Mat> labels, centers;

    // dataDb::getFilesInDirectory(&v, dir);
    // for (int i = 0; i < v.size(); ++i)
    // {
    //     dataDb *tmpDataStore = new dataDb();
    //     dataDb::readDataStore(dir + "/" + v[i], tmpDataStore);
    //     test_dataStore.push_back(tmpDataStore);
    // }
    // return test_dataStore;
    int _data_store;
    vector<size_t> tmp;
    tmp.push_back(1);
    tmp.push_back(12);
    for (int i = 0; i < 2; ++i)
    {
        // srand (time(NULL));
        _data_store = rand() % total_sets;
        cout << _data_store << endl;
        // _data_store = 24;
        // cout << _data_store << endl;
        test_dataStore.push_back(dataStoreHash[_data_store]);
        // dataStore.erase(dataStore.begin() + _data_store);
        dataStoreHash.erase(_data_store);
        sleep(1);
    }

    // cout << "\n\n";
    // for (std::vector<dataDb *>::iterator dt = test_dataStore.begin(); dt != test_dataStore.end(); ++dt)
    // {
    //     cout << (*dt)->fileName << "\t";
    //     cout << (*dt)->store_id << endl;
    // }
    // cout << "\nto exit here\n";

    // for (std::vector<dataDb *>::iterator it = dataStore.begin(); it != dataStore.end(); ++it)
    // {
    //     if(dataStoreHash.find( (*it)->store_id ) != dataStoreHash.end()){
    //         cout << (*it)->fileName << "\t";
    //         cout << (*it)->store_id << endl;
    //     }
    // }
    // exit(1);
    return test_dataStore;
}


void run_kmeans_random_no_lables(std::vector<dataDb *> dataStore_test, int cluster_count = 40)
{
    //###################### BENCHMARKING CODE ##############################
    long elapsed_seconds;
    long elapsed_useconds;
    long elapsed_utime;

    struct timeval tempo, tempo1;
    // gettimeofday(&tempo, NULL);
    //###################### BENCHMARKING CODE ##############################

    std::vector<cv::Mat> labels, centers;
    cv::Mat label, center;
    double compactness;

    int i = 0;
    for (std::vector<dataDb *>::iterator parIter = dataStore_test.begin(); parIter != dataStore_test.end(); ++parIter, ++i)
    {
        // if(i < 3){
            gettimeofday(&tempo, NULL);
            cout << "K-means++ for data set no : " << (*parIter)->store_id << endl;
            compactness = kmeans((*parIter)->data, cluster_count, label, cv::TermCriteria( cv::TermCriteria::EPS, 10000, .1), 1, cv::KMEANS_RANDOM_CENTERS, center);
            cout << "compactness : " << compactness << endl;

            gettimeofday(&tempo1, NULL);
            elapsed_seconds = tempo1.tv_sec - tempo.tv_sec;
            elapsed_useconds = tempo1.tv_usec - tempo.tv_usec;
            elapsed_utime = (elapsed_seconds) * 1000000 + elapsed_useconds;
            cout << "CPU Run Time in k means with no history reuse run : " << elapsed_utime << endl << endl;
            //cout << "The Labels Matrix" << label << endl;
        // }
    }
    
    //###################### BENCHMARKING CODE ##############################
    // gettimeofday(&tempo1, NULL);

    // elapsed_seconds = tempo1.tv_sec - tempo.tv_sec;
    // elapsed_useconds = tempo1.tv_usec - tempo.tv_usec;
    // elapsed_utime = (elapsed_seconds) * 1000000 + elapsed_useconds;
    // cout << "\nCPU Run Time in k means with no history reuse run : " << elapsed_utime << endl;
    //###################### BENCHMARKING CODE ##############################
}

void run_kmeans_no_lables(std::vector<dataDb *> dataStore_test, int cluster_count = 40)
{
    //###################### BENCHMARKING CODE ##############################
    long elapsed_seconds;
    long elapsed_useconds;
    long elapsed_utime;

    struct timeval tempo, tempo1;
    // gettimeofday(&tempo, NULL);
    //###################### BENCHMARKING CODE ##############################

    std::vector<cv::Mat> labels, centers;
    cv::Mat label, center;
    double compactness;

    int i = 0;
    for (std::vector<dataDb *>::iterator parIter = dataStore_test.begin(); parIter != dataStore_test.end(); ++parIter, ++i)
    {
        // if(i < 3){
            gettimeofday(&tempo, NULL);
            cout << "K-means++ for data set no : " << (*parIter)->store_id << endl;
            compactness = kmeans((*parIter)->data, cluster_count, label, cv::TermCriteria( cv::TermCriteria::EPS, 10000, .01), 1, cv::KMEANS_PP_CENTERS, center);
            cout << "compactness : " << compactness << endl;

            gettimeofday(&tempo1, NULL);
            elapsed_seconds = tempo1.tv_sec - tempo.tv_sec;
            elapsed_useconds = tempo1.tv_usec - tempo.tv_usec;
            elapsed_utime = (elapsed_seconds) * 1000000 + elapsed_useconds;
            cout << "CPU Run Time in k means with no history reuse run : " << elapsed_utime << endl << endl;
            //cout << "The Labels Matrix" << label << endl;
        // }
    }
    
    //###################### BENCHMARKING CODE ##############################
    // gettimeofday(&tempo1, NULL);

    // elapsed_seconds = tempo1.tv_sec - tempo.tv_sec;
    // elapsed_useconds = tempo1.tv_usec - tempo.tv_usec;
    // elapsed_utime = (elapsed_seconds) * 1000000 + elapsed_useconds;
    // cout << "\nCPU Run Time in k means with no history reuse run : " << elapsed_utime << endl;
    //###################### BENCHMARKING CODE ##############################
}

void run_kmeans_custom_lables(std::vector<dataDb *> dataStore_test, int cluster_count = 40)
{
    //###################### BENCHMARKING CODE ##############################
    long elapsed_seconds;
    long elapsed_useconds;
    long elapsed_utime;

    struct timeval tempo, tempo1;
    // gettimeofday(&tempo, NULL);
    //###################### BENCHMARKING CODE ##############################
    std::vector<cv::Mat> labels, centers;
    int ctr = 0;

    for (std::vector<dataDb *>::iterator parIter = dataStore_test.begin(); parIter != dataStore_test.end(); ++parIter)
    {   
        // if (ctr++ < 1)
        // {
        //     // for (int i = 0; i < dataStoreHash.size(); ++i)
            // {
                gettimeofday(&tempo, NULL);
                cout << "\nHistory reuse K-means for data set no : " << (*parIter)->store_id << endl;
                // (*parIter)->dimBinPoints = dataDb::prepare_pca_data((*parIter)->data, (*parIter)->histograms);

                (*parIter)->relativeRank.clear();
                if((*parIter)->data.cols > PCA_MIN_DIM)
                {
                    (*parIter)->pca = dataDb::PCA_dim_reduction((*parIter)->data);
                    (*parIter)->has_pca = 1;
                }
                
                // cv::Mat labels = dataDb::rank_runt_time_data_set(*parIter);
                size_t store_id = dataDb::rank_runt_time_data_set(*parIter);
                // store_id = (size_t)i;
                // cout << "\nStore Id : " << store_id << endl;
                // store_id = (size_t) i;
                // (*parIter)->centroids = NULL;
                // (*parIter)->labels = NULL;
                // (*parIter)->compactness = 0;
                // if(store_id != 24)
                (*parIter)->compactness = kmeans((*parIter)->data, cluster_count, dataStore[store_id]->labels, cv::TermCriteria( cv::TermCriteria::EPS, 10000, .1), 1, cv::KMEANS_USE_INITIAL_LABELS, (*parIter)->centroids);
                // (*parIter)->compactness = kmeans((*parIter)->data, cluster_count, labels, cv::TermCriteria( cv::TermCriteria::EPS, 10000, .1), 1, cv::KMEANS_USE_INITIAL_LABELS, (*parIter)->centroids);
                cout << "compactness : " << (*parIter)->compactness << endl;
                gettimeofday(&tempo1, NULL);

                elapsed_seconds = tempo1.tv_sec - tempo.tv_sec;
                elapsed_useconds = tempo1.tv_usec - tempo.tv_usec;
                elapsed_utime = (elapsed_seconds) * 1000000 + elapsed_useconds;
                cout << "CPU Run Time in k means with history reuse run : " << elapsed_utime << endl;
            // }
            //cout << "the centroids input are : " << (*parIter)->centroids << endl;
        // }
    }
    
    //###################### BENCHMARKING CODE ##############################
    // gettimeofday(&tempo1, NULL);

    // elapsed_seconds = tempo1.tv_sec - tempo.tv_sec;
    // elapsed_useconds = tempo1.tv_usec - tempo.tv_usec;
    // elapsed_utime = (elapsed_seconds) * 1000000 + elapsed_useconds;
    // cout << "\nCPU Run Time in k means with history reuse run : " << elapsed_utime << endl;
    //###################### BENCHMARKING CODE ##############################
}

void run_kmeans_no_lables_3d_large()
{
    std::vector<dataDb *> dataStore_test;
    const string dir = "../3D_large_data";
    const string test_dir = "../3D_Large_Test_Set";

    int test_set_count = 4;
    int total_sets = 40;
    
    dataStore_test = read_test_dataStore(test_dir, test_set_count, total_sets);
    cout << "Running k-means++ algorithm: \n\n";
    run_kmeans_no_lables(dataStore_test, 80);
}

void run_kmeans_custom_lables_3d_large()
{
    std::vector<dataDb *> dataStore_test;
    const string dir = "../3D_large_data";
    const string test_dir = "../3D_Large_Test_Set";

    cout << "Intiailizing training of history data sets: \t(This may take a while. Please be patient)\n";
    trainDataSet(dir, 80);
    cout << "Training of history data sets completed. \n";

    int test_set_count = floor(0.1 * (int)dataStore.size());
    int total_sets = (int)dataStore.size();
    
    dataStore_test = read_test_dataStore(test_dir, test_set_count, total_sets);

    // cout << "Now running kmeans with custom labels with K-Index = 40: \n\n";
    // run_kmeans_custom_lables(dataStore_test);
    cout << "\n\n############################################################################################\n";
    cout << "now running kmeans with Random Intiailizing :";
    cout << "\n############################################################################################\n\n";
    // run_kmeans_random_no_lables(dataStore_test, 80);
    
    cout << "\n\n############################################################################################\n";
    cout << "now running kmeans with kmeans ++ Intiailizing :";
    cout << "\n############################################################################################\n\n";
    // run_kmeans_no_lables(dataStore_test, 80);
    
    cout << "\n\n############################################################################################\n";
    cout << "now running kmeans with custom labels :";
    cout << "\n############################################################################################\n\n";
    start_time_computation = 1;
    run_kmeans_custom_lables(dataStore_test, 80);

    // cout << "\nReduce Data Points Time : " << reduce_data_points_time;
    // cout << "\nPrepare PCA Data Time : " << prepare_pca_data_time;
    // cout << "\nRank Dataset PCA Projection Time : " << rank_data_set_pca_time;
    cout << "\nRank data set T-Test Computation Time : " << rank_data_set_t_test_time;
    cout << "\nTotal computation over head : " << rank_runt_time_data_set_time << endl;
}

void run_kmeans_no_lables_10d_large()
{
    std::vector<dataDb *> dataStore_test;
    const string dir = "../10D_large_data";
    const string test_dir = "../10D_Large_Test_Set";

    int test_set_count = floor(0.1 * (int)dataStore.size());
    int total_sets = (int)dataStore.size();
    
    dataStore_test = read_test_dataStore(test_dir, test_set_count, total_sets);

    cout << "Running k-means++ algorithm: \n\n";
    run_kmeans_no_lables(dataStore_test, 80);
}

void run_kmeans_custom_lables_10d_large()
{
    std::vector<dataDb *> dataStore_test;
    const string dir = "../10D_large_data";
    const string test_dir = "../10D_Large_Test_Set";

    cout << "Intiailizing training of history data sets: \t(This may take a while. Please be patient)\n";
    trainDataSet(dir, 80);
    cout << "Training of history data sets completed. \n";

    int test_set_count = ceil(0.1 * (int)dataStore.size());
    int total_sets = (int)dataStore.size();
    
    dataStore_test = read_test_dataStore(test_dir, test_set_count, total_sets);

    // cout << "Now running kmeans with custom labels with K-Index = 40: \n\n";
    // run_kmeans_custom_lables(dataStore_test);
    // for (int i = 0; i < 10; ++i)
    // {
        // run_kmeans_no_lables(dataStore_test, 80);
        // cout << "\n\nNow running kmeans with custom labels with K-Index = 80 : \n\n";
        // start_time_computation = 1;
        // run_kmeans_custom_lables(dataStore_test, 80);

        // cout << "\nRank data set T-Test Computation Time : " << rank_data_set_t_test_time;
        // cout << "\nTotal computation over head : " << rank_runt_time_data_set_time + pca_dim_reduction_time << endl;

    cout << "\n\n############################################################################################\n";
    cout << "now running kmeans with Random Intiailizing :";
    cout << "\n############################################################################################\n\n";
    run_kmeans_random_no_lables(dataStore_test, 80);
    
    cout << "\n\n############################################################################################\n";
    cout << "now running kmeans with kmeans ++ Intiailizing :";
    cout << "\n############################################################################################\n\n";
    run_kmeans_no_lables(dataStore_test, 80);
    
    cout << "\n\n############################################################################################\n";
    cout << "now running kmeans with custom labels :";
    cout << "\n############################################################################################\n\n";
    start_time_computation = 1;
    run_kmeans_custom_lables(dataStore_test, 80);

        // cout << "\n\nEnd of computation number : " << i << endl << endl;
    // }

    cout << "\nReduce Data Points Time : " << reduce_data_points_time;
    cout << "\nPrepare PCA Data Time : " << prepare_pca_data_time;
    cout << "\nRank Dataset PCA Projection Time : " << rank_data_set_pca_time;
    cout << "\nRank data set T-Test Computation Time : " << rank_data_set_t_test_time;
    cout << "\nTotal computation over head : " << rank_runt_time_data_set_time + pca_dim_reduction_time << endl;

    
        rank_data_set_t_test_time = 0;
        rank_runt_time_data_set_time = 0;
        pca_dim_reduction_time = 0;
}


int main(int argc, char const *argv[])
{
    std::vector<dataDb *> test_dataStore;
    std::vector<string> v;
    const string dir = "../dataset_two_gas_sources_/dataset_twosources_downsampled";
    dataDb::getFilesInDirectory(&v, dir);
    for (int i = 0; i < 1; ++i)
    {
        dataDb *tmpDataStore = new dataDb();
        dataDb::readDataStore(dir + "/" + v[i], tmpDataStore);
        test_dataStore.push_back(tmpDataStore);
    }

    for (std::vector<dataDb *>::iterator parIter = test_dataStore.begin(); parIter != test_dataStore.end(); ++parIter) 
    {
        cout << endl << (*parIter)->data.rows  << " : " << (*parIter)->data.cols << endl;
    }

    run_kmeans_random_no_lables(test_dataStore, 80);
    run_kmeans_no_lables(test_dataStore, 80);
    return 0;
}
    
