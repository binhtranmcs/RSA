## BTL MMVANM

Trong bài tập lớn này, bạn cần phải hiện thực hệ mã RSA trên Java/C/C++. Bạn không được dùng các hiện thực RSA đã có từ web hay trong Java. Những gì bạn có thể dùng là:

- Java có lớp BigInteger được xây dựng sẳn.

- C++ có thư viện NTL(Library for doing Number Theory) or GMP (the GNU Multiple Precision Arithmetic Library). 

- Bạn có thể dùng các hiện thực big-integer để quản lý dữ liệu của bạn và thực hiện phép toán mod nhưng không được dùng các phương thức đã hiện thực (gcd, power, tìm số nguyên tố, ..). Như vậy bạn phải tự hiện thực các phương thức này. 

- Bạn có thể dùng hàm an toàn đang tồn tại để tạo ra các số ngẫu nhiên lớn. Ví dụ Java cung cấp các công cụ để tạo số ngẫu nhiên trong java.util.random hay java.security.SecureRandom. Tương tự C++ có rand() và srand() để tạo số ngẫu nhiên. 

Trong hiện thực RSA của bạn, giả sử các số nguyên tố lớn ít nhất phải 500 bits(nhưng có thể lớn hơn) và bạn phải viết các hàm sau:

- Tìm số nguyên tố lớn khi cho số lượng bit của số nguyên tố lớn cần tìm.

- Tính ước số lớn nhất khi cho hai số nguyên lớn.

- Tính toán khóa giải mã d khi cho khoá mã hóa e và hai số nguyên tố lớn.

- Tạo bộ khóa ngẫu nhiên khi cho 2 số nguyên tố lớn.

- Mã hóa khi cho thông điệp và khóa mã hóa e và n.

- Giải mã khi cho thông điệp mã hóa và khóa giải mã d và n.