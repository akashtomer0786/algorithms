#include<bits/stdc++.h>
using namespace std;
///how to access private Data member
class Student
{
    private:    /// private data member
    int rollno;

    public:
    /// public function to get value of rollno - getter
    int getRollno(){
        return rollno;
    }
   /// // public function to set value for rollno - setter
    void setRollno(int i){
        rollno=i;
    }

    inline void DisplayRollno(){
        cout<<rollno<<endl;
    }
};

int main()
{
    Student A;
    A.rollono=1;  ///Compile time error
    cout<< A.rollno; ///Compile time error

    A.setRollno(1);  ///Rollno initialized to 1
    cout<< A.getRollno(); ///Output will be 1


}
