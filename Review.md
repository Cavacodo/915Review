### Review

## 第一章

### 数据结构三要素

#### 1.逻辑结构：

##### 线性结构：一般线性表，受限线性表(栈，队列，串)，线性表推广(数组)

##### 非线性结构：集合，树形结构(一般树，二叉树)，图状结构(有向图，无向图)

#### 2.存储结构(物理结构)

##### 顺序存储

##### 链式存储

##### 索引存储

##### 散列存储

#### 3.数据的运算

### 五个特征

有穷性，确定性，可行性，输入，输出

#### 好的算法应该有的目标：

可读性，正确性，健壮性，高效率低存储需求

### 基本概念和术语：

==**数据**==：数据是信息的载体，是描述客观事物的数，字符及所有能输入到计算机中并被计算机程序识别和处理的符号的集合。(Table)

**==数据元素==**：数据元素是数据的基本单位，通常作为一个整体考虑处理。由若干==数据项==组成。(Table-Row)

**==数据对象==**：具有相同性质的数据元素的几个(Table-Col)

**==数据类型==**：数据类型是一个值的集合和定义在此集合的一组操作的总称

1) 原子类型：不可再分
2) 结构类型：结构体变量
3) 抽象数据类型：自己定义的

**==数据结构==**： 数据结构是相互之间存在一种或多种特定关系的数据元素的集合。包含三方面内容：==逻辑结构，存储结构，数据的运算==。

### 算法效率的度量

#### 时间复杂度

算法中基本运算执行的次数称为时间复杂度

T(n) = O(f(n))

#### 主定理

递归子问题的求解

​															$T(n) = aT(n/b)+f(n)$

$a$:规约后子问题的个数

$n/b$:规约后子问题的规模

$f(n)$:规约过程及组合子问题解工作量

设$a \geq 1, b > 1 ,且令 \varepsilon > 0$

若
$$
f(n) = \Omicron(n^{log_ba-\varepsilon})
$$
则

$$
T(n) = \Theta(n^{log_ba})
$$
若

$$
f(n) = \Omega(n^{log_ba+\varepsilon})
$$


则

$$
T(n) = \Theta(f(n))
$$


若

$$
f(n) = \Theta(n^{log_ba}log^kn)
$$


则

$$
T(n) = \Theta(n^{log_ba}log^{k+1}n)
$$


#### 常见的时间复杂度大小比较

$O(1) < O(log_2n) < O(n) < O(nlog_2n) < O(n^2) < O(n^3) < O(2^n) < O(n!) < O(n^n)$

#### 空间复杂度

算法所需的存储空间

原地工作是指O(1)

---

## 第二章

### 线性表定义

线性表是具有相同数据类型的n个数据元素的有限序列，其中n为表长，n = 0 ，线性表为一个==空表==。

**线性表可以是空表**

### 线性表的顺序存储

是一种随机存取的存储结构

**线性表中元素的位序是从1开始的，而数组中的下标是从0开始的**。

一位数组可以是静态分配的，但也可以是动态分配的

==**插入操作**==：平均需要移动n/2个元素

**==删除操作==**：平均需要移动(n-1)/2个元素

**==按值查找(顺序查找)==**：平均次数 (n+1)/2

### 线性表的链式存储

头指针是NULL时表示一个空表

### 静态链表

==优点==：不需要移动元素

==缺点==：不可随机存取，容量不可变

