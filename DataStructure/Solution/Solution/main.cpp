#include "stdafx.h"
#include <iostream>
#include "ListTest.h"
#include "ArrayStack.h"
#include "ListStack.h"
#include "ArrayQuene.h"
#include "ListQuene.h"
#include "BSTree.h"
#include <string>
#include <map>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>

using namespace std;

void testLinkList()
{
	LinkList* p1 = new LinkList;
	p1->createLinkList(5);
	p1->traverseLinkList();
	p1->insertNode(2, 5);
	p1->traverseLinkList();
	p1->deleteNode(4);
	p1->traverseLinkList();
	LinkList* p2 = p1->ReverseLinkList();
	p1->traverseLinkList();
	p2->traverseLinkList();
	p1->deleteLinkList();
	p2->deleteLinkList();
	p1->traverseLinkList();
}

void testArrayQuene()
{
	ArrayQuene<int> p(5);
	//init
	for (int i = 0; i < 5; i++)
	{
		p.push(i);
	}
	std::cout << p.front() << std::endl;
	std::cout << p.pop() << std::endl;
	std::cout << p.front() << std::endl;
	std::cout << p.size() << std::endl;
}

void testListStack()
{
	ListQuene<int> p;
	for (int i = 0; i < 5; i++)
	{
		p.push(i);
	}
	std::cout << p.front() << std::endl;
	std::cout << p.pop() << std::endl;
	std::cout << p.front() << std::endl;
	std::cout << p.size() << std::endl;
}

std::vector <std::string> letterCombinations(std::string digits)
{
	std::map<char, std::vector<std::string>> phone_info;
	std::vector<std::string> result;
	phone_info['2'] = { "a","b","c" };
	phone_info['3'] = { "d","e","f" };
	phone_info['4'] = { "g","h","i" };
	phone_info['5'] = { "j","k","l" };
	phone_info['6'] = { "m","n","o" };
	phone_info['7'] = { "p","q","r","s" };
	phone_info['8'] = { "t","u","v" };
	phone_info['9'] = { "w","x","y","z" };

	auto func = [&phone_info,&result](int i)
	{
		if (result.empty())
		{
			result = phone_info[i];
			return;
		}
		std::vector<std::string> tmp = result;
		result.clear();
		for (auto it : tmp)
		{
			for (auto iter : phone_info[i])
			{
				result.push_back(it + iter);
			}
		}
	};
	for (int i = 0; i < digits.size(); i++)
	{
		func(digits[i]);
	}
	
	return result;
}

ListNode* removeNthFromEnd(ListNode* head, int n)
{
	if (head == nullptr)
		return nullptr;

	ListNode* first = head;
	ListNode* behind = head;

	for (int i = 0; i < n; i++)
	{
		first = first->next;
	}

	if (!first) return head->next;

	while (first->next)
	{

		behind = behind->next;
		first = first->next;
	}

	//remove behind->next
	ListNode* tmp = behind->next;
	if (behind->next)
	{
		behind->next = tmp->next;
		delete tmp;
	}

	return head;
}

bool isValid(string s)
{
	std::stack<char> st;

	auto func = [&st](char ch)->bool
	{
		bool flag = true;

		if (ch == '(' || ch == '[' || ch =='{')
		{
			st.push(ch);
		}
		else
		{	
			if (st.empty())
			{
				flag = false;
			}
			else
			{
				if (((ch == ']') && st.top() == '[') || ((ch == ')') && st.top() == '(') || ((ch == '}') && st.top() == '{'))
				{
					st.pop();
				}
				else
				{
					flag = false;
				}
			}
		}

		return flag;
	};

	bool flag = true;
	for (int i = 0; i < s.size(); i++)
	{
		flag = func(s[i]);
		if (flag == false)
			break;
	}

	return flag && (st.size() == 0);
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
	ListNode* result = l1;
	
	if (l1->val > l2->val)
	{
		result = l2;
		l2 = l1;
	}
	ListNode* temp = result;
   
	while (temp->next && l2)
	{
		if (temp->next->val > l2->val)
		{
			ListNode* t = temp->next;
			temp->next = l2;
			l2 = l2->next;
			temp->next->next = t;
		}

		temp = temp->next;
	}
	if (temp->next == nullptr && l2)
	{
		temp->next = l2;
	}
	return result;
}
vector<string> generateParenthesis(int n)
{
	std::set<std::string> result;
	if (n == 0)
	{
		result.insert("");
	}
	else
	{
		std::vector<std::string> pre = generateParenthesis(n - 1);
		for (auto it : pre)
		{
			for (int i = 0; i < it.size(); i++)
			{
				if (it[i] == '(')
				{
					std::string str = it;
					str.insert(str.begin() + i+1, '(');
					str.insert(str.begin() + i + 2, ')');
					result.insert(str);
				}
			}
			result.insert("()"+it);
		}
	}

	return std::vector < std::string >(result.begin(), result.end());
}

