#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "json_parser.cpp"

using namespace std;

void printBooks(const vector<Book> &books)
{
    cout << "[" << endl;

    for (const auto &book : books)
    {
        cout << "{judul: \"" << book.judul << ", penulis: \"" << book.penulis << ", tahun_terbit: " << book.tahun_terbit << ", nomor_rak: \"" << book.nomor_rak << "}\"" << endl;
    }
    cout << "]" << endl;
}

void merge(vector<Book> &books, int left, int middle, int right, string sortBy)
{
    int n1 = middle - left + 1;
    int n2 = right - middle;

    vector<Book> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = books[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = books[middle + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (sortBy == "judul" ? L[i].judul <= R[j].judul : sortBy == "penulis" ? L[i].penulis <= R[j].penulis
                                                                               : L[i].tahun_terbit <= R[j].tahun_terbit)
        {
            books[k] = L[i];
            i++;
        }
        else
        {
            books[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        books[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        books[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<Book> &books, int left, int right, string sortBy)
{
    if (left >= right)
        return;

    int middle = left + (right - left) / 2;
    mergeSort(books, left, middle, sortBy);
    mergeSort(books, middle + 1, right, sortBy);
    merge(books, left, middle, right, sortBy);
}

int main()
{
    ifstream file("data.json");

    stringstream buffer;
    buffer << file.rdbuf();
    string jsonData = buffer.str();

    vector<Book> books = jsonToBooks(jsonData);

    int choice;
    cout << "Pilih kriteria untuk mengurutkan buku: " << endl;
    cout << "1. Judul" << endl;
    cout << "2. Penulis" << endl;
    cout << "3. Tahun Terbit" << endl;
    cout << "4. Exit" << endl;
    cout << "Masukkan pilihan Anda: ";
    cin >> choice;

    string sortBy;
    switch (choice)
    {
    case 1:
        sortBy = "judul";
        break;
    case 2:
        sortBy = "penulis";
        break;
    case 3:
        sortBy = "tahun_terbit";
        break;
    case 4:
        cout << "Matur nuwun";
        return 0;
        break;
    default:
        cout << "Pilihan tidak valid.";
        return 0;
    }

    mergeSort(books, 0, books.size() - 1, sortBy);
    printBooks(books);

    return 0;
}
