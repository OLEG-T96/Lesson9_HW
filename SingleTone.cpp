#include <iostream>
#include <string>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std:: string;

class Singletone
{
    Singletone(const Singletone &) = delete;
    Singletone & operator= (const Singletone &) = delete;

private:
    std::ofstream file;

    Singletone() 
      {
        file.open("log.txt");
        if(!file.is_open())
          {
            cout<< "Can not create file" << endl;
            exit(0);
          }
      }

public:
    static Singletone &Create()
      {
        static Singletone log;
        return log;
      }

    void WriteLog(const char *log)
      {
        if(log != nullptr)
          {
            file << "> "<< log << "\n";
          }
      }
};

int main()
{
   auto &log  = Singletone::Create();

   cout<<"Type 'quit' to finish the program\n\n" <<">";
   string str;
   getline(cin,str);
   while(str != "quit")
     {
        log.WriteLog(str.c_str());
        cout<<">";
        getline(cin,str);
     }

    return 0;
}
