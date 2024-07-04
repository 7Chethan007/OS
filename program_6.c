// Write a program to simulate Segmentation. Compute the physical address

// Take as input:
// 	1. Segment number
// 	2. Base address
// 	3. Segment limit

#include <stdio.h>

int main() {
int Number;
int baseAddress, Limit, offset;
printf("Enter  number: ");
scanf("%d", &Number);
printf("Enter base address (in hexadecimal format): ");
scanf("%x", &baseAddress);
printf("Enter  limit (in hexadecimal format): ");
scanf("%x", &Limit);
printf("Enter offset (in hexa): ");
scanf("%x", &offset);
if (offset >= Limit) {
    printf("Offset exceeds  limit\n");}
	else{
    int physicalAddress = baseAddress + offset;
    printf("Physical address: 0x%04X\n", physicalAddress);}

return 0;

}