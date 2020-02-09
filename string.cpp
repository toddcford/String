#include <iostream>
using namespace std;


class String {
private:
  size_t  m_length;
  char *  m_str;

  String(size_t len) {
    m_length = len;
    m_str = new char[m_length+1];
  }

public:

  static const size_t npos = -1;

  String(): m_length(0), m_str(NULL){}

  String(const char* cstr) {
    m_length = str_len(cstr);
    m_str = new char[m_length+1];
  
    for(size_t i = 0; i < m_length; ++i){
      m_str[i] = cstr[i];
    }
  }

  String(const String& other) {
    m_length = other.m_length;
    m_str = new char[other.m_length+1];
    
    for(int i = 0; i < m_length; ++i) {
      m_str[i] = other.m_str[i];
    }
  }

  ~String() {
    delete[] m_str;
  }

  String& operator=(const String& other){
    delete m_str;
    m_length = other.m_length;
    m_str = new char[size() + 1];
    for( int i = 0; i < size() + 1; ++i){
      m_str[i] = other.m_str[i];
    }
    return *this;
  }
  char operator[](size_t i) const {
    return m_str[i];
  }
  
  size_t size() const {
    return m_length;
  }

  bool empty() const{
    return m_length == 0;
  }

  bool operator==(const String& other) const{
    if(m_length != other.m_length) { return false; }
    for(int i = 0; i < other.m_length; ++i) {
      if(m_str[i] != other.m_str[i]) {
	return false;
      }
    }
    return true;   
  }

  bool operator!=(const String& other) const {
    return !(m_str == other.m_str);    
  }

  String operator+(const String& other) const {
    String sum(m_length + other.m_length);
    for(int i = 0; i < m_length; ++i) {
      sum.m_str[i] = m_str[i];
    }
    for(int i = m_length; i < sum.m_length; ++i) {
      sum.m_str[i] = other.m_str[i-m_length];
    }
    return sum;
}
  const char* c_str() const {
    m_str[m_length] = '\0';
    return m_str;
  }


  size_t find(char c, size_t pos = 0) const {
    for(size_t i = pos; i < m_length; ++i){
      if (m_str[i] == c)
	return i;
    }
    return -1;
    
  }

  String substr(size_t pos, size_t len = npos) const {
    String new_str(len);
    for(size_t i = pos; i < pos + len; ++i) {
      new_str.m_str[i-pos] = m_str[i];
      
    }  
    return new_str;

  }
  
  int str_len(const char* cstr) {
    int len = 0;
    char const *c = cstr;
    while(*c != '\0') {
      len++;
      c++;
    }

    return len;
  }


};


int main() {

  String a("Hello");
  String b(" World");
  String test;
  printf("a = \"%s\"\n", a.c_str());
  printf("b = \"%s\"\n", b.c_str());
  printf("a + b = \"%s\"\n", (a + b).c_str());
  printf("a+b size = %lu\n", (a+b).size());
  String c(" World");
  String d("Hello");
  String empty("");
  String empty2("");

  printf(a != b ? "a != b : TRUE\n" : "a != b : FALSE\n");
  printf("b.size() = %lu\n", b.size());  
  printf("a+b size = %lu\n", (a+b).size());
  printf(a == c ? "a == c : TRUE\n" : "a == c : FALSE\n");
  printf(a == d ? "a == d : TRUE\n" : "a == d : FALSE\n");
  printf(empty.empty() ? "empty is empty \n" : "empty is not empty\n");
  printf(b.empty() ? "b is empty \n" : "b is not empty\n");
  printf("a.size() = %lu\n", a.size());
  printf("b.size() = %lu\n", b.size());
  printf("a+b = \"%s\"\n", (a+b).c_str());
  
  printf("H in Hello is located at position: %lu\n", a.find('H', 0)); 
  printf("substring from 1:6 of Hello World: \"%s\"\n", ((a+b).substr(1, 6)).c_str());
}
