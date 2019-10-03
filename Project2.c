#include <stdio.h>

/*
Team number:19
Team members: Liam, Evan, Oscar
*/

/* PROJECT 1 */

/* In this assignment you will examine a program consisting of a number of functions - labelled ques1.c to ques16.c -- each of which tests your knowledge of bitwise C operations (and data representation and logic operators). Your goal is to (a) determine what each function does and (b) if there
is a simpler way to implement the function using other operators, conditionals, loops etc.. For questions where the function returns a boolean value, figure out when it returns a 1. Thus, there are two parts to the requirements.  */

/* Assume 32 bit integers */

/* PART A: You need to determine what each function is doing .
You have to determine what each function is doing WITHOUT running the code -- simply handing in the results of your program execution. You must provide an explanation for your answer - you will get no credit if you correctly identify the function but provide  an incorrect or insufficient/incomplete explanation. Providing an 
example of output of each function for a given input is NOT a formal explanation and will get you no credit. 
 Once you determine the function, make sure you run the code and check your answer on various boundary conditions.
To run the code to test your function, you will need to insert appropriate C code to call the function and print out the result; a sample of what this may
require is provided in function main to call function ques0.
 Once you are done showing what each function does, you should then answer part b. */

/* PART B: For each function, can you write a simpler equivalent function in C (using any C operators) that produces the same result.
 By simpler, we are interested in fewer operations in C but also more readable code. */


/*
 As an example, consider the answers to function ques0 - which you worked out in class.

 HANDIN Instruction. 
Part A: You must write out your answers to Part A in a report to be submitted (as a tarfile or zipfile, along with your code) - in addition to the report, 
you can include comments in your code that may provide a secondary explanation (in case  your report has errors). You MUST provide an explanation for what
 the function does and justify your answer. Simply providing an example is NOT an explanation - so don't expect any credit if  your answers are simply a 
collection of examples or code comments. You are welcome to provide formal proofs where appropriate, but use your judgement on whether to pursue a formal 
proof or not. It is preferable to write your answers as comments in the code - but do not feel pressured to do so (this gets complicated if you  used
figures and examples in your explanation). */
/*
Part B: For part B, write out your code in this file with the answer (a simpler code if it exists) after each of the assigned functions in a manner similar
 to the example shown in ques0 (i.e., the answer to function ques7 should be named ans7). In Function main you MUST call both the question and answer 
functions and print out the results. Refer to the example shown for ques0 and ans0. This will also help you check if your code is giving the same
answer as the functions you are to decipher. HINT: For some of the questions, you may want to read in (and print out) the input variables in hex format -- 
similar to the inclass exercise (the first variable you entered, which was sent to function whoamI).

TEAM WORK DISTRIBUTION: At the top of your submission (the code and the report) clearly specify what each team member did; if each was responsible for a 
set of questions then specify that information. We will take team member contributions into consideration during our grading.

 IMPORTANT: The code you submit must compile correctly (using gcc). If the code you submit does not compile (i.e., we expect zero errors!),
 you will get a zero for Part B of this project.

 GRADING: Each question has a specific number of points (i.e., not all questions have the same level of difficulty). Your grade will be based
 on (a) the correctness of your answers, (b) expressing the answer as a logical function where possible, and (c) the efficiency and readability of your
 rewritten code.

 Collaboration: You should work your teammates. But you CANNOT refer to online sources to get help; you can refer to the C syntax documentations. Your report must include names of all members of the team -- failure to do so would imply you are claiming you worked on your own, and may constitute a violation of academic integrity policies.*/

/* EXAMPLE
 this function is similar to CallMeLast in the inclass exercises */
/*  function ques0(x,y) returns (x-y) since ~y +1 is the two's complement of y, i.e., -y. */
/* the function ans0 does the same in one C statement */

int ques0(int x, int y){//subtracts y from x
    int temp;
    temp = ~y;
    temp = temp +1;
    temp = temp + x;
    return (temp);
}

/* Answer to PART B: */
int ans0(int x, int y){


    return (x-y);
}

/* QUESTIONS */






/* Question 1 */
int ques1(int x, int y){
    int x_and_y = x&y; //bit wise and
    int x_or_y = ~(~x & ~y); //not (not x and not y) so x or y
    return (x_or_y & ~(x_and_y));// thereby produces an xor
    }
int ans1(int x, int y){
    //xor
    return  x ^ y;
    }


/* Question 2 */
int ques2(x) {
    int mask = x>>31;//shifts it to the right 31 bits resulting in 0
    int y= (x ^ mask);// xors it resulting in the input number
    int z = (~mask + 1);//results in 0
    return (y+z);//returns starting number
}

int ans2(x){
    return x;
}



/* Question 3 */
int ques3(int x) {
    int y = x >> 31;//is zero
    int z = !!x;//inverts the bits
    return y | z;//or
}

int ans3(int x){
    return 1;
}

/* Question 4 */

int ques4(int x, int y) {
	int a = x >> 31;//0
	int b = y >> 31;//0
	return ! (a & !b) | (( !(a ^b)) & (~y +x)>>31);
    //!(a & !b) is 1
    //!(a ^b)) is 1
    // then (~y +x)>>31 moves the 1 in 32 bit over
	  
}

int ans4(int x, int y){
    return 1;
}

/* Question 5 */

