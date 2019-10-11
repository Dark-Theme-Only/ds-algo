#include<iostream>
#include<queue>
#define NODE 6
using namespace std;

typedef struct node {
   int val;
   int state;    //status
}node;

int graph[NODE][NODE] = {
   {0, 1, 1, 1, 0, 0},
   {1, 0, 0, 1, 1, 0},
   {1, 0, 0, 1, 0, 1},
   {1, 1, 1, 0, 1, 1},
   {0, 1, 0, 1, 0, 1},
   {0, 0, 1, 1, 1, 0}
};

void bfs(node *vert, node s) {
   node u;
   int i, j;
   queue<node> que;

   for(i = 0; i<NODE; i++) {
      vert[i].state = 0;    //not visited
   }

   vert[s.val].state = 1;   //visited
   que.push(s);            //insert starting node

   while(!que.empty()) {
      u = que.front();    //delete from queue and print
      que.pop();
      cout << char(u.val+'A') << " ";

      for(i = 0; i<NODE; i++) {
         if(graph[i][u.val]) {
            //when the node is non-visited
            if(vert[i].state == 0) {
               vert[i].state = 1;
               que.push(vert[i]);
            }    
         }
      }
      u.state = 2;   //completed for node u
   }
}

int main() {
   node vertices[NODE];
   node start;
   char s;

   for(int i = 0; i<NODE; i++) {
      vertices[i].val = i;
   }

   s = 'B';   //starting vertex B
   start.val = s-'A';
   cout << "BFS Traversal: ";
   bfs(vertices, start);
   cout << endl;
}