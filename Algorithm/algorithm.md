# 常见算法
### 1.快慢指针  
1.概念  
快慢指针是指指定两个指针，其中快的指针的步数是慢的指针的两倍。  
在判断是否有环中，指针的移动通常为：  

	faster = faster->next->next;
	slower = slower->next;
2.应用
  
+ 判断链表是否有环及寻找环的入口  
+ 数组的寻找范围
+ 链表或数组中移除重复的元素
+ 寻找链表的中点或者中位数
+ 倒数第几个元素
  
3.注意
   
+ 链表长度的奇偶性
+ 如果快指针步速是慢指针的2倍，循环条件为：  
	
	faster->next!=nullptr && faster->next->next !=nullptr
+ 当自行设置快慢指针步长时。要考虑步长等于链表长度等边界情况/
