# 热身赛题解

## A. 国士无双

题意：  
> 给定一个字符串，判断该字符串是否仅由1m、9m、1p、9p、1s、9s、1z、2z、3z、4z、5z、6z、7z子串组成。若无缺失子串，全部输出；否则输出缺失子串。

一道有点细节的模拟题，因为输入已经保证字符串长度为26(即给13张牌)，细心点就好了。考虑以下三点：  
1. 手牌中是否包含`非幺九牌`  
2. 有且只有一种情况，手牌能形成`十三面听`(十三种幺九牌全为听牌)：每种幺九牌均出现在手牌中。  
3. `单吊`(只听一张牌)时，手牌中幺九牌的种类只可能为十二种。

按以上思路，依次检查手牌即可。

## B. ONU!

非常无聊的模拟题，以至于题解根本不知道该写什么。  
主要问题在于如何优雅地维护玩家卡组信息。标程提供了一种借助`struct`和`map`维护的方法，仅供参考。  
P.S: 最坏情况为$O(400000)$，标程在使用STL的情况下只跑了$7ms$，可见OJ性能恐怖。

## C. 好多表达式

对于每一位数字，只有两种操作：
1. 在这个数字前面放`+`号
2. 不在这个数字前面放`+`号

于是考虑dfs。在搜索过程中，我们需要维护以下信息：
1. **表达式中已经固定下来的数字**，可以用一个`数组`（或者`vector`、`stack`之类的数据结构）去维护。
2. **正在构造中的数字**，用一个`int`类型变量维护即可。
3. **遍历到数字第几位**，用一个`int`类型变量维护即可。

每次遍历完数字，表达式和即为`数组和`+`构造中数字`之和。  
这种方式会将每条表达式构造两次，所以不要忘记除2。

## D. 排名之谜

非常有趣的思维题，最好排名为$max(1, min(n, x + y + 1 - n))$，最坏排名为$min(x + y - 1, n)$。  
这里提供两种思路，仅作参考。  

### Solution 1. 找规律

上面的答案构成相对复杂，只凭肉眼和弱样例，难以猜测（要是有同学一眼猜对，那你真是天才👍）。  
通过仔细阅读样例解释或手动构造样例，~~不难猜到~~大概、也许、可能猜到，`JHSeng`的排名是通过`n`、`x`与`y`**线性计算**得到的。  
怎么印证这个想法是正确的呢？考虑**打表**。枚举`JHSeng`第1、2轮所有的排名，计算所有可能的最好排名与最坏排名。  
打表代码见[此处](https://github.com/TzeHimSung/NewbieCupWarmup/blob/main/D/bruteforce.cpp)  
这段代码的运行结果如下
```shell
best rank result
1 1 1 1 2 
1 1 1 2 3 
1 1 2 3 4 
1 2 3 4 5 
2 3 4 5 5 
worst rank result
1 2 3 4 5 
2 3 4 5 5 
3 4 5 5 5 
4 5 5 5 5 
5 5 5 5 5
```
最坏排名的规律显而易见，就是`x+y-1`，再与总人数取较小值。  
最好排名的规律其实也不难猜测。通过矩阵中的2、3、4的值可以看出是`x+y-n+1`，再保证答案落入`[1, n]`的区间，修正上述公式的不合理值即可。

### Solution 2. 构造

`找规律`的做法适合在赛场上快速猜测答案。然而，这道题有没有较为优雅的数学解呢？  
当然是有的，不过比较复杂。