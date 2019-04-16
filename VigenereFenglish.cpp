#include <iostream>
#include <string>
using namespace std;
string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string key = "AIRAUMFERAE", plaintext;
int c,d,f;
int main()
{
  cin>>plaintext;
  cout<<endl<<endl;
  for(int i=0; i<plaintext.size(); i++)
  {
    for(int j=0; j<26; j++)
    {
      if(plaintext[i] == alphabet[j])
      {
        for(int b=0; b<26; b++)
         if(key[i%11] == alphabet[b]) c=b;
         cout<<alphabet[(j+c)%26];
      }
    }
  }
  cout<<endl<<endl;
  for(int i=0; i<plaintext.size(); i++)
  {
    for(int j=0; j<26; j++)
    {
      if(plaintext[i] == alphabet[j] && plaintext[i] != 'F')
      {
        for(int b=0; b<26; b++)
         if(key[f%11] == alphabet[b]) c=b;
         cout<<alphabet[(j+c)%26];
      }
      if(plaintext[i] == 'F') {cout<<'F'; break;}
    }
    f++;
  }
}
