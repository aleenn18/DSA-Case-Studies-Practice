#include <iostream>
using namespace std;

class Tower {
private:
    int F1, F2, F3;
    int B1, B2, B3;
    int PQ[3][5];

public:
    Tower() {
        F1 = -1; B1 = -1;
        F2 = -1; B2 = -1;
        F3 = -1; B3 = -1;
    }

    bool isEmpty(int p) {
        if (p == 1) {
            return F1 == -1;
        } else if (p == 2) {
            return F2 == -1;
        } else if (p == 3) {
            return F3 == -1;
        }
        return true;            
    }

    bool isFull(int p) {
        if (p == 1) {
            return B1 == 4;
        } else if (p == 2) {
            return B2 == 4;
        } else if (p == 3) {
            return B3 == 4;
        }
        return false;
    }

    // 1. Moved 'add' OUTSIDE of 'insert' so it's a proper member function
    void add(int x, int &B, int &F, int i) {
        if (isFull(i + 1)) {
            cout << "The queue is Full" << endl;
            return;
        } else {
            B++;
            PQ[i][B] = x;
            if (F == -1) {
                F = 0;
            }
            cout << "Enqueued flight no " << x << endl;
        }
    }

    void insert(int fn, int p) {
        switch(p) {
            case 1:
                add(fn, B1, F1, 0);
                break;
            case 2:
                // 2. Fixed row/marker mapping for priority 2 and 3
                add(fn, B2, F2, 1); 
                break;
            case 3:
                add(fn, B3, F3, 2); 
                break;
            default:
                cout << "INVALID" << endl;
        }
    }

    // 3. Moved 'remove' OUTSIDE of 'delete' so it's a proper member function
    void remove(int &B, int &F, int i) {
        if (isEmpty(i + 1)) {
            cout << "The queue is Empty" << endl;
            return;
        }
        
        // 4. Fixed PQ lookup to print the actual item being removed instead of undefined 'x'
        int removedItem = PQ[i][F];
        cout << "Removed flight no " << removedItem << endl;
        
        if (F == B) {
            F = -1;
            B = -1;
        } else {
            F++;
        }
    }

    // Renamed from 'delete' to 'del' because 'delete' is a reserved keyword in C++
    void del(int p) {
        switch(p) {
            case 1:
                remove(B1, F1, 0);
                break;
            case 2:
                remove(B2, F2, 1);
                break;
            case 3:
                remove(B3, F3, 2);
                break;
            default:
                cout << "INVALID" << endl;
        }
    }
    int nextPriority(){
        if(!isEmpty(1)) return 1;
        if(!isEmpty(2)) return 2;
        if(!isEmpty(3)) return 3;
        return 0; //All empty
    }
    int nextToLand(){
        int p = nextPriority();
        if(p==0) return -1;

        int flightnum = peek();
         del(p);                     // and remove it
    return flightnum;
}
    int peek(){
        int p = nextPriority();
        if(p==0) return -1;
        if(p==1) return PQ[0][F1];
        if(p==2) return PQ[1][F2];
        return PQ[2][F3];
    }
    int count(int p){
        int F=-1, B=-1;
        if(p ==1) {
            F=F1;
            B=B1;
        }
        if(p==2){
            F=F2;
            B=B2;
        }
        if(p==3){
            F=F3;
            B=B3;
        }
        if(F==-1){
            return 0;
        }
        return B-F+1;
    }
    int totalwaiting(){
        return count(1)+ count(2) + count(3);
    }
// Finished display function
    void display() {
        for (int p = 1; p <= 3; p++) {
            cout << "Queue " << p << ":" << endl;
            if (isEmpty(p)) {
                cout << "Queue is Empty" << endl;
            } else {
                int F = (p == 1) ? F1 : (p == 2) ? F2 : F3;
                int B = (p == 1) ? B1 : (p == 2) ? B2 : B3;
                for (int i = F; i <= B; i++) {
                    cout << PQ[p - 1][i] << " ";
                }
                cout << endl;
            }
        }
    }
        void showMarkers() {
        cout << "Queue 1 -> F: " << F1 << ", B: " << B1 << endl;
        cout << "Queue 2 -> F: " << F2 << ", B: " << B2 << endl;
        cout << "Queue 3 -> F: " << F3 << ", B: " << B3 << endl;
    }
};

int main() {
    
    Tower t;
    int opt = 0;
    int flightNo, priority;

    while (opt != 8) {
        cout << "\n--- AIR TRAFFIC CONTROL MENU ---" << endl;
        cout << "1. A flight requests to land" << endl;
        cout << "2. Clear the next flight to land" << endl;
        cout << "3. Who lands next?" << endl;
        cout << "4. A waiting flight declares an emergency (Skipped)" << endl;
        cout << "5. Display all waiting flights" << endl;
        cout << "6. Count waiting flights" << endl;
        cout << "7. Show front and back markers" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your option (1-8): ";
        cin >> opt;

        switch (opt) {
            case 1:
                cout << "Enter flight number: ";
                cin >> flightNo;
                cout << "Enter priority (1: High, 2: Medium, 3: Low): ";
                cin >> priority;
                t.insert(flightNo, priority);
                break;

            case 2: {
                int nextP = t.nextPriority();
                if (nextP == 0) {
                    cout << "No flights waiting to land." << endl;
                } else {
                    t.del(nextP);
                }
                break;
            }

            case 3: {
    int nextFlight = t.peek();
    if (nextFlight == -1) {
        cout << "No flights currently waiting." << endl;
    } else {
        cout << "The next flight to land is: " << nextFlight
             << " (priority " << t.nextPriority() << ")" << endl;
    }
    break;
}
            break;

            case 4:
                cout << "Emergency feature is excluded for now." << endl;
                break;

            case 5:
                t.display();
                break;

            case 6:
                cout << "Total waiting flights across all queues: " << t.totalwaiting() << endl;
                cout << "  - Priority 1: " << t.count(1) << endl;
                cout << "  - Priority 2: " << t.count(2) << endl;
                cout << "  - Priority 3: " << t.count(3) << endl;
                break;

            case 7:
                t.showMarkers();
                break;

            case 8:
                cout << "Exiting Air Traffic Control System. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid option! Please choose between 1 and 8." << endl;
        }
    }

    return 0;

}
