#include<iostream>
#include<unordered_map>
#include<string>
#include<stdlib.h>
using namespace std;
class Bill{
    public:
     unordered_map<string, double>payment;
    void calculate(int &n , string &payer , string &payee, double &amount){
        
        double splitAmount;
        splitAmount= amount/(n-1);
        payment[payer]-=amount;
        payment[payee]+=splitAmount;
    }
     void display(){
            cout<<" Everyone needs to pay the amount as following:"<<endl;
            for(auto f= payment.begin(); f!=payment.end() ; f++){
                string friendpp= f->first;
                double balance= f->second;
                if(balance>0){
                    cout<<friendpp<<" =  need to collect rupees: "<<balance<<endl;
                }
                else if(balance<0){
                    cout<<friendpp<<"  =  need to pay rupees: "<<-balance<<endl;
                }
                else{
                    cout<<friendpp<<" = no balance"<<endl;
                }
            }
     }
};
int main(){
    Bill b1;
    string payer;
    string payee;
    double amount;
    string friends;
    int n;
    int choose;
    do{
        cout<<"choose the scenario:"<<endl;
        cout<<"1.if the payer has to pay full amount of all friends."<<endl;
        cout<<"2. if the payer has to pay the amount of one friend from all friends."<<endl;
        cout<<"3. Exit"<<endl;
        cin>>choose;
        cin.ignore();
        switch(choose){
            case 1:
                cout<<"In this case all friends are payee and one is payer."<<endl;
                cout<<"Enter the number of all friends including payer: "<<endl;
                cin>>n;
                cin.ignore();
                cout<<"Enter the Total Amount"<<endl;
        cin>>amount;
                cout<<"Enter name of payer : "<<endl;
                cin>>payer;
                cin.ignore();
                for(int i =0 ; i<n-1 ; i++){
                    cout<<"Enter name of other friends: (payee)"<<endl;
                    cin>>friends;
                    cin.ignore();}
                    b1.calculate(n ,payer , friends, amount);
                
                b1.display();
                break;
            case 2:
                cout<<"In this case payer will pay the amount of one friend(payee)"<<endl;
                cout<<"Enter the number of all friends including payer and payee: "<<endl;
                cin>>n;
                cin.ignore();
                cout<<"Enter the Total Amount"<<endl;
        cin>>amount;
                cout<<"Enter name of payer : "<<endl;
                cin>>payer;
                cin.ignore();
                cout<<"Enter name of payee : "<<endl;
                cin>>payee;
                cin.ignore();
                for(int i =0 ; i<n-2 ; i++){
                    cout<<"Enter name of other friends : "<<endl;
                    cin>>friends;
                    cin.ignore();}
                    b1.calculate(n ,payer , friends, amount);
                
                b1.calculate(n ,payer , payee, amount);
                b1.display();
                break;
            case 3:
                cout<<" Exit "<<endl;
                break;
            default:
                cout << "Invalid entry,\n  Please Enter the number between 1-3 " << endl;
                break;
        }
    }
    while(choose!=3);
    return 0;
}
