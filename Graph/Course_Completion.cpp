/**
 * There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
 * You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.
*/


#include<vector>
#include<queue>
#include "iostream"

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses ==0 || prerequisites.size() ==0 )
            return true;
        //Build the adjacency list and the indegree vector
        vector<vector<int>> adjList;
        adjList.reserve(numCourses);
        vector<int> indegree(numCourses,0);

        for( auto p: prerequisites) {
            adjList[p[0]].push_back(p[1]);
        }
        //Populate the indegree of nodes
        for( int i=0; i<adjList.size(); ++i) {
            for( int v : adjList[i])
                ++indegree[v];
        }

        return getTopologicalSort(adjList,numCourses,indegree);
    }
    bool getTopologicalSort( const vector<vector<int>> &adjList, const int &numCourses, 
                             vector<int> &indegree) {

        queue<int> enq;
        vector<bool> visited(numCourses,false);

        //Check the vertex/course with 0 indegree or dependency and push to enq.
        for( int i =0; i<numCourses; ++i) {
            if( 0== indegree[i])
                enq.push(i);
        }
        //If no course has indegree 0 then cycle exists and the course can't be completed return false
        if( enq.empty())
            return false;
        
        //counter to keep track of the num of courses processed
        int course_processed = 0;
        while( !enq.empty()) {
            int course = enq.front();
            enq.pop();
            visited[course] = true;
            ++course_processed;

            for( int v: adjList[course]) {
                --indegree[v];
                if( 0 == indegree[v]){
                    if( !visited[v])
                        enq.push(v);
                }
                   
            }
        }
        //If course_processed is same as total course count then task is completed.
        return (numCourses ==course_processed);

    }
        
       
};

int main() {
    Solution sol;

    // Test case 1: Possible to finish all courses
    int numCourses1 = 2;
    std::vector<std::vector<int>> prerequisites1 = {{1, 0}};

    if (sol.canFinish(numCourses1, prerequisites1)) {
        std::cout << "Test Case 1: It is possible to finish all courses." << std::endl;
    } else {
        std::cout << "Test Case 1: It is not possible to finish all courses." << std::endl;
    }

    return 0;
}