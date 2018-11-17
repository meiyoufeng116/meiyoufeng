#include <stdio.h>
#include <iostream>
#include <string>
#define INFINITY INT_MAX						//最大值∞
#define MAX_VERTEX_NUM 20						//最大顶点个数 

/* 图、表的数组（邻接矩阵）表示法类型定义 */
typedef enum{ DG, DN, UDG, UDN }GraphKind;		//0-有向图，1-有向网（带权值），2-无向图，3-无向网（带权值）
typedef struct{ }InfoType;						//弧相关信息
typedef int VRType;								//图、表顶点关系类型 
typedef struct ArcCell
{
	VRType adj;									//带权图中表示权值，无权图中用0、1表示是否相邻
	InfoType info;								//该弧相关信息，可以忽略 
}ArcCell;
typedef ArcCell AdjMatrix[MAX_VERTEX_NUM+1][MAX_VERTEX_NUM+1]; //邻接矩阵 

/* 图、表（数组表示法）的存储表示 */
typedef char VertexType_M;				//图、表顶点类型 
typedef struct
{
	VertexType_M vexs[MAX_VERTEX_NUM+1];//顶点向量
	AdjMatrix arcs;						//邻接矩阵
	int vexnum,	arcnum;					//图、表的当前顶点数和弧数
	int IncInfo;						//IncInfo为0则各弧不含其它信息 
	GraphKind kind;						//图、表的种类标志 
    }MGraph;

/* 全局变量 */
