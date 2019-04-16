#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int s;
string Runes[29] = {"ᚠ","ᚢ","ᚦ","ᚩ","ᚱ","ᚳ","ᚷ","ᚹ","ᚻ","ᚾ","ᛁ","ᛂ","ᛇ","ᛈ","ᛉ","ᛋ","ᛏ","ᛒ","ᛖ","ᛗ","ᛚ","ᛝ","ᛟ","ᛞ","ᚪ","ᚫ","ᚣ","ᛡ","ᛠ"};
int main()
{
  cin>>s;
  srand(time(0));
  for(int i=0; i<s; i++)
  cout<<Runes[rand()%29];
}
