#include <iostream>
#include <string.h>
#include <assert.h>
using namespace std;

#ifndef __STRING_H
#define __STRING_H

namespace bit
{

ostream& operator<<(ostream& out , const string& s);
istream& operator>>(istream& in , string& s);
class string
{
    typedef char* iterator;
    friend ostream& operator<<(ostream& out , const string& s);
    friend istream& operator>>(istream& in , string& s);
    public:
        string(const char* str = "");

        string(const string& s);

        // string(const string& s)     现代写法
        // : _str(nullptr)
        // {
        //     string tmp(s._str);
        //     swap(_str , tmp._str);
        // }

        ~string();

        bool operator<(const string& s);

        bool operator>(const string& s);

        bool operator>=(const string& s);
        
        bool operator<=(const string& s);

        bool operator==(const string& s);

        bool operator!=(const string& s);

        string& operator=(const string& s);

        string& operator+=(const char ch);

        string& operator+=(const char* str);

        char& operator[](size_t i) const;

        size_t size() const;

        size_t capacity() const;

        iterator begin();

        iterator end();

        void reserve(size_t n);

        void push_back(const char ch);

        void append(const char* str);

        void insert(size_t pos , const char ch);

        void insert(size_t pos , const char* str);

        void resize(size_t n , char ch = '\0');

        void erase(size_t pos , size_t len = std :: string :: npos);

        size_t find(char ch , size_t pos = 0);

        size_t find(const char* str , size_t pos = 0);

    private:
        char* _str;
        size_t _size;
        size_t _capacity;
};


    char* my_strstr(const char* p1 , const char* p2);

}

#endif
