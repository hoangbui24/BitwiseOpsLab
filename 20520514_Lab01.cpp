#include <iostream>
using namespace std;

// Thực hành môn Lập Trình Hệ Thống - Lab01
//Bùi Đức Hoàng - 20520514

// Hàm hỗ trợ biểu diễn một số dưới dạng nhị phân đầy đủ 32 bit
void PrintBits(unsigned int x)
{
    int i;
    for (i = 8 * sizeof(x) - 1; i >= 0; i--)
    {
        (x & (1 << i)) ? putchar('1') : putchar('0');
    }
    printf("\n");
}

// Hàm biểu diễn một số dưới dạng nhị phân chỉ 8 ký tự (8 bit thấp)
void PrintBitsOfByte(unsigned int x)
{
    int i;
    for (i = 7; i >= 0; i--)
    {
        (x & (1 << i)) ? putchar('1') : putchar('0');
    }
    printf("/n");
}

/*
Câu 1.1
Thực hiện & bit 2 số nguyên: x & y
Yêu cầu: không dùng toán tử &, chỉ dùng toán
tử | và ~
• Input: 2 số nguyên x, y tùy ý
• PT: bitAnd(3, -9) == (3 & -9)
*/
int bitAnd(int x, int y)
{
    /*
    Vì yêu cầu không được xài toán tử & để
    tính hàm And, nên ta có thể xài định lý
    De Morgan: ~(x & y) = ~x | ~y
    */
    cout << "Demo ở dạng nhị phân\n";
    cout << "Số " << x << " ở dạng nhị phân: ";
    PrintBits(x);
    cout << "Số " << y << " ở dạng nhị phân: ";
    PrintBits(y);
    cout << "Số " << x << " khi đảo bit: ";
    PrintBits(~x);
    cout << "Số " << y << " khi đảo bit: ";
    PrintBits(~y);
    cout << "~" << x << " OR "
         << "~" << y << ": ";
    PrintBits(~x | ~y); // = ~(x & y)
    cout << x << " AND " << y << ": ";
    PrintBits(~(~x | ~y)); // = ~(~(x & y)) = x & y
    int result = ~(~x | ~y);
    return result;
}

/*
Câu 1.2
Tính giá trị của –x không dùng dấu –
• Input: Số nguyên x
• PT: negative (0) == 0 && negative (9) == -9
&& negative (-5) == 5
*/
int negative(int x)
{
    /*
    Đề bài yêu cầu output ra số đối của số nhập vào, không được
    xài dấu -, nên ta sử dụng bù 2.
    Bù 2 có dạng là đầu tiên đảo tất cả các bit, sau đó cộng cho 1
    */

    cout << "Demo ở dạng nhị phân\n";
    cout << "Số " << x << " ở dạng nhị phân: ";
    PrintBits(x);
    cout << "Số " << x << " khi đảo bit: ";
    PrintBits(~x);
    cout << "Cộng 1 và thành dạng bù 2: ";
    PrintBits(~x + 1);
    int result = ~x + 1;
    cout << "Kết quả ở dạng thập phân: ";
    cout << result;
    return result;
}

/*
Câu 1.3
Bật bit thứ n trong biểu diễn nhị phân của x (các
bit được đánh thứ tự từ 0 đến 31 từ phải sang
trái).
• Input:
    • Số x nguyên
    • Số n (0 ≤ n ≤ 31)
• PT: setBit(8,2) == 6 && setBit(5,0) == 5
&& setBit(32,3) == 40
*/
int setBit(int x, int n)
{
    /*
    Ở đây ta sẽ tạo một cái mask bằng 1, sau đó ta sẽ xài toán tử
    shift left để dịch số 1 sang trái n bit.
    Tiếp đó, ta xài toán tử OR, và x | mask vì A|B = 1 khi A = 1 hoặc B = 1
    */
    cout << "Demo ở dạng nhị phân\n";
    cout << "Số " << x << " ở dạng nhị phân: ";
    PrintBits(x);
    int mask = 1;
    cout << "Mask khi chưa dịch bit: ";
    PrintBits(mask);
    cout << "Mask khi đã dịch sang trái " << n << " bit: ";
    mask = mask << n;
    PrintBits(mask);
    int result = x | mask;
    cout << "Kết quả của " << x << " sau khi đã bật bit thứ " << n << " lên: ";
    PrintBits(x | mask);
    cout << "Kết quả sau khi đã bật bit thứ " << x << " ở dạng thập phân: ";
    cout << result;
    return result;
}

