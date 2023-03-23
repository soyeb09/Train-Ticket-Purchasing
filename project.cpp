#include <iostream>  //input output string = used for basic actions
#include <windows.h> // used for console window edit
#include <string>  // used for string operations
#include <fstream>   // used for managing file actions
#include <direct.h>  // used for making directory
#include <conio.h>  // used for taking password hidden input
#include <urlmon.h>  // used for downloading file
#include <vector> // used for file string replacement

#pragma comment(lib, "urlmon.lib")
#pragma warning(disable : 4996) 
#pragma warning(disable : 6031) 
#pragma warning(disable : 4129) 

using namespace std;

string phone;
string username;
string payment_status()
{
    ifstream status;
    string x;
    status.open(("C:\\database//" + phone + ".bin").c_str()); // .c_str() = convert to string

    string st_pending = "pending";
    string st_approved = "approved";
    string st_denied = "denied";
    int line = 1;
    bool found = false;
    while (getline(status, x))
    {
        
        if (x.find(st_pending, 0) != string::npos) // npos = end position of string
        {
            if (line == 8)
            {
                if (st_pending == x)
                {
                    found = true;
                    break;
                }
            }
        }
        else if (x.find(st_approved, 0) != string::npos) // npos = end position of string
        {
   
            if (line == 8)
            {
                if (st_approved == x)
                {
                    found = true;
                    break;
                }
            }
            
        }
   
        else if (x.find(st_denied, 0) != string::npos) // npos = end position of string
        {
            if (line == 8)
            {
                if (st_denied == x)
                {
                    found = true;
                    break;
                }
            }
        }
        
        line++;
    }
    status.close();
    if (found == true)
    {
        return x;
    }
    else
    {
        return "Payment has not been done yet!";
    }
    
}
bool signup()
{
    
    system("cls");
    cout << "Signup Process is running . . ." << endl;

    
    string name, NID, password;
    cout << "Name : ";
    getline(cin >> ws, name);
    cout << "Phone : ";
    getline(cin, phone);
    cout << "NID : ";
    getline(cin, NID);
    cout << "Password : ";

    int letter = 0;
    letter = getch();
    while (letter != 8 && letter != 13)
    {
        
        password.push_back(letter);
        cout << "*";
        letter =  getch();
    }

    ofstream create;

    create.open(("C:\\database//" + phone + ".bin").c_str()); // .c_str() = convert to string
    create << name << "\n" << phone << "\n" << NID << "\n" << password << endl;
    create.close();

    system("cls");
    cout << "Signup complete. Go to main menu to login . . ." << endl;

    return true;
}
bool login()
{
    string password;

    cout << "Phone : ";
    getline(cin >> ws, phone);
    cout << "Password : ";

    int letter = 0;
    letter = getch();
    while (letter != 8 && letter != 13)
    {
        password.push_back(letter);
        cout << "*";
        letter = getch();
    }

    cout << "\nIn progress";
    Sleep(500);
    cout << ".";
    Sleep(500);
    cout << ".";

    ifstream pw(("C:\\database//" + phone + ".bin").c_str());
    string x;
    fstream read;
    string identity = ("C:\\database//" + phone + ".bin").c_str();

    bool found = false;
    if (pw.is_open() == true)
    {
        Sleep(500);
        cout << "." << endl;

        int line = 1;
        while (getline(pw, x))
        {

            if (x.find(password, 0) != string::npos) // npos = end position of string
            {
                if (line == 4)
                {
                    if (password == x)
                    {
                        found = true;
                        break;
                    }
                    else
                        break;
                }
            }
            line++;
        }
        pw.close();

        if (found == false)
        {
            cout << "Password does not match!" << endl;
            return false;
        }
        else
        {
            cout << "Credential Matched!" << endl;
            cout << "Login Success" << endl;

            system("cls");


            cout << R"(
   __        __   _
   \ \      / /__| | ___ ___  _ __ ___   ___
    \ \ /\ / / _ \ |/ __/ _ \| '_ ` _ \ / _ \
     \ V  V /  __/ | (_| (_) | | | | | |  __/
      \_/\_/ \___|_|\___\___/|_| |_| |_|\___|

)" << endl;// << name;

            int line = 1;

            read.open(identity, ios::in);
            while (getline(read, x))
            {
                if (line == 1) 
                { 
                    cout << x << endl;
                    break; 
                }      
            }
            read.close();
            return true;
        }
    }
    else
    {
        cout << "." << endl;
        cout << "Phone Number does not match!" << endl;
        
        return false;
    }

}
int price(int Train_no)
{
    ofstream price;

    price.open("C:\\j2me\\Price\\price.bin"); // .c_str() = convert to string

    price << R"(320
560
360
240
550
420)";
    price.close();

    ifstream train;
    string x;
    train.open("C:\\j2me\\Price\\price.bin");
    if (train.is_open() == true)
    {
        Sleep(500);
        int line = 1;
        while (getline(train, x))
        {
            if (line == Train_no)
            {
                break;
            }
            line++;
        }
        train.close();
    }
    else
    {
        return -9099;
    }
    return stoi(x);
}
bool train_manual()
{
    system("cls");
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, 786, 560, TRUE);
    system("cls");

    ofstream manual;

    manual.open("C:\\j2me\\TrainList\\train.bin"); // .c_str() = convert to string
    
    manual << R"(  Train Name  		Destination   			Time
