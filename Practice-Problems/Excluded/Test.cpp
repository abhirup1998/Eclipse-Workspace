
/*
 * Test.cpp
 *
 *  Created on: 24-Sep-2017
 *      Author: eihpi
 */
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
typedef long long ll;
typedef pair <ll,ll > pr;
vector <pr> adj[10005];
bool visited[10005][10005];
int main(){
	ll n,m;
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=m;i++){
		ll u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		adj[u].push_back(make_pair(v,w));
		adj[v].push_back(make_pair(u,w));
	}
	ll source,destination;
	scanf("%lld%lld",&source,&destination);
	queue<ll> bfsq;
	bfsq.push(source);// source into queue
	bfsq.push(0);//
	while(!bfsq.empty()){
	ll u=bfsq.front();
		bfsq.pop();
		ll cost=bfsq.front();
		bfsq.pop();
		visited[u][cost]=true;
		for(ll i=0;i<adj[u].size();i++){
		  ll  v=adj[u][i].first;// neighbor of u is v
          ll  w2=adj[u][i].second;//// u is connected to v with this cost
          if(visited[v][w2|cost]==false){
          	visited[v][w2|cost]=true;
          	bfsq.push(v);
			bfsq.push(w2|cost);


		  }
		}
	}
	ll ans=-1LL;
	for(ll i=0;i<1024;i++){
		if(visited[destination][i]==true){
			ans=i;
			break;
		}
	}
	printf("%lld\n",ans);
	return 0;

}
