#include<bits/stdc++.h>
using namespace std;
int main(){

    ///If an exception is thrown and not caught anywhere, the program terminates abnormally.
    ///For example, in the following program, a char is thrown, but there is no catch block to catch a char.

    try {
        int age = 15;
        if (age > 18) {
            cout << "Access granted - you are old enough.";
        } else {
            throw age;
        }
    }
    catch (int myNum) {
        cout << "Access denied - You must be at least 18 years old.\n";
        cout << "Age is: " << myNum;
    }


    ///some changes from here
    int x = -1;

   // Some code
    cout << "Before try \n";
    try {
      cout << "Inside try \n";
      if (x < 0)
      {
         throw x;
         cout << "After throw (Never executed) \n";
      }
    }
    catch (int x ) {
      cout << "Exception Caught \n";
    }

    cout << "After catch (Will be executed) \n";

    ///some changes from here
    ///we can see  below that integer is thrown but none of them is catching int so default will catch
    try  {
       throw 10;
    }
    catch (char *excp)  {

        ///excp may be a string here
        cout << "Caught " << excp;
    }
    catch (...)  {
        cout << "Default Exception\n";
    }
    return 0;
}
