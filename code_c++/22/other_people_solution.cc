// 1
vector<string> result;
vector<string> generateParenthesis(int n) {
    helper("", n, 0);
    return result;
}

/*  this hepler function insert result strings to "vector<string> result"
    When number of '(' less than "n", can append '(';
    When number of '(' is more than number of ')', can append ')';

    string s : current string;
    int leftpare_need : number of '(' that have not put into "string s";
    int moreleft : number of '(' minus number of ')' in the "string s";
*/

void helper(string s, int leftpare_need, int moreleft)
{
    if(leftpare_need == 0 && moreleft == 0)
    {
        result.push_back(s);
        return;
    }
    if(leftpare_need > 0)
        helper(s + "(", leftpare_need - 1, moreleft+1);
    if(moreleft > 0)
        helper(s + ")", leftpare_need, moreleft - 1);
}


// 2 similar to 3
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n==0) return vector<string>(1,"") ;
        if(n==1) return vector<string>(1,"()") ;
        vector<string> result;
        for(int i=0;i!=n;i++)
            for(auto inner: generateParenthesis(i))
                for(auto outter:  generateParenthesis(n-i-1))
                    result.push_back("("+inner+")"+outter);
        return result;
    }
};

//3 
My method is DP. First consider how to get the result f(n) from previous result f(0)...f(n-1). Actually, the result f(n) will be put an extra () pair to f(n-1). Let the "(" always at the first position, to produce a valid result, we can only put ")" in a way that there will be i pairs () inside the extra () and n - 1 - i pairs () outside the extra pair.

Let us consider an example to get clear view:

f(0): ""

f(1): "("f(0)")"

f(2): "("f(0)")"f(1), "("f(1)")"

f(3): "("f(0)")"f(2), "("f(1)")"f(1), "("f(2)")"

So f(n) = "("f(0)")"f(n-1) , "("f(1)")"f(n-2) "("f(2)")"f(n-3) ... "("f(i)")"f(n-1-i) ... "(f(n-1)")"


public class Solution
{
    public List<String> generateParenthesis(int n)
    {
        List<List<String>> lists = new ArrayList<>();
        lists.add(Collections.singletonList(""));

        for (int i = 1; i <= n; ++i)
        {
            final List<String> list = new ArrayList<>();

            for (int j = 0; j < i; ++j)
            {
                for (final String first : lists.get(j))
                {
                    for (final String second : lists.get(i - 1 - j))
                    {
                        list.add("(" + first + ")" + second);
                    }
                }
            }

            lists.add(list);
        }

        return lists.get(lists.size() - 1);
    }
}

