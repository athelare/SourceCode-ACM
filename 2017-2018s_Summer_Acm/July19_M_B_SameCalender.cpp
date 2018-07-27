#include<stdio.h>
int leap(int n){return n%100 == 0?n%400 == 0:n%4 == 0;}
int main()
{
	int daysCount;
	int year;
	while(~scanf("%d",&year)){
		daysCount = 0;
		if(leap(year)){
			while(1){
				year++;
				daysCount = (daysCount+(leap(year)==1?366:365))%7;
				if(daysCount%7 == 0 && leap(year))
					break;
                
			}
			printf("%d\n", year);
		}else{
			while(1){
				year++;
				daysCount = (daysCount + (leap(year) == 1 ? 366 : 365)) % 7;
				if(daysCount == 0 && !leap(year))
					break;
			}
			printf("%d\n", year);
		}
	}
	return 0;
}