![](https://ucc.alicdn.com/images/user-upload-01/39256bfa74fe4603891d75426d8fa9a7.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5oS_5aSp5aCC5rKh5pyJQ--8i--8iw==,size_20,color_FFFFFF,t_70,g_se,x_16#pic_center)

### 存储密度

存储密度 = （结点数据本身所占的存储量）/（结点结构所占的存储总量）

比如

```c++
typedef struct chainList {
	int data;
	struct chainList *next;
}Node;
```

数据本身占据 int = 2

总体 指针+int = 8+2

存储密度 = 0.2

32位电脑指针占4

64位占8

---

## 第三章

有n个不同元素进栈时，出栈元素个数不同排列有

​														$Catalan = \frac{1}{n+1}C_{2n}^{n}$

### 共享栈

top = -1 时 0 号栈为空

Top1 = MAXSIZE时1号栈为空

当(top1 - top0 = 1)时，判断为栈满

### 队列的基本概念

#### 循环队列

初始时：Q.front = Q.rear = 0

队首指针进1: Q.front = (Q.front+1) % MaxSize

队尾指针进1: Q.rear = (Q.rear+1) % MaxSize

队列长度：(Q.rear+MaxSize-Q.front) % MaxSize

##### 判断循环队列队满/队空的判断条件

1) ##### 牺牲一个单位来区分队空和队满

   和上面的逻辑一样，第一个元素始终没有存上，直接到了下一位置

   **队满条件**：(Q.rear+1) % MaxSize == Q.front

   **队空条件**：Q.front == Q.rear

   **队列中元素的个数**：(Q.rear+MaxSize-Q.front) % MaxSize

2) ##### 类型中设置size数据成员

   表示元素个数，删除成功size-1,插入成功size+1,队空时size=0，队满时size=maxsize

3) ##### 类型中增设tag数据成员

   区分队满队空，删除成功tag = 0,若Q.front == Q.rear，则为队空。若插入成功tag = 1,若Q.front == Q.rear则为队满

### 栈和队列的应用

#### 括号匹配

```c++
class Solution {
public:
    bool isValid(string s) {
        deque<char> dq;
        unordered_map<char,char> map;
        map[')'] = '(';
        map['}'] = '{';
        map[']'] = '[';
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                dq.push_back(s[i]);
            }else{
                if(dq.empty()) return 0;
                if(map[s[i]] == dq.back()){
                    dq.pop_back();
                    continue;
                }else return 0;
            }
        }
        return dq.empty() ? 1 : 0;
    }
};
```

#### 表达式求值

中缀转后缀：

1) 给所有运算单位加括号
2) 运算符移动到对应括号的后面
3) 去除括号

```javascript
A+B*(C-D)-E/F
(A+(B*(C-D))-(E/F))
(A(B(CD)-)*)+(EF)/)-
ABCD-*+EF-
```

入栈出栈规则

1) ==遇到操作数== 直接加入后缀表达式
2) ==遇到界限符== 如果是 ' ( ' 直接入栈。如果是 ' ) '，依次弹出栈中运算符，并加入后缀表达式。直到弹出' ( ' 为止。
3) ==遇到运算符== 若其优先级高于除去" ( " 以外的栈顶运算符，并加入后缀表达式，否则(<=)则取出两个操作数，运算后加入再加入该栈

![img](https://img2020.cnblogs.com/blog/1358881/202005/1358881-20200510203222875-1233268295.png)

#### 后缀表达式求值

![img](https://s2.51cto.com/images/blog/202108/08/411d4a31fb8904571dffab79ab41bf96.png?x-oss-process=image/watermark,size_16,text_QDUxQ1RP5Y2a5a6i,color_FFFFFF,t_30,g_se,x_10,y_10,shadow_20,type_ZmFuZ3poZW5naGVpdGk=/format,webp)

#### 栈在递归中应用

栈在每一次递归中把当前工作状态压入栈，后年才弹出计算

#### 队列在计算机系统中的应用

1) 缓冲区的逻辑结构
2) 多队列出队/入队操作应用

### 特殊数组的压缩存储

#### 对称矩阵

