#include "../common.h"

class Expression_Function
{
private:
  int precedence(char c)
  {
    if (c == '^')
    {
      return 3;
    }
    else if (c == '*' || c == '/')
    {
      return 2;
    }
    else if (c == '+' || c == '-')
    {
      return 1;
    }
    else
    {
      return -1;
    }
  }

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

  string infix_to_postfix(string str)
  {
    stack<char> st;
    string res;

    for (int i = 0; i < str.length(); i++)
    {
      if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
      {
        res += str[i];
      }
      else if (str[i] == '(')
      {
        st.push('(');
      }
      else if (str[i] == ')')
      {
        while (!st.empty() && st.top() != '(')
        {
          res += st.top();
          st.pop();
        }

        if (!st.empty())
        {
          st.pop();
        }
      }
      else
      {
        while (!st.empty() && precedence(st.top()) > precedence(str[i]))
        {
          res += st.top();
          st.pop();
        }
        st.push(str[i]);
      }
    }

    while (!st.empty())
    {
      res += st.top();
      st.pop();
    }
    return res;
  }

  
};

int main()
{
  Expression_Function ef;
  // cout << "Prefix Result: " << ef.evaluate_prefix("-+7*45+20") << ", Expected: 25" << lb;
  // cout << "Postfix Result: " << ef.evaluate_postfix("46+2/5*7+") << ", Expected: 32" << lb;
  cout << "Infix To Postfix Result: " << ef.infix_to_postfix("(a-b/c)*(a/k-l)") << ", Expected: abc/-ak/l-*" << lb;

  return 0;
}
