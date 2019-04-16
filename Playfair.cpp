#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<stack>
#include <cstdlib>
#include <ctime>
using namespace std;
string Text;
stack<int> Transcription; 
int RunesPos[10000];
vector<int> PlaintextV;
pair<string,int> SingleRunes[24] = {{"F",0},{"U",1},{"R",4},{"C",5},{"K",5},{"G",6},{"W",7},{"H",8},{"N",9},{"I",10},{"J",11} ,{"P",13},{"X",14},{"S",15},{"Z",15},{"T",16},{"B",17},{"E",18},{"M",19},{"L",20},{"D",23},{"A",24},{"Y",26},{"O",3}};
pair<string,int> DoubleRunes[8] = {{"TH",2},{"EO",12},{"NG",21},{"OE",22},{"AE",25},{"IA",27},{"IO",27},{"EA",28}};
pair<string,int> TripleRunes[1] = {{"ING",22}};
string Runes[30] = {"ᚠ","ᚢ","ᚦ","ᚩ","ᚱ","ᚳ","ᚷ","ᚹ","ᚻ","ᚾ","ᛁ","ᛂ","ᛇ","ᛈ","ᛉ","ᛋ","ᛏ","ᛒ","ᛖ","ᛗ","ᛚ","ᛝ","ᛟ","ᛞ","ᚪ","ᚫ","ᚣ","ᛡ","ᛠ","•"};
string plaintext,ciphertext;
int spaces[10000],pairs[2];
int a,b,c,d,e,f,g,h,k,l,m,n,o,q,r,s,t,u,v=1,x11,y11,x2,y2;
double p,ll;
 int Encoder1[5][5] = {{20,27,4,11,18},
                            {26,8,10,17,19},
                            {7,9,16,23,25},
                            {13,15,22,24,6},
                            {14,21,28,5,12}};
int excluded[4] = {25,26,27,28};
//int CalculateStatistics()
//{

//}
int EncodeText()
{
  for(int i=0; i<s; i++)
    PlaintextV.push_back(RunesPos[i+1]);
  k=0; q=0;
  while(k<s)
  {
   if(PlaintextV[m]==29) {PlaintextV.erase(PlaintextV.begin()+m); spaces[k]++; d++;}
    else m++; k++;
  }
  m=0;
  while(m<PlaintextV.size())
  {
    if(PlaintextV[m] == PlaintextV[m+1] && m+1 < s)
    PlaintextV.insert(PlaintextV.begin()+(m),6);
   m+=2;
  }
 if(PlaintextV.size()%2>0) PlaintextV.push_back(6);
 
 for(m=0; m<PlaintextV.size(); m+=2)
 {
   n=m; o=m+1;
   //Match The Runes in the encoder
   for(int i=0; i<5; i++)
   {
     for(int j=0; j<5; j++)
     {
       if(PlaintextV[n] == Encoder1[i][j])
         {y11=i; x11=j; q++;} 
       if(PlaintextV[o] == Encoder1[i][j])
         {y2=i; x2=j; q++;} 
     }
   }
   pairs[0] = PlaintextV[n]; pairs[1] = PlaintextV[o];
   //Rule 1
   if(x11 == x2 && q>1)
    {PlaintextV.erase(PlaintextV.begin()+n); PlaintextV.insert(PlaintextV.begin()+n,Encoder1[(y11+1)%5][x11]); PlaintextV.erase(PlaintextV.begin()+o); PlaintextV.insert(PlaintextV.begin()+o,Encoder1[(y2+1)%5][x11]);}
   //Rule 2
   if(y11 == y2 && q>1)
    {PlaintextV.erase(PlaintextV.begin()+n); PlaintextV.insert(PlaintextV.begin()+n,Encoder1[y11][(x11+1)%5]); PlaintextV.erase(PlaintextV.begin()+o); PlaintextV.insert(PlaintextV.begin()+o,Encoder1[y11][(x2+1)%5]);}
   //Rule 3
   if(y11 != y2 && x11 != x2 && q>1)
    {PlaintextV.erase(PlaintextV.begin()+n); PlaintextV.insert(PlaintextV.begin()+n, Encoder1[y11][x2]); PlaintextV.erase(PlaintextV.begin()+o); PlaintextV.insert(PlaintextV.begin()+o,Encoder1[y2][x11]);} 
  //if pairs match skip the bigram 
  if(n-1>0)
  if(PlaintextV[n] == PlaintextV[n-1]) {PlaintextV.erase(PlaintextV.begin()+n); PlaintextV.insert(PlaintextV.begin()+n, pairs[0]); PlaintextV.erase(PlaintextV.begin()+o); PlaintextV.insert(PlaintextV.begin()+o, pairs[1]); 
  int ds=rand()%29;
  for(int i=0; i<5; i++)
    for(int j=0; j<5; j++)
      {Encoder1[i][j]=((Encoder1[i][j]+ds)%29);}
      ds=0;
  } 
  q=0;
 } 
 for(int i=0; i<PlaintextV.size(); i++){
if(spaces[i] == 1) PlaintextV.insert(PlaintextV.begin()+i, 29);
 cout<<Runes[PlaintextV[i]]; if(i>1) if(PlaintextV[i-1] == PlaintextV[i]) p++; 
  }
  cout<<endl;
  cout<<p<<endl;
  cout<<PlaintextV.size()<<endl;
  ll=PlaintextV.size();
  cout<<p/ll<<endl;
 return 1;
}
int Reverse()
{
  s=Transcription.size();
  while(Transcription.size() != 0)
  {
    RunesPos[s-k] = Transcription.top();
    Transcription.pop();
    k++;
  }
  return 1;
}
int ConvertToRunes()
{
for(int i=0; i<Text.size(); i++)
{
 if (Text.at(i) >91 )   Text.at(i) = toupper(Text.at(i));
 for(int j=0; j<24; j++)
 {
 if(Text.at(i) == SingleRunes[j].first.at(0))
 Transcription.push(SingleRunes[j].second);
 if(i>=1)
 {
 if(Text.at(i-1) == DoubleRunes[j%8].first.at(0) && Text.at(i) == DoubleRunes[j%8].first.at(1))
 {
 Transcription.pop();
 Transcription.push(DoubleRunes[j%8].second); 
 Text.at(i) = '0';
 }
 }
 }
 if(i>=2)
 {
   if(Transcription.top() == 21)
   {
     Transcription.pop();
     if(Transcription.top() == 10)
     {
       Transcription.pop();
       Transcription.push(21);
     }
     else {Transcription.push(21);}
   }
 }
 //missing letters
 if(Text.at(i) == 'V')
 Transcription.push(1);
 if(Text.at(i) == 'Q')
 Transcription.push(5);
 //space
 if(Text.at(i) == ' ')
 Transcription.push(29);
 }
 return 1;
}
int main()
{
  srand(time(0));
  cout<<"Enter Plaintext here:"<<endl;
  getline(cin,Text);
  ConvertToRunes();
  Reverse();
  for(int i=0; i<s; i++)
  cout<<Runes[RunesPos[i+1]];
  cout<<endl;
  cout<<endl;
  EncodeText();
 // CalculateStatistics();
}