![img](https://images0.cnblogs.com/blog2015/740575/201505/161452034236173.gif)

下标对应情况如下：

i,j从1开始	1 <= i , j <= n

使用B[n*(n-1)/2]开始

数组下标从k = 0开始
$$
k=
\begin{cases}
\frac{i(i-1)}{2}+j-1,\quad i\geq j(下三角区和主对角线元素)\\
\frac{j(j-1)}{2}+i-1, \quad i<j(上三角)
\end{cases}
\tag{1}
$$

#### 三角矩阵

![img](https://images0.cnblogs.com/blog2015/740575/201505/161513148929847.gif)

除去上三角或下三角以外，剩下位置均是常数c

使用B[n*(n-1)/2+1]个位置存储

元素对应关系：
$$
k = \begin{cases}
\frac{i(i-1)}{2} + j-1 \quad i\geq j(下三角区和对角线) \\
\frac{n(n+1)}{2} \quad i<j(上三角区元素)
\end{cases}
$$

#### 三对角矩阵

![img](https://github.com/fmw666/Data-Structure/raw/master/pics/3/3.4.3(4).png)

也叫带状矩阵

存储方式如下：

![img](https://docs.oldtimes.me/c.biancheng.net/cpp/uploads/allimg/120222/1-1202221I412553.jpg)

由此可计算矩阵A中三条对角线上元素ai,j(1 <= i, j <= n, |i-j| <= 1)在一维数组B中存放的下标为k = 2i+j-3

#### 稀疏矩阵

使用三元组存储

![稀疏矩阵之三元组压缩存储并且转置_稀疏矩阵](https://s2.51cto.com/images/blog/202305/17182304_6464ab080cb4329430.png?x-oss-process=image/watermark,size_16,text_QDUxQ1RP5Y2a5a6i,color_FFFFFF,t_30,g_se,x_10,y_10,shadow_20,type_ZmFuZ3poZW5naGVpdGk=/format,webp/resize,m_fixed,w_1184)

也可以使用十字链表存储 

![img](https://pic002.cnblogs.com/images/2012/457289/2012102211294516.jpg)

---

## 第四章

### KMP

假设串为 abcac

##### PM(Partial Match)求法

| 编号 |  1   |  2   |  3   |  4   |  5   |
| :--: | :--: | :--: | :--: | :--: | :--: |
|  S   |  a   |  b   |  c   |  a   |  c   |
|  PM  |  0   |  0   |  0   |  1   |  0   |

看前缀从前向后求

向后移动的位数 == 已匹配的字符数 - 对应的PM

##### next数组求法

把PM整体右移一位得到next数组

| 编号 |  1   |  2   |  3   |  4   |  5   |
| :--: | :--: | :--: | :--: | :--: | :--: |
|  S   |  a   |  b   |  c   |  a   |  c   |
| next |  -1  |  0   |  0   |  0   |  1   |

有时为了使得公式简洁，计算简单可以将数组整体+1

| 编号 |  1   |  2   |  3   |  4   |  5   |
| :--: | :--: | :--: | :--: | :--: | :--: |
|  S   |  a   |  b   |  c   |  a   |  c   |
| next |  0   |  1   |  1   |  1   |  2   |

next[j]的含义是：当子串的第 j 个字符与主串发生失配时，跳到子串的next[ j ]位置重新与主串当前位置进行比较。

##### nextval数组的计算

|      模式串      |  a   |  b   |  c   |  a   |  c   |
| :--------------: | :--: | :--: | :--: | :--: | :--: |
|       下标       |  1   |  2   |  3   |  4   |  5   |
|     next数组     |  0   |  1   |  1   |  1   |  2   |
| next数组对应字母 |  -   |  a   |  a   |  a   |  b   |
|     Nextval      |  0   |  1   |  1   |  0   |  2   |

Nextval[0] 默认与next数组第一个一样

如果next数组对应字母与模式串不同，nextval对应位置直接照抄

如果相同,则nextval[i] 等于next数组nextval[next[i]]

比如下标位4，都是a,则nextval = nextval[0]

---

## 第五章

**树和二叉树可以是空树，但是度为m(m>0)的树不能是空树**；

**树的层次** ： 从树根开始定义，根节点为第一层，它的孩子是第二层，依次类推。

**有序树和无序树**：树中节点的各子树从左到右是有次序的，不能互换称为有序树，否则是无序树

**路径和路径长度** ：两个节点之间的路径是两个节点之间所经过的节点序列构成的。路径长度是路径上所有的经过的边的个数。

**森林**：m(m >= 0)颗互不相交的树的集合。

### 二叉树

#### 二叉树和度为2的树的区别

1) 度为2的树至少有3个节点，二叉树可以为空树(度为m的树至少有m+1个节点)
2) 度为2的树孩子的左右次序无关，但是二叉树有关

#### 特殊的二叉树

1) 满二叉树
2) 完全二叉树(deg == 1的节点只能是0个或者1)，若n为奇数，每个分支节点都有左孩子和右孩子;n为偶数，编号最大的分支节点只有左孩子，没有右孩子
3) 正则二叉树(树中只有度为0或2的节点)

#### 遍历序列构建二叉树

先序中序构建二叉树

```cpp
class Solution {
public:
    vector<int> pre;
    vector<int> in;
    unordered_map<int,int> map;
    TreeNode* dfs(int pl,int pr,int il,int ir){
        if(pl == pr) return nullptr;
        int offset = map[pre[pl]] - il;
        //  左闭右开区间
        TreeNode* left = dfs(pl+1,pl+1+offset,il,il+offset);
        TreeNode* right = dfs(pl+1+offset,pr,il+offset+1,ir);
        return new TreeNode(pre[pl],left,right);
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pre = preorder,in = inorder;
        for(int i = 0; i < inorder.size(); i++) map[inorder[i]] = i;
        int n = preorder.size();
        return dfs(0,n,0,n);
    }
};
```

后序中序构建二叉树

```cpp
class Solution {
public:
    vector<int> in;
    vector<int> post;
    unordered_map<int,int> umap;
    TreeNode* dfs(int pl,int pr,int il,int ir){
        if(pl == pr) return nullptr;
        int left_size = umap[post[pr-1]] - il;
        TreeNode* left = dfs(pl,pl+left_size,il,il+left_size);
        TreeNode* right = dfs(pl+left_size,pr-1,il+left_size+1,ir);
        return new TreeNode(post[pr-1],left,right); 
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        in = inorder;
        post = postorder;
        for(int i = 0 ; i < postorder.size(); i++) umap[inorder[i]] = i;
        return dfs(0,n,0,n);
    }
};
```

### 树 森林

#### 树的存储方法

##### 1.双亲表示法

![双亲表示法](https://p3-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/9f7b391cdce5428abf2156e46ed978f8~tplv-k3u1fbpfcp-zoom-in-crop-mark:1512:0:0:0.awebp)

##### 2.孩子表示法

![在这里插入图片描述](https://i-blog.csdnimg.cn/blog_migrate/f1519acba73751c197ac92723438fb12.png)

##### 3.孩子兄弟表示法

![img](https://img2020.cnblogs.com/blog/1662740/202104/1662740-20210402212730970-481741869.png)

#### 树 森林的转换

**树转二叉树的规则**：每个结点的左指针指向它的第一个孩子，右指针指向它在树中的相邻右兄弟，即左孩子右兄弟。由于根节点没有兄弟，因此树转二叉树没有右子树。

**森林转二叉树**：先将森林中的每一颗树转换成二叉树，由于任意一颗树的右子树为空，若把森林中的第二颗树当作第一颗树的右子树，依次递归，得到树转二叉树。

#### 树的遍历

1) **先根遍历**：先访问根节点，再依次访问根结点的每棵子树，遍历子树时仍旧遵循先根后子树。
2) **后根遍历** : 先依次遍历根节点的每棵子树，遍历子树仍旧遵循先子树后根的规则。再访问根结点。

#### 森林的遍历

1) **先序遍历森林**：若森林非空，访问森林中的第一颗树的根节点，先序遍历第一颗树中根节点的子树森林。先序遍历除去第一颗树之后剩余的树构成的森林。
2) **中序遍历森林**：树中序遍历森林第一颗树的根节点。中序遍历除去第一颗树之后剩余的树构成的森林。

