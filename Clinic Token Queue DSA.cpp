#include <iostream>
using namespace std;
class clinicQueue{
  private: 
    int F,R;
    int token[5];
    public:
    clinicQueue(){
        F=-1;
        R=-1;
    }
    bool isEmpty(){
        if(F==-1 || F>R){
            return true;
        }
        return false;
    }
    bool isFull(){
            if(R==4){
                return true;
            }
        return false;
    }
    void enqueue(int tokenNo){
        if(isFull()){
            cout<<"OVERFLOW"<<endl;
            return;
        }
        R++;
        token[R] = tokenNo;
        if(F==-1){ //first element
            F=0;
        }
        cout<<"Token "<<token[R]<<" Added in the Queue"<<endl;
    }
    void dequeue(){
        if(isEmpty()){
            cout<<"UNDERFLOW"<<endl;
            return;
        }
        cout<<"Token "<<token[F]<<" Checked out from the queue"<<endl;
        token[F] = 0;
        F++;
    }
    void peek(){
        if (isEmpty()){
        cout << "The Queue is Empty" << endl;
        return;
    }
        cout<<"Next Patient: "<<token[F]<<endl;
        
    }
    void display(){
        if(isEmpty()){
            cout<<"The queue is Empty"<<endl;
            return;
        }
        else
            for(int i =F; i<=R; i++){
               cout<<token[i]<<endl; 
            }
    }
    int count(){
        if(isEmpty()){
            return 0;
        }
        return R-F+1;
    }
    int showmarkers(){
        cout<<"Front: "<<F<<"  REAR: "<<R<<endl;
        return 0;
    }
    
};
int main(){
    clinicQueue obj;
    int n, opt, loop =1;
    while(loop){
        cout<<"1. New patient (enqueue)"<<endl;
        cout<<"2. Call next patient (dequeue)"<<endl;
        cout<<"3. Who is next? (peek)"<<endl;
        cout<<"4. Display waiting patients"<<endl;
        cout<<"5. Count waiting patients"<<endl;
        cout<<"6. Show front and rear markers"<<endl;
        cout<<"7. Exit"<<endl;
        cout<<"Enter Your Choice(1-7): ";
        cin>>opt;
        switch(opt){
            case 1:
                cout<<"Enter the Token no. ";
                cin>>n;
                obj.enqueue(n);
            break;
            case 2:
                 obj.dequeue();
                break;
            case 3:
                obj.peek();
                break;
            case 4:
                obj.display();
            break;
            case 5:
                cout<<"Total Count: "<<obj.count()<<endl;
            break;
            case 6:
                obj.showmarkers();
            break;
            case 7: 
                loop =0;
            break;
            
            default:
                cout<<"INVALID INPUT"<<endl;
                
        }
    }

}
