#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void dfs(int node,vector<vector<int>>&adj,vector<bool>&visited){
	cout<<node<<" ";
	visited[node] = true;
	for(int neighbour : adj[node]){
		if(!visited[neighbour]){
			dfs(neighbour,adj,visited);
		}
	}
}

void bfs(queue<int>&q,vector<vector<int>>&adj,vector<bool>&visited){
	if(q.empty()){
		return;
	}
	int node = q.front();
	q.pop();
	cout<<node<<" ";
	
	for(int neighbour : adj[node]){
		if(!visited[neighbour]){
			visited[neighbour] = true;
			q.push(neighbour);
		}
	}
	
	bfs(q,adj,visited);
}
int main(){
	int v = 6;
	vector<vector<int>> adj(v);
	adj[0] = {1,2,3};
	adj[1] = {0,2};
	adj[2] = {0,1,3,4};
	adj[3] = {0,2,4,5};
	adj[4] = {2,3,5};
	adj[5] = {3,4};
	vector<bool> visitedDfs(v,false);
	cout<<"DFS is : ";
	dfs(1,adj,visitedDfs);
	cout<<endl;
	
	queue<int> q;
	q.push(1);
	vector<bool> visitedBfs(v,false);
	visitedBfs[1] = true;
	cout<<"BFS is : ";
	bfs(q,adj,visitedBfs);
	cout<<endl;
}

