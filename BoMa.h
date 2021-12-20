#include <iostream>


using namespace std;


class BoMa {
  vector<string> danh_sach_ma;

  public:
    void khoi_tao();
    void show_bo_ma();
    string giai_ma();
    bool isPrefix();
};


void BoMa::khoi_tao() {
  cout<<"Nhập vào danh sách các mã trong bộ mã, nhập q để dừng :"<<endl;
  do {
    string ma;
    cin>>ma;
    if(ma == "q") {
      break;
    }
    danh_sach_ma.push_back(ma);
  }while(true);
}

void BoMa::show_bo_ma() {
  cout<<"Bộ mã gồm các mã là:"<<endl;
  in_mang(danh_sach_ma);
  cout<<endl;
}

bool BoMa::isPrefix() {
  for(int i = 0; i<danh_sach_ma.size(); i++) {
    for(int j = 0; j<danh_sach_ma.size(); j++) {
      if(isPre(danh_sach_ma[i], danh_sach_ma[j])) {
        return false;
      }
    }
  }
  return true;
}

string BoMa::giai_ma() {

  vector<vector <string>> bang_giai_ma;
  int do_cham = 1;
  binary_sort(danh_sach_ma);
  bang_giai_ma.push_back(danh_sach_ma);

  if(BoMa::isPrefix()) {
    return ("Mã phân tách được, độ chậm giải mã là: " + to_string((danh_sach_ma.back()).size()));
  }

  //flag để dừng thuật toán
  int flag_cot = 0;
  int flag_dung = 0;
  cout<<"\n Bảng giải mã: "<<endl;
  do {
    vector<string> cot_i;
    for(int i = 0; i<(bang_giai_ma.back()).size(); i++) {
      for(int j = i ; j<(bang_giai_ma.front()).size(); j++) {
        if(isPre(bang_giai_ma.front()[j], bang_giai_ma.back()[i])) {
          string rest = take_rest(bang_giai_ma.front()[j], bang_giai_ma.back()[i]);
          cout<<rest<<endl;
          if(includes(danh_sach_ma, rest)) {
            return "Mã không phân tách được";
          }
          cot_i.push_back(rest);
        }
      }
    }
    cout<<endl;

    if(cot_i.size() == 0) {
      do_cham +=1;
      flag_dung = 1;
    }
    if(cot_i.size() > 0) {
      binary_sort(cot_i);
      for(int i =1; i<bang_giai_ma.size(); i++) {
        if(isSame(bang_giai_ma[i], cot_i)) {
          return "Mã phân tách được, độ chậm giải mã là vô hạn";
        }
      }
      bang_giai_ma.push_back(cot_i);
      do_cham +=1;
    }

  }while(flag_dung != 1);

  return "Mã phân tách được, độ chậm giải mã là: " + to_string(do_cham);
}