### 树与二叉树的应用

#### Huffman Encoding

从树中一个节点到另一个节点之间的分支(edge)构成这两个结点之间的**路径**

路径上的分支数目称为**路径长度**

从树的根到一个结点的路径长度与该结点上权值的乘积，称为该结点的**带权路径长度**。
$$
WPL = \sum_{i=1}^{n} w_il_i
$$


树中所有叶结点的带权路径长度之和称为该树的带权路径长度，其中带权路径长度最小的二叉树称为哈夫曼树。也称**最优二叉树**。

##### Huffman树的构造

1) 将这n个节点分别作为n颗仅含一个结点的二叉树。构成森林F
2) 构建一个新节点，从森林中选择两颗根节点权值最小的树作为新节点的左右子树。并且将新结点的权值置为左右子树上根结点的权值之和。
3) 从F中删除刚才选择的两颗树，同时将新构建的树加入
4) 重复构建步骤2和步骤3，直到F中只剩下一颗树为止。

##### Huffman树的性质

1) 权值越小的结点到根结点的路径长度越大。
2) 构建过程中共新建了n-1个结点，因此huffman树中的结点总数是2n-1
3) 每次构建都选择2颗树作为新结点的孩子，因此Huffman树中不存在度为1的结点。

##### Huffman编码

