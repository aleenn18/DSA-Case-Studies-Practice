#include <iostream>
using namespace std;
class Traystack{
    private:
        int top;
        int stk[5];
    public:
        Traystack(){
            top =-1;
        }
        bool isEmpty(){
            if(top ==-1){
                return true;
            }
            return false;
        }
    bool isFull(){
            if(top ==4){
                return true;
            }
            return false;
        }
    void push(int trayID){
        if(top ==4){
            cout<<"The Stack is FULL"<<endl;
            return;
        }
        top++;
        stk[top] = trayID;
        cout << "Tray " << trayID << " added" << endl;
    }
    void pop(){
        if(top ==-1){
            cout<<"The Stack is EMPTY"<<endl;
            return;
        }
        int val = stk[top];
        top--;
        cout << "Tray " << val << " taken" << endl;
    }
    void peek(){
        if(top ==-1){
            cout<<"The Stack is EMPTY"<<endl;
            return;
        }
        int val = stk[top];
        cout<<"The Tray on the top is "<<val<<endl;
    }
    void display(){
        if(top ==-1){
            cout<<"The Stack is EMPTY"<<endl;
            return;
        }
        for(int i = top; i>=0; i--){
            cout<<" \n"<<stk[i]<<endl;
        }
    }
    int count(){
        return top+1;
    }
};
int main() {
   Traystack Tray;
    int n, opt, loop=1;
    while(loop){
        cout<<"1. Add a Tray (push)"<<endl;
        cout<<"2. Take a Tray (pop)"<<endl;
        cout<<"3. Look at the top tray (peek)"<<endl;
        cout<<"4. Display All the trays"<<endl;
        cout<<"5. Count Trays "<<endl;
        cout<<"6. Exit"<<endl;
        cout<<"Enter your Option (1-6)";
        cin>>opt;
        switch(opt){
            case 1:
            cout<<"Enter The tray Id ";
            cin>>n;
            Tray.push(n);
            break;

            case 2:
            Tray.pop();
            break;

            case 3:
            Tray.peek();
            break;

            case 4:
            Tray.display();
            break;

            case 5:
            cout << "Trays: " << Tray.count() << endl;
            break;

            case 6:
            loop =0;
            break;

            default:
            cout<<"Invalid Option"<<endl;
            
        }
    }
    
}
