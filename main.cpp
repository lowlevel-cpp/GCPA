#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cctype>
#include <iomanip>

using namespace std;

// LOGIN CLASS ----------

class Login {
    private:
        // VARIABLES AND FAYL OF LOGIN CLASS ----------
        string username;
        string parol;
        string telefon_nomer;

        fstream login_fayl;

    public:

        // CONSTRUCTOR AND DECONSTRUCTOR ----------

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

        // LOGIN CLASS / SETTERS ---------------
        void setUsername(string u) {username = u; }
        void setParol(string p) {parol = p; }
        void setTelefon(string t) {telefon_nomer = t; }
        
        // LOGIN CLASS / GETTERS ---------------
        string getUsername() {return username; }
        string getParol() {return parol; }
        string getTelefon() {return telefon_nomer; }   
        
        // FAYLGA MALUMOTLARNI YOZILISHI / QO'SHILISHI -----

        void add() {
            ostringstream fayl_yozilishi;
            fayl_yozilishi << getUsername() << "*" << getParol() << "*" << getTelefon() << "\n";

            if (login_fayl.is_open()) {
                login_fayl << fayl_yozilishi.str();
                login_fayl.flush();
            }
        }
};

// ALL INFO CLASS ----------

class AllInfo {
    // VARIABLES AND FAYL OF ALL INFO CLASS -----
    private:
        string ism;
        string familya;
        string uquvchiId;
        string fan1Nomi;
        string darslar1Soni;
        string baho1;
        string fan2Nomi;
        string darslar2Soni;
        string baho2;
        string fan3Nomi;
        string darslar3Soni;
        string baho3;
        string fan4Nomi;
        string darslar4Soni;
        string baho4;

        fstream yaratilganFayl;
    public:
        // ALL INFO CONSTRUCTOR AND DECONSTRUCTOR -----

        AllInfo(const string& filename) {
            yaratilganFayl.open(filename, ios::app);
            if(!yaratilganFayl.is_open()) {
                cerr << "Fayl ochiq emas.\n";
            }
        }

        ~AllInfo() {
            if(yaratilganFayl.is_open()) {
                yaratilganFayl.close();
            }
        }

        // ---------- ALL INFO / SETTERS ----------

        void setIsm(string i) {ism = i; }
        void setFamilya(string f) {familya = f; }
        void setId(string id) {uquvchiId = id; }
        void setFanName1(string sfn1) {fan1Nomi = sfn1; }
        void setDarslar1(string ds1) {darslar1Soni = ds1; }
        void setBaho1(string b1) {baho1 = b1; }
        void setFanName2(string sfn2) {fan2Nomi = sfn2; }
        void setDarslar2(string ds2) {darslar2Soni = ds2; }
        void setBaho2(string b2) {baho2 = b2; }
        void setFanName3(string sfn3) {fan3Nomi = sfn3; }
        void setDarslar3(string ds3) {darslar3Soni = ds3; }
        void setBaho3(string b3) {baho3 = b3; }
        void setFanName4(string sfn4) {fan4Nomi = sfn4; }
        void setDarslar4(string ds4) {darslar4Soni = ds4; }
        void setBaho4(string b4) {baho4 = b4; }

        // ---------- ALL INFO / GETTERS ----------

        string getIsm() {return ism; }
        string getFamilya() {return familya; }
        string getId() {return uquvchiId; }
        string getFanName1() {return fan1Nomi; }
        string getDarslar1() {return darslar1Soni; }
        string getBaho1() {return baho1; }
        string getFanName2() {return fan2Nomi; }
        string getDarslar2() {return darslar2Soni; }
        string getBaho2() {return baho2; }
        string getFanName3() {return fan3Nomi; }
        string getDarslar3() {return darslar3Soni; }
        string getBaho3() {return baho3; }
        string getFanName4() {return fan4Nomi; }
        string getDarslar4() {return darslar4Soni; }
        string getBaho4() {return baho4; }

