# 排名之谜
## 描述
> 因为`hrmm`不想让大家在10分钟内秒杀热身赛，所以他让`JHSeng`给可爱的大一小朋友们出一道丧心病狂的思维题，全怪`hrmm`！  

在`未来道具研究所`，借助`電話レンジ`(`电话微波炉`)的力量，`JHSeng`穿越到2077年的`SCUT`，参加一年一度的`ACM新生杯`。  

2077年的新生杯规则如下：  
1. 新生杯由两轮比赛组成，每轮比赛均有`n`名参赛者。  
2. 在任意一轮比赛中，**不存在**参赛者并列名次的情况。
3. 比赛结束后，对每位参赛者**计分**，计分规则为**两轮比赛排名之和**。
4. 根据每位参赛者的**得分**，计算参赛者的**总排名**。
5. 参赛者的**总排名**，指的是**得分小于或等于当前参赛者分数**的**人数**（包括参赛者本人）。

比赛结束后，`JHSeng`得知自己第一轮排第`x`名，第二轮排第`y`名。在不知道其他选手的排名下，`JHSeng`迫切地想知道，自己的**最好**和**最坏总排名**可能是多少。

`JHSeng`对自己的总排名很有信心，但他不知道的是，`すべてはシュタインズ・ゲートの選択である`(这一切都是命运石之门的选择)。

## 输入描述
一行，包含三个整数，`n`、`x`和`y`。其中，$1 \le n \le 10^9$，$1 \le x, y \le n$。

## 输出描述
一行，包含两个整数，用空格分隔，代表`JHSeng`可能的**最好总排名**与**最坏总排名**。

## 输入样例1
```
5 1 3
```
## 输出样例1
```
1 3
```

## 样例解释
`JHSeng`最好总排名是`1`，此时一种可能的情况如下所示：
|参赛者|第一轮排名|第二轮排名|得分|总排名|
|---|---|---|---|---|
|JHSeng|1|3|4|1|
|A|2|4|6|3|
|B|3|5|8|5|
|C|4|1|5|2|
|D|5|2|7|4|

`JHSeng`最坏总排名是`3`，此时一种可能的情况如下所示：
|参赛者|第一轮排名|第二轮排名|得分|总排名|
|---|---|---|---|---|
|JHSeng|1|3|4|3|
|A|2|2|4|3|
|B|3|1|4|3|
|C|4|4|8|4|
|D|5|5|10|5|

## 无关小信息
> 宇宙に始まりはあるが、終わりはない。　---無限  
> 星にもまた始まりはあるが、自らの力をもって滅び逝く。　---有限  
> 英知を持つ者こそ、最も愚かであること。歴史からも読み取れる。  
> 海に生ける魚は、陸の世界を知らない。彼らが英知を持てば、それもまた滅び逝く。  
> 人間が光の速さを超えるのは、魚たちが陸で生活を始めるよりも滑稽。  
> これは抗える者たちに対する、神からの最後通告とも言えよう。  
>   
> 宇宙虽有其起源，却没有终结——无限。  
> 星球也有起源，却因其自身之力走向毁灭——有限。  
> 历史上拥有智慧的人类往往是最愚昧的。  
> 生活在海中的鱼不知道陆地的存在，如果它们拥有智慧也会走向毁灭。  
> 人类如果想要超越光速，比鱼类生活在陆地更为滑稽。  
> 这就是，对于反抗神人们的最后通牒。  
> ---《STEINS;GATE》