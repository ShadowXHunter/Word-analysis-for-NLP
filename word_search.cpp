#include<bits/stdc++.h>

using namespace std;
//word frequency search function
int search(string s,map<string,int> x)
{
  return x[s];
}

//Comparator function for sorting the vector of pairs
bool cmp(pair<string, int>& a, pair<string, int>& b)
{
    return a.second > b.second;
}

//function to sort and display most frequent words after
//removing the stop words to obtain an idea about the text
void most_frequent(map<string, int>& dict, set<string>& stwords)
{
    int counter=0;
    // Declare vector of pairs
    vector<pair<string, int> > A;
  
    // Copy key-value pair from Map to vector of pairs
    for (auto it : dict) {
        A.push_back(it);
    }
  
    // Sort using comparator function
    sort(A.begin(), A.end(), cmp);
  
    //Print the most frequent words
    cout<<"\n20 most frequent words after removing the stop words:\n"<<endl;
    for (auto it = A.begin(); it != A.end() && counter<20; it++) {
        //display words if not in stop words list
        if(!stwords.count(it->first)){
          cout << it->first << endl;
          counter++;
        }
    }
}

int main()
{
    ifstream f, file;
    //map to store frequency of each unique word
    map<string,int> dict;
    f.open("english_stopwords.txt");
    char id;
    cout<<"Files available for analysis:\n1. Pride and Prejudice - Chapter 1\n2. News article on an underwater lake\n"<<endl;
    while(1){
      cout<< "Enter choice in no. or '!' to cancel - ";
      cin>>id;
      if(id=='1'){ file.open("pride_and_prejudice.txt"); break;}
      else if(id=='2'){ file.open("news_article.txt"); break;}
      else if(id=='!') exit(0);
      else cout<<"\nINVALID CHOICE! Try Again.\n";
    }
    string word;
    char symbols[] = {'.', '?', '!', ',', ':', ';', '"', '_', '-', '@', '$', '&', '%', '#', '(', ')', '{', '}', '[', ']', '/', '<', '>', '|', '*', '+', '=', '`', '~'};
    //container to store the english stop words 
    set<string> stwords;
    vector<string> str;
    while(f>>word)
    {
        stwords.insert(word);
    }
    
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
    cout<<"\nPrinting word frequency...\n";
    while(!str.empty())
    {
      cout<<str.back()<<": "<<dict[str.back()]<<endl;
      str.pop_back();
    }    
    cout<<"\nTotal unique words: "<<dict.size()<<"\n";
    //print most frequent words
    most_frequent(dict, stwords);
    //search for particular word frequency
    cout<<"\nSearch for frequency of a particular word?  y/n: ";
    cin>>word;
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    if(word=="y"||word=="yes"){
      while(1){
        cout<<"Enter word or \'!\' to cancel: ";
        cin>>word;
        if(word=="!") break;
        cout<<search(word, dict)<<"\n";
      }
    }  
}
