#include <iostream>
#include <climits>

/*

对于某32bit的输入和一个32bit数组，找到与其中与它异或结果最大的值

*/

using namespace std;
//静态树
typedef long long ll;
const int M=32;
const int N=M*1e5;
//树结点
struct Node
{
    int l,r;
    ll val;

    void init()
    {
        l=-1;
        r=-1;
    }
}node[N];
int p;//p 用于指向静态数组为静态树分配空间
ll t[M];//t数组分别为2**i   用于异或取对应位的值
void insert(int &root,int deep,ll va)
{
    if (root==-1)
    {
        root=p++;
        node[root].init();
    }
	//32位长的数据插入到了最低的叶子结点
    if (deep==0)
    {
        node[root].val=va;
        return ;
    }
	//该位是0 或 1
    if ((va&t[deep-1]))
    {
        insert(node[root].r,deep-1,va);
    }
    else
    {
        insert(node[root].l,deep-1,va);
    }

}

// 孩子指针不为空 比存在叶子结点
void findval(int root,int deep,ll va)
{
    if (deep==0)
    {
        cout << node[root].val;
        return;
    }
	//左右走
    if (((va&t[deep-1])&&node[root].l!=-1)||node[root].r==-1)
    {
        findval(node[root].l,deep-1,va);
    }
    else
    {
        findval(node[root].r,deep-1,va);
    }
}
int main()
{
    t[0]=1;

    for (int i=1;i<M;i++)
    {
        t[i]=t[i-1]<<1;
    }

    int cas,n,m;
    cin>>cas;
    for (int i=0;i<cas;i++)
    {
        cin>>n>>m;
        root=-1;
		//p 从新指向数组第一个元素
        p=0;
        ll temp;
        for (int j=0;j<n;j++)
        {
            cin>>temp;
            insert(root,33,temp);//树高32 则需要33次 根结点为2**0

        }
        for (int j=0;j<m;j++)
        {
            cin>>temp;
            findval(root,33,temp);
        }

    }
}






//#include <cstdio>
//#include <cstring>
//#include <iostream>
//
//using namespace std;
////typedef __int64 ll;
//typedef long long ll;
//
//const int M = 55;
//const int N = M*1e5;
//
//struct Node {
//    ll val;
//    int l;
//    int r;
//
//    void clear() {
//        l = r = -1;
//    }
//}node[N];
//
//int p;
//ll a, t[M];
//
//void insert (int& root, int d, ll u) {
//
//    if (root == -1) {
//        root = p++;
//        node[root].clear();
//    }
//
//    if (d == -1) {
//        node[root].val = u;
//        return;
//    }
//
//    if (u & t[d])
//        insert(node[root].r, d - 1, u);
//    else
//        insert(node[root].l, d - 1, u);
//}
//
//void query(int root, int d, ll u) {
//
//    if (d == -1) {
//        printf("%lld\n", node[root].val);
//        return;
//    }
//
//    if (((u & t[d]) && node[root].l != -1) || node[root].r == -1)
//        query(node[root].l, d - 1, u);
//    else
//        query(node[root].r, d - 1, u);
//}
//
//int main () {
//    int cas, n, m;
//    scanf("%d", &cas);
//
//    t[0] = 1;
//    for (int i = 1; i < 55; i++)
//        t[i] = t[i-1] * 2;
//
//    for (int i = 1; i <= cas; i++) {
//        p = 0;
//        int root = -1;
//
//        scanf("%d%d", &n, &m);
//        for (int j = 0; j < n; j++) {
//            scanf("%lld", &a);
//            insert(root, 50, a);
//        }
//
//        printf("Case #%d:\n", i);
//        for (int j = 0; j < m; j++) {
//            scanf("%lld", &a);
//            query(root, 50, a);
//        }
//    }
//    return 0;
//}
