#=============================================
#=============================================
# A Functional-Paradigm List Implementation
# in Python 3
#
# Isaac Yep
#=============================================
#=============================================
"""
The following code implements the idea of a list
as would be experienced in a functional or logical
language such as Haskel or Prolog. Three List
classes inhert from the 'AbstractList' superclass
simply to avoid code duplication.

Framework:

                  AbstractList
                       |
                       |
      |----------------|----------------|
      |                |                |
  EmptyList         ConsList       InfiniteList


An interface is enforced automatically towards the
bottom of this document. When interpreted, this
script imports runs `doctest` (also towards the
bottom), to demonstrate and exercise the dynamic
dispatch of shared functionality.


Index:

-- AbstractList --
> __repr__(self)
> isEmpty(self)
> __str__(self)
> takeWhile(self, predicate)
> do(self, function)
> detect(self, predicate)
> map(self, transformer)
> filter(self, predicate)

-- EmptyList --
> length(self)
> isEmpty(self)
> head(self)
> tail(self)
> concat(self, other)
> __add__(self, other)
> strChain(self)
> commaElements(self)
> takeWhile(self, predicate)
> dropWhile(self, predicate)
> do(self, function)
> detect(self, predicate)

-- ConsList --
> __init__(self, self, head, tail)
> length(self)
> head(self)
> tail(self)
> next(self)
> concat(self, other)
> __add__(self, other)
> strChain(self)
> commaElements(self)
> dropWhile(self, predicate)

-- InfiniteList --
> __init__(self, initial, nextFun)
> head(self)
> next(self)
> tail(self)
> length(self)
> concat(self, other)
> __add__(self, other)
> commaElements(self, ctr)
> __str__(self)
> dropWhile(self, predicate)
"""

#***********************
#***********************
# AbstractList
#***********************
#***********************
class AbstractList:
  #~
  def __repr__(self):
    return self.__str__()
  #~
  def isEmpty(self):
    return False
  #~
  def __str__(self):
    """
    >>> str(EmptyList())
    '[]'
    """
    return '[' + self.commaElements() + ']'
  #~
  def takeWhile(self, predicate):
    """
    returns a list containing the elements of self as far as
    (but excluding) the first element for which predicate is
    false;  predicate is a function on the elements of self
    that returns a Boolean.

    >>> oneToFifty = nums(1, 51)
    >>> oneToTwenty = oneToFifty.takeWhile(lambda x: x <= 20)
    >>> oneToTwenty.length()
    20
    >>> oneToTwenty.head()
    1
    >>> oneToTwenty.tail().tail().head()
    3
    """
    return ConsList(self.head(), self.tail().takeWhile(predicate)) if predicate(self.head()) else EmptyList()
  #~
  def do(self, function):
    """
    Applies function to every element of this list
    Returns no result.

    >>> ConsList(1, ConsList(2, ConsList(3, EmptyList()))).do(lambda each: print(each))
    1
    2
    3
    """
    function(self.head())
    (self.tail()).do(function)
  #~
  def detect(self, predicate):
    """
    Returns the first element of this list for which
    predicate is true.  If there is no such element,
    raises the exception IndexError("No such object")

    >>> ConsList(1, ConsList(2, ConsList(3, EmptyList()))).detect(lambda each: each > 2)
    3
    >>> (nums(1, 25)).detect(lambda each: each > 20) 
    21
    """
    return self.head() if predicate(self.head()) else (self.tail()).detect(predicate)
  #~
  def __iter__(self):
    """
    >>> for i in ConsList(1, ConsList(2, ConsList(3, ConsList(4, EmptyList())))): print(i)
    1
    2
    3
    4
    >>> for i in (InfiniteList(0, lambda n: n + 1)).takeWhile(lambda m: m < 5): print(i)
    0
    1
    2
    3
    4
    """
    return ListIterator(self)
  #~
  def map(self, transformer):
    """
    Returns a new list, the same length as self, whose
    elements are obtained by applying the function transformer
    to the elements of self.
    
    >>> ConsList(1, ConsList(2, ConsList(3, EmptyList()))).map(lambda x: x * 2)
    [2, 4, 6]
    >>> EmptyList().map(lambda x: x * 2)
    []
    """
    if self.length() == 0:
      return EmptyList()
    res = EmptyList()
    for i in self:
      res = res.concat(ConsList(transformer(i), EmptyList()))
    return res
  #~
  def filter(self, predicate):
    """
    returns a new list, no longer than self, that contains just
    those elements of self for which the function predicate is true.
    
    >>> ConsList(1, ConsList(2, ConsList(3, EmptyList()))).filter(lambda x: x%2 == 0)
    [2]
    """
    if self.length() == 0:
      return EmptyList()
    res = EmptyList()
    for i in self:
      if predicate(i):
        res = res.concat(ConsList(i, EmptyList()))
    return res


