#include<bits/stdc++.h>
# include<vector>
using namespace std;


// pair<int, int> pairs node name with weight. Basically each of the boxes
// in the visual representation with arrows points out.
typedef pair<int, int> vertex;



// AdjacencyListType is just a name for vector<vector <vertex>>
// The outermost vector is initialized to size v here.
// Think of the outermost vector as the leftmost side or, column in the visual representation
// shown in the books. The inner vector is each for the rows single dimensional array. The
// inner vector stores pair<int, int> in each of its slot. Where pair<int, int> is used to
// show the adjacent node and the weight between the nodes. Basically each of the boxes.
typedef vector<vector <vertex> > AdjacencyListType;



// Take input of directed weighted graph
// AdjacencyListType &adjList is pass by reference of the adjacency list of type vector<vector <vertex>>
// The const keyword is added wherever I know the value does not need to be modified.
void inputAdjacencyList(AdjacencyListType &adjList, int const& edges){
    int source, dest, weight;
    for(int i = 0; i < edges; ++i){
        cin >> source >> dest >> weight;

        vertex vet1(dest, weight);
        adjList[source].push_back(vet1);
    }
}



// If there are no adjacent node "NONE" is printed.
// adjList[m].size() gets the connected node count of the current node.
// Then adjList[m][j] gets a specific node which is of pair<int, int> type.
// Now get the node name and the pair by accessing the first and second property.
// Since I have paired node name with weight so, the first is name and next one is the weight
void printCompleteAdjacencyList( AdjacencyListType const& adjList, int &v ){

    for(int i = 0; i < v; ++i){

        int adjNodes = adjList[i].size();
        printf("Adjacent of: %d", i);

        if(adjNodes > 0){
            for(int j = 0; j < adjNodes; ++j){
                printf(" -> %d (w:%d)", adjList[i][j].first, adjList[i][j].second);
            }
        }else{
            printf(" -> NONE");
        }

        printf("\n");
    }

}


// List nodes adjacent or, connected with current node.
void listAdjacentNodes( AdjacencyListType const& adjList, int const& m){

    printf("%d", m);
    for(int j = 0; j < adjList[m].size(); ++j){
        printf(" -> %d (w:%d)", adjList[m][j].first, adjList[m][j].second);
    }

}


int main(){

    // Input the vertex or, node count of the graph
    printf("Enter number of nodes:\n");
    int v;
    cin >> v;


    // Create the adjacency list structure with size of v.
    AdjacencyListType adjList(v);


    // Input the edge count of the graph
    printf("Enter Edge count:\n");
    int edges;
    cin >> edges;


    // Input the adjacency list
    printf("\nEnter source, destination and weight:\n");
    inputAdjacencyList(adjList, edges);


    // Show the complete adjacency list structure
    printf("\nWhole Adjacency List:\n");
    printCompleteAdjacencyList(adjList, v);


    // Enter a node number to see its adjacent or connected nodes
    printf("\nEnter node number to see adjacent nodes:\n");
    int m;
    scanf("%d", &m);


    // If the given node number is greater than the vertexes or, node count do nothing
    if(m < v){
        listAdjacentNodes(adjList, m);
    }

    return 0;
}
