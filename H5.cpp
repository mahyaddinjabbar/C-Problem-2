/*H5. Read text from given text file. Find 5 most frequent pairs of words in given text.
 Pair of words are two adjacent words in the same line of input text file separated with non-letter symbols.
 Print in another text file 5 pairs of words and number how many times this pair appears in text
 (for example of the 12, and the 10, at the 10, on the 10, he would 8). Word is string containing only English alphabet letters.*/
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<fstream>
#include<algorithm>
#include<list>
#include<filesystem>
#include <bits/stdc++.h>
using namespace std;

//bool to compare pairs and finding pairs with higher frequency
bool cmp(pair<string, int>& a,pair<string, int>& b){  
      return a.second > b.second;
}
int main(){
    const int max_nums = 1000;   
    fstream myfile("textin.txt", ios::in);
    ofstream myfileout("textout.txt",ios::out);
    map<string,int>allWords;
    int size = 0;


    if(myfile.is_open()){
      string allWords[max_nums];
      int count=0;

      //transfering all words from text file to allWords map.
      while(!myfile.eof()){   
        count++;
        myfile>>allWords[count];
        size++;
      }
      map<string,int>pairWords;
      
      //creating word pairs and transferring them to another map
      for(int i = 1; i<size-1; i++){
        string key = allWords[i]+" "+allWords[i+1];
        pairWords[key]++;
      }

      vector<pair<string, int>> A;

      // Copy key-value pair from Map
      // to vector of pairs
      for (auto& it : pairWords) {
          A.push_back(it);
      }

      sort(A.begin(), A.end(), cmp);

      // Print the sorted value to another file
      int index = 0;
      for(auto& it : A) {
        myfileout<< it.first << '-'<< it.second << endl;
        index++;
        if(index==5) break;
      }
        myfileout.close();
    }



}
