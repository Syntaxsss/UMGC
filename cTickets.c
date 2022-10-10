// C code
// This code will compute the values of
// tickets sales for concerts and
// sort the entries by values
// Developer: Stacy Sewell Student CMIS102
// Date: 12/14/2019

#include<stdio.h>

#define MAXN 100 // max characters in a group/concert name
#define MAXG 50  // max concerts/groups
//#define MAXC  3  // max categories
#define MAXC 4 // 4 categories
char group [MAXG][MAXN];
int fans [MAXG][MAXC];
float prices[MAXC];
float sales [MAXG];
float totSal1;
float totSal;
int count = 0;
void intro(){
	 printf("\n******************************");
	 printf("\n         Welcome              ");
	 printf("\n         CMIS102              ");
	 printf("\n  This program will calculate ");
	 printf("\n   concert tickets by group   ");
	 printf("\n   written by Stacy Sewell    ");
	 printf("\n******************************\n\n");
}
void printArray(){
	 printf("%15s%5s%5s%5s%5s%10s\n","Concert","s1","s2","s3","s4","Sales");
		 for (int i = 0; i < count; i++){
		   printf("%15s", group[i]);
			 for(int j = 0; j < MAXC; j++){
			   printf("%5d",fans[i][j]);
			 }// end for each category
			 printf("%10.2f\n", sales[i]);
			 totSal += sales[i];
			}// end for each group
}// end of funtion printArray

void computeSales(){
  for(int i =0; i< count; i++){
	sales[i] = 0;
	for(int j = 0; j < MAXC; j++){
	  sales[i] += prices[j]*fans[i][j];
	}// end for each category
  }//end for each group
}//end function computeSales

void switchRows(int m, int n){
  char tc;
  int ti;
  float v;
  //printf("Switching m = %d with n= %d\n", m, n);
  for (int i = 0; i < MAXN; i++){
	tc = group[m][i];
	group[m][i] = group[n][i];
	group[n][i] = tc;
  }// end for each character in a group name
  for (int i = 0; i < MAXC; i++){
	 ti = fans[m][i];
	 fans[m][i] = fans[n][i];
	 fans[n][i] = ti;
  }// end for each fan category
  v = sales[m];
  sales[m] = sales[n];
  sales[n] = v;
}// end switch

int findMinSales(int m){
  float min = sales[m];
  int target = m;
  for(int i = m+1; i < count; i++)
	if(sales[i] < min){
	  min = sales[i];
	  target = i;
	}// end new max found
  return target;
}// end function findMinSales

void sortBySales(){
  int target;
  for(int i = 0; i < count; i++){
	 target = findMinSales(i);
	 if(target > i)
		switchRows(i, target);
  }// for each concert
}// end function sortBySales

void getData(){
  //for (int i = 0;i < MAXG; i++)   sales[i] = 0;
  printf("Enter ticket prices in each of %d categories\n", MAXC);
  for(int i = 0; i < MAXC; i++)//max categories MAXC is 3
	 scanf("%f", &prices[i]);
	 printf("--Enter group and fans in %d categories\n", MAXC);
	 printf(" .to finish entries:\n");
	 for(int g = 0; g < MAXG;g++){
	  //for( n = 0; n < MAXN; n++)
		  scanf("%s", &group[g][0]);
		if(group[g][0] == '.')
		//if(group[g][n] == '.')
		  break;
		  count++;
		  for(int j = 0; j < MAXC; j++)
			scanf("%d", &fans[g][j]);

	 }// end for each group
}// end function getData

int main(void){
  intro();
  getData();
  computeSales();
  printArray();
  printf("\n--Sorted\n");
  sortBySales();
  printArray();
  printf("\n%35s", "**** Total Sales:");
  printf("%10.2f\n",totSal/2);
  printf("...-bye...\n");
  return 0;
}

