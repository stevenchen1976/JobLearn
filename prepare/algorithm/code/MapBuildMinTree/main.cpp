#include "MapBuildMinTree1.hpp"
#include "MapBuildMinTree2.hpp"
using namespace std;


/* 图最小生成树-----Kruskal算法,Prim算法
 *
 * 图的相关概念:
 * 连通图:在无向图中,若任意两个顶点vi与vj都有路径相通,则称该无向图为连通图.
 * 强连通图:在有向图中,若任意两个顶点vi与vj都有路径相通,则称该有向图为强连通图.
 * 连通网:在连通图中,若图的边具有一定的意义,每一条边都对应着一个数,称为权;权代表着连接连个顶点的代价,称这种连通图叫做连通网.
 * 生成树:一个连通图的生成树是指一个连通子图,它含有图中全部n个顶点,但只有足以构成一棵树的n-1条边.一颗有n个顶点的生成树有且仅有n-1条边,如果生成树中再添加一条边，则必定成环.
 * 最小生成树:在连通网的所有生成树中,所有边的代价和最小的生成树,称为最小生成树.
 *
 * */


int main() {
    TestMapBuildMinTree1();         //图最小生成树-----Kruskal算法
    TestMapBuildMinTree2();         //图最小生成树-----Prim算法
}