/*
Câu 1.4
Tính kết quả x/2n
• Input:
    • Số x nguyên dương
    • Số n âm (-31 ≤ n ≤ -1)
• PT: divpw2(10, -1) == 20 && divpw2(15, -2) == 60 && divpw2(2, -4) == 32
*/
int divpw2(int x, int n)
{
    /*
    Ta có:
          + 2^n (n < 0) = 1/2^n (n > 0) (1)
          + x/(y/z) = x * (z/y)         (2)
    Từ (1)(2), suy ra:
          + x/(2^n) (n < 0) = x * 2^n (n > 0)
    Từ suy luận trên, ta có phép shift left n bit sẽ nhân
    số hiện có với lũy thừa 2^n.
    Nên đầu tiên, ta phải chuyển số n đang âm về dương, sau đó tiến
    hành shift left.
    */

    cout << "Demo ở dạng nhị phân\n";
    cout << "Số " << x << " ở dạng nhị phân: ";
    PrintBits(x);
    n = ~n + 1;
    cout << "Số bit dịch trái: " << n << "\n";
    int result = x << n;
    cout << "Kết quả ở dạng nhị phân là: ";
    PrintBits(result);
    cout << "Kết quả của x/(2^n) là: " << result;
    return result;
}

/*
Câu 1.5
Tính kết quả x % 2n
(phép chia lấy dư)
• Input:
    • Số x nguyên dương
    • Số n (0 ≤n≤31)
• PT: modulus2(2,1) == 0 &&
modulus2(30,2) == 2 && modulus2(63,6) = 63
*/
int modulus2(int x, int n)
{
    /*
    Số bị chia = x
    Số chia = 2^n
    Theo các phép tính toán trên MIPS, ta có số dư = số bị chia &     (số chia -1)
    Gọi a = 1, suy ra a shift left n bit = a * 2^n = số chia
    Do trong câu đố không cho sử dụng phép trừ, nên ta sẽ thay bằng   cách cộng số chia cho bù 2 của số 1 => a - 1 = a + (~1+1)
    Sau đó, ta AND số bị chia với (số chia trừ 1)
    */
    cout << "Demo ở dạng nhị phân\n";
    int a = 1;
    cout << "Số a ban đầu: ";
    PrintBits(a);
    a = a << n;
    cout << "Số " << x << " ở dạng nhị phân: ";
    PrintBits(x);
    cout << "Số a khi đã dịch trái " << n << " bit: ";
    PrintBits(a);
    cout << "Số a sau khi cộng cho bù 2 của 1: ";
    PrintBits(a + (~1 + 1));
    int result = x & (a + (~1 + 1));
    cout << "Kết quả của phép tính là: " << result;
    return result;
}

/*
Câu 2.1
Kiểm tra số x có chẵn hay không. Trả về 1 nếu
x chẵn, ngược lại trả về 0.
• Input: Số nguyên x
• PT: isEven(4) && !isEven(13) && isEven(0)
*/
int isEven(int x)
{
    /*
    Để biết một số là chẵn hay lẻ, ta dựa vào bit đầu tiên,
    nếu bit thứ 0 = 1 thì là số lẻ
        bit thứ 0 = 0 thì là số chẵn
    Nên ta sẽ sử dụng phép AND với 1 để kiểm tra
    Sau đó, ta xài phép XOR với 0 để trả kết quả theo yêu cầu đề bài
    */
    int a = x & 1;
    int result = !(a | 0);
    cout << "Số x có phải số chẵn ?: " << result;
    return result;
}

/*
Câu 2.2
Kiểm tra 1 số nguyên x có chia hết cho 16
hay không? Trả về 1 nếu chia hết ngược lại
trả về 0.
• Input: Số nguyên x không âm
• PT: is16x(16) && !is16x(3) && is16x(0)
*/
int is16x(int x)
{
    /*
    Số bé nhất chia hết cho 16 là 10000 hay 16.
    Do đó, ta sẽ kiểm tra 4 bit cuối cùng, nếu là 0000 thì số đó chia hết cho 16
    Đầu tiên, ta sẽ AND với 1111 để lấy ra 4 bit.
    Sau đó, ta OR với 0 để kiểm tra kết quả.
    */
    int a = x & 0b1111;
    int result = !(a | 0);
    cout << "Số x có chia hết cho 16 ?: " << result;
    return result;
}

