#include <stdio.h>
#include <stdlib.h>
int main(){
int counter =0;
int BUFFER_SIZE =100;
int buffer[BUFFER_SIZE];

while(1) {
/* produce an item in next produced */
while (counter == BUFFER_SIZE){
printf("%d\n",counter);
break;
} /* do nothing */
buffer[counter] = 1;
if(counter == BUFFER_SIZE ) break;
counter++;
}
start:
printf("hello");
while(1) {
while(counter == 0){
printf("%d\n",counter);
break;} /* do nothing */
buffer[counter] = 0;
if(counter ==0)break;
counter--;
/* consume the item in next consumed */
}
}
