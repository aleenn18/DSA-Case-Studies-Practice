
#include <iostream>
using namespace std;

class problemQ {
    int F, R;
    int first[5];
    int second[5];
public:
    problemQ() {
        F = -1;
        R = -1;
    }
    bool isEmpty() {
        if (F == -1 || F > R) {
            return true;
        }
        return false;
    }
    bool isFull() {
        if (R == 4) {
            return true;
        }
        return false;
    }
    bool enqueue(int a, int b) {
        if (isFull()) {
            cout << "OVERFLOW" << endl;
            return false;
        }
        R++;
        first[R] = a;
        second[R] = b;
        if (F == -1) {
            F = 0;
        }
        return true;
    }
    bool dequeue() {
        if (isEmpty()) {
            cout << "UNDERFLOW" << endl;
            return false;
        }
        first[F] = 0;
        second[F] = 0;
        F++;
        return true;
    }
    int frontfirst() {
        if (isEmpty()) {
            cout << "UNDERFLOW" << endl;
            return -1;
        }
        return first[F];
    } 
    int frontsecond() {
        if (isEmpty()) {
            cout << "UNDERFLOW" << endl;
            return -1;
        }
        return second[F];
    }
    int count() {
        if (isEmpty()) {
            return 0;
        }
        return R - F + 1;
    }
};

bool askProblem(int a, int b) {
    int ans;
    cout << a << " + " << b << " = ";
    cin >> ans;
    return ans == (a + b);
}

int main() {
    int n, opt, loop = 1;
    while (loop) {
        cout << "\n1. Start Session" << endl;
        cout << "2. Exit" << endl;
        cout << "Enter option: ";
        cin >> opt;
        
        switch (opt) {
            case 1: {
                problemQ retryQ;
                int firsttryright = 0;
                int retryright = 0;
                int retrytotal = 0;
                int num1[5] = {5, 9, 7, 2, 5};
                int num2[5] = {9, 5, 9, 6, 5};

                for (int i = 0; i < 5; i++) {
                    int a = num1[i];
                    int b = num2[i];

                    if (askProblem(a, b)) {
                        cout << "CORRECT" << endl;
                        firsttryright++;
                    }
                    else {
                        cout << "WRONG TRY AGAIN LATER" << endl;
                        retryQ.enqueue(a, b);
                    }
                }
                
                retrytotal = retryQ.count();
                if (retryQ.isEmpty()) {
                    cout << "PERFECT SCORE!" << endl;
                }
                else {
                    cout << "RETRY ROUND: " << retrytotal << " Problems" << endl;
                }
                
                while (!retryQ.isEmpty()) {
                    int a = retryQ.frontfirst();
                    int b = retryQ.frontsecond();
                    retryQ.dequeue();

                    if (askProblem(a, b)) {
                        cout << "CORRECT" << endl;
                        retryright++;
                    } 
                    else {
                        cout << "WRONG! the answer is " << (a + b) << endl;
                    }
                }
                
                // Phase 3: Summary
                cout << "\n--- Summary ---" << endl;
                cout << "First try: " << firsttryright << "/5" << endl;
                cout << "Retry: " << retryright << "/" << retrytotal << endl;
                break;
            }
            case 2:
                cout << "EXITING THE PROGRAM" << endl;
                loop = 0;
                break;
            default:
                cout << "INVALID OPTION" << endl;
                break;
        }
    }
    return 0;
}
