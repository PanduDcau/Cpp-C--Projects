#include <iostream>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;

int N; //no of bottles sadun bought
int M; //no of barrels wine yard have

struct barrel{
	int volume;
	int price;
	int unitPrice;
	
};

bool compareBarrel(barrel a, barrel b);


int main(){
	
	cout<<"Inputs.....\n";
	cin>>N>>M; //get no of bottles and no of barrels
	barrel count[M];
	
	/*Get Volume of barrel*/
	string vol;
	getline(cin, vol);
	
	for(int i=0; i<M; ){
		if(vol[i] == ' '){
		}
		else{
			cin>>count[i].volume;
			i++;
		}
	}
	
	/*Get Price of a barrel */
	string pri;
	getline(cin, pri);
	
	for(int i=0; i<M; ){
		if(vol[i] == ' '){
		}
		else{
			cin>>count[i].price;
			i++;
		}
	}
	
	/*Set Unit Price*/
	int i=0;
	for(i=0; i<M; ){
		count[i].unitPrice = count[i].price / count[i].volume;
		i++;
	}
	
	
	sort(count,count+M,compareBarrel);
		
	int maxVal=0;
	int j = N;
	
	
	for(int i=M-1; i>=0; i--){
		if(j>=count[i].volume){
			maxVal += count[i].price;
			j-=count[i].volume;
		}
		else{
			maxVal += count[i].unitPrice * j;
			break;
		}
	}
	
	
	cout<<"\n\nOutput.....\n"<<maxVal<<"\n\n";
	
	return 0;
}

bool compareBarrel(barrel a, barrel b){
	
	if(a.unitPrice < b.unitPrice){		
		return 1;
	}
	else{
		return 0;
	}
		
}
