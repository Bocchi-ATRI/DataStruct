#include <iostream>
#include "string.h"
using namespace std;

bit :: string :: string(const char* str)
{
    _size = strlen(str);
    _capacity = _size;
    _str = new char[_capacity + 1];
    strcpy(_str , str);
}

// bit :: string :: string(const string& s)
// {
//     _size = strlen(s._str);
//     _capacity = _size;
//     _str = new char[_capacity + 1];
//     strcpy(_str , s._str);
// }

bit :: string :: string(const string& s)     //现代写法
: _str(nullptr)
{
    string tmp(s._str);
    swap(_str , tmp._str);
    swap(_size , tmp._size);
    swap(_capacity , tmp._capacity);
}

bit :: string :: ~string()
{
    delete[] _str;
    _str = nullptr;
    _size = _capacity = 0;
}

bit :: string& bit :: string :: operator=(const string& s)
{
    if(_str != s._str)
    {
        _size = s._size;
        _capacity = s._capacity;
        delete[] _str;
        _str = new char[_capacity + 1];
        strcpy(_str , s._str);
    }
    return *this;
}

size_t bit :: string :: size() const
{
    return _size;
}

size_t bit :: string :: capacity() const
{
    return _capacity;
}

char& bit :: string :: operator[](size_t i) const
{
    assert(i < _size);
    return _str[i];
}

bit :: string :: iterator bit :: string :: begin()
{
    return _str;
}

bit :: string :: iterator bit :: string :: end()
{
    return _str + _size;
}

void bit :: string :: reserve(size_t n)
{
    if(n > _capacity)
    {
        char* tmp = new char[n + 1];
        strcpy(tmp , _str);
        delete[] _str;
        _str = tmp;
        _capacity = n;
    }
}

void bit :: string :: push_back(const char ch)
{
    if(_size == _capacity)
    {
        size_t newcapacity = _capacity == 0 ? 2 : _capacity * 2;
        reserve(newcapacity);
    }
    _str[_size] = ch;
    _str[_size + 1] = '\0';
    ++ _size;
}

void bit :: string :: append(const char* str)
{
    size_t len = strlen(str);
    if(_size + len > _capacity)
    {
        size_t newcapacity = _size + len;
        reserve(newcapacity);
    }
    strcpy(_str + _size , str);
    _size += len;
}

bit :: string& bit :: string :: operator+=(const char ch)
{
    push_back(ch);
    return *this;
}

bit :: string& bit :: string :: operator+=(const char* str)
{
    append(str);
    return *this;
}

void bit :: string :: insert(size_t pos , const char ch)
{
    assert(pos <= _size);
    if(_size == _capacity)
    {
        int newcapacity = _capacity == 0 ? 2 : _capacity * 2;
        reserve(newcapacity);
    }
    int end = _size;
    while(end >= pos)
    {
        _str[end + 1] = _str[end];
        -- end;
    }
    _str[pos] = ch;
    ++ _size;
}

void bit :: string :: insert(size_t pos , const char* str)
{
    assert(pos <= _size);
    size_t len = strlen(str);
    if(_size + len > _capacity)
    {
        size_t newcapacity = _size + len;
        reserve(newcapacity + 1);
    }
    size_t end = _size;
    while(end >= pos)
    {
        _str[end + len] = _str[end];
        -- end;
    }
    strncpy(_str + pos , str , len);
    _size += len;
}

void bit :: string :: resize(size_t n , char ch)
{
    if(n < _size)
    {
        _str[n] = '\0';
        _size = n;
    }
    else
    {
        if(n > _capacity)
        {
            reserve(n);
        }
        for(int i = _size ; i < n ; ++ i)
        {
            _str[i] = ch;
        }
        _size = n;
        _str[_size] = '\0';
    }
}

void bit :: string :: erase(size_t pos , size_t len)
{
    assert(pos < _size);
    if(len < _size - pos)
    {
        int tmp = _size - pos - len + 1;
        for(int i = 0 ; i < tmp ; ++ i)
        {
            _str[pos] = _str[pos + len];
            pos ++;
        }
        _size -= len;
    }
    else
    {
        _str[pos] = '\0';
        _size = pos;
    }
}

size_t bit :: string :: find(char ch , size_t pos)
{
    for(size_t i = pos ; i < _size ; ++ i)
    {
        if(_str[i] == ch)
            return i;
    }
    return std :: string :: npos;
}

char* bit :: my_strstr(const char* p1 , const char* p2)
{
    assert(p1);
    assert(p2);
    char* cur = (char*)p1;
    if(*p2 == '\0')
        return nullptr;
    while(*cur)
    {
        char* s1 = cur;
        char* s2 = (char*)p2;
        while((*s1 != '\0') && (*s2 != '\0') && (*s1 == *s2))
        {
            ++ s1;
            ++ s2;
        }
        if(*s2 == '\0')
            return cur;
        ++ cur;
    }
    return nullptr;
}

size_t bit :: string :: find(const char* str , size_t pos)
{
    char* p = strstr(_str , str);
    if(p == nullptr)
        return std :: string :: npos;
    else
        return p - _str;
}

bool bit :: string :: operator<(const string& s)
{
    int ret = strcmp(_str , s._str);
    return ret < 0;
}

bool bit :: string :: operator>(const string& s)
{
    if((*this < s) || (*this == s))
        return false;
    return true;
}

bool bit :: string :: operator>=(const string& s)
{
    return !(*this < s);
}

bool bit :: string :: operator<=(const string& s)
{
    return !(*this > s);
}

bool bit :: string :: operator==(const string& s)
{
    int ret = strcmp(_str , s._str);
    return ret == 0;
}

bool bit :: string :: operator!=(const string& s)
{
    return !(*this == s);
}

namespace bit
{
ostream& operator<<(ostream& out , const string& s)
{
    for(size_t i = 0 ; i < s.size() ; ++ i)
    {
        out << s[i];
    }
    return out;
}

istream& operator>>(istream& in , string& s)
{
    while(1)
    {
        char ch;
        //in >> ch;
        ch = in.get();
        if(ch == ' ' || ch == '\n')
            break;
        s += ch;
    }
    return in;
}
}
