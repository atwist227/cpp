class String {
private:
    unsigned len;

public:
    char* str;

    String();
    String(const String&);
    String(const char*);
    String(unsigned, char);
    ~String();

    char operator[](unsigned);
    String operator+(const String&);
    String& operator+=(const String&);
    String& operator=(const String&);
    bool operator==(const String&);
    explicit operator bool();
    explicit operator unsigned();

    unsigned length();
};
