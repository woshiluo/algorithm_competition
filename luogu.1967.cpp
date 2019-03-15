#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 11000;
const int M = 51000;

int n, m, q, x, y, z;

class kruskal_tree{
	public:
		int ecnt_normal;
		struct edge_normal{
			int now, to, val;
			bool operator < (edge_normal &b) const{
				return this -> val > b.val;	
			}
		}e_normal[M << 1];
		struct uds{
			int fa[N << 2];
			inline void init(int n){n <<= 1;for(int i = 0; i <= n; i++) fa[i] = i;}
			int& operator[](int now){return fa[now];}
			inline int get_fa(int now){return fa[now] == now ? now: fa[now] = get_fa(fa[now]);};
		}set; 
		class Graph{	
			public:
				int idcnt, ecnt, ehead[N << 1];
				struct node{
					int val, son, mson, top, id, dep, fa;
				}nodes[N << 1];
				struct edge{
					int now, to, next;
				}e[M << 1];
				inline void add_edge(int now, int to);
				void find_son(int now);
				void get_edges(int now, int dep);
				void init(int now);
				int lca(int from, int to);
		}G;
		inline void add_edge_normal(int now, int to, int val);
		void build_tree(int &n);
		inline void init(int n);
}T;

void kruskal_tree::Graph::find_son(int now){
	if(now == 0) return ;
	nodes[now].son = 1;
	nodes[now].mson = 0;
	for(int i = ehead[now]; i; i = e[i].next){
		find_son(e[i].to);	
		nodes[now].son += nodes[now].son;
		if(nodes[ e[i].to ].son > nodes[ nodes[now].mson ].son)
			nodes[now].mson = e[i].to;
	}	
}

void kruskal_tree::Graph::get_edges(int now, int dep){
	if(now == 0) return ;
	nodes[now].id = ++idcnt;
	nodes[now].dep = dep;
	if(nodes[now].top == 0) nodes[now].top = now;
	if(nodes[now].mson == 0) return ;			
	nodes[ nodes[now].mson ].top = nodes[now].top;
	get_edges(nodes[now].mson, dep + 1);
	for(int i = ehead[now]; i; i = e[i].next){
		if(e[i].to == nodes[now].mson) 
			continue;
		nodes[ e[i].to ].fa = now;
		get_edges(e[i].to, dep + 1);
	}
}

void kruskal_tree::Graph::init(int now){
	nodes[0].son = -1;
	idcnt = 0;
	find_son(now);
	get_edges(now, 1);
}

int kruskal_tree::Graph::lca(int from, int to){
	while(nodes[from].top != nodes[to].top){
		if(nodes[ nodes[from].top ].dep < nodes[ nodes[to].top ].dep){
			int tmp = to; to = from; from = tmp;
		}
		from = nodes[ nodes[from].top ].fa;
	}	
	if(nodes[from].dep > nodes[to].dep){
		int tmp = to; to = from; from = tmp;
	}
	return from;
}

inline void kruskal_tree::add_edge_normal(int now, int to, int val){
	ecnt_normal++;
	e_normal[ecnt_normal].now = now;
	e_normal[ecnt_normal].to = to;
	e_normal[ecnt_normal].val = val;
}

inline void kruskal_tree::Graph::add_edge(int now, int to){
	ecnt++;
	e[ecnt].to = to;
	e[ecnt].next = ehead[now];
	ehead[now] = ecnt;
}

void kruskal_tree::build_tree(int &n){
	int tmp_cnt = n;
	set.init(n);
	std::sort(e_normal + 1, e_normal + ecnt_normal + 1);
	for(int i = 1; i <= ecnt_normal; i++){
		int tmp_x = set.get_fa(e_normal[i].now), tmp_y = set.get_fa(e_normal[i].to);
		if(tmp_x != tmp_y){
			tmp_cnt++;		
			G.nodes[tmp_cnt].val = e_normal[i].val;
			G.add_edge(tmp_cnt, tmp_y);
			G.add_edge(tmp_cnt, tmp_x);
			set[tmp_x] = tmp_cnt;
			set[tmp_y] = tmp_cnt;
		}
	}
	n = tmp_cnt;
}

inline void kruskal_tree::init(int n){
	build_tree(n);
	G.init(n);
}

int main(){
#ifdef woshiluo
	freopen("luogu.1967.in", "r", stdin);
	freopen("luogu.1967.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);	
	for(int i = 1; i <= m; i++){
		scanf("%d%d%d", &x, &y, &z);					
		T.add_edge_normal(x, y, z);
		//T.add_edge_normal(y, x, z);
	}
	for(int i = 1; i <= n; i++){
		T.add_edge_normal(n + 1, i, -1);
	}
	m += n;
	T.init(n);
	scanf("%d", &q);
	while(q--){
		scanf("%d%d", &x, &y); 
		printf("%d\n", (T.G.nodes[ T.G.lca(x, y) ]).val);
	}
}
