
#include <iostream>
using namespace std;


class Stack
{
private:
    int top;
    int stk[5];

public:
    Stack(){
        top =-1;
    };                 // constructor: top = -1
    bool isEmpty(){
        return top== -1;
    };
    bool isFull(){
        return top ==4;
    };
    bool push(int page){
        if(isFull()){
            cout<<"History Full: Cannot Visit"<<endl;
            return false;
        }
        top++;
        stk[top] = page;
        return true;
        
        cout<<"Site "<<stk[top]<<" Opened "<<endl;
    };
    int pop(){
        if(isEmpty()){
            cout<<"Nothing Found in History"<<endl;
            return -1;
        }
        int val = stk[top];
        top--;
        cout<<"Site "<<val<<" removed "<<endl;
        return val;
    };
    int peek(){
        if(isEmpty()){
            cout<<"Nothing Found in History"<<endl;
            
        }
        int val = stk[top];
        return val;
    };
    int count(){
    return top + 1;
}
        

    void clear()
    {
        
        top = -1;
        
    }
};


int main() {
    
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top: " << s.peek() <<endl;
    cout<<"count: " << s.count() << endl;
    cout << "Popped: " << s.pop() << endl;
    s.clear();
    cout << "After clear, count: " << s.count() <<endl;
    cout<<"pop gives: " << s.pop() << endl;
    return 0;
}
  
