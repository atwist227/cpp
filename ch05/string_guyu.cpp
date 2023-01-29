#include <cstring>
class String {
private:
    unsigned len;

public:
    char* str;

    String() {
        len = 0;
        str = new char[1]{'\0'};
    }
    String(const String& initVal) {
        len = initVal.len;
        str = new char[len + 1];
        for (unsigned i{0}; i <= len; i++)
            str[i] = initVal.str[i];
    }
    String(const char* initVal) {
        len = std::strlen(initVal);
        str = new char[len + 1];
        for (unsigned i{0}; i <= len; i++)
            str[i] = initVal[i];
    }
    String(unsigned num, char c) {
        len = num;
        str = new char[num + 1];
        for (unsigned i{0}; i <= num; i++)
            str[i] = c;
        str[num] = '\0';
    }
    ~String() {
        delete[] str;
    }

    char operator[](unsigned pos) {
        return str[pos];
    }
    String operator+(const String& b) {
        char* newstr{new char[len + b.len + 1]};
        std::strcpy(newstr, str);
        std::strcpy(newstr + len, b.str);
        String result(newstr);
        delete[] newstr;
        return result;
    }
    String& operator+=(const String& b) {
        String result(operator+(b)); //
        operator=(result);
        return *this;
    }
    String& operator=(const String& assignVal) {
        if (str == assignVal.str) return *this;
        delete[] str;
        len = assignVal.len;
        str = new char[len];
        for (unsigned i{0}; i < len; i++) {
            str[i] = assignVal.str[i];
        }
        return *this;
    }
    explicit operator bool() {
        if (len == 0) return false;
        else return true;
    }

    unsigned length() {
        return len;
    }
};
