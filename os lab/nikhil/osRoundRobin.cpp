#include<bits/stdc++.h>
using namespace std;

struct process
{
	int id;
	int arrTime;
	int burstTime;
	int tempBurstTime;
	int compTime;
	int turnAroundTime;
	int waitingTime;
};

void findComp(vector<process> &p , int Quantum)
{
	int n = p.size();
	int min_time = 0;
	int comp_pro = 0;

	while(comp_pro < n)
	{
		for(int i = 0 ; i < n ; i++)
		{
			if(p[i].arrTime <= min_time and p[i].burstTime > 0)
			{
				int execution_time = (p[i].burstTime <= Quantum) ? p[i].burstTime : Quantum;
				p[i].burstTime -= execution_time;
				min_time += execution_time;

				if(p[i].burstTime == 0)
				{
					p[i].compTime = min_time;
					comp_pro++;
				}
			}
		}
		
	}
}

void findTAT(vector<process> &p)
{
	for(auto &i : p) i.turnAroundTime = i.compTime - i.arrTime;
}

void findWT(vector<process> &p)
{
	for(auto &i : p) i.waitingTime = i.turnAroundTime - i.tempBurstTime;
}

int main()
{
	int n , Quantum ; cin >> n >> Quantum;
	vector<process> p(n);

	for(auto &i : p) cin >> i.id  >> i.arrTime >> i.burstTime;

	for(auto &i : p) i.tempBurstTime = i.burstTime;

	findComp(p , Quantum);
	findTAT(p);
	findWT(p);

	cout << "ID At Bt Ct TAT Wt" << endl;
	for(auto i : p) cout << i.id << "  " << i.arrTime << "  " << i.tempBurstTime << "  " << i.compTime << " " << i.turnAroundTime << "  " << i.waitingTime << endl;

	int avg_turnaround_time = 0 , avg_waitingtime = 0;
	
	for(auto i : p) 
	{
		avg_turnaround_time += i.turnAroundTime;
		avg_waitingtime += i.waitingTime;
	}

	cout << "avgTurnAroundTime : " << avg_turnaround_time/n << "\navgWaitingTime : " << avg_waitingtime/n << endl ;

}
