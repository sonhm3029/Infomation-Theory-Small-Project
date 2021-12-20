#include <iostream>



using namespace std;

class NguonTin {
  vector <double> xac_suat;
  public:
    void khoi_tao_nguon_tin();
    void show_nguon_tin();
    double luong_tin_tb();
    double entropy();
};

void NguonTin::khoi_tao_nguon_tin() {
  cout<<"Nhập vào xác suất các tin, nhấn q để dừng nhập:"<<endl;
  string key;
  do {
    string dau_vao;
    cin>>dau_vao;
    key = dau_vao;
    if(dau_vao == "q") {
      break;
    }
    double p_xi = calc_expression(dau_vao);
    xac_suat.push_back(p_xi);
  }while (key != "q");
}


void NguonTin::show_nguon_tin() {
  cout<<"Nguồn tin từ x1 -> x"<<xac_suat.size()<<" có xác suất lần lượt là:"<<endl;
  in_mang(xac_suat);
}

double NguonTin::luong_tin_tb() {
  double result = 0;
  for(int i = 0; i<xac_suat.size(); i++) {
    result += xac_suat[i]*luong_tin_rieng(xac_suat[i]);
  }
  return result;
}

double NguonTin::entropy() {
  return NguonTin::luong_tin_tb();
}



