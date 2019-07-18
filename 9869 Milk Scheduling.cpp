#include <iostream>
#include <vector>

using namespace std;

struct cow {
	int gallon;
	int deadline;
};

vector<cow> line;
vector<cow> scheduler;

cow cow_swap(int index, cow temp);

int main() {
	int n, maxDead=0;
	cow temp;

	cin >> n;
	if (n < 1 || n> 10000) {
		return 0;
	}
	line.push_back(temp);
	
	for (int i = 1; i <= n; i++) {
		cin >> temp.gallon >> temp.deadline;
		if (temp.gallon < 1 || temp.deadline < 1 || temp.gallon > 1000 || temp.deadline > 10000) {
			return 0;
		}
		if (maxDead < temp.deadline) {
			maxDead = temp.deadline;
		}
		line.push_back(temp);
	}
	/*	Greedy Approach */
	int idx, last = n, count = 1;
	scheduler.resize(maxDead + 1);
	while (count <= n) {
	/*	Step 1. define criterion as the maximun 
		amount of gallons. */
		idx = line[count].deadline;
		if (scheduler[idx].gallon == 0) {
			scheduler[idx] = line[count];
		}
		else{
			if (scheduler[idx].gallon < line[count].gallon) {
				temp = scheduler[idx];
				scheduler[idx] = line[count];
			}
			else {
				temp = line[count];
			}
			for (int i = idx - 1; i > 0; i--) {
				if (scheduler[i].gallon == 0){
					scheduler[i] = temp;
					break;
				}
				else if(scheduler[i].gallon < temp.gallon){
					temp = cow_swap(i, temp);
				}
			}
		}
		count++;
	}
	count = 0;
	for (int i = 1; i <= maxDead; i++) {
		count += scheduler[i].gallon;
	}
	cout << count;
}

cow cow_swap(int index, cow temp) {
	cow temp1 = scheduler[index];
	scheduler[index] = temp;
	temp = temp1;
	return temp;
}