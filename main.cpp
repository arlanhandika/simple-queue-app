#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* next;
};

Node* head = nullptr;
int count = 0;

bool penuh() {
    if (count >= 5) {
        return true;
    } else {
        return false;
    }
}

bool kosong() {
    if (head == nullptr) {
        return true;
    } else {
        return false;
    }
}

void view() {
    if (!kosong()) {
        cout << "Data antrian: " << endl;
        Node* current = head;
        int index = 1;
        while (current != nullptr) {
            cout << index << ". " << current->data << endl;
            current = current->next;
            index++;
        }
    } else {
        cout << "Antrian kosong" << endl;
    }
    if (penuh()) {
        cout << "Antrian sudah penuh" << endl;
    }
    cout << endl;
}

void enqueue() {
    if (!penuh()) {
        string nama;
        cout << "Masukkan Nama: ";
        cin >> nama;

        Node* newNode = new Node();
        newNode->data = nama;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }

        count++;
    }
}

void dequeue() {
    if (!kosong()) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count--;
    }
}

int main() {
    int pil;

    queue:
        system("cls");
        cout << "===ANTRIAN RUMAH SAKIT AYO SEHAT===\n" << endl;
        view();
        cout << "MENU UTAMA";
        cout << "\n1. Tambahkan antrian";
        cout << "\n2. Hapus antrian";
        cout << "\n3. Keluar";
        cout << "\nMasukkan pilihan: ";
        cin >> pil;

    switch(pil) {
        case 1:
            system("cls");
            enqueue();
            goto queue;
        case 2:
            system("cls");
            dequeue();
            goto queue;
        case 3:
            exit(0);
        default:
            cout << "Pilihan tidak valid\n\n";
    }
}
