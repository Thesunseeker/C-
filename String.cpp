/** 
 *简单实现一个String类,以及各个接口函数 
 */
#include <string>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <assert.h>
using namespace std;

template<class T>
class String
{
  private:
    T& m_size;
    T& m_capacity;
    T& m_data;
  
  public:
    String(const char* str = "")
    :m_capacity(16)
    {
      if(nullptr == str)
      {
        m_size = 0;
      }
      m_size = strlen(str);
      m_data = new char[m_capacity + 1];
      reserve(m_size);
      strncpy(m_data , str, m_size);//防止输入为null报错
    }

    String(const String &s)
    {
      m_size = s.m_size;
      m_capacity = s.m_capacity;
    //深拷贝
      m_data = new char[m_capacity];
      strcpy(m_data , s.m_data);
    }
    
    ~String()
    {
      if(m_data)
      {
        delete  []m_data;
        m_data = NULL;
      }
      m_size = m_capacity = 0;
    }

   /* String& operator=(String& s)
    {
      if(this != &s)
      {
        if(m_data)
        {
          delete [] m_data;
          m_data = new char[strlen(s.m_data) + 1];
          strcpy(m_data , s.m_data);
        }
        return *this;
      }
    }
    老的重载赋值写法
    */
    //现代重载赋值写法
    T& operator=(String s)
    {
      swap(m_data , s.m_data);
      return *this;
    }

    T& reserve(size_t size)
    {
      if(size >= m_capacity)
      {
        m_capacity = (size / 16 + 1) * 16;
        m_data = (char*)realloc(m_data , m_capacity);        
      }
    }
   
    T& resize(size_t size , char ch = '\0')
    {
      reserve(size);

      if(m_size < size)
      {
        memset(m_size + size , ch , size - m_size);
      }
      m_size = size;
    }

    T& Insert(size_t pos , const char* str)
    {
      int len = strlen(m_data);
      assert(pos < m_size);
      if(m_size + len > m_capacity)
      {
        reserve(m_data + len);
      }
      size_t end = m_size + len;
      while(end > pos + len -1)
      {
        m_data[end + len] = m_data[end - len];
        --end;
      }
      while(*str)
      {
        m_data[pos++] = *str;
        ++str;
      }
      m_size += len;
    }
  
    T& PushBack(T& c)
    {
      if(m_data == m_capacity)
      {
        //增容
        size_t newC = m_capacity == 0 ? 15 : 2 * m_capacity;
        reserve(newC);
      }
      m_data[m_size] = c;
      m_data[m_size] = '\0';
    }
    
    void Erase(size_t pos , size_t n)
    {
      assert(pos < m_size);
      if(n > m_size - pos)
      {
        m_size = pos;
        m_data[m_size] = '\0';
      }
      size_t begin = pos + n;
      while(begin <= m_size)
      {
        m_data[pos++] = m_data[begin];
        ++begin;
      }
      m_size -= n;
    }
   
    size_t Find(size_t pos , char c)
    {
      if(pos < 0 || pos >= m_size)
      {
        return -1;
      }
      char* tmp = strchr(m_data + pos , c);
      if(tmp)
      {
        return tmp - m_data;
      }
      return -1;
    }

    size_t Find(size_t pos ,const char* c)
    {
      if(pos < 0 || pos >= m_size)
      {
        return -1;
      }
      char* tmp = strshr(m_data + pos , c);
      if(tmp)
      {
        return tmp - m_data;
      }
      return -1;
    }
  
    size_t Find(size_t pos ,const String &c)
    {
      if(pos < 0 || pos >= m_size)
      {
        return -1;
      }
      char* tmp = strshr(m_data + pos , c.m_data);
      if(tmp)
      {
        return tmp - m_data;
      }
      return -1;
    }
   
    String Substr(size_t pos , size_t n)
    {
      String tmp;
      tmp.resize(n);

      strncpy(tmp.m_data , m_data + pos , n);
      return tmp;
    }

    void Append(const char* str)
    {
      Insert(m_size , str);
    }

    char& operator[](size_t pos)
    {
      assert(pos < m_size);
      return m_data[pos];
      return* this;
    }

    String& operator+=(char str)
    {
      PushBack(str);
      return* this;
    }

    size_t size()
    {
      return m_size;
    }

    size_t capacity()
    {
      return m_capacity - 1;
    }

    size_t empty()
    {
      return m_size == 0;
    }
  
    typedef char* iterator;
    iterator begin()
    {
      return m_data;
    }
    
    iterator end()
    {
      return m_size + m_data;
    }
  };

int main()
{
  return 0;
}
