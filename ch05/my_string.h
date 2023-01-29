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

    char& operator[](unsigned);
    const char& operator[](unsigned) const;
    String operator+(const String&) const;
    String& operator+=(const String&);
    String& operator=(const String&);
    bool operator==(const String&) const;
    explicit operator bool() const;

    unsigned length() const;
};
