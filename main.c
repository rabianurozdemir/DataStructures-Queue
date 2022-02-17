//RABÝA NUR ÖZDEMÝR
//191180066

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct{
	int value;
}element;

int front = -1;
int rear = -1;
element queue[SIZE];
element newQueue[SIZE]; //We will use this queue to hold the elements we have removed from our original queue.

void Option(){
    
    printf("\n---------OPTIONS---------\n");
    printf("0- Print all elements of the queue\n");
    printf("1- Add an element into the queue\n");
    printf("2- Remove element from the queue\n");
    printf("3- Exit\n");
    printf("Select (0-3)? : ");
}

void print_queue(){
    
    int i;
    
    for(i = front; i <= rear; i++){
        printf(" %d", queue[i].value);
    }
    
    printf("\n");
}

void enqueue(int value){
    
    if(front == -1){
        front = 0;
    }
    rear++;
    queue[rear].value = value;
}

void dequeue(){

    front++;
    
}

//isFull() function checks if the queue is full.
int isFull(){
	
	if(rear == SIZE -1){
        return 1;
    }
    else{
    	return 0;
	}
}

//isEmpty() function checks if the queue is empty.
int isEmpty(){
	
	if(front == -1 && rear == -1){
        return 1;
    }
    else if(front > rear){
    	return 1;
	}
    else{
    	return 0;
	}
}

int main() {
    
    int value = 0; //The number we want to add
    int option = 0; //What we want to do
    
    while(1){
        Option();
    	scanf("%d", &option);
    
    	switch(option){
        	case 0:
        		if(isEmpty()){
        			printf("Queue is empty.\n"); //If the queue is empty, print "Queue is empty." to the screen.
				}
				else{
					print_queue(); //If the queue is not empty, print the items in the queue to the screen.
				}   
            	break;
            	
        	case 1:
        		if(isFull()){
        			printf("Queue is full.\n"); //If the queue is full, print "Queue is full." to the screen.
				}
				else{
					printf("\nPlease enter the number you want to add to the queue: ");
            	scanf("%d", &value);
            	if(front == -1){ //If the queue is empty, add the value to the queue.
                	enqueue(value); }
            	else if(value > queue[rear].value){ //If the queue is not empty and value > queue[rear], add the value to the queue.
                    enqueue(value);
                }
            	else if(value < queue[rear].value){ //If the queue is not empty and value < queue[rear]
                	int i, j = 0, k;
                
                	for(i = front; i <= rear; i++){
                    	newQueue[i].value = queue[i].value; //Put the elements in the original queue into the newQueue.
                    	if(i==rear){ //Make the original queue empty.
                    		rear = -1;
                    		front = -1;
						}
                	}
                
                	while(value > newQueue[j].value){ //Add elements less than value, back to the original queue. 
                		enqueue(newQueue[j].value);
                		j++;
					}
					enqueue(value); //Add value
				
					while(value < newQueue[j].value){ //Add elements larger than value, back to the original queue. 
                		enqueue(newQueue[j].value);
              
             			j++;
             			if(j == rear - front){
             				break;
					 	}
					}
				}
				printf("The element has been successfully added.\n");
			}
            
            break;
            
        case 2:
        	if(isEmpty()){
        		printf("Queue is empty.\n"); //If the queue is empty, print "Queue is empty." to the screen.
			}
			else{
				dequeue(); //If the queue is not empty, remove the first item from queue.
				printf("The first element has been successfully removed.\n");
			}
            break;
            
        case 3:
            return 0;
            break;
            
        default:
            printf("Please choose a number from 0-3");
            break;
    }
    }
}
