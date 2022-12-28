// hashing technique : linear probing(type 1 of closed hashing or open addressing)
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    char status;
};

void line(){
	printf("---------------------------------------\n");
}

/* status terminology
'e' ->empty
'o' ->occupied
'd' ->deleted */

void insert(struct node h[],int ts,int x){
    int i,j;
    i=j=x%ts;
    do{
        if(h[i].status=='e' || h[i].status=='d'){
            h[i].data=x;
            h[i].status='o';
            printf("%d is inserted\n",x);
            return;
        }
        i=(i+1)%ts;
    }while(i!=j);
    printf("hash table overflow\n");
}

void delete(struct node h[],int ts,int x){
    int i,j;
    i=j=x%ts;
    do{
        if(h[i].status=='e'){
            printf("element not found to delete\n");
            return;
        }
        if(h[i].status=='o' && h[i].data==x){
            printf("%d is deleted\n",x);
            h[i].status='d';
            return;
        }
        i=(i+1)%ts;
    }while(i!=j);
    printf("element not found\n");
}

void display(struct node h[],int ts){
	int i;
    printf("the current hash table is:\n");
		    for(i=0;i<ts;i++){
        printf("h[%d] ---> ",i);
        if(h[i].status=='o'){
            printf("%d",h[i].data);
        }
        printf("\n");
    }
}

int search(struct node h[],int ts,int x){
    int i,j;
    i=j=x%ts;
    do{
        if(h[i].status=='e'){
            return 0;
        }
        if(h[i].status=='o' && h[i].data==x){
            return 1;
        }
        i=(i+1)%ts;
    }while(i!=j);
    return 0;
}

int main(){
    int ts,i,ch,x;
    printf("enter size of hash table\n");
    scanf("%d",&ts);

    struct node h[ts];
    for(i=0;i<ts;i++){
        h[i].status='e';
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