int ques5(int x, int n) {
    /* for this question ONLY, you can  assume x and n are not  negative numbers  */

    int temp = (1 << n);// moves 1 over n bits to the left    
    int z = temp + ~0;//temp is added by negative 1
    //printf("z and x : %d\n", z&x);
    return (z & x);

    //if n <= the number of bits it gets a different answer otherwise it is x
}

int ans5(int x, int n)
{
    int k = (int)pow(2,n);
    return (k-1)&x;
}

/* Question 6 */

int ques6(int x, int n){
  /* assume n<=30 */
  int mask = (1 <<n) + ( ~0);// shifts left
  int bias = (x >> 31) & mask;//shifts right
  //bias is always 0
  return ((x+bias)>> n);
}

int ans6(int x, int n)
{
    return (x+0)>>n;
}

/* Question 7 */

int ques7(int x, int y){
    int sum= x+y;
    int x_neg= x>>31;//this is 0
    int y_neg = y>>31;//this 0
    int s_neg = sum>>31;//this 0
    return !(~(x_neg^y_neg) & (x_neg^s_neg));//returns 1
    }
int ans7(int x, int y){
  
  return 1;
}

/* Question 8  */
int ques8(void) {
    int byte = 0xAA;//00aa
    int word = byte | byte<<8;//double the statement by moving the statment to the left and keeping the orginal statment
    //kind of like a copy and append of hex values
    return word | word<<16;//does the same thing as above just doubles this
}
int ans8(void) {
    return -1431655766;
}
/* Question 9 */
int ques9(int x){
    int m8= 0xAA;// starts with aa
    int m16 = m8 | m8 <<8;// then becomes aaaa
    int m32 = m16 | m16<<16;//then becomes aaaaaaa
    int y = x | m32;//this cycles through b, a, b, e, f
    return !! y;// the first ! makes it 0000, the second makes it 0001
    }
int ans9(int x){
    
    return 1;
    }

/* Question 10 */
int ques10(int x){
    int m8= 0xAA;
    int m16 = m8 | m8 <<8;
    int m32 = m16 | m16<<16;
    int fillx = x | m32;
    return !(~fillx);
}


/*Question 11 */
int ques11(int x, int y){
    int x_and_y = x &y;
    int nx_and_ny = (~x & ~y);
    return (x_and_y | nx_and_ny );
    }

/* Question 12 */

int ques12(int x, int n){
  /* assume n is <= 32 */
	int shift = 32 + ~n +1 ;
	int move = (x << shift) >> shift;
	return !(x^move);
	}

/* Question 13 */
int ques13(int x, int n){
  int z = n << 3;
  int y = ~(0xFF << z);
  return (y & x);
}

/* Question 14 */

int ques14(int x, int n, int m){
/* assume 0 <= n <=3 and 0 <= m <=3 */
	int n8= n <<3;
	int m8 = m <<3;
	int n_mask = 0xff << n8;
	int m_mask = 0xff << m8;
	int n_byte = ((x & n_mask) >>n8) & 0xff;
	int m_byte = ((x & m_mask) >> m8) & 0xff;
	int bytes_mask = n_mask | m_mask ;
	int leftover = x & ~bytes_mask;
	return ( leftover | (n_byte <<m8)| (m_byte << n8) );
	}


/* Question 15 */

int ques15(int x){
  int nx = ~x;
  int nxnz = !!nx;
  int nxov = !( nx +nx);
  return (nxnz & nxov);
}

/* Question 16 */
int ques16(int x){
    int wd16 = x ^ (x>>16);
    int wd8 = wd16 ^ (wd16 >>8);
    int wd4 = wd8 ^ (wd8<<4);
    int wd2= wd4 ^ (wd4<<2);
    int bit = (wd2 ^ (wd2>>1)) & (0x1);
    return bit;
}



  /* main is used only for testing the results of each function */
int main(){

  /* the variables defined in main are used to pass arguments to functions and get return value from the functions. */

  /* Example for ques0 */
  int a, b;/* input parameters to be sent to function  ques0 */
   int t1;
/**
 	printf("Enter first number, an integer stored into variable A preferably between 1 and 20:");
 	scanf ("%d",&a);
	printf("\n");
 	printf("Enter second number, an integer stored into variable B preferably between 1 and 20:");
 	scanf ("%d", &b);
	printf("\n");


	printf("you entered a= %d b= %d  \n", a,b);

**/
	//t1=ques3(a); /* call function ques0; return value is stored in t1 . Next, print out the return value. */
	//printf("output of ques2 is t1 = %d  \n", t1);
	//t1=ans1(a,b); /* call function ans0, return value is in t1. Next, print out the return value */
	//printf("output of ans0 is t1 = %d  \n", t1);

/**
 * Since the orginally input was a number between 1 and 20 I am only using numbers within that domain
 * 
 **/

	/* To test/run the functions, you will need to mimic the above process (input numbers and then call each of the functions, and print
 the return value) for each of the questions and answers */


   //for(int i = 1; i < 21; i++){
       // for(int j = 1; j < 21; j++){
       // t1=ques7(i,j); /* call function ques0; return value is stored in t1 . Next, print out the return value. */
 
     // int t2 =ans7(i, j);
      // if(t1 != t2){
     //       printf("%d, %d, output of ques7 is t1 = %d, t2 =%d  \n", i, j, t1, t2);
    //   }
        
    //   }
  //}   
  
  for(int i = 1; i < 21; i++){
  printf("%d, %d, output of ques9 is t1 = %04x, t2 =%04x  \n", i, 1, ques9(i), ans9(i));
  }
	return 0;
}
