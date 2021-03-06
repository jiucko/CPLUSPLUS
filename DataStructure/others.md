## 2-3树
对于普通的二叉查找树（Binary Search Tree），在大多数情况下查找和插入的效率是没有问题的，但是在最差情况下，二叉查找树会退化成链表，效率就比较低，如何保证在最差情况下也是lgN的效率，这就是平衡查找树。要保证效率，我们需要在每次插入后使树仍然保持平衡状态。
### 定义
和二叉树不一样，2-3树每个节点保持一个或者两个值，对于普通的2节点（2-node），保存1个key和左右两个子节点。对于3节点（3-node）,保存两个key,2-3查找树的定义如下：
1. 要么为空，或者：
2. 对于2节点，该节点保持一个key及对应的value，以及两个指向左右子节点的指针。
3. 对于3节点，该节点保存两个key及对应的value,以及左中右三个子节点，其左子节点所有值小于两个值的最小值，中子节点的值的大小在两个值之间，其右子节点的所有值比两个值的最大值大。
![](https://images0.cnblogs.com/blog/94031/201403/252248450292152.png) 

## 红黑树(Red-Black Tree)
红黑树是一种简单实现2-3树的数据结构。
### 定义
红黑树的主要是想对2-3查找树进行编码，尤其是对2-3查找树中的3-nodes节点添加额外的信息。红黑树中将节点之间的链接分为两种不同类型，红色链接，他用来链接两个2-nodes节点来表示一个3-nodes节点。黑色链接用来链接普通的2-3节点。特别的，使用红色链接的两个2-nodes来表示一个3-nodes节点，并且向左倾斜，即一个2-node是另一个2-node的左子节点。这种做法的好处是查找的时候不用做任何修改，和普通的二叉查找树相同。
![](https://images0.cnblogs.com/blog/94031/201403/270024368439888.png)
更具以上描述，红黑树定义如下：
红黑树是一种具有红色和黑色链接的平衡查找树，同时满足：
+ 红色节点向左倾斜
+ 一个节点不能有两个红色链接
+ 整个树完全黑色平衡，即从根节点到所以叶子结点的路径上，黑色链接的个数都相同

另一种说法：
+ 每个节点要么是红色，要么是黑色；
+ 根节点永远是黑色的；
+ 所有的叶节点都是是黑色的（注意这里说叶子节点其实是上图中的 NIL 节点）；
+ 每个红色节点的两个子节点一定都是黑色；
+ 从任一节点到其子树中每个叶子节点的路径都包含相同数量的黑色节点；
![](https://img-blog.csdn.net/20161123195416588)

## 字典树（Trie）
Trie树，又叫字典树，前缀树（Prefix Tree），是一种多叉树结构。如下图：
![](https://img-blog.csdn.net/20150509003807271)
上图是一颗Trie树，表示关键字集合{"a","to","tea","ted","ten","i","in","inn"}.从上图可知Trie树的基本性质：
1. 更节点不包含字符，出根节点外的每个子节点都包含一个字符。
2. 从根节点到某一个子节点，路径上经过的字符串连接起来，为该节点对应的字符串。
3. 每个节点的所有子节点包含的字符互不相同。

通常在实现的时候，会在节点结构中设置一个标准，用来标记该节点是否构成一个单词。
可以看出，Trie树的关键字一般都是字符串，而且Trie树把每个关键字保存在一条路径上，而不是一个结点中。另外，两个有公共前缀的关键字，在Trie树中前缀部分的路径相同，所以Trie树又叫做前缀树（Prefix Tree）。
### Trie树的优缺点
Trie树的核心思想是空间换时间，利用字符串的公共前缀来减少字符串的比较以达到提高查询效率的目的。
优点：
1. 插入和查询的效率很高，都为O（m）,其中m为插入和查询的字符串的长度。
2. Trie树中不同的关键字不会产生冲突。
3. Trie树只有在允许一个关键字关联多个值时才会产生类似hash碰撞。
4. Trie树不用求hash值，对短字符串有更快的速度。通常，求hash值也需要遍历字符串。
5. Trie树可以对关键字按字典序排序。

缺点：
1. 如果hash函数足够好，Trie树的查找效率会低于hash
2. 空间消耗较大
### Trie树的应用
+ 字符串的检索
+ 词频统计
+ 字符串的排序
+ 前缀匹配

## hash表
哈希表是一种以键值（key-indexed）存储数据的结构，我们只要输入待查找的值即key,即可超导相对应的值。
哈希的思路很简单，如果所有的键都是整数，那么就可以使用一个简单的无序数组来实现：将键作为索引，值即为预期对应的值，这样就可以快速访问任意键的值。这是对于简单的键的情况，我们将其扩展到可以处理更加复杂的类型的键。
使用hash查找有两个步骤：
1. 使用hash函数将被查找的键转换为数组的索引。在理想的情况下，不同的键会被转换为不同的索引值，但是在有些情况下我们需要处理多个键被哈希到同一个索引值的情况。
2. 处理哈希碰撞冲突。

哈希表是一个在空间和时间上做出权衡的经典例子。如果没有内存限制，那么可以直接将键作为数组的索引。那么所有的查找时间复杂度都是O(1)；如果没有时间的限制，那么我们可以对无序数组进行顺序查找，这样只需要很少的内存。哈希表使用适度的时间和空间类在这两个极端之间找到了平衡，只需要调整哈希函数算法即可在时间和空间上做出取舍。
### 哈希函数
哈希查找第一步就是使用哈希函数将键映射成索引。这种映射函数就是哈希函数。我如果我们有一个保持0-M数组，呢吗我们就需要一个将任意值转换为该数组范围ide索引的哈希函数。哈希函数需要易于计算并且能够均匀分布所有键。比如一个简单的例子，使用 手机号码的后三位就比前2为作为key要好，因为前3为的重复率很高。
#### 1.正整数
获取正整数哈希值最常用的方法是使用除留余数法。即对于大小为素数M的数组，对于任意正整数K,计算K除以M的余数。M一般取素数。
#### 2.字符串
将字符串作为键的时候，我们也可以将它视作一个大的整数，采用保留除余法。我们可以对每个字符取值进行哈希。比如

	int getHashCode(string str)
	{
		int hash = 0;
		for(int i =0;i<strlen(s);i++)
		{
			hash = s[i]+(31*hash);
		}
		return hash;
	}
上面的哈希值是Horner计算字符串哈希值的方法。
对每个字符去取哈希值比较耗时，所以可以通过间隔取N个字符来获取哈希值节省时间。比如：
		
	int getHashCode(string str)
	{
		int hash = 0;
		int skip = max(1,strlen(s)/8);
		for(int i =0;i<strlen(s);i+=skip)
		{
			hash = s[i]+(31*hash);
		}
		return hash;
	}

### 避免哈希冲突
#### 拉链法（Separate chaining with linked lists）
通过哈希函数，我们可以将键转换为数组的索引（0-M-1），但是对于两个或者多个键具有相同值的索引，我们需要有一种方法来处理冲突。
一种比较直接的解决方法是，将大小为M的数组的每个元素指向一个链表，链表中的每个点都存储散列值为该索引的键值对，这就是拉链法。
![](https://images0.cnblogs.com/blog/94031/201410/312300382371659.png)
图中，"John Smith"和"Sandra Dee"通过哈希函数都指向152这个索引，该索引又指向一个链表，链表中依次存储这两个字符串/
该方法的基本思想就是选择足够大的M,使得所有链表都经可能的短小，以保证查找效率。对于采用拉链法的哈希实现查找分为两步，首先是根据散列值找到相应的链表，然后沿着无序链表顺序查找到相应的键。
#### 线性探测法
线性探测法是开放寻址法解决哈希冲突的一种方法。其本的原理为，使用大小为M的数组来保存N个键值对，其中M>N,我们需要使用数组中的空位来解决碰撞冲突。如下图所示：
![](https://images0.cnblogs.com/blog/94031/201410/312300528784418.png)
对照前面的拉链法，在该图中，”Ted Baker” 是有唯一的哈希值153的，但是由于153被”Sandra Dee”占用了。而原先”Snadra Dee”和”John Smith”的哈希值都是152的，但是在对”Sandra Dee”进行哈希的时候发现152已经被占用了，所以往下找发现153没有被占用，所以存放在153上，然后”Ted Baker”哈希到153上，发现已经被占用了，所以往下找，发现154没有被占用，所以值存到了154上
开放寻址法中最简单的是线性探测法：当碰撞发生时即一个键的散列值被另外一个键占用时，直接检查散列表中的下一个位置即将索引值加1，这样的线性探测会出现三种结果：
+ 命中，该位置的键和被查找的键相同
+ 未命中，键为空
+ 继续查找，该位置和键被查找的键不同。

实现线性探测法也很简单，我们只需要两个大小相同的数组分别记录key和value
线性探查（Linear Probing）方式虽然简单，但是有一些问题，它会导致同类哈希的聚集。在存入的时候存在冲突，在查找的时候冲突依然存在
#### 性能分析
我们可以看到，哈希表存储和查找数据的时候分为两步，第一步为将键通过哈希函数映射为数组中的索引， 这个过程可以认为是只需要常数时间的。第二步是，如果出现哈希值冲突，如何解决，前面介绍了拉链法和线性探测法下面就这两种方法进行讨论：

对于拉链法，查找的效率在于链表的长度，一般的我们应该保证长度在M/8~M/2之间，如果链表的长度大于M/2，我们可以扩充链表长度。如果长度在0~M/8时，我们可以缩小链表。

对于线性探测法，也是如此，但是动态调整数组的大小需要对所有的值从新进行重新散列并插入新的表中。

不管是拉链法还是散列法，这种动态调整链表或者数组的大小以提高查询效率的同时，还应该考虑动态改变链表或者数组大小的成本。散列表长度加倍的插入需要进行大量的探测， 这种均摊成本在很多时候需要考虑。

## B树
## 跳表
## 总结
![](https://images0.cnblogs.com/blog/94031/201410/312301180197071.png)
