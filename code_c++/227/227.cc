class Solution {

public:

    int calculate(string s) {

		s += "=";

        stack<int> opNum;

        stack<char> opChar;

        string strNum = "";

        for (int i = 0; i < s.size(); i ++) {

            if (s[i] == ' ')

                continue;

            else if (isdigit(s[i])) {

                strNum += s[i];

            }

            else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '='){

                int nNum = atoi(strNum.c_str());

                strNum = "";

                if (!opChar.empty() && (opChar.top() == '*' || opChar.top() == '/')) {

                    int topNum = opNum.top();

                    opNum.pop();

                    char topChar = opChar.top();

                    opChar.pop();

                    if (topChar == '*')

                        opNum.push(topNum * nNum);

                    else

                        opNum.push(topNum / nNum);

					if (s[i] != '=')

						opChar.push(s[i]);

                }

                else {

                    opNum.push(nNum);

					if (s[i] != '=')

						opChar.push(s[i]);

                }

            }

		}

				stack<char> stk;

				while (!opChar.empty()) {

					stk.push(opChar.top());

					opChar.pop();

				}

				opChar = stk;



				stack<int> sn;

				while (!opNum.empty()) {

					sn.push(opNum.top());

					opNum.pop();

				}

				opNum = sn;

				opChar = stk;

				while (!opChar.empty()) {

					int n1 = opNum.top();

					opNum.pop();

					int n2 = opNum.top();

					opNum.pop();

					char c = opChar.top();

					opChar.pop();

					switch (c) {

					case '+':

						opNum.push(n1 + n2);

						break;

					case '-':

						opNum.push(n1 - n2);

						break;

					}

				}

		

        return opNum.top();

    }

};
