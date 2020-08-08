#include <iostream>
#include "cstring"
#include "fstream"
using namespace std;
const int num=255;
class Myclass
{
public:
  Myclass();
  Myclass(string pt, int len,string pathww);
  void readStruct();
  void printStruct();
  void findStruct();
  void writeStruct();
  void setPath(string pt);
  string getPath();
  void setPathw(string pt);
  string getPathw();
private:
  string path;
  string pathw;
  int lenght;
  string text;
  char *a1_darr;
  double summ;
  int strok;
};

int main()
{
//setlocale(LC_ALL, "Russian");
Myclass c1;
int inputt=0;
while(inputt!=6)
{
  cout<<"Для чтения структуры нажмите 1"<<endl;
  cout<<"Для нахождения средней стоимости, нажмите 2"<<endl;
  cout<<"Для записи в файл , нажмите 4"<<endl;
  cout<<"Для вывода содержимого , нажмите 5"<<endl;
  cout<<"Для выхода , нажмите 6"<<endl;
  cin>>inputt;
  if(inputt==1)
  c1.readStruct();
  if(inputt==2)
  c1.findStruct();
  if(inputt==4)
  c1.writeStruct();
  if(inputt==5)
  c1.printStruct();
cout<<"______"<<endl;

};
Myclass::Myclass()
{
  path="text.txt";
  lenght=4;
  strok=0;
  text="";
  a1_darr=new char [num];
  summ=0;
  pathw="rrr.txt";
};
Myclass::Myclass(string pt, int len,string pathww)
{
  path=pt;
  lenght=len;
  strok=0;
  text="";
  a1_darr=new char [num];
  summ=0;
  pathw=pathww;
};
void Myclass::readStruct()
{
  ifstream fin(path);
  char ch=fin.get();
  int f=0,g=0;
  while(ch != EOF)
    {
      while(ch != '\n')
      {
        a1_darr[f]=char(ch);
        ch=fin.get();
        f++;
      }
      g++;
      a1_darr[f]='\n';
      f++;
      ch=fin.get();
    }
};
void Myclass::printStruct()
{
        cout<<a1_darr;
  cout<<"______"<<endl;
};
void Myclass::writeStruct()
{
  ofstream fs;
  fs.open(pathw);
  fs<<a1_darr;
  fs.close();
};
void Myclass::findStruct()
{
    int j=0,jold=0;
    string t="";
    bool k=1;
  while(j<255)
    {
      if((int(a1_darr[j])>=48)&&(int(a1_darr[j])<=57)&&(k!=0))
      {
        t+=a1_darr[j];
      }
      else
      if((int(a1_darr[j])==32)&&(t!=""))
      {
        k=0;
        summ+=atoi(t.c_str());
        t="";

      }
      if(a1_darr[j]=='\n')
      {
        k=1;
      }
    j++;
  }

cout<<"Среднее значение: "<<summ/3<<endl;
};
void Myclass::setPath(string pt)
{
  path=pt;
}
string Myclass::getPath()
{
  return path;
}
void Myclass::setPathw(string pt)
{
  pathw=pt;
}
string Myclass::getPathw()
{
  return pathw;
}