ListNode* mergeKLists(vector<ListNode*>& lists)
{

	auto func = [&lists]()->ListNode*
	{
		int val = INT_MAX;
		ListNode ** pNode = nullptr;
		for (auto& it : lists)
		{
			if (it && it->val < val)
			{
				val = it->val;
				pNode = &it;
			}
		}
		ListNode *result = nullptr;
		if (pNode != nullptr)
		{
			result = *pNode;
			*pNode = (*pNode)->next;
		}
		return result;
	};
	ListNode* result = nullptr;
	ListNode* tmp = result;
	ListNode* t = func();
	while (t)
	{
		if (result == nullptr)
		{
			result = t;
			tmp = result;
		}
		else
		{
			tmp->next = t;
			tmp = tmp->next;
		}
		t = func();
	}
	return result;
}

void nextPermutation(vector<int>& nums) 
{
	int val = INT_MAX;
	int index = -1;
	for (int i = nums.size() - 1; i > 0; i--)
	{
		if (nums[i] > nums[i-1])
		{
			val = nums[i-1];
			index = i-1;
			break;
		}
	}
	if (index >= 0)
	{
		for (int i = nums.size() - 1; i >= 0; i--)
		{
			if (nums[i] > val)
			{
				int tmp = nums[i];
				nums[i] = val;
				nums[index] = tmp;
				break;
			}
		}
	}
	
	//×ªÖÃ
	for (int i = 0; i < nums.size(); i++)
	{
		if (i > index && i < nums.size() + index - i)
		{
			int tmp = nums[i];
			nums[i] = nums[nums.size() + index -i];
			nums[nums.size() + index - i] = tmp;
		}
	}
	

}

int longestValidParentheses(string s)
{
	std::stack<pair<char,int>> st;

	for (int i = 0; i < s.length(); i++)
	{
		if (st.empty()||s[i] == '(')
		{
			st.push(make_pair(s[i],i));
		}
		else
		{
			if (st.top().first == '(')
			{
				st.pop();
			}
			else
			{
				st.push(make_pair(s[i], i));
			}
		}
	}
	int result = 0;
	int last = s.length();

	while (!st.empty())
	{
		result = max(result, last-st.top().second-1 );
		last = st.top().second;
		st.pop();
	}
	result = max(result, last);
	return result;
}

int search(vector<int>& nums, int target)
{
	int left = 0;
	int right = nums.size() - 1;


	while (left <= right)
	{
		int middle = (right + left) / 2;
		if (nums[middle] == target)
		{
			return middle;
		}
		else
		{
			if (nums[middle] < nums[right])
			{
				if (target > nums[middle] && target <= nums[right])
				{
					left = middle +1;
				}
				else
				{
					right = middle-1;
				}
			}
			else
			{
				if (target >= nums[left] && target < nums[middle])
				{
					right = middle-1;
				}
				else
				{
					left = middle+1;
				}
			}
		}

	}
	return -1;
}

vector<int> searchRange(vector<int>& nums, int target)
{
	int left = 0;
	int right = nums.size() - 1;
	std::vector<int> result = { -1,-1 };
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (target > nums[mid] )
		{
			left = mid + 1;
		}
		else if (target < nums[mid])
		{
			right = mid - 1;
		}
		else
		{
			left = mid;
			right = mid;
			while (left - 1 >= 0 && nums[left - 1] == target)
			{
				left--;
			}
			while (right + 1 < nums.size() && nums[right +1] == target)
			{
				right++;
			}
			result.clear();
			result.push_back(left);
			result.push_back(right);
			break;
		}
	}
	return result;
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
{
	
}

int main()
{
	std::vector<int> nums = {1,1,3};

	std::vector<int> count = searchRange(nums,1);
	cout << count[0]<<"  "<<count[1];
	return 0;
}