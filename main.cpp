#include <iostream>
#include <string>
#include <fstream>
//Прыгунов Данил вариант 16 , побитовый сдвиг вправо на 2 бита
using namespace std;
int main(int argc, const char* argv[]) {
    if (argc != 3) {
        cerr << "Error: Use three parameters\n"; return 5;
    }
    const string mode(argv[1]); // Режим работы
    const string file_name(argv[2]); // Имя файла
     if (mode == "encryption") {
    // Режим шифрование
    char str;
    cout<<"Write text(length-1)\n";
    cin>>str;
    int password;
    cout<<"Write password"<<endl<<"Password-";
    cin>>password;
    int8_t h=str;
    srand(password);
    h=h^rand();
    h=(h >> 2) | (h << (8 - 2));
    ofstream file;
    //помещаем значение в файл
    file.open(file_name, ios::binary);
    file << h;
    file.close();
}
else if (mode == "decryption") {
// Режим расшифрования
//Достаем зашифрованные данные из файла
int8_t n;
ifstream file;
file.open(file_name, ios::binary);
file>>n;
int password;
cout<<"Write password"<<endl<<"Password-";
cin>>password;
srand(password);
n=(n << 2) | (n >> (8 - 2));
n=n^rand();
char b =n;
cout<<b;

}
return 0; }