        // ALL INFO CLASS ADDING INFORMATION TO FILE -----
        void add() {
            ostringstream faylgaMalumolarYozilishi;
            faylgaMalumolarYozilishi 
                << getIsm() << "*" << getFamilya() << "*" << getId()
                << "*" << getFanName1() << "*" << getDarslar1() << "*" << getBaho1()
                << "*" << getFanName2() << "*" << getDarslar2() << "*" << getBaho2()
                << "*" << getFanName3() << "*" << getDarslar3() << "*" << getBaho3()
                << "*" << getFanName4() << "*" << getDarslar4() << "*" << getBaho4()
                << '\n';

            if (yaratilganFayl.is_open()) {
                yaratilganFayl << faylgaMalumolarYozilishi.str();
                yaratilganFayl.flush();
            }
        }

};

bool checkLogin(const string& username, const string& password);
bool checkPhone(const string& phoneNumber);
bool checkStudentID(string& uquvchi_ism, string& uquvchi_familya, string& uquvchi_id, 
                    string& fan1, string& darslar1, string& baho1,
                    string& fan2, string& darslar2, string& baho2,
                    string& fan3, string& darslar3, string& baho3,
                    string& fan4, string& darslar4, string& baho4);
string titleCase(string& matn);
void choiceN1();
void choiceN2();
void choiceN3();
void choiceN4();
void choiceN8();
void choiceN9();

// MAIN FUNKSIYASI ---------------

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
        transform(username.begin(), username.end(), username.begin(), ::tolower);
        login.setUsername(username);
        
        cout << "Parol kiriting >>> ";
        cin >> parol;
        login.setParol(parol);
        
        cout << "Telefon nomeringizni kiriting >>> (+998) ";
        cin >> telefon_nomer;
        login.setTelefon(telefon_nomer);
        
        login.add();
    }

    
    int choice;
    cout << string (17, ' ') << string(61, '-');
    cout << endl << string(17, ' ') << "| Yangi student kiritish uchun [ 2 ] ni bosing.             |\n";
    cout << string(17, ' ') << "| Talabalaning GPA baholarini ko'rish uchun [ 3 ] ni bosing.|\n";
    cout << string(17, ' ') << "| Barcha talabalarni ko'rish uchun [ 4 ] ni bosing.         |\n";
    cout << string(17, ' ') << "| Talabalarni GPA orqali saralash uchun [ 5 ] ni bosing.    |\n";
    cout << string(17, ' ') << "| Talabani o'chirib tashlash uchun [ 6 ] ni bosing.         |\n";
    cout << string(17, ' ') << "| Tizimdan chiqish uchun [ 7 ] ni bosing.                   |\n";
    cout << string(17, ' ') << "| Akkauntdan chiqish uchun [ 8 ] ni bosing.                 |\n";
    cout << string (17, ' ') << string(61, '-') << endl;

    cout << "Choice: ";
    cin >> choice;

    switch (choice) {
        case 2:
            choiceN2();
            break;
        case 3:
            choiceN3();
            break;
        case 4:
            choiceN4();
            break;
        case 7:
            return 0;
        case 8:
            choiceN8();
            break;
    }
    return 0;
}

// LOGIN CHECKING FUNCTION ----------

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

// CHECKING PHONE NUMBER FUNCTION -----

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

