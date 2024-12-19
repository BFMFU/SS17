#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
void printMenu(void);
void inputChar(char *str);
void printChar(char *str);
void countWord(char *str);
void countNum(char *str);
void count(char *str);
int main(){
	char *string=(char *)malloc(100*sizeof(char));
	int choice;
	do{
		printMenu();
		printf("Lua chon cua ban la: ");
		scanf("%d",&choice);
		getchar();
		switch (choice){
			case 1:{
				inputChar(string);
				break;
			}
			case 2: {
				printChar(string);
				break;
			}
			case 3: {
				countWord(string);
				break;
			}
			case 4: {
				countNum(string);
				break;
			}
			case 5:{
				count(string);
				break;
			}
			case 6:{
				printf("Thoat chuong trinh.");
				break;
			}
			default:{
				printf("Lua chon khong hop le. Vui long chon lai.");
				break;
			}
		}
	}while(choice!=6);
	return 0;
}
void printMenu(void) {
    printf("\nMENU\n");
    printf("1. Nhap vao chuoi.\n");
    printf("2. In ra chuoi.\n");
    printf("3. Dem so luong chu cai va in ra.\n");
    printf("4. Dem so luong chu so va in ra.\n");
    printf("5. Dem so luong ky tu dac biet va in ra.\n");
    printf("6. Thoat.\n");
}
void inputChar(char *str){
	printf("Nhap vao chuoi ky tu ban muon: \n");
	fgets(str,100,stdin);
}
void printChar(char*str){
	printf("Chuoi hien tai la: %s",str);
}
void countWord(char *str){
	int countWord=0;
	for(int i=0;str[i]!='\0';i++){
		if(isalpha(str[i])){
			countWord++;
			printf("%c",str[i]);
		}
	}
	printf("\n");
	printf("So luong ky tu chu: %d",countWord);
}
void countNum(char *str){
	int countNum=0;
	for(int i=0;str[i]!='\0';i++){
		if(isdigit(str[i])){
			countNum++;
			printf("%c",str[i]);
		}
	}
	printf("\n");
	printf("So luong ky tu chu so: %d",countNum);
}
void count(char *str){
	int countSpecial=0;
	for(int i=0;str[i];i++){
		if(!isalnum(str[i])){
			countSpecial++;
			printf("%c",str[i]);
		}
	}
	printf("\n");
	printf("So luong ky tu dac biet: %d",countSpecial);
}
	




