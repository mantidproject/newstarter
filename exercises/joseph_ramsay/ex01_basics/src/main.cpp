#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>


using namespace std;


char chartolower(char c){
  if (65 <= c && c <= 90)
    return c + 32;
  return c;
}


string lower(string s){
  string t;
  transform(s.begin(), s.end(), back_inserter(t), chartolower);
  return t;
}


bool space(char c){
  return isspace(c) || c == 45;
}


bool notspace(char c){
  return !space(c);
}


vector<string> split(const string s){
  typedef string::const_iterator iter;
  vector<string> words;
  iter i = s.begin();

  while (i != s.end()){
    i = find_if(i, s.end(), notspace);
    iter j = find_if(i, s.end(), space);
    
    if (i != s.end())
      words.push_back(string(i, j));
    i = j;
  }
  return words;
}


bool notlowerchar(char c){
  return c < 97 || c > 122;
}


string nopunct(string s){
  string::const_iterator iter(remove_if(s.begin(), s.end(), notlowerchar));
  s.erase(iter, s.end());
  return s;
}


int maxlen(map<string, int> counter){
  int m = 0;
  for (map<string, int>::const_iterator it = counter.begin();
       it != counter.end(); ++it){
    m = max(m, int(it->first.length()));
  }
  return m;
}


bool comparepair(pair<string, int> p1, pair<string, int> p2){
  return p1.second > p2.second;
}


vector<pair<string,int>> sortedmap(map<string, int> counter){
  vector<pair<string,int>> sorted;
  for_each(counter.begin(), counter.end(), [&](pair<string, int> p){sorted.push_back(p);});
  sort(sorted.begin(), sorted.end(), comparepair);
  return sorted;
}


int main(int argv, char **argc){
  if (argv <= 1){
    cout << "Please enter a filename" << endl;
    cout << "Usage: ./WordCounter infile [outfile]" << endl;
    return 1;
  }
  
  ifstream infile(argc[1]);

  if (!infile.good()){
    cout << "File does not exist" << endl;
    cout << "Usage: ./WordCounter infile [outfile]" << endl;
    return 1;
  }
  
  string s;
  map<string, int> counter;
  
  while (getline(infile, s)){
    vector<string> words = split(lower(s));
    transform(words.begin(), words.end(), words.begin(), nopunct);
    for_each(words.begin(), words.end(), [&](string t){if (t.length() > 4) ++counter[t];});
  }
  
  vector<pair<string, int>> sortedcounter = sortedmap(counter);
  int maxwordlength = maxlen(counter);

  string outname = "output.txt";
  if (argv == 3)
    outname = argc[2];
  
  ofstream outfile(outname);
  outfile << "Word" << string(maxwordlength - 3, ' ') <<  "Usage" << endl << endl;
  
  for_each(sortedcounter.begin(), sortedcounter.end(), [&](pair<string, int> p)
	   {outfile << p.first << string(maxwordlength - p.first.length() + 1, ' ') << p.second << endl;});

  cout << "Output file written to " << outname << endl;
  return 0; 
}