// CHECK STUDENT ID FUNCTION ----------
bool checkStudentID(string& uquvchi_ism, string& uquvchi_familya, string& uquvchi_id,
            string& fan1, string& darslar1, string& baho1,
            string& fan2, string& darslar2, string& baho2,
            string& fan3, string& darslar3, string& baho3,
            string& fan4, string& darslar4, string& baho4) {

    bool is_leng_six = false;
    if (uquvchi_id.length() == 6) {
        is_leng_six = true;
    }
    while(!is_leng_six) {
        cout << string(8, ' ') << "Talabaning ID sini kiritng (6-raqam) >> ";
        cin >> uquvchi_id;
        if (uquvchi_id.length() == 6) {
            break;
        } 
    }

    string checkingIsm, checkingFamilya, checkingId, checkingFan1, checkingDarslar1, checkingBaho1, checkingFan2, checkingDarslar2, checkingBaho2, checkingFan3, checkingDarslar3, checkingBaho3,  checkingFan4, checkingDarslar4, checkingBaho4;
    ifstream ReadFile("AllInfo.txt", ios::in);
    if (!ReadFile.is_open()) {
        cerr << "File is not open.";
    }
    while (getline(ReadFile, checkingIsm, '*') &&
           getline(ReadFile, checkingFamilya, '*') &&
           getline(ReadFile, checkingId, '*') &&
           getline(ReadFile, checkingFan1, '*') &&
           getline(ReadFile, checkingDarslar1, '*') &&
           getline(ReadFile, checkingBaho1, '*') &&
           getline(ReadFile, checkingFan2, '*') &&
           getline(ReadFile, checkingDarslar2, '*') &&
           getline(ReadFile, checkingBaho2, '*') &&
           getline(ReadFile, checkingFan3, '*') &&
           getline(ReadFile, checkingDarslar3, '*') &&
           getline(ReadFile, checkingBaho3, '*') &&
           getline(ReadFile, checkingFan4, '*') &&
           getline(ReadFile, checkingDarslar4, '*') &&
           getline(ReadFile, checkingBaho4))
           {
            if (uquvchi_id == checkingId) {
                ReadFile.close();
                return true;
            }
           }
           ReadFile.close();
           return false;
}

// TITLE CASE FUNCTION -----

string titleCase(string& matn) {
    bool yangiSoz = true;
    for (int i = 0; i < matn.length(); i++) {
        if (matn[i] == ' ') {
            yangiSoz = true;
        } else if (yangiSoz) {
            matn[i] = toupper(matn[i]); 
            yangiSoz = false;
        } else {
            matn[i] = tolower(matn[i]);
        }
    }
    return matn;
}

// CHOICE N1 FUNCTION / ~REGISTRING~ -----

void choiceN1() {
    Login login("Login_fayl.txt");

    string searchUsername;
    string searchParol;

    cout << "Username >> ";
    cin >> searchUsername;
    transform(searchUsername.begin(), searchUsername.end(), searchUsername.begin(), ::tolower);
    cout << "Parol >> ";
    cin >> searchParol;


    int choice;
    
        if (checkLogin(searchUsername, searchParol)) {
            cout << string (17, ' ') << string(61, '-');
            cout << endl << string(17, ' ') << "| Yangi student kiritish uchun [ 2 ] ni bosing.             |\n";
            cout << string(17, ' ') << "| Talabalaning GPA baholarini ko'rish uchun [ 3 ] ni bosing.|\n";
            cout << string(17, ' ') << "| Barcha talabalarni ko'rish uchun [ 4 ] ni bosing.         |\n";
            cout << string(17, ' ') << "| Talabalarni GPA orqali saralash uchun [ 5 ] ni bosing.    |\n";
            cout << string(17, ' ') << "| Talabani o'chirib tashlash uchun [ 6 ] ni bosing.         |\n";
            cout << string(17, ' ') << "| Tizimdan chiqish uchun [ 7 ] ni bosing.                   |\n";
            cout << string(17, ' ') << "| Akkauntdan chiqish uchun [ 8 ] ni bosing.                 |\n";
            cout << string (17, ' ') << string(61, '-') << endl;
            
            cout << "Choice: ";
            cin >> choice;
            
        } else {
            choiceN8();
        }
        switch (choice) {
            case 2:
                choiceN2();
                break;
            case 4:
                choiceN4();
                break;
            case 7:
                return;
            case 8:
                choiceN8();
                break;
        }
    }


// CHOICE N2 FUNCTION / ENTERING STUDENTS NAME, SUBJECTS, MARKS, ETC... -----

