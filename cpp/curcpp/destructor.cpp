A destructor takes no arguments and has no return type. 
Its address cannot be taken. Destructors cannot be declared const, volatile, const volatile or static. 
A destructor can be declared virtual or pure virtual.
  
  
  The keyword static means that the variable is independent of instances. That's why you can access static variables 
  and methods without instantiating an object from the class in the first place. That's why destroying an instance will not affect any static variables.
