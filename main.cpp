#include <bits/stdc++.h>
#define task "XEPHAU."
#define inf 1e9 + 7

using namespace std;

const int maxn = 9;
int n, cnt, res[maxn], column[maxn], main_diagonal[maxn], secondary_diagonal[maxn];

// In nghiệm theo dạng: index. x1 x2 ... xn.
void printf_result()
{
    cout << ++cnt << ". ";

    for (int i = 1; i <= n; ++i)
        cout << res[i] << ' ';

    cout << endl;
}

// Kiểm tra xem đặt quân hậu ở hàng thứ i vào cột thứ j có được hay không?
bool check(int i, int j)
{
    if (column[j] == 1 || main_diagonal[i - j] == 1 || secondary_diagonal[i + j] == 1)
        return false;

    return true;
}

// Tìm vị trí cột để đặt quân hậu trên hàng thứ i.
void backtrack(int i, int n)
{
    // Thử từng cột.
    for (int j = 1; j <= n; ++j)
        if (check(i, j))
        {
            res[i] = j;
            column[j] = 1;
            main_diagonal[i - j] = 1;
            secondary_diagonal[i + j] = 1;

            // Nếu đã tạo được xong một vector nghiệm thì in nó ra.
            if (i == n)
                printf_result();
            // Ngược lại thì tiếp tục tạo thành phần thứ i + 1.
            else
                backtrack(i + 1, n);

            // Xóa quân hậu ở cột j hàng i đi, khởi tạo lại cột và các đường chéo.
            column[j] = 0;
            main_diagonal[i - j] = 0;
            secondary_diagonal[i + j] = 0;
        }
}

int main()
{
    int n;
    cin >> n;

    backtrack(1, n);

    return 0;
}
