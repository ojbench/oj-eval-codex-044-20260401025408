#include <bits/stdc++.h>
using namespace std;

class mystring {
private:
    char *ch = nullptr;
    int len = 0;

public:
    mystring() : ch(nullptr), len(0) {}

    mystring(int _len, int c) : ch(nullptr), len(0) {
        if (_len > 0) {
            len = _len;
            ch = new char[len + 1];
            for (int i = 0; i < len; ++i) ch[i] = static_cast<char>(c);
            ch[len] = '\0';
        }
    }

    mystring(string &c) : ch(nullptr), len(0) {
        len = static_cast<int>(c.length());
        if (len > 0) {
            ch = new char[len + 1];
            memcpy(ch, c.c_str(), len);
            ch[len] = '\0';
        }
    }

    ~mystring() {
        delete[] ch;
        ch = nullptr;
        len = 0;
    }

    // Copy constructor
    mystring(const mystring &other) : ch(nullptr), len(other.len) {
        if (len > 0) {
            ch = new char[len + 1];
            memcpy(ch, other.ch, len + 1);
        }
    }

    // Move constructor
    mystring(mystring &&other) noexcept : ch(other.ch), len(other.len) {
        other.ch = nullptr;
        other.len = 0;
    }

    // Copy assignment
    mystring &operator=(const mystring &other) {
        if (this == &other) return *this;
        char *nch = nullptr;
        if (other.len > 0) {
            nch = new char[other.len + 1];
            memcpy(nch, other.ch, other.len + 1);
        }
        delete[] ch;
        ch = nch;
        len = other.len;
        return *this;
    }

    // Assign from std::string as in sample (mystring str2 = str_in1;)
    mystring &operator=(const string &s) {
        char *nch = nullptr;
        int nlen = (int)s.length();
        if (nlen > 0) {
            nch = new char[nlen + 1];
            memcpy(nch, s.c_str(), nlen);
            nch[nlen] = '\0';
        }
        delete[] ch;
        ch = nch;
        len = nlen;
        return *this;
    }

    // Indexing: return character or '\0' when out-of-range
    char operator[](int x) const {
        if (x < 0 || x >= len) return '\0';
        return ch ? ch[x] : '\0';
    }

    // Comparison operator < : lexicographic by characters, then by length
    bool operator<(const mystring &rhs) const {
        int m = min(len, rhs.len);
        for (int i = 0; i < m; ++i) {
            if (ch[i] != rhs.ch[i]) return ch[i] < rhs.ch[i];
        }
        return len < rhs.len;
    }

    // ADD: concatenate another mystring to this
    void ADD(const mystring &other) {
        int nlen = len + other.len;
        char *nch = nullptr;
        if (nlen > 0) {
            nch = new char[nlen + 1];
            if (len > 0) memcpy(nch, ch, len);
            if (other.len > 0) memcpy(nch + len, other.ch, other.len);
            nch[nlen] = '\0';
        }
        delete[] ch;
        ch = nch;
        len = nlen;
    }

    // Output function
    void out() const {
        if (len > 0 && ch) {
            cout.write(ch, len);
        }
    }

    // Optional operator<< overload (main mentions optional). We'll not rely on it.
    friend ostream &operator<<(ostream &os, const mystring &ms) {
        if (ms.len > 0 && ms.ch) os.write(ms.ch, ms.len);
        return os;
    }

    int get_len() const { return len; }
};

string str_in1, str_in2;
int n, id;

int main() {
    // Keep default sync to avoid mixing issues with potential printf usage
    ios::sync_with_stdio(true);
    cin.tie(nullptr);

    if (!(cin >> id)) return 0;
    if (id == 1) {
        mystring str1(100, 'a');
        str1.out();
        cout << '\n';
        // cout << str1 << endl;
    } else if (id == 2) {
        cin >> str_in1;
        mystring str2 = str_in1;
        cin >> n;
        for (int i = 0, x; i < n; ++i) {
            cin >> x;
            cout << str2[x] << '\n';
        }
    } else if (id == 3) {
        cin >> str_in1 >> str_in2;
        mystring str2 = str_in1;
        mystring str3 = str_in2;
        cout << (int)(str2 < str3) << '\n';
    } else if (id == 4) {
        cin >> str_in1 >> str_in2;
        mystring str2 = str_in1;
        mystring str3 = str_in2;
        str2.ADD(str3);
        str2.out();
        cout << '\n';
        // cout << str2 << endl;
    } else {
        cin >> str_in1 >> str_in2;
        mystring str2 = str_in1;
        mystring str3 = str_in2;
        cin >> n;
        for (int i = 0, x; i < n; ++i) {
            cin >> x;
            cout << str3[x] << '\n';
        }
        cout << str2.get_len() << " " << str3.get_len() << '\n';
        cout << (int)(str2 < str3) << '\n';
        str2.ADD(str3);
        str2.out();
        cout << '\n';
        // cout << str2 << endl;
        cout << str2.get_len() << '\n';
    }
    return 0;
}