在数据通信中，若对每个字符使用相等长度的二进制位表示，称这种方式为**固定长度编码**。若允许对不同字符使用不等长的二进制位表示，则这种编码方式成为**可变长度编码(Huffman)**。

Huffman编码使得可以被唯一翻译，每个结点的权值为出现的次数(或频度)

**使用Huffman编码可以设计出总长度最短的二进制前缀编码**

#### 并查集

##### Init操作

```c++
void Init(int pa[]){
    for(int i=0;i<size;i++) {
        pa[i] = i;
        rnk[i] = 1;
    }
}
```

##### find操作

```c++
int find(int pa[],int x){
    return pa[x] == x ? x : find(pa,pa[x]);
}
```

##### Union操作

```c++
void Union(int pa[],int root1,int root2){
    pa[find(pa,root1)] = find(pa,root2);
}
```

##### 优化后的find操作

```c++
int find_opt(int pa[],int x){
    return pa[x] == x ? x : pa[x] = find(pa,x);
}
```

##### 优化后的Union操作

```c++
void Union_opt(int pa[],int x,int y){
    //这里找到的是最祖先的，pa数组存储的是最直接的父亲
    //把小的合并到大的上
    int root1 = find(pa,x);
    int root2 = find(pa,y);
    if(root1 == root2) return;
    if(rnk[x] > rnk[y]){
        pa[y] = x;
    }else if(rnk[x] < rnk[y]){
        pa[x] = y;
    }else{
        rnk[x]++;
    }
}
```

---

## 第六章

线性表可以是空表，树可以是空树(度为2的树不能是空树，二叉树可以是空树)，但是图不能是**空图**。

#### 图的定义

##### 简单图

不存在重复边(平行边)，不存在顶点到自身的边(自环)，则称G为简单图。

反之则是**多重图**

##### 完全图(简单无向图)

对于**无向图**，有n(n-1)/2条边的无向图称为完全图。完全图中任意两个结点之间均存在边。

对于**有向图**，有n(n-1)条边的有向图称为**有向完全图**。

##### 子图

设有两个图$G=(V,E)$,和$G'=(V',E')$ 且，若$V'$是$V$的子集，$E'$是$E$的子集，则称$G'$是$G$的子图。

若有满足$V(G') = V(G)$ (也就是顶点相同)的子图$G'$，则称其为$G$的**生成子图**。

##### 连通图和连通分量

在**无向图**中，若从顶点v到顶点w有路径存在，则称v,w是连通的。若图G中任意两个顶点都是连通的则称图G是**连通图**，否则称为**非连通图**。无向图中的极大连通子图称为**连通分量**(极大连通子图要求包含尽可能多的顶点和边，并且要求连通)。

##### 强连通图，强连通分量

在有向图中，若有一对顶点v,w，从v到w和从w到v之间都有路径，则称这两个顶点是**强连通的**。若图中任意一对顶点都是强连通的，则称此图为**强连通图**。有向图中的极大强连通子图称为有向图的**强连通分量**。

**生成树，生成森林**

**连通图**的生成树是包含图中全部顶点的一个极小连通子图。

极小连通子图是既要保持子图连通又要使边数最少的子图。

##### 边的权和网

在一个图中，每条边上带某种含义的数值，称该数值为该边的权值。这种边上带有权值的图称为带权图，也称**网**。

##### 稠密图，稀疏图

一般来说，当图满足|E|<|V|log|V|时，称G为稀疏图。

##### 简单路径，简单回路

在路径序列中，顶点不重复出现的路径称为**简单路径**，除去第一个顶点和最后一个顶点之外，其余顶点不重复出现的回路称为**简单回路**。

##### 有向树

一个顶点的入度为0，其余顶点的入度为1的有向图称为有向树。

