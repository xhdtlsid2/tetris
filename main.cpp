
// ConsoleApplication1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

//#include "stdafx.h"
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
//#include <unistd.h> //for sleep() function
//#define TIME    0.5
#define col     12
#define row     25
#define bsize   4
#define Ox      5.5
#define Oy      1.5
#define blist   7
//int k;
//int Time = 1;
  //, end;
int score = 0, highscore = 0;
double Time = 1;
double x = Ox, y = Oy;
//y = 1.5;

int list[7][bsize + 1][bsize] = {
    {{ 0,0,0,0 },{ 0,0,0,0 },{ 1,1,1,1 },{ 0,0,0,0 },{ 4,0,0,0 }},  //I
    {{ 0,0,0,0 },{ 1,1,1,0 },{ 0,1,0,0 },{ 0,0,0,0 },{ 3,0,0,0 }},  //T
    {{ 1,1,0,0 },{ 0,1,1,0 },{ 0,0,0,0 },{ 0,0,0,0 },{ 3,0,0,0 }},  //Z
    {{ 0,1,1,0 },{ 1,1,0,0 },{ 0,0,0,0 },{ 0,0,0,0 },{ 3,0,0,0 }},  //CZ
    {{ 1,1,1,0 },{ 1,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 },{ 3,0,0,0 }},  //L
    {{ 1,1,1,0 },{ 0,0,1,0 },{ 0,0,0,0 },{ 0,0,0,0 },{ 3,0,0,0 }},  //CL
    {{ 0,0,0,0 },{ 0,1,1,0 },{ 0,1,1,0 },{ 0,0,0,0 },{ 4,0,0,0 }}   //S
};

//block[4][0] (=블럭의 크기) 를 항상 bsize 또는 bsize-1로 설정 (크기가 작은 블럭은 중심점으로 평행이동시켜주면 됨)
//ㄴ사용자 블럭 제작 시 자동으로 블럭의 중심점을 찾아 (자동 블럭 크기 구하는 방법 이용) 블럭이 저장될 배열 (bsize*bsize 크기)의 중심점으로 평행이동하여 저장, 블럭 제작이 이루어지는 배열과 실제 블럭이 저장되는 배열을 따로 만들기

int block[bsize + 1][bsize];
clock_t start;
/*
int I[bsize + 1][bsize] = {
	{ 0,0,0,0 },
	{ 0,0,0,0 },
	{ 1,1,1,1 },
	{ 0,0,0,0 },
	{ 4,0,0,0 }
};

int T[bsize + 1][bsize] = {
    { 0,0,0,0 },
    { 1,1,1,0 },
    { 0,1,0,0 },
    { 0,0,0,0 },
    { 3,0,0,0 }
};

int Z[bsize + 1][bsize] = {
    { 0,0,1,0 },
    { 0,1,1,0 },
    { 0,1,0,0 },
    { 0,0,0,0 },
    { 3,0,0,0 }
};

int CZ[bsize + 1][bsize] = {
    { 1,0,0,0 },
    { 1,1,0,0 },
    { 0,1,0,0 },
    { 0,0,0,0 },
    { 3,0,0,0 }
};

int L[bsize + 1][bsize] = {
    { 0,1,1,0 },
    { 0,1,0,0 },
    { 0,1,0,0 },
    { 0,0,0,0 },
    { 3,0,0,0 }
};

int CL[bsize + 1][bsize] = {
    { 1,1,0,0 },
    { 0,1,0,0 },
    { 0,1,0,0 },
    { 0,0,0,0 },
    { 3,0,0,0 }
};

int S[bsize + 1][bsize] = {
    { 1,1,0,0 },
    { 1,1,0,0 },
    { 0,0,0,0 },
    { 0,0,0,0 },
    { 2,0,0,0 }
};
*/
int board[row][col] = {
    { 1,0,0,0,0,0,0,0,0,0,0,1 },    // |
    { 1,0,0,0,0,0,0,0,0,0,0,1 },    // |Hidden layers
    { 1,0,0,0,0,0,0,0,0,0,0,1 },    // |
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },    // |
//----------------------------------//start
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
    { 1,0,0,0,0,0,0,0,0,0,0,1 },    //10
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },    //20
	{ 1,1,1,1,1,1,1,1,1,1,1,1 }
};