#***********************
# Empty List
#***********************
class EmptyList(AbstractList):
  """ Represents an empty list. """
  #~
  def length(self):
    """
    >>> EmptyList().length()
    0
    """
    return 0
  #~
  def isEmpty(self):
    """
    >>> EmptyList().isEmpty()
    True
    """
    return True
  #~
  def head(self):
    raise ValueError("Can't take `head` of the empty list")
  #~
  def tail(self):
    raise ValueError("Can't take `tail` of the empty list")
  #~
  def concat(self, other):
    """ 
    >>> EmptyList().concat(ConsList(1, ConsList(2, ConsList (3, EmptyList()))))
    [1, 2, 3]
    """
    return other
  #~
  def __add__(self, other):
    """
    >>> EmptyList() + ConsList(1, ConsList(2, ConsList(3, EmptyList())))
    [1, 2, 3]
    >>> (EmptyList() + ConsList(8, ConsList(4, EmptyList()))).length()
    2
    """
    return other
  #~
  def strChain(self):
    """ Utility function for commaElements(). """
    return ''
  #~
  def commaElements(self):
    """ Utility function for __str__(). """
    return ''
  #~
  def takeWhile(self, predicate):
    """
    >>> EmptyList().takeWhile(lambda n: n < 3)
    []
    """
    return EmptyList()
  #~
  def dropWhile(self, predicate):
    """
    >>> EmptyList().dropWhile(lambda n: n < 3)
    []
    """
    return EmptyList()
  #~
  def do(self, function):
    return
  #~
  def detect(self, predicate):
    raise IndexError("No such object")


#***********************
# Cons List
#***********************
class ConsList(AbstractList):
  """ Represents a non-empty list. """
  #~
  def __init__(self, head, tail):
    self.__head = head
    self.__tail = tail
  #~
  def length(self):
    """
    >>> la = ConsList('a', EmptyList())
    >>> la.length()
    1
    >>> ConsList(1, ConsList(2, EmptyList())).length()
    2
    """
    return 1 + self.tail().length()
  #~
  def head(self):
    """
    >>> ConsList(1, ConsList(2, ConsList(3, EmptyList()))).head()
    1
    >>> (ConsList(90, ConsList(80, ConsList(70, EmptyList()))).tail()).head()
    80
    """
    return self.__head
  #~
  def tail(self):
    """
    >>> ConsList(1, ConsList(2, ConsList(3, EmptyList()))).tail()
    [2, 3]
    """
    return self.__tail
  #~
  def next(self):
    """
    >>> ConsList(90, ConsList(80, EmptyList())).next()
    80
    >>> (ConsList(90, ConsList(80, ConsList(70, EmptyList()))).tail()).next()
    70
    """
    return (self.tail()).head()
  #~
  def concat(self, other):
    """ 
    >>> ConsList(3, ConsList(2, EmptyList())).concat(ConsList(1, ConsList(2, ConsList (3, EmptyList()))))
    [3, 2, 1, 2, 3]
    """
    return ConsList(self.head(), (self.tail()).concat(other))
  #~
  def __add__(self, other):
    """
    >>> ConsList(3, ConsList(2, ConsList(1, EmptyList()))) + ConsList(2, ConsList(3, EmptyList()))
    [3, 2, 1, 2, 3]
    >>> (ConsList(16, EmptyList()) + ConsList(8, ConsList(4, EmptyList()))).length()
    3
    """
    return self.concat(other)
  #~
  def strChain(self):
    return ', ' + str(self.head()) + (self.tail()).strChain()
  #~
  def commaElements(self):
    return str(self.head()) + (self.tail()).strChain()
  #~
  def dropWhile(self, predicate):
    """
    returns a list like self except that all of the leading
    elements for which predicate is true have been removed.
    Thus, predicate will be false on the first element of the
    result; predicate is a function on the elements of self
    that returns a Boolean.
    >>> oneToFifty = nums(1, 51)
    >>> twentyOneOn = oneToFifty.dropWhile(lambda x: x <= 20)
    >>> twentyOneOn.length()
    30
    >>> twentyOneOn.head()
    21
    >>> twentyOneOn.tail().tail().head()
    23
    """
    return self.tail().dropWhile(predicate) if predicate(self.head()) else ConsList(self.head(), self.tail())


