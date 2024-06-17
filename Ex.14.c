#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
struct node {
 int vertex;
 int w;
 struct node *next;
};
struct graph {
 int numvertex;
 struct node **adjlist;
};
struct node* create_node(int vertex, int w) {
 struct node *new = (struct node*)malloc(sizeof(struct node));
 if (!new) {
 fprintf(stderr, "Memory allocation error\n");
 exit(EXIT_FAILURE);
 }
 new->vertex = vertex;
 new->w = w;
 new->next = NULL;
 return new;
}
struct graph* create_graph(int no) {
 struct graph *new = (struct graph*)malloc(sizeof(struct graph));
 if (!new) {
 fprintf(stderr, "Memory allocation error\n");
 exit(EXIT_FAILURE);
 }
 new->numvertex = no;
 new->adjlist = (struct node**)malloc(no * sizeof(struct node*));
 if (!new->adjlist) {
 fprintf(stderr, "Memory allocation error\n");
 exit(EXIT_FAILURE);
 }
 for (int i = 0; i < no; i++) {
 new->adjlist[i] = NULL;
 }
 return new;
}
void add_edge(struct graph *g, int s, int d, int w) {
 struct node *new = create_node(d, w);
 new->next = g->adjlist[s];
 g->adjlist[s] = new;
 new = create_node(s, w);
 new->next = g->adjlist[d];
 g->adjlist[d] = new;
}
struct graph* input(struct graph *g) {
 int no, d, s, w;
 printf("ENTER THE NO. OF EDGES: ");
 scanf("%d", &no);
 for (int i = 0; i < no; i++) {
 printf("Enter edge (source destination weight): ");
 scanf("%d %d %d", &s, &d, &w);
 add_edge(g, s, d, w);
 }
 return g;
}
void print_graph(struct graph *g) {
 for (int i = 0; i < g->numvertex; i++) {
 struct node *temp = g->adjlist[i];
 printf("VERTEX %d\n", i);
 while (temp != NULL) {
 printf("%d(%d) --> ", temp->vertex, temp->w);
 temp = temp->next;
 }
 printf("NULL\n");
 }
}
void free_graph(struct graph *g) {
 for (int i = 0; i < g->numvertex; i++) {
 struct node *temp = g->adjlist[i];
 while (temp != NULL) {
 struct node *to_free = temp;
 temp = temp->next;
 free(to_free);
 }
 }
 free(g->adjlist);
 free(g);
}
void print_path(int path[], int vertex) {
 if (path[vertex] == -1) {
 printf("%d", vertex);
 return;
 }
 print_path(path, path[vertex]);
 printf(" -> %d", vertex);
}
void dijkstra(struct graph *g, int src) {
 int numvertex = g->numvertex;
 int dist[numvertex];
 bool known[numvertex];
 int path[numvertex];
 for (int i = 0; i < numvertex; i++) {
 dist[i] = INT_MAX;
 known[i] = false;
 path[i] = -1;
 }
 dist[src] = 0;
 for (int count = 0; count < numvertex - 1; count++) {
 int u = -1;
 int min = INT_MAX;
 for (int v = 0; v < numvertex; v++) {
 if (!known[v] && dist[v] < min) {
 min = dist[v];
 u = v;
 }
 }
 if (u == -1) {
 printf("Graph is disconnected\n");
 return;
 }
 known[u] = true;
 struct node *temp = g->adjlist[u];
 while (temp != NULL) {
 int v = temp->vertex;
 if (!known[v] && dist[u] != INT_MAX && dist[u] + temp->w < dist[v]) {
 dist[v] = dist[u] + temp->w;
 path[v] = u;
 }
 temp = temp->next;
 }
 }
 printf("Vertex \t Distance from Source \t Path\n");
 for (int i = 0; i < numvertex; i++) {
 if (i != src && dist[i] != INT_MAX) {
 printf("%d \t\t %d \t\t\t\t\t ", i, dist[i]);
 print_path(path, i);
 printf("\n");
 }
 }
}
int main() {
 int n;
 printf("ENTER THE NO. OF NODES: ");
 scanf("%d", &n);
 if (n <= 0) {
 printf("Number of nodes must be greater than 0\n");
 return -1;
 }
 struct graph *g = create_graph(n);
 input(g);
 print_graph(g);
 int src;
 printf("Enter the source vertex: ");
 scanf("%d", &src);
 if (src < 0 || src >= n) {
 printf("Invalid source vertex\n");
 free_graph(g);
 return -1;
 }
 printf("Shortest Paths using Dijkstra's Algorithm:\n");
 dijkstra(g, src);
 free_graph(g);
 return 0;
}