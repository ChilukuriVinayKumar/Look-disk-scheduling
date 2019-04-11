//////////////////////////////////////////////////// LOOK DISK SCHEDULING ///////////////////////////////////////////////////////////
/*
Q34. Write a C program to solve the following problem: 
Suppose that a disk drive has 5,000 cylinders, numbered 0 to 4999. The drive is currently serving a request at cylinder 143, and the previous request was at cylinder 125. 
The queue of pending requests, in FIFO order is: 
86, 1470, 913, 1774, 948, 1509, 1022, 1750, 130 
Starting from the current head position, what is the total distance (in cylinders) that the disk arm moves to satisfy all the pending requests for each of the 
LOOK disk-scheduling algorithms?  
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int findMax(vector<int>);
int findMin(vector<int>);
bool find(int,vector<int>);
class DiskScheduling
{
	vector<int>qOfPending,diskArmDist;
	int totalcylinders,curr,previous,n,val,max,min,prereq,diff;
	public:
		void getData()
		{
			cout<<"\t\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\"<<endl<<endl;
			cout<<"\t\t\t\tLOOK DISK SCHEDULING "<<endl<<endl;
			cout<<"\t\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\"<<endl<<endl;
			cout<<"\tEnter the number total number of cylinders :: ";
			cin>>totalcylinders;
			cout<<"\tEnter the currently serving request :: ";
			cin>>curr;
			cout<<"\tEnter the previously served request  :: ";
			cin>>previous;
			cout<<"\tEnter the number of pending requests in Queue :: ";
			cin>>n;
			for(int i=0;i<n;i++)
			{
				cout<<"\t--> ";
				cin>>val;
				qOfPending.push_back(val);
			}
		}
		void startProcess()
		{
			max=*(std::max_element(qOfPending.begin(),qOfPending.end()));
			min=*(std::min_element(qOfPending.begin(),qOfPending.end()));
			prereq=curr;
			if(curr>previous)
			{
				cout<<"\tDirection: FORWARD-->BACKWARD"<<endl;
				for(int i=curr;i<=max;i++)
				{ 
    				if(find(i,qOfPending)==true) 
					{
						diff=i-prereq;
						diskArmDist.push_back(diff);
						prereq=i;
						diff=0; 		
        			} 
        		}	
        		for(int i=curr;i>=min;i--)
				{ 
    				if(find(i,qOfPending)==true) 
					{
						diff=prereq-i;
						diskArmDist.push_back(diff);
						prereq=i;
						diff=0; 		
        			} 
        		}
			}
			else
			{
				cout<<"\tDirection: BACKWARD-->FORWARD"<<endl;
				for(int i=curr;i>=min;i--)
				{
					if(find(i,qOfPending)==true) 
					{
						diff=prereq-i;
						diskArmDist.push_back(diff);
						prereq=i; 		
						diff=0;        			
					} 
        		}	
        		for(int i=curr;i<=max;i++)
				{ 
    				if(find(i,qOfPending)==true) 
					{
						diff=i-prereq ;
						diskArmDist.push_back(diff);
						prereq=i;
						diff=0; 		
        			} 
        		}		
			}
		}
		void finalBlock()
		{
			int sum=0;
			for(int i=0;i<diskArmDist.size();i++)
			{
				sum=sum+diskArmDist.at(i);
			}
			cout<<"    +------------------------------------------------------------------------------------------------------------+"<<endl;
			cout<<"    |  The total distance (in cylinders) that the disk arm moves to satisfy all the pending requests :: "<<sum<<"     |"<<endl;
			cout<<"    +------------------------------------------------------------------------------------------------------------+";
		}
};
int main()
{
	DiskScheduling sc;
	sc.getData();
	sc.startProcess();
	sc.finalBlock();
}
bool find(int i,vector<int> qOfPending)
{
	int var=i;
	for(int j=0;j<qOfPending.size();j++)
	{
		if(var==qOfPending.at(j))
		{
			return true;
		}	
	}
	return false;
}
/*
Test Case 1:
5000
143
125
9
86 
1470
913
1774
948
1509
1022
1750 
130
 
Output:
	Direction: FORWARD-->BACKWARD
    +-----------------------------------------------------------------------------------------------------------+
    |  The total distance (in cylinders) that the disk arm moves to satisfy all the pending requests :: 3319    |
    +-----------------------------------------------------------------------------------------------------------+

=======================================
Test Case 2:
200
53
40
8
98
183
41
122
14
124 
65 
67

Output:
	 Direction: FORWARD-->BACKWARD
    +-----------------------------------------------------------------------------------------------------------+
    |  The total distance (in cylinders) that the disk arm moves to satisfy all the pending requests :: 299     |
    +-----------------------------------------------------------------------------------------------------------+
*/
