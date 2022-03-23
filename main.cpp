#include<iostream>
#include<string>
#include<vector>
#include<sstream>

using namespace std;

vector<string> split(const string &s, const char delimiter = '\n') {
	istringstream is(s);
	string buffer;
	vector<string> result;

	while (getline(is, buffer, delimiter))
		result.push_back(buffer);

	return result;
}

// abcd\efgh\ijkl\mnop -> ponm\lkji\hgfe\dcba
// 
// abcd -> ponm
// efgh -> lkji
// ijkl -> hgfe
// mnop -> dcba
string rot(const string& strng) {
	string s = strng;
	reverse(s.begin(), s.end());
	return s;
};

//abcd-- > abcd....
//efgh     efgh....
//ijkl     ijkl....
//mnop     mnop....
//		   ....ponm
//		   ....lkji
//		   ....hgfe
//		   ....dcba
string selfieAndRot(const string& strng) {
	string result;
	string reversedResult;
	string temp = strng;
	vector<string> vec = split(temp);
	string row;

	for (int i = 0; i < vec.size(); i++) {
		result += vec[i] + string(vec[i].size(), '.') + "\n";
	}

	reversedResult = result;
	reversedResult.pop_back();
	reverse(reversedResult.begin(), reversedResult.end());

	return result + reversedResult;
}

int main() {
	string str = "abcd\nefgh\nijkl\nmnop";

	cout << selfieAndRot(str);

	return 0;
}
