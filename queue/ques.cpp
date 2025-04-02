#include<iostream>
using namespace std;

//1. k queues in an array
class NQueue{
public:
    int n;
    int s;
    int *arr;
    int *front;
    int *rear;
    int *next;
    int free;

    NQueue(int n, int s){
        this->n=n;
        this->s=s;

        front=new int[s];   //firstly k size ka front or rear banaya
        rear=new int [s];   
        for(int i=0; i<s;i++){  //and uss f,r ko starting mei -1 initialize kara
            front[i]=-1;
            rear[i]=-1;
        }
        next=new int[n];
        for(int i=0; i<n;i++){
            next[i]=i+1;
        }
        next[n-1]=-1;
        arr=new int[n];
        free=0;
    }

    // Enqueues 'X' into the Mth queue. Returns true if it gets pushed into the queue, and false otherwise.
    bool enqueue(int x, int m){
        if(free==-1){   //next free slot nhi hai means full-overflow
            return false;
        }
        //fetching first idx to enqueue
        int idx=free;   //sabse pehle free ko fetch kra & idx bna liya
        free=next[idx]; //then next wala freeslot dhundege via next of idx

        //check if it's first one to insert
        if(front[m-1]==-1){
            front[m-1]=idx; //agr yes front hai toh front use assign kara denge
        }else{
            //if not first -link
            next[rear[m-1]]=idx; //toh prev rear ke sath link karenge via next
        }
        //updating rear and next
        rear[m-1]=idx;  //updating rear as usual for next push
        next[idx]=-1;   //agr mth queue fill ho gya then
        arr[idx]=x;

        return true;
    }

    // Dequeues top element from Mth queue. Returns -1 if the queue is empty, otherwise returns the popped element.
    int dequeue(int m){
        if(front[m-1]==-1){
            return -1;
        }
        //fetching idx to pop
        int idx=front[m-1];
        //updating front after pop
        front[m-1]=next[idx];

        //free slot managing-jo delete hua wo pehle free banega
        next[idx]=free; //poped wale ka next fetching for next free
        free=idx;   //current free is poped wala

        return arr[idx];
    }
};


//2. sum of max & min of all subarray of size k
long long sumOfMaxAndMin(vector<int> &nums, int n, int k) {
	deque<int> max(k);
	deque<int>min(k);

	//addition first k
	for(int i=0; i<k ;i++){
		while(!max.empty() && nums[max.back()]<=nums[i]){
			max.pop_back();
		}
		while(!min.empty() && nums[min.back()]>=nums[i]){
			min.pop_back();
		}
		max.push_back(i);
		min.push_back(i);
	}
	long long int ans=0;
	ans+=nums[max.front()]+nums[min.front()];

	for(int i=k;i<n;i++){	//remaining window processing for except first k & last 
		//removal
		while(!max.empty() && i-max.front()>=k){
			max.pop_front();
		}
		while(!min.empty() && i-min.front()>=k){
			min.pop_front();
		}
		//addition
		while(!max.empty() && nums[max.back()]<=nums[i]){
			max.pop_back();
		}
		while(!min.empty() && nums[min.back()]>=nums[i]){
			min.pop_back();
		}
		max.push_back(i);
		min.push_back(i);
	
		ans+=nums[max.front()]+nums[min.front()];
	}

	return ans;

}

int main(){






    return 0;
}