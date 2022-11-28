#include <iostream>

#ifndef _STRING_H_
#define _STRING_H_
class String
{
public:
    String();
    String(const String& str);
    String(const char *s);
    ~String();
    size_t size() const;
    const char* c_str() const;
    const char operator[] (const size_t pos) const;
    String& operator+= (const String& str);
    String& operator+= (const char* s);
    String& operator+= (char c);
    String& operator=  (const String& str);
    String& operator=  (const char* s);
    String& operator=  (char c);
    void swap(String& str);
    void clear();
private:
    char *str_ = nullptr;
    size_t size_ = 0, capacity_ = 0;
};
// relational operators
bool operator<  (const String& lhs, const String& rhs);
bool operator<  (const char*   lhs, const String& rhs);
bool operator<  (const String& lhs, const char*   rhs);
bool operator>  (const String& lhs, const String& rhs);
bool operator>  (const char*   lhs, const String& rhs);
bool operator>  (const String& lhs, const char*   rhs);
bool operator<= (const String& lhs, const String& rhs);
bool operator<= (const char*   lhs, const String& rhs);
bool operator<= (const String& lhs, const char*   rhs);
bool operator>= (const String& lhs, const String& rhs);
bool operator>= (const char*   lhs, const String& rhs);
bool operator>= (const String& lhs, const char*   rhs);
bool operator== (const String& lhs, const String& rhs);
bool operator== (const char*   lhs, const String& rhs);
bool operator== (const String& lhs, const char*   rhs);
bool operator!= (const String& lhs, const String& rhs);
bool operator!= (const char*   lhs, const String& rhs);
bool operator!= (const String& lhs, const char*   rhs);
// operator <<, >>
ostream& operator<< (ostream& os, const String& str);
istream& operator>> (istream& is, String& str);
// operators +
String operator+ (const String& lhs, const String& rhs);
String operator+ (const String& lhs, const char*   rhs);
String operator+ (const char*   lhs, const String& rhs);
String operator+ (const String& lhs, char          rhs);
String operator+ (char          lhs, const String& rhs);

#endif _STRING_H_