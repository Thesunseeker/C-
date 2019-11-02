#include <iostream>
#include <assert.h>
#include <string>
#include <vector>
using namespace std;

template<class T>
class Vector
{
  public:
    typedef T* iterator;
    //typedef const T* const_iterator;
   
    iterator end()
    {
      return _finish;
    }

    Vector()
    :_start(nullptr)
    ,_finish(nullptr)
    ,_endofStorage(nullptr)
    {}
    
    ~Vector()
    {
      if(_start)
      {
        cout << "~Vector()" <<endl;
        delete  []_start;
        _start = _finish = nullptr;
      }
    }
       
    Vector(const Vector<T>& v)
    {
      _start = new T[v.Capacity()];
      for(int i = 0 ; i < v.Size(); i++)
      {
        _start[i] = v[i];
      }
      _finish = _start + v.Size();
      _endofStorage = _start + v.Capacity();
    }
    void Swap(Vector<T>& v)
    {
      swap(_start , v._start);
      swap(_finish ,v._finish);
      swap(_endofStorage, v._endofStorage);
    }

    Vector<T>& operator=(Vector<T> v)
    {
      Swap(v);
      return *this;
    }

    size_t Capacity()
    {
      return _endofStorage - _start;
    }
 
    //增加size
    //T()调用默认构造函数，给value赋缺省值
    //因为容器Vector内可以存放任意类型的数据，当类型将T替换时，就会调用对应类型的构造函数
    //C++中内置类型也有对应的构造函数(int() char())
    void Resize(size_t  n , const T& val = T())
    {
      if(n <= Size())
      {
        _finish = _start + n;
      }
      if(n > Capacity())
      {
        Reserve(n);
      }
      while(_finish < _start + n)
      {
        *_finish++ = val;
      }
    }

    //增容
    void Reserve(size_t n)
    {
      size_t num = Size();
      if(n > Capacity())
      {
        T* tmp = new T[n];
        //需深拷贝
        if(_start)
        {
          for(int i = 0 ; i < Size() ; i++)
          {
            tmp[i] = _start[i];
          }
        }
        _start = tmp;
        _finish = _start + num;
        _endofStorage = _start + n;
      }
    }
    
    void PushBack(const T &v)
    {
     if(_finish == _endofStorage)
       {
       size_t newC = Capacity() == 0 ? 1 :Capacity() * 2;
       Reserve(newC);
       }
       
       *_finish = v;
       ++_finish;
       
      
      
     // Insert(end(),v);
    }

    void Insert(iterator pos , T& val)
    {
      size_t len = pos - _start;
      if(_finish == _endofStorage)
      {
        size_t newC = Capacity() == 0 ? 1: 2 * Capacity();
        Reserve(newC);
      }
      //若增容, 会使迭代器失效, 所以需更新迭代器
      pos = _start +len;
      iterator end = _finish - 1 ;
      while(end > pos)
      {
        *end = *(end - 1);
        --end;
      }
      *pos = val;
      ++_finish;
    }
  
    //删除操作也有可能产生迭代器失效问题
    //所以一边遍历一遍删除
    iterator Erase(iterator pos)
    {
      iterator begin = pos + 1;
      while(begin != _finish)
      {
        *(begin - 1) = *begin;
        ++begin;
      }
      --_finish;
      return pos;
    }
      
    size_t Size()
    {
      return _finish - _start;
    }

    void PopBack()
    {
      assert(Size() > 0);
      --_finish;
    }

    T& operator[](size_t pos)
    {
      assert(pos < Size());
      return _start[pos];
    }

    iterator begin()
    {
      return _start;
    }

  private:
    T* _start = nullptr;
    T* _finish = nullptr;
    T* _endofStorage = nullptr;
};

void test()
{
  Vector<int> v;
  v.PushBack(1);
  v.PushBack(1);
  v.PushBack(1);
  v.PushBack(1);
  v.PushBack(1);
 // v.Erase(v.end());
  v.PushBack(1);
  v.PushBack(1);
  for (const auto& e : v)
     {
       cout << e << endl;
     }
}

int main()
{
  test();
  return 0;  
}
