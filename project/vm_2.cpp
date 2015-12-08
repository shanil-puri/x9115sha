/*
	Generate all possible paths from 0,0 to m,n in a x*y matrix. Return kth path in lexicogrphical order.
*/
#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;


void generate_all_paths(int m, int n, int i, int j, string& path, std::vector<string>& paths, int is_hor)
{
	if(i >= m || j >= n)
		return;
	// Move horizontally.
	if(i == m-1 && j == n-1)
	{
		paths.push_back(path);
	}

	if(is_hor)
		path += "H";
	else if (is_hor == 0)
	{
		path += "V";
	}

	generate_all_paths(m, n, i+1, j, path, paths, 1);
	generate_all_paths(m, n, i, j+1, path, paths, 0);
}

void Tokenize(const string& str,
                      vector<string>& tokens,
                      const string& delimiters = " ")
{
    // Skip delimiters at beginning.
    string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    // Find first "non-delimiter".
    string::size_type pos     = str.find_first_of(delimiters, lastPos);

    while (string::npos != pos || string::npos != lastPos)
    {
        // Found a token, add it to the vector.
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        // Skip delimiters.  Note the "not_of"
        lastPos = str.find_first_not_of(delimiters, pos);
        // Find next "non-delimiter"
        pos = str.find_first_of(delimiters, lastPos);
    }
}

std::vector<string> return_kth_path(vector<string> positions)
{
	vector<string> all_paths, tokens;
	std::vector<string> return_paths;
	int x, y, k_index;
	string path;
	std::string::size_type sz;
	for (vector<string>::iterator it = positions.begin();it != positions.end(); ++it)
	{
		Tokenize(*it, tokens, " ");
		x 		= stoi(tokens[0], &sz);
		y 		= stoi(tokens[1], &sz);
		k_index = stoi(tokens[2], &sz);

		generate_all_paths(x, y, 0, 0, path, all_paths, -1);
		std::sort(all_paths.begin(), all_paths.end());

		return_paths.push_back(all_paths[k_index - 1]);
	}

	return return_paths;
}

int main(int argc, char const *argv[])
{
	int arr[10][10];
	std::vector<string> v;
	std::vector<string> ret;
	v.push_back("2 2 2");
	v.push_back("2 2 3");
	ret = return_kth_path(v);

	for (int i = 0; i < ret.size(); ++i)
	{
		cout << ret[i] << endl;
	}
	return 0;
}