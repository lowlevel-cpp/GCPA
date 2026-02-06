#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cctype>

using namespace std;

class Login {
    private:
        // VARIABLES AND FAYL ---------------
        string username;
        string parol;
        string telefon_nomer;

        fstream login_fayl;

    public:

        Login(const string& filename) {
            login_fayl.open(filename, ios::app);
            if (!login_fayl.is_open()) {
                cerr << "Login tizimida xatolik ketdi!";
            }
        }

        ~Login() {
            if (login_fayl.is_open()) {
                login_fayl.close();
            }
        }     

        // SETTERS --------------------
        void setUsername(string u) {username = u; }
        void setParol(string p) {parol = p; }
        void setTelefon(string t) {telefon_nomer = t; }
        
        // GETTERS --------------------
        string getUsername() {return username; }
        string getParol() {return parol; }
        string getTelefon() {return telefon_nomer; }        

        void add() {
            ostringstream fayl_yozilishi;
            fayl_yozilishi << getUsername() << "*" << getParol() << "*" << getTelefon() << "\n";

            if (login_fayl.is_open()) {
                login_fayl << fayl_yozilishi.str();
                login_fayl.flush();
            }
        }

        // void newUsernameFunc(string username, string password, string phonenumber) {
        //     ostringstream faylYozilishi;
        //     faylYozilishi << username << "*" << password << "*" << phonenumber << "\n";
        //     login_fayl << faylYozilishi.str();
        //     login_fayl.flush();
        // }
};
bool checkLogin(const string& username, const string& password);
bool checkPhone(const string& phoneNumber);
void choiceN1();
void choiceN5();
void choiceN6();

int main() {
    Login login("Login_fayl.txt");

    if (filesystem::is_empty("Login_fayl.txt")) {
        string username;
        string parol;
        string telefon_nomer;

        cout << endl << string(20, ' ') << "Tizimga kirish uchun AKKAUNT yarating.\n";
        cout << string(75, '-');

        cout << "\nUsername kriting >>> ";
        cin >> username;
        login.setUsername(username);
        
        cout << "Parol kiriting >>> ";
        cin >> parol;
        login.setParol(parol);
        
        cout << "Telefon nomeringizni kiriting >>> ";
        cin >> telefon_nomer;
        login.setTelefon(telefon_nomer);
        
        login.add();
    }

    
    int choice;
    cout << string (25, ' ') << string(50, '-');
    cout << endl << string(25, ' ') << "| Yangi student kiritish uchun [ 2 ] ni bosing.  |\n";
    cout << string(25, ' ') << "| Barcha baholarni ko'rish uchun [ 3 ] ni bosing.|\n";
    cout << string(25, ' ') << "| Tizimdan chiqish uchun [ 4 ] ni bosing.        |\n";
    cout << string(25, ' ') << "| Akkauntdan chiqish uchun [ 5 ] ni bosing.      |\n";
    cout << string (25, ' ') << string(50, '-') << endl;

    cout << "Choice: ";
    cin >> choice;

    switch (choice) {
        case 4:
            return 0;
        case 5:
            choiceN5();
            break;
    }
    return 0;
}

bool checkLogin(const string& username, const string& password) {
    ifstream Read_file("Login_fayl.txt");
    string fileUsername, filePassword, fileNumber;

    if (!Read_file.is_open()) {
        cerr << "File is not open.\n";
        return false;
    }
    while (getline(Read_file, fileUsername, '*') &&
           getline(Read_file, filePassword, '*') &&
            getline(Read_file, fileNumber, '*')) {
        if (fileUsername == username && filePassword == password) {
            Read_file.close();
            return true;
        }
    }

    Read_file.close();
    return false;
}

bool checkPhone(const string& phoneNumber) {
    ifstream Read_file("Login_fayl.txt");
    string fileUsername, filePassword, fileNumber;

    if(!Read_file.is_open()) {
        cerr << "File ochilmadi.\n";
        return false;
    }

    while (getline(Read_file, fileUsername, '*') &&
           getline(Read_file, filePassword, '*') &&
           getline(Read_file, fileNumber)) {
            if (phoneNumber == fileNumber) {
                Read_file.close();
                return true;
        }
    }

    Read_file.close();
    return false;
}

// bool isFour() {
//     fstream Read_file("is_four_file", ios::out);
//     if (!Read_file.is_open()) {
//         cerr << "Is Four File is not open.\n";
//     }

//     int wrod;
//     if (!Read_file) {
//         return false;
//     }
//     while (Read_file >> wrod) {
//         if (wrod == 4) {
//             Read_file.close();
//             return true;
//         }
//     }
//     return false;
//     Read_file.close();
// }