void choiceN2() {
    AllInfo barchMalumotlar("AllInfo.txt");

    string uquvchi_ism, uquvchi_familya, uquvchi_id, fan1, darslar1, baho1,
                                                     fan2, darslar2, baho2,
                                                     fan3, darslar3, baho3,
                                                     fan4, darslar4, baho4;

    cout << string(8, ' ') << "Talabaning ismi >> ";
    cin >> uquvchi_ism;
    cout << string(8, ' ') << "Talabaning familyasi >> ";
    cin >> uquvchi_familya;

    transform(uquvchi_ism.begin(), uquvchi_ism.end(), uquvchi_ism.begin(), ::tolower);
    transform(uquvchi_familya.begin(), uquvchi_familya.end(), uquvchi_familya.begin(), ::tolower);

    cout << string(8, ' ') << "Talabaning ID sini kiritng >> ";
    cin >> uquvchi_id;
    bool idCheck = false;
    if (checkStudentID(uquvchi_ism, uquvchi_familya, uquvchi_id, fan1, darslar1, baho1,
                                                    fan2, darslar2, baho2,
                                                    fan3, darslar3, baho3,
                                                    fan4, darslar4, baho4)) 
    {
        idCheck = true;
    }

    while (idCheck) {
        cout << string(8, ' ') << "Bunday ID tizimda bor! Talabaning ID sini kiritng >> ";
        cin >> uquvchi_id;
            if (!(checkStudentID(uquvchi_ism, uquvchi_familya, uquvchi_id, fan1, darslar1, baho1,
                                                    fan2, darslar2, baho2,
                                                    fan3, darslar3, baho3,
                                                    fan4, darslar4, baho4)))
            {
                break;
            }
    }

    cout << endl << string(8, ' ') << string(35, '-') << endl;

    cout << string(8, ' ') << "1-Fan >> ";
    getline(cin >> ws, fan1);
    transform(fan1.begin(), fan1.end(), fan1.begin(), ::tolower);
    cout << string(8, ' ') << "Darslar soni >> ";
    cin >> darslar1;
    cout << string(8, ' ') << "Bahosi >> ";
    cin >> baho1;

    cout << string(8, ' ') << string(35, '-') << endl;

    cout << string(8, ' ') << "2-Fan >> ";
    getline(cin >> ws, fan2);
    transform(fan2.begin(), fan2.end(), fan2.begin(), ::tolower);
    cout << string(8, ' ') << "Darslar soni >> ";
    cin >> darslar2;
    cout << string(8, ' ') << "Bahosi >> ";
    cin >> baho2;

    cout << string(8, ' ') << string(35, '-') << endl;

    cout << string(8, ' ') << "3-Fan >> ";
    getline(cin >> ws, fan3);
    transform(fan3.begin(), fan3.end(), fan3.begin(), ::tolower);
    cout << string(8, ' ') << "Darslar soni >> ";
    cin >> darslar3;
    cout << string(8, ' ') << "Bahosi >> ";
    cin >> baho3;

    cout << string(8, ' ') << string(35, '-') << endl;

    cout << string(8, ' ') << "4-Fan >> ";
    getline(cin >> ws, fan4);
    transform(fan4.begin(), fan4.end(), fan4.begin(), ::tolower);
    cout << string(8, ' ') << "Darslar soni >> ";
    cin >> darslar4;
    cout << string(8, ' ') << "Bahosi >> ";
    cin >> baho4;
    

    barchMalumotlar.setIsm(uquvchi_ism);
    barchMalumotlar.setFamilya(uquvchi_familya);
    barchMalumotlar.setId(uquvchi_id);
    barchMalumotlar.setFanName1(fan1);
    barchMalumotlar.setDarslar1(darslar1);
    barchMalumotlar.setBaho1(baho1);

    barchMalumotlar.setFanName2(fan2);
    barchMalumotlar.setDarslar2(darslar2);
    barchMalumotlar.setBaho2(baho2);

    barchMalumotlar.setFanName3(fan3);
    barchMalumotlar.setDarslar3(darslar3);
    barchMalumotlar.setBaho3(baho3);

    barchMalumotlar.setFanName4(fan4);
    barchMalumotlar.setDarslar4(darslar4);
    barchMalumotlar.setBaho4(baho4);

    barchMalumotlar.add();

    main();
}

