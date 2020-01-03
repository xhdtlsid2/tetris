
// ConsoleApplication1.cpp: �ܼ� ���� ���α׷��� �������� �����մϴ�.
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

//block[4][0] (=���� ũ��) �� �׻� bsize �Ǵ� bsize-1�� ���� (ũ�Ⱑ ���� ���� �߽������� �����̵������ָ� ��)
//������� �� ���� �� �ڵ����� ���� �߽����� ã�� (�ڵ� �� ũ�� ���ϴ� ��� �̿�) ���� ����� �迭 (bsize*bsize ũ��)�� �߽������� �����̵��Ͽ� ����, �� ������ �̷������ �迭�� ���� ���� ����Ǵ� �迭�� ���� �����

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
            //���� ���� o   //double Time = pow(0.75, score / 10) after checkline() in update()    //���� ���� o�� ������ �ϳ� ���� ���� o�� �����ϱ� ������ ���� �� ������ ���� (���� < ����)
                                                                                                //���� o�̸� ������ ����ƴ� ���� ���� �̿����� �����Ƿ� ���� ������ �� ������ ����
                                                                                                //�׷��� ���� ���� �̿� �� score++;�ؿ� Time = pow(0.75, score / 10)�� ���� �ǹǷ� ���� ������ �̿��� ������ ���ʿ��� ��귮�� ����

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
//���� A != ���� B //xor..?

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

        case 1: printf("��");
    }
}