void choiceN1() {
    Login login("Login_fayl.txt");

    string searchUsername;
    string searchParol;

    cout << "Username >> ";
    cin >> searchUsername;
    cout << "Parol >> ";
    cin >> searchParol;

    int choice;
    
        if (checkLogin(searchUsername, searchParol)) {
            cout << string (25, ' ') << string(50, '-');
            cout << endl << string(25, ' ') << "| Yangi student kiritish uchun [ 2 ] ni bosing.  |\n";
            cout << string(25, ' ') << "| Barcha baholarni ko'rish uchun [ 3 ] ni bosing.|\n";
            cout << string(25, ' ') << "| Tizimdan chiqish uchun [ 4 ] ni bosing.        |\n";
            cout << string(25, ' ') << "| Akkauntdan chiqish uchun [ 5 ] ni bosing.      |\n";
            cout << string (25, ' ') << string(50, '-') << endl;
            
            cout << "Choice: ";
            cin >> choice;
            
        } else {
            cout << endl << string(25, ' ') << "| Username yoki parol xato. |\n";
            cout << string (25, ' ') << string(50, '-');
            cout << endl << string(25, ' ') << "| Akkauntga kirish uchun [ 1 ] ni bosing.        |\n";
            cout << string(25, ' ') << "| Tizimdan chiqish uchun [ 4 ] ni bosing.        |\n";
            cout << string(25, ' ') << "| Parolni qayta tiklash uchun [ 6 ] ni bosing.   |\n";
            cout << string (25, ' ') << string(50, '-') << endl;
            cout << "\nChoice: ";
            cin >> choice;
        }
        switch (choice) {
            case 1:
                choiceN1();
                break;
            case 4:
                return;
            case 5:
                choiceN5();
                break;
            case 6:
                choiceN6();
        }
    }


    
// }

void choiceN5() {

    // fstream isFourFile("Is_four_file.txt", ios::out);

    cout << endl << string(25, ' ') << "Akkauntdan chiqildi.\n";
    cout << string (25, ' ') << string(50, '-');
    cout << endl << string(25, ' ') << "| Akkauntga kirish uchun [ 1 ] ni bosing.        |\n";
    cout << string(25, ' ') << "| Tizimdan chiqish uchun [ 4 ] ni bosing.        |\n";
    cout << string(25, ' ') << "| Parolni qayta tiklash uchun [ 6 ] ni bosing.   |\n";
    cout << string (25, ' ') << string(50, '-') << endl;

    
    cout << "Choice: ";
    int choice;
    cin >> choice;

    // if (choice == 4) {
    //     isFourFile << 4;
    //     isFourFile.close();
    // }
    
    switch (choice) {
        case 1:
            choiceN1();
            break;
        case 4:
            return;
        case 6:
            choiceN6();
            break;
    }
}

void choiceN6() {
    Login login("Login_fayl.txt");
    string phoneNumber;
    cout << endl << "Akkaunt ga ochilgan telefon nomeringizni kiriting.\n";
    cout << "Nomer: ";
    cin >> phoneNumber;
    if (checkPhone(phoneNumber)) {
        string number;
        srand(time(0));
        int randomRaqam = rand() % 1000001;
        cout << "Shu raqamni kiriting: " << randomRaqam;
        string str_raqam = to_string(randomRaqam);
        cout << "\nInput: ";
        cin >> number;

        if (str_raqam == number) {
            string yangiUsername;
            string yangiParol;
            cout << "Yangi UserName kiriting: ";
            cin >> yangiUsername;
            cout << "Yangi Parol kiriting: ";
            cin >> yangiParol;

            ofstream File("Vaqtincha_fayl.txt");
            File << yangiUsername << "*" << yangiParol << "*" << phoneNumber << "\n";
            File.close();

            remove("Login_fayl.txt");
            rename("Vaqtincha_fayl.txt", "Login_fayl.txt");
            remove("Vaqtincha_fayl.txt");

            main();
        }
    } else {
        cout << endl << string(25, ' ') << "Bunday raqam mavjud emas!.\n";
        cout << string (25, ' ') << string(50, '-');
        cout << endl << string(25, ' ') << "| Akkauntga kirish uchun [ 1 ] ni bosing.        |\n";
        cout << string(25, ' ') << "| Tizimdan chiqish uchun [ 4 ] ni bosing.        |\n";
        cout << string(25, ' ') << "| Parolni qayta tiklash uchun [ 6 ] ni bosing.   |\n";
        cout << string (25, ' ') << string(50, '-') << endl;
        
        cout << "Choice: ";
        int choice;
        cin >> choice;
        
        switch (choice) {
            case 1:
                choiceN1();
                break;
            case 4:
                return;
            case 6:
                choiceN6();
                break;
        }
    }
}