// CHOICE N3 FUNCTION / SEE THE INFO OF ONE SPECIFIC STUDENT -----

void choiceN3() {
    AllInfo all_info("AllInfo.txt");

    ifstream ReadFile("AllInfo.txt");

    if (!ReadFile.is_open()) {
        cerr << "File is not open.";
    }

    string uquvchi_ism, uquvchi_familya, uquvchi_id, fan1, darslar1, baho1,
                                                     fan2, darslar2, baho2,
                                                     fan3, darslar3, baho3,
                                                     fan4, darslar4, baho4, searchID;
    bool checkTrueOrNot = false;
    cout << "ID ni kiriting: ";
    cin >> searchID;

    while (getline(ReadFile, uquvchi_ism, '*') &&
           getline(ReadFile, uquvchi_familya, '*') &&
           getline(ReadFile, uquvchi_id, '*') &&
           getline(ReadFile, fan1, '*') &&
           getline(ReadFile, darslar1, '*') &&
           getline(ReadFile, baho1, '*') &&
           getline(ReadFile, fan2, '*') &&
           getline(ReadFile, darslar2, '*') &&
           getline(ReadFile, baho2, '*') &&
           getline(ReadFile, fan3, '*') &&
           getline(ReadFile, darslar3, '*') &&
           getline(ReadFile, baho3, '*') &&
           getline(ReadFile, fan4, '*') &&
           getline(ReadFile, darslar4, '*') &&
           getline(ReadFile, baho4))
           {
            if (searchID == uquvchi_id) {
                checkTrueOrNot = true;
                break;
            }
           }

        //    RAQAM - 1

           string sda1 = darslar1 + " soat";
           
           float hisoblash1 = stof(darslar1)*stof(baho1);

           ostringstream oss1;
           oss1 << hisoblash1 << " ball";
           string h1 = oss1.str();

        //    RAQAM - 2

           string sda2 = darslar2 + " soat";
           
           float hisoblash2 = stof(darslar2)*stof(baho2);

           ostringstream oss2;
           oss2 << hisoblash2 << " ball";
           string h2 = oss2.str();

        //    RAQAM - 3

           string sda3 = darslar3 + " soat";
           
           float hisoblash3 = stof(darslar3)*stof(baho3);

           ostringstream oss3;
           oss3 << hisoblash3 << " ball";
           string h3 = oss3.str();


        //    RAQAM - 4

           string sda4 = darslar4 + " soat";
           
           float hisoblash4 = stof(darslar4)*stof(baho4);

           ostringstream oss4;
           oss4 << hisoblash4 << " ball";
           string h4 = oss4.str();

           

           float all_baho = hisoblash1 + hisoblash2 + hisoblash3 + hisoblash4;
           int darslar_soni = stoi(darslar1) + stoi(darslar2) + stoi(darslar3) + stoi(darslar4);
           float GPA = all_baho/darslar_soni;
           ostringstream ossGPA;
           ossGPA << fixed << setprecision(2) << GPA;
           string strGPA = ossGPA.str();

           if (checkTrueOrNot) {
                cout << endl << string(5, ' ') << "Talaba: " << titleCase(uquvchi_familya) << " " << titleCase(uquvchi_ism) << " / ID raqam: " << uquvchi_id << endl;
                cout << string(5, ' ') << "Umumiy GCPA: " << strGPA << endl;
                cout << endl << string(5, ' ') << left << setw(23) << "Fan" << setw(20) << "Darslar/Soat" << setw(15) << "Baho" << setw(10) << "Umumiy Ball" << endl;
                cout << string(5, ' ') << string(69, '-') << endl;
                cout << string(5, ' ') << left << setw(23) << titleCase(fan1) << setw(20) << sda1 << setw(15) << baho1 << setw(10) << h1 << endl;
                cout << string(5, ' ') << string(69, '-') << endl;
                cout << string(5, ' ') << left << setw(23) << titleCase(fan2) << setw(20) << sda2 << setw(15) << baho2 << setw(10) << h2 << endl;
                cout << string(5, ' ') << string(69, '-') << endl;
                cout << string(5, ' ') << left << setw(23) << titleCase(fan3) << setw(20) << sda3 << setw(15) << baho3 << setw(10) << h3 << endl;
                cout << string(5, ' ') << string(69, '-') << endl;
                cout << string(5, ' ') << left << setw(23) << titleCase(fan4) << setw(20) << sda4 << setw(15) << baho4 << setw(10) << h4 << endl;
            } else {
                cout << "Bunday ID raqam topilmadi!\n";
            }

            cout << endl;

        main();
}



