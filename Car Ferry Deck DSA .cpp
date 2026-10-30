#include <iostream>
using namespace std;

class FerryDeck{
  private:
    int F,B;
    int cars[5];
    public:
    FerryDeck(){
        F=-1;
        B=-1;
    }
    bool isEmpty(){
        return F==-1 && B==-1;
    }
    bool isFull(){
        return F==0 && B==4;
    }
    void loadfront(int carNo){
        if(isFull()){
            cout<<"Full Capacity"<<endl;
            return;
        }
        if(isEmpty()){
            F=B=0;
            cars[F] = carNo;
        }
        else if (F>0){
            F--;
            cars[F] = carNo;
            
        }
        else {cout<<"No space from front side"<<endl;
             return; }
        cout<<"Car No "<<carNo<<" Loaded "<<endl;
    }
    void loadback(int carNo){
        if(isFull()){
            cout<<"Full Capacity"<<endl;
            return;
        }
        if(isEmpty()){
            F=B=0;
            cars[B] = carNo;
        }
         else if (B<4){
             B++;
             cars[B] = carNo;
            
        }
        else {cout<<"No space from back side"<<endl;
             return; }
        cout<<"Car No "<<carNo<<" Loaded "<<endl;
    }
    void unloadfront(){
        if(isEmpty()){
            cout<<"Empty Capacity"<<endl;
            return;
        }
            int car = cars[F]; //read
        
        if(F==B){
            F=B=-1;
        }
        
        else {
            F++;
             }
        cout<<"Car No "<<car<<" Unloaded "<<endl;
    }
    
    void unloadback(){
        if(isEmpty()){
            cout<<"Empty Capacity"<<endl;
            return;
        }
        int car = cars[B];
        if(F==B){
            F=B=-1;
        }
        else { B--; }
        cout<<"Car No "<<car<<" Unloaded "<<endl;
    }
    int peekfront(){
        if(isEmpty()){
            
            return -1;
        }
        return cars[F];
    }
    int peekback(){
        if(isEmpty()){
            
            return -1;
        }
        return cars[B];
    }
    int count(){
        if(isEmpty()){
            cout<<"Empty Capacity"<<endl;
            return 0;
        }
        return B-F+1;
    }
    void display(){
         if(isEmpty()){
            cout<<"Empty Capacity"<<endl;
            return;
        }
        for(int i=F;i<=B;i++){
            cout<<cars[i]<<endl;
        }
    }
    void showmarkers(){
        cout<<"Front: "<<F<<" Back: "<<B<<endl;
    }
};
int main() {
       FerryDeck Ferry;
    int n, opt, loop =1;
    while(loop){
        cout<<"1. Load a car from the front"<<endl;
        cout<<"2. Load a car from the back"<<endl;
        cout<<"3. Unload a car from the front"<<endl;
        cout<<"4. Unload a car from the back"<<endl;
        cout<<"5. Show the cars nearest each ramp"<<endl;
        cout<<"6. Show the deck"<<endl;
        cout<<"7. Show front and back markers"<<endl;
        cout<<"8. Exit"<<endl;
        cout<<"Enter the option: ";
        cin>>opt;
        switch(opt){
            case 1:
            cout<<"Enter Car no: ";
            cin>>n;
            Ferry.loadfront(n);
            break;

             case 2:
            cout<<"Enter Car no: ";
            cin>>n;
            Ferry.loadback(n);
            break;

            case 3:
            Ferry.unloadfront();
            break;

            case 4:
            Ferry.unloadback();
            break;

            case 5: {
                int front = Ferry.peekfront();
                if(front == -1) {
                    cout << "The deck is empty" << endl;
                } else {
                    cout << "Car at Front " << front << endl;
                    cout << "Car at Back " << Ferry.peekback() << endl;
                }
                break;
            }

            case 6:
            Ferry.display();
            break;

            case 7:
            Ferry.showmarkers();
            break;

            case 8:
              cout<<"Exiting System"<<endl;  
            loop =0;
            break;

            default:
            cout<<"INVALID OPTION"<<endl;
        }
    }
    return 0;
}
