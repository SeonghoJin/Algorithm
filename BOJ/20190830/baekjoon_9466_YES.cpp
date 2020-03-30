#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int N;
char str[300001];
int ans[300001];
int pos[300001];
int sa[300001],d=1;
int visit[300001];
vector<pair<int,int>> v;

bool cmp(int i, int j){
	if(pos[i]!=pos[j])return pos[i] < pos[j];
	i+=d;
	j+=d;
	return i < N && j < N ? pos[i] < pos[j] : i > j;
}

void findstr(char* s,int n = 0,int a = 0, int b = N-1){;
	if(s[0] =='\0'){ 
		for(int i = a; i <= b; i++){
			int k = sa[i];
			v.push_back(make_pair(k,k+n));
		}
		return;		   
	}
	
	int ta = -1;
	int tb = -1;
	for(int start = a, end = b; start<=end; ){
		int mid = (start+end)/2;
		if(sa[mid] + n > N){
			start = mid + 1; 
			continue;
		}
		if( str[sa[mid]+n]==s[0] && (sa[mid-1]+n >= N || mid == a || (sa[mid-1]+n < N && mid > 0  && s[0] > str[sa[mid-1]+n]) ) ){
			ta = mid;
			break;
		}
		else{
			if((str[sa[mid]+n] == s[0] && (sa[mid-1]+n < N && str[sa[mid-1]+n] == s[0])) || str[sa[mid]+n] > s[0]){
				end = mid - 1;
			}
			else{
				start = mid + 1;
			}
		}
		
	}
	
	for(int start = a, end = b; start<=end;){
		int mid = (start+end)/2;
		if(sa[mid]+n > N){
			start = mid + 1;
			continue;
		}
		if( str[sa[mid]+n]==s[0] && (sa[mid+1]+n >= N || mid == b || (mid < b  && sa[mid+1]+n  < N && s[0] < str[sa[mid+1]+n]) ) ){
			tb = mid;
			break;
		}
		else{
			if((str[sa[mid]+n] == s[0] &&(sa[mid+1]+n < N  && str[sa[mid+1]+n] == s[0])) || str[sa[mid]+n] < s[0]){
				start = mid + 1;
			}
			else{
				end = mid - 1;
			}
		}
		
	}
	
	if(ta == -1 || tb == -1)return;
	findstr(s+1,n+1,ta,tb);
}

int main(){
	
	scanf("%d %s",&N, str);
	
	for(int i = 0; i < N; i++){
		sa[i]=i;
		pos[i]=str[i];
	}
	
	while(1){
		sort(sa,sa+N,cmp);
		
		int temp[300001];
		
		for(int i = 1; i < N; i++){
			temp[i] = temp[i-1]+cmp(sa[i-1],sa[i]);
		}
		
		for(int i = 0; i < N; i++){
			pos[sa[i]]=temp[i];
		}
		
		if(temp[N-1] == N-1)break;
		d*=2;
	}
	int T;
	scanf("%d",&T);
	char c[5001];
	while(T--){
		scanf("%s",c);
		findstr(c);
	}
	
	sort(v.begin(), v.end());
	
	if(v.size() != 0){
		
		int ta = v[0].first;
		int tb = v[0].second;
		
		for(int i = 0; i < v.size()-1; i++){
		
		int tc = v[i+1].first;
		int td = v[i+1].second;
		
		if(tb >= tc){tb = max(tb,td);}
		else{
			for(int i = ta; i < tb; i++){
				ans[i] = 1;
			}
			ta = v[i+1].first;
			tb = v[i+1].second;
		}
			}
		
		for(int i = ta; i < tb; i++){
			ans[i] = 1;
		}
	
	}
	
	int sum = 0;
	for(int i = 0; i < N; i++){
		if(ans[i] == 0)sum++;
	}
	printf("%d",sum);
	
}