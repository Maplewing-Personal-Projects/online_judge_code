/*******************************************************/
/* UVa 644 Immediate Decodability                      */
/* Author: Maplewing [at] knightzone.studio            */
/* Version: 2020/05/14                                 */
/*******************************************************/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

struct TrieNode {
  bool isEnd;
  map<char, TrieNode*> nextNodes;
};

bool insertTrieAndCheckPrefix(TrieNode* root, const string& symbol) {
  bool isPrefixFound = false;
  TrieNode* currentNode = root;
  for (int i = 0 ; i < symbol.length() ; ++i) {
    if (currentNode->nextNodes.find(symbol[i]) == currentNode->nextNodes.end()) {
      currentNode->nextNodes[symbol[i]] = new TrieNode();
    }
    currentNode = currentNode->nextNodes[symbol[i]];
    if (currentNode->isEnd) isPrefixFound = true;
  }

  currentNode->isEnd = true;
  return isPrefixFound;
}

void clearTrie(TrieNode* root) {
  for (
    map<char, TrieNode*>::iterator it = root->nextNodes.begin() ;
    it != root->nextNodes.end() ;
    ++it
  ) {
    clearTrie(it->second);
  }

  delete root;
}

bool compare(const string& a, const string& b) {
  return a.length() < b.length();
}

int main() {
  vector<string> symbols;
  string input;
  int caseNumber = 1;
  while (cin >> input) {
    if (input != "9") {
      symbols.push_back(input);
      continue;
    }

    sort(symbols.begin(), symbols.end(), compare);

    bool isPrefixFound = false;
    TrieNode* trieRoot = new TrieNode();
    for (int i = 0 ; !isPrefixFound && i < symbols.size() ; ++i) {
      isPrefixFound = isPrefixFound || 
        insertTrieAndCheckPrefix(trieRoot, symbols[i]);
    }

    printf("Set %d is%s immediately decodable\n",
      caseNumber++,
      isPrefixFound ? " not" : "");
    
    clearTrie(trieRoot);
    symbols.clear();
  }
  return 0;
}