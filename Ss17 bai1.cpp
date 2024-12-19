#include <stdio.h>
#include <stdlib.h>

void printMenu(void);
void printArray(int n, int *arr);
int calculateSum(int n, int *arr);
void findMax(int n, int *arr);

int main() {
    int n = 0; // 
    int choice;
    int *arr = (int *)malloc(100 * sizeof(int)); // 

    do {
        printMenu();
        printf("Lua chon cua ban la: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: { // 
                do {
                    printf("Nhap so phan tu ban muon: ");
                    scanf("%d", &n);
                } while (n < 0 || n > 100);

                for (int i = 0; i < n; i++) {
                    printf("Nhap gia tri arr[%d]= ", i);
                    scanf("%d", &arr[i]);
                }
                break;
            }
            case 2: { // 
                printArray(n, arr);
                break;
            }
            case 3: { // 
                printf("Do dai mang la: %d\n", n);
                break;
            }
            case 4: { // 
                int sum = calculateSum(n, arr);
                printf("Tong cac phan tu trong mang la: %d\n", sum);
                break;
            }
            case 5: { // 
                findMax(n, arr);
                break;
            }
            case 6: {
                printf("Thoat chuong trinh.\n");
                break;
            }
            default: {
                printf("Lua chon khong hop le. Vui long chon lai.\n");
                break;
            }
        }
    } while (choice != 6);

    free(arr); //y
    return 0;
}
void printMenu(void) {
    printf("\nMENU\n");
    printf("1. Nhap vao so phan tu va tung phan tu.\n");
    printf("2. Hien thi cac phan tu trong mang.\n");
    printf("3. Tinh do dai mang.\n");
    printf("4. Tinh tong cac phan tu trong mang.\n");
    printf("5. Tim gia tri lon nhat trong mang.\n");
    printf("6. Thoat.\n");
}
void printArray(int n, int *arr) {
    if (n == 0) {
        printf("Mang hien tai khong co phan tu nao.\n");
        return;
    }
    printf("Mang hien tai la: ");
    for (int i = 0; i < n; i++) {
        printf("arr[%d]=%d ", i, arr[i]);
    }
    printf("\n");
}
int calculateSum(int n, int *arr) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}
void findMax(int n, int *arr) {
    if (n == 0) {
        printf("Mang hien tai khong co phan tu nao.\n");
        return;
    }
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("Gia tri lon nhat trong mang la: %d\n", max);
}

