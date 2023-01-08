
#include <stdio.h>
#include <stdlib.h>


void START_MENU()
{
    printf(" _________________________________________\n");
    printf("|  -----Page Replacement Algorithm-----   |\n");
    printf("|      1. Chuoi tham chieu mac dinh       |\n");
    printf("|      2. Nhap chuoi tham chieu bang tay  |\n");
    printf("|_________________________________________|\n");
}

void FRAME_INSERT_MENU()
{
    printf(" _________________________________________\n");
    printf("|  -----Page Replacement Algorithm-----   |\n");
    printf("|          Nhap so khung trang            |\n");
    printf("|_________________________________________|\n");
}

void OPTIONS_MENU()
{
    printf(" _________________________________________\n");
    printf("|  -----Page Replacement Algorithm-----   |\n");
    printf("|          1. Giai thuat FIFO             |\n");
    printf("|          2. Giai thuat OPT (Optimal)    |\n");
    printf("|          3. Giai thuat LRU              |\n");
    printf("|_________________________________________|\n");
}

void defA_to_A(int defA[], int A[])
{
    int i;
    for (i = 0; i < 12; i++)
    {
        A[i] = defA[i];
    }
}

void A_Insert(int A[], int n)
{
    printf("Chuoi tham chieu: ");
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
}

void FIFO(int A[], int frames[], int NumOf_frames, int n)
{
    printf(" _____________________________________\n");
    printf("|---FIFO Page Replacement Algorithm---|\n");
    printf("|_____________________________________|\n");
    int i, j, k, available, count = 0;

	for(i = 0; i < NumOf_frames; i++)
        frames[i] = -1; // Giả sử ban đầu các frame trống
    j = 0;
    printf("\t|Chuoi|\t|Khung trang");
    for(k = 0; k < NumOf_frames - 1; k++)
		printf("\t");
	printf("|\n");
	for(i = 1; i <= n; i++)
    {
        printf("\t|  %d  |\t", A[i]);
        available = 0; // trang không có sẵn
        for(k = 0; k < NumOf_frames; k++)
            if(frames[k] == A[i]) // kiểm tra trang có sẵn
                available = 1; // trang có sẵn
        if (available == 0) // thay thế trang nếu không có sẵn
        {
            frames[j] = A[i];
            j = (j + 1) % NumOf_frames;
            count++;
            printf("|");
            for(k = 0; k < NumOf_frames; k++)
                printf("%d\t", frames[k]);
            printf("| *"); // Dấu hiệu nhận biết xảy ra lỗi trang
        }
        else
        {
            printf("|");
            for(k = 0; k < NumOf_frames; k++)
                printf("%d\t", frames[k]);
            printf("|");
        }
        printf("\n");
	}
    printf("So trang loi la: %d\n", count);
}

int main()
{
    int default_A[] = {2, 1, 5, 2, 2, 1, 1, 7, 0, 0, 7}; // default reference string
    int A[50];

    int NumOf_frames, frames[5];

    int n; // so phan tu chuoi tham chieu

    ////////////////////////////////////
    int choice;

    START_MENU();
    do
    {
        printf("Ban chon: ");
        scanf("%d", &choice);
    } while (choice != 1 && choice != 2);
    if (choice == 2)
    {
        printf("Nhap so phan tu cua chuoi tham chieu: ");
        scanf("%d", &n);
        A_Insert(A, n);
    }
    else
    {
        defA_to_A(default_A, A);
    }
    ////////////////////////////////
    FRAME_INSERT_MENU();
    printf("So khung trang: ");
    scanf("%d", &NumOf_frames);

    ////////////////////////////////
    OPTIONS_MENU();
    int choice2;
    do
    {
        printf("Ban chon: ");
        scanf("%d", &choice2);
    } while (choice2 < 1 && choice2 > 3);
    if (choice == 1) // nguoi dung chon Chuoi mac dinh
    {
        switch (choice2)
        {
        case 1: // nguoi dung chon giai thuat FIFO
            FIFO(A, frames, NumOf_frames, 11);
            break;
        case 2: // OPT
            OPT(A, frames, NumOf_frames, 11);
            break;
        case 3:
            // LRU
            LRU(A, frames, NumOf_frames, 11);
            break;
        }
    }
    else // nguoi dung chon Tu nhap chuoi
    {
        switch (choice2)
        {
        case 1: // nguoi dung chon giai thuat FIFO
            FIFO(A, frames, NumOf_frames, n);
            break;
        case 2:
            OPT(A, frames, NumOf_frames, n);
            break;
        case 3:
            LRU(A, frames, NumOf_frames, n);
            break;
        }
    }

    return 0;
}
