#ifndef computeMathExpression_h
#define computeMathExpression_h
#include "files.h"

int precedence(char x) {
    if (x == '(') {
        return 1;
    }
    else if (x == ')') {
        return 2;
    }
    else if (x == '^') {
        return 5;
    }
    else if (x == '*' || x == '/' || x == '%') {
        return 4;
    }
    else if (x == '+' || x == '-') {
        return 3;
    }
    else {
        return 0;
    }
}

Vector<string> InfixToPostfix(string infix) {
    Vector<string> postfix;
    Stack<char> st;
    infix = '(' + infix + ')';
    bool ok = true;
    for (int i = 0; i < infix.size(); i++) {
        int x = precedence(infix[i]);
        if (x == 1) {
            st.push(infix[i]);
            ok = true;
        }
        else if (x == 2) {
            while (st.top() != '(') {
                postfix.push_back(string(1, st.top()));
                st.pop();
            }
            st.pop();
            ok = true;
        }
        else if (3 <= x && x <= 5) {
            while (precedence(st.top()) >= x) {
                postfix.push_back(string(1, st.top()));
                st.pop();
            }
            st.push(infix[i]);
            ok = true;
        }
        else {
            if (ok) {
                postfix.push_back(string(1, infix[i]));
            }
            else {
                postfix.back() += infix[i];
            }
            ok = false;
        }
    }
    return postfix;
}

long long power(long long n, long long p, long long mod = 1e9 + 7) {
    n %= mod;
    long long ret = 1;
    while (p) {
        if (p & 1) {
            ret = ret * n % mod;
        }
        n = n * n % mod;
        p >>= 1;
    }
    return ret;
}
long long calc(long long x, long long y, char sign) {
    if (sign == '+') {
        return x + y;
    }
    if (sign == '-') {
        return x - y;
    }
    if (sign == '*') {
        return x * y;
    }
    if (sign == '/') {
        return x / y;
    }
    if (sign == '%') {
        return x % y;
    }
    if (sign == '^') {
        return power(x, y, LLONG_MAX);
    }
    return 0;
}

bool isNumeric(string s) {
    for (auto &it : s) {
        if (!isdigit(it)) {
            return false;
        }
    }
    return true;
}

long long evaluate(string expression) {
    Stack<long long> st;
    auto v = InfixToPostfix(expression);
    for (int i = 0; i < v.size(); ++i) {
        string it = v[i];
        if (isNumeric(it)) {
            st.push(stoll(it));
        }
        else {
            long long op2 = st.top();
            st.pop();
            long long op1 = st.top();
            st.pop();
            st.push(calc(op1, op2, it[0]));
        }
    }
    return st.top();
}

#endif