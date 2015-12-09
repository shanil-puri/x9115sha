#include <boost/math/distributions/students_t.hpp>
#include <iostream>
#include <iomanip>
#include <vector>
#include "t_test.hpp"


using namespace boost::math;
using namespace std;

 int main(int argc, char const *argv[])
 {
 	std::vector<double> v1;
 	std::vector<double> v2;
 	std::vector<double> v3;

 	v1.push_back(1.23);
 	v1.push_back(1.221);
 	v1.push_back(1.222);
 	v1.push_back(1.2223);
 	v1.push_back(1.24);
 	v1.push_back(1.229);
 	v1.push_back(1.2312);

 	v2.push_back(1.1223);
 	v2.push_back(1.1221);
 	v2.push_back(1.1212);
 	v2.push_back(1.1123);
 	v2.push_back(1.1234);
 	v2.push_back(1.1249);
 	v2.push_back(1.12312);

 	v3.push_back(1.231);
 	v3.push_back(1.2211);
 	v3.push_back(1.2221);
 	v3.push_back(1.22231);
 	v3.push_back(1.241);
 	v3.push_back(1.2291);
 	v3.push_back(1.23121 );

 	std::pair<double, double> t_test_vals = t_statistics<double>(v1, v2);

 	std::cout << "T Statistic : " << t_test_vals.first << " : degrees of freedom : " << t_test_vals.second << std::endl;

 	students_t dist(t_test_vals.second);

 	double q = cdf(complement(dist, fabs(t_test_vals.first)));
	std::cout << setw(55) << left << "Probability that difference is due to chance" << "=  " 
   		<< setprecision(3) << 2 * q << "\n\n";

   	std::cout << endl << "blah 1 : " << similarity_probability<double>(v1, v2) << endl;
   	cout << "\n#############################################################################\n\n";
	t_test_vals = t_statistics<double>(v1, v3);

 	std::cout << "T Statistic : " << t_test_vals.first << " : degrees of freedom : " << t_test_vals.second << std::endl;

 	students_t dist1(t_test_vals.second);

 	q = cdf(complement(dist1, fabs(t_test_vals.first)));
	std::cout << setw(55) << left << "Probability that difference is due to chance" << "=  " 
   		<< setprecision(3) << scientific << 2 * q << "\n\n";

   	std::cout << endl << "blah 2 : " << similarity_probability<double>(v1, v3) << endl;
 	return 0;
 }