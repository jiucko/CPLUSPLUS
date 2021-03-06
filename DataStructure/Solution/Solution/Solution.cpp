#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

 class Solution {
public:
	string longestCommonPrefix(vector<string>& strs)
	{
		std::string prefix = "";
		if (strs.empty())
		{
			return prefix;
		}

		for (int i = 0; i< strs[0].size(); i++)
		{
			char temp = strs[0][i];
			bool flag = false;
			for (int j = 0; j< strs.size(); j++)
			{
				if (i >= strs[j].size() || strs[j][i] != temp)
				{
					flag = true;
					break;
				}

				if (j == strs.size() - 1)
				{
					prefix += temp;
				}
			}

			if (flag)
			{
				break;
			}
		}

		return prefix;
	}


	vector<vector<int>> threeSum(vector<int>& nums)
	{
		std::sort(nums.begin(), nums.end());

		vector<vector<int>> result;

		if (nums.size() < 3)
		{
			return result;
		}

		auto func = [&result](vector<int>vec)->bool
		{
			bool isfound = false;

			for (int i = 0; i < result.size(); i++)
			{
				for (int j = 0; j < result[i].size(); j++)
				{
					if (result[i][j] != vec[j])
					{
						break;
					}

					if (j == result[i].size() - 1)
					{
						isfound = true;
					}
				}

				if (isfound)
				{
					break;
				}
			}

			return isfound;
		};

		for (int i = 0; i < nums.size() - 2; i++)
		{
			if (i >= 1 && nums[i] == nums[i - 1])
			{
				continue;
			}

			int k = nums.size() - 1;
			int j = i + 1;

			while (j < k && j < nums.size() - 1)
			{
				if (j >= i + 2 && nums[j] == nums[j - 1])
				{
					j++;
					continue;
				}

				if (k < nums.size() - 1 && nums[k] == nums[k + 1])
				{
					k--;
					continue;
				}


				if (nums[i] * (-1) == nums[k] + nums[j])
				{
					vector<int> tmp;

					tmp.push_back(nums[i]);
					tmp.push_back(nums[j]);
					tmp.push_back(nums[k]);

					// if(!func(tmp))
					{
						result.push_back(tmp);
					}
					break;
				}
				else if (nums[i] * (-1) > nums[k] + nums[j])
				{
					j++;
				}
				else if (nums[i] * (-1) < nums[k] + nums[j])
				{
					k--;
				}
			}


		}

		return result;
	}
};

 double betsy(int lns)
 {
	 return 0.05*lns;
 }

 double pam(int lns)
 {
	 return 0.03 * lns * 0.004 * lns * lns;
 }

 void estimate(int lines, double(*pf)(int))
 {
	 cout << lines << "lines will take" << endl;
	 cout << (*pf)(lines) << "hours" << endl;
	 cout << (pf)(lines) << "hours" << endl;
 }


 void dec2bin(int num, int* bin) {
	 for (int i = 31; i >= 0; i--) {
		 if (num & (1 << i))
			 bin[31 - i] = 1;
		 else
			 bin[31 - i] = 0;
	 }
 }

