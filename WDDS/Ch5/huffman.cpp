#include <bits/stdc++.h>
using namespace std;
#define N 1000
//TODO HUFFMAN
typedef struct HNode{
    int weight;
    HNode *L,*R;
}*Htree;

Htree createHuffmanTree(int arr[], int n) {
  Htree forest[N];
  Htree root = NULL;
  for (int i = 0; i < n; i++) {  // 将所有点存入森林
    Htree temp;
    temp = (Htree)malloc(sizeof(HNode));
    temp->weight = arr[i];
    temp->L = temp->R = NULL;
    forest[i] = temp;
  }

  for (int i = 1; i < n; i++) {  // n-1 次循环建哈夫曼树
    int minn = -1, minnSub;  // minn 为最小值树根下标，minnsub 为次小值树根下标
    for (int j = 0; j < n; j++) {
      if (forest[j] != NULL && minn == -1) {
        minn = j;
        continue;
      }
      if (forest[j] != NULL) {
        minnSub = j;
        break;
      }
    }

    for (int j = minnSub; j < n; j++) {  // 根据 minn 与 minnSub 赋值
      if (forest[j] != NULL) {
        if (forest[j]->weight < forest[minn]->weight) {
          minnSub = minn;
          minn = j;
        } else if (forest[j]->weight < forest[minnSub]->weight) {
          minnSub = j;
        }
      }
    }

    // 建新树
    root = (Htree)malloc(sizeof(HNode));
    root->weight = forest[minn]->weight + forest[minnSub]->weight;
    root->L = forest[minn];
    root->R = forest[minnSub];

    forest[minn] = root;     // 指向新树的指针赋给 minn 位置
    forest[minnSub] = NULL;  // minnSub 位置为空
  }
  return root;
}

int getWPL(int arr[], int n) {  // 对于未建好的霍夫曼树，直接求其 WPL
  priority_queue<int, vector<int>, greater<int>> huffman;  // 小根堆
  for (int i = 0; i < n; i++) huffman.push(arr[i]);

  int res = 0;
  for (int i = 0; i < n - 1; i++) {
    int x = huffman.top();
    huffman.pop();
    int y = huffman.top();
    huffman.pop();
    int temp = x + y;
    res += temp;
    huffman.push(temp);
  }
  return res;
}

void huffmanCoding(Htree root, int len, int arr[]) {  // 计算霍夫曼编码
  if (root != NULL) {
    if (root->L == NULL && root->R == NULL) {
      printf("结点为 %d 的字符的编码为: ", root->weight);
      for (int i = 0; i < len; i++) printf("%d", arr[i]);
      printf("\n");
    } else {
      arr[len] = 0;
      huffmanCoding(root->L, len + 1, arr);
      arr[len] = 1;
      huffmanCoding(root->R, len + 1, arr);
    }
  }
}

int main()
{
    
    
    return	0;
}