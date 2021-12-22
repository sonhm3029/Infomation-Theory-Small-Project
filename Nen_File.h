#include <iostream>
#include "Huffman.h"


using namespace std;


void nen_file(string input_path) {
  string van_ban;

  ifstream MyReadFile(input_path);
  if(!MyReadFile) {
    cout<<"Không tìm thấy file!";
    return;
  }
  getline(MyReadFile, van_ban);

  Huffman cay_ma;
  string output_path = tach_extension(input_path) + "_giainen" +".txt";

  Node* root = cay_ma.tao_cay_Huffman(van_ban, output_path);

  // Bắt đầu quá trình mã hóa và nén:
  unordered_map<char, string> huffmanCode;
  cay_ma.ma_hoa(root, "", huffmanCode);

  cout<<"Bảng mã huffman: \n"<<'\n';
  for(auto pair: huffmanCode) {
    cout<<pair.first<<" "<<pair.second<<'\n';
  }

  // Mã hóa văn bản với bảng mã đã lập
  string vb_da_ma_hoa = "";
  for(char ki_tu: van_ban) {
    vb_da_ma_hoa += huffmanCode[ki_tu];
  }

  // Ghi đoạn văn sau khi đã được mã hóa ra file
  ofstream OuputFile(output_path,fstream::app);

  OuputFile<<vb_da_ma_hoa;
  OuputFile.close();

}


void giai_nen(string input_path) {

  // Mở file cần giải nen và lấy ra key
  ifstream InputFile(input_path);
  if(!InputFile) {
    cout<<"Không tìm thấy file!";
    return;
  }
  char ki_tu;
  int freq;
  int num_key;

  InputFile>>num_key;

  unordered_map<char, int> bang_tan_so;
  priority_queue<Node*, vector<Node*>, comp> container;
  for(int i = 0; i<num_key; i++) {

    InputFile>>ki_tu;
    if(ki_tu == '_') {
      ki_tu = ' ';
    }
    InputFile>>freq;
   
    container.push(tao_Node(ki_tu, freq, nullptr, nullptr));
  }

  // Lấy ra đoạn văn đã được mã hóa để giải mã
  string doan_ma_hoa;
  getline(InputFile,doan_ma_hoa);

  // Loại bỏ dấu cách bị thừa ở đầu 
  // đoạn văn trong quá trình mã hóa
  string doan_ma_hoa_moi = "";
  for(int i =1; i<doan_ma_hoa.size(); i++) {
    doan_ma_hoa_moi += doan_ma_hoa[i];
  }
 
  Huffman cay_ma;
  Node * root = cay_ma.tao_cay_Huffman(container);

  // Thực hiện giải mã
  int index = -1;
	cout << "\n Nội dung file đã được giải nén: \n";
	while (index < (int)doan_ma_hoa.size() - 2) {
		cay_ma.giai_ma(root, index, doan_ma_hoa_moi);
	}
}