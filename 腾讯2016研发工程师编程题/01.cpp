class GrayCode {
public:
	vector<string> getGray(int n) {
		// write code here
		vector<string> result;
		if (n == 1) {
			result.push_back("0");
			result.push_back("1");
		}
		else {
			vector<string> temp = getGray(n - 1);
			for (int i = 0; i < temp.size(); i++) {
				result.push_back('0' + temp[i]);
			}
			for (int i = temp.size()-1; i >= 0; i--) {
				result.push_back('1' + temp[i]);
			}
		}
		return result;
	}
};