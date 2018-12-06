/*
 **********************************************
 *  CS314 Principles of Programming Languages *
 *  Fall 2018                                 *
 *  File: filter.c                            *
 *  Date: 11/25/2018                          *
 **********************************************
 */

#include "filter.h"

void count_unmatched_vertices(int threadId, int threadNum, int nodeNum,
                              int *nodeToProcess, int *res,
                              int *nodeCount)
{
    /* Your Code Goes Here*/
    int i = threadId;
    nodeCount[threadId]=0;
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
		if(res[v]==-1){
			nodeCount[i]++;
		}
	}
	
}

void update_remain_nodes_index(int threadId, int threadNum,
                               int *nodeToProcess, int *startLocations,
                               int *res,
                               int nodeNum, int *newNodeToProcess)
{
    /* Your Code Goes Here */
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
    int off;
    for(j = begin; j<end; j++){
		v = nodeToProcess[j];
		if(res[v]==-1){
				off = startLocations[i]++;
				newNodeToProcess[off]=v;
		}
	}
	
}