/*
Câu 2.3
Trả về 1 nếu x dương (x > 0)
• Input: Số nguyên x
• PT: isPositive(10) && !isPositive(-5) && !isPositive(0)
*/
int isPositive(int x)
{
    /*
    Để kiểm tra một số âm hay dương thì ta kiểm tra bit có trọng số cao nhất của số đó,
    nếu bằng 1 thì số âm, nếu bằng 0 thì số dương/
    Do số 0 không âm cũng không dương, nên ta cũng phải kiểm tra x có khác 0 không.
    Đầu tiên, ta sẽ dịch số x sang phải 31 bit, để lôi bit trọng số cao nhất về
    Sau đó, ta xài ! để kiểm tra.
    Cuối cùng, ta xài XOR để kiểm x có dương và khác 0 hay
    */
    int a = x >> 31;
    int result = (!a ^ !x);
    cout << "Số x có dương không ?: " << result;
    return result;
}

/*
Câu 2.4
Trả về 1 nếu x ≥ 2^n
• Input:
  • Số x nguyên dương
  • Số n (0 ≤n≤30)
• PT: isGE2n(15,1) && isGE2n(8,3) && !isGE2n(12,4)
*/
int isGE2n(int x, int n)
{
    /*
    Đầu tiên, ta sẽ tính 2^n bằng cách gán một biến = 1, sau đó, ta
    dịch trái n bit, ta thu được 2^n
    Tiếp đó, ta sẽ cho số x cộng với bù 2 của số 2^n (tạm gọi là a)
    Vì nếu số a lớn hơn số x, thì ta sẽ thu được kết quả là âm, còn số a bé hơn hoặc bằng số x, kết quả thu được sẽ là dương hoặc     bằng 0. Nên ở đây ta sử dụng phép shift right 31 bit để lấy bit   có trọng số cao nhất là bit dấu.
    Và kết quả thu được sẽ là kiểm tra bằng !
    */
    int a = 1;
    a = a << n;
    int s = x + (~a + 1);
    int b = s >> 31;
    int result = (!b);
    cout << "Số x có lớn hơn hoặc bằng 2^n ?: " << result;
    return result;
}

int main()
{
    cout << "Bài báo cáo Lập trình hệ thống - Bitwise\n";
    cout << "Họ và tên: Bùi Đức Hoàng\n";
    cout << "MSSV: 20520514\n";
    cout << "\n";
    cout << "------------------------------------------\n";
    cout << "\n";
    cout << "Câu 1.1\n";
    bitAnd(3, -9);
    cout << "\n";
    cout << "------------------------------------------\n";
    cout << "\n";
    cout << "Câu 1.2\n";
    negative(-5);
    cout << "\n";
    cout << "\n";
    cout << "------------------------------------------\n";
    cout << "\n";
    cout << "Câu 1.3\n";
    setBit(8, 2);
    cout << "\n";
    cout << "\n";
    cout << "------------------------------------------\n";
    cout << "\n";
    cout << "Câu 1.4\n";
    divpw2(10, -1);
    cout << "\n";
    cout << "\n";
    cout << "------------------------------------------\n";
    cout << "\n";
    cout << "Câu 1.5\n";
    modulus2(30, 2);
    cout << "\n";
    cout << "\n";
    cout << "------------------------------------------\n";
    cout << "\n";
    cout << "Câu 2.1\n";
    isEven(24);
    cout << "\n";
    cout << "\n";
    cout << "------------------------------------------\n";
    cout << "\n";
    cout << "Câu 2.2\n";
    is16x(16);
    cout << "\n";
    cout << "\n";
    cout << "------------------------------------------\n";
    cout << "\n";
    cout << "Câu 2.3\n";
    isPositive(12);
    cout << "\n";
    cout << "\n";
    cout << "------------------------------------------\n";
    cout << "\n";
    cout << "Câu 2.4\n";
    isGE2n(12, 4);
    cout << "\n";
    cout << "\n";
    cout << "------------------------------------------\n";
    cout << "\n";
    cout << "\t\t\t\tHết";
}

