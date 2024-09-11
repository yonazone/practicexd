#include <iostream>
#include <string>

class String
{
  char* m_Buffer;
  unsigned int m_Size;

public:
  String(const char* string)
  {
    m_Size = strlen(string);
    m_Buffer = new char[m_Size + 1];
    memcpy(m_Buffer, string, m_Size);
    m_Buffer[m_Size] = 0;
  }
  // Copy constructor
  String(const String& other); // supplied by  C++ automatically

  // How it is implemented
  String(const String& other)
    : m_Buffer(other.m_Buffer), m_Size(other.m_Size)
  {
    
  }

  // Another version of how it can be implemented
  String(const String& other)
  {
    memcpy(this, &other, sizeof(String));
  }
  
  // If we dont want this copy constructor then we can delete like this
  String(const String& other) = delete;

  ~String()
  {
    delete[] m_Buffer;
  }

  friend std::ostream& operator<<(std::ostream& stream, const String& string)
};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
  stream << string.m_Buffer;
  return stream;
}

int main()
{
  String string = "Cherno";
  String second = string;
}
