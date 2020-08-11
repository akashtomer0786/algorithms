
#include <iostream> 
/// macro definition 
#define LIMIT 5 
/// macro with parameter 
#define AREA(l, b) (l * b) 

///Note: There is no semi-colon(‘;’) at the end of macro definition. Macro definitions do not need a semi-colon to end.
int main() 
{ 
    int l1 = 10, l2 = 5, area; 
  
    area = AREA(l1, l2); 
  
    std::cout << "Area of rectangle is: " << area;
    
    for (int i = 0; i < LIMIT; i++) { 
        std::cout << i << "\n"; 
    }
  
    return 0; 
}
