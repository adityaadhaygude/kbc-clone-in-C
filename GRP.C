#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void border()     
	 {cprintf("\r\n����[�]���������������������������������������������������������������������ͻ");
	  cprintf("\r\n�                                                                            �");
	  cprintf("\r\n�                                                                            �");
	  cprintf("\r\n�                                                                            �");
	  cprintf("\r\n�                                                                            �");
	  cprintf("\r\n�                                                                            �");
	  cprintf("\r\n�                                                                            �");
	  cprintf("\r\n�                                                                            �");
	  cprintf("\r\n�                                                                            �");
	  cprintf("\r\n�                                                                            �");
	  cprintf("\r\n�                                                                            �");
	  cprintf("\r\n�                                                                            �");
	  cprintf("\r\n�                                                                            �");
	  cprintf("\r\n�                                                                            �");
	  cprintf("\r\n�                                                                            �");
	  cprintf("\r\n�                                                                            �");
	  cprintf("\r\n�                                                                            �");
	  cprintf("\r\n�                                                                            �");
	  cprintf("\r\n��Ͱ������������������������������������������������������������������������ͼ");}

void main()
{
	FILE *fp,*fp1,*fq;
	int i=3,n,cnt=0,random_que,actual_ans_index,que_no=1;
	char name[30],j,r,input_answer,exit,answer[116];
	static ch;
	clrscr();
	textcolor(WHITE);
	textbackground(BLUE);
	cprintf("\r\n����[�]���������������������������������������������������������������������ͻ");
	cprintf("\r\n�                                 WELCOME                                    �");
	cprintf("\r\n�                            TO KBC QUIZ GAME                                �");
	cprintf("\r\n�                                                                            �");
	cprintf("\r\n�          $**** Welcome To Kaun Banega Crorepati ****$                      �");
	cprintf("\r\n�                         ARE YOU READY TO PLAY ........?                    �");
	cprintf("\r\n�                             RULES for KBC                                  �");
	cprintf("\r\n�         1.The game consists of 10 questions.                               �");
	cprintf("\r\n�         2.Every question consists of 4 options with 1 correct option.      �");
	cprintf("\r\n�         3.For every correct answer you will be getting Rs.10000 of money   �");
	cprintf("\r\n�         4.You will be exit out of game for wrong answer.                   �");
	cprintf("\r\n�         5.You can use 50-50 option only one time.                          �");
	cprintf("\r\n�         6.50-50 option is avilable only after 8th question.                �");
	cprintf("\r\n�        If you are intrested to play game press ENTER to enter into game.   �");
	cprintf("\r\n�                                                                            �");
	cprintf("\r\n�                                                                            �");
	cprintf("\r\n��Ͱ������������������������������������������������������������������������ͼ");
	getch();
	clrscr();
//==============================================================================================

	border();
	gotoxy(3,3);
	printf("Enter your name:  ");  //WE ARE GETTING PLAYERS NAME AS INPUT
	scanf("%s",name);
	clrscr();
	while(que_no<=10)
	{
		border();
		fp=fopen("q.c","r");   //open question containing file to read questions.
		randomize();
		random_que=rand()%58; //RANDOM QUESTION WILL BE CHOOSEN & SHOWN ON SCREEN.
		cnt=0;
		gotoxy(3,3);
		printf("Your %d question is on your screen\n",que_no);
		gotoxy(70,3);
		printf("%s",name);
		gotoxy(3,4);
		printf("%d.",que_no);
		while(cnt<7*(random_que-1))    //FROM QUE.C FILE WE HAVE MANAGANED 7 LINES SO HERE IS LOGIC FOR GETTING ONLY 1 QUE AT ATIME
		{
			fscanf(fp,"%c",&ch);
			if(ch=='\n')
			cnt++;
		}
		cnt=0;
		i=3;
		while(cnt<7)
		{
			fscanf(fp,"%c",&ch);
			printf("%c",ch);
			if(ch=='\n')
			{
				cnt++;
				gotoxy(3,2+i);
				i++;
			}
		}

		fp1=fopen("opt.c","r");  //opening options file for matching input with correct option.
		for(i=0;i<116;i++)
		{
			answer[i]=fgetc(fp1);
		}
		i=8;
		actual_ans_index=random_que*2-2;    //LOGIC TO STORE ACTUAL ANS OF THAT PARTICULAR QUESTION.
		gotoxy(3,5+i);
		printf("Enter your answer:\n");
		gotoxy(3,6+i);
		scanf(" %c",&input_answer);
		//IF YOU INPUT CORRECT ANSWER FOLLOWING WINDOW WILL BE SHOWN.
		if(toupper(input_answer)==answer[actual_ans_index])
		{
			gotoxy(3,7+i);
			printf("Correct answer");
			getch();
			clrscr();
			cprintf("\r\n����[�]���������������������������������������������������������������������ͻ");
			cprintf("\r\n�                                                                            �");
			cprintf("\r\n�                                                                            �");
			cprintf("\r\n�                                                                            �");
			cprintf("\r\n�                                                                            �");
			cprintf("\r\n�                                                                            �");
			cprintf("\r\n�                                                                            �");
			cprintf("\r\n�                                                                            �");
			cprintf("\r\n�                       ��������������������������ͻ                         �");
			cprintf("\r\n�                       � YOU HAVE WON RS.%d0000    �                         �",que_no);
			cprintf("\r\n�                       ��������������������������ͼ                         �");
			cprintf("\r\n�                                                                            �");
			cprintf("\r\n�                                                                            �");
			cprintf("\r\n�                                                                            �");
			cprintf("\r\n�                                                                            �");
			cprintf("\r\n�                                                                            �");
			cprintf("\r\n�                                                                            �");
			cprintf("\r\n�                                                                            �");
			cprintf("\r\n��Ͱ������������������������������������������������������������������������ͼ");
			getch();
			clrscr();
		}
		//--------------------------------------------------------------------------------------------------------
		//IF YOU INPUT WRONG ANSWER FOLLOWING WINDOW WILL BE SHOWN
		else
		{
			gotoxy(3,8+i);
			printf("wrong answer\n");
			fq=fopen("ans.c","r");
			gotoxy(3,9+i);
			printf("Correct answer is ");
			cnt=1;
			while(cnt<random_que)
			{
				fscanf(fq,"%c",&ch);
				if(ch=='\n')
				{
					cnt++;
				}
			}
			cnt=0;
			while(cnt<1)
			{
				fscanf(fq,"%c",&ch);
				printf("%c",ch);
				if(ch=='\n')
				{
					cnt++;
					gotoxy(3,2+i);
					i++;
				}
			}
			getch();
			clrscr();
			cprintf("\r\n����[�]���������������������������������������������������������������������ͻ");
			cprintf("\r\n�                                                                            �");
			cprintf("\r\n�                                                                            �");
			cprintf("\r\n�                                                                            �");
			cprintf("\r\n�                                                                            �");
			cprintf("\r\n�                                                                            �");
			cprintf("\r\n�                                                                            �");
			cprintf("\r\n�                                                                            �");
			cprintf("\r\n�                                ����������ͻ                                �");
			cprintf("\r\n�                                � YOU LOST �                                �");
			cprintf("\r\n�                                ����������ͼ                                �");
			cprintf("\r\n�                                                                            �");
			cprintf("\r\n�                                                                            �");
			cprintf("\r\n�                                                                            �");
			cprintf("\r\n�                                                                            �");
			cprintf("\r\n�                                                                            �");
			cprintf("\r\n�                                                                            �");
			cprintf("\r\n�                                                                            �");
			cprintf("\r\n��Ͱ������������������������������������������������������������������������ͼ");
			getch();
			clrscr();
			border()     ;
			gotoxy(28,10);
			printf("You have won Rs%d0000",que_no-1);
			getch();
			break;
		 }
		que_no++;
		if(que_no==11)
		{
			clrscr();
			border()     ;
			gotoxy(23,10);
			printf("%s is the new winner of our game",name);
			getch();
		}
		fclose(fp);
	}
}