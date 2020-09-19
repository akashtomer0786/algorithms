In C++, the constructor cannot be virtual, because when a constructor of a class is executed there is no virtual table in the memory, 
means no virtual pointer defined yet. So, the constructor should always be non-virtual.
  
cpp doesn't have static constructor
