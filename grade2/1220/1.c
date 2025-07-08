#define MAXSIZE 114514

typedef struct arcNode{
	int adjvex; //指向的顶点编号
	struct arcNode *next; 
}ArcNode; //边的定义

typedef struct vNode{
	int data; //这个顶点存储的数据
	ArcNode *frist; //从这个顶点出发的边中的第一个
}VNode,AdjList[MAXSIZE];

typedef struct {
	AdjList vertices;
	int vex; //顶点数量
    int arc; //边数量
}ALGraph;

int LocateVex(ALGraph *G,int v){
	int i;
	for(i=0;i<=G->vex;i++) {
		if(G->vertices[i].data==v) return i;
    }
} 

