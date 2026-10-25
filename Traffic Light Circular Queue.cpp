// Online C++ compiler (editor)
// Write and run C++ online using this editor.

#include <iostream>
using namespace std;

const int MAX =5;
class TrafficQ{
    int F,B;
    int roads[MAX];
    public:
    TrafficQ(){
        F=-1;
        B=-1;
    }
    bool isEmpty(){
        return F==-1 && B==-1;
    }
    bool isFull(){
        return F==(B+1)%MAX;
    }
    bool enqueue(int roadID){
        if(isFull()){
            cout<<"OVERFLOW"<<endl;
            return false;
        }
        B=(B+1)%MAX;
        roads[B] = roadID;
        if(F==-1){
            F=0;
        }
        cout<<"Road "<<roads[B]<<" Enqueued"<<endl;
            return true;
    }
    int dequeue(){
        if(isEmpty()){
            cout<<"UNDERFLOW"<<endl;
            return -1;
        }
        int road = roads[F];
        if(F==B){
            F=-1;
            B=-1;
        }
        else {
            F=(F+1)%MAX; // Fixed: should advance F, not B
        }
        cout<<"Road "<<road<<" Dequeued"<<endl;
        return road; // Fixed: return the actual road number instead of 0
    }

    int Nextgreen(){
        if(isEmpty()){
            return -1;
        }
        int road = dequeue();
        enqueue(road);
        return road; // Fixed: return the road ID directly without adding +1
    }
    int peek(){
        if(isEmpty()){
            cout<<"UNDERFLOW"<<endl;
            return -1;
        }
        cout<<"Next Road: "<<roads[F]<<endl;
        return 0;
    }
    
    int count(){
        if(isEmpty()){
            return 0;
        }
        if(B>=F){
            return B-F+1; //Simple
        }
        else 
            return MAX - F+B+1; //wrapped around
    }
    void display(){
        if(isEmpty()){
            cout<<"The queue is empty"<<endl;
        }
        int n = count();
        for(int i = 0; i<n; i++){
            cout<<roads[(F+i)%MAX]<<endl;
        }
    }
    void Showmarkers(){
        cout<<"Front: "<<F<<" Back: "<<B<<endl;
    }
};
int main() {
    TrafficQ junction;
    int opt = 0;
    int roadId = 0;
    int result = 0;

    while (opt != 8)
    {
        cout << "\n1. Add a road to the cycle" << endl;
        cout << "2. Remove the front road (road closed)" << endl;
        cout << "3. Next green light" << endl;
        cout << "4. Which road is next?" << endl;
        cout << "5. Display the cycle" << endl;
        cout << "6. Count roads" << endl;
        cout << "7. Show front and rear markers" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter the option (1-8): ";
        cin >> opt;
    switch(opt){
        case 1:
        cout<<"Enter the road number: ";
        cin>>roadId;
        junction.enqueue(roadId);
        break;
        
        case 2:
        junction.dequeue();
        break;

        case 3:
        result = junction.Nextgreen();
        if(result ==-1){
            cout<<"UNDERFLOW"<<endl;
        }
        cout<<"Green for road: "<<result<<endl;
        break;

        case 4:
        junction.peek();
        break;

        case 5:
         junction.display();
                break;

        case 6:
        cout<<"Count: "<<junction.count()<<endl;
        break;

        case 7:
        junction.Showmarkers();
        break;

        case 8: 
        cout<<"GOODBYE!"<<endl;
        break;

        default:
        cout<<"INVALID OPTION"<<endl;
    }
        

    }
    return 0;
}
