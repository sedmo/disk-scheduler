#ifndef DSA_H
#define DSA_H

#include <iostream>
#include <cstdlib>//srand
#include <ctime>
#include <array>
#define C_SZ 5000
#define REQ_SZ 50 

using namespace std;

class DSA
{
	int head;
	array<int, REQ_SZ> reqs;
	/* int fcfs: First come first serve algorithm. Moves arm to the cylinders as they come in.
	 *
	 * params: none
	 *
	 * return value:  #of movements to complete request.
	 *
	 */
	int fcfs();
	/* int sstf: Shortest seek time first algorithm. Arm moves to the clinders closes to head last is cylinder furthest from head.
	 *
	 * params: none
	 *
	 * return value: #of movements to complete request. 
	 *
	 */
	int sstf();
	/* int scan: Scan algorithm. Arm scans all cylinders to the left then all to the right of the head. 
	 *
	 * params: none
	 *
	 * return value: #of movements to complete request. 
	 *
	 */
	int scan();
	/* int cscan: Just like scan. However, when arm reaches right end, it starts back from beginning
	 * as opposed to backtracking.
	 *
	 * params: none
	 *
	 * return value: #of movements to complete request.
	 *
	 */
	int cscan();
	/* int look: Just like scan. Arm only goes as far as largest cylinder.
	 *
	 * params: none
	 *
	 * return value: #of movements to complete request.
	 *
	 */
	int look();
	/* int look: Just like cscan. Arm only goes as far as largest cylinder.
	 *
	 * params: none
	 *
	 * return value: #of movements to complete request.
	 *
	 */
	int clook();
	
	public:
		DSA(int &head): head(head)
		{
			srand(time(0));

			for(int i = 0; i < REQ_SZ; i++){
				reqs[i] = rand() % C_SZ;						
			} 
		}
		void print();
		void print_arr(){cout<<"Printing array: \n"; for(int i:reqs){cout<<i<<endl;}}
		int get_head(){return head;};
};

#endif /* DSA_H */
