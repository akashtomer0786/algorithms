//operator precedence
1)Parenthesis () {} []
2)Exponents (Right to left)
3)Multiplication and Divison (Left to Right)
4)Addition and Subtraction (Left to Right)

#include<iostream>
#include<string>
#include<stack>
using namespace std;
stack <char> s;
int isprec(char exp) {
	if (exp == '+' || exp == '-')
		return 1;
	if (exp == '*' || exp == '/')
		return 2;
	if (exp == '^')
		return 3;
	return -1;

}
int ischar(char exp) {
	return((exp >= 'a'&&exp <= 'z') || (exp >= 'A'&&exp <= 'Z'));
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		string str;
		cin >> str;
		string result;
		for (int i = 0; i < str.size(); i++) {
			if (ischar(str[i])) {
				result.push_back(str[i]);

			}
			else if (str[i] == '(') {
				s.push(str[i]);
			}
			else if (str[i] == ')') {
				while (!s.empty() && s.top() != '(') {
					result.push_back(s.top());
					s.pop();
				}
				s.pop();
			}
			else {
				if (s.empty()) {
					s.push(str[i]);
					// printf("%c  \n%d",i,s.top());
				}
				else if (isprec(str[i]) > isprec(s.top())) {
					s.push(str[i]);
				}
				else if (isprec(str[i]) <= isprec(s.top())) {
					while (!s.empty() && isprec(str[i]) <= isprec(s.top())) {
						result.push_back(s.top());
						s.pop();
					}
					s.push(str[i]);
				}


			}

		}
		while (!s.empty()) {
			result.push_back(s.top());
			s.pop();
		}
		cout << result<<endl;
	}
}

