#include <stdio.h>
#include <stdlib.h>


int calculatedValue =0;
int counter =0;
int endLMC =0;
  int arrayNumber;
	char Values[8][8];
	char a[100][14] ;
	int *LMCarray ;
	int Loop;

	int command ;
	int value ;
	int endProg =0;

    void addValue()
{
    printf( "Command to be added (eg. \"901\" for input):" );
    scanf( "%d", &command );
    printf( "You entered %d\n", command);
    printf( "number to store into" );
    scanf( "%d", &value );
    printf( "You entered %d\n", value);
    LMCarray[value] = command;

}
void checkCommand(int comd)
{
    if (comd==0) {endLMC = 1;}
    else
    if (comd>=100 && (comd < 200)) {calculatedValue=LMCarray[comd-100] +calculatedValue;}
    else
    if (comd>=200 && (comd < 300)) {calculatedValue=LMCarray[comd-200] -calculatedValue;}
    else
    if (comd>=300 && (comd < 400)) {LMCarray[comd-300]= calculatedValue;}
    else
    if (comd>=500 && (comd < 600)) {calculatedValue= LMCarray[comd-500];}
    else
    if (comd>=600 && (comd < 700)) {counter= comd-600;}
    else
    if (comd>=700 && (comd < 800)) {if(calculatedValue == 0){counter= comd-700; }}
    else
    if (comd>=800 && (comd < 900)) {if(calculatedValue >= 0){counter= comd-800; }}
    else
    if (comd== 901) {printf( "INPUT:");
                        scanf( "%d", &calculatedValue );}
                        else
    if (comd== 902) { printf( "OUTPUT: %d\n", calculatedValue);}
   // else{"INVALID COMMAND LINE: %d\n", counter;}


}
void run ()
{
    counter =0;
    calculatedValue =0;
while (endLMC == 0)
{
    checkCommand(LMCarray [counter]);
    counter = counter +1;
}

}
	void begin()
{

    for (  Loop= 0; Loop< arrayNumber; Loop++ ) {

            LMCarray[Loop] = 0;

	}
}
	void display()
{

    for (  Loop= 0; Loop< arrayNumber; Loop++ ) {
        printf("[ %d ]\t" ,Loop);
		printf( "[ %d ]\n", LMCarray[Loop] );
	}
}
int main()
{
    	printf( "Please Array Size:" );
    scanf( "%d", &arrayNumber );
    printf( "You entered for array positions: %d", arrayNumber);
     LMCarray  = malloc( sizeof(*LMCarray ) * arrayNumber );
    begin();
	while (endProg ==0)
    {
        printf( "\n 1. Display LMC\n" );
    printf( "2. Start LMC\n" );
    printf( "3. Add to lmc\n" );
    printf( "4. Exit\n" );
    printf( "Selection: " );
    scanf( "%d", &command );
    printf( "You entered %d\n", command);
    switch (command){
        case 1:
            display();
            break;
        case 2:
            printf( "LMC started \n\n");
            run();
            printf( "\n\n LMC Ended \n");
            break;
        case 3:
            addValue();

            break;
        case 4:
            endProg = 1;
            break;
        default :
            printf( "Bad input\n" );
            break;
        }

    }
    free(LMCarray);
    getchar();
    return 0;
}
