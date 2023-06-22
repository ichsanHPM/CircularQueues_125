#include <iostream>
using namespace std;

class queues {
    int front, rear, max = 5;
    int queue_array[5];

public:
    queues() {
        front = -1;
        rear = -1;
    }

    void insert() {
        int num;
        cout << "enter a number: ";
        cin >> num;
        cout << endl;

        //cek apakah antrian penuh
        if ((front == 0 && rear == max - 1) || (front == rear + 1)) {
            cout << "\nqueue overvlow\n";
            return;
        }

        //cek apakah antrian kosong
        if (front == -1) {
            front = 0;
            rear = 0;
        }
        else {
            //jika rear berada diposisi akhir array,kembali ke awal array
            if (rear == max - 1)
                rear = 0;
            else
                rear = rear + 1;
        }
        queue_array[rear] = num;
        
    }
    void remove() {
        //cek apakah antrian kosong
        if (front == -1) {
            cout << "queue underflow\n";
            return;
        }
        cout << "\nthe element deleted from the queue is: " << queue_array[front] << "\n";

        //cek jika antrean hanya memiliki satu element
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            //jika element yang dihapus berada diposisi terakhir array, kembali ke awal array
            if (front == max - 1)
                front = 0;
            else
                front = front + 1;
        }
    }

    void display() {
        int front_position = front;
        int rear_position = rear;

        //cek apakah antrian kosong
        if (front == -1) {
            cout << "queue is empty\n";
            return;
        }

        cout << "\nelements in the queue are ...\n";

        //jika front_position <= rear position,iterasi dari front hingga rear
        if (front_position <= rear_position) {
            while (front_position <= rear_position) {
                cout << queue_array[front_position] << "  ";
                front_position++;
            } 
            cout << endl;
        }
        else {
            //jika front position > rear position ,iterasi dari front hingga akhir array
            while (front_position <= max - 1) {
                cout << queue_array[front_position] << "  ";
                front_position++;
            }

            front_position = 0;
            
            //iterasi dari awal array hingga rear
            while (front_position <= rear_position) {
                cout << queue_array[front_position] << "  ";
                front_position++;
            }
            cout << endl;
        }
       
    }
   
};

int main()
{
    queues q;
    char ch;

    while (true) {
        cout << "MENU" << endl;
        cout << "1. implement insert operation" << endl;
        cout << "2. implement delete operation" << endl;
        cout << "3. display values" << endl;
        cout << "4. exit" << endl;
        cout << "5. enter your choice (1-4) : " << endl;
        cin >> ch;
        cout << endl;

        switch(ch) {
            case '1': {
                q.insert();
                break;
            }
            case '2': {
                q.remove();
                break;
            }
            case '3': {
                q.display();
                break;
            }
            case '1': {
                q.insert();
                break;
            }

        }
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
