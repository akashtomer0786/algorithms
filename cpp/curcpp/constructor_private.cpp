#include<bits/stdc++.h>
using namespace std;
///because of this private constructor i am able to control the number of instance of admin class
///singleton class
class Admin{
private:
    char adminName[20];
    char adminPassword[20];
    static int adminCount;

    Admin(){
        strcpy(adminName,"admin");
        strcpy(adminPassword,"admin");
    }
public:
    void showAdmin(){
        cout<<"Admin Name: "<<adminName;
        cout<<"Admin Password: "<<adminPassword;
    }

    static Admin* getInstance(){
        if(adminCount!=0)return NULL;
        Admin *admin = new Admin;
        adminCount++;
        return admin;
    }
};
int Admin::adminCount=0;
int main(){
    ///there are two type of members
    /// 1) Instance member
    /// 2) Static member



    Admin *admin = Admin::getInstance();
    admin->showAdmin();

}
