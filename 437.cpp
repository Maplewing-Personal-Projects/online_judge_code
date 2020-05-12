/*******************************************************/
/* UVa 437 The Tower of Babylon                        */
/* Author: Maplewing [at] knightzone.studio            */
/* Version: 2020/05/12                                 */
/*******************************************************/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Block {
  int baseX;
  int baseY;
  int heightZ;
};

bool compare(const Block& a, const Block& b) {
  if (a.baseX < b.baseX) return true;
  if (a.baseX == b.baseX && a.baseY < b.baseY) return true;
  if (a.baseX == b.baseX && a.baseY == b.baseY && a.heightZ < b.heightZ) return true;
  return false;
}

void addAllPermutationBlocks(vector<Block>& blockTypes, const Block& block) {
  int blockEdges[] = { block.baseX, block.baseY, block.heightZ };
  for (int i = 0 ; i < 3 ; ++i ) {
    for (int j = 0 ; j < 3 ; ++j ) {
      if (i == j) continue;

      for (int k = 0 ; k < 3 ; ++k ) {
        if (i == k || j == k) continue;
        
        blockTypes.push_back((Block){ blockEdges[i], blockEdges[j], blockEdges[k] });
      }
    }
  }
}

int main() {
  int caseNumber = 1, n;
  while (scanf("%d", &n) != EOF && n != 0) {
    vector<Block> blockTypes;
    for (int i = 0 ; i < n ; ++i) {
      Block inputBlock;
      scanf("%d%d%d", &(inputBlock.baseX), &(inputBlock.baseY), &(inputBlock.heightZ));
      
      addAllPermutationBlocks(blockTypes, inputBlock);
    }

    sort(blockTypes.begin(), blockTypes.end(), compare);

    int totalBlockTypesCount = blockTypes.size();
    vector<int> lis(totalBlockTypesCount);
    for (int sequenceEndIndex = 0 ; sequenceEndIndex < totalBlockTypesCount ; ++sequenceEndIndex) {
      Block endBlock = blockTypes[sequenceEndIndex];
      lis[sequenceEndIndex] = endBlock.heightZ;

      for (int beforeEndIndex = 0 ; beforeEndIndex < sequenceEndIndex ; ++beforeEndIndex) {
        Block currentBlock = blockTypes[beforeEndIndex];
        if (
          currentBlock.baseX < endBlock.baseX && currentBlock.baseY < endBlock.baseY &&
          lis[beforeEndIndex] + endBlock.heightZ > lis[sequenceEndIndex]
        ) {
          lis[sequenceEndIndex] = lis[beforeEndIndex] + endBlock.heightZ;
        }
      }
    }

    int maxHeight = 0;
    for (int i = 0 ; i < totalBlockTypesCount ; ++i) {
      maxHeight = max(maxHeight, lis[i]);
    }
    printf("Case %d: maximum height = %d\n", caseNumber++, maxHeight);
  }

  return 0;
}