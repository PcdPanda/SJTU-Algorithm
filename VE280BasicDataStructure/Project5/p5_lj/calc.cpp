#include <iostream>
#include "dlist.h"

using namespace std;

bool isNum(string s) {
    if (s == "-")
        return false;
    if ((s[0] > '9' || s[0] < '0') && (s[0] != '-'))
        return false;
    for (int i = 1; i < s.size(); i++)
        if (s[0] > '9' || s[0] < '0')
            return false;
    return true;
}

bool handleNdp(string s, Dlist<int> &sta) {
    if (sta.isEmpty())
        return false;
    int *a = sta.removeFront();
    if (s == "n") {
        *a = -(*a);
        sta.insertFront(a);
    } else if (s == "d") {
        int *cloneA = new int;
        *cloneA = *a;
        sta.insertFront(a);
        sta.insertFront(cloneA);
    } else if (s == "p") {
        cout << *a << endl;
        sta.insertFront(a);
    } else {
        if (sta.isEmpty()) {
            sta.insertFront(a);
            return false;
        }
        int *b = sta.removeFront();

        if (s == "+") {
            *b += *a;
            sta.insertFront(b);
            delete a;
        } else if (s == "-") {
            *b -= *a;
            sta.insertFront(b);
            delete a;
        } else if (s == "*") {
            *b *= *a;
            sta.insertFront(b);
            delete a;
        } else if (s == "/") {
            if (*a == 0) {
                cout << "Divide by zero\n";
                sta.insertFront(b);
                sta.insertFront(a);
            } else {
                *b /= *a;
                sta.insertFront(b);
                delete a;
            }
        } else if (s == "r") {
            sta.insertFront(a);
            sta.insertFront(b);
        }
    }
    return true;
}

int main() {
    Dlist<int> stack;
    string s;
    cin >> s;
    while (s != "q") {
        if (isNum(s)) {
            int *t = new int;
            *t = atoi(s.c_str());
            stack.insertFront(t);
        } else if (s == "c") {
            while (!stack.isEmpty()) {
                int *front = stack.removeFront();
                delete front;
            }
        } else if (s == "a") {
            Dlist<int> h = stack;
            while (!h.isEmpty()) {
                int *front = h.removeFront();
                cout << *front << ' ';
            }
            cout << endl;
        } else if (s == "+" || s == "-" || s == "*" || s == "/" || s == "r" ||
                   s == "n" || s == "d" || s == "p") {
            if (!handleNdp(s, stack))
                cout << "Not enough operands\n";
        } else
            cout << "Bad input\n";
        cin >> s;
    }
    return 0;
}



