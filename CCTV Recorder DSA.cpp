#include <iostream>
using namespace std;

const int MAX =5;
class Clip{
    private:
    int F,B;
    int clips[MAX];
    public:
    Clip(){
        F=-1;
        B=-1;
    }
    bool isEmpty(){
        return F==-1 &&B==-1;
    }
    bool isFull(){
        return F==(B+1)%MAX;
    }
    bool enqueue(int clipNo){
        if(isFull()){
            cout<<"OVERFLOW"<<endl;
            return false;
        }
        B =(B+1)%MAX;
        clips[B] = clipNo;
        if(F==-1){
            F=0;
        }
        cout<<"Clip "<<clips[B]<<" Enqueued"<<endl;
        return true;
    }
    int dequeue(){
        if(isEmpty()){
            cout<<"UNDERFLOW"<<endl;
            return -1;
        }
        int clip = clips[F];
        if(F==B){
            F=-1;
            B=-1;
        }
        else
            F=(F+1)%MAX;

         cout<<"Clip "<<clip<< " Dequeued "<<endl;
    return clip;
    }
    int oldest(){
        if(isEmpty()){
            cout<<"UNDERFLOW"<<endl;
            return -1;
        }
        return clips[F];
    }
    int newest(){
        if(isEmpty()){
            cout<<"UNDERFLOW"<<endl;
            return -1;
        }
        return clips[B];
    }
    int recordloop(int clipNo){
    	int lost =-1;
        if(isFull()){
            lost = dequeue();
        }
        
        enqueue(clipNo);
        return lost;
    }
    int count(){
        if(isEmpty()){
            
            return -1;
        }
        if(B>=F){
            return B-F+1;
        }
        else
            return MAX-F+B+1;
    }
    void display(){
        if(isEmpty()){
            cout<<"Memory is Empty"<<endl;
            return;
            
        }
        int n = count();
        for(int i =0; i<n; i++){
            cout<<clips[(F+i)%MAX]<<endl;
        }
    }
    void showmarkers(){
        cout<<"Front: "<<F<<" Back: "<<B<<endl;
    }
};


int main() {
   Clip c;
    int n, opt, loop =1;
    while(loop){
        cout<<"1. Record a new clip (loop recording)"<<endl;
        cout<<"2. Watch the oldest clip"<<endl;
        cout<<"3. Check the newest clip"<<endl;
        cout<<"4. Delete the oldest clip"<<endl;
        cout<<"5. Show stored clips"<<endl;
        cout<<"6. Show front and rear markers"<<endl;
        cout<<"7. Exit"<<endl;
        cout<<"Enter Your Option: ";
        cin>>opt;

        switch(opt){
            case 1:
            cout<<"Enter Clip No: ";
            cin>>n;
            c.recordloop(n);
            break;

            case 2: {
                int oldestClip = c.oldest();
                if (oldestClip == -1) {
                    cout << "No clips stored" << endl;
                } else { 
                    cout << "Oldest Clip Playing: " << oldestClip << endl;
                }
                break;
            }

            case 3: {
                int newestClip = c.newest();
                if (newestClip == -1) {
                    cout << "No clips stored" << endl;
                } else {
                    cout << "Newest Clip Recorded: " << newestClip << endl;
                }
                break;
            }
            case 4:
            c.dequeue();
            break;

            case 5:
            c.display();
            break;

            case 6:
            c.showmarkers();
            break;
               

                case 7:
                loop =0;
                break;

            default:
                cout<<"INVALID OPTION"<<endl;

                
            
        }
    }
    return 0;
}