void gotoxy(int x,int y)
{
     COORD pos={x,y};
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void InitializeBoardandScore(){
    for(int j = 0 ; j < row ; j++){
        for(int i = 0 ; i < col ; i++){
            if(i == 0 || i == col - 1  || j == row - 1) board[j][i] = 1;
            else board[j][i] = 0;
        }
    }
    score = 0;
}

bool IsThereNzero(int j){
    for(int i = 1 ; i <= col - 2 ; i++){
        if(board[j][i] != 0) return true;
    }
    return false;
}

bool AreAllNzero(int j){
    for(int i = 1 ; i <= col - 2 ; i++){
        if(board[j][i] == 0) return false;
    }
    return true;
}
void printscore();  //prototyping
void checkline(){

    int prevscore = score;
    for(int k = row - 2 ; IsThereNzero(k) && k >= 0 ; ){
        if(AreAllNzero(k)) {
            score++;
            if(score % 10 == 0) Time = Time * 0.75;
            //지역 수식 o   //double Time = pow(0.75, score / 10) after checkline() in update()    //전역 수식 o도 가능은 하나 지역 수식 o가 가능하기 때문에 굳이 쓸 이유는 없음 (전역 < 지역)
                                                                                                //수식 o이면 변수에 저장됐던 이전 값을 이용하지 않으므로 전역 변수를 쓸 이유가 없음
                                                                                                //그러나 전역 변수 이용 시 score++;밑에 Time = pow(0.75, score / 10)를 쓰면 되므로 지역 변수를 이용할 때보다 불필요한 계산량이 적음

            int j;
            for(j = k ; IsThereNzero(j-1) && j != 0 ; j--){
                for(int i = 1 ; i <= col - 2 ; i++){
                    board[j][i] = board[j-1][i];
                }
            }
            for(int i = 1 ; i <= col - 2 ; i++){
                board[j][i] = 0;
            }
        //printscore();
        }
        else k--;
    }
    if(prevscore < score) printscore();
}
//조건 A != 조건 B //xor..?

bool checkoverlap(){

    for(int j = bsize - 1 ; j >= 0 ; j--){
        for(int i = 0 ; i < bsize ; i++){
            if(block[j][i] != 0 && board[(int)(y + j - 1.5)][(int)(x + i - 1.5)] != 0) return true;  //express 1.5 using bsize
        }
    }
    return false;
}

void printblock(int a, int b){
    switch(block[a][b]){
        case 0: printf("  ");
                break;

        case 1: printf("□");
    }
}

void printboard(int a, int b){
    switch(board[a][b]){
        case 0: printf("  ");
                break;

        case 1: printf("■");
    }
}

void printhelp(){
    char help[][30] = {
    "A - move left",
    "S - move down",
    "D - move right",
    "M - rotate clockwise",
    "N - rotate counter clockwise",  //+ '\0' = 29 characters
    "space bar - drop"
    //"H - hold"
    };
    for(int i = 0 ; i < 6 ; i++){   //6 : number of help
        //gotoxy(26, 2*j);
        //int z;
        gotoxy(2 * col + 2, (int)((double)((row - 4) - 12) / 3 + 0.5) + 2 * i); //12 = 11(help = list + (list - 1)) + 1(score)  = 2 * list
        //printf("%d %d",z, i);
        puts(help[i]);
    }
    gotoxy(0, 0);

}

void printscore(){
    //gotoxy(26, 15);
    gotoxy(2 * col + 2, (int)((double)((row - 4) - 10) / 3 + 0.5) * 2 + 9);
    printf("score : %d", score);  //if score < 2 "line" else "lines"
    gotoxy(0, 0);
}

void getblock(){
      //내려오고 1초 딜레이 후 다음 블럭 생성?    //맨 처음에 항상 같은 블럭?-no
    int k = rand() % blist;     //for user created blocks, there should be +n after blist
    for(int j = 0 ; j < bsize + 1 ; j++){
        for(int i = 0 ; i < bsize ; i++) {
            block[j][i] = list[k][j][i];
        }
    }
}


//'반시계 회전' 시 프로그램 오작동 현상에 대하여
//1. clock_t start;를 int block[][];밑에 쓰면 문제가 발생하지 않음.
//2. start라는 이름의 변수가 다른 파일에 존재? (static이 아닌 전역변수 선언 시 다른 파일에서도 접근 가능), start 선언 시 0이 아닌 다른 값으로 초기화하면 문제가 발생하지 않음.
//3. block[4][0]의 값이 3이상이면 문제가 발생하지 않음.


void rotate(int d) {   //★★bsize 대신 현재 블럭 리스트 중 가장 큰 블럭의 가로 세로 길이 중 더 큰 값을 넣는 방법? (항상 맥시멈 블럭 크기로 회전 수행 시 불필요한 계산(빈공간 회전)이 많이 발생하기 때문)

    double k = (double)block[4][0] / 2 - 0.5;             //in updated version the program will calculate the B[4][0] value automatically, so B[4][] will become unnecessary
    //if(B[4][0] == 1) k = ((double)bsize - 2) / 2;   //중심의       //3x3 block
    //else k = ((double)bsize - 1) / 2;               //평행이동
    //printf("%f",k);
	int backup[bsize][bsize];
	for (int i = 0; i < bsize; i++) {
		for (int j = 0; j < bsize; j++) {
			backup[i][j] = block[i][j];
		}
	}
    //배열 값이 0일 경우 패스하는 방법 이용해볼 것
	int temp1;
	double qx, qy, temp2;
    for (double i = 0; i < bsize; i++) {
		for (double j = 0; j < bsize; j++) {
			temp1 = backup[(int)i][(int)j];
			qx = j, qy = i;   //왼쪽 위부터 오른쪽 아래로 차례대로 진행
			qy = -qy; //y축 반전
			qx -= k, qy += k; //원점으로 중심 이동
			//------회전 알고리즘(시계방향 90도)------//
			temp2 = qx;
			qx = d * qy;
			qy = d * -temp2;
			//--------------------------------//
			qx += k, qy -= k; //중심 원위치
			qy = -qy; //y부호 원래대로 반전

			block[(int)qy][(int)qx] = temp1;  //현재 처리중인 배열 안의 값(회전 이전 상태, backup 배열)을 회전되었을 때 들어갈 배열 인덱스 자리(위 과정을 통해 구한)에다 넣음
		}
	}


    /*
	gotoxy(0,27);
	for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            printblock(i,j);
        }
        printf("\n");
	}
	gotoxy(0,0);
    */


    /*
	for (int i = 0; i < bsize; i++) {
        for (int j = 0; j < bsize; j++) {
            printf("%d", B[i][j]);
        }
        printf("\n");
    }
    */

}
/*
void printboard() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			switch (board[i][j]) {
			case 0:	//공백
				printf("  ");
				break;
			case 9:	//맵 테두리
				printf("□");
				break;
			default: //블럭
				printf("■");
			}

		}
		printf("\n");
	}
}
*/

void printall(){

    //gotoxy( 0 , 0 );
    double k, a, s, t, b;
    k = bsize / 2;
    if((b = bsize + 1.5 - y) < 0) b = 0;                  //b = (bsize - 0.5) - (y - 2) = 4 - {(y + 2) - (bsize - 0.5)}
    if((s = col - 10.5 - x) < 1) s = 0;
    if((t = col + 1.5 - x) > 3) t = 4;
    //use bsize when calculating b, s, t (express 1.5, 10.5, 1.5, 0, 1, 3, 4 with bsize)★★★★★★★★★★★★★★★★
    a = s;
    for(double j = bsize ; j < row ; j++){
        for(double i = 0 ; i < col ; i++){
            if((i > x - k) && (i <= x + k) && (j > y - k) && (j <= y + k)){
                //if(board==0) printf block; else printf board;
                if(board[(int)j][(int)i] == 0) printblock((int)b, (int)a);
                else printboard((int)j, (int)i);
                a++;
                if(a == t) b++, a = s;
            }else printboard((int)j, (int)i);
        }
        printf("\n");
    }

//    gotoxy()
    //printf("%d",score);
    //printf("%d %d",(int)s, (int)t);
    gotoxy(0, 0); //혹시 출력이 겹쳐서 혼란이 생길까 봐 주석처리함
}

bool restart(){
    switch(getch()){
    //y
    case  89:
    case 121:   InitializeBoardandScore();
                gotoxy(0, 0);
                printall();
                printhelp();
                printscore();
                start = clock();
                Time = 1;
                return false;
    //n
    case  78:
    case 110:   return true;

    default :   return restart();

    }
}

/*
void timer() {

	clock_t start, end;
	start = clock();
	while (1) {
		end = clock();
		double k = (end - start) / (double)1000;
		if (k >= TIME - 0.005 && k <= TIME + 0.005) {
			//printf("%.3fs passed\n", (double)TIME);
			//~Time;
			start = start + TIME * 1000;
		}
	}
}
clock_t cl1;
*/

void nextdrop(){
    y--;
    for(int j = 0 ; j < bsize ; j++){
        for(int i = 0 ; i < bsize ; i++){
            if(block[j][i] != 0) board[(int)(y + j - 1.5)][(int)(x + i - 1.5)] = block[j][i];
            //블럭이 내려왔을 때 맵에서 완전 다른 블럭으로 바뀔 시 따로 if문을 만들어 주면 됨
            //ex) if(block[][] == k) board[][] = l;
        }
    }
    checkline();

    x = Ox, y = Oy;
    //getblock();
}

bool gameover(){
    system("cls");
    gotoxy(col - 5, (row - 4) / 2 - 2);
    printf("GAME OVER!");           //10
    int cnt = 0;
    int tempscore = score;
    do{
        tempscore = tempscore / 10;
        cnt++;
    }while(tempscore >= 1);

    /*
    COUNTING DIGITS
    double score = 12289.1223;    //-1928, ...
    int cnt = 0;
    do{
        score = score / 10;
        cnt++;
    }while(score >= 1 || score <= -1);
    printf("%d\n",cnt);
    */

    //if(cnt % 2 == 0){
    gotoxy(col - (8 + cnt) / 2, (row - 4) / 2);
    //}else gotoxy(col - (8 + cnt) / 2 - 1, (row - 4) / 2);
    printf("score : %d", score);
    gotoxy(col - 9, (row - 4) / 2 + 2);
    printf("RESTART? ( Y / N )");   //18
    return restart();  //1. 포인터로 main함수의 quit에 접근하여 대입하고, return;으로 끝내는 방법. update함수의 data type를 void로 할 수 있다.
                       //2. return restart;를 이용하는 방법. update함수의 data type을 bool로 해야 한다.
}

bool update(int *hold){

    double tx = x, ty = y;
    bool r_ovlp = false;
    bool otherkey = false;

    //bool overlap = 0;
   // clock_t start, end;
            /*
                    gotoxy(0,25);
                    printf("%ld      \n       ",start);
                    Sleep(250);
                    gotoxy(0,0);

            */
    //int a = 0, b = 0;
    //double x = 5.5, y = 5.5;
    //start = clock();    -> while(1) 밖에 있어야 함
    ////for(double j = 0 ; j < 100 ; j++){             //j = y
    ////    for(double i = 0 ; i < 1000 ; i++){         //i = x

            //start = clock();
            /*
            if(j == 0 && i == 0){
                //clock_t cl1;
                cl1 = clock();
                printf("%f", (clock() - start) / (double)1000);
            }
*/
            //end = clock();                                                                            >
            //double k = (end - start) / (double)1000;                                                  >
            //if (k >= TIME - 0.005 && k <= TIME + 0.005) { (아랫줄 대신 이용 가능(오차범위를 0.005로 설정한 것))     >
            //if (k == TIME){                                                                           >
            if(kbhit()){
                switch(getch()){
                case  97:
                    x--;
                    break;

                case 100:
                    x++;
                    break;

                case 115:
                    y++;
                    break;

                case 110:
                    rotate(-1);    //counter clockwise
                    if(checkoverlap() == true){
                        r_ovlp = true;
                        rotate(1);
                        //Sleep(500);
                        //return;
                    }
                    break;

                case 109:

                    rotate(1);     //clockwise
                    if(checkoverlap() == true){
                        r_ovlp = true;
                        rotate(-1);
                        //Sleep(500);
                        //return;
                    }
                    break;
                    //break;
                    //rotate 시 겹칠 때 (overlap 확인 함수 이용)rotate 취소하기 -> rotate 3번! // 임시배열?(계산량 가장 적음) //역회전?
                    //3rotate < 역회전, 임시배열을 이용하는 방법은 계산량은 적으나 추가되는 코드 길이가 길고 코드를 이해하기가 조금 어려울 수 있으므로 역회전으로 결정, 새로운 조작 키로도 만들 수 있어서 좋음->
                    //rotate 함수에 회전각을 인자로 전달해줘야됨★★★, 회전변환 공식 그대로 적용★★★


                    //한방에 밑으로 내려오는 키 만들기 (checkoverlap == true 가 될 때 까지 y를 증가시키면 됨)★★★★
                case 32:    //space bar

                    start = clock();
                    while(checkoverlap() == false) y++;

                    nextdrop();
                    getblock();

                    //gameover()이 아닐 때 밑으로 계속 진행하는 문제? 다시 처음으로 돌아와야 함"★★★★★"
                    if(checkoverlap() == true) return gameover();   //return is (kind of) playing the role of "else"
                    printall();
                    return false;

                case 104:   //h

                    if(*hold % 2 != 0){
                        switch(*hold){

//                        case 1: holdin();
                                break;

  //                      case 3: holdout();

                        }
                        *hold++;
                    }
                    /*
                    switch(*hold){

                    case 1: holdin();
                            *hold = 3;
                            break;

                    case 2: holdout();
                            *hold = 4;

                    //case 3: break;

                    //case 4:

                    }
                    */
                    break;

                default:

                    otherkey = true;
                }
                /*
                    gotoxy(0,25);
                    printf("%ld      \n       ",start);
                    Sleep(250);
                    gotoxy(0,0);
                */
            if(checkoverlap() == true) x = tx, y = ty;
            else if(r_ovlp == false && otherkey == false) printall();
            //checkoverlap이 true인 회전은 출력되고있음★★★★★★★★★★★★★★ - 해결
            /*
            for(b = bsize - 1 ; b >= 0 ; b--){
                for(a = 0 ; a < bsize ; a++){
                    if(CL[(int)b][(int)a] == 1 && board[(int)(y + b - 1.5)][(int)(x + a - 1.5)] == 9){  //express 1.5 using bsize
                        x = tx;
                        y = ty;
                        overlap = 1;
                        break;
                    }
                }
            }
            */
            //make overlap check to a function!★★
            //위 블럭 리스트를 3차원 배열으로 만들기, 랜덤으로 블럭 뽑을 때 편함! [a][bsize+1][bsize] 에서 a가 각 블럭을 지정하는 인덱스가 됨★★
            /*
            if(overlap == 0) printboard();
            */
            //if(getch() == '0') printf("ch1");
            //else printf("ch2");
            }


            if ((clock() - start) / (double)1000 >= Time){
                    //ㄴint r;
            //if ((end - start) / (double)1000 == TIME) {
			//printf("%.3fs passed\n", (double)TIME);
			//~Time;
                /*
                    gotoxy(0,25);
                    printf("%ld      \n%ld       ",start,r);
                    Sleep(500);
                    gotoxy(0,0);
                */
			//start += TIME * 1000;
			start = clock();
			y++;

			if(checkoverlap() == true){     //끝까지 내려옴
			    nextdrop();
			    getblock();
			    /*
                y--;
                for(int j = 0 ; j < bsize ; j++){
                    for(int i = 0 ; i < bsize ; i++){
                        if(block[j][i] != 0) board[(int)(y + j - 1.5)][(int)(x + i - 1.5)] = block[j][i];
                        //블럭이 내려왔을 때 맵에서 완전 다른 블럭으로 바뀔 시 따로 if문을 만들어 주면 됨
                        //ex) if(block[][] == k) board[][] = l;
                    }
                }
                checkline();

                x = Ox, y = Oy;
                getblock();
                */
                if(checkoverlap() == true) return gameover();
                /*{ //if statement is necessary for determining whether "this" function will return or not


                    system("cls");
                    gotoxy(col - 5, (row - 4) / 2 - 2);
                    printf("GAME OVER!");           //10
                    int cnt = 0;
                    int tempscore = score;
                    do{
                        tempscore = tempscore / 10;
                        cnt++;
                    }while(tempscore >= 1);
                    //if(cnt % 2 == 0){
                    gotoxy(col - (8 + cnt) / 2, (row - 4) / 2);
                    //}else gotoxy(col - (8 + cnt) / 2 - 1, (row - 4) / 2);
                    printf("score : %d", score);
                    gotoxy(col - 9, (row - 4) / 2 + 2);
                    printf("RESTART? ( Y / N )");   //18
                    return restart();  //1. 포인터로 main함수의 quit에 접근하여 대입하고, return;으로 끝내는 방법. update함수의 data type를 void로 할 수 있다.
                                       //2. return restart;를 이용하는 방법. update함수의 data type을 bool로 해야 한다.


                }
                */
                //Sleep(3000);
                //sleep(k*TIME); ??


                if(*hold % 2 == 0) *hold++;
                if(*hold > 4) *hold %= 4;
                /*
                switch(*hold){

                case 3: *hold = 2;
                        break;

                case 4: *hold = 1;

                }
                */
			}
			printall();
			//start = clock();
			//if(overlap == 0) printboard();★★★★★★★
			//else move_to_the_next_block;★★★★★★★★★
			//블럭의 1을 보드의 9로 바꿔줘야함★★★★★★
			//x,y위치 초기화, 랜덤숫자(a) 뽑아 블럭 결정 ([a][bsize + 1][bsize])


			//한 줄 모두 채우면 그 줄이 없어지고 위에 있는 모든 블럭이 밑으로 없어진 줄 수 만큼 내려옴
			//printboard();
            }

            /*/*
            if(j==99&&i==999) {
                    printf("ch");
                switch(getch()){
                case 75:
                    x--;
                    break;

                case 77:
                    x++;
                    break;

                case 80:
                    y++;
                    break;

                case 32:
                    rotate(Z);

                }
            printboard();
            }
            //*/
    //printf("%f",(clock() - cl1 ) / (double)1000 );
    ////    }
    ////}
    //printf("%d",k++);
    return false;
}

























int main() {

    //start
    int startboard[25][3] = {
        {0,0,0},
        {1,1,1},{0,1,0},{0,1,0},    //T
        {0,0,0},
        {1,1,1},{1,1,0},{1,1,1},    //E
        {0,0,0},
        {1,1,1},{0,1,0},{0,1,0},    //T
        {0,0,0},
        {1,1,1},{1,1,0},{1,0,1},    //R
        {0,0,0},
        {1,1,1},{0,1,0},{1,1,1},    //I
        {0,0,0},
        {0,1,1},{0,1,0},{1,1,0},    //S
        {0,0,0}
    };
    for(int j = 0 ; j < 25 ; j++){
        gotoxy(8, j);
        for(int i = 0 ; i < 3 ; i++){       //printstart(startboard[j][i]); + after for loop(i) printf("\n");
            switch(startboard[j][i]){

            case 0 : printf("  ");
                     break;

            case 1 : printf("■");

            }
        }
        printf("\n");
    }
    printf("Press any key to start");
    getch();

    //in-game && end
    system("cls");
    //gotoxy(0, 0); //system("cls") moves cursor to origin

    bool quit = false;

    srand(time(NULL));

    getblock();
    printall();
    printhelp();
    printscore();

    start = clock();

    int hold = 1;
    while(quit == false){
            //gotoxy( 0 , 0 );
        //timer();
        quit = update(&hold);
    }
    //printf("%d",quit);                                                            //update()에서 return이 없을 때?
    /*
    //printf("%d",(int)-0.5);
	int a;
    //printf("%d", sizeof(I[4][4]));
	while (1) {
		scanf("%d", &a);
		if (a == 1) {
			rotate(I);
		}
	}
	*/
	/*
    int k;
	while(k = getch(), k != '0'){
            printf("A");

	}
	*/
    /*
    start = clock();
    int k;
    while(1){
        end = clock();
        if((end - start) / (double)1000 == TIME) break;
        if(k = kbhit(), k != 0) printf("%d", k);
    //&& getch() == '0'
        //if(kbhit() == 0) printf("ch");
    }
    printf("end");
    */
    /*
    int k = kbhit();
    printf("%d", k);
    getch();
    */
/*
    start = clock();
    while((clock() - start) / (double)1000 <= TIME){
        getch();
    }
*/
/*
    int a = 1;
    start = clock();
    while((clock() - start) / (double)1000 <= TIME){
        //printf("%d", kbhit());

        if(getch() == '0' && a != 1 ) printf("ch");     // &&(AND)조건문에서 조건의 순서 상관 "있음"
        //printf("%d\n", kbhit());

    }
    */
    /*
    while(1){
        int k = 0, l = 0;
        for(int i = 0 ; i < 12000 ; i++){

                if(i == 120*k){
                  printf("%d", l);
                  k++;
                  l++;
                  if(k % 10 == 0) l -= 10;
                } else printf("%d", kbhit());
                if(i == 11999) printf("\n\n");
        }
        getch();
    }
    */




    /*
    start = clock();
    while((clock() - start) / (double)1000 <= TIME){
        if(kbhit()){
            switch(getch()){
            case 75:
                printf("ch1");
                break;

            case 77:
                printf("ch2");
                break;

            case 80:
                printf("ch3");
            }
            //if(getch() == '0') printf("ch1");
            //else printf("ch2");
        }
    }
    */






    /*
    int a;
    while(1){

        printf("%d", kbhit());
        scanf("%d", &a);
    }
    */

    //while(1) printf("%d\n", getch());
    return 0;
}

