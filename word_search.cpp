#include<bits/stdc++.h>

using namespace std;
int search(string s,map<string,int> x)
{
  return x[s];
}
int main()
{
    ifstream file;
    
    map<string,int> dict;
    file.open("read.txt");
    string word;
    char symbols[] = {'.', '?', '!', ',', ':', ';', '"'}; 
    vector<string> str;
    while(file>>word)
    {
        //symbols removed
        for(int i=0; i<sizeof(symbols); i++)
        {word.erase(remove(word.begin(),word.end(),symbols[i]),word.end());}
        //case changed to lower
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        
        //word added to map if previously not present
        if(dict[word]==0)
        {
            dict[word]=1;
        }
        //if present, count increased
        else
        {
            dict[word]++;
        }
        //all different words sent to word vector
        if(dict[word]==1)
        {
          str.push_back(word);
          
        }
    }
    while(!str.empty())
    {
      cout<<str.back()<<":"<<dict[str.back()]<<endl;
      str.pop_back();
    }    
    
    
}