---------------------------------------------------------------------
1 Dhaka Mail		Dhaka to Sylhet		09:00 AM - 03:30 PM
2 Chattogram Mail	Dhaka to Chattogram	10:00 AM - 05:00 PM
3 Karnaphuli Express    Dhaka to Khulna  	07:30 AM - 02:00 PM
4 Chattogram Mail	Dhaka to Mymensingh	05:30 PM - 02:00 AM
5 Rajshahi Express	Dhaka to Rangpur	09:00 AM - 03:30 PM
6 Mohanagar Provati	Dhaka to Rajshahi	11:00 AM - 09:00 PM)";
    manual.close();
    return true;
}
bool admin_register()
{
    ifstream j2("C://j2me");

    string password, masterPassword;

    string confirm = "administrator";
    string c;
    //system("cls");
    cout << "What is the confirmation password?\n";
    int letter = 0;
    letter = getch();
    while (letter != 8 && letter != 13)
    {
        c.push_back(letter);
        cout << "*";
        letter = getch();
    }
    if (confirm==c)
    {
        Sleep(50);
        cout << "\nConfirmed!\n";
        system("cls");
        cout << "username : ";
        getline(cin >> ws, username);
        cout << "password : ";

        int letter = 0;
        letter = getch();
        while (letter != 8 && letter != 13)
        {
            password.push_back(letter);
            cout << "*";
            letter = getch();
        }
        cout << "\nmaster password : ";

        int letter1 = 0;
        letter1 = getch();
        while (letter1 != 8 && letter1 !=13)
        {
            masterPassword.push_back(letter1);
            cout << "*";
            letter1 = getch();
        }

        ofstream adminX;

        adminX.open(("C://j2me//" + username + ".bin").c_str());
        adminX << username << "\n" << masterPassword  << "\n" << password << endl;
        adminX.close();

        return true;
    }
    else
    {
        cout << "\nWrong password!\n";
        return false;
    }
}
bool admin_login()
{
    string password;

    cout << "username : ";
    getline(cin >> ws, username);

    cout << "password : ";
    int letter = 0;
    letter = getch();
    while (letter != 8 && letter != 13)
    {
        password.push_back(letter);
        cout << "*";
        letter = getch();
    }

    cout << "\nIn progress";
    Sleep(500);
    cout << ".";
    Sleep(500);
    cout << ".";

    ifstream pw(("C:\\j2me\\" + username + ".bin").c_str());
    string x;

    bool found = false;
    if (pw.is_open() == true)
    {
        Sleep(500);
        cout << "." << endl;
       
        int line = 1;
        while (getline(pw, x))
        {

            if (x.find(password, 0) != string::npos) // npos = end position of string
            {
                if (line == 3)
                {
                    if (password == x)
                    {
                        found = true;
                        break;
                    }
                    break;
                }
            }
            line++;
        }
        pw.close();

        if (found == false)
        {
            cout << "Password does not match!" << endl;
            return false;
        }
        else
        {
            cout << "Credential Matched!" << endl;
            cout << "Login Success" << endl;
            return true;
        }
    }
    else
    {
        cout << "." << endl;
        cout << "Invalid Details!" << endl;
        return false;
    }

}
bool admin_forget_passowrd()
{
    string MP;

    cout << "username : ";
    getline(cin >> ws, username);
    cout << "Enter Master Password : ";
    int letter1 = 0;
    letter1 = getch();
    while (letter1 != 8 && letter1 != 13)
    {
        MP.push_back(letter1);
        cout << "*";
        letter1 = getch();
    }

    cout << "\nIn progress";
    Sleep(500);
    cout << ".";
    Sleep(500);
    cout << ".";

    ifstream pw(("C:\\j2me\\" + username + ".bin").c_str());
    string x;

    bool found = false;
    if (pw.is_open() == true)
    {
        Sleep(500);
        cout << "." << endl;
        int line = 1;
        while (getline(pw, x))
        {
         
            if (x.find(MP, 0) != string::npos) // npos = end position of string
            {
                if (line == 2)
                {
                    if (MP == x)
                    {
                        found = true;
                        break;
                    }
                    break;
                }
            }
            line++;
        }
        pw.close();

        if (found == false)
        {
            cout << "Password does not match!" << endl;
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        cout << "." << endl;
        cout << "Invalid Details!" << endl;
        return false;
    }

}
bool user_forget_passowrd()
{
    string NID;

    cout << "Phone No: ";
    getline(cin >> ws, phone);
    cout << "Enter NID : ";

    int letter1 = 0;
    letter1 = getch();
    while (letter1 != 8 && letter1 != 13)
    {
        NID.push_back(letter1);
        cout << "*";
        letter1 = getch();
    }

    cout << "\nIn progress";
    Sleep(500);
    cout << ".";
    Sleep(500);
    cout << ".";

    ifstream pw(("C:\\database//" + phone + ".bin").c_str());
    string x;

    bool found = false;
    if (pw.is_open() == true)
    {
        Sleep(500);
        cout << "." << endl;
        
        int line = 1;
        while (getline(pw, x))
        {

            if (x.find(NID, 0) != string::npos) // npos = end position of string
            {
                if (line == 3)
                {
                    if (NID == x)
                    {
                        
                        found = true;
                        break;
                    }
                    break;
                }
            }
            line++;
        }
        pw.close();

        if (found == false)
        {
            cout << "Password does not match!" << endl;
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        cout << "." << endl;
        cout << "Invalid Details!" << endl;
        return false;
    }

}

int main()
{
    _mkdir("C:\\database");  
    _mkdir("C:\\j2me");
    _mkdir("C:\\j2me\\TrainList");  
    _mkdir("C:\\j2me\\Price");  
    system("attrib +h C:\\database");
    system("attrib +h C:\\j2me");
    system("attrib +h C:\\j2me\\TrainList");
    system("attrib +h C:\\j2me\\Price");

    URLDownloadToFile(NULL, L"https://cdn.discordapp.com/attachments/1044588980219416599/1044589040764194846/list.bat", L"C:\\j2me\\list.bat", 0, NULL);
    // Unknown Pointer , wide char "string/link", wide char "file path", int64, call back status
start:
    SetConsoleTitleA("                      Railway Ticket Management System");
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, 450, 570, TRUE);
    system("color 70");

    cout << R"(

                        .-"""-.
                       / .===. \
                       \/ o o \/
                       ( \___/ )
         _________ooo___\_____/_____________
        /                                   \
       |              1. User Mode           |
       |              2. Admin Mode          |
       |              3. Exit                |
       |                                     |
        \_______________________ooo_________/
                        |  |  |
                        |_ | _|
                        |  |  |
                        |  |  |
                        /-'Y'-\
                       ( /   \ )
)";
    
    int menu_choise = 0;
    cin >> menu_choise;
    int goback;


    if (menu_choise == 1)
    {
        system("cls");

        cout << "User Mode\n\n1. Signup\n2. Login\n3.\ Forget Password\n0. Main Menu\n";

        
        int U_c;
        cin >> U_c;
        if (U_c == 1)
        {
            system("cls");
            signup();
            
            cout << "\n0 : Main Menu" << endl;
            cin >> goback;
            if (goback == 0)
            {
                goback = 1;
                system("cls");
                goto start;
            }
        }
        else if (U_c == 2)
        {
            system("cls");
            if (login() == true)
            {
                cout << "Payemnt status : " << payment_status() << endl;
                Sleep(2000);
                
               if (payment_status() == "Payment has not been done yet!")
                {
                    Sleep(2000);
                    train_manual();

                    ifstream train;
                    string x;
                    train.open("C:\\j2me\\TrainList\\train.bin");
                    if (train.is_open() == true)
                    {
                        Sleep(500);
                        int line = -1;
                        while (getline(train, x))
                        {
                            cout << x << endl;
                        }
                        train.close();
                    }
                    else
                    {
                        cout << "No train list found in database" << endl;
                        goto start;
                    }
               }

                else
                {
                   ifstream status;
                   string x;
                   int line = 1;
                   status.open(("C:\\database\\" + phone + ".bin").c_str());
                   MoveWindow(console, r.left, r.top, 650, 570, TRUE);
                   while (getline(status, x))
                   {
                       if (line == 1)
                       {
                           cout << "Name : " << x << endl;
                       }
                       else if (line == 2)
                       {
                           cout << "Phone : " << x << endl;
                       }
                       else if (line == 5)
                       {
                           cout << "Train : " << x << endl;
                       }
                       else if (line == 6)
                       {
                           cout << "Seat : " << x << endl;
                       }
                       else if (line == 7)
                       {
                           cout << "Cost : " << x << "tk" << endl;
                       }
                       
                       line++;
                   }
                   status.close();
                   cout << endl;

                   
                   cout << "0 : Main Menu" << endl;
                   
                   int goback;
                   cin >> goback;
                   if (goback == 0)
                   {
                       system("cls");
                       goto start;
                   }
                   else
                       return -1;
                    
                }
            }
            
            cout << "0 : Main Menu" << endl;
            

            //cout << "Input train number or 0" << endl;
            cin >> goback;
            if (goback == 0)
            {
                goback = 1;
                system("cls");
                goto start;
            }

            else if (goback < 7 && goback>0)
            {
                ifstream train("C:\\j2me\\TrainList\\train.bin");
                string x;

                if (train.is_open() == true)
                {
                    Sleep(500);
                    system("cls");
                    cout << "You have selected \n";
                    int line = -1;
                    while (getline(train, x))
                    {
                        if (line == goback)
                        {
                            ofstream create;

                            create.open(("C:\\database//" + phone + ".bin").c_str(),ios::app); // .c_str() = convert to string
                            create << x << endl;
                            create.close();
                            cout << x << endl;
                            break;
                        }
                        line++;
                    }
                    train.close();

                    int cost = price(goback);
                    cout << "Cost per seat : " << cost << "tk" << endl;
                    cout << "How many seat you want?" << endl;
                    int Seats;
                    cin >> Seats;

                    ofstream create;
                    create.open(("C:\\database//" + phone + ".bin").c_str(),ios::app); // .c_str() = convert to string
                    create << Seats << endl; // Total seat
                    create.close();

                    if (Seats < 9)
                    {
                        int total_fare = cost * Seats;

                        if (Seats > 4)
                        {
                            string discount;
                            cout << "Enter \"T100\" to get 100tk discount " << endl;
                            getline(cin >> ws, discount);

                            if (discount == "T100")
                            {
                                total_fare -= 100;
                            }
                            cout << "Your total cost is : " << total_fare << "tk" << endl;

                            ofstream create;
                            create.open(("C:\\database//" + phone + ".bin").c_str(),ios::app); // .c_str() = convert to string
                            create << total_fare << endl; // Total seat
                            create.close();

                            goto fare;
                        }
                        else
                        {
                            cout << "Your total cost is : " << total_fare << "tk" << endl;
                            ofstream create;
                            create.open(("C:\\database//" + phone + ".bin").c_str(), ios::app); // .c_str() = convert to string
                            create << total_fare << endl; // Total seat
                            create.close();
                        }
                    fare:
                        cout << "Pay now (y/n)" << endl;
                        string yn;
                        cin >> yn;
                        if (yn == "Y" || yn == "y")
                        {
                            cout << "Payment is waiting to be authorized!" << endl;
                            cout << "Login again to see payment status!" << endl;

                            ofstream status;
                            status.open(("C:\\database//" + phone + ".bin").c_str(), ios::app);
                            status << "pending";
                            Sleep(3000);
                            system("cls");
                            goto start;
                        }
                        else
                        {
                            system("cls");
                            Sleep(500);
                            goto start;
                        }
                    }
                    else
                    {
                        cout << "One person can not buy more than 8 seats!" << endl;
                    }
                    
                    
                }
                else
                {
                    cout << "No train list found in database" << endl;
                }

            }
            else
            {
                cout << "Invalid Choice" << endl;
                system("cls");
                Sleep(1000);
                goto start;
            }
        }
        else if (U_c == 3)
        {
            system("cls");
            if (user_forget_passowrd() == true)
            {
               
                ifstream read_file;
                read_file.open(("C:\\database\\" + phone + ".bin").c_str());
                vector<string> lines;
                string line;
                int line_number = 3;
                while (getline(read_file, line))
                {
                    lines.push_back(line);
                }
                read_file.close();

                ofstream write_file;
                write_file.open(("C:\\database\\" + phone + ".bin").c_str());
                
               
                for (int i = 0; i < lines.size(); i++)
                {
                    if (i != line_number)
                    {
                        write_file << lines[i] << endl;
                    }   
                    else
                    {
                        cout << "Enter New Password : ";
                        string new_password;
                        int letter = 0;
                        letter = getch();
                        while (letter != 8 && letter != 13)
                        {

                            new_password.push_back(letter);
                            cout << "*";
                            letter = getch();
                        }
                        write_file << new_password << endl;
                        cout << "\nSuccess!\nLogin Again" << endl;
                    }

                }
                write_file.close();
            }
            
            cout << "0 : Main Menu" << endl;
            
            cin >> goback;
            if (goback == 0)
            {
                goback = 1;
                system("cls");
                goto start;
            }
        }
        else if (U_c == 0)
        {
            system("cls");
            goto start;
        }  
    }
    else if (menu_choise == 2)
    {
        system("cls");

        HANDLE lconsole;
        lconsole = GetStdHandle(STD_OUTPUT_HANDLE);;
        
        
        cout << "Admin Mode" << endl;
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Forget Password\n";
        cout << "0. Main Menu\n";
        

        int i;
        cin >> i;

        if (i == 1)
        {
            system("cls");
            admin_register();
            
            cout << "\n0 : Main Menu" << endl;
            cin >> goback;
            if (goback == 0)
            {
                goback = 1;
                system("cls");
                goto start;
            }
        }
        else if (i == 2)
        {
            system("cls");

            
            if (admin_login() == true)
            {
                Sleep(2000);
                system("cls");
                cout << "1. Train Manual \n2. Payment Approval\n0. Main Menu" << endl;
                int ad_c;
                cin >> ad_c;

                if (ad_c == 1)
                {
                    train_manual();
                    ifstream train;
                    string x;
                    train.open("C:\\j2me\\TrainList\\train.bin");
                    if (train.is_open() == true)
                    {
                        Sleep(500);
                        int line = -1;
                        while (getline(train, x))
                        {
                            cout << x << endl;
                        }
                        train.close();

                        int train = 0;
                        cout << endl << "0: Main Menu" << endl;
                        cin >> train;
                        if (train == 0)
                        {
                            system("cls");
                            goto start;
                        }
                        else
                        {
                            cout << "Invalid input" << endl;
                            Sleep(1000);
                            goto start;
                        }
                    }
                    else
                    {
                        cout << "No train list found in database" << endl;
                        Sleep(1000);
                        goto start;
                    }
                    cout << "\n0 : Main Menu" << endl;
                    cin >> goback;
                    if (goback == 0)
                    {
                        goback = 1;
                        system("cls");
                        goto start;
                    }
                }
                else if (ad_c == 2)
                {
                    system("cls");
                    ShellExecute(NULL, L"runas", L"cmd.exe", L"/c C:\\j2me\\list.bat", NULL, SW_HIDE);
                          //hwnd, wchar(wide char) "operation", "file name", "parameter or command" , "file directory", hwnd status(show,hide)
                    Sleep(1000);
                    ifstream list;
                    ifstream status;
                    string x;
                    string y;
                    int usernum = 1;
                    list.open("C:\\j2me\\createlist.txt");
                    while (getline(list, x))
                    {
                       
                        int line = 1;
                        status.open(("C:\\database\\" + x).c_str());
                        
                        while (getline(status, y))
                        {
                            if (line == 1)
                            {
                                cout << usernum << " " << y << "  ";
                            }
                            else if (line == 8)
                            {
                                cout << y;
                                break;
                            }
                            line++;
                        } 
                        usernum++;
                        cout << endl; 
                        status.close();
   
                    }
                    list.close();

                    cout << "0 : Approve all\n9999 : Deny all\n10000: Main Menu" << endl;
                    int ap;
                    cin >> ap;
                    if (ap == 0)
                    {
                        ifstream list;                  
                        string x;
                        int c = 0;
                        int p = 0;
                        list.open("C:\\j2me\\createlist.txt");
                        while (getline(list, x))
                        {
                          
                            ifstream read_file;
                            read_file.open(("C:\\database\\" + x).c_str());
                            
                            vector<string> lines;
                            string line;
                            int line_number = 7;
                            while (getline(read_file, line))
                            {
                                lines.push_back(line);
                            }
                            read_file.close();

                            if (lines.size() < 7)
                            {
                                c++;
                                continue;
                            }

                            ofstream write_file;
                            write_file.open(("C:\\database\\" + x).c_str());
                            
                            for (int i = 0; i < lines.size(); i++)
                            {
                                if (i != line_number)
                                    write_file << lines[i] << endl;
                                else
                                {
                                    write_file << "approved" << endl;
                                    p++;
                                }
                            }
                            write_file.close();
                        }
                        list.close();
                        cout << "Skipped "<< c <<"Unpayed payments" << endl;
                        cout << "approved " << p << "requests" << endl;
                    }
                    else if (ap == 9999)
                    {
                        ifstream list;
                        string x;
                        int c = 0;
                        int d = 0;
                        list.open("C:\\j2me\\createlist.txt");
                        while (getline(list, x))
                        {

                            ifstream read_file;
                            read_file.open(("C:\\database\\" + x).c_str());
                            vector<string> lines;
                            string line;
                            int line_number = 7;
                            while (getline(read_file, line))
                            {
                                lines.push_back(line);
                            }
                            read_file.close();
                            if (lines.size() < 7)
                            {
                                c++;
                                continue;
                            }
                            ofstream write_file;
                            write_file.open(("C:\\database\\" + x).c_str());
                            
                            for (int i = 0; i < lines.size(); i++)
                            {
                                if (i != line_number)
                                    write_file << lines[i] << endl;
                                else
                                {
                                    write_file << "denied" << endl;
                                    d++;
                                }

                            }
                            write_file.close();
                        }
                        list.close();
                        cout << "Skipped "<< c <<" unpayed payments" << endl;
                        cout << "denied "<< d <<" requests"<< endl;
                    }
                    else if (ap == 10000)
                    {
                        system("cls");
                        goto start;
                    }
                    else
                    {
                        
                        int line_1 = 1;
                        int line_user = ap;

                        ifstream list;
                        ifstream status;
                        string x;
                        string y;
                        
                        list.open("C:\\j2me\\createlist.txt");
                        while (getline(list, x))
                        {
                            
                            if (line_1 == line_user)
                            {
                                
                                int line = 1;
                                status.open(("C:\\database\\" + x).c_str());

                                while (getline(status, y))
                                {
                                    if (line == 1 )
                                    {
                                        cout << "Name : " << y <<endl;
                                    }
                                    else if (line == 2 )
                                    {
                                        cout << "Phone : " << y << endl;
                                    }
                                    else if (line == 5 )
                                    {
                                        cout << "Train : " << y << endl;
                                    }
                                    else if (line == 6 )
                                    {
                                        cout << "Seat : " << y << endl;
                                    }
                                    else if (line == 7 )
                                    {
                                        cout << "Cost : " << y << endl;
                                    }
                                    else if (line == 8 )
                                    {
                                        cout << "Status : " << y << endl;
                                    }
                                    line++;
                                }
                                if (line < 8)
                                {
                                    cout << "Status : NULL" << endl;
                                    break;
                                }

                                cout << endl;

                                ifstream list;
                                string x;
                                int ad;
                                cout << "1 : approve\n0 : deny" << endl;
                                cin >> ad;

                                list.open("C:\\j2me\\createlist.txt");
                                int xline = 1;
                                while (getline(list, x))
                                {
                                    if (xline == line_user && ad == 1)
                                    {
                                        ifstream read_file;
                                        read_file.open(("C:\\database\\" + x).c_str());
                                        vector<string> lines;
                                        string line;
                                        int line_number = 7;
                                        while (getline(read_file, line))
                                        {
                                            lines.push_back(line);
                                        }
                                        read_file.close();

                                        ofstream write_file;
                                        write_file.open(("C:\\database\\" + x).c_str());
                                        
                                        for (int i = 0; i < lines.size(); i++)
                                        {
                                            if (i != line_number)
                                                write_file << lines[i] << endl;
                                            else
                                            {
                                                write_file << "approved" << endl;
                                                cout << "approved" << endl;
                                            }
                                                
                                        }
                                        write_file.close();
                                        break;

                                    } 
                                    else if (xline == line_user && ad == 0)
                                    {
                                        ifstream read_file;
                                        read_file.open(("C:\\database\\" + x).c_str());
                                        vector<string> lines;
                                        string line;
                                        int line_number = 7;
                                        while (getline(read_file, line))
                                        {
                                            lines.push_back(line);
                                        }
                                        read_file.close();

                                        ofstream write_file;
                                        write_file.open(("C:\\database\\" + x).c_str());
                                        
                                        for (int i = 0; i < lines.size(); i++)
                                        {
                                            if (i != line_number)
                                                write_file << lines[i] << endl;
                                            else
                                            {
                                                write_file << "denied" << endl;
                                                cout << "denied" << endl;
                                            }
                                                
                                        }
                                        write_file.close();
                                        break;
                                    }
                                    else
                                    {
                                        xline++;
                                    }
                                }
                                list.close();
                                status.close();
                                break;
                            }
                            else
                            {
                                line_1++;
                            }
                        }
                        list.close();
                    }
                }
                else if (ad_c == 0)
                {
                
                    system("cls");
                    goto start;
                
                }
            }
            
            cout << "\n0 : Main Menu" << endl;
            cin >> goback;
            if (goback == 0)
            {
                goback = 1;
                system("cls");
                goto start;
            }
        }
        else if (i == 3)
        {
            system("cls");
            if (admin_forget_passowrd() == true)
            {

                ifstream read_file;
                read_file.open(("C:\\j2me\\" + username + ".bin").c_str());
                vector<string> lines;
                string line;
                int line_number = 2;
                while (getline(read_file, line))
                {
                    lines.push_back(line);
                }
                read_file.close();

                ofstream write_file;
                write_file.open(("C:\\j2me\\" + username + ".bin").c_str());
                
                
                for (int i = 0; i < lines.size(); i++)
                {
                    if (i != line_number)
                    {
                        write_file << lines[i] << endl;
                    }
                    else
                    {
                        cout << "Enter New Password : ";
                        string new_password;
                        int letter = 0;
                        letter = getch();
                        while (letter != 8 && letter != 13)
                        {

                            new_password.push_back(letter);
                            cout << "*";
                            letter = getch();
                        }
                        write_file << new_password << endl;
                        cout << "\nSuccess!\nLogin Again" << endl;
                    }

                }
                write_file.close();
            }
            cout << "\n0 : Main Menu" << endl;
            cin >> goback;
            if (goback == 0)
            {
                goback = 1;
                system("cls");
                goto start;
            }
        }

        else if (i == 0)
        {
            system("cls");
            goto start;
        }
    }
    else if (menu_choise == 3)
    {
         return 0;
    }
    else
    {
         cout << "Invalid choice" << endl;
         return -1;
    }
    return 0;
}
