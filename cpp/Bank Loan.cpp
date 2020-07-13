#include<bits/stdc++.h>
using namespace std;
class LoanException{
public:
     int errNo;
     string errMsg;
     LoanException(int n,string msg ){
     errNo=n;
     errMsg=msg;
     }
     void showError(){
     cout<<errNo<<":"<<errMsg<<endl;
     }
};

class Loan{
public:
    int LoanId;
    float LoanAmt;
    float LoanIntRate;
    float emi;
    int RetPeriod;
    Loan(){
    }
    Loan(int LoanId,float LoanAmt,float LoanIntRate,int RetPeriod){
        this->LoanId=LoanId;
        this->LoanAmt=LoanAmt;
        this->LoanIntRate=LoanIntRate;
        this->emi=0;
        this->RetPeriod=RetPeriod;
    }
    ///to perform polymorphism
    ///only this function will be accessible when derived class pointer is kept in variable of derived class pointer
    virtual void printLoan()=0;
    virtual void computeEmi()=0;
};
class TwoWheelerLoan:public Loan{
public:
    float totalLoanAmt;
    TwoWheelerLoan():Loan(){
    }
    TwoWheelerLoan(int loanId,float LoanAmt,float LoanIntRate,int RetPeriod):Loan(LoanId,LoanAmt,LoanIntRate,RetPeriod){
        this->emi=0;
    }
    void computeEmi(){

    this->emi=(LoanAmt+LoanAmt*(float)(LoanIntRate/100))/RetPeriod;
    totalLoanAmt=(LoanAmt+LoanAmt*(float)(LoanIntRate/100));

    }
    void printLoan(){
    cout<<LoanId<<":"<<LoanAmt<<":"<<LoanIntRate<<":"<<RetPeriod<<
    ":"<<this->emi<<endl;
    }

};
class FourWheelerLoan:public Loan{
public:
    FourWheelerLoan():Loan(){

    }
    FourWheelerLoan(int loanId, float loanAmt, float intRate, int rPeriod):Loan(loanId,loanAmt,intRate,rPeriod){
    this->emi=0;
    }
    void computeEmi(){
            this->emi=(LoanAmt+LoanAmt*((float)(LoanIntRate)/100))/RetPeriod;

    }
    void printLoan(){

    cout<<LoanId<<":"<<LoanAmt<<":"<<LoanIntRate<<":"<<RetPeriod<<":"<<emi<<endl;

    }
};
class Customer{
public:
    int CustId;
    string CustName;
    ///Important
    Loan* loans[2];
    float TotalAmt1;
    float TotalAmt2;
    Customer(){
        CustId=0;
        CustName="";
    }
    Customer(int id,string n){
        CustId=id;
        CustName=n;
    }
    void availLoan(){

    loans[0]= new TwoWheelerLoan(1,10000.0f,10,12);
    loans[1]=new FourWheelerLoan(2,10000.0f,7,12);
    TotalAmt1=(loans[0]->LoanAmt+
              loans[0]->LoanAmt*(float)(loans[0]->LoanIntRate/100));
    TotalAmt2=(loans[1]->LoanAmt+
              loans[1]->LoanAmt*(float)(loans[1]->LoanIntRate/100));
    }
    void printTotalLoanAmt(){
        cout<<"Loan 1:"<<TotalAmt1<<"Loan 2:"<<TotalAmt2<<endl;
    }
    ///virtual funtion
    void viewLoanStatus(){
        loans[0]->printLoan();
        loans[1]->printLoan();
    }
    void rePay(){
    //cout<<totalAmt1<<":"<<totalAmt2<<endl;
    int loanNo;
    cout<<"Enter loan number to repay"<<endl;
    cin>>loanNo;
    if(loanNo<0)throw LoanException(1,"invalid loan number");
    if(loanNo==1){
    for(int i=0;i<12;i++){
    TotalAmt1-=loans[0]->emi;
    if(TotalAmt1<0){
            TotalAmt1=0;
            loans[0]->LoanAmt=0;
        cout<<"Repayment completed"<<endl;}
        else{cout<<TotalAmt1<<endl;}
    }
    }
    else
    {
    for(int j=0;j<12;j++){
    TotalAmt2 -= loans[1]->emi;
    if(TotalAmt2<0){
            TotalAmt2=0;
            loans[1]->LoanAmt=0;
        cout<<"Repayment completed"<<endl;}
        else{cout<<TotalAmt2<<endl;}

    }
    }
    cout<<TotalAmt1<<":"<<TotalAmt2<<endl;
   }
};


int main()
{
    Customer c(1001,"aaaa");
    try{
        c.availLoan();
        c.printTotalLoanAmt();

        c.loans[0]->computeEmi();
        c.loans[1]->computeEmi();

        c.viewLoanStatus();
        c.rePay();
        c.viewLoanStatus();
    }catch(LoanException e){
        e.showError();
    }
    cout<<"End"<<endl;
    return 0;
}

