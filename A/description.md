# 国士无双
## 描述

作为棋牌类游戏与不均等博弈爱好者，`JHSeng`精通国标、广东、四川和日本麻将，他最喜欢的役种是`国士无双`。  
在麻将术语中，`国士无双`（或称`十三幺`）是一种仅涉及`幺九牌`的特殊和牌方式。  

> 幺九牌: 指一万、九万、一饼、九饼、一条、九条、东风、南风、西风、北风、白板、发财、红中共十三种牌。  

它的和牌组合表示为：  

1. 手牌中，每类`幺九牌`至少有一张。  
2. 存在一类`幺九牌`，张数为二。  

手牌同时满足上述1、2条件时，即可`和牌`；手牌仍差一张才能和牌时，即为`听牌`。  

为了更好地表示牌型，对牌面约定如下：  

|牌的种类|表示方法|样例|
|---|---|---|
|万|数字+m|1m(一万), 2m(二万)|
|饼|数字+p|1p(一饼), 2p(二饼)|
|条|数字+s|1s(一条), 2s(二条)|
|东风|1z|1z(东风)|
|南风|2z|2z(南风)|
|西风|3z|3z(西风)|
|北风|4z|4z(北风)|
|白板|5z|5z(白板)|
|发财|6z|6z(发财)|
|红中|7z|7z(红中)|

例如，下述牌型即为一种合法的**和牌**方案。此时每类幺九牌至少有一张，且有两张`红中`。  

```
1m9m1p9p1s9s1z2z3z4z5z6z7z7z
```

显然，从和牌方案中任意移除一张牌，均为合法的**听牌**方案。如从上述牌型移除一张`一万`。  

```
9m1p9p1s9s1z2z3z4z5z6z7z7z
```

给定一副手牌(13张)，请判定是否已经达成**国士无双听牌**。若已达成，请输出`YES`，并指明听哪张牌；否则输出`NO`。  

## 输入描述
一行，一个长度为26的字符串，代表给定的麻将手牌。  

## 输出描述
输出至少为一行，不超过两行。  
第一行应为`YES`或`NO`，代表给定的手牌是否已经**国士无双听牌**。  
若已听牌，第二行应输出具体听的牌。  
**若同时听多张牌，按字典序输出这些牌，用空格分开。**

## 输入样例

```
9m1p9p1s9s1z2z3z4z5z6z7z7z
```

## 输出样例

```
YES
1m
```

## 样例解释
- 样例中，缺少一张“一万”即可和牌。  

## 提示
字符串的**字典序**，是指根据字符在字典中的顺序来排列字符串的方法。比较规则如下：  
1. 从第一个字符开始逐个比较两个字符串的字符。  
2. 若两个字符相同，则继续比较下一个字符。  
3. 若遇到不同字符，则字符较小的字符串更靠前。例如，`apple`小于`banana`。  
4. 若一个字符串是另一个字符串的前缀，则短的字符串更靠前。例如，`app`小于`apple`。  
5. 数字比字母更靠前。  