#include <iostream>
using namespace std;

// Thực hành môn Lập Trình Hệ Thống - Lab01

// Hàm hỗ trợ biểu diễn một số dưới dạng nhị phân đầy đủ 32 bit
void PrintBits(unsigned int x)
{
    int i;
    for (i = 8 * sizeof(x) - 1; i >= 0; i--)
    {
        (x & (1 << i)) ? putchar('1') : putchar('0');
    }
    printf("\n");
}

// Hàm biểu diễn một số dưới dạng nhị phân chỉ 8 ký tự (8 bit thấp)
void PrintBitsOfByte(unsigned int x)
{
    int i;
    for (i = 7; i >= 0; i--)
    {
        (x & (1 << i)) ? putchar('1') : putchar('0');
    }
    printf("/n");
}

/*
Câu 1.1
Thực hiện & bit 2 số nguyên: x & y
Yêu cầu: không dùng toán tử &, chỉ dùng toán
tử | và ~
• Input: 2 số nguyên x, y tùy ý
• PT: bitAnd(3, -9) == (3 & -9)
*/
int bitAnd(int x, int y)
{
    /*
    Vì yêu cầu không được xài toán tử & để
    tính hàm And, nên ta có thể xài định lý
    De Morgan: ~(x & y) = ~x | ~y
    */
    cout << "Demo ở dạng nhị phân\n";
    cout << "Số " << x << " ở dạng nhị phân: ";
    PrintBits(x);
    cout << "Số " << y << " ở dạng nhị phân: ";
    PrintBits(y);
    cout << "Số " << x << " khi đảo bit: ";
    PrintBits(~x);
    cout << "Số " << y << " khi đảo bit: ";
    PrintBits(~y);
    cout << "~" << x << " OR "
         << "~" << y << ": ";
    PrintBits(~x | ~y); // = ~(x & y)
    cout << x << " AND " << y << ": ";
    PrintBits(~(~x | ~y)); // = ~(~(x & y)) = x & y
    int result = ~(~x | ~y);
    return result;
}

/*
Câu 1.2
Tính giá trị của –x không dùng dấu –
• Input: Số nguyên x
• PT: negative (0) == 0 && negative (9) == -9
&& negative (-5) == 5
*/
int negative(int x)
{
    /*
    Đề bài yêu cầu output ra số đối của số nhập vào, không được
    xài dấu -, nên ta sử dụng bù 2.
    Bù 2 có dạng là đầu tiên đảo tất cả các bit, sau đó cộng cho 1
    */

    cout << "Demo ở dạng nhị phân\n";
    cout << "Số " << x << " ở dạng nhị phân: ";
    PrintBits(x);
    cout << "Số " << x << " khi đảo bit: ";
    PrintBits(~x);
    cout << "Cộng 1 và thành dạng bù 2: ";
    PrintBits(~x + 1);
    int result = ~x + 1;
    cout << "Kết quả ở dạng thập phân: ";
    cout << result;
    return result;
}

/*
Câu 1.3
Bật bit thứ n trong biểu diễn nhị phân của x (các
bit được đánh thứ tự từ 0 đến 31 từ phải sang
trái).
• Input:
    • Số x nguyên
    • Số n (0 ≤ n ≤ 31)
• PT: setBit(8,2) == 6 && setBit(5,0) == 5
&& setBit(32,3) == 40
*/
int setBit(int x, int n)
{
    /*
    Ở đây ta sẽ tạo một cái mask bằng 1, sau đó ta sẽ xài toán tử
    shift left để dịch số 1 sang trái n bit.
    Tiếp đó, ta xài toán tử OR, và x | mask vì A|B = 1 khi A = 1 hoặc B = 1
    */
    cout << "Demo ở dạng nhị phân\n";
    cout << "Số " << x << " ở dạng nhị phân: ";
    PrintBits(x);
    int mask = 1;
    cout << "Mask khi chưa dịch bit: ";
    PrintBits(mask);
    cout << "Mask khi đã dịch sang trái " << n << " bit: ";
    mask = mask << n;
    PrintBits(mask);
    int result = x | mask;
    cout << "Kết quả của " << x << " sau khi đã bật bit thứ " << n << " lên: ";
    PrintBits(x | mask);
    cout << "Kết quả sau khi đã bật bit thứ " << x << " ở dạng thập phân: ";
    cout << result;
    return result;
}

