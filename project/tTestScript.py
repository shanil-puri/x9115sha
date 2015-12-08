import numpy
import scipy
import matplotlib

from scipy import stats
def t_test_PCA_Val(b1, b2):
	if set(b1) == set(b2) :
		return (1,1)
	paired_sample  = stats.ttest_rel(b1, b2)
	# print "The t-statistic is %.3f and the p-value is %.3f." % paired_sample
	return paired_sample
