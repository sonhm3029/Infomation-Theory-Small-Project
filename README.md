# Information-Theory-Small-Project

Đây là project nhỏ về lý thuyết thông tin gồm các chức năng:

- Tính toán các thông số cơ bản của tin: Lượng tin riêng, Entropy
- Tính toán khả năng phân tách của bộ mã
- Dùng thuật toán Huffman để nén file text, encode, decode...

## I. Tính toán Lượng tin, Entropy

**Cách dùng:**

Trong file `main.cpp`

Sử dụng class `NguonTin` trong thư viện [NguonTin.h](./NguonTin.h) gồm các hàm:

Hàm | Chức năng
----|----------
`void khoi_tao_nguon_tin()`| Khởi tạo nguồn tin gồm các Xi với xác suất tương ứng
`void show_nguon_tin()`| In ra màn hình nguồn tin đã khởi tạo
`double luong_tin_tb()`| Tính toán lượng tin trung bình của nguồn tin
`double entropy()`| Tính toán entropy của nguồn tin

Chương trình mẫu:

```C++
    int main() {
        // Khởi tạo nguồn tin
        NguonTin example;
        example.khoi_tao_nguon_tin();

        // Show nguồn tin đã nhập
        example.show_nguon_tin();

        // Tính toán lượng tin trung bình:
        example.luong_tin_tb();

        // Tính toán entropy:
        example.entropy();
    }
```

Ngoài ra để tính lượng tin riêng ta có thể dùng hàm

```C++
double luong_tin_rieng(double p_xi) {
  return -(log2(p_xi));
}
```

Hàm `luong_tin_rieng()` được định nghĩa trong thư viện [helper.h](./helper.h)

## II. Tính toán khả năng phân tách của bộ mã

**Cách dùng:**

Trong file `main.cpp`

Sử dụng class `BoMa` trong thư viện [BoMa.h](./BoMa.h) gồm các hàm:

Hàm | Chức năng
----|----------
`void khoi_tao()` | Khởi tạo bộ mã
`void show_bo_ma()` | In ra màn hình bộ mã đã khởi tạo
`string giai_ma()` | Kiểm tra xem bộ mã đã cho có phân tách được không, nếu có thì độ chậm giải mã là bao nhiêu
`bool isPrefix()` | Kiểm tra xem bộ mã đã cho có tính prefix không

Chương trình mẫu:

```C++
    int main() {
        
        // Khởi tạo bộ mã
        BoMa example;
        example.khoi_tao();

        // In bộ mã đã tạo
        example.show_bo_ma();

        // Kiểm tra xem bộ mã
        // có phân tách được không
        cout<<example.giai_ma();
    }
```

## III. Nén và giải nén file .txt

**Cách dùng:**

Trong file `main.cpp`

Sử dụng các hàm trong thư viện [Nen_File.h](./Nen_File.h) để thực hiện các hàm:

Hàm | Chức năng
----|----------
`void nen_file(string input_path)` | Hàm dùng để đọc file text đã cho và xuất ra file được mã hóa
`void giai_nen(string input_path)` | Hàm dùng để đọc file text đã được nén bằng hàm `nen_file()` và In ra màn hình nội dung của file đã được giải nén

Các hàm của thư viện này được xây dựng dựa trên thuật toán `Huffman` được định nghĩa bằng class `Huffman` trong thư viện [Huffman.h](./Huffman.h). Class gồm các hàm:

Hàm | Chức năng
----|----------
`void ma_hoa(...)` | mã hóa các kí tự trong văn bản dựa trên cây nhị phân được xây dựng bằng thuật toán Huffman
`void giai_ma(...)` | giải mã các kí tự đã được mã hóa dựa trên cây nhị phân được xây dựng bằng thuật toán Huffman
`Node* tao_cay_Huffman(...)` | Xây dựng cây nhị phân để mã hóa hoặc giải mã dựa trên thuật toán Huffman.

**Chương trình mẫu:**

```C++
    int main() {
        nen_file("duong_dan_den_file_can_nen");
        giai_nen("duong_dan_den_file_can_giai_nen)
    }
```
