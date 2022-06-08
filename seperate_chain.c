// hashing technique : seperate chaining or open hashing or closed addressing
#include<stdio.h>
#include<stdlib.h>

void line(){
	printf("---------------------------------------\n");
}

struct hash{
	int data;
	struct hash *next;
};

struct hash* create(int x){
	struct hash *h;
	h=(struct hash*)malloc(sizeof(struct hash));
	h->data=x;
	h->next=NULL;
	return h;
}

void insert(struct hash *h[],int ts,int x){
	int i;
	struct hash *temp,*j;
	temp=create(x);
	i=x%ts;
	if(h[i]==NULL){
		h[i]=temp;
		printf("%d is inserted\n",x);
	}
	else{
		j=h[i];
		while(j->next!=NULL){
			j=j->next;
		}
		j->next=temp;
		printf("%d is inserted\n",x);
	}
}

void delete(struct hash *h[],int ts,int x){
	int i;
	struct hash *j,*pre;
	i=x%ts;
	j=h[i];
	if(j==NULL){
		printf("element not found to delete\n");
	}
	else if(j->data==x){
		h[i]=j->next;
		printf("%d is deleted\n",x);
	}
	else{
		while(j!=NULL){
			if(j->data==x){
				pre->next=j->next;
				printf("%d is deleted\n",x);
				return;
			}
			pre=j;
			j=j->next;
		}
		if(j==NULL){
			printf("element not found to delete\n");
		}
	}
}

void display(struct hash *h[],int ts){
	int i;
	struct hash *j;
	printf("the hash table is :\n");
	for(i=0;i<ts;i++){
		printf("h[%d] ---> ",i);
		for(j=h[i];j!=NULL;j=j->next){
			printf("  %d  ",j->data);
		}
		printf("\n");
	}
}

int search(struct hash *h[],int ts,int x){
	int i;
	struct hash *j;
	i=x%ts;
	j=h[i];
	while(j!=NULL){
		if(j->data==x){
			return 1;
		}
		j=j->next;
	}
	return 0;
}

int main(){
	int ts,i,ch,x;  //ts:table size,ch:choice,i:table index,x:element
	printf("enter size of hash table\n");
	scanf("%d",&ts);

	struct hash *h[ts];
	for(i=0;i<ts;i++){
		h[i]=NULL;
	}
	while(1){
		line();
		printf("Enter your choice\n");
		line();
		printf("1.insert an element to hash table\n2.delete an element from hash table\n3.display the hash table\n4.search an element in hash table\n5.exit from program\n");
		line();
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("enter an element to insert\n");
				scanf("%d",&x);
				insert(h,ts,x);
				break;
			case 2:
				printf("enter an element to delete\n");
				scanf("%d",&x);
				delete(h,ts,x);
				break;
			case 3:
				display(h,ts);
				break;
			case 4:
				printf("enter an element to search\n");
				scanf("%d",&x);
				x=search(h,ts,x);
				if(x==1){
					printf("searching element is found\n");
				}
				else{
					printf("searching element is not found\n");
				}
				break;
			case 5:
				printf("you choose to exit from program and your wish became true");
				exit(0);
			default:
				printf("enter valid number from given choices\n");
		}
	}
}
