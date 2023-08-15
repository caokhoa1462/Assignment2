#include <stdio.h>
#include <stdlib.h>
#define checksonguyento(n) (checkprime(n))

int checkprime(int num) 
{
    if (num <= 1) 
    {
        return 0; // Nếu num nhỏ hơn hoặc bằng 1, num không phải số nguyên tố
    }
    if (num <= 3) 
    {
        return 1; // Nếu num nhỏ hơn hoặc bằng 3, thực chất là num bằng 2 hoặc bằng 3 thì num là số ngtố
    }
    if (num % 2 == 0 || num % 3 == 0) 
    {
        return 0; // Nếu num vừa chia hết cho 2 vừa chia hết cho 3 thì num không phải là số nguyên tố
    }

    for (int i = 5; i * i <= num; i += 6) 
    {
        if (num % i == 0 || num % (i + 2) == 0) 
        {
            return 0; // Không phải là số nguyên tố
            /* Ở đây sẽ sử dụng điều kiện để kiểm tra nhanh số nguyên tố
            Giải thích về điều kiện kiểm tra nhanh số nguyên tố: 
            - Những số nguyên tố lớn hơn hoặc bằng 3 và 5 (phải loại trừ 4 ra) đều có dạng là 6k ± 1 
              (bởi vì 6k, 6k ± 2 là những số chẵn, 6k + 3 lại là chia hết cho 3)

            - Điều kiện lặp i * i <= num đảm bảo rằng chúng ta chỉ cần xét các giá trị i 
              nhỏ hơn hoặc bằng căn bậc hai của num. Điều này là vì nếu num không phải là số nguyên tố, 
              thì nó phải có một ước số nằm trong khoảng từ 2 đến căn bậc hai của num.

            - Chúng ta kiểm tra xem num có chia hết cho i hoặc i + 2 không (điều này tương ứng với 6k - 1 
              và 6k + 1). Nếu có một trong hai trường hợp này xảy ra, điều đó có nghĩa là num không phải 
              là số nguyên tố, vì nó có ước số nằm trong khoảng từ 5 đến căn bậc hai của num.

            - Nếu một trong hai trường hợp kiểm tra chia hết (num % i == 0 hoặc num % (i + 2) == 0) xảy ra, 
              chúng ta trả về 0, ngụ ý rằng num không phải là số nguyên tố.

            - Nếu cả hai trường hợp kiểm tra chia hết đều không xảy ra, chúng ta tiếp tục với vòng lặp tiếp 
              theo để kiểm tra các giá trị i tiếp theo.
            */
        }
    }
    return 1; //  Số nguyên tố
}

int main(int argc, char *argv[]) 
{
    int a = atoi(argv[1]); // Đối số đầu tiên được truyền vào, chuyển đối số thành số nguyên bằng hàm atoi()
    int b = atoi(argv[2]); // Đối số thứ hai được truyền vào, chuyển đối số thành số nguyên bằng hàm atoi()
    while (a < 1 || b < a || b > 1000000000) {
        printf("Nhap lai a va b sao cho 1 <= a <= b <= 10^9.\n");

        if (argc == 3) {
            printf("Nhap a: ");
            scanf("%d", &a);

            printf("Nhap b: ");
            scanf("%d", &b);
        } else {
            return 1;
        }
    }
    printf("Prime numbers in the range from %d to %d:\n", a, b);
    for (int i = a; i <= b; i++) {
        if (checkprime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}
