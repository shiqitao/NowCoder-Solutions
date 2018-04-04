class Gift {
public:
	int getValue(vector<int> gifts, int n) {
		// write code here
		int money = -1, num = 0;
		for (int i = 0; i < n; i++) {
			if (gifts[i] == money) {
				num++;
			}
			else if (num == 0) {
				money = gifts[i];
				num = 1;
			}
			else {
				num--;
			}
		}
		int count = 0;
		for (int i = 0; i < n; i++) {
			if (gifts[i] == money) {
				count++;
			}
		}
		if (count * 2>n) {
			return money;
		}
		return 0;
	}
};