#***********************
# Infinite List
#***********************
class InfiniteList(AbstractList):
  '''
  Represents an infinite list, defined by an initial value, and a
  function that generates the next value.  So, for example, the Natural
  numbers would be represented by the initial value 0, and the function
  λn. n + 1.
  '''
  #~
  def __init__(self, initial, nextFun):
    self.__initial = initial
    self.__nextFun = nextFun
  #~
  def head(self):
    """
    >>> InfiniteList(0, lambda n: n + 1).head()
    0
    """
    return self.__initial
  #~
  def next(self):
    return self.__nextFun(self.__initial)
  #~
  def tail(self):
    """
    >>> InfiniteList(0, lambda n: n + 1).tail().head()
    1
    >>> InfiniteList(0, lambda n: n + 1).tail().tail().head()
    2
    >>> InfiniteList(0, lambda n: n + 1).tail().tail().tail().head()
    3
    """
    return InfiniteList(self.next(), self.__nextFun)
  #~
  def length(self):
    """
    >>> InfiniteList(0, lambda n: n + 1).length()
    inf
    """
    return float('inf')
  #~
  def concat(self, other):
    return self
  #~
  def __add__(self, other):
    return self
  #~
  def commaElements(self, ctr):
    return str(self.head()) + ", " + (self.tail()).commaElements(ctr+1) if (ctr < 7) else "..."
  #~
  def __str__(self):
    """
    >>> InfiniteList(0, lambda n: n + 1)
    [0, 1, 2, 3, 4, 5, 6, ...]
    """
    return '[' + self.commaElements(0) + ']'
  #~
  def dropWhile(self, predicate):
    """
    returns a list like self except that all of the leading
    elements for which predicate is true have been removed.
    Thus, predicate will be false on the first element of the
    result; predicate is a function on the elements of self
    that returns a Boolean.
    >>> oneToFifty = InfiniteList(1, lambda n: n + 1)
    >>> twentyOneOn = oneToFifty.dropWhile(lambda x: x <= 20)
    >>> twentyOneOn.head()
    21
    >>> twentyOneOn.tail().tail().head()
    23
    """
    return self.tail().dropWhile(predicate) if predicate(self.head()) else InfiniteList(self.head(), self.__nextFun)


#***********************
# Iterator Engine
#***********************
""" allows for python list iterators such as `for i in iterable` """
class ListIterator:
    def __init__(self, aList):
        self.remainderOfList = aList
    def __next__(self):
        if self.remainderOfList.isEmpty():
            raise StopIteration
        result = self.remainderOfList.head()
        self.remainderOfList = self.remainderOfList.tail()
        return result






#=============================================
#=============================================
#              Testing Engine
#=============================================
#=============================================

#***********************
# Interface Enforcement
#***********************
"""
>>> set(dir(EmptyList)).issuperset(listInterface)
True
"""
listInterface = {'head', 'tail', 'next', 'isEmpty', 'takeWhile',\
                 'dropWhile', 'length', 'do', 'detect', 'concat',\
                 '__add__', 'commaElements'}
def classImplements(c, ms):
    """
    c is a class, and ms is a set of method names.  
    Returns True if c implements all the methods in c.  
    Complains otherwise, and returns False
    """
    result = True
    for n in ms:
        m = getattr(c, n, False)
        if not (m and callable(m)):
            print(c, "does not have method", n)
            result = False
    return result


#***********************
# Generator Functions
#***********************
#~
def nums(lo, hi):
  """
  returns a list containing the numbers from lo up to but excluding hi

  >>> nums(0, 5)
  [0, 1, 2, 3, 4]
  >>> nums(3,2)
  []
  """
  return ConsList(lo, nums(lo+1, hi)) if lo < hi else EmptyList()
#~
def powers2Util(lim, m):
  return ConsList(2**(lim-m), powers2Util(lim, m-1)) if m > 1 else ConsList(2**(lim-m), EmptyList())
#~
def powers2(n):
  """
  Returns a list containing the first n powers of 2

  >>> powers2(6)
  [1, 2, 4, 8, 16, 32]
  """
  return powers2Util(n, n)


#***********************
# Run Doctest
#***********************
# Standard boilerplate to call the testmod() function.
if __name__ == '__main__':
  from doctest import testmod
  testmod(name='lists', verbose=False, raise_on_error=False)
