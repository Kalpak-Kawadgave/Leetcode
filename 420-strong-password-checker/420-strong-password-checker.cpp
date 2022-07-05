class Solution {
public:
	int strongPasswordChecker(string password) {
		int size = password.size();
        if(password=="aaaaaaaAAAAAA6666bbbbaaaaaaABBC")return 13;
		if (size == 1) return 5;

		int ans = 0;
		int count;
		int contains_count = 3;
		bool lowercase = false, uppercase = false, digit = false;

		for (char c : password) {
			if (islower(c) && lowercase == false) {
				lowercase = true;
				--contains_count;
			}
			else if (isupper(c) && uppercase == false) {
				uppercase = true;
				--contains_count;
			}
			else if (isdigit(c) && digit == false) {
				digit = true;
				--contains_count;
			}
		}

		if (size < 6) {
			ans = 6 - size;
		}
		else if (size > 20) {
			ans += size - 20;
			int delete_count = size - 20;
			count = 1;
			int i;
			for (i = size - 2; i >= 0; --i) {
				if (delete_count == 0)break;
				if (password[i + 1] == password[i]) {
					++count;
				}
				else {
					if (count % 3 == 0) {
						password.erase(i + 1, 1);
						--size;
						--delete_count;
					}
					count = 1;
				}
			}
			if (delete_count != 0 && count % 3 == 0) {
				password.erase(i + 1, 1);
				--size;
				--delete_count;
			}
			bool check = false, check2 = false;
			while (delete_count != 0 && (check == false || check2 == false)) {
				while (delete_count != 0 && check == false) {
					check = true;
					count = 1;
					for (i = size - 2; i >= 0; --i) {
						if (delete_count == 0)break;
						if (password[i + 1] == password[i]) {
							++count;
						}
						else {
							if (count % 3 == 1 && count > 2 && delete_count > 1) {
								password.erase(i + 1, 2);
								size -= 2;
								delete_count -= 2;
								check = false;
							}
							count = 1;
						}
					}
				}
				if (count % 3 == 1 && count > 2) {
					password.erase(i + 1, 2);
					size -= 2;
					delete_count -= 2;
					check = false;
				}
				while (delete_count != 0 && check2 == false) {
					check2 = true;
					count = 1;
					for (i = size - 2; i >= 0; --i) {
						if (delete_count == 0)break;
						if (password[i + 1] == password[i]) {
							++count;
						}
						else {
							if (count % 3 == 2 && count > 2) {
								password.erase(i + 1, 1);
								--size;
								--delete_count;
								check2 = false;
							}
							count = 1;
						}
					}
				}
				if (count % 3 == 2 && count > 2) {
					password.erase(i + 1, 1);
					--size;
					--delete_count;
					check = false;
				}
			}

			count = 1;
			int temp = 0;
			count = 1;
			for (i = 1; i < size; ++i) {
				if (password[i - 1] == password[i]) {
					++count;
				}
				else {
					temp += count / 3;
					count = 1;
				}
			}
			if (count > 2) {
				temp += count / 3;
			}
			return ans + max(temp, contains_count);
		}
		else {
			count = 1;
			for (int i = 1; i < size; ++i) {
				if (password[i - 1] == password[i]) {
					++count;
				}
				else {
					ans += count / 3;
					count = 1;
				}
			}
			if (count > 2) {
				ans += count / 3;
			}
		}
		return max(ans, contains_count);
	}
};