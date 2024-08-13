#include "../common.h"

class Expression_Function
{
private:
public:
  int evaluate_prefix(string str)
  {
    stack<int> st;

    for (int i = str.length() - 1; i >= 0; i--)
    {
      if (str[i] >= '0' && str[i] <= '9')
      {
        st.push(str[i] - '0');
      }
      else
      {
        int op1 = st.top();
        st.pop();
        int op2 = st.top();
        st.pop();

        switch (str[i])
        {
        case '+':
          st.push(op1 + op2);
          break;
        case '-':
          st.push(op1 - op2);
          break;
        case '*':
          st.push(op1 * op2);
          break;
        case '/':
          st.push(op1 / op2);
          break;
        case '^':
          st.push(pow(op1, op2));
          break;
        }
      }
    }

    return st.top();
  }

  int evaluate_postfix(string str)
  {
    stack<int> st;

    for (int i = 0; i < str.length(); i++)
    {
      if (str[i] >= '0' && str[i] <= '9')
      {
        st.push(str[i] - '0');
      }
      else
      {
        int op2 = st.top();
        st.pop();
        int op1 = st.top();
        st.pop();

        switch (str[i])
        {
        case '+':
          st.push(op1 + op2);
          break;
        case '-':
          st.push(op1 - op2);
          break;
        case '*':
          st.push(op1 * op2);
          break;
        case '/':
          st.push(op1 / op2);
          break;
        case '^':
          st.push(pow(op1, op2));
          break;
        }
      }
    }

    return st.top();
  }
};

int main()
{
  Expression_Function ef;
  cout << "Prefix Result: " << ef.evaluate_prefix("-+7*45+20") << ", Expected: 25" << lb;
  cout << "Postfix Result: " << ef.evaluate_postfix("46+2/5*7+")<< ", Expected: 32" << lb;

  return 0;
}
