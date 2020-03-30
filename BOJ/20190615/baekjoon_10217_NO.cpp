/*
각고의 노력 끝에 찬민이는 2014 Google Code Jam World Finals에 진출하게 되었다. 구글에서 온 초대장을 받고 기뻐했던 것도 잠시, 찬찬히 읽어보던 찬민이는 중요한 사실을 알아차렸다. 최근의 대세에 힘입어 구글 역시 대기업답게 비용 감축에 열을 내고 있었던 것이다.

초대장 내용에 의하면 구글은 찬민에게 최대 M원까지의 비용만을 여행비로써 부담해주겠다고 한다. 인천에서 LA행 직항 한 번 끊어주는게 그렇게 힘드냐고 따지고도 싶었지만, 다가올 결승 대회를 생각하면 대회 외적인 곳에 마음을 쓰고 싶지 않은 것 또한 사실이었다. 그래서 찬민은 인천에서 LA까지 M원 이하로 사용하면서 도착할 수 있는 가장 빠른 길을 차선책으로 택하기로 하였다.

각 공항들간 티켓가격과 이동시간이 주어질 때, 찬민이 인천에서 LA로 갈 수 있는 가장 빠른 길을 찾아 찬민의 대회 참가를 도와주자.

입력
입력 파일의 첫 번째 줄에 테스트 케이스의 수를 의미하는 자연수 T가 주어진다. 그 다음에는 T개의 테스트 케이스가 주어진다.

각 테스트 케이스의 첫 줄에는 공항의 수 N (2 ≤ N ≤ 100), 총 지원비용 M (0 ≤ M ≤ 10,000), 티켓정보의 수 K (0 ≤ K ≤ 10,000)가 공백으로 구분되어 주어진다. 이어서 K개의 줄에 걸쳐 각 티켓의 출발공항 u, 도착공항 v (1 ≤ u, v ≤ N, u ≠ v), 비용 c (1 ≤ c ≤ M, 정수), 그리고 소요시간 d (1 ≤ d ≤ 1,000) 가 공백으로 구분되어 주어진다. 인천은 언제나 1번 도시이고, LA는 언제나 N번 도시이다
*/
/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using point = pair<int,int>;
using pip = pair<int, point>;



int limit=987654321;
int T,N,M,K;

pip make_three(int a,int b, int c){
	return make_pair(a,make_pair(b,c));
}

void dijkstra(vector<vector<pip> > tickets){
	
	vector<point> limit_times_money(101,make_pair(limit,0));
	limit_times_money[1].first = 0;
	priority_queue<pip> pq;
	// 시간 돈 번호 순서
	pq.push(make_three(0,0,1));
	
	while(!pq.empty()){
		int num = pq.top().second.second;
		int time = -pq.top().first;
		int money = pq.top().second.first;
		pq.pop();
		
		if(time > limit_times_money[num].first)continue;
		
		for(int i = 0; i < tickets[num].size(); i++){
			int nextnum = tickets[num][i].first;
			int nexttime = tickets[num][i].second.second + time;
			int nextmoney = tickets[num][i].second.first + money;
			
			if(nextmoney > N) continue;
			if(nexttime < limit_times_money[nextnum].first){
				limit_times_money[nextnum].first = nexttime;
				limit_times_money[nextnum].second = nextmoney;
				pq.push(make_three(-nexttime,nextmoney,nextnum));
			}
			
			
		}
		
	}
	
	if(limit_times_money[N].first >= limit)cout << "Poor KCM" << '\n';
	else cout << limit_times_money[N].first << '\n';
	
	
}

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	cin >> T;
	
	while(T--){
		cin >> N >> M >> K;
		vector<vector<pip> > tickets(101,vector<pip>());
		for(int i = 0; i < K; i++){
			int a,b,c,d;
			cin >> a >> b >> c >> d;
			tickets[a].push_back(make_three(b,c,d));
		}
		
		dijkstra(tickets);
		
	}
}
*/