// void choiceN4() {
//     AllInfo allinfo("AllInfo.txt");

//     fstream ReadFile("AllInfo.txt");
//     string uquvchi_ism, uquvchi_familya, uquvchi_id, fan1, darslar1, baho1,
//                                                      fan2, darslar2, baho2,
//                                                      fan3, darslar3, baho3,
//                                                      fan4, darslar4, baho4;

//     cout << "Ismlar" << endl;

//     auto it = findif(ReadFile.)

//     while (getline(ReadFile, uquvchi_ism, '*') &&
//            getline(ReadFile, uquvchi_familya, '*') &&
//            getline(ReadFile, uquvchi_id, '*') &&
//            getline(ReadFile, fan1, '*') &&
//            getline(ReadFile, darslar1, '*') &&
//            getline(ReadFile, baho1, '*') &&
//            getline(ReadFile, fan2, '*') &&
//            getline(ReadFile, darslar2, '*') &&
//            getline(ReadFile, baho2, '*') &&
//            getline(ReadFile, fan3, '*') &&
//            getline(ReadFile, darslar3, '*') &&
//            getline(ReadFile, baho3, '*') &&
//            getline(ReadFile, fan4, '*') &&
//            getline(ReadFile, darslar4, '*') &&
//            getline(ReadFile, baho4)) {
//                 cout << titleCase(uquvchi_ism) << endl;
//            }
    
// }

// CHOICE N8 FUNCTION / OUT OF THE ACCOUNT ----- 

void choiceN8() {

    cout << endl << string(22, ' ') << "Akkauntdan chiqildi.\n";
    cout << string (22, ' ') << string(50, '-');
    cout << endl << string(22, ' ') << "| Akkauntga kirish uchun [ 1 ] ni bosing.        |\n";
    cout << string(22, ' ') << "| Parolni qayta tiklash uchun [ 9 ] ni bosing.   |\n";
    cout << string (22, ' ') << string(50, '-') << endl;

    
    cout << "Choice: ";
    int choice;
    cin >> choice;
    
    switch (choice) {
        case 1:
            choiceN1();
            break;
        case 9:
            choiceN9();
            break;
    }
}

// CHOICE N9 FUNCTION / CHANGING USERNAME AND PASSWORD VIA PHONENUMBER -----

void choiceN9() {
    Login login("Login_fayl.txt");
    string phoneNumber;
    cout << endl << "Akkaunt ga ochilgan telefon nomeringizni kiriting.\n";
    cout << "Nomer: (+998) ";
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
            transform(yangiUsername.begin(), yangiUsername.end(), yangiUsername.begin(), ::tolower);
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
        cout << string(25, ' ') << "| Parolni qayta tiklash uchun [ 9 ] ni bosing.   |\n";
        cout << string (25, ' ') << string(50, '-') << endl;
        
        cout << "Choice: ";
        int choice;
        cin >> choice;
        
        switch (choice) {
            case 1:
                choiceN1();
                break;
            case 9:
                choiceN9();
                break;
        }
    }
}
