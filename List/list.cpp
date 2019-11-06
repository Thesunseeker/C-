#include <iostream>
#include <vector>
using namespace std;

template<class T>
struct ListNode
{
  ListNode<T>* _prev;
  ListNode<T>* _next;
  T _data;

  ListNode(const T& val = T())
  :_prev(nullptr)
   ,_next(nullptr)
   ,_data(val)
  {}
};

template<class T, class Ptr , class Ref>
struct _ListIterator
{
  typedef ListNode<T> Node;
  typedef _ListIterator<T,Ptr,Ref> Self;
  _ListIterator(Node* node)
  :_node(node)
  {}

  Node* _node;

  Ref operator*()
  {
    return _node->_data;
  }

  Ptr operator->()
  {
    return _node->_data;
  }

  //++iterator
  Self& operator++()
  {
    _node = _node->_next;
    return *this;
  }

  //iterator+=
  Self operator++(int)
  {
    Self tmp(*this);
    _node = _node->_next;
    return tmp;
  }

  Self operator--()
  {
    _node = _node->_prev;
    return *this;
  }

  Self operator--(int)
  {
    Self tmp(*this);
    _node = _node->_prev;
    return tmp;
  }

  bool operator!=(Self &it)
  {
    return _node != it._node;
  }
};

template<class T>
class List 
{
  typedef ListNode<T> Node;
  private:
    Node* _head;
  public:
    typedef _ListIterator<T, T*, T&> iterator;
    typedef _ListIterator<T ,const T* ,const T&> const_iterator;

  iterator begin()
  {
    return iterator(_head->_next);
  }

  iterator end()
  {
    return iterator(_head);
  }

  const_iterator begin() const 
  {
    return const_iterator(_head->_next);
  }

  const_iterator end() const 
  {
    return const_iterator(_head);
  }
  
  List()
    :_head(new Node)
  {
   _head->_next = _head;
   _head->_prev = _head;
  }

  ~List()
  {
    if(_head)
    {
      Clear();
      delete _head;
      _head = nullptr;
    }
  }

  List(const List<T>& lst)
  {
    _head = new Node;
    _head->_prev = _head;
    _head->_next = _head;
    for(const auto &e : lst)
    {
      PushBack(e);
    }
  }

  List<T>& operator=(List<T> lst)
  {
    swap(_head , lst._head);
    return *this; 
  }

  void Clear()
  {
    if(_head)
    {
      Node* cur = _head->_next;
      while(cur != _head)
      {
        Node* next = cur->_next;
        delete cur;
        cur = next;
      }
      _head->_next = _head;
      _head->_prev = _head;
    }
  }

  void PushBack(const T& val)
  {
    /*Node* tail = _head->_prev;
    Node* node = new Node(val);
    tail->_next = node;
    tail->_prev = _head;
    _head->_prev = node;*/
    Node *node = new Node(val);

    node->_next = _head;
    node->_prev = _head->_prev;

    _head->_prev = node;
    node->_prev->_next = node;
  }

  void PopBack()
  {
    Node* cur = _head->_prev;
    if(cur != _head)
    {
      _head->_prev = cur->_prev;
      cur->_prev->_next = _head;
      delete cur;
    }
  }

  void Insert(iterator pos, const T &val)
  {
    Node* node = new Node(val);
    Node* cur = pos._node;
    Node* prev = cur->_prev;

    node->_next = cur;
    cur->_prev = node;

    prev->_next = node;
    node->_prev = prev;
  }

  iterator Erase(iterator pos)
  {
    if(pos != end())
    {
      Node* cur = pos._node;
      Node* prev = cur->_prev;
      Node* next = cur->_next;

      prev->_next = next;
      next->_prev = prev;

      delete cur;
      cur = nullptr;
      pos = iterator(next);
    }
    return pos;
  }

  void PushFront(const T& val)
  {
    Insert(begin() , val);
  }

  void PopFront()
  {
    Erase(begin());
  }


};

int main()
{
  List<int> lst;
  lst.Insert(lst.begin(), 0);
  lst.Insert(lst.begin(), 1);
  lst.Insert(lst.begin(), 2);
  lst.Insert(lst.begin(), 3);
  auto lit = lst.begin();
  cout << *lit << endl;

}
