#include <iostream>

using namespace std;

struct Node {
  char ki_tu;
  int tan_so;
  Node *left, *right;
};

Node* tao_Node(char ki_tu, int tan_so, Node *left, Node *right) {

  Node* new_node= new Node();

  new_node->ki_tu = ki_tu;
  new_node->tan_so = tan_so;
  new_node->left = left;
  new_node->right = right;

  return new_node;
}


// Định nghĩa compare function dùng trong priority queue
struct comp {
  bool operator()(Node* left, Node* right){
    // Định nghĩa toán tử so sánh để set cho priority queue có phần tử với tần số thấp nhất sẽ ở độ ưu tiên cao nhất.
    return left->tan_so > right->tan_so;
  }
};

class Huffman {
  unordered_map<char, int> bang_tan_so;
  public:
    void ma_hoa(Node* root, string danh_so, unordered_map<char, string> &huffManCode);
    void giai_ma(Node* root, int &index, string encoded_str);
    Node* tao_cay_Huffman(string van_ban, string output_path);
    Node* tao_cay_Huffman(priority_queue<Node*, vector<Node*>, comp> container);
    double ty_so_nen(unordered_map<char, string> huffmanCode);
};


void Huffman::ma_hoa(Node* root, string ma, unordered_map<char, string> &huffManCode) {
  
  // Kiểm tra nếu như không còn nút để duyệt
  // thì dừng lại quá trình duyệt và mã hóa
  if(root == nullptr) return;

  // Nếu chạm đến nút lá
  // Thì gán mã hóa cho kí tự trong danh sách mã huffManCode
  if(!root->left && !root->right) {
    huffManCode[root->ki_tu] = ma;
  }

  // Dùng hồi quy để duyệt cây mã huffMan
  ma_hoa(root->left, ma + "0", huffManCode);
  ma_hoa(root->right, ma + "1", huffManCode);

}

void Huffman::giai_ma(Node* root, int &index, string encoded_str) {

  if(root == nullptr) {
    return ;
  }

  // Nếu chạm tới nút kí tự
  if (!root->left && !root->right)
	{
		cout << root->ki_tu;
		return;
	}

	index++;

	if (encoded_str[index] =='0')
		giai_ma(root->left, index, encoded_str);
	else
		giai_ma(root->right, index, encoded_str);
}

Node* Huffman::tao_cay_Huffman(string van_ban, string output_path) {

  // Bảng đếm tần số xuất hiện của các kí tự
  // unordered_map<char, int> bang_tan_so;
  for(char ch: van_ban) {
    bang_tan_so[ch]++;
  }
  // Ghi lại key để giải mã file được nén
  ofstream OutputFile(output_path);
  OutputFile<<bang_tan_so.size()<<endl;
  for (auto pair: bang_tan_so) {
    char ki_tu;
    ki_tu = pair.first;
    if(ki_tu == ' ') {
      ki_tu = '_';
    }
    OutputFile<<ki_tu<<" "<<pair.second<<" ";
  }
  // Tạo container để lưu trữ tần số các kí tự
  // Sao cho các kí tự có tần số nhỏ nhất
  // Luôn luôn được ưu tiên lấy ra đầu
  priority_queue<Node*, vector<Node*>, comp> container;

  // Tạo các nút lá chứa kí tự cần mã hóa
  // Và thêm chúng vào container
  for(auto pair: bang_tan_so) {
    container.push(tao_Node(pair.first, pair.second, nullptr, nullptr));
  }


  // Tiến hành xây dựng cây mã
  while(container.size() !=1) {
    
    // lấy ra 2 nút có tần số nhỏ nhất
    // sau đó khởi tạo nút mới
    // Có tông tần số = tần số 2 nút lấy ra
    // Lưu lại vào container.
    Node *left = container.top(); container.pop();
    Node *right = container.top(); container.pop();

    int sum = left->tan_so + right->tan_so;
    container.push(tao_Node('\0', sum, left, right));
  }

  

  // Lấy ra root của cây mã
  Node* root = container.top();

  return root;
}


Node* Huffman::tao_cay_Huffman(priority_queue<Node*, vector<Node*>, comp> container) {

  // Tạo các nút lá chứa kí tự cần mã hóa
  // Và thêm chúng vào container

  // Tiến hành xây dựng cây mã
  while(container.size() !=1) {
    
    // lấy ra 2 nút có tần số nhỏ nhất
    // sau đó khởi tạo nút mới
    // Có tông tần số = tần số 2 nút lấy ra
    // Lưu lại vào container.
    Node *left = container.top(); container.pop();
    Node *right = container.top(); container.pop();

    int sum = left->tan_so + right->tan_so;
    container.push(tao_Node('\0', sum, left, right));
  }

  // Lấy ra root của cây mã
  Node* root = container.top();

  return root;
}

double Huffman::ty_so_nen(unordered_map<char, string> huffmanCode) {
  int tong_ki_tu = 0;
  for(auto pair:bang_tan_so) {
    tong_ki_tu += pair.second;
  }
  
  // Tính toán entropy
  double Hx = 0;
  for(auto pair:bang_tan_so) {
    double p_xi = double(pair.second)/tong_ki_tu;
    Hx += p_xi*(luong_tin_rieng(p_xi));
  }

  // Tính toán độ dài trung bình từ mã
  double l_tb = 0;
  for(auto pair: huffmanCode) {
    double p_xi = double(bang_tan_so[pair.first])/tong_ki_tu;
    l_tb += p_xi*((pair.second).size());
  }

  
  return Hx/l_tb;
}



