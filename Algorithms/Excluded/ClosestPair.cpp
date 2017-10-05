#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <cmath>
using namespace std;
double dist(pair<int,int> p, pair<int,int> q)
{
	return sqrt(pow(p.first - q.first, 2) + pow(p.second - q.second, 2) );
}
tuple<double, pair<int,int>, pair<int,int> > ClosestPair(const vector<pair<int,int> > &Px, const vector<pair<int,int> > &Py)
{
	tuple<double, pair<int,int>, pair<int,int> >t;
	if(Px.size() == 2)
	{
		t = make_tuple(dist(Px[0], Px[1]), Px[0], Px[1]);
		return t;
	}
	if(Px.size() == 3)
	{
		double a = dist(Px[0], Px[1]), b = dist(Px[1], Px[2]), c = dist(Px[2], Px[0]);
		if(a <= b && a <= c)
			t = make_tuple(a, Px[0], Px[1]);
		else if (b <= c && b <= a)
			t = make_tuple(b, Px[1], Px[2]);
		else t = make_tuple(c, Px[3], Px[1]);
		return t;
	}
	vector<pair<int,int> > Qx(Px.begin(), Px.begin() + Px.size()/2),
			Rx(Px.begin() + Px.size()/2, Px.end()), Qy, Ry;
	int xmid = Qx[Qx.size()-1].first;
	for(int i=0; i<Py.size(); i++)
		if(Py[i].first <= xmid)
			Qy.push_back(Py[i]);
		else Ry.push_back(Py[i]);

	auto t1 = ClosestPair(Qx, Qy); double dq = get<0>(t1);
	auto t2 = ClosestPair(Rx, Ry); double dr = get<0>(t2);
	int d = ceil(min(dq, dr));

	vector<pair<int,int> > Sy;

	int i = 0, j = 0;
	while(i < Qy.size() && j < Ry.size())
	{
		if(Qy[i].first < xmid - d)
		{
			i++; continue;
		}
		if(Ry[j].first > xmid + d)
		{
			j++; continue;
		}
		if(Qy[i].second <= Ry[j].second)
			Sy.push_back(Qy[i++]);
		else if(Qy[i].second > Ry[j].second)
			Sy.push_back(Ry[j++]);
	}
	while(i < Qy.size() && Qy[i].first >= xmid - d)
		Sy.push_back(Qy[i++]);
	while(j < Ry.size() && Ry[j].first <= xmid + d)
		Sy.push_back(Ry[j++]);

	double minm; pair<int,int>a, b;
	double ds = 0;
	for(int i=0; i<Sy.size(); i++)
	{
		minm = DBL_MAX;
		for(j = i+1; j <= min((int)(Sy.size()-1), 15); j++)
		{
			ds = dist(Sy[i], Sy[j]);
			if(ds < minm)
			{
				minm = ds;
				a = Sy[i];
				b = Sy[j];
			}
		}
	}
	ds = floor(minm);
	if(ds <= dq && ds <= dr)
		t = make_tuple(ds, a, b);
	else if(dq <= ds && dq <= dr)
		t = t1;
	else t = t2;
	return t;
}
bool lesserX(pair<int,int> a, pair<int,int>b)
{
	return a.first < b.first;
}
bool lesserY(pair<int,int> a, pair<int,int>b)
{
	return a.second < b.second;
}
int main()
{
	int n;
	cin >> n;
	vector<pair<int, int> > pts(n);
	for(int i=0; i<n; i++)
	{
		int a, b;
		cin >> a >> b;
		pts[i] = make_pair(a,b);
	}
	vector<pair<int,int> > Px(pts.begin(), pts.end()), Py(pts.begin(), pts.end());
	sort(Px.begin(), Px.end(), lesserX);
	sort(Py.begin(), Py.end(), lesserY);
	auto t = ClosestPair(Px, Py);
	cout << get<0>(t) << " (" << get<1>(t).first << ", " << get<1>(t).second << ") ("
			<< get<2>(t).first << ", " << get<2>(t).second << ")" << endl;

}
