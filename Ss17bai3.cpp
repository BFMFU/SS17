#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
void reverseString(char *str);
int countWords(char *str);
void toUpperCase(char *str);
void appendString(char *str1, char *str2);
int main() {
    char *str1=(char *)malloc(100*sizeof(char));
    char *str2=(char *)malloc(100*sizeof(char));
    int choice;
    do {
        printf("\n--- MENU ---\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi dao nguoc\n");
        printf("3. Dem so luong tu trong chuoi\n");
        printf("4. Nhap vao chuoi khac, so sanh chuoi do voi chuoi ban dau\n");
        printf("5. In hoa tat ca chu cai trong chuoi\n");
        printf("6. Nhap vao chuoi khac va them chuoi do vao chuoi ban dau\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar(); 
        switch (choice) {
        case 1:
            printf("Nhap vào chuoi: ");
            fgets(str1,100, stdin);
            str1[strcspn(str1, "\n")] = '\0';
            break;
        case 2:
            if (strlen(str1) == 0) {
                printf("Chuoi chua duoc nhap.\n");
            } else {
                printf("Chuoi dao nguoc: ");
                reverseString(str1);
            }
            break;
        case 3:
            if (strlen(str1) == 0) {
                printf("Chuoi chua duoc nhap.\n");
            } else {
                char temp[100];
                strcpy(temp, str1);
                printf("So luong tu trong chuoi: %d\n", countWords(temp));
            }
            break;
        case 4:
            if (strlen(str1) == 0) {
                printf("Chuoi ban dau chua duoc nhap.\n");
            } else {
                printf("Nhap vao chuoi khac: ");
                fgets(str2,100, stdin);
                str2[strcspn(str2, "\n")] = '\0';
                if (strlen(str1) > strlen(str2)) {
                    printf("Chuoi moi ngan hon chuoi ban dau.\n");
                } else if (strlen(str1) < strlen(str2)) {
                    printf("Chuoi moi dai hon chuoi ban dau.\n");
                } else {
                    printf("Hai chuoi co do dai bang nhau.\n");
                }
            }
            break;
        case 5:
            if (strlen(str1) == 0) {
                printf("Chuoi chua duoc nhap.\n");
            } else {
                toUpperCase(str1);
                printf("Chuoi sau khi in hoa: %s\n", str1);
            }
            break;
        case 6:
            if (strlen(str1) == 0) {
                printf("Chuoi ban dau chua duoc nhap.\n");
            } else {
                printf("Nhap vao chuoi khac: ");
                fgets(str2, 100, stdin);
                str2[strcspn(str2, "\n")] = '\0';
                appendString(str1, str2);
                printf("Chuoi sau khi ghep: %s\n", str1);
            }
            break;
        case 7:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 7);
    return 0;
}
void reverseString(char *str) {
    int len = strlen(str);
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
}
int countWords(char *str) {
    int count = 0;
    char *token = strtok(str, " ");
    while (token != NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}
void toUpperCase(char *str) {
    while (*str) {
        *str = toupper(*str);
        str++;
    }
}
void appendString(char *str1, char *str2) {
    strcat(str1, str2);
}

