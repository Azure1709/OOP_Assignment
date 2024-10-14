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

