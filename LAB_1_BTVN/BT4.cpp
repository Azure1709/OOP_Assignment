/*
Bài tập 4: Arnold's Cat Map là một phép biến đổi ma trận đơn giản nhưng thú vị, có tác
dụng chuyển đổi dữ liệu từ một dạng có quy luật thành một dạng có vẻ hỗn độn. Được
định nghĩa trên một ma trận vuông kích thước m×mm \times mm×m, phép biến đổi
Arnold's Cat Map áp dụng công thức (x,y)=((2i+j)%m,(i+j)%m)(x, y) để xác định vị trí
mới của mỗi phần tử trong ma trận, với (i,j) là chỉ số hàng và cột của phần tử ban đầu.
Nhiệm vụ của bài toán là xác định hệ số chu kỳ k của phép biến đổi này, tức là số lần biến 
đổi cần thiết để ma trận trở về trạng thái ban đầu. Đầu vào của bài toán bao gồm
kích thước ma trận và ma trận dữ liệu, và đầu ra là hệ số chu kỳ k. Để giải bài toán, bạn
cần áp dụng phép biến đổi Arnold's Cat Map nhiều lần và đếm số lần biến đổi cho đến
khi ma trận trở về trạng thái ban đầu.
*/

#include <iostream>
#include <vector>
using namespace std;

// Class đại diện cho ma trận và phép biến đổi Arnold's Cat Map
class Matrix {
private:
    vector<vector<int>> data;
    int size;

public:
    // Constructor để khởi tạo ma trận với kích thước n x n
    Matrix(int n) : size(n) {
        data.resize(n, vector<int>(n, 0));
    }

    // Phương thức nhập ma trận từ đầu vào
    void input() {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                cin >> data[i][j];
            }
        }
    }

    // Phương thức thực hiện phép biến đổi Arnold's Cat Map
    void applyArnoldTransform(Matrix &tempMatrix) {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                tempMatrix.data[i][j] = data[(2 * i + j) % size][(i + j) % size];
            }
        }
        *this = tempMatrix;  // Cập nhật trạng thái ma trận hiện tại
    }

    // Phương thức so sánh hai ma trận xem chúng có giống nhau không
    bool isEqual(const Matrix &otherMatrix) const {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (data[i][j] != otherMatrix.data[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;  // Kích thước của ma trận

    // Khởi tạo các ma trận ban đầu, trung gian, và trạng thái hiện tại
    Matrix initialMatrix(n), currentMatrix(n), tempMatrix(n);
    
    initialMatrix.input();  // Nhập ma trận ban đầu
    currentMatrix = initialMatrix;  // Sao chép trạng thái ban đầu cho ma trận hiện tại

    int k = 0;  // Biến đếm số lần biến đổi
    do {
        ++k;
        currentMatrix.applyArnoldTransform(tempMatrix);
    } while (!currentMatrix.isEqual(initialMatrix));

    // Xuất ra chu kỳ k
    cout << k << endl;

    return 0;
}