/*
Câu 1.4
Tính kết quả x/2n
• Input:
    • Số x nguyên dương
    • Số n âm (-31 ≤ n ≤ -1)
• PT: divpw2(10, -1) == 20 && divpw2(15, -2) == 60 && divpw2(2, -4) == 32
*/
int divpw2(int x, int n)
{
    /*
    Ta có:
          + 2^n (n < 0) = 1/2^n (n > 0) (1)
          + x/(y/z) = x * (z/y)         (2)
    Từ (1)(2), suy ra:
          + x/(2^n) (n < 0) = x * 2^n (n > 0)
    Từ suy luận trên, ta có phép shift left n bit sẽ nhân
    số hiện có với lũy thừa 2^n.
    Nên đầu tiên, ta phải chuyển số n đang âm về dương, sau đó tiến
    hành shift left.
    */

    cout << "Demo ở dạng nhị phân\n";
    cout << "Số " << x << " ở dạng nhị phân: ";
    PrintBits(x);
    n = ~n + 1;
    cout << "Số bit dịch trái: " << n << "\n";
    int result = x << n;
    cout << "Kết quả ở dạng nhị phân là: ";
    PrintBits(result);
    cout << "Kết quả của x/(2^n) là: " << result;
    return result;
}

/*
Câu 1.5
Tính kết quả x % 2n
(phép chia lấy dư)
• Input:
    • Số x nguyên dương
    • Số n (0 ≤n≤31)
• PT: modulus2(2,1) == 0 &&
modulus2(30,2) == 2 && modulus2(63,6) = 63
*/
int modulus2(int x, int n)
{
    /*
    Số bị chia = x
    Số chia = 2^n
    Theo các phép tính toán trên MIPS, ta có số dư = số bị chia &     (số chia -1)
    Gọi a = 1, suy ra a shift left n bit = a * 2^n = số chia
    Do trong câu đố không cho sử dụng phép trừ, nên ta sẽ thay bằng   cách cộng số chia cho bù 2 của số 1 => a - 1 = a + (~1+1)
    Sau đó, ta AND số bị chia với (số chia trừ 1)
    */
    cout << "Demo ở dạng nhị phân\n";
    int a = 1;
    cout << "Số a ban đầu: ";
    PrintBits(a);
    a = a << n;
    cout << "Số " << x << " ở dạng nhị phân: ";
    PrintBits(x);
    cout << "Số a khi đã dịch trái " << n << " bit: ";
    PrintBits(a);
    cout << "Số a sau khi cộng cho bù 2 của 1: ";
    PrintBits(a + (~1 + 1));
    int result = x & (a + (~1 + 1));
    cout << "Kết quả của phép tính là: " << result;
    return result;
}

/*
Câu 2.1
Kiểm tra số x có chẵn hay không. Trả về 1 nếu
x chẵn, ngược lại trả về 0.
• Input: Số nguyên x
• PT: isEven(4) && !isEven(13) && isEven(0)
*/
int isEven(int x)
{
    /*
    Để biết một số là chẵn hay lẻ, ta dựa vào bit đầu tiên,
    nếu bit thứ 0 = 1 thì là số lẻ
        bit thứ 0 = 0 thì là số chẵn
    Nên ta sẽ sử dụng phép AND với 1 để kiểm tra
    Sau đó, ta xài phép XOR với 0 để trả kết quả theo yêu cầu đề bài
    */
    int a = x & 1;
    int result = !(a | 0);
    cout << "Số x có phải số chẵn ?: " << result;
    return result;
}

/*
Câu 2.2
Kiểm tra 1 số nguyên x có chia hết cho 16
hay không? Trả về 1 nếu chia hết ngược lại
trả về 0.
• Input: Số nguyên x không âm
• PT: is16x(16) && !is16x(3) && is16x(0)
*/
int is16x(int x)
{
    /*
    Số bé nhất chia hết cho 16 là 10000 hay 16.
    Do đó, ta sẽ kiểm tra 4 bit cuối cùng, nếu là 0000 thì số đó chia hết cho 16
    Đầu tiên, ta sẽ AND với 1111 để lấy ra 4 bit.
    Sau đó, ta OR với 0 để kiểm tra kết quả.
    */
    int a = x & 0b1111;
    int result = !(a | 0);
    cout << "Số x có chia hết cho 16 ?: " << result;
    return result;
}

