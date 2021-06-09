#include <iostream>
#include <string>
#include <array>
using namespace std;

string olimp(string l)
{
    string a, n;
    int mas[7000],A,N,len,ost=0;
    a = l.substr(0, l.find(' ', 0));
    n = l.substr(l.find(' ', 0) + 1);// разделение строки
    A = stoi(a);
    N = stoi(n);//преобразование в инт
    if (N == 1) {
        return to_string(A);//частный случий при n=1
    }
    mas[0] =1;
    len = 1;
    for (int i = 0; i < N; i++)
    {
        ost = 0;
        for (int j = 0; j < len; j++)
        {
            ost = ost + mas[j] * A;
            mas[j] = ost % 10;//запись в массив
            ost = ost / 10;//опредение остатка
        }
        if (ost != 0)
        {
            
            mas[len] = ost;
            len++;
        }
    }
    a = "";
    for (int i = len-1; i >= 0; i--)
    {
        a += to_string(mas[i]);
    }
    return a;
    


}

    
 
int main()
{
    freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
    string x;
    getline(cin, x);
    cout << olimp(x);
    return 0;

}