void printboard(int a, int b){
    switch(board[a][b]){
        case 0: printf("  ");
                break;

        case 1: printf("��");
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
      //�������� 1�� ������ �� ���� �� ����?    //�� ó���� �׻� ���� ��?-no
    int k = rand() % blist;     //for user created blocks, there should be +n after blist
    for(int j = 0 ; j < bsize + 1 ; j++){
        for(int i = 0 ; i < bsize ; i++) {
            block[j][i] = list[k][j][i];
        }
    }
}


//'�ݽð� ȸ��' �� ���α׷� ���۵� ���� ���Ͽ�
//1. clock_t start;�� int block[][];�ؿ� ���� ������ �߻����� ����.
//2. start��� �̸��� ������ �ٸ� ���Ͽ� ����? (static�� �ƴ� �������� ���� �� �ٸ� ���Ͽ����� ���� ����), start ���� �� 0�� �ƴ� �ٸ� ������ �ʱ�ȭ�ϸ� ������ �߻����� ����.
//3. block[4][0]�� ���� 3�̻��̸� ������ �߻����� ����.


void rotate(int d) {   //�ڡ�bsize ��� ���� �� ����Ʈ �� ���� ū ���� ���� ���� ���� �� �� ū ���� �ִ� ���? (�׻� �ƽø� �� ũ��� ȸ�� ���� �� ���ʿ��� ���(����� ȸ��)�� ���� �߻��ϱ� ����)

    double k = (double)block[4][0] / 2 - 0.5;             //in updated version the program will calculate the B[4][0] value automatically, so B[4][] will become unnecessary
    //if(B[4][0] == 1) k = ((double)bsize - 2) / 2;   //�߽���       //3x3 block
    //else k = ((double)bsize - 1) / 2;               //�����̵�
    //printf("%f",k);
	int backup[bsize][bsize];
	for (int i = 0; i < bsize; i++) {
		for (int j = 0; j < bsize; j++) {
			backup[i][j] = block[i][j];
		}
	}
    //�迭 ���� 0�� ��� �н��ϴ� ��� �̿��غ� ��
	int temp1;
	double qx, qy, temp2;
    for (double i = 0; i < bsize; i++) {
		for (double j = 0; j < bsize; j++) {
			temp1 = backup[(int)i][(int)j];
			qx = j, qy = i;   //���� ������ ������ �Ʒ��� ���ʴ�� ����
			qy = -qy; //y�� ����
			qx -= k, qy += k; //�������� �߽� �̵�
			//------ȸ�� �˰���(�ð���� 90��)------//
			temp2 = qx;
			qx = d * qy;
			qy = d * -temp2;
			//--------------------------------//
			qx += k, qy -= k; //�߽� ����ġ
			qy = -qy; //y��ȣ ������� ����

			block[(int)qy][(int)qx] = temp1;  //���� ó������ �迭 ���� ��(ȸ�� ���� ����, backup �迭)�� ȸ���Ǿ��� �� �� �迭 �ε��� �ڸ�(�� ������ ���� ����)���� ����
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
			case 0:	//����
				printf("  ");
				break;
			case 9:	//�� �׵θ�
				printf("��");
				break;
			default: //��
				printf("��");
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
    //use bsize when calculating b, s, t (express 1.5, 10.5, 1.5, 0, 1, 3, 4 with bsize)�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
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
    gotoxy(0, 0); //Ȥ�� ����� ���ļ� ȥ���� ����� �� �ּ�ó����
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
            //���� �������� �� �ʿ��� ���� �ٸ� ������ �ٲ� �� ���� if���� ����� �ָ� ��
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
    return restart();  //1. �����ͷ� main�Լ��� quit�� �����Ͽ� �����ϰ�, return;���� ������ ���. update�Լ��� data type�� void�� �� �� �ִ�.
                       //2. return restart;�� �̿��ϴ� ���. update�Լ��� data type�� bool�� �ؾ� �Ѵ�.
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
    //start = clock();    -> while(1) �ۿ� �־�� ��
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
            //if (k >= TIME - 0.005 && k <= TIME + 0.005) { (�Ʒ��� ��� �̿� ����(���������� 0.005�� ������ ��))     >
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
                    //rotate �� ��ĥ �� (overlap Ȯ�� �Լ� �̿�)rotate ����ϱ� -> rotate 3��! // �ӽù迭?(��귮 ���� ����) //��ȸ��?
                    //3rotate < ��ȸ��, �ӽù迭�� �̿��ϴ� ����� ��귮�� ������ �߰��Ǵ� �ڵ� ���̰� ��� �ڵ带 �����ϱⰡ ���� ����� �� �����Ƿ� ��ȸ������ ����, ���ο� ���� Ű�ε� ���� �� �־ ����->
                    //rotate �Լ��� ȸ������ ���ڷ� ��������ߵʡڡڡ�, ȸ����ȯ ���� �״�� ����ڡڡ�


                    //�ѹ濡 ������ �������� Ű ����� (checkoverlap == true �� �� �� ���� y�� ������Ű�� ��)�ڡڡڡ�
                case 32:    //space bar

                    start = clock();
                    while(checkoverlap() == false) y++;

                    nextdrop();
                    getblock();

                    //gameover()�� �ƴ� �� ������ ��� �����ϴ� ����? �ٽ� ó������ ���ƿ;� ��"�ڡڡڡڡ�"
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
            //checkoverlap�� true�� ȸ���� ��µǰ������ڡڡڡڡڡڡڡڡڡڡڡڡڡ� - �ذ�
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
            //make overlap check to a function!�ڡ�
            //�� �� ����Ʈ�� 3���� �迭���� �����, �������� �� ���� �� ����! [a][bsize+1][bsize] ���� a�� �� ���� �����ϴ� �ε����� �ʡڡ�
            /*
            if(overlap == 0) printboard();
            */
            //if(getch() == '0') printf("ch1");
            //else printf("ch2");
            }


            if ((clock() - start) / (double)1000 >= Time){
                    //��int r;
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

			if(checkoverlap() == true){     //������ ������
			    nextdrop();
			    getblock();
			    /*
                y--;
                for(int j = 0 ; j < bsize ; j++){
                    for(int i = 0 ; i < bsize ; i++){
                        if(block[j][i] != 0) board[(int)(y + j - 1.5)][(int)(x + i - 1.5)] = block[j][i];
                        //���� �������� �� �ʿ��� ���� �ٸ� ������ �ٲ� �� ���� if���� ����� �ָ� ��
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
                    return restart();  //1. �����ͷ� main�Լ��� quit�� �����Ͽ� �����ϰ�, return;���� ������ ���. update�Լ��� data type�� void�� �� �� �ִ�.
                                       //2. return restart;�� �̿��ϴ� ���. update�Լ��� data type�� bool�� �ؾ� �Ѵ�.


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
			//if(overlap == 0) printboard();�ڡڡڡڡڡڡ�
			//else move_to_the_next_block;�ڡڡڡڡڡڡڡڡ�
			//���� 1�� ������ 9�� �ٲ�����ԡڡڡڡڡڡ�
			//x,y��ġ �ʱ�ȭ, ��������(a) �̾� �� ���� ([a][bsize + 1][bsize])


			//�� �� ��� ä��� �� ���� �������� ���� �ִ� ��� ���� ������ ������ �� �� ��ŭ ������
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

            case 1 : printf("��");

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
    //printf("%d",quit);                                                            //update()���� return�� ���� ��?
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

        if(getch() == '0' && a != 1 ) printf("ch");     // &&(AND)���ǹ����� ������ ���� ��� "����"
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

