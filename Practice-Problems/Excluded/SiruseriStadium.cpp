/*
 * SiruseriStadium.cpp
 *
 *  Created on: 28-Sep-2017
 *      Author: eihpi
 */


#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
typedef pair<long, long> pr;
struct fcomp{
	bool operator()(const pr a, const pr b)const
	{
		if(a.second == b.second)
			return a.first < b.first;
		return a.second < b.second;
	}
}obj;
int main()
{   //int tc;
	//cin >> tc;
	//vector<int> ans;
	//for(int t=0; t<tc; t++)
	//{
		int n, cnt=0;
		cin >> n;
		vector<pr> tsk(n);
		//	vector<pr> atsk;
		for(int i=0; i<n; i++)
		{
			int a, b;
			cin >> a >> b;
			tsk[i] = make_pair(a,a+b);
		}
		sort(tsk.begin(), tsk.end(), obj);
		for(int i=0; i<n;)
		{
			//		atsk.push_back(tsk[i]);
			cnt++;
			int j = i+1;
			while(tsk[j].first < tsk[i].second && j < n)
				j++;
			i = j;
		}
		//	for(int i=0; i<atsk.size(); i++)
		//		cout << atsk[i].first << " " << atsk[i].second << endl;
		cout << cnt;
	//}
	//for(int t=0; t<tc; t++)
	//	cout << ans[t] << endl;
}
