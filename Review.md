# Review

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

​															$f(n) = \Omicron(n^{log_ba-\varepsilon})$

则

​															$T(n) = \Theta(n^{log_ba})$

若

​															$f(n) = \Omega(n^{log_ba+\varepsilon})$

则

​															$T(n) = \Theta(f(n))$

若

​															$f(n) = \Theta(n^{log_ba}log^kn)$

则

​															$T(n) = \Theta(n^{log_ba}log^{k+1}n)$

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

