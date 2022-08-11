#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <iomanip>
#include <cmath>

void System_main_Display();
bool Chechk_File_Content(std::string fileName, std::vector<std::string>& Str);

int main()
{
    std::string Defined_Operation;
    int errorcounter = 1;
    int errorcounter1 = 1;
    std::string want_or_not = "";

    std::ifstream MainFile("names.txt");
    std::vector<std::string>Str;
    bool result = Chechk_File_Content("names.txt", Str);
    System_main_Display();
    do {
        std::cout << "\n\n\t\t Your Wanted Operation : ";    std::cin >> Defined_Operation;

        std::for_each(Defined_Operation.begin(), Defined_Operation.end(), [](char& c) {
            c = ::tolower(c);
            });

            // list
            // sort
            // keyword
            // filter
            // backup

        while (std::cin.fail() || (Defined_Operation != "list" && Defined_Operation != "l" &&
            Defined_Operation != "sort" && Defined_Operation != "s" && Defined_Operation != "keyword" && Defined_Operation != "k" &&
            Defined_Operation != "filter" && Defined_Operation != "f" && Defined_Operation != "backup" && Defined_Operation != "b" &&
            errorcounter != 3) )
        {
            errorcounter++;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "\a\tInvalid Operation " << std::endl;
            std::cout << "\t" << 3 - errorcounter << " attempts remaining ";
            std::cout << "\tPlease\, Prompt The Operation here Again : "; std::cin >> Defined_Operation;
        }
        if (errorcounter == 3)
        {
            std::cout << "\a\tInvalid Input for Three times , Program Stops Execution here :( " << std::endl;
            exit(1);
        }
        if (Defined_Operation == "backup" || Defined_Operation == "b")
        {
            system("cls");
            std::string name = "";
            std::cout << "Name The file You want to Create to backup the data : "; std::cin >> name;
            std::ofstream Backup{ name };
            

            std::string line;   
            char string1[256], string2[256];
            int it = 0, Different_words_counter = 0;
            

            if (Backup.is_open())
            {
                    if (MainFile && Backup) {
                        while (getline(MainFile, line)) {
                            Backup << line << std::endl;
                        }
                    }
                    while (!MainFile.eof())
                    {
                        std::ifstream Backup{ "Backup_file.txt" };
                        MainFile.getline(string1, 256);
                        Backup.getline(string2, 256);
                        it++;
                        if (strcmp(string1, string2) != 0)
                        {
                            Different_words_counter++;
                        }
                    }
                    if (Different_words_counter > 0)
                    {
                        std::cout << "\tData Backed up Successfully " << std::endl;
                    }
                    else {
                        std::cout << "\tSuch file is created already and it has the same content as  main(name.txt file) has,\n\t Wanna Overwrite to it ? Type '1' if yes else Press Anything else ";
                        int yes_or_no = 0;
                        std::cin >> yes_or_no;
                        if (yes_or_no == 1)
                        {
                            while (getline(MainFile, line)) {
                                Backup << line << '\n';
                            }
                            std::cout << "\t Data overwrited Successfully  " << std::endl;
                            Backup.close();
                        }
                        std::cin.clear();
                        std::cin.ignore(1000000,'\n');
                    }
                }
            else {
                std::cout << "\aOops ..  Something went Wrong Can't Create a backup file " << std::endl;
            }
            MainFile.close();
            Backup.close();
        }
        else if (Defined_Operation == "list" || Defined_Operation == "l")
        {
           system("cls");
           std::cout<<"\t\tooooo         o8o               .   "  <<std::endl;
           std::cout<<"\t\t`888'         `\"'             .o8   "  <<std::endl;
           std::cout<<"\t\t 888         oooo   .oooo.o .o888oo "  <<std::endl;
           std::cout<<"\t\t 888         `888  d88(  \"8   888   "  <<std::endl;
           std::cout<<"\t\t 888          888  `\"Y88b.    888   "   <<std::endl;
           std::cout<<"\t\t 888       o  888  o.  )88b   888 . "    <<std::endl;
           std::cout<< "\t\to888ooooood8 o888o 8""888P'   \"888\" " << std::endl;
      
             if (result)
             {
                 int Upper_Boud = 0;
                 std::cout << "There are " << Str.size() << " Names in the list How many Customers You want To see. Type the Number here : "; std::cin >> Upper_Boud;
                 
                 if (Upper_Boud > 0) {
                     std::cout << "+---+------+------+------+------+------+---+" << std::endl;
                     std::cout << "|N  |   Names     |   N  |   Names         |" << std::endl;
                     std::cout << "+---+------+------+------+------+------+---+" << std::endl;
                     for (int n = 1; n <= Upper_Boud; ++n)
                     {
                         while (true) {
                             if (n <= Upper_Boud) {
                                 std::cout << std::setw(4) << std::setprecision(4) << n << "\t" << Str[n - 1] << "\t";
                             }
                             break;
                         }
                         if (n % 2 == 0) {
                             std::cout << std::endl;
                         }

                     }
                 }
                 else {
                     std::cout << "\t\t\t  No Customers Found";
                 }
                 
                  
             }
        }
        else if (Defined_Operation == "sort" || Defined_Operation == "s")
        {
            sort(Str.begin(), Str.end());
            system("cls");
                                                       
            std::cout << " \ .-\-\.--\.  \  \    \   \               ___  "<< std::endl;
            std::cout<<" \/  \/\   \ '.\  \    \   \             ,--.'|_  "<<std::endl; 
            std::cout<<"|\  :\ \ /`\. /\  \  ,-\--.\    __  ,-.  |  | :,' "<<std::endl; 
            std::cout<<";\  |\ \ |-\-` \  \ '  \ ,'\\ ,' ,'/ /|  :  : ' : "<<std::endl; 
            std::cout<<"|\  :\ \ ;_\   \  \/   \/  \ |'  | |' |.;__,'  /  "<<std::endl; 
            std::cout<<" \\  \\\   \ `.\ .\   ;\ ,.\ :|  |   ,'|  |   |   "<<std::endl; 
            std::cout<<" \ `-\-\--.\   \\'\   |\ |:\ :'  :  /  :__,'| :   "<<std::endl; 
            std::cout<<" \ __\ \\  \\  \|'\   |\ .;\ :|  | '     '  : |__ "<<std::endl; 
            std::cout<<" \/  \/\`--\'  \/|\   :\   \ |;  : |     |  | '.'|"<<std::endl; 
            std::cout<<"'\--'\.\   \  /\  \\   \\  \/ |  , ;     ;  :    ;"<<std::endl; 
            std::cout<<" \ `-\-\'--\-' \  \ `--\--'\   ---'      |  ,   / "<<std::endl; 
            std::cout<<" \   \ \   \   \  \    \   \              ---`-'  "<<std::endl; 

            int Upper_Boud = Str.size();
      

            for (int n = 1; n <= Upper_Boud; ++n)
            {
                while (true) {
                    if (n <= Upper_Boud) {
                        std::cout << std::setw(4) << std::setprecision(4) << n << "\t" << Str[n - 1] << "\t";
                    }
                    break;
                }
                if (n % 5 == 0) {
                    std::cout << std::endl;
                }

            }
        }
        else if (Defined_Operation == "keyword" || Defined_Operation == "k")
        {
        system("cls");
        std::cout << " .---------\--\-----.  .----------\------.  .----\-\-\-\---------.  .--------\-\-------.  .---\---------\----.  .---------\-\-\-----.  .-------------\---. " << std::endl;
        std::cout << "| .--------\--\----. || .---------\-----. || .---\-\-\-\--------. || .-------\-\------. || .--\---------\---. || .--------\-\-\----. || .------------\--. |" << std::endl;
        std::cout << "| |  ___  _\__\_   | || |  _______\__   | || |  _\_\_\_\  ____  | || | _____ \ \_____ | || |  \   ____  \   | || |  ______\_\ \    | || |  ________  \  | |" << std::endl;
        std::cout << "| | |_  ||_\  \_|  | || | |_   ___\  |  | || | |_\ \ \_\||_  _| | || ||_   _|\|\_   _|| || |  \ .'    `.\   | || | |_   __\ \\\    | || | |_   ___ `.\  | |" << std::endl;
        std::cout << "| |   | |_/\ /\    | || |   | |_  \\_|  | || |   \\\ \\\  / /   | || |  | | /\\\ | |  | || |  \/  .--.  \\  | || |   | |__\)\ \|   | || |   | |   `. \\ | |" << std::endl;
        std::cout << "| |   |  __\'.\    | || |   |  _| \ _   | || |   \ \\\ \\/ /    | || |  | |/ \ \\| |  | || |  \| |    | \|  | || |   |  __\ \/\    | || |   | |    | \| | |" << std::endl;
        std::cout << "| |  _| |  \\ \\_  | || |  _| |___\/ |  | || |   \ \_\|\  |_    | || |  |   /\\\   |  | || |  \\  `--'  \/  | || |  _| |  \\\ \\_  | || |  _| |___.' \/ | |" << std::endl;
        std::cout << "| | |____||\__\__| | || | |_______\__|  | || |   \|\_\_\____|   | || |  |__/ \ \\__|  | || |  \ `.____.'\   | || | |____| \|\_\__| | || | |________.'\  | |" << std::endl;
        std::cout << "| |        \  \    | || |         \     | || |   \ \ \ \        | || |       \ \      | || |  \         \   | || |        \ \ \    | || |            \  | |" << std::endl;
        std::cout << "| '--------\--\----' || '---------\-----' || '---\-\-\-\--------' || '-------\-\------' || '--\---------\---' || '--------\-\-\----' || '------------\--' |" << std::endl;
        std::cout << " '---------\--\-----'  '----------\------'  '----\-\-\-\---------'  '--------\-\-------'  '---\---------\----'  '---------\-\-\-----'  '-------------\---' " << std::endl;


            std::string name;
            std::cout << "Input The KeyWord here :  ";  std::cin >> name;

            int Count = std::count(Str.begin(), Str.end(), name) ;
            if (Count > 0) {
                std::cout << "\tThere is Found " << Count << " Result" << std::endl;
            }
            else if (Count == 0)
            {
                std::cout << "There is nothing like this Here Unfortunately " << std::endl;
            }
        }
        else if (Defined_Operation == "filter" || Defined_Operation == "f")
        {
            system("cls");
                        std::cout<<"     ***** **            ***                                      "<<std::endl;
                        std::cout<<"  ******  **** *   *      ***        *                            "<<std::endl;
                        std::cout<<" **   *  *  ***   ***      **       **                            "<<std::endl;
                        std::cout<<"*    *  *    *     *       **       **                            "<<std::endl;
                        std::cout<<"    *  *                   **     ********           ***  ****    "<<std::endl;
                        std::cout<<"   ** **         ***       **    ********     ***     **** **** * "<<std::endl;
                        std::cout<<"   ** **          ***      **       **       * ***     **   ****  "<<std::endl;
                        std::cout<<"   ** ******       **      **       **      *   ***    **         "<<std::endl;
                        std::cout<<"   ** *****        **      **       **     **    ***   **         "<<std::endl;
                        std::cout<<"   ** **           **      **       **     ********    **         "<<std::endl;
                        std::cout<<"   *  **           **      **       **     *******     **         "<<std::endl;
                        std::cout<<"      *            **      **       **     **          **         "<<std::endl;
                        std::cout<<"  *****            **      **       **     ****    *   ***        "<<std::endl;
                        std::cout<<" *  *****          *** *   *** *     **     *******     ***       "<<std::endl;
                        std::cout<<"*    ***            ***     ***              *****                "<<std::endl;
                        std::cout<<"*                                                                 "<<std::endl;
                        std::cout<<" **                                                               "<<std::endl;
          
            std::string line;
            std::string name;
            int count = 0;


            std::cout << "Input The KeyWord To find Substrings :  "; std::cin >> name;
            while (getline(MainFile, line))
            {
                if (line.find(name) != std::string::npos) {
                    std::cout << " #"<<count+1<<"  |   " << line << '\n';  
                    count += 1;
                }
            }
            if (count > 0)
            {
                std::cout << "We found " << count-1 << " Searching results In Total" << std::endl;
                
            }
            else if (count == 0)
            {
                std::cout << "No substrings Found For Prompted Keyword" << std::endl;
            }
        }
        if (errorcounter != 3)
        {

            std::cout << "\n\tDo you want to continue ?  Please Type \'y\' or \'yes\' ,\'1\' is welcomed as well ,But in else cases Type anything else " << std::endl;
            std::cout << "\tYour answer  here : "; std::cin >> want_or_not;
            std::for_each(want_or_not.begin(), want_or_not.end(), [](char& c) {
                c = ::tolower(c);
                });
            while (std::cin.fail() && (want_or_not != "y" || want_or_not != "yes" || want_or_not != "1") && errorcounter1 != 2)
            {
                errorcounter1++;
                std::cout << "Invalid Input " << std::endl;
                std::cout << 3 - errorcounter1 << " attempts remaining" << std::endl;
                std::cin.clear();
                std::cin.ignore(100000, '\n');
                std::cout << "Please Provide again : "; std::cin >> want_or_not;
            }
            if (errorcounter1 == 2)
            {
                std::cout << "\t I hope We meet each other Again,Now I have to say goodbye" << std::endl; break;
            }
            if (want_or_not == "y" || want_or_not == "yes" || want_or_not == "1")
            {
                system("cls");
                System_main_Display();
            }
            else 
            {
                std::cout << "\tOkay , Goodbye then I hope we meet each other again " << std::endl; break;
            }
        }
        else { break; }
    } while ((errorcounter != 3 || errorcounter1 != 2) && want_or_not != "y" || want_or_not != "yes" || want_or_not != "1");
   // std::cout << "Program Stops Execution Here ";
    system("pause>0");
    return 0;
}