/*
Câu 2.3
Trả về 1 nếu x dương (x > 0)
• Input: Số nguyên x
• PT: isPositive(10) && !isPositive(-5) && !isPositive(0)
*/
int isPositive(int x)
{
    /*
    Để kiểm tra một số âm hay dương thì ta kiểm tra bit có trọng số cao nhất của số đó,
    nếu bằng 1 thì số âm, nếu bằng 0 thì số dương/
    Do số 0 không âm cũng không dương, nên ta cũng phải kiểm tra x có khác 0 không.
    Đầu tiên, ta sẽ dịch số x sang phải 31 bit, để lôi bit trọng số cao nhất về
    Sau đó, ta xài ! để kiểm tra.
    Cuối cùng, ta xài XOR để kiểm x có dương và khác 0 hay
    */
    int a = x >> 31;
    int result = (!a ^ !x);
    cout << "Số x có dương không ?: " << result;
    return result;
}

/*
Câu 2.4
Trả về 1 nếu x ≥ 2^n
• Input:
  • Số x nguyên dương
  • Số n (0 ≤n≤30)
• PT: isGE2n(15,1) && isGE2n(8,3) && !isGE2n(12,4)
*/
int isGE2n(int x, int n)
{
    /*
    Đầu tiên, ta sẽ tính 2^n bằng cách gán một biến = 1, sau đó, ta
    dịch trái n bit, ta thu được 2^n
    Tiếp đó, ta sẽ cho số x cộng với bù 2 của số 2^n (tạm gọi là a)
    Vì nếu số a lớn hơn số x, thì ta sẽ thu được kết quả là âm, còn số a bé hơn hoặc bằng số x, kết quả thu được sẽ là dương hoặc     bằng 0. Nên ở đây ta sử dụng phép shift right 31 bit để lấy bit   có trọng số cao nhất là bit dấu.
    Và kết quả thu được sẽ là kiểm tra bằng !
    */
    int a = 1;
    a = a << n;
    int s = x + (~a + 1);
    int b = s >> 31;
    int result = (!b);
    cout << "Số x có lớn hơn hoặc bằng 2^n ?: " << result;
    return result;
}

int main()
{
    cout << "Bài báo cáo Lập trình hệ thống - Bitwise\n";
    cout << "Họ và tên: Bùi Đức Hoàng\n";
    cout << "MSSV: 20520514\n";
    cout << "\n";
    cout << "------------------------------------------\n";
    cout << "\n";
    cout << "Câu 1.1\n";
    bitAnd(3, -9);
    cout << "\n";
    cout << "------------------------------------------\n";
    cout << "\n";
    cout << "Câu 1.2\n";
    negative(-5);
    cout << "\n";
    cout << "\n";
    cout << "------------------------------------------\n";
    cout << "\n";
    cout << "Câu 1.3\n";
    setBit(8, 2);
    cout << "\n";
    cout << "\n";
    cout << "------------------------------------------\n";
    cout << "\n";
    cout << "Câu 1.4\n";
    divpw2(10, -1);
    cout << "\n";
    cout << "\n";
    cout << "------------------------------------------\n";
    cout << "\n";
    cout << "Câu 1.5\n";
    modulus2(30, 2);
    cout << "\n";
    cout << "\n";
    cout << "------------------------------------------\n";
    cout << "\n";
    cout << "Câu 2.1\n";
    isEven(24);
    cout << "\n";
    cout << "\n";
    cout << "------------------------------------------\n";
    cout << "\n";
    cout << "Câu 2.2\n";
    is16x(16);
    cout << "\n";
    cout << "\n";
    cout << "------------------------------------------\n";
    cout << "\n";
    cout << "Câu 2.3\n";
    isPositive(12);
    cout << "\n";
    cout << "\n";
    cout << "------------------------------------------\n";
    cout << "\n";
    cout << "Câu 2.4\n";
    isGE2n(12, 4);
    cout << "\n";
    cout << "\n";
    cout << "------------------------------------------\n";
    cout << "\n";
    cout << "\t\t\t\tHết";
}