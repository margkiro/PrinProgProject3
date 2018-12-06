/*
 **********************************************
 *  CS314 Principles of Programming Languages *
 *  Fall 2018                                 *
 *  File: oneway.c                            *
 *  Date: 11/25/2018                          *
 **********************************************
 */
#include "oneway.h"
#include "utils.h"

void extend_one_hand(int threadId, int threadNum, GraphData graph,
                     int nodeNum, int *nodeToProcess,
                     int *res, int *strongNeighbor)
{
    /* Your Code Goes Here*/
    int i = threadId;
    int wordChunk = (nodeNum+threadNum-1)/threadNum;
    int begin = i*wordChunk;
    int end;
    if((begin+wordChunk)>nodeNum){
    	end = nodeNum;
    }else{
    	end = (begin+wordChunk);
    }
    int v;
    int j;
    for(j = begin; j<end; j++){
		v = nodeToProcess[j];
		int *N = graph.index + graph.offset[v];
		int m;
		int u;
		strongNeighbor[v] = -1;
		for(m = 0; m<graph.degree[v]; m++){
			u = N[m];
			if(res[u] == -1){
				strongNeighbor[v]=u;
				break;			
			}
		}
    }
}

void check_handshaking(int threadId, int threadNum,
                       int nodeNum, int *nodeToProcess,
                       int *strongNeighbor, int *res)
{
    /* Your Code Goes Here*/ 
    int i = threadId;
    int wordChunk = (nodeNum+threadNum-1)/threadNum;
    int begin = i*wordChunk;
    int end;
    if((begin+wordChunk)>nodeNum){
    	end = nodeNum;
    }else{
    	end = (begin+wordChunk);
    }
    int v;
    int j;
    int s;
    for(j = begin; j<end; j++){
		v = nodeToProcess[j];
		s = strongNeighbor[v];
		if(s == -1) {
			res[v]=-2;
		}
		else if(v == strongNeighbor[s]){
			res[v]=s;
		}
	}
}