void System_main_Display() {

    static int count = 0;


std::cout<<" .----------------. .----------------. .----------------. .----------------.                                                                             \n";
std::cout<<"| .--------------. | .--------------. | .--------------. | .--------------. |                                                                            \n";
std::cout<<"| |  ________    | | |      __      | | |  _________   | | |      __      | |                                                                            \n";
std::cout<<"| | |_   ___ `.  | | |     /  \\     | | | |  _   _  |  | | |     /  \\     | |                                                                            \n";
std::cout<<"| |   | |   `. \\ | | |    / /\\ \\    | | | |_/ | | \\_|  | | |    / /\\ \\    | |                                                                            \n";
std::cout<<"| |   | |    | | | | |   / ____ \\   | | |     | |      | | |   / ____ \\   | |                                                                            \n";
std::cout<<"| |  _| |___.' / | | | _/ /    \\ \\_ | | |    _| |_     | | | _/ /    \\ \\_ | |                                                                            \n";
std::cout<<"| | |________.'  | | ||____|  |____|| | |   |_____|    | | ||____|  |____|| |                                                                            \n";
std::cout<<"| |              | | |              | | |              | | |              | |                                                                            \n";
std::cout<<"| '--------------' | '--------------' | '--------------' | '--------------' |                                                                            \n";
std::cout<<" .----------------. .-----------------..----------------. .----------------. .----------------. .----------------. .----------------. .----------------. \n";
std::cout<<"| .--------------. | .--------------. | .--------------. | .--------------. | .--------------. | .--------------. | .--------------. | .--------------. |\n";
std::cout<<"| |      __      | | | ____  _____  | | |      __      | | |   _____      | | |  ____  ____  | | |   ________   | | |  _________   | | |  _______     | |\n";
std::cout<<"| |     /  \\     | | ||_   \\|_   _| | | |     /  \\     | | |  |_   _|     | | | |_  _||_  _| | | |  |  __   _|  | | | |_   ___  |  | | | |_   __ \\    | |\n";
std::cout<<"| |    / /\\ \\    | | |  |   \\ | |   | | |    / /\\ \\    | | |    | |       | | |   \\ \\  / /   | | |  |_/  / /    | | |   | |_  \\_|  | | |   | |__) |   | |\n";
std::cout<<"| |   / ____ \\   | | |  | |\\ \\| |   | | |   / ____ \\   | | |    | |   _   | | |    \\ \\/ /    | | |     .'.' _   | | |   |  _|  _   | | |   |  __ /    | |\n";
std::cout<<"| | _/ /    \\ \\_ | | | _| |_\\   |_  | | | _/ /    \\ \\_ | | |   _| |__/ |  | | |    _|  |_    | | |   _/ /__/ |  | | |  _| |___/ |  | | |  _| |  \\ \\_  | |\n";
std::cout<<"| ||____|  |____|| | ||_____|\\____| | | ||____|  |____|| | |  |________|  | | |   |______|   | | |  |________|  | | | |_________|  | | | |____| |___| | |\n";
std::cout<<"| |              | | |              | | |              | | |              | | |              | | |              | | |              | | |              | |\n";
std::cout<<"| '--------------' | '--------------' | '--------------' | '--------------' | '--------------' | '--------------' | '--------------' | '--------------' |\n";
std::cout<<" '----------------' '----------------' '----------------' '----------------' '----------------' '----------------' '----------------' '----------------' \n";


if (count = 0) {
        std::cout << "\nWelcome To Data Analyzer Please feel free to choose one of Operations on The Table\n" << std::endl;
        count++;
}



std::cout<<"+-------------------------+--------------------------------------------------------+"<<std::endl;
std::cout<<"|  If You Provide         |                     Then we do the following           |"<<std::endl;
std::cout<<"+-------------------------+--------------------------------------------------------+"<<std::endl;
std::cout<<"| list      (l)           |  Lists all the element from File                       |"<<std::endl;
std::cout<<"| sort      (s)           | Sort names by ascending order(A - Z)                   |"<<std::endl;
std::cout<<"| keyword   (k)           | Traverses the number of Keyword be found into a File   |"<<std::endl;
std::cout<<"| filter    (f)           | Traverses  all the Substrings of the following Strings |"<<std::endl;
std::cout<<"| backup    (b)           | Creates a backup - file for corresponding file         |"<<std::endl;
std::cout<<"+-------------------------+--------------------------------------------------------+"<<std::endl;
}
bool Chechk_File_Content(std::string fileName, std::vector<std::string>& Str)
{
    std::ifstream MainFile(fileName.c_str());
    if (!MainFile)
    {
        std::cerr << "\a\n\t -->Something went Wrong Please check the file  " << std::endl; return false;
    }
    std::string str;
    while (getline(MainFile, str))
    {
        if (str.size() > 0)
        {
            Str.push_back(str);
        }
    }
    MainFile.close(); return true